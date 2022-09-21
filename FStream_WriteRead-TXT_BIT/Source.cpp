#include "Header.h"

int width = 20;
int height = 15;
int imgLength = width * height;

int numberOfImages = 3;

void TEST_SaveImage0()
{
	bool* img_0 = new bool[imgLength];
	for (size_t i = 0; i < imgLength; i++)
	{
		img_0[i] = false;
	}

	SaveImageToFile_TXT("image_0.txt", img_0, width, height);
}

void TEST_SaveImageSet0()
{
	bool** imgSet_0 = new bool* [numberOfImages];

	for (size_t i = 0; i < numberOfImages; i++)
	{
		imgSet_0[i] = new bool[imgLength];
		for (size_t j = 0; j < imgLength; j++)
		{
			imgSet_0[i][j] = false;
		}
	}

	SaveImagesToFile_TXT("setOfImages_0.txt", imgSet_0, numberOfImages, width, height);
}

void TEST_LoadImag0()
{
	bool* arr = LoadImageFromFile_TXT("image_0.txt");

	///	Print array as a matrix
	for (size_t i = 0, j = 1; i < 20 * 15; i++)
	{
		if (i == width * j)
		{
			++j;
			std::cout << std::endl;
		}
		std::cout << arr[i];
	}
	std::cout << std::flush;
}

int main()
{


	return 0;
}