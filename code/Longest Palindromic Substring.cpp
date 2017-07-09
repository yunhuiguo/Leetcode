#include <iostream>
#include <string>
using namespace std;


class Solution {
public:

    string longestPalindrome(string s) {
        int mx = 1;
        int j = 0, k = 0, tmp;
        int low_j = 0, high_k = 0;
        for(int i = 0; i < s.length(); i++) {
            j = i - 1;
            k = i + 1;
            tmp = 1;
            while(j >= 0 && k < s.length()) {
                if(s[j] == s[k]) {
                    tmp+= 2;
                    if(tmp > mx) {
                        mx = tmp;
                        low_j = j;
                        high_k = k;
                    }
                    j--;
                    k++;
                } else 
                    break;
            }

            j = i;
            k = i+1;
            tmp = 0;
            while(j >= 0 && k < s.length()) {
                if(s[j] == s[k]) {
                    tmp += 2;
                    if(tmp > mx) {
                        mx = tmp;
                        low_j = j;
                        high_k = k;
                    }
                    j--;
                    k++;
                } else
                    break;
            }
        }   
        return s.substr(low_j,high_k-low_j+1);
    }
};

int main() {
    Solution s;
    string ss = "a";
    cout << s.longestPalindrome(ss) << endl; 
    

}