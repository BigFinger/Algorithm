#include <iostream>
#include <vector>
using namespace std;

#define MAXVALUE 1000
typedef struct{
	int value;
	int index;
}MinValue;

typedef struct{
	int dir;
	int index;
}pathValue;

MinValue getMinIndex(vector<int> s, int length, int weightMap[][9], int index){
	MinValue result = {0};
	int minValue = MAXVALUE;
	for(int i = 0; i < length; i++)
	{
		if (weightMap[index][i] < minValue && find(s.begin(), s.end(), i) == s.end())
		{
			minValue = weightMap[index][i];
			result.value = weightMap[index][i];
			result.index = i;
		}
	}
	return result;
}
int getMinValue(vector<int> s, int length, int weightMap[][9], int index){
	int result = MAXVALUE;
	for (int i = 0; i < length; i++)
	{
		if (weightMap[index][i] < result && find(s.begin(), s.end(), i) == s.end())
		{
			result = weightMap[index][i];
		}
	}
	return result;
}

vector< vector<int> > bothWayDijkstra(int length, int weightMap[][9], int startIndex, int destIndex){
	vector<int> sList;
	vector<int> dList;
	vector<int> sRemain;
	vector<int> dRemain;
	MinValue sValue = {0};
	MinValue tValue = {0};
	MinValue value = {0};
	int dirIndex = 0;
	bool stop = false;
	vector< vector<int> > resultPath;
	vector< vector<int> > sPath;
	vector< vector<int> > dPath;
	for (int i = 0; i < length; i++)
	{
		if (i != 0)
			sRemain.push_back(i);
		if (i != length - 1)
			dRemain.push_back(i);
	}
	sList.push_back(0);
	dList.push_back(length - 1);
	while(!stop)
	{
        /* 获取还未探索点中最短距离的点索引 */
		sValue = getMinIndex(sList, length, weightMap, startIndex);
		tValue = getMinIndex(dList, length, weightMap, destIndex);
		if (sValue.value < tValue.value)
		{
			dirIndex = 0;
			value = sValue;
		}
		else
		{
			dirIndex = destIndex;
			value = tValue;
		}
        /* 松弛此次DJ源点到其它点的距离 */
		for (int i = 0; i < length; i++)
		{
			if (weightMap[dirIndex][value.index] + weightMap[value.index][i] < weightMap[dirIndex][i])
			{
				weightMap[dirIndex][i] = weightMap[dirIndex][value.index] + weightMap[value.index][i];
			}
		}
        /* 更新是否已经找到最短距离 */
		for (int i = 0; i < length; i++)
		{
			if (weightMap[startIndex][i] + weightMap[destIndex][i] < weightMap[startIndex][destIndex])
			{
				weightMap[startIndex][destIndex] = weightMap[startIndex][i] + weightMap[destIndex][i];
			}
			if (weightMap[startIndex][i] + weightMap[destIndex][i] < weightMap[destIndex][startIndex])
			{
				weightMap[destIndex][startIndex] = weightMap[startIndex][i] + weightMap[destIndex][i];
			}
		}
		if (dirIndex == 0)
		{
			sList.push_back(value.index);
			sRemain.erase(find(sRemain.begin(), sRemain.end(), value.index));
		}
		else
		{
			dList.push_back(value.index);
			dRemain.erase(find(dRemain.begin(), dRemain.end(), value.index));
		}
        /* 判断是否需要停止双向DJ探索 */
		int sMinValue = getMinValue(sList, length, weightMap, startIndex);
		int dMinValue = getMinValue(dList, length, weightMap, destIndex);
		if (weightMap[startIndex][destIndex] <= (sMinValue + dMinValue) ||
			weightMap[destIndex][startIndex] <= (sMinValue + sMinValue))
		{
			stop = true;
		}
	}
	return resultPath;
}

int main() {
	int weightMap[9][9] = {
		0, 3, 6, 7, MAXVALUE, MAXVALUE,MAXVALUE,MAXVALUE,MAXVALUE,
		3, 0, 1, MAXVALUE, 4, MAXVALUE,MAXVALUE,MAXVALUE,MAXVALUE,
		6, 1, 0, MAXVALUE, MAXVALUE, 2,MAXVALUE,MAXVALUE,MAXVALUE,
		7,MAXVALUE,MAXVALUE,0,MAXVALUE,3,4,MAXVALUE,MAXVALUE,
		MAXVALUE,4,MAXVALUE,MAXVALUE,0,MAXVALUE,MAXVALUE,1,MAXVALUE,
		MAXVALUE,MAXVALUE,2,3,MAXVALUE,0,MAXVALUE,1,2,
		MAXVALUE,MAXVALUE,MAXVALUE,4,MAXVALUE,MAXVALUE,0,MAXVALUE,5,
		MAXVALUE,MAXVALUE,MAXVALUE,MAXVALUE,1,1,MAXVALUE,0,2,
		MAXVALUE,MAXVALUE,MAXVALUE,MAXVALUE,MAXVALUE,2,5,2,0
	};
	bothWayDijkstra(9, weightMap, 0, 8);
	
	system("PAUSE");
	return 0;
}