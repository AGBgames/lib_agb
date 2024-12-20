// Copyright 2024 AGBgames - All rights reserved.
// Author: Nils "AGBDev" Böhm.

#include <windows.h>
#include <winuser.h>

#include <string>

#include "common.hpp"

namespace agberror
{
    constexpr std::string unknown_error = "Unknown Error";
    const std::vector<std::string> error_code_messages { "Failed to open std::fstream" };

    std::vector<std::string> get_error_code_messages()
    {
        return error_code_messages;
    }

    std::string get_error_code_message(size_t error_code) 
    {
        if (agberror::get_error_code_messages().size() - 1 < error_code)
            return unknown_error;
        for (size_t i = 0; i < agberror::get_error_code_messages().size(); i++)
        {
            if (error_code == i) 
                return agberror::get_error_code_messages()[i];
        }
        return unknown_error;
    }
}

std::string quick_joinstrings(const std::string &str1, const std::string &str2)
{
    std::string str{str1};
    str.append(str2);
    return str;
}
