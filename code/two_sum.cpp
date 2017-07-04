#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
                    unordered_map<int, int> map;
                    for(int i = 0; i < nums.size(); i++) 
                        map[nums[i]] = i;
                    vector<int> r;
                    for(int i = 0; i < nums.size(); i++) {
                        if(map.find(target- nums[i]) != map.end()) {
                            if(i != map[target-nums[i]]) {
                                r.push_back(i);
                                r.push_back(map[target-nums[i]]);
                                return r;
                            }
                        }
                    }
                }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(-4);
    int target = -8;
    vector<int> r = s.twoSum(nums, target);
    for(int i = 0; i < r.size(); i++)
        cout << r[i];
    cout <<endl;
}
