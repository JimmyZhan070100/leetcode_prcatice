#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findCircleNum(vector<vector<int>> &arr){
        int n = arr.size(), count = 0;
        vector<bool> visited(n, false);
        for(int i=0; i<n; ++i){
            if(!visited[i]){
                dfs(arr, i, visited);
                ++count;
            }
        }
        return count;
    }

    void dfs(vector<vector<int>> &arr, int i, vector<bool> &visited){
        visited[i] = true;
        for(int k=0; k<arr.size(); ++k){
            if(arr[i][k] == 1 && !visited[k])
                dfs(arr, k, visited);
        }
    }
};

int main()
{
    vector<vector<int>> arr = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    Solution s;
    cout << s.findCircleNum(arr) << endl;
    return 0;
}