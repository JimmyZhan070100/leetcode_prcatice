#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> graycode(int n){
        vector<int> ans;
        int powNum = 1 << n;
        for(int i=0; i<powNum; ++i){
            ans.push_back(i^i>>1);
        }
        return ans;
    }
};

int main()
{
    int n = 3;
    Solution s;
    for(const auto& item : s.graycode(n))
        cout << item << endl;
    return 0;
}