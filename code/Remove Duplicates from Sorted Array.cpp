#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int length = 1;
        int end = 0;
        int cnt = nums[0];
        for(int i = 0; i < nums.size()-1; i++) {
            if(cnt < nums[i+1]) {
                length += 1;
                cnt = nums[i+1];
                int tmp = nums[end+1];
                nums[end+1] = cnt;
                nums[i+1] = tmp;
                end++;
            }
        }
        return length;    
    }
};

int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);
    a.push_back(3);
    a.push_back(5);

    Solution s;
    cout << s.removeDuplicates(a) << endl;


    return 0;
}