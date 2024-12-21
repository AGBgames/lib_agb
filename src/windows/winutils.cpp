#include <sstream>

#include "winutils.hpp"

#include "../common/common.hpp"
#include "../info.hpp"

static std::string global_window_title{};

void set_global_window_title(const std::string &new_global_window_title)
{
    global_window_title = new_global_window_title;
}

std::string get_global_window_title()
{
    return global_window_title;
}

int quick_messagebox(const std::string &text, const std::string &title, unsigned long types)
{
    return MessageBox(NULL, text.c_str(), title.c_str(), types);
}

int quick_messagebox(const std::string &text, unsigned long types)
{
    return quick_messagebox(text, global_window_title, types);
}

int display_error_message(int error_code, const std::string &source, const std::string &additional_info)
{
    std::stringstream stream{};
    stream << "An error occured in AGB-Library (libagb.dll)\n";
    stream << "Affected Software: " << get_global_window_title() << "\n\n\n";
    stream << "Library Version: " << get_lib_version() << "\n";
    stream << "C++ Standard: " << get_lib_cpp_standard() << "\n\n";
    stream << "Error Details: \n";
    stream << "Error Code: " << error_code << " => " << agberror::get_error_code_message(error_code) << "\n";
    stream << "Error Source: " << source << "\n";
    stream << "Additional Information: \n";
    stream << additional_info;

    const std::string title = "AGB-Libary" 
        + std::string(" in ")
        + std::string(get_global_window_title());
    return quick_messagebox(stream.str(), title, wind_error_ok);
}