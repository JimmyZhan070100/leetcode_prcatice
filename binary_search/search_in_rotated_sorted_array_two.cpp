#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[l] == nums[mid]){
                ++l;
            }
            else if(nums[mid] <= nums[r]){
                if(target > nums[mid] && target <= nums[r]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            else{
                if(target >= nums[l] && target < nums[mid]){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 0;
    Solution s;
    cout << s.search(nums, target);
    return 0;
}