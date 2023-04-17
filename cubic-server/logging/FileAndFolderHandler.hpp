#ifndef FILEANDFOLDERHANDLER_HPP_
#define FILEANDFOLDERHANDLER_HPP_

#include <string>

namespace logging {
/**
 * @brief Handles files and folders creation and verification
 */
class FileAndFolderHandler {
public:
    void createFolder(std::string folderName);
    bool folderExist(std::string folderName) const;
    void createFile(std::string filename);
    static bool fileExist(std::string filename);
    const std::string &getFolderPath() const;
    const std::string &getFilePath() const;
    void unsetFolderPath();
    void unsetFilePath();

private:
    std::string _folderPath; // Path to the folder where log files are stored
    std::string _filePath; // Path to the current log file
};
}

#endif /* !FILEANDFOLDERHANDLER_HPP_ */
