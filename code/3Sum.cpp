#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            if(i >= 1 && nums[i] == nums[i-1]) {
            } else {
                for(int j = i+1; j < nums.size(); j++) {
                    if(j >= i+2 && nums[j] == nums[j-1]) {}
                        else {
                            int index = binary_search(nums, j+1, nums.size()-1, -(nums[i]+nums[j]));
                            if(index != -1) {
                                vector<int> r;
                                r.push_back(nums[i]);
                                r.push_back(nums[j]);
                                r.push_back(nums[index]);
                                res.push_back(r);
                            }        
                        }   
                }
            }
        }
        return res;
    }

    int binary_search(vector<int> nums, int start, int end, int x) {
        while(start <= end) {
            int mid = start + (end-start)/2;
            if (nums[mid] == x) 
                return mid;
            else if(nums[mid] > x) 
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }

};
*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
                
                if(i >= 1)
                    while(nums[i] == nums[i-1])
                        i++;

                int start = i+1;
                int end = nums.size()-1;


                while(end > start) {
                    if(nums[end]+nums[start] == -nums[i]) {
                        vector<int> r;
                        r.push_back(nums[i]);
                        r.push_back(nums[start]);
                        r.push_back(nums[end]);
                        res.push_back(r);
                        end--;
                        start++;
                        while(nums[end] == nums[end+1])
                        end--;
                        while(nums[start] == nums[start-1])
                        start++;

                    } else if(nums[end]+nums[start] > -nums[i]) {
                        end--;
                    } else {
                        start++;
                    }
                }

        }
        return res;
    }
};


 
int main() {
    vector<int> a;
    a.push_back(-1);
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    a.push_back(-1);
    a.push_back(-4);

    Solution s;
    vector<vector<int> > res = s.threeSum(a);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
        }
        cout << endl;
    }


    return 0;
}