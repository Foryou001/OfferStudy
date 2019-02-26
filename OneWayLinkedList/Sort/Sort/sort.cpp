#include <iostream>

using namespace std;



void swap(int* array, int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	
	return;
}


//QuickSort

int Partition(int* array, int start, int end)
{
	//选取数组中的第一个元素为	基准元素
	int pivot = start;
	int key = array[pivot];

	for (int i = start + 1; i <= end; ++i)
	{
		if (array[i] < key && i != pivot + 1)
		{
			swap(array, i, ++pivot);
		}
	}
	swap(array, start, pivot);
}



void QuickSort(int* array, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int pivot = Partition(array, start, end);
	QuickSort(array, start, pivot - 1);
	QuickSort(array, pivot + 1, end);


}

int main()
{
	int array[] = { 1, 2, 8, 4, 3, 9 };
	QuickSort(array, 0, 5);

	for (int i = 0; i != 6; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}