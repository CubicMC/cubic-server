#ifndef FILEANDFOLDERHANDLER_HPP_
#define FILEANDFOLDERHANDLER_HPP_

#include <string>

namespace logging
{
    /**
     * @brief Handles files and folders creation and verification
     */
    class FileAndFolderHandler
    {
        public:
            void create_folder(std::string folder_name);
            bool folder_exist(std::string foldername) const;
            void create_file(std::string filename);
            static bool file_exist(std::string filename);
            const std::string& get_folder_path() const;
            const std::string& get_file_path() const;
            void unset_folder_path();
            void unset_file_path();
        private:
            std::string _folder_path;   /// Path to the folder where log files are stored
            std::string _file_path;     /// Path to the current log file
    };
}

#endif /* !FILEANDFOLDERHANDLER_HPP_ */