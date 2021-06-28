#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    string removeDuplicates(string s){
        stack<char> st;
        for(int i=0; i<s.length(); ++i){
            if(st.empty() || st.top() != s[i])
                st.push(s[i]);
            else
                st.pop();
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    string s = "abbaca";
    Solution solve;
    cout << solve.removeDuplicates(s) << endl;
    return 0;
}