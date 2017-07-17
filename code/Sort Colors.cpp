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

    void sortColors(vector<int>& nums) {
        if(nums.size() != 0) {
            int last_zero = 0;
            int last_two = nums.size()-1;

            while(nums[last_zero] == 0)
                last_zero++;
            while(nums[last_two] == 2)
                last_two--;

            int run = last_zero;
            while(run <= last_two) {

                    while( (nums[run] == 0 && run != last_zero)|| (nums[run] == 2 && run != last_two)) {
                        if(nums[run] == 0) { 
                            swap(nums[run], nums[last_zero]);
                            last_zero++;
                        } else if(nums[run] == 2) {
                            swap(nums[run], nums[last_two]);
                            last_two--;
                        }
                    }
                    run++;
            }
        }
    }
};


int main() {
   
    Solution s;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    s.sortColors(nums);
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i];
   
    cout << endl;


    return 0;
}