// Copyright 2024 AGBgames - All rights reserved.
// Author: Nils "AGBDev" Böhm.

#include <windows.h>
#include <winuser.h>

#include <string>

#include "common.hpp"

const std::vector<std::string> error_code_messages { "Failed to open std::fstream" };

std::vector<std::string> get_error_code_messages()
{
    return error_code_messages;
}

std::string quick_joinstrings(const std::string &str1, const std::string &str2)
{
    std::string str{str1};
    str.append(str2);
    return str;
}
