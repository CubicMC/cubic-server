#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <fstream>
#include <string>

namespace logging
{
    /**
     * @brief Handles logging in a file, creating the file if it doesn't exist and the folder too
     */
    class Logger
    {
    public:
        Logger();
        Logger(std::string file_name);
        Logger(std::string folder_name, std::string file_name);
        Logger(bool create_all);
        ~Logger();
        void log(std::string message);

    private:
        void create_folder_if_nessessary(std::string folder_name = "logs");
        void create_file(std::string filename = "");
        bool file_exist(std::string filename) const;
        std::string get_time() const;
        std::string get_time(std::string format) const;
        std::string _folder_path;   /// Path to the folder where log files are stored
        std::string _file_path;     /// Path to the current log file
        std::fstream _file_stream;  /// Stream to the current log file
    };
}

#endif /* !LOGGER_HPP_ */