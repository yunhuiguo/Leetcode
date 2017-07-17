#include <iostream>
using namespace std;

class Solution {
public:
    int min(int a, int b) {
        return a < b ? a : b; 
    }

    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = 0;

        dp[0][0] = grid[0][0];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j >= 1) {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                } else if(j == 0 && i >= 1)
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                else if (i >= 1 && j >= 1) {
                    dp[i][j] = min(dp[i][j-1]+ grid[i][j], dp[i-1][j]+grid[i][j]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution s;
    



    return 0;
}