#include <iostream>
#include <vector>
using namespace std;

#define MAXVALUE 999

typedef struct{
	int value;
	int prePoint;
}ShortValue;

int getMinValue(vector<int>& s, int weightMap[][7], int length) {
	int minValue = MAXVALUE;
	int result = 0;

	for (int i = 0; i < length; i++)
	{
		if (weightMap[0][i] < minValue && find(s.begin(), s.end(), i) == s.end())
		{
			minValue = weightMap[0][i];
			result = i;
		}
	}

	return result;
}

vector<int> dynamicProgramming(int length, vector<int>& pointList, int weightMap[][7]) {
	vector<int> preValue;
	vector<int> prePoint;

	for (int i = 0; i < length; i++)
	{
		preValue.push_back(weightMap[0][i]);
		prePoint.push_back(0);
	}

	for(int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if ((weightMap[i][j] + preValue[i]) < preValue[j])
			{
				preValue[j] = weightMap[i][j] + preValue[i];
				prePoint[j] = i;
			}
		}
	}
	return preValue;
}

int main() {
	int weightMap[7][7] = {
		0, 12, MAXVALUE, MAXVALUE, MAXVALUE, 16,14,
		12, 0, 10, MAXVALUE, MAXVALUE, 7,MAXVALUE,
		MAXVALUE, 10, 0, 3, 5, 6,MAXVALUE,
		MAXVALUE,MAXVALUE,3,4,MAXVALUE,MAXVALUE,MAXVALUE,
		MAXVALUE,MAXVALUE,5,4,0,2,8,
		16,7,6,MAXVALUE,2,0,9,
		14,MAXVALUE,MAXVALUE,MAXVALUE,8,9,0
	};
	vector<int> pointList;
	for (int i = 0; i < 7; i++)
	{
		pointList.push_back(i);
	}
	vector<int> result = dynamicProgramming(7, pointList, weightMap);
	for (int i = 0; i < result.size(); i++)
	{
		cout << "0->" << i << ":" << result[i] << endl;
	}
	system("PAUSE");
	return 0;
}