#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if( n == 1) {
            string cur = "1";
            return cur;
        } else {
            string pre = "1";
            string cur;
            int cnt;
            for(int i = 1; i < n; i++) {
                cur = "";
                cnt = 1;
                for(int j = 0; j < pre.length(); j++) {
                    if( j < pre.length() - 1 && pre[j] == pre[j+1]) {
                        cnt++;
                    }  else {
                        cur += to_string(cnt);
                        cur += pre[j];
                        cnt = 1;
                    }
               }
               pre = cur;
            }
            return cur;
        }
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(7) << endl;

    return 0;
}