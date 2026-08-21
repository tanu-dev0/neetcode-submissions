class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        // Step 1: Sort the array to use the two-pointer technique
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            // Step 2: Skip duplicate elements for the first position
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    // Step 3: Correctly insert the triplet vector into the answer vector
                    ans.push_back({nums[i], nums[left], nums[right]});
                    
                    // Step 4: Skip duplicate elements for left and right pointers
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    // Move both pointers inward
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++; // Sum is too small, move left pointer rightward
                } 
                else {
                    right--; // Sum is too large, move right pointer leftward
                }
            }
        }
        return ans;
    }
};

