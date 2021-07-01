#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n){
        int pos = m-- + n-- - 1;
        while(m>=0 && n>=0){
            num1[pos--] = num1[m] > num2[n]? num1[m--]:num2[n--];
        }
        while(n>=0){
            num1[pos--] = num2[n--];
        }
    }
};

int main()
{
    vector<int> num1 = {1,2,3,0,0,0};
    vector<int> num2 = {2,5,6};
    int m=3, n = 3;
    Solution s;
    s.merge(num1, m, num2, n);
    for(const auto &iter : num1)
        cout << iter << " ";
    return 0;
}