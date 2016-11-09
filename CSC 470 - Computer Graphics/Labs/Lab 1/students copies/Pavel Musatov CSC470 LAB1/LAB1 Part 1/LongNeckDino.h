#pragma once
#include <fstream>
#include <vector>
class LongNeckDino
{
public:

	LongNeckDino();
	LongNeckDino(const char * fileName);
	~LongNeckDino();
	struct Coordinates
	{
		std::vector<float> x;
		std::vector<float> y;
	};
	float get_X_Coord(int arrayPosition, int vectorPosition);
	float get_Y_Coord(int arrayPosition, int vectorPosition);

	int vector_size(int inThisArray);

	int get_Array_Size();
private:
	int arraySizeX;
	Coordinates* coordinates_ptr;
};

