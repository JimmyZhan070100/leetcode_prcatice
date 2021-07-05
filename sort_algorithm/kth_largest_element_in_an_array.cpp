#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution{
public:
    int findKthLargest(vector<int> &nums, int k){
        int l = 0, r = nums.size()-1, target = nums.size() - k;
        while (l<r)
        {
            int mid = quickSelection(nums, l, r);
            if(mid == target){
                return nums[mid];
            }
            if(mid < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return nums[l];
    }

/**
 * quickSelection : quicksort + selection
 * But it just consider the subset which has its target, and
 * therefore, its time complexity is O(n).
*/
    int quickSelection(vector<int> &nums, int l, int r){
        int i = l+1, j=r;
        while(true){
            while(i<r && nums[i] <= nums[l])
                ++i;
            while(l<j && nums[j] >= nums[l])
                --j;
            if(i >= j)
                break;
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[j]);
        // j is pivot's index
        return j;
    }
};

int main()
{
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    Solution s;
    cout << s.findKthLargest(nums, k) << endl;
    return 0;
}
