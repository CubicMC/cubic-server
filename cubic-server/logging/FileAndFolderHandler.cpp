#include "FileAndFolderHandler.hpp"
#include <cstring>
#include <errno.h>
#include <fstream>
#include <iostream>
#include <sys/stat.h>

namespace logging {
/**
 * @brief Create the folder if it doesn't exist
 *
 * @param folder_name Name of the folder to create.
 *
 * @throw std::runtime_error if the folder can't be created
 */
void FileAndFolderHandler::create_folder(std::string folder_name)
{
    if (mkdir(folder_name.c_str(), 0777) != 0)
        if (errno != EEXIST)
            throw std::runtime_error(std::strerror(errno));
    this->_folder_path = folder_name;
}

/**
 * @brief Check if the folder exist
 *
 * @param foldername Name of the folder to check.
 *
 * @return true if the folder exist
 * @return false if the folder doesn't exist
 */
bool FileAndFolderHandler::folder_exist(std::string foldername) const
{
    struct stat info;

    if (stat(foldername.c_str(), &info) != 0)
        return false;
    else if (info.st_mode & S_IFDIR)
        return true;
    else
        return false;
}

/**
 * @brief Create the file
 *
 * @param filename Name of the file to create
 *
 * @throw std::runtime_error if the file cannot be created
 */
void FileAndFolderHandler::create_file(std::string filename)
{
    this->_file_path = this->_folder_path.empty() ? filename : this->_folder_path + "/" + filename;
    std::fstream file;
    file.open(this->_file_path, std::ios::app);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot create file");
    }
    file.close();
}

/**
 * @brief Check if the file exist
 *
 * @param filename Name of the file to check
 *
 * @return true The file exist
 * @return false The file doesn't exist
 */
bool FileAndFolderHandler::file_exist(std::string filename)
{
    struct stat info;
    int ret = stat(filename.c_str(), &info);
    if (ret == 0)
        return true;
    else if (errno == ENOENT)
        return false;
    else
        throw std::runtime_error(std::strerror(errno));
}

/**
 * @brief Get the Folder Path object
 *
 * @return std::string Path to the folder where log files are stored
 */
const std::string &FileAndFolderHandler::get_folder_path() const { return this->_folder_path; }

/**
 * @brief Get the File Path object
 *
 * @return std::string Path to the current log file
 */
const std::string &FileAndFolderHandler::get_file_path() const { return this->_file_path; }

/**
 * @brief Unset the folder path
 */
void FileAndFolderHandler::unset_folder_path() { this->_folder_path = ""; }

/**
 * @brief Unset the file path
 */
void FileAndFolderHandler::unset_file_path() { this->_file_path = ""; }
}
