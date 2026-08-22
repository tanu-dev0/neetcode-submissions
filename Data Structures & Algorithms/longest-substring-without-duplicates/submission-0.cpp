class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int cnt=0;
        int left=0;

        for (int right = 0; right < s.length(); right++) {
             while (st.contains(s[right])) { 
            st.erase(s[left]);
            left++;
        }
         st.insert(s[right]);
          cnt = max(cnt, right - left + 1);
        }
        return cnt;
    }
};
