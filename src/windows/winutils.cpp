#include <vector>

#include "winutils.hpp"

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

std::vector<std::string> error_code_messages{ "Failed to open std::fstream" };

static std::string get_error_code_message(size_t error_code) 
{
    if (error_code_messages.size() - 1 < error_code)
        return "Unknown error";
    for (size_t i = 0; i < error_code_messages.size(); i++)
    {
        if (error_code == i) return error_code_messages[i];
    }
    return "Unknown error";
}

int display_error_message(int error_code, const std::string &source, const std::string &extra_info)
{
    std::string message{"An error occured in AGB-Library (agb.dll)\n\n"};
    message.append("Library Version: ");
    message.append(std::to_string(get_lib_version()));
    message.append("\n");
    message.append("CPP Standard: ");
    message.append(std::to_string(get_lib_cpp_standard()));
    message.append("\n\nDetails: \n");
    message.append("Error: ");
    message.append(get_error_code_message(error_code));
    message.append("\n");
    message.append("Source: ");
    message.append(source);
    message.append("\n");
    message.append("Additional Info: ");
    message.append(extra_info);
    return quick_messagebox(message, "AGB-Library", wind_error_ok);
}
