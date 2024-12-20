// Copyright 2024 AGBgames - All rights reserved.
// Author: Nils "AGBDev" Böhm.

#ifndef H_COMMON_HPP
#define H_COMMON_HPP

#include <windows.h>
#include <winuser.h>

#include <vector>
#include <string>

std::vector<std::string> get_error_code_messages();

// Utils method for a quick join of two strings.
std::string quick_joinstrings(const std::string &str1, const std::string &str2);

#endif 