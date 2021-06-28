#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices){
        int num = prices.size();
        if(!num)
            return 0;
        int profit = 0;
        for(int i=1; i<num; i++){
            if(prices[i] > prices[i-1])
                profit += prices[i] - prices[i-1];
        }
        return profit;
    }
};

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}