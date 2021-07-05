#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return vector<int> {-1, -1};
        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target)-1;
        if(lower == nums.size() || nums[lower] != target){
            return vector<int> {-1, -1};
        }
        return vector<int>{lower, upper};
    }

    int lower_bound(vector<int> &nums, int target){
        int l=0, r = nums.size(), mid;
        while(l < r){
            mid = l + (r-l)/2;
            if(nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    int upper_bound(vector<int> &nums, int target){
        int l = 0, r = nums.size(), mid;
        while(l < r){
            mid = l + (r-l)/2;
            if(nums[mid] > target)
                r = mid;
            else
                l = mid+1;
        }
        return l;
    }
};

int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    Solution s;
    for(const auto i : s.searchRange(nums, target))
        cout << i << " ";
    return 0;
}