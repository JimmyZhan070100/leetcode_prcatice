#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * DFS + backtracking
 * We swap (i, level) positions each iteration.
 * After finishing recursion, we swap again
*/

class Solution{
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtracking(nums, 0, ans);
        return ans;
    }

    void backtracking(vector<int> &nums, int level, vector<vector<int>> &ans){
        if(level == nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int i=level; i<nums.size(); ++i){
            swap(nums[i], nums[level]);
            backtracking(nums, level+1, ans);
            swap(nums[i], nums[level]);
        }
    }
};

int main()
{
    vector<int> nums = {1,2,3};
    Solution s;
    vector<vector<int>> ans = s.permute(nums);
    for(const auto &iter : ans){
        for(const auto &row : iter){
            cout << row << " ";
        }
        cout << endl;
    }
    return 0;
}