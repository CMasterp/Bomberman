/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** File
*/

inline std::string Raylib::File::loadFileData(const std::string &fileName, unsigned int &bytesRead)
{
    return (const char *) ::LoadFileData(fileName.c_str(), &bytesRead);
}

inline void Raylib::File::unloadFileData(const std::string &data)
{
    return ::UnloadFileData((unsigned char *) data.c_str());
}

inline bool Raylib::File::saveFileData(const std::string &fileName, void *data, const unsigned int &bytesToWrite)
{
    return ::SaveFileData(fileName.c_str(), data, bytesToWrite);
}

inline std::string Raylib::File::loadFileText(const std::string &fileName)
{
    return ::LoadFileText(fileName.c_str());
}

inline void Raylib::File::unloadFileText(const std::string &text)
{
    return ::UnloadFileText((unsigned char *)text.c_str());
}

inline bool Raylib::File::saveFileText(const std::string &fileName, const std::string &text)
{
    return ::SaveFileText(fileName.c_str(), const_cast<char *>(text.c_str()));
}

inline bool Raylib::File::fileExists(const std::string &fileName)
{
    return ::FileExists(fileName.c_str());
}

inline bool Raylib::File::directoryExists(const std::string &dirPath)
{
    return ::DirectoryExists(dirPath.c_str());
}

inline bool Raylib::File::isFileExtension(const std::string &fileName, const std::string &ext)
{
    return ::IsFileExtension(fileName.c_str(), ext.c_str());
}

inline const std::string Raylib::File::getFileExtension(const std::string &fileName)
{
    return ::GetFileExtension(fileName.c_str());
}

inline const std::string Raylib::File::getFileName(const std::string &filePath)
{
    return ::GetFileName(filePath.c_str());
}

inline const std::string Raylib::File::getFileNameWithoutExt(const std::string &filePath)
{
    return ::GetFileNameWithoutExt(filePath.c_str());
}

inline const std::string Raylib::File::getDirectoryPath(const std::string &filePath)
{
    return ::GetDirectoryPath(filePath.c_str());
}

inline const std::string Raylib::File::getPrevDirectoryPath(const std::string &dirPath)
{
    return ::GetPrevDirectoryPath(dirPath.c_str());
}

inline const std::string Raylib::File::getWorkingDirectory(void)
{
    return ::GetWorkingDirectory();
}

inline std::vector<std::string> Raylib::File::getDirectoryFiles(const std::string &dirPath, int &count)
{
    char **p = ::GetDirectoryFiles(dirPath.c_str(), &count);
    return std::vector<std::string>(p, p + count);
}

inline void Raylib::File::clearDirectoryFiles(void)
{
    return ::ClearDirectoryFiles();
}

inline bool Raylib::File::changeDirectory(const std::string &dir)
{
    return ::ChangeDirectory(dir.c_str());
}

inline bool Raylib::File::isFileDropped(void)
{
    return ::IsFileDropped();
}

inline std::vector<std::string> Raylib::File::getDroppedFiles(int &count)
{
    char **p = ::GetDroppedFiles(&count);
    return std::vector<std::string>(p, p + count);
}

inline void Raylib::File::clearDroppedFiles(void)
{
    return ::ClearDroppedFiles();
}

inline long Raylib::File::getFileModTime(const std::string &fileName)
{
    return ::GetFileModTime(fileName.c_str());
}