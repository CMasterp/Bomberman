/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** File
*/

#ifndef FILE_HPP_
#define FILE_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <type_traits>
#include "raylib.h"

namespace Raylib {
    class File {

    public:
        /**
         * @brief Construct a new File object
         */
        File();

        /**
         * @brief Destroy the File object
         */
        ~File();

        /**
         * @brief Load file data as byte array (read)
         *
         * @param fileName const std::string
         * @param bytesRead unsigned int &
         * @return data static std::string
         */
        static std::string
        loadFileData(const std::string &fileName, unsigned int &bytesRead);

        /**
         * @brief Unload file data allocated by LoadFileData()
         *
         * @param data unsigned char
         */
        static void unloadFileData(const std::string &data);

        /**
         * @brief Save data to file from byte array (write)
         *
         * @param fileName const std::string
         * @param data void *
         * @param bytesToWrite unsigned int
         * @return returns true on success, false otherwise
         */
        static bool saveFileData(const std::string &fileName, void *data,
                                 const unsigned int &bytesToWrite);

        /**
         * @brief Load text data from file (read)
         *
         * @param fileName const std::string
         * @return returns a '\0' terminated string
         */
        static std::string loadFileText(const std::string &fileName);

        /**
         * @brief Unload file text data allocated by LoadFileText()
         *
         * @param text unsigned std::string
         */
        static void unloadFileText(const std::string &text);

        /**
         * @brief Save text data to file (write), string must be '\0' terminated
         *
         * @param fileName the name of the file
         * @param text the text to write in the file
         * @return returns true on success, false otherwise
         */
        static bool
        saveFileText(const std::string &fileName, const std::string &text);

        /**
         * @brief Check if file exists
         *
         * @param fileName the name of the file
         * @return returns true on success, false otherwise
         */
        static bool fileExists(const std::string &fileName);

        /**
         * @brief Check if a directory path exists
         *
         * @param dirPath path of the directory
         * @return returns true on success, false otherwise
         */
        static bool directoryExists(const std::string &dirPath);

        /**
         * @brief Check file extension (including point: .png, .wav)
         *
         * @param fileName the name of the file
         * @param ext the extension of the file
         * @return returns true on success, false otherwise
         */
        static bool
        isFileExtension(const std::string &fileName, const std::string &ext);

        /**
         * @brief Get pointer to extension for a filename string (includes dot: ".png")
         *
         * @param fileName the name of the file
         * @return A pointer
         */
        static const std::string getFileExtension(const std::string &fileName);

        /**
         * @brief Get pointer to filename for a path string
         *
         * @param filePath the path of the file
         * @return A pointer
         */
        static const std::string getFileName(const std::string &filePath);

        /**
         * @brief Get filename string without extension (uses static string)
         *
         * @param filePath the path of the file
         * @return filename string without extension
         */
        static const std::string
        getFileNameWithoutExt(const std::string &filePath);

        /**
         * @brief Get full path for a given fileName with path (uses static string)
         *
         * @param filePath the path of the file
         * @return full path
         */
        static const std::string getDirectoryPath(const std::string &filePath);

        /**
         * @brief Get previous directory path for a given path (uses static string)
         *
         * @param dirPath the path of the directory
         * @return previous directory
         */
        static const std::string
        getPrevDirectoryPath(const std::string &dirPath);

        /**
         * @brief Get current working directory (uses static string)
         *
         * @return Get current working directory
         */
        static const std::string getWorkingDirectory(void);

        /**
         * @brief Get filenames in a directory path (memory should be freed)
         *
         * @param dirPath the path of the directory
         * @param count the number of files
         * @return filenames
         */
        static std::vector<std::string>
        getDirectoryFiles(const std::string &dirPath, int &count);

        /**
         * @brief Clear directory files paths buffers (free memory)
         */
        static void clearDirectoryFiles(void);

        /**
         * @brief Change working directory
         *
         * @param dir the directory you whant to move to
         * @return return true on success and false on error
         */
        static bool changeDirectory(const std::string &dir);

        /**
         * @brief Check if a file has been dropped into window
         *
         * @return return true on success and false on error
         */
        static bool isFileDropped(void);

        /**
         * @brief Get dropped files names (memory should be freed)
         *
         * @param count the numbers of dropped files
         * @return Filesnames
         */
        static std::vector<std::string> getDroppedFiles(int &count);

        /**
         * @brief Clear dropped files paths buffer (free memory)
         */
        static void clearDroppedFiles(void);

        /**
         * @brief Get file modification time (last write time)
         *
         * @param fileName the name of the file
         * @return file modification time (last write time)
         */
        static long getFileModTime(const std::string &fileName);
    };

#include "File.inl"

}

#endif /* !FILE_HPP_ */
