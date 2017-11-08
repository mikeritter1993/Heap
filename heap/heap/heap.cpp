//Author: Michael Ritter
//Date: 10/12/2015
//Description: Implementation of a heap by me for C++ assignment.  
#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 2000;		//max number of heap nodes

void checkSwap(int heap[MAX], int i);							//used to check if the child data should be swaped with its parent
void heapSort(int heap[MAX], int heapSorted[MAX], int last);	//standard heapsort

void main()
{
	ifstream infile;		//file with data
	int heap[MAX];			//array with the inserted data
	int heapSorted[MAX];	//array of sorted data
	int last;				//last node entered (MAX -1)


	infile.open("2000.txt");


	int i = 1;
	while (i < MAX)				//Insertion loop
	{
		infile >> heap[i];
		checkSwap(heap, i);
		last = i;
		i++;
	}

	heapSort(heap, heapSorted, last);

	for (int j = 1; j < MAX; j++)		//print loop
	{
		cout << heapSorted[j] << "\t";
	}

	infile.close();
	cout << endl << endl;
	system("PAUSE");
}



//Description: checks if the child nodes data need to be swaped with the parents to keep with the heap rules.
void checkSwap(int heap[MAX], int i)
{
	int hold;

	if (i / 2 != 0)
	{
		while (heap[i] < heap[i / 2])
		{
			hold = heap[i];
			heap[i] = heap[i / 2];
			heap[i / 2] = hold;
			i = i / 2;
		}
	}
}

//Description: standard heap sort
void heapSort(int heap[MAX], int heapSorted[MAX], int last)
{
	int i = 1;
	int j = 1;
	int hold;

	while (i < MAX)
	{
		heapSorted[i] = heap[1];
		heap[1] = heap[last];
		heap[last] = NULL;
		last = last - 1;

		j = 1;

		while ((j * 2 + 1 <= last) && (heap[j] > heap[j * 2] || heap[j] > heap[j * 2 + 1]))
		{
			if (j * 2 + 1 <= last)
			{
				if (heap[j * 2] < heap[j * 2 + 1])
				{
					hold = heap[j];
					heap[j] = heap[j * 2];
					heap[j * 2] = hold;
					j = j * 2;
				}
				else
				{
					hold = heap[j];
					heap[j] = heap[j * 2 + 1];
					heap[j * 2 + 1] = hold;
					j = j * 2 + 1;
				}
			}
			else
			{
				if (heap[j] > heap[j * 2])
				{
					hold = heap[j];
					heap[j] = heap[j * 2];
					heap[j * 2] = hold;
					j = j * 2;
				}
			}
		}
		i++;
	}
}