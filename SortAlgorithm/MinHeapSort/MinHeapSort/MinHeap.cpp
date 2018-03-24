#include "MinHeap.h"

MinHeap::MinHeap(){}

MinHeap::~MinHeap(){}

bool MinHeap::isEmpty(){
	return mHeap.empty();
}

string MinHeap::toString(){
	string result;
	for (int i = 0; i <mHeap.size(); i++)
	{
		char tempLine[DEFAULTSIZE] = {0};
		sprintf(tempLine, "%d",mHeap[i]);
		result += tempLine;
		if (i != mHeap.size() - 1)
		{
			result += ",";
		}
	}
	return result;
}

int MinHeap::poll(){
	if (!isEmpty())
	{
		return mHeap[0];
	}
	return -1;
}

void MinHeap::shiftDown(int start, int end){
	for (int i = start; i < end;)
	{
		bool isLeft = false;
		int leftchild = i * 2 + 1;
		int rightchild = i * 2 + 2;
		if (leftchild <= end && mHeap[i] > mHeap[leftchild] ||
			rightchild <= end && mHeap[i] > mHeap[rightchild])
		{
			int min = mHeap[leftchild] < mHeap[rightchild] ? leftchild : rightchild;
			swap(mHeap[i], mHeap[min]);
			i = min;
		}
		else
		{
			i++;
		}
	}
}

void MinHeap::shiftUp(int end){
	for(int i = end; i > 0;)
	{
		int parent = i % 2 == 0 ? i / 2 - 1 : i / 2;
		if (parent >= 0 && mHeap[parent] > mHeap[i])
		{
			swap(mHeap[parent], mHeap[i]);
			i = parent;
		}
		else
		{
			i--;
		}
	}
}

void MinHeap::insertValue(const int value){
	mHeap.push_back(value);
	shiftUp(mHeap.size() - 1);
}

void MinHeap::removeMin(){
	if (!isEmpty())
	{
		swap(mHeap[mHeap.size() - 1], mHeap[0]);
		mHeap.pop_back();
		shiftDown(0, mHeap.size() - 1);
	}
}

void MinHeap::swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}