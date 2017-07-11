#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void swap(int& i, int& j) {
        int tmp = i;
        i = j;
        j = tmp;
    }

    vector<vector<int> > permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        recursion(res, nums, 0);
        return res;
        
    }

    void recursion(vector<vector<int> >& res, vector<int> nums, int start) {
        if(start == nums.size()-1) {
            res.push_back(nums);
            return;
        } 

        for(int k = start; k < nums.size(); k++) {
            if( start != k && nums[start] == nums[k]) continue;
                    swap(nums[start], nums[k]); 
                    recursion(res, nums, start+1);

            } 
        
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(-1);
    nums.push_back(2);
    Solution s;
    vector<vector<int> > res = s.permuteUnique(nums);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}