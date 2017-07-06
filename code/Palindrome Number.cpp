#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int flag = 1;
        if(x < 0) {
            flag = 0;
            return flag;
        }   
        string n = to_string(x);
        for(int i = 0; i < n.length()/2; i++) {
            if(n[i] != n[n.length()-1-i]) {
                flag = 0;
                break;
            }
        }
    return flag;   
    }
};

int main() {
    int x = 123;
    Solution s;
    int flag = s.isPalindrome(x);
    cout << flag << endl;


}