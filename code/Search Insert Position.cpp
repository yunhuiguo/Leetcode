#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == target)
                    return i;
                else  if (target < nums[i]) {
                    if(i == 0)
                        return 0;
                    else if(target > nums[i-1])
                            return i;
                } 
            }
            return int(nums.size());
    }
};
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] == target)
                return mid;
            else if(target > nums[mid])
                low++;
            else
                high--;
        }
        return low;
    }

    
};



int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    cout << s.searchInsert(nums,3) << endl;

}