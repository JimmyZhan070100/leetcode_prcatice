#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * DFS + Backtracking
 * count : has only two values, 0 or 1 which means its position 
 * pos : means current position's number
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb(k, 0);
        int count = 0;
        backtracking(ans, comb, count, 1, n, k);
        return ans;
    }
    
    void backtracking(vector<vector<int>> &ans, vector<int> &comb, int &count, int pos, int n, int k){
        if(count == k){
            ans.push_back(comb);
            return;
        }
        for(int i=pos; i<=n; ++i){
            comb[count++] = i;  // change current node state
            backtracking(ans, comb, count, i+1, n, k);
            --count;    // recover current node's state
        }
    }
};

int main()
{
    int n=4, k=2;
    Solution s;
    vector<vector<int>> ans = s.combine(n, k);
    for(const auto &row: ans){
        for(const auto &col : row)
            cout << col << " ";
        cout << endl;
    }
    return 0;
}