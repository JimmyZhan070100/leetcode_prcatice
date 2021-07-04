#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counts;
        for(char c : s)
            ++counts[c];
        sort(s.begin(), s.end(), [&](char &a, char &b){
            return counts[a] > counts[b] || (counts[a] == counts[b] && a < b);
        });
        return s;
    }
};

int main()
{
    string s = "tree";
    Solution solve;
    cout << solve.frequencySort(s) << endl;
    return 0;
}
