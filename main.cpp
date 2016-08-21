#include <iostream>
#include "conio.h"


using namespace std;

//Functions for sorting
void bubbleSort(int* arrayToSort, int n);
void insertSort(int* arrayToSort, int n);
void selectionSort(int* arrayToSort, int n);

void arrayPrint(int* arrayToPrint, int n);

int main()
{
	int SIZE;
	cout << "Input the size of the array: ";
	cin >> SIZE;

	int *arr = new int[SIZE]; 

	cout << "Input the array: " << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Input the element [" << i << "]: ";
		cin >> arr[i];
	}

	cout << endl << "1 - Bubble Sort\n2 - Insert Sort\n3 - Selection Sort \n\nChoose the method of sorting:";
	char choise = _getch();

	cout << endl << "Old array: \t";
	arrayPrint(arr, SIZE);
	cout << endl;
	switch (choise)
	{
	case '1':	bubbleSort(arr, SIZE);		break;
	case '2':	insertSort(arr, SIZE);		break;
	case '3':	selectionSort(arr, SIZE);	break;
	}
	
	cout << "Sorted array: \t" ;
	arrayPrint(arr, SIZE);
	
	cout << endl << endl;
	delete[] arr;
	system("pause");
	return 0;
}

void bubbleSort(int* arrayToSort, int n)
{
	for (int i = 0; i < (n - 1); i++)
	{
		for (int j = 0; j < (n - 1 - i); j++)
		{
			if (arrayToSort[j] > arrayToSort[j + 1])
			{
				int temp = arrayToSort[j];
				arrayToSort[j] = arrayToSort[j + 1];
				arrayToSort[j + 1] = temp;
			}
		}
	}
}

void insertSort(int* arrayToSort, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j < 0; j--)
		{
			if (arrayToSort[j - 1] > arrayToSort[j])
			{
				int temp = arrayToSort[j];
				arrayToSort[j] = arrayToSort[j + 1];
				arrayToSort[j + 1] = temp;
			}
		}
	}

}

void selectionSort(int* arrayToSort, int n)
{
	for (int i = 0; i < (n - 1); i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arrayToSort[j] < arrayToSort[min])
				min = j;
		}
		int temp = arrayToSort[i];
		arrayToSort[i] = arrayToSort[min];
		arrayToSort[min] = temp;
	}

}

void arrayPrint(int* arrayToPrint, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arrayToPrint[i] << " ";
	}
}