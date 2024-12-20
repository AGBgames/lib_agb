#pragma once

#include <string>
#include <fstream>

// Open fstream via filename and open mode and return success via a bool.
bool open_file(const std::string &filename, std::fstream *stream, std::ios_base::openmode mode, bool suppress_errors = false);

bool write_file(const std::string &filename, const std::string &data, bool suppress_errors = false);
