#include <iostream>
#include <vector>
using namespace std;

void shellSort(vector<int> &num){
    int length = num.size();
    for(int shellLen = length / 2; shellLen > 0; shellLen /= 2)
    {
        for (int i = shellLen; i < length; i++)
        {
            int target = num[i];
            int j = i;
            while((j - shellLen) >= 0)
            {
                if (target < num[j - shellLen])
                {
                    num[j] = num[j - shellLen];
                }
                else
                {
                     break;
                }
                j -= shellLen;
            }
            num[j] = target;
        }
    }
}

int main(){
    vector<int> num;
    int unit = 0;
    int length = 0;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> unit;
        cout << unit << ",";
        num.push_back(unit);
    }
    cout << endl;
    shellSort(num);
    for (int i = 0; i < length; i++)
    {
        cout << num[i] << ",";
    }
    cout << endl;
    return 0;
}