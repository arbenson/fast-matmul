#ifndef _TIME_HPP_
#define _TIME_HPP_

#include <chrono>
#include <iostream>
#include <functional>
#include <string>

// Wrappers for timing routines

// Time func and return the time
double Time(std::function<void ()> func) {
  using FpMilliseconds =
      std::chrono::duration<float, std::chrono::milliseconds::period>;
  static_assert(std::chrono::treat_as_floating_point<FpMilliseconds::rep>::value, 
		"Rep required to be floating point");
  auto t1 = std::chrono::high_resolution_clock::now();
  func();
  auto t2 = std::chrono::high_resolution_clock::now();
  auto time_ms = FpMilliseconds(t2 - t1);
  return time_ms.count();
}

// Timing func and print the message.
void Time(std::function<void ()> func, std::string msg) {
  double time = Time(func);
  std::cout << msg << ": " << time << " milliseconds." << std::endl;
}

#endif  // _TIME_HPP_
