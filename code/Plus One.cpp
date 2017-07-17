#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry = 0;


        for(int i = digits.size()-1; i >= 0; i--) {
            if(i == digits.size()-1) {
                int tmp = digits[i]+1;
                carry = tmp/10;
                res.push_back(tmp%10);
            } else {
                int tmp = digits[i]+carry;
                carry = tmp/10;
                res.push_back(tmp%10);
            }
        }

        if(carry != 0)
            res.push_back(carry);

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    vector<int> digits;
    digits.push_back(9);
    digits.push_back(9);
    digits.push_back(9);
    Solution s;
    vector<int> res = s.plusOne(digits);
    for(int i = 0;i < res.size(); i++)
        cout << res[i];
    cout << endl;

    return 0;
}

