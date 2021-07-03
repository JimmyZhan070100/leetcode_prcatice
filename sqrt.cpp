#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int mySqrt(int x){
        if(x==0)
            return x;
        int l = 1, r = x, mid, sqrt;
        while(l <= r){
            mid = l + (r-l)/2;   // Avoid (l+r)/2 might overflow
            sqrt = x/mid;
            if(sqrt == mid){
                return mid;
            }
            else if(mid > sqrt){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return r;
    }
};

int main()
{
    int x = 8;
    Solution s;
    cout << s.mySqrt(x) << endl;
    return 0;
}