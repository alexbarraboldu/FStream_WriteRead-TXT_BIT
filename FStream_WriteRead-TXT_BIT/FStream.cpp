#include "Header.h"

#include <new>

///O	Hacer que puedas sobrescribir el archivo.
/// (
/// Sobrecargar la funci�n para poder poner m�tliples im�genes.
///	Insertar primero cuantas imagenes hay.
/// Si no hay varias im�genes se pondr� un -1.
/// )
///	Insertar el tama�o de la/s imagen.
///	Luego insertar la imagen de golpe.
/// 
/// -------------------------
/// DONE
/// Hacer 8 funciones.
/// 4 guardar
///		2 en texto		->	DONE
///			1 una imagen | 1 m�ltiples imagenes
///		2 en binario	->	TODO
///			1 una imagen | 1 m�ltiples im�genes
/// -------------------------


#pragma region LOAD

#pragma region TEXT

bool* LoadImageFromFile_TXT(const char* fileName)
{
	std::ifstream file;
	file.open(fileName, std::ios::in);

	///	std::ios::good Solo retorna true si no hay ninguna otra flag activada.
	if (!file.good()) return new bool[1];

	///	Coger la el ancho y alto de la imagen y comprobar que el archivo sea el correcto

	///	La primera l�nea no puede ser m�s larga que 5+1 car�cteres,
	/// ya que la resoluci�n de imagen no ser� superior a 99x74 (4:3).
	/// Por ej.: 20;15 -> Total length 5 + 1 ('\');

	const int firstLineLength = 6;
	char firstLine[firstLineLength];
	file.getline(firstLine, firstLineLength, '\n');

	///	Comprobar que el archivo sea de una sola imagen
	if (firstLine[2] != ';') return new bool[2];
	///------------------

	///	Coger el ancho y alto de la imagen
	char charWidth[2] = { firstLine[0], firstLine[1] };
	int imgWidth = atoi(charWidth);

	char charHeight[2] = { firstLine[3], firstLine[4] };
	int imgHeight = atoi(charHeight);
	///------------------

	///	Coger la imagen completa
	int charImgLength = (imgWidth * imgHeight) + (1 * imgHeight);
	char* charImg = new char[charImgLength];

	///	Comprobamos que se haya leido correctamente
	//if (file.getline(charImg, charImgLength, file.eof()).bad())
	//{
	//	file.close();
	//	return new bool[2];
	//}
	file.getline(charImg, charImgLength, file.eof());
	file.close();

	int imgLength = imgWidth * imgHeight;
	bool* resultImg = new bool[imgLength];

	for (size_t i = 0, j = 0, f = 1; i < imgLength; i++, j++)
	{
		resultImg[i] = charImg[j] - '0';
		if (i == (imgWidth * f) - 1)
		{
			++j, ++f;
		}
	}

	delete[] charImg;
	///------------------

	return resultImg;
}

///	FALTA IMPLEMENTAR CORRECTAMENTE
bool** LoadImagesFromFile_TXT(const char* fileName)
{
	std::ifstream file;
	file.open(fileName, std::ios::in);

	///	std::ios::good Solo retorna true si no hay ninguna otra flag activada.
	if (!file.good()) return new bool* [1];

	///	Coger la el ancho y alto de la imagen y comprobar que el archivo sea el correcto

	///	La primera l�nea no puede ser m�s larga que 5+1 car�cteres,
	/// ya que la resoluci�n de imagen no ser� superior a 99x74 (4:3).
	/// Por ej.: 20;15 -> Total length 5 + 1 ('\');

	const int firstLineLength = 6;
	char firstLine[firstLineLength];
	file.getline(firstLine, firstLineLength, '\n');

	///	Comprobar que el archivo sea de una sola imagen
	if (firstLine[2] != ';') return new bool* [2];
	///------------------

	///	Coger el ancho y alto de la imagen
	char charWidth[2] = { firstLine[0], firstLine[1] };
	int imgWidth = atoi(charWidth);

	char charHeight[2] = { firstLine[3], firstLine[4] };
	int imgHeight = atoi(charHeight);
	///------------------

	///	Coger la imagen completa
	int charImgLength = (imgWidth * imgHeight) + (1 * imgHeight);
	char* charImg = new char[charImgLength];

	///	Comprobamos que se haya leido correctamente
	//if (file.getline(charImg, charImgLength, file.eof()).bad())
	//{
	//	file.close();
	//	return new bool[2];
	//}
	file.getline(charImg, charImgLength, file.eof());
	file.close();

	int imgLength = imgWidth * imgHeight;
	bool* resultImg = new bool[imgLength];

	for (size_t i = 0, j = 0, f = 1; i < imgLength; i++, j++)
	{
		resultImg[i] = charImg[j] - '0';
		if (i == (imgWidth * f) - 1)
		{
			++j, ++f;
		}
	}

	delete[] charImg;
	///------------------

	return new bool* [1];
}

