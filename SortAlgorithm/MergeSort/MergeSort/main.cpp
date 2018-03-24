#include <iostream>
using namespace std; 

void merge(int* array, int leftStart, int leftEnd, int rightStart, int rightEnd){
	if (leftEnd >= leftStart && rightEnd >= rightStart)
	{
		int *leftArray = new int[leftEnd - leftStart + 2];
		int *rightArray = new int[rightEnd - rightStart + 2];
		memcpy(leftArray, array + leftStart, sizeof(int) * (leftEnd - leftStart + 1));
		leftArray[leftEnd - leftStart + 1] = INT_MAX;
		memcpy(rightArray, array + rightStart, sizeof(int) * (rightEnd - rightStart + 1));
		rightArray[rightEnd - rightStart + 1] = INT_MAX;
		int i = 0;
		int j = 0;
		int index = leftStart;
		while(i < (leftEnd - leftStart + 1) || j < (rightEnd - rightStart + 1))
		{
			if (leftArray[i] < rightArray[j])
			{
				array[index++] = leftArray[i++]; 
			}
			else
			{
				array[index++] = rightArray[j++]; 
			}
		}
		delete[] leftArray;
		delete[] rightArray;
	}
}

void MergeSort(int *array, int start, int end){
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(array, start, mid);
		MergeSort(array, mid + 1, end);
		merge(array, start, mid, mid + 1, end);
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
	MergeSort(a, 0, 9);
	cout<< "After Sort: " << endl;
	toString(a, 10);
	system("PAUSE");
	delete[] a;
	return 0;
}