class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size());
        int product=1;

        //for left sid e
        for(int i=0;i<nums.size();i++){
            ans[i]=product;//first write product in ans then update it later so that when we move to next elemnt , ans me hum direct product likh de jo update hua tha last iteration me , then next line me fir product update .
          product=nums[i]*product;//here. 
        }

product=1;
for(int i=nums.size()-1;i>=0;i--){
    //ans array me abhi hai {1,1,2,8}, yaani left side ka sum
    ans[i]=ans[i]*product;//ans[i]=8*product=1=8;
    //4*6=24
    product=product*nums[i];//1*6=6

}
return ans;
    }
};
