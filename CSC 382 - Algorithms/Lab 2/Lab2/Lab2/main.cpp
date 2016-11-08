///////////////////////////////////////////////
//						Muhand Jumah
//						CSC 382 Lab2
///////////////////////////////////////////////
#include<iostream>
#include<iomanip>
using namespace std;


//////////////////////////////////
//Global Variables
//////////////////////////////////
int const TESTDATASIZE = 6;
int testData[TESTDATASIZE] = { 30,50,80,100,1000,10000 };

//////////////////////////////////
//Functions Prototypes
//////////////////////////////////
int Find(int, int[], int);
void calculateAverage(int,int&,int&);
int main()
{
	//////////////////////////////////
	//Local Variables
	//////////////////////////////////
	int calcAvg=0, realAvg=0;

	//////////////////////////////////
	//Styling
	//////////////////////////////////
	cout << left;


	//Print Headers
	cout << left << setw(15) << "Bound" << setw(28) << "Calculated Average" << "Real Average" << endl;
	cout << left << setw(15) << "-----" << setw(28) << "------------------" << "------------" << endl;

	//////////////////////////////////
	//Processing and print result
	//////////////////////////////////
	for (int i = 0; i < TESTDATASIZE; i++)
	{
		calculateAverage(testData[i],calcAvg,realAvg);

		cout << left << setw(15) << testData[i] << setw(28) << calcAvg << realAvg << endl;

	}


	system("pause");
	return 0;
}

int Find(int x, int A[], int n) // array of size n
{
	int  j;
	for (j = 0; j < n; j++) {
		      if (x == A[j]) {
			return (j + 1); //the position is 1 more than the index
		}
	}
	return 0; // x is not an element of the array
}

void calculateAverage(int bound, int& resForCalcAvg, int& resForRealAvg)
{
	//////////////////////////////////
	//Local Variables
	//////////////////////////////////
	const int n = 50;
	int hits = 0, x = rand() % (bound - 0 + 1) + 0;
	float q = 0;
	int sequence[n];
	int totalSteps = 0;

	for (int i = 0; i < 10000; i++)
	{
		for (int i = 0; i < 50; i++)
		{
			int randNum = rand() % (bound - 0 + 1) + 0;
			sequence[i] = randNum;
		}
		int res = Find(x, sequence, n);
		if (res > 0)
		{
			hits++;
			totalSteps += res;
		}
		else
			totalSteps += 50;
	}

	q = hits / 10000.0;

	resForCalcAvg = (50.0 - (((q+0.0) * 50.0) / 2.0)) + ((q+0) / 2.0);
	resForRealAvg = totalSteps / 10000;
}