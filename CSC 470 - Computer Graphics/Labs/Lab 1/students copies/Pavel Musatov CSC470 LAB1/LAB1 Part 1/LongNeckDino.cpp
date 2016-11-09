#include "LongNeckDino.h"

using namespace std;

int LongNeckDino::get_Array_Size()
{
	return arraySizeX;
}

int LongNeckDino::vector_size(int inThisArray)
{
	return coordinates_ptr[inThisArray].x.size();
}

LongNeckDino::LongNeckDino()
{
	coordinates_ptr = NULL;
	
}

LongNeckDino::LongNeckDino(const char* fileName)
{
	float tempX, tempY;
	fstream fileStream;
	int temp_vector_size;
	fileStream.open(fileName, ios::in);
	if (fileStream.fail())
		return;
	fileStream >> arraySizeX;
	coordinates_ptr = new Coordinates[arraySizeX];
	for (int i = 0; i < arraySizeX; ++i)
	{
		fileStream >> temp_vector_size;
		for (int j = 0; j < temp_vector_size; ++j)
		{
			fileStream >> tempX;
			coordinates_ptr[i].x.push_back(tempX);
			
			fileStream >> tempY;
			coordinates_ptr[i].y.push_back(tempY);
		}
	}
	fileStream.close();
}


LongNeckDino::~LongNeckDino()
{
	delete[] coordinates_ptr;
}

float LongNeckDino::get_X_Coord(int arrayPosition, int vectorPossition)
{
	return coordinates_ptr[arrayPosition].x[vectorPossition];
}

float LongNeckDino::get_Y_Coord(int arrayPosition, int vectorPossition)
{
	return coordinates_ptr[arrayPosition].y[vectorPossition];
}
