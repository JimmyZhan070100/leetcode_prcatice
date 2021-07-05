#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> direction = {-1, 0, 1, 0, -1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int max_area = 0, island = 0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j]){
                    dfs(grid, i, j, island);
                    max_area = max(max_area, island);
                    island = 0;
                }
            }
        }
        return max_area;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int &island){
        grid[r][c] = 0;    // prevent from searching the same position
        ++island;
        for(int i=0; i<4; ++i){
            int x = r + direction[i], y = c + direction[i+1];
            if(x >= 0 && x<grid.size() && y >= 0 && y<grid[0].size() && grid[x][y])
                dfs(grid, x, y, island);
        }
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1,0,1,1,0,1,0,1},
        {1,0,1,1,0,1,1,1},
        {0,0,0,0,0,0,0,1}
    };
    Solution s;
    cout << s.maxAreaOfIsland(grid) << endl;
}