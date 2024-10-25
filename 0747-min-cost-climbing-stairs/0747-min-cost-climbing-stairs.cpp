class Solution {
public:
        // int solve(vector<int> &cost , int n){
        //     if(n == 0){
        //         return cost[0];
        //     }
        //     if(n == 1){
        //         return cost[1];

        //     }   
        //     int ans =cost[n] + min(solve(cost, n-1), solve(cost, n-2));
        //     return ans;    
            
        //     }
        // step2
        int solve2(vector<int> &cost , int n, vector<int> & dp){
            if(n == 0){
                return cost[0];
            }
            if(n == 1){
                return cost[1];

            }  

            // step3 after base case
            if(dp[n] != -1){
                return dp[n];
            }

            // step2 

            dp[n] =cost[n] + min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
            return dp[n];    
            
            }

        int minCostClimbingStairs(vector <int> &cost){
            // using recursion
            // int n = cost.size();
            // int ans = min(solve(cost, n-1), solve(cost, n-2));
            // return ans;


            // using dp 
            int n = cost.size();
            // step1
            // to make memosiation make dp array initialize with -1//
            vector<int> dp(n+1, -1);
            int ans = min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
            return ans;
        }
};