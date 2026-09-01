class Solution {
public:
int solve(vector<int>& nums, int idx, int n, vector<int>& dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        int take=solve(nums, idx+2,n,dp)+ nums[idx];
        int not_take=solve(nums,idx+1,n,dp);
         dp[idx]=max(take,not_take);
         return dp[idx];
}


    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums, 0,n,dp);
    }
};
