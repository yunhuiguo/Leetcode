#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;
        if(matrix.size() == 0)
            return res;
        int m = matrix.size()-1;
        int n = matrix[0].size()-1;

        spiral(matrix, res, 0, 0, m, n);
        return res;
    }

    void spiral(vector<vector<int> >& matrix, vector<int>& res, int row, int col, int m, int n) {
        if(row <= m && col <= n) {
            for(int j = col; j <= n; j++)
                res.push_back(matrix[row][j]);
            for(int i = row+1; i <= m; i++)
                res.push_back(matrix[i][n]);
            if(row + 1 <= m) 
                for(int j = n-1; j >= col; j--)
                    res.push_back(matrix[m][j]);
            if(col <= n-1)
                for(int i = m-1; i >= row+1; i--)
                    res.push_back(matrix[i][col]);
            spiral(matrix, res, row+1, col+1, m-1, n-1);

        } else
            return;
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