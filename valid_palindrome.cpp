#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isPalindrome(string s){
        string temp;
        for(char ch:s){
            if(isalnum(ch)){
                temp += towlower(ch);
            }
        }
        int lhs = 0, rhs = temp.length()-1;
        while(lhs < rhs){
            if(temp[lhs] != temp[rhs]){
                return false;
            }
            ++lhs;
            --rhs;
        }
        return true;
    }
};

int main()
{
    string str = "A man, a plan, a canal: Panama";
    Solution s;
    cout << s.isPalindrome(str) << endl;
    return 0;
}