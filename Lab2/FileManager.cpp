//
// Created by margi on 2023-09-15.
//
#include "FileManager.h"
void ClearFiles(const std::vector<std::string> &fileNames) {
    for (std::string fileName : fileNames) {
        std::ofstream file(fileName);
        if (file.is_open()) {
            file << fileName.erase(fileName.size() - 4, 4) << "\n" << "N\t\tT[ms]\t\tStdev[ms]\tSamples\n";
            file.close();
        }
    }
}
void WriteFile(const std::string& fileName, const std::string& output){
    std::ofstream file(fileName, std::ios::app);
    if (file.is_open()){
        file << output;
        file.close();
    }
}
