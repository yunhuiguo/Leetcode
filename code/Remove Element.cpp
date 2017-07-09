#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = 0;
        int start = 0;
        int end = nums.size()-1;
        while(start <= end) {
            while(nums[end] == val) 
                end--;
            if(nums[start] == val) {
                if(end > start) {
                    int tmp = nums[start];
                    nums[start] = nums[end];
                    nums[end] = tmp;
                } 
            } else {
                start++;
                length++;
            }
        }

        return length;    
    }
};

int main() {
    vector<int> ss;
    ss.push_back(3);
    ss.push_back(2);
    ss.push_back(3);
    ss.push_back(2);
    Solution s;
    cout << s.removeElement(ss,2) << endl;


    return 0;
}