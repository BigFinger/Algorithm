#include <iostream>
using namespace std; 

void BubbleSort(int *a, int length){
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (a[j + 1] < a[j])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
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
	BubbleSort(a, 10);
	cout<< "After Sort: " << endl;
	toString(a, 10);
	system("PAUSE");
	delete[] a;
	return 0;
}