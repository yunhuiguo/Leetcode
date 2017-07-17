#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp = nums;
        int max = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i]+dp[i-1] > dp[i])
                dp[i] = dp[i-1] + nums[i];
            if(dp[i] > max)
                max = dp[i];
        }
        return max;
    }
};

