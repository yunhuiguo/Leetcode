#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> r;
        int used[nums.size()];
        for(int i = 0; i < nums.size(); i++)
            used[i] = 0;
        solve(res, r, nums, used);
        return res;
    }

    void solve(vector<vector<int> >& res, vector<int>& r, vector<int>& nums, int* used) {
        if(r.size() == nums.size()) {
            res.push_back(r);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(!used[i]) {
                used[i] = 1;
                r.push_back(nums[i]);
                solve(res, r, nums, used);
                r.pop_back();
                used[i] = 0;
            }
        }
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    Solution s;
    vector<vector<int> > res = s.permute(nums);
    for(int i = 0;i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) 
            cout << res[i][j];
        cout << endl;
    }

    return 0;
}