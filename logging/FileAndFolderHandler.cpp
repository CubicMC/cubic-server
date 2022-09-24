#include "FileAndFolderHandler.hpp"
#include <sys/stat.h>
#include <errno.h>
#include <iostream>
#include <fstream>

namespace logging
{
    /**
     * @brief Create the folder if it doesn't exist
     *
     * @param folder_name Name of the folder to create.
     *
     * @throw std::runtime_error if the folder can't be created
     */
    void FileAndFolderHandler::create_folder(std::string folder_name)
    {
        if (mkdir(folder_name.c_str(), 0777) != 0) {
            switch(errno) {
                case EACCES:
                    throw std::runtime_error("Cannot create folder, the program don't have the rights");
                    break;
                case EEXIST:
                    std::cout << "Folder already exist. Setting it as _folder_path" << std::endl;
                    this->_folder_path = folder_name;
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
        } else {
            this->_folder_path = folder_name;
        }
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
    bool FileAndFolderHandler::file_exist(std::string filename) const
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
     * @brief Get the Folder Path object
     *
     * @return std::string Path to the folder where log files are stored
     */
    std::string FileAndFolderHandler::get_folder_path() const
    {
        return this->_folder_path;
    }

    /**
     * @brief Get the File Path object
     *
     * @return std::string Path to the current log file
     */
    std::string FileAndFolderHandler::get_file_path() const
    {
        return this->_file_path;
    }

    /**
     * @brief Unset the folder path
     */
    void FileAndFolderHandler::unset_folder_path()
    {
        this->_folder_path = "";
    }

    /**
     * @brief Unset the file path
     */
    void FileAndFolderHandler::unset_file_path()
    {
        this->_file_path = "";
    }
}