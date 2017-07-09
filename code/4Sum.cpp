#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        if(nums.size() < 4)
            return res;
        else {
            for(int i = 0; i < nums.size()-3; i++) {
                if(i > 0)
                    while(nums[i] == nums[i-1])
                        i++;

                for(int j = i + 1; j < nums.size()-2; j++) {
                    if(j > i+1)
                        while(nums[j] == nums[j-1])
                            j++;

                    int start = j+1;
                    int end = nums.size()-1;
                    while(start < end) {
                        if(nums[i]+nums[j]+nums[start]+nums[end] == target) {
                            vector<int> r;
                            r.push_back(nums[i]);
                            r.push_back(nums[j]);
                            r.push_back(nums[start]);
                            r.push_back(nums[end]);
                            res.push_back(r);
                            start++;
                            end--;
                            while(nums[start] == nums[start-1])
                                start++;
                            while(nums[end] == nums[end+1])
                                end--;
                        } else if(nums[i]+nums[j]+nums[start]+nums[end] > target) {
                            end--;
                        }
                        else
                            start++;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(1);
    nums.push_back(-2);
    nums.push_back(2);
 
    vector<vector<int> > res = s.fourSum(nums,0);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j];
        cout << endl;
    }

}