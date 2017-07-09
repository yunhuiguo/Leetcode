#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length == 0)
            return cnt;
        set<char> c;
        int cnt = 1;

        c.insert(s[0]);
        int end = 0, run = 1;
        int tmp = cnt;
        while(run < s.length) {
            if(c.find(s[run]) == c.end()) {
                c.insert(s[run]);
                run++; 
                tmp++;
            } else {
                if(tmp > cnt) {
                    cnt = tmp; 
                    end = run-1;
                }
                tmp = 1;
                run++;
            }
        }

        return cnt;
    }
};
    
int main() {
    Solution s;
    string ss = "pwwkew";
    cout << s.lengthOfLongestSubstring(ss) << endl;



}