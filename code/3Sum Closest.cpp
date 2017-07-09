#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            int closest = abs(nums[0]+nums[1]+nums[2]-target);
            int ii = 0, jj = 1, kk = 2;

            for(int i = 0; i < nums.size()-2; i++) {
                int start = i+1;
                int end = nums.size()-1;

                while(start < end) {

                    if(abs(nums[i]+nums[start]+nums[end]-target) <= closest) {
                        closest = abs(nums[i]+nums[start]+nums[end]-target);
                        ii = i;
                        jj = start;
                        kk = end;
                    } 

                    if(nums[i]+nums[start]+nums[end] - target > 0) {
                        end--;
                    } else {
                        start++;
                    }

                }
            }
            return nums[ii]+nums[jj]+nums[kk];

    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-4);
 
    cout << s.threeSumClosest(nums, 1) << endl;

}