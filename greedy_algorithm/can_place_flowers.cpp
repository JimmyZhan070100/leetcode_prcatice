#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * thinking : [i-1], [i], [i+1] continuous three of flowerbed be empty
 * then add 1 into [i]
 * How to deal with begining and ending : insert 0 into begining and 
 * push_back 0 into ending
*/

class Solution{
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n){
            flowerbed.insert(flowerbed.begin(), 0);
            flowerbed.push_back(0);
            int size = flowerbed.size();
            int res = 0;
            for(int i=1; i<size-1; ++i){
                if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                    ++res;
                    flowerbed[i] = 1;
                }
            }
            return res >= n;
        }
};


int main()
{
    vector<int> flowerbed = {0,1,0};
    int n = 1;
    Solution s;
    cout << s.canPlaceFlowers(flowerbed, n) << endl;
    return 0;
}