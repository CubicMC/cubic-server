#include "Logger.hpp"
#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <ctime>
#include <chrono>
#include <unordered_map>
#include <errno.h>

namespace logging
{
    /**
     * @brief Construct a new Logger:: Logger object
     */
    Logger::Logger()
    {
        this->create_folder_if_nessessary();
        this->create_file();
        this->_file_stream.open(this->_file_path, std::ios::app);
    }

    /**
     * @brief Construct a new Logger:: Logger object
     *
     * @param file_name Name of the log file
     *
     * @overload Logger::Logger()
     *
     * @note The file will be created as well as the folder
     */
    Logger::Logger(std::string file_name)
    {
        this->create_folder_if_nessessary();
        this->create_file(file_name);
        this->_file_stream.open(this->_file_path, std::ios::app);
    }

    /**
     * @brief Construct a new Logger:: Logger object
     *
     * @param folder_name Name of the folder where the log file will be stored
     * @param file_name Name of the log file
     *
     * @overload Logger::Logger()
     *
     *
     * @note The file will be created as well as the folder
     */
    Logger::Logger(std::string folder_name, std::string file_name)
    {
        this->create_folder_if_nessessary(folder_name);
        this->create_file(file_name);
        this->_file_stream.open(this->_file_path, std::ios::app);
    }

    /**
     * @brief Construct a new Logger:: Logger object
     *
     * @param create_all If true, the folder and the file will be created
     *
     * @overload Logger::Logger()
     *
     * @note The file will be created as well as the folder
     */
    Logger::Logger(bool create_all)
    {
        if (create_all)
        {
            this->create_folder_if_nessessary();
            this->create_file();
            this->_file_stream.open(this->_file_path, std::ios::app);
        }
    }

    /**
     * @brief Destroy the Logger:: Logger object
     *
     * @note The file stream will be closed
     */
    Logger::~Logger()
    {
        this->_file_stream.close();
    }

    /**
     * @brief Create the folder if it doesn't exist
     *
     * @param folder_name Name of the folder to create. This parameter is optional and will be set to "logs" by default
     */
    void Logger::create_folder_if_nessessary(std::string folder_name)
    {
        this->_folder_path = folder_name;
        if (mkdir(folder_name.c_str(), 0777) != 0) {
            switch(errno) {
                case EACCES:
                    throw std::runtime_error("Cannot create folder, the program don't have the rights");
                    break;
                case EEXIST:
                    std::cout << "Folder already exist. Passing..." << std::endl;
                    break;
                case ELOOP:
                    throw std::runtime_error("Cannot create folder, the path contain a loop reference");
                    break;
                case EMLINK:
                    throw std::runtime_error("Cannot create folder, the link number of the path cannot exceed LINK_MAX");
                    break;
                case ENAMETOOLONG:
                    throw std::runtime_error("Cannot create folder, the path exceed PATH_MAX characters");
                    break;
                case ENOENT:
                    throw std::runtime_error("Cannot create folder, a component of the path doesn't exist");
                    break;
                case ENOSPC:
                    throw std::runtime_error("Cannot create folder, the file system doesn't have enough space");
                    break;
                case ENOTDIR:
                    throw std::runtime_error("Cannot create folder, a component of the path is not a directory");
                    break;
                case EROFS:
                    throw std::runtime_error("Cannot create folder, the file system is read only");
                    break;
                default:
                    throw std::runtime_error("Cannot create folder, unknown error");
                    break;
            }
        }
    }

    /**
     * @brief Create the file
     *
     * @param filename Name of the file to create. This parameter is optional and will be set to the current date by default with an indexer if the file already exist
     */
    void Logger::create_file(std::string filename)
    {
        this->_file_path = this->_folder_path + '/' + filename;

        for (int i = 1; filename == "" && this->file_exist(this->_file_path); i++) {
            filename = this->get_time("YYYY-MM-DD-") +
                std::to_string(i) + ".log";
                this->_file_path = this->_folder_path + '/' + filename;
        }

        std::cout << "log file: " << this->_file_path << std::endl;
    }

    /**
     * @brief Check if the file exist
     *
     * @param filename Name of the file to check
     *
     * @return true The file exist
     * @return false The file doesn't exist
     */
    bool Logger::file_exist(std::string filename) const
    {
        std::fstream file;
        file.open(filename);
        if (file.is_open()) {
            file.close();
            return true;
        }
        file.close();
        return false;
    }

    /**
     * @brief Get the current time
     *
     * @return std::string The current time
     *
     * @note The format is YYYY/MM/DD HH:MM:SS.sss by default
     */
    std::string Logger::get_time() const
    {
        const std::time_t now = std::time(nullptr);
        const std::tm* tm_now = std::localtime(&now);
        int millis = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - now;

        return  std::to_string(tm_now->tm_year + 1900) + '/' +
                std::to_string(tm_now->tm_mon + 1) + '/' +
                std::to_string(tm_now->tm_mday) + '/' +
                ' ' +
                std::to_string(tm_now->tm_hour) + ':' +
                std::to_string(tm_now->tm_min) + ':' +
                std::to_string(tm_now->tm_sec) + '.' +
                std::to_string(millis);
    }

    /**
     * @brief Get the current time
     *
     * @param format Format of the time. When there is YYYY or any other format letters, they will be replaced by the current time
     *
     * @return std::string The current time
     *
     * @overload std::string Logger::get_time() const
     *
     * @note The format is YYYY/MM/DD HH:MM:SS.sss by default
     */
    std::string Logger::get_time(std::string format) const
    {
        const std::time_t now = std::time(nullptr);
        const std::tm* tm_now = std::localtime(&now);
        int millis = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - (now * 1000);
        std::unordered_map<std::string, std::string> values = {
            {"YYYY", std::to_string(tm_now->tm_year + 1900)},
            {"MM", tm_now->tm_mon + 1 < 10 ? "0" + std::to_string(tm_now->tm_mon + 1) : std::to_string(tm_now->tm_mon + 1)},
            {"DD", tm_now->tm_mday < 10 ? "0" + std::to_string(tm_now->tm_mday) : std::to_string(tm_now->tm_mday)},
            {"HH", tm_now->tm_hour < 10 ? "0" + std::to_string(tm_now->tm_hour) : std::to_string(tm_now->tm_hour)},
            {"mm", tm_now->tm_min < 10 ? "0" + std::to_string(tm_now->tm_min) : std::to_string(tm_now->tm_min)},
            {"SS", tm_now->tm_sec < 10 ? "0" + std::to_string(tm_now->tm_sec) : std::to_string(tm_now->tm_sec)},
            {"sss", millis < 10 ? "00" + std::to_string(millis) : millis < 100 ? "0" + std::to_string(millis) : std::to_string(millis)}
        };

        for (auto iter = values.begin(); iter != values.end(); iter++) {
            if (format.find(iter->first) != std::string::npos)
                format.replace(format.find(iter->first), iter->first.length(), iter->second);
        }
        return format;
    }

    /**
     * @brief Write a message in the log file
     *
     * @param message Message to write
     *
     * @note The message will be written in the log file with the current time
     */
    void Logger::log(std::string message)
    {
        this->_file_stream << this->get_time("YYYY/MM/DD HH:mm:SS.sss") << " " << message << std::endl;
    }
}