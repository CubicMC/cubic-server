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
 * @param folderName Name of the folder to create.
 *
 * @throw std::runtime_error if the folder can't be created
 */
void FileAndFolderHandler::createFolder(std::string folderName)
{
    if (mkdir(folderName.c_str(), 0777) != 0)
        if (errno != EEXIST)
            throw std::runtime_error(std::strerror(errno));
    this->_folderPath = folderName;
}

/**
 * @brief Check if the folder exist
 *
 * @param folderName Name of the folder to check.
 *
 * @return true if the folder exist
 * @return false if the folder doesn't exist
 */
bool FileAndFolderHandler::folderExist(std::string folderName) const
{
    struct stat info;

    if (stat(folderName.c_str(), &info) != 0)
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
void FileAndFolderHandler::createFile(std::string filename)
{
    this->_filePath = this->_folderPath.empty() ? filename : this->_folderPath + "/" + filename;
    std::fstream file;
    file.open(this->_filePath, std::ios::app);
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
bool FileAndFolderHandler::fileExist(std::string filename)
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
const std::string &FileAndFolderHandler::getFolderPath() const { return this->_folderPath; }

/**
 * @brief Get the File Path object
 *
 * @return std::string Path to the current log file
 */
const std::string &FileAndFolderHandler::getFilePath() const { return this->_filePath; }

/**
 * @brief Unset the folder path
 */
void FileAndFolderHandler::unsetFolderPath() { this->_folderPath = ""; }

/**
 * @brief Unset the file path
 */
void FileAndFolderHandler::unsetFilePath() { this->_filePath = ""; }
}
