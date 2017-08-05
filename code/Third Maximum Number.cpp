
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void max_heapify(vector<int>& nums, int i, int ss) {
        int l = 2*i;
        int r = 2*i + 1;
        int largest;
        if(l <= ss && nums[l] > nums[i])
            largest = l;
        else
            largest = i;

        if(r <= ss && nums[r] > nums[largest])
            largest = r;

        if(largest != i) {
            int tmp = nums[largest];
            nums[largest] = nums[i];
            nums[i] = tmp;
            max_heapify(nums, largest, ss);
        }
    }

    void build_heap(vector<int>& nums) {
        for(int i = nums.size()/2; i >= 0; i--) {
            max_heapify(nums, i, nums.size()-1);
        }
    }


    int thirdMax(vector<int>& nums) {
        build_heap(nums);

        int one_max, sec_max, third_max;
        int ss = nums.size()-1;

        one_max = nums[0];
        nums[0] = nums[ss];
        ss = ss - 1;
        if(ss >= 0) {
            max_heapify(nums, 0, ss);

            while(nums[0] == one_max) {
                nums[0] = nums[ss];
                ss = ss - 1;
                if(ss >= 0) {
                    max_heapify(nums, 0, ss);
                } else
                    return one_max;
            }

            sec_max = nums[0];
            nums[0] = nums[ss];
            ss = ss - 1;
            if(ss >= 0) {
                max_heapify(nums, 0, ss);
                while(nums[0] == sec_max) {
                    nums[0] = nums[ss];
                    ss = ss - 1;
                    if(ss >= 0) {
                        max_heapify(nums, 0, ss);
                    } else
                        return one_max;
                }

                third_max = nums[0];
                return third_max;
            } else
                return one_max;

        } else
            return one_max;
    }
};

int main() {
    Solution s;
    vector<int> nums1;

    nums1.push_back(2);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(1);

    int third = s.thirdMax(nums1);
    cout << third << endl;

    return 0;
}