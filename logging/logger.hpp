#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <fstream>
#include <string>
#include <experimental/filesystem>

namespace logging
{
    class Logger
    {
    public:
        Logger();
        ~Logger();
    private:
        void create_folder_if_nessessary(std::string folder_name = "logs");
        void create_file(std::string filename = "");
        std::experimental::filesystem::path _folder_path;
        std::experimental::filesystem::path _file_path;
        std::ofstream _file_stream;
    };
}

#endif /* !LOGGER_HPP_ */