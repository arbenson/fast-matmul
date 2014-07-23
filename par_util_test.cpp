#include "par_util.hpp"

#include <iostream>

int main() {
  // Strassen

  int mults_per_step = 3;
  int total_rec_steps = 2;
  int steps_left = 2;
  int num_threads = 5;

  for (int i = 1; i <= 3; ++i) {
	std::cout << should_task_wait(mults_per_step, total_rec_steps, 0, steps_left, i, num_threads) << std::endl;
  }
  std::cout << "---" << std::endl;

  for (int i = 1; i <= 3; ++i) {
	std::cout << should_launch_task(mults_per_step, total_rec_steps, 0, steps_left, i, num_threads) << std::endl;
  }
  std::cout << "---" << std::endl;

  steps_left = 1;

  for (int i = 1; i <= 3; ++i) {
	std::cout << should_task_wait(mults_per_step, total_rec_steps, steps_left, i, num_threads) << std::endl;
  }
  std::cout << "---" << std::endl;

  for (int i = 1; i <= 3; ++i) {
	std::cout << should_launch_task(mults_per_step, total_rec_steps, steps_left, i, num_threads) << std::endl;
  }
  std::cout << "---" << std::endl;


}
