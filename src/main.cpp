#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <unistd.h>

#include "options_parser.hpp"

int main(int argc, char *argv[]) {
    command_line_options_t parser{argc, argv};

    std::vector<std::string> files = parser.get_filenames();
    if (parser.is_soft()) {
        if (symlink(files[0].c_str(), files[1].c_str()) < 0) {
            perror("myln");
            exit(errno);
        }
    } else {
        if (link(files[0].c_str(), files[1].c_str()) < 0) {
            perror("myln");
            exit(errno);
        }
    }

    return 0;
}
