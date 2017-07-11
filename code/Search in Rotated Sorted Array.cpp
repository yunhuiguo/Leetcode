#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(target == nums[mid])
                return mid;

            if(nums[mid] > nums[high]) {
                if(target > nums[mid]) {
                    low = mid + 1;
                } else if(target < nums[mid] && target >= nums[low])
                    high = mid - 1;
                else if(target < nums[mid] && target < nums[low])
                    low = mid+1;

            } else {
                if(target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else if(target > nums[mid] && target > nums[high])
                    high = mid - 1;
                else if(target < nums[mid])
                    high = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(3);
    Solution s;
    cout << s.search(nums,3) << endl;

    return 0;
}