#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void nextPermutation(vector<int>& nums) {
        recursion(nums, nums.size()-1);
    } 

    void recursion(vector<int>& nums, int start) {
        int k;
        for(int i = start; i > 0; i--) {
            if(nums[i] > nums[i-1]) {
                swap(nums[i], nums[i-1]);
                k = i;
                break;
            }
        }

        for(int i = k; i < nums.size()-1; i++) {
            if(nums[i] > nums[i+1]) {
                swap(nums[i], nums[i+1]);
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    s.nextPermutation(nums);
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i];
    cout << endl;
    return 0;
}

