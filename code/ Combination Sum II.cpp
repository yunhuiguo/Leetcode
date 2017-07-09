#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int> > res;
            vector<int> r; 
            vector<int> used
            for(int i = 0; i < candidates.length(); i++)
                used.push_back(0);
            solve(candidates, res, r, target , 0, used);
            return res;
    }

    void solve(vector<int>& candidates, vector<vector<int> >& res, vector<int>& r, int target, int begin, vector<int>& used) {
            if(target == 0) {
                res.push_back(r);
                return;
            } 
            for(int i = begin; i < candidates.size() && target >= candidates[i]; i++) {  
                if(!used[i]) {
                    r.push_back(candidates[i]);
                    used[i] = 1;
                    solve(candidates, res, r, target - candidates[i], i);
                    r.pop_back();
                    used[i] = 0;
                }
            }
    }   
};


int main() {
    Solution s;
    vector<int> ss;
    ss.push_back(1);
    ss.push_back(2);

    vector<vector<int> > res = s.combinationSum2(ss, 4);
    
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
        }
        cout << endl;
    }
    
    return 0;
}