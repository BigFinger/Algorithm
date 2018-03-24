#include <iostream>
#include <vector>
using namespace std;


void InsertSort(vector<int> &num, int left, int right){
    if (left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            int temp = num[i];
            int j = i - 1;
            while (j >= left && num[j] > temp)
            {
                num[j + 1] = num[j];
                j--;
            }
            num[j + 1] = temp;
        }
    }
}

void CountingSort(vector<int> &num, vector<int> &index, int unit){
    int length = num.size();
    int *temp = new int[length];
    int *indexValue = new int[length + 1];
    memset(indexValue, 0 ,sizeof(int) * (length + 1));
    memset(temp, 0 ,sizeof(int) * length);

    for (int i = 0; i < length; i++)
    {
        indexValue[num[i] / unit % 10 + 1]++;
    }
    for (int i = 1; i <= length; i++)
    {
        indexValue[i] += indexValue[i - 1];
    }

    for (int i = 0; i < length + 1; i++)
    {
        index.push_back(indexValue[i]);
    }
    for (int i = 0; i < length; i++)
    {
        temp[indexValue[num[i] / unit % 10]++] = num[i]; 
    }
    for (int i = 0; i < length; i++)
    {
        num[i] = temp[i];
    }
    delete []temp;
}

void BucketSort(vector<int> &num){
    vector<int> index;
    CountingSort(num, index, 10);

    for (int i = 0; i < num.size(); i++)
    {
        int left  = index[i];
        int right = index[i + 1] - 1;
        InsertSort(num, left, right);
    }
}

int main(){
    vector<int> num;
    num.push_back(29);
    num.push_back(25);
    num.push_back(3);
    num.push_back(49);
    num.push_back(9);
    num.push_back(37);
    num.push_back(21);
    num.push_back(43);

    BucketSort(num);

    printf("Í°ÅÅÐò½á¹û£º");
    for (int i = 0; i < num.size(); i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}