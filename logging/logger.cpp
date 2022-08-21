#include "logger.hpp"
#include <experimental/filesystem>
#include <iostream>
//#include <chrono>
#include <string>
#include <fstream>
#include <ctime>

namespace logging
{
    Logger::Logger()
    {
        create_folder_if_nessessary();
        create_file();
        this->_file_stream.open(this->_file_path, std::ios::app);
    }

    Logger::~Logger()
    {
        this->_file_stream.close();
    }

    void Logger::create_folder_if_nessessary(std::string folder_name)
    {
        const std::experimental::filesystem::path logs{folder_name};
        if (std::experimental::filesystem::exists(logs))
            std::cout << "folder exist" << std::endl;
        else {
            std::experimental::filesystem::create_directory(logs);
            std::cout << "folder created" << std::endl;
        }
        this->_folder_path = logs;
    }

    void Logger::create_file(std::string filename)
    {
        // this->_file_path = {this->_folder_path / filename};

        // const std::chrono::year_month_day ymd{std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now())};

        // for (int i = 1; std::experimental::filesystem::exists(this->_file_path) && filename == ""; i++) {
        //     filename =
        //         std::to_string(static_cast<int>(ymd.year())) + '-' +
        //         std::to_string(static_cast<unsigned>(ymd.month())) + '-' +
        //         std::to_string(static_cast<unsigned>(ymd.day())) + '-' +
        //         std::to_string(i) + ".log";
        //         this->_file_path = {this->_folder_path / filename};
        // }

        // std::cout << "log file: " << this->_file_path << std::endl;

        this->_file_path = {this->_folder_path / filename};

        const std::time_t now = std::time(nullptr);
        const std::tm* tm_now = std::localtime(&now);

        for (int i = 1; std::experimental::filesystem::exists(this->_file_path) && filename == ""; i++) {
            filename =
                std::to_string(tm_now->tm_year + 1900) + '-' +
                std::to_string(tm_now->tm_mon + 1) + '-' +
                std::to_string(tm_now->tm_mday) + '-' +
                std::to_string(i) + ".log";
                this->_file_path = {this->_folder_path / filename};
        }

        std::cout << "log file: " << this->_file_path << std::endl;
    }
}

int main() {
    logging::Logger logger;
}