#ifndef _PAR_UTIL_
#define _PAR_UTIL_

#include "common.hpp"
#include "math.h"
#include "assert.h"

// Determine whether or not we should wait for tasks in hybrid parallelism.
bool should_task_wait(int mults_per_step, int total_rec_steps, int steps_left,
					  int start_index, int position, int num_threads) {
  assert(0 < position && position <= mults_per_step);

#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_)
  return position == mults_per_step;
#endif

  int total_multiplies = pow(mults_per_step, total_rec_steps);
  int extra_multiplies = total_multiplies % num_threads;

  if (position == mults_per_step) {
	// The last position always waits.
	return true;
  }

  int end_index = total_multiplies - extra_multiplies;
  // There is exactly one wait at the bottom level of the recursive tree.
  if (steps_left == 1 && start_index + position == end_index) {
	//std::cout << "End stop: " << steps_left << " " << start_index << " " << position << std::endl;
	return true;
  }

  int num_from_end = extra_multiplies / mults_per_step;
  if (steps_left == 2 && mults_per_step - num_from_end == position) {
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
  
  int num_from_end = extra_multiplies / mults_per_step;
  if (steps_left == 2 && mults_per_step - num_from_end < position) {
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
  void Release() { omp_unset_lock(&lock_); }

 private:
  omp_lock_t lock_;
};


class LockAndCounter {
 public:
  LockAndCounter(int count) : count_(count) { lock_.Acquire(); }

  void decrement() {
	#pragma omp atomic update
	--count_;
	if (count_ == 0) {
	  lock_.Release();
	}
  }

  Lock& lock() { return lock_; }
  int count() { return count_; }

 private:
  int count_;
  Lock lock_;
};

#endif  // _PAR_UTIL_
