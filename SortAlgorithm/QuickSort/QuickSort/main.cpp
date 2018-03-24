#include <iostream>
using namespace std; 

int partition(int* array, int start, int end){
	int index = end;
	int i = start - 1;
	for (int j = start; j < end; j++)
	{
		if (array[j] < array[index])
		{
			i++;
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	int temp = array[++i];
	array[i] = array[index];
	array[index] = temp;
	return i;
}

void QuickSort(int* array, int start, int end){
	if (start < end)
	{
		int mid = partition(array, start, end);
		QuickSort(array, start, mid - 1);
		QuickSort(array, mid + 1, end);
	}
}

void toString(int* a, int length){
	for (int i = 0; i < length; i++)
	{
		if (i != length - 1)
			cout << a[i] << ",";
		else
			cout << a[i] << endl;
	}
}

int main(){
	int *a = new int[10];
	for(int i = 0; i < 10; i++)
	{
		cin>>a[i];
	}
	cout<<"Before Sort:" <<endl;
	toString(a, 10);
	QuickSort(a, 0, 9);
	cout<< "After Sort: " << endl;
	toString(a, 10);
	system("PAUSE");
	return 0;
}