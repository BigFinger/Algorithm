#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define DEFAULTSIZE 10

class MinHeap{
public:
	MinHeap();
	~MinHeap();
public:
	void insertValue(const int value);
	void removeMin();
	bool isEmpty();
	string toString();
public:
	void shiftDown(int start, int end);
	void shiftUp(int end);
	int poll();
private:
	void swap(int& a, int& b);
private:
	vector<int> mHeap;
};