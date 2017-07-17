
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        vector<vector<int> cy = matrix;
        for(int i = 0; i < cy; i++) 
    }   
};

int main() {
    Solution s;
    vector<vector<int> > matrix;

    vector<int> r1;
    r1.push_back(3);
 
    vector<int> r2;
    r2.push_back(2);

    vector<int> r3;
    r3.push_back(7);
    r3.push_back(8);
    r3.push_back(9);
  
    matrix.push_back(r1);
    matrix.push_back(r2);
    vector<int> res = s.spiralOrder(matrix);
    for(int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";
    cout << endl;

    return 0;
}