#pragma endregion

#pragma region BINARY

///	FALTA IMPLEMENTAR CORRECTAMENTE
bool* LoadImageFromFile_BIT(const char* fileName)
{
	///	El tama�o de la imagen se encuentra al principio del todo.
	///	Despues a descargar los datos.

	std::ifstream file;
	file.open(fileName, std::ios::in);

	///	std::ios::good Solo retorna true si no hay ninguna otra flag activada.
	if (!file.good()) return new bool[1];

	char data[100];

	file >> data;

	file.close();

	return new bool[1];
}

///	FALTA IMPLEMENTAR CORRECTAMENTE
bool** LoadImagesFromFile_BIT(const char* fileName)
{
	///	El tama�o de la imagen se encuentra al principio del todo.
	///	Despues a descargar los datos.

	std::ifstream file;
	file.open(fileName, std::ios::in);

	///	std::ios::good Solo retorna true si no hay ninguna otra flag activada.
	if (!file.good()) return new bool* [1];

	char data[100];

	file >> data;

	file.close();

	return new bool* [1];
}

#pragma endregion

#pragma endregion

#pragma region SAVE

#pragma region TEXT

void SaveImageToFile_TXT(const char* fileName, bool* imageData, int imgWidth, int imgHeight, bool overrideFile)
{
	int imageLength = imgWidth * imgHeight;
	if (imageLength <= 0) return;

	std::ofstream file;
	std::ios_base::openmode fileFlag = std::ios::out;

	///O
	if (overrideFile) fileFlag |= std::ios::trunc;
	else fileFlag |= std::ios::app;

	file.open(fileName, fileFlag);

	///	std::ios::good Solo retorna true si no hay ninguna otra flag activada.
	if (!file.good()) return;

	///	Save width and height
	file << imgWidth << ';' << imgHeight << std::endl;

	///	Save array
	for (size_t i = 0, f = 1; i < imageLength; i++)
	{
		if (i == imgWidth * f)
		{
			++f;
			file << std::endl;
		}
		file << imageData[i];
	}
	file << std::endl;

	file.close();
}

void SaveImagesToFile_TXT(const char* fileName, bool** imagesData, int totalImages, int imgWidth, int imgHeight, bool overrideFile)
{
	int imageLength = imgWidth * imgHeight;
	if (imageLength <= 0) return;
	if (totalImages <= 0) return;

	std::ofstream file;
	std::ios_base::openmode fileFlag = std::ios::out;

	///O
	if (overrideFile) fileFlag |= std::ios::trunc;
	else fileFlag |= std::ios::app;

	file.open(fileName, fileFlag);

	///	std::ios::good Solo retorna true si no hay ninguna otra flag activada.
	if (!file.good()) return;

	///	Save totalImages
	file << totalImages << std::endl;

	///	Save width and height
	file << imgWidth << ';' << imgHeight << std::endl;

	///	Save each image
	for (size_t i = 0; i < totalImages; i++)
	{
		///	Save array
		for (size_t j = 0, f = 1; j < imageLength; j++)
		{
			if (j == imgWidth * f)
			{
				++f;
				file << std::endl;
			}
			file << imagesData[i][j];
		}
		file << std::endl;
		file << std::endl;
	}

	file.close();
}

#pragma endregion

#pragma region BINARY

///	FALTA IMPLEMENTAR CORRECTAMENTE
void SaveImageToFile_BIT(const char* fileName, bool* fileData, int fileLength = 0, bool overrideFile = true)
{
	std::ofstream file;
	std::ios_base::openmode fileFlag = std::ios::out;

	///O
	if (overrideFile) fileFlag |= std::ios::trunc;

	file.open(fileName, fileFlag);

	///	std::ios::good Solo retorna true si no hay ninguna otra flag activada.
	if (!file.good()) return;

	file << fileData << std::endl;

	file.close();
}

///	FALTA IMPLEMENTAR CORRECTAMENTE
void SaveImagesToFile_BIT(const char* fileName, bool** fileData, int fileLength = 0, bool overrideFile = true)
{
	std::ofstream file;
	std::ios_base::openmode fileFlag = std::ios::out;

	///O
	if (overrideFile) fileFlag |= std::ios::trunc;

	file.open(fileName, fileFlag);

	///	std::ios::good Solo retorna true si no hay ninguna otra flag activada.
	if (!file.good()) return;

	file.close();
}

#pragma endregion

#pragma endregion
