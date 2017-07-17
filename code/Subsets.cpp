#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> tmp;
        res.push_back(tmp);
        int used[nums.size()];
        for(int i = 0; i < nums.size(); i++)
            used[i] = 0;

        recursive(res, nums, tmp, used, 0);
        return res;
    }

    void recursive(vector<vector<int> >& res, vector<int>& nums, vector<int>& tmp, int* used, int start)  {
            for(int j = start; j < nums.size(); j++) {
                if(!used[j]) {
                    used[j] = 1;
                    tmp.push_back(nums[j]);
                    res.push_back(tmp);
                    recursive(res, nums, tmp, used, j+1);
                    used[j] = 0;
                    tmp.pop_back();
                }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int> > res = s.subsets(nums);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
        }
        cout << endl;
    }
 
    return 0;

}