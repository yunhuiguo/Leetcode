#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        recursive(res, n, 0, "");

        return res;
    }

    void recursive(vector<string>& res, int left_cnt, int right_cnt, string tmp) {
        if(left_cnt == 0 && right_cnt == 0) {
            res.push_back(tmp);
            return;
        }

        if(left_cnt > 0) 
            recursive(res, left_cnt-1, right_cnt+1, tmp+'(');

        if(right_cnt > 0)
            recursive(res, left_cnt, right_cnt-1, tmp+')');
    }
};


int main() {
    Solution s;
    vector<string> res = s.generateParenthesis(3);

    for(int i = 0; i < res.size(); i++) {
        cout << res[i];
        cout << endl;

    }
    cout << endl;
    return 0;

}