#include <iostream>
#include <vector>
using namespace std;

void CountingSort(vector<int> &num){
    int length = num.size();
    int *temp = new int[length + 1];
    int *value = new int[length];
    memset(value, 0 , sizeof(int) * length);
    memset(temp, 0 , sizeof(int) * (length + 2));
    for (int i = 0; i < length; i++)
    {
        int index = num[i];
        temp[index + 1]++;
    }
    for (int i = 1; i < length; i++)
    {
        temp[i] = temp[i] + temp[i - 1];
    }
    for (int i = 0; i < length; i++)
    {
        value[temp[num[i]]++] = num[i];
    }
    for (int i = 0; i < length; i++)
    {
        num[i] = value[i];
    }
	delete[] temp;
	delete[] value;
}

int main(){
    vector<int> num;
    int length, value;

    num.push_back(2);
    num.push_back(3);
    num.push_back(3);
    num.push_back(4);
    num.push_back(1);
    num.push_back(3);
    num.push_back(4);
    num.push_back(3);
    num.push_back(1);
    num.push_back(2);
    num.push_back(2);
    num.push_back(1);
    num.push_back(2);
    num.push_back(4);
    num.push_back(3);
    num.push_back(4);
    num.push_back(4);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
   
    CountingSort(num);
    for (int i = 0; i < 20; i++)
    {
        cout << num[i] << ",";
    }
    cout << endl;
    return 0;
}