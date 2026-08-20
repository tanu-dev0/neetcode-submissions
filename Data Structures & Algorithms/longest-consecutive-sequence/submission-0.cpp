class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for (auto x : nums) {

            // Agar x-1 present hai, toh x sequence ka starting point nahi hai
            if (st.count(x - 1))
                continue;

            // x se sequence start ho rahi hai
            int current = x;
            int cnt = 1;

            // Check karo x+1, x+2, x+3... present hain ya nahi
            while (st.count(current + 1)) {
                current++;
                cnt++;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};
