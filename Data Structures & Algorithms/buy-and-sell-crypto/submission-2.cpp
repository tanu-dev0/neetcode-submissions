class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        if(n==1 || n==0) return 0;
         int ans = 0;
        for(int mid = 0; mid < n - 1; mid++) {
             int leftmin = prices[0];
        int i=1;
        while(i<=mid){
            if(prices[i]<leftmin){
            leftmin=prices[i];
            }
            i++;
        }

           int rightmax = prices[mid + 1];  
            



        i=mid+2;
        while(i<n){
            if(rightmax<prices[i]){
                rightmax=prices[i];
            }
            i++;
        }

        if(rightmax>leftmin){
            ans= max(ans,rightmax-leftmin);
               } 
        
    }
    return ans;
    }
};
