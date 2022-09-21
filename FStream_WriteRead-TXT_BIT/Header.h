#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>

bool* LoadImageFromFile_TXT(const char* fileName);

void SaveImageToFile_TXT(const char* fileName, bool* imageData, int width, int height, bool overrideFile = true);
void SaveImagesToFile_TXT(const char* fileName, bool** imagesData, int totalImages, int imgWidth, int imgHeight, bool overrideFile = true);
#endif // !HEADER_H
