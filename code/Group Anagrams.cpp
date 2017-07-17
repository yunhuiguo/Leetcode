#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> st;
        vector<vector<string> > res;
        int start = 0;

        for(int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if(st.find(tmp) != st.end()) {
                res[st[tmp]].push_back(strs[i]);
            } else {
                st[tmp] = start;
                start++;
                vector<string> tv;
                tv.push_back(strs[i]);
                res.push_back(tv);
            }
        }

        return res;
    }
};

int main() {
    vector<string> ss;
    ss.push_back("eat");
    ss.push_back("tea");
    ss.push_back("tan");
    ss.push_back("ate");
    ss.push_back("nat");
    ss.push_back("bat");
    Solution s;
    vector<vector<string> > res = s.groupAnagrams(ss);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j];
        cout << endl;
    }
    return 0;
}