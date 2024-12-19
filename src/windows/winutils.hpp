#pragma once

#include <windows.h>
#include <winuser.h>

#include <string>

typedef long window_t;
constexpr window_t wind_info_ok = MB_ICONINFORMATION | MB_OK;
constexpr window_t wind_error_ok = MB_ICONERROR | MB_OK;
constexpr window_t wind_error_retrycancel = MB_ICONERROR | MB_RETRYCANCEL;
constexpr window_t wind_error_okeycancel = MB_ICONERROR | MB_OKCANCEL;

// Update global window title for messagebox windows.
void set_global_window_title(const std::string &new_global_window_title);
// Get current global window title
std::string get_global_window_title();

// Display messagebox.
int quick_messagebox(const std::string &text, const std::string &title, unsigned long types);
// Display messagebox using global window title.
int quick_messagebox(const std::string &text, unsigned long types);

// ##################################### ERROR HANDLING #####################################

// Display messagebox with information about an error or an important information during runtime.
int display_error_message(int error_code, const std::string &source, const std::string &extra_info);