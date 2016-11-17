///////////////////////////////////////////////
//				Muhand Jumah
//				CSC 382 Lab4
///////////////////////////////////////////////

#include<iostream>
#include<iomanip>

using namespace std;

//Global Variables and arrays
int* inputSize;
int* currentArray;

//Prototypes
void init();
void reAllocateGlobalMemory();
void generateArray(int size, int *&arrToFill);
void insertionSort(int size, int *arr);
void mergeSort(int *arr, int right, int left);
void merge(int *arr, int l, int m, int r);

int main()
{
	//Local variables
	clock_t begin;
	clock_t end;
	double insertion_time;
	double merge_time;

	init();																			//Initialize program

	//Set output styling
	cout << fixed << setprecision(4);
	cout << left << setw(15) <<"Input Size"<< setw(37) << "Insertion Sort (time in seconds)" << "Merge Sort (time in seconds)" <<endl;

	//Loop through the inputs size
	int i = 0;																		//Set counter to 0
	while (inputSize[i] > 0)
	{
		int size = inputSize[i];

		generateArray(size, currentArray);											//Generate a random array everytime there is a size
		
		
		begin = clock();															//Calculate current time
		insertionSort(size, currentArray);											//Do insertion sort
		end = clock();																//Calculate the time after the insertion function ran
		insertion_time = (double)(end - begin) / (double)CLOCKS_PER_SEC;			//Take the difference to see the execution time


		//Same as insertion but merge instead
		clock_t nbegin = clock();
		mergeSort(currentArray, 0, size-1);
		clock_t nend = clock();
		merge_time = (double)(nend - nbegin) / (double)CLOCKS_PER_SEC;


		cout << left << setw(15) << size << setw(37) << insertion_time << merge_time << endl;				//Print out the result

		i++;																		//Increament counter
	}

	reAllocateGlobalMemory();														//Restore allocated memory to avoid any memory leaks
	system("pause");
	return 0;
}

void init()
{
	inputSize = new int[6]{100, 1000, 10000, 50000, 100000, 200000 };
}

void reAllocateGlobalMemory()
{
	delete[] inputSize;
	delete[] currentArray;
}

void generateArray(int size, int *&arrToFill)
{
	arrToFill = new int[size];
	
	for (int i = 0; i < size; i++)
		arrToFill[i] = rand() % 1000;
}
void insertionSort(int size, int *arr)
{
	int j, temp;
	for (int i = 0; i < size; i++) {
		j = i;
		while (j > 0 && arr[j] < arr[j - 1]) {
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
}
void mergeSort(int *arr, int right, int left)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;

		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);

		merge(arr, left, middle, right);
	}
}

void merge(int *arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int* L = new int[n1];
	int* R = new int[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}