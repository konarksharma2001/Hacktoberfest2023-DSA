#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: Recursion + memoization
    // T.C. -> O(M * N)
    // S.C. -> O(M * N) [2 D dp matrix] + O((n-1) + (m-1)) [ Path length of recursion tree]
    //     int f(int i,int j,vector<vector<int>> &dp){

    //         // Base Case
    //         if(i == 0 && j == 0) return 1;
    //         if(i < 0 || j < 0) return 0;
    //         if(dp[i][j] != -1) return dp[i][j]; // Step 3

    //         int up = f(i-1,j,dp);
    //         int left = f(i,j-1,dp);

    //         return dp[i][j] = up + left; // Step 2
    //     }

    //     int uniquePaths(int m, int n) {
    //         if(m == 1 && n == 1) return 1;
    //         vector<vector<int>> dp(m,vector<int>(n,-1)); // Step 1
    //         f(m-1,n-1,dp);
    //         return dp[m-1][n-1];
    //     }

    // Approach 2: Tabulation [Bottom up]
    // T.C. -> O(M * N)
    // S.C. -> O(M * N) [2 D dp matrix]
    // int uniquePaths(int m, int n) {

    //      vector<vector<int>> dp(m,vector<int>(n,-1));
    //      for(int i=0;i<m;i++){
    //          for(int j=0;j<n;j++){
    //              if(i == 0 && j == 0) dp[0][0] = 1;
    //              else{
    //                  int up = 0, left = 0;
    //                  if(i > 0) up = dp[i-1][j];
    //                  if(j > 0) left = dp[i][j-1];
    //                  dp[i][j] = up + left;
    //              }
    //          }
    //      }
    //      return dp[m-1][n-1];
    // }

    // Approach 3: Space Optimization
    // T.C. -> O(M * N)
    // S.C. -> O(N)
    int uniquePaths(int m, int n)
    {

        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    curr[j] = 1;
                else
                {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = prev[j];
                    if (j > 0)
                        left = curr[j - 1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};

int main()
{

    int m = 3;
    int n = 7;

    Solution obj;
    int ans = obj.uniquePaths(m, n);
    cout << "\n\nThe Number of Grid Unique Paths are: " << ans << endl;

    return 0;
}