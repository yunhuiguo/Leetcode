#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commom;
        if(strs.size() > 0) {
            int shortest = strs[0].length();
            for(int i = 1; i < strs.size(); i++) {
                if(strs[i].length() < shortest)
                    shortest = strs[i].length();
            }

            for(int i = 0; i < shortest; i++) {
                int flag = 1;
                for(int j = 1; j < strs.size(); j++) {
                    if(strs[j-1][i] != strs[j][i]) {
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                    commom += strs[0][i];
                else
                    break;
            }
        }

        return commom;
    }
};  

int main() {
    vector<string> strs;
    
    strs.push_back("abcd");
    strs.push_back("ab");
    strs.push_back("abc");
    strs.push_back("abcde");
    
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;


    return 0;
}