#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int> > res;
            vector<int> r;
            solve(candidates, res, r, target , 0);
            return res;
    }

    void solve(vector<int>& candidates, vector<vector<int> >& res, vector<int>& r, int target, int begin) {
            if(target == 0) {
                res.push_back(r);
                return;
            } 
            for(int i = begin; i < candidates.size() && target >= candidates[i]; i++) {                
                r.push_back(candidates[i]);
                solve(candidates, res, r, target - candidates[i], i);
                r.pop_back(); 
            }
    }   
};


int main() {
    Solution s;
    vector<int> ss;
    ss.push_back(1);
    ss.push_back(2);

    vector<vector<int> > res = s.combinationSum(ss, 4);
    
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
        }
        cout << endl;
    }
    
    return 0;
}