#ifndef _PAR_UTIL_
#define _PAR_UTIL_

// Determine whether or not we should wait for tasks in hybrid parallelism.
bool should_task_wait(int mults_per_step, int total_rec_steps,
					  int steps_left, int position, int num_threads) {
  int total_multiplies = pow(mults_per_step, total_rec_steps);
  int extra_multiplies = num_threads % total_multiplies;

  // TODO: fill in
  int start_index = 0;

  if (extra_multiplies == 0) {
	return false;
  }

  int end_index = total_multiplies - extra_multiplies;
  // There is exactly one wait at the bottom level of the recursive tree.
  if (steps_left == 1 && start_index + position == end_index) {
	return true;
  }

  int num_from_end = extra_multiplies / mults_per_step;
  if (steps_left == 2 && mults_per_step - num_from_end == position) {
	return true;
  }

  return false;
  // Does the break fall in the middle of my recursive region?
}

// Determine whether or not we should launch a task for hybrid parallelism.
bool should_launch_task(int mults_per_step, int total_rec_steps,
						int steps_left, int position, int num_threads) {
  return true;
#if defined(_BFS_PAR_)
  return true;
#endif

  int total_multiplies = pow(mults_per_step, total_rec_steps);
  int extra_multiplies = num_threads % total_multiplies;

  // TODO: fill in
  int start_index = 0;

  if (extra_multiplies == 0) {
	return true;
  }

  int end_index = total_multiplies - extra_multiplies;
  if (steps_left == 1 && start_index + position <= end_index) {
	return true;
  }
  
  int num_from_end = extra_multiplies / mults_per_step;
  if (steps_left == 2 && mults_per_step - num_from_end >= position) {
	return true;
  }

  return false;
}

#endif  // _PAR_UTIL_
