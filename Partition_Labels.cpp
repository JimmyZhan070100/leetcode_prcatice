#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
 * Use greedy algorithm
 * Set last_index to record each character in string's index (ascii code)
 * Set start and end to check partition's interval, until (i==end) means
 * it would be a set.
*/


class Solution{
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_index(128, 0);
        for(int i=0; i<s.length(); ++i)
            last_index[s[i]] = i;
        vector<int> ans;
        int start = 0, end = 0;
        for(int i=0; i<s.length(); ++i){
            end = max(end, last_index[s[i]]);
            if(i==end){
                ans.push_back(end-start+1);
                start = end+1;
            }
        }
        return ans;
    }
};

int main()
{
    string s = "ababcbacadefegdehijhklij";
    Solution solve;
    cout << solve.partitionLabels(s).size() << endl;
    return 0;
}