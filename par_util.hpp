#ifndef _PAR_UTIL_
#define _PAR_UTIL_

#include "common.hpp"
#include "math.h"
#include "assert.h"

int earliest_leaf_start(int mults_per_step, int steps_left, int start_index, int position) {
  if (steps_left == 1) {
	return start_index;
  }
  int earliest_child_start = (start_index + position - 1) * mults_per_step;
  return earliest_leaf_start(mults_per_step, steps_left - 1, earliest_child_start, 1);
}

// Determine whether or not we should wait for tasks in hybrid parallelism.
bool should_task_wait(int mults_per_step, int total_rec_steps, int steps_left,
                      int start_index, int position, int num_threads) {
  assert(0 < position && position <= mults_per_step);

#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_)
  return position == mults_per_step;
#endif

  int total_multiplies = pow(mults_per_step, total_rec_steps);
  int extra_multiplies = total_multiplies % num_threads;

  // HYBRID does all DFS, so no need to wait.
  if (num_threads > total_multiplies) {
	return false;
  }

  if (position == mults_per_step) {
    // The last position always waits.
    return true;
  }

  int end_index = total_multiplies - extra_multiplies;
  // There is exactly one wait at the bottom level of the recursion tree.
  if (steps_left == 1 && start_index + position == end_index) {
    //std::cout << "End stop: " << steps_left << " " << start_index << " " << position << std::endl;
    return true;
  }

  // There can be at most one wait at the second to last level of the recursion tree.
  int smallest_index = earliest_leaf_start(mults_per_step, steps_left, start_index, position);
  if (smallest_index >= end_index) {
    //std::cout << "Early stop: " << steps_left << " " << start_index << " " << position << std::endl;
    return true;
  }

  return false;
}

// Determine whether or not we should launch a task for hybrid parallelism.
bool should_launch_task(int mults_per_step, int total_rec_steps, int steps_left,
                        int start_index, int position, int num_threads) {
  assert(0 < position && position <= mults_per_step);

#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_)
  return true;
#endif

  int total_multiplies = pow(mults_per_step, total_rec_steps);
  int extra_multiplies = total_multiplies % num_threads;

  // If the number of threads is greater than the total number of multiplies,
  // then we just run parallel MKL.
  if (num_threads > total_multiplies) {
    return false;
  }

  int end_index = total_multiplies - extra_multiplies;
  if (steps_left == 1 && start_index + position > end_index) {
    //std::cout << "Not launching: " << steps_left << " " << start_index << " " << position << std::endl;
    return false;
  }
  
  int smallest_index = earliest_leaf_start(mults_per_step, steps_left, start_index, position);
  if (smallest_index >= end_index) {
    //std::cout << "Not launching: " << steps_left << " " << start_index << " " << position << std::endl;
    return false;
  }

  return true;
}

class Lock {
public:
  Lock() { omp_init_lock(&lock_); }
  ~Lock() { omp_destroy_lock(&lock_); }

  void Acquire() { omp_set_lock(&lock_); }
  bool Test() { return omp_test_lock(&lock_); }
  void Release() { omp_unset_lock(&lock_); }

private:
  omp_lock_t lock_;
};


class LockAndCounter {
public:
  LockAndCounter(int count) : count_(count) { lock_.Acquire(); }

  void Decrement() {
    #pragma omp critical
	{
	  if (count_ > 0) {
		--count_;
		if (count_ == 0) {
		  lock_.Release();
		}
	  }
	}
  }

  // Non-blocking acquire that yields to other tasks.
  void Acquire() {
	while (!lock_.Test()) {
        #pragma omp taskyield
	}
  }
  void Release() { lock_.Release(); }

private:
  int count_;
  Lock lock_;
};

# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
// Switch to DFS style sub-problems in the hybrid parallelism
void SwitchToDFS(LockAndCounter& locker, int num_threads) {
    locker.Acquire();
    mkl_set_num_threads_local(num_threads);
    locker.Release();
}
#endif

#endif  // _PAR_UTIL_
