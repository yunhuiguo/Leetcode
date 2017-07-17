#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        if(obstacleGrid[0][0] != 1)
            dp[0][0] = 1;
        else
            dp[0][0] = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(i == 0 && j >= 1 && obstacleGrid[i][j] != 1 ) {
                    dp[i][j] = dp[i][j-1]; 
                } else if(i >= 1 && j == 0 && obstacleGrid[i][j] != 1) {
                    dp[i][j] = dp[i-1][j];
                } else if(i >= 1 && j >= 1 && obstacleGrid[i][j] != 1) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else if(i != 0 || j != 0)
                    dp[i][j] = 0;
            } 
        }
     

        return dp[m-1][n-1];
    }
};


int main() {
    Solution s;
    vector<vector<int> > obstacleGrid;

    vector<int> r1;
    r1.push_back(0);
    r1.push_back(0);
 

    
    vector<int> r2;
    r2.push_back(1);
    r2.push_back(0);

    /*
    vector<int> r3;
    r3.push_back(0);
    r3.push_back(0);
    r3.push_back(0);
    */

    obstacleGrid.push_back(r1);
    obstacleGrid.push_back(r2);
   

    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}