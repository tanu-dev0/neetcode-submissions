class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>counts(26,0);
         int left = 0;
    int max_freq = 0; // Tracks the highest frequency of any single character seen so far
    int max_len = 0;  // Stores final answer

    for (int right = 0; right < s.length(); right++) {
        // 1. Add current character to our window frequency map
        counts[s[right] - 'A']++;
        
        // 2. Update the maximum frequency found in the current window
        max_freq = std::max(max_freq, counts[s[right] - 'A']);

        // 3. Check if we need more than 'k' replacements to make the window uniform
        int current_window_size = right - left + 1;
        if (current_window_size - max_freq > k) {
            // Window is invalid! Shrink it from the left
            counts[s[left] - 'A']--;
            left++;
        }

        // 4. Update the maximum valid window length found
        max_len = std::max(max_len, right - left + 1);
    }

    return max_len;
    }
};
