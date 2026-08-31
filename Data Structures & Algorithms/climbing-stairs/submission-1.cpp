class Solution {
public:
  vector<int> dp;
    int f(int idx) {
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int left = f(idx - 1);
        int right = f(idx - 2);
    
        return dp[idx] = left + right;
    }

    int climbStairs(int n) {
      dp.resize(n + 1, -1);
        dp[0]=1;
        dp[1]=1;
        
        return f(n);
    }
};