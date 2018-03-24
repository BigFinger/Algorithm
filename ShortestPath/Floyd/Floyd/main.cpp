#include <iostream>
using namespace std;

#define MAXVALUE 1000

void floyd(int** weightMap, int** viaMap, int length){
	int runNum = 0;
	while(runNum < length)
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if ((weightMap[i][runNum] + weightMap[runNum][j]) < weightMap[i][j] && i != j)
				{
					weightMap[i][j] = weightMap[i][runNum] + weightMap[runNum][j];
					viaMap[i][j] = runNum;
				}
			}
		}
		runNum++;
	}
}

int main(){
	int pointNum, linkNum;
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
		weightMap[linkWeight[i][0] - 1][linkWeight[i][1] - 1] = linkWeight[i][2];
		weightMap[linkWeight[i][1] - 1][linkWeight[i][0] - 1] = linkWeight[i][2];
	}
	floyd(weightMap, viaMap, pointNum);
	for (int i = 0; i < pointNum; i++)
	{
		for (int j = 0; j < pointNum; j++)
		{
			if (i != j)
			{
				cout<< i << "->" << j << ":" << weightMap[i][j] << endl;
				cout<< "Path:";
				int start = i;
				int dest = j;
				cout << start << "->";
				while(start != dest)
				{
					if (viaMap[start][dest] == dest)
					{
						cout << viaMap[start][dest];
						break;
					}
					else
					{
						cout << viaMap[start][dest] << "->";
						start = viaMap[start][dest];
					}
				}
				cout << endl;
			}
			
		}
	}
	system("PAUSE");
	return 0;
}