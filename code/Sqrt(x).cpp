#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x < 0)
            return -1;
        if(x == 0)
            return x;

        int low = 1;
        int high = x/2+1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(mid == x/mid)
                return mid;f
            else if(mid > x/mid)
                high = mid - 1;
            else
                low = mid + 1;
        }      
        return low-1;  
    }

};

int main() {
    Solution s;
    cout << s.mySqrt(2147395599) << endl;



    return 0;
}