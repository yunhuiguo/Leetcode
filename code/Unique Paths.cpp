#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];

        for(int i = 0; i <= m; i++) {
            dp[i][0] = 1;
            dp[i][1] = 1;
        }
 
        for(int j = 0; j <= n; j++) {
            dp[0][j] = 1;
            dp[1][j] = 1;
        }


        for(int i = 2; i <= m; i++) 
            for(int j = 2; j <= n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
           

        return dp[m][n];
    }

};

int main() {
    Solution s;
    cout << s.uniquePaths(3, 3) << endl;

    return 0;
}