#include <iostream>
using namespace std;


class Solution {
public:
    bool isalpha(char c) {
        if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            return 1;
        return 0;
    }

    int lengthOfLastWord(string s) {
        int cnt = 0;
        int flag = 0;

        for(int i = 0; i < s.length(); i++) {
            if(isalpha(s[i])) {
                if(flag == 1) {
                    if(cnt!= 0)
                        cnt = 0;
                    flag = 0;
                }
                cnt = cnt + 1;

            } else if(s[i] == ' ')
                flag = 1;
        }

        return cnt;
    }
};

int main() {
    string ss = "hello  day  ";
    Solution s;
    cout << s.lengthOfLastWord(ss) << endl;
    return 0;
}