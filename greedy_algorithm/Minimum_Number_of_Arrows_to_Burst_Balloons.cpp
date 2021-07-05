#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
 * Use Greedy algoritm, first we sort vector in ascending order,
 * then we select the first interval as our shoot coodinate.
 * If next points[i][0] greater than soot, adding it to be another shoot.
*/


class Solution{
public:
    int findMinArrowShots(vector<vector<int>>& points){
        if(points.empty())
            return 0;
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int shoot = points[0][1];
        int ans = 1;
        for(int i=1; i<points.size(); ++i){
            if(points[i][0] > shoot){
                shoot = points[i][1];
                ++ans;
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    Solution s;
    cout << s.findMinArrowShots(points) << endl;
    return 0;
}