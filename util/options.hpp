/**
   Copyright (c) 2014-2015, Sandia Corporation
   All rights reserved.

   This file is part of fast-matmul and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause.
*/

#ifndef _OPTIONS_HPP_
#define _OPTIONS_HPP_

#include <cstdlib>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

// These are simple functions for handling command-line options.

bool OptExists(std::map<std::string, std::string>& args_map, std::string arg) {
  return args_map.find(arg) != args_map.end();
}

int GetIntOpt(std::map<std::string, std::string>& args_map,
			  std::string arg, int default_opt=0) {
  if (!OptExists(args_map, arg)) {
	return default_opt;
  } else {
	return atoi(args_map[arg].c_str());
  }
}

float GetFloatOpt(std::map<std::string, std::string>& args_map,
				  std::string arg, float default_opt=0.0) {
  if (!OptExists(args_map, arg)) {
	return default_opt;
  } else {
	return atof(args_map[arg].c_str());
  }
}

std::string GetStrOpt(std::map<std::string, std::string>& args_map,
					  std::string arg, std::string default_opt="") {
  if (!OptExists(args_map, arg)) {
	return default_opt;
  } else {
	return args_map[arg];
  }
}

std::map<std::string, std::string> GetOpts(int argc, char **argv) {
  std::map<std::string, std::string> args_map;
  if (argc == 1) {
	return args_map;
  }
  std::vector<std::string> args(argv + 1, argv + argc);
  if (args.size() % 2) {
	throw std::logic_error("All options must come in pairs!");
  }
  for (int i = 0; i < args.size() - 1; ++i) {
	std::string arg1 = args[i];
	std::string arg2 = args[i + 1];
	args_map[arg1.substr(1)] = arg2;
  }
  return args_map;
}


#endif  // _OPTIONS_HPP_
