#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
 
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        set<char> c;
        map<char, int> m;
        int mx = 1;
        c.insert(s[0]);
        m[s[0]] = 0;
        int dp[s.length()];
        for(int i = 0; i < s.length(); i++)
            dp[i] = 1;

        for(int i = 1; i < s.length(); i++) {
            if(c.find(s[i]) == c.end()) {
                c.insert(s[i]);
                dp[i] = dp[i-1]+1;
                m[s[i]] = i;
            } else {
                if(i - dp[i-1] == m[s[i]]) {
                    dp[i] = dp[i-1];
                } else if(i - dp[i-1] < m[s[i]]){
                    dp[i] = i-m[s[i]];
                } else {
                    dp[i] = dp[i-1]+1;
                }
            }

            m[s[i]] = i;
            if(dp[i] > mx)
                mx = dp[i];
        }
        return mx;

    }   
};
    
int main() {
    Solution s;
    string ss = "tmmxft";
    cout << s.lengthOfLongestSubstring(ss) << endl;



}