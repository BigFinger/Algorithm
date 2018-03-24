#include <iostream>
#include <vector>
using namespace std;

void CountingSort(vector<int>& num, int unit){
    int length = num.size();
    int *temp = new int[length + 1];
    int *sub = new int[length];
    memset(temp, 0, sizeof(int) * (length + 1));
    memset(sub, 0, sizeof(int) * length);

    for (int i = 0; i < length; i++)
    {
        temp[(num[i] / unit % 10) + 1]++;
    }
    
    for (int i = 1; i <= length; i++)
    {
        temp[i] += temp[i - 1];
    }

    for (int i = 0; i < length; i++)
    {
        sub[temp[(num[i] /unit % 10)]++] = num[i];
    }
    for (int i = 0; i < length; i++)
    {
        num[i] = sub[i];
    }
    delete []temp;
    delete []sub;
}

void RadixSort(vector<int>& num, int len){
    int unit = 1;
    for (int i = 0; i < len; i++)
    {
        CountingSort(num, unit);
        unit *= 10;
    }
}

int main(){
    vector<int> num;
    num.push_back(20);
    num.push_back(90);
    num.push_back(64);
    num.push_back(289);
    num.push_back(998);
    num.push_back(365);
    num.push_back(852);
    num.push_back(123);
    num.push_back(789);
    num.push_back(456);

    RadixSort(num, 3);
    printf("基数排序结果：");
    for (int i = 0; i < num.size(); i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}