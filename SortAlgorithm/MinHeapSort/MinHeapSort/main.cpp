#include "MinHeap.h"

int main(){
	MinHeap Heap;

	printf("------------Insert------------\n");
	int arr[8] = {8, 7, 6, 5, 4, 3, 2, 1};
	for (int i = 0; i < 8; i++) {
		Heap.insertValue(arr[i]);
	}

	printf("%s\n",Heap.toString().c_str());
	
	printf("------------Remove------------\n");
	Heap.removeMin();
	printf("%s\n",Heap.toString().c_str());

	printf("------------Order------------\n");
	while(!Heap.isEmpty())
	{
		std::cout << Heap.poll() << ",";
		Heap.removeMin();
	}
	cout<<endl;
	system("PAUSE");
	return 0;
}