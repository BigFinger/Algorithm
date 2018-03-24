#include <iostream>
#include <vector>
using namespace std;

#define INT_MAX 999

int getMinValue(vector<int>& s, int weightMap[][7], int length) {
    int minValue = INT_MAX;
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

vector< vector<int> > djkstra(int length, vector<int>& pointList, int weightMap[][7]) {
    vector<int> s;
    vector< vector<int> >result;
    for (int i = 0; i < length; i++)
    {
        vector<int> path;
        result.push_back(path);
    }
    s.push_back(pointList[0]);
    pointList.erase(find(pointList.begin(), pointList.end(), pointList[0]));
    while (!pointList.empty())
    {
        int value = getMinValue(s, weightMap, length);
        for (int i = 0; i < length; i++)
        {
            if ((weightMap[0][value] + weightMap[value][i]) < weightMap[0][i])
            {
                weightMap[0][i] = weightMap[0][value] + weightMap[value][i];
                result[i] = result[value];
                result[i].push_back(value);
            }
        }
        s.push_back(value);
        pointList.erase(find(pointList.begin(), pointList.end(), value));
    }
    for (int i = 0; i < result.size(); i++)
    {
        result[i].push_back(i);
    }
    return result;
}

int main() {
    int weightMap[7][7] = {
    0, 12, INT_MAX, INT_MAX, INT_MAX, 16,14,
    12, 0, 10, INT_MAX, INT_MAX, 7,INT_MAX,
    INT_MAX, 10, 0, 3, 5, 6,INT_MAX,
    INT_MAX,INT_MAX,3,4,INT_MAX,INT_MAX,INT_MAX,
    INT_MAX,INT_MAX,5,4,0,2,8,
    16,7,6,INT_MAX,2,0,9,
    14,INT_MAX,INT_MAX,INT_MAX,8,9,0
    };
    vector<int> pointList;
    for (int i = 0; i < 7; i++)
    {
        pointList.push_back(i);
    }
    vector< vector<int> > result = djkstra(7, pointList, weightMap);
    for (int i = 0; i < result.size(); i++)
    {
        cout << "0->" << i << ":" << weightMap[0][i] << endl;
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << ",";
        }
        cout << endl;
    }
    system("PAUSE");
    return 0;
}