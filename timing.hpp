#ifndef _TIME_HPP_
#define _TIME_HPP_

#include <chrono>
#include <iostream>
#include <functional>
#include <string>

// Timing wrapper
void Time(std::function<void ()> func, std::string msg) {
  using FpMilliseconds =
      std::chrono::duration<float, std::chrono::milliseconds::period>;
  static_assert(std::chrono::treat_as_floating_point<FpMilliseconds::rep>::value, 
		"Rep required to be floating point");
  auto t1 = std::chrono::high_resolution_clock::now();
  func();
  auto t2 = std::chrono::high_resolution_clock::now();
  auto time_ms = FpMilliseconds(t2 - t1);
  std::cout << msg << ": " << time_ms.count() << " milliseconds." << std::endl;
}

#endif  // _TIME_HPP_
