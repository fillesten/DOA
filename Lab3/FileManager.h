//
// Created by margi on 2023-10-06.
//

#ifndef LABORATION_3_FILEMANAGER_H
#define LABORATION_3_FILEMANAGER_H

#include <vector>
#include <fstream>
#include <iostream>
/// Clears all files in the list of filenames
/// \param fileNames the list of filenames
void ClearFiles(const std::vector<std::string> &fileNames);
/// Writes output into a file
/// \param fileName file to write to
/// \param output what to write to file
void WriteFile(const std::string& fileName, const std::string& output);

#endif //LABORATION_3_FILEMANAGER_H
