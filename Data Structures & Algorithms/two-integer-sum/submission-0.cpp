class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n=nums.size();
       int i=0;
       
       while(i<n){
          int j=n-1;
          while(j>i){
            if(nums[i]+nums[j]==target) return {i,j};
            j--;
          }
          i++;
       } 
 return {};
    }
};
