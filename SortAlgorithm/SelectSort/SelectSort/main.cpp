#include <iostream>
using namespace std; 

void SelectSort(int *a, int length){
	for (int i = 0; i < length; i++)
	{
		int index = i;
		for (int j = i; j < length; j++)
		{
			if (a[j] < a[index])
			{
				index = j;
			}
		}
		int temp = a[index];
		a[index] = a[i];
		a[i] = temp;
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
	SelectSort(a, 10);
	cout<< "After Sort: " << endl;
	toString(a, 10);
	system("PAUSE");
	delete[] a;
	return 0;
}