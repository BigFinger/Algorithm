#include <iostream>
#include <vector>
using namespace std;

#define MAXVALUE 1000

typedef struct{
	int start;
	int dest;
	int weight;
}LinkWeight;

vector<int> bellman_ford(int length, vector<LinkWeight>& weightList){
	int runNum = 0;
	vector<int> result;
	for (int i = 0; i < length; i++)
	{
		if (i == 0)
			result.push_back(0);
		else
			result.push_back(MAXVALUE);
	}
	
	while(runNum < length)
	{
		for(int i = 0; i < weightList.size(); i++)
		{
			if (result[weightList[i].start] + weightList[i].weight < result[weightList[i].dest])
			{
				result[weightList[i].dest] =  result[weightList[i].start] + weightList[i].weight;
			}
		}
		runNum++;
	}
	return result;
}

int main(){
	int pointNum, linkNum;
	vector<LinkWeight> weightList;
	int linkWeight[12][3] = {
		1,2,12,
		1,6,16,
		1,7,14,
		2,3,10,
		2,6,7,
		3,4,3,
		3,5,5,
		3,6,6,
		4,5,4,
		5,6,2,
		5,7,8,
		6,7,9
	};
	pointNum = 7;
	int **weightMap = new int*[pointNum];
	int **viaMap = new int*[pointNum];
	for (int i = 0; i < pointNum; i++)
	{
		weightMap[i] = new int[pointNum];
		viaMap[i] = new int[pointNum];
		for (int j = 0; j < pointNum; j++)
		{
			weightMap[i][j] = MAXVALUE;
			viaMap[i][j] = j;
		}
	}
	linkNum = 12;
	for (int i = 0; i < linkNum; i++)
	{
		LinkWeight weight;
		weight.start = linkWeight[i][0] - 1;
		weight.dest = linkWeight[i][1] - 1;
		weight.weight = linkWeight[i][2];
		weightList.push_back(weight);
	}
	vector<int> result = bellman_ford(pointNum, weightList);
	bool hasCircle = false;
	for(int i = 0; i < weightList.size(); i++)
	{
		if (result[weightList[i].start] + weightList[i].weight < result[weightList[i].dest])
		{
			hasCircle = true;
		}
	}
	if (hasCircle)
	{
		cout << "有负环" << endl;
	}
	else
	{
		cout << "无负环" << endl;
	}
	for (int i = 1; i < result.size(); i++)
	{
		cout<< "0->" << i << ":" << result[i] << endl;
	}
	system("PAUSE");
	return 0;
}