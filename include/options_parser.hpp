#ifndef MYLN_CONFIG_FILE_H
#define MYLN_CONFIG_FILE_H

#include <boost/program_options.hpp>
#include <exception>
#include <stdexcept>
#include <string>

class OptionsParseException : public std::runtime_error {
public:
    using runtime_error::runtime_error;
};

void assert_file_exist(const std::string &f_name);

class command_line_options_t {
public:
    command_line_options_t();
    command_line_options_t(int ac, char **av);

    //! Explicit is better than implicit:
    command_line_options_t(const command_line_options_t &) = default;
    command_line_options_t &operator=(const command_line_options_t &) = delete;
    command_line_options_t(command_line_options_t &&) = default;
    command_line_options_t &operator=(command_line_options_t &&) = delete;
    ~command_line_options_t() = default;

    [[nodiscard]] std::vector<std::string> const &get_filenames() const {
        return filenames;
    };
    [[nodiscard]] bool is_soft() const { return soft; };

    void parse(int ac, char **av);

private:
    bool soft{false};
    std::vector<std::string> filenames;

    boost::program_options::variables_map var_map{};
    boost::program_options::options_description opt_conf{
        "Config File Options:\n\tmyln [-h|--help] [-s|--soft] <source> "
        "<dest>\n"};
};

#endif // MYLN_CONFIG_FILE_H
