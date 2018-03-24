#include <iostream>
using namespace std; 

void InsertSort(int *a, int length){
	for (int i = 0; i < length; i++)
	{
		int target = a[i];
		int j = i - 1;
		for (; j >= 0; j--)
		{
			if (a[j] > target)
			{
				a[j + 1] = a[j];
			}
			else
			{
				break;
			}
		}
		a[j + 1] = target; 
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
	InsertSort(a, 10);
	cout<< "After Sort: " << endl;
	toString(a, 10);
	system("PAUSE");
	delete[] a;
	return 0;
}