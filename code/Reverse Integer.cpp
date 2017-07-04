#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x != 0) {
            res = 10*res + x%10;
            x = (x - x%10)/10;
        }
       return (res< INT_MIN || res>INT_MAX) ? 0 : res;
    }
};

int main() {
    
    int x = -123;
    Solution s;
    int res = s.reverse(x);
    cout << res << endl;

    return 0;

}
