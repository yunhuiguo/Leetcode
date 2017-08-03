
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> tmp;

        rescurive(res, tmp, n, k, 1);

        return res;
    }

    void rescurive(vector<vector<int> >& res, vector<int>& tmp, int n, int k, int start) {

        if(tmp.size() == k) {
            res.push_back(tmp);
            return;
        }

        for(int i = start; i <= n; i++) {
            tmp.push_back(i);
            rescurive(res, tmp, n, k, i+1);
            tmp.pop_back();

        }
    }
};

int main() {
    Solution s;
    vector<vector<int> > res = s.combine(4,2);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
        }
        cout << endl;
    }


    return 0;
}