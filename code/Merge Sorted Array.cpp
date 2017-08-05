
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        for(int j = 0; j < n; j++) {
            while(nums2[j] >= nums1[i] && i < m)
                i++;
            for(int k = m; k > i; k--)
                nums1[k] = nums1[k-1];

            nums1[i] = nums2[j];
            m = m + 1;
        }
    }
};


int main() {
    Solution s;
    vector<int> nums1;
    vector<int> nums2;

    nums1.push_back(1);
    nums1.push_back(3);
    nums1.push_back(5);

    nums2.push_back(2);
    nums2.push_back(2);
    nums2.push_back(6);

    s.merge(nums1, 3, nums2, 3);
    for(int i = 0; i < 6; i++)
        cout << nums1[i] << endl;


    return 0;
}