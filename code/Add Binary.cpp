#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        int last_a = a.size()-1;
        int last_b = b.size()-1;

        while(last_a >= 0 && last_b >= 0) {
            int sum = (a[last_a] - '0') + (b[last_b] - '0') + carry;
            res += to_string(sum%2);
            carry = sum/2;
            last_b--;
            last_a--;
        }

        while(last_a >= 0) {
            int sum = (a[last_a] - '0')  + carry;
            res += to_string(sum%2);
            carry = sum/2;
            last_a--;
        }

         while(last_b >= 0) {
            int sum = (b[last_b] - '0')  + carry;
            res += to_string(sum%2);
            carry = sum/2;
            last_b--;
        }

        if(carry != 0) {
            res += to_string(carry);
        }

        reverse(res.begin(),res.end());
        return res;

    }
};



int main() {
    string a = "11";
    string b = "1";
    Solution s;
    cout << s.addBinary(a,b) << endl;


    return 0;
}