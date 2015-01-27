/*
 * FileUtils.h
 *
 *  Created on: 2014/8/4
 *      Author: leo
 */

#ifndef FILEUTILS_H_
#define FILEUTILS_H_

#include "Log/MiLog/header/MiLog.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fstream>

namespace FileUtils {

    inline bool fileExist(const char* filePath) {
        struct stat buf;
        int result = stat(filePath, &buf);

        return (result == 0);
    }

    static bool createDir(const char* dirPath) {
        if (!fileExist(dirPath)) {
            if (mkdir(dirPath, 0700) == -1)
                return false;
        }
        return true;
    }

    static bool copyFile(const char* srcFilePath, const char* destFilePath) {
        if (!fileExist(srcFilePath))
            return false;

        std::ifstream src(srcFilePath,  std::ios::binary);
        std::ofstream dst(destFilePath, std::ios::binary);

        LOG_S_INFO("CopyFile successfully from %s ... %s", srcFilePath, destFilePath);

        dst << src.rdbuf();
        return true;
    }

    static bool moveFile(const char* srcFilePath, const char* destFilePath) {
        if (rename(srcFilePath, destFilePath) == 0) {
            LOG_S_INFO("MoveFile successfully from %s ... %s", srcFilePath, destFilePath);
            return true;

        } else {
            LOG_S_ERROR("Error renaming file from %s ... %s", srcFilePath, destFilePath);
            return false;
        }
    }

    static bool removeFile(const char* filePath) {
        if (fileExist(filePath) && remove(filePath) != 0) {
            LOG_S_ERROR("Error deleting file %s", filePath);
            return false;

        } else {
            LOG_S_INFO("File successfully deleted %s", filePath);
            return true;
        }
    }
}

#endif /* FILEUTILS_H_ */
