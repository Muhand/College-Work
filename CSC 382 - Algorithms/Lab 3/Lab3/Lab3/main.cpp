///////////////////////////////////////////////
//						Muhand Jumah
//						CSC 382 Lab3
///////////////////////////////////////////////
#include<iostream>
#include<iomanip>
using namespace std;

//////////////////////////////////
//Global Variables
//////////////////////////////////
int const TESTDATASIZE = 6;
int testData[TESTDATASIZE] = { 100,500,1000,2500,3000,3500 };

//////////////////////////////////
//Functions Prototypes
//////////////////////////////////
int InsertionMod(int A[], int n);
void Insertion(int A[], int n);
void calculateAverage(int, int&, int&);

int main()
{

	//////////////////////////////////
	//Local Variables
	//////////////////////////////////
	int calcAvg = 0, realAvg = 0;

	//////////////////////////////////
	//Styling
	//////////////////////////////////
	cout << left;

	//Print Headers
	cout << left << setw(20) << "Input Size" << setw(28) << "Calculated Average" << "Real Average" << endl;
	cout << left << setw(20) << "----------" << setw(28) << "------------------" << "------------" << endl;

	//////////////////////////////////
	//Processing and print result
	//////////////////////////////////
	for (int i = 0; i < TESTDATASIZE; i++)
	{
		calculateAverage(testData[i], calcAvg, realAvg);
		cout << left << setw(20) << testData[i] << setw(28) << calcAvg << realAvg << endl;

	}
	system("pause");
	return 0;
}
void Insertion(int A[], int n) // in reality the elements to be sorted are indexed from
								 // index 1 to index n
{
	int i, j, temp;
	A[0] = -32768; //smallest possible integer using 2 bytes integer representation
	for (i = 1; i <= n; i++)
	{
		j = i;
		while (A[j] < A[j - 1]) { // swap 
			temp = A[j];
			A[j] = A[j - 1];
			A[j - 1] = temp;
			j--;
		}
	}
}

int InsertionMod(int A[], int n) // in reality the elements to be sorted are indexed from
								// index 1 to index n
{
	int comp = 0;
	int i, j, temp;
	A[0] = -32768; //smallest possible integer using 2 bytes integer representation
	for (i = 1; i <= n; i++) 
	{
		j = i;
		comp++;
		while (A[j] < A[j - 1]) { // swap 
			comp++;
			temp = A[j];
			A[j] = A[j - 1];
			A[j - 1] = temp;
			j--;
		}
	}

	return comp;
}

void calculateAverage(int bound, int& resForCalcAvg, int& resForRealAvg)
{
	//////////////////////////////////
	//Local Variables
	//////////////////////////////////
	//AverageCase = ((n^2)/4)+(3/4)n
	//MC = sumofSteps/total times generated

	const int n = 100;
	int totalSteps = 0;
	int *seq = new int[bound];

	for (int i = 0; i < 10000; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			int randNum = rand() % (bound - 0 + 1) + 0;
			seq[j] = randNum;
		}
		int res = InsertionMod(seq, bound);
		if (res > 0)
			totalSteps += res;
		else
			totalSteps += 50;
	}
	resForCalcAvg = (pow(bound, 2) / 4) + (3 / 4);
	resForRealAvg = totalSteps / 10000;
	//delete[] seq;

}

