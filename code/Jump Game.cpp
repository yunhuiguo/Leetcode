#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) 
            return 1;
        int flag = 1;
        int last_index = nums.size()-1;
        int run = last_index-1;

        while(run >= 0 ) {
            while(run >= 0 && nums[run] < last_index - run) {
                run--;
                flag = 0;
            }

            if(run == -1 && flag == 0) 
                return 0;
            flag = 1;
            last_index = run;
            run = last_index - 1;
        }
        
        if(flag == 1)
            return 1;
        return 0;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(4);
    Solution s;
 
    cout <<  s.canJump(nums) <<  endl;

    return 0;
}

