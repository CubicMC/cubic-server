#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <fstream>
#include <string>

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
        bool file_exist(std::string filename);
        std::string _folder_path;
        std::string _file_path;
        std::fstream _file_stream;
    };
}

#endif /* !LOGGER_HPP_ */