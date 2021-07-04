#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        int max_count = 0;
        for(const int &num : nums){
            max_count = max(max_count, ++counts[num]);
        }
        vector<vector<int>> buckets(max_count+1);
        for(const auto &p : counts){
            buckets[p.second].push_back(p.first);
        }

        vector<int> ans;
        for(int i=max_count; i>=0 && ans.size() < k; --i){
            for(const int &num : buckets[i]){
                ans.push_back(num);
                if(ans.size() == k){
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1,1,1,1,2,2,3,4};
    int k = 2;
    Solution s;
    nums = s.topKFrequent(nums, k);
    for(const auto &i : nums)
        cout << i << " ";
    return 0;
}
