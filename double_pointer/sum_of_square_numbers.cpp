#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    bool judgeSquareSumv(int c){
        long left = 0;
        long right = (int)sqrt(c);
        while(left <= right){
            long sum = left*left + right*right;
            if(sum == c){
                cout << left << " " << right << endl;
                return true;
            }
            else if(sum < c)    ++left;
            else    --right;
        }
        return false;
    }
};

int main()
{
    int c = 5;
    Solution s;
    cout << s.judgeSquareSumv(c);
    return 0;
}