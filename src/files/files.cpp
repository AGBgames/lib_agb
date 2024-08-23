#include "files.hpp"

#include "../windows/winutils.hpp"

bool open_file(const std::string &filename, std::fstream *stream, std::ios_base::openmode mode, bool suppress_errors)
{
    *stream = std::fstream{filename, mode};

    if (!stream->is_open())
    {
        if (!suppress_errors)
            display_error_message(0, "lib_agb:files/filesys.cpp:12",
                              "Invalid filename/-path.");
        return false;                    
    }

    return true;
}

bool write_file(const std::string &filename, const std::string &data,
                        bool suppress_errors)
{
    std::fstream stream{};
    if (!open_file(filename, &stream, std::ios_base::out))
    {
        return false;
    }

    stream << data;

    return true;
}