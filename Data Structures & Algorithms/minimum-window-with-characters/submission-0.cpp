class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";

    // 1. Map to store the count of characters needed from 't'
    std::unordered_map<char, int> countT;
    for (char c : t) countT[c]++;

    std::unordered_map<char, int> window;
    int have = 0, need = countT.size();
    
    // Track the best window properties
    int min_len = INT_MAX;
    int min_left = 0; 
    int left = 0;

    // Right pointer aggressively explores
    for (int right = 0; right < s.length(); right++) {
        char c = s[right];
        window[c]++;

        // If this character is needed and we reached its required count
        if (countT.count(c) && window[c] == countT[c]) {
            have++;
        }

        // SHRINKING TIME: While our window contains all characters of 't'
        while (have == need) {
            // Update our minimum window record
            if ((right - left + 1) < min_len) {
                min_len = right - left + 1;
                min_left = left;
            }

            // Pop the character at 'left' out of the window
            window[s[left]]--;
            
            // If dropping this character breaks our validity condition
            if (countT.count(s[left]) && window[s[left]] < countT[s[left]]) {
                have--;
            }
            
            // Tail pulls forward (always shrinking from the left!)
            left++;
        }
    }

    return (min_len == INT_MAX) ? "" : s.substr(min_left, min_len);
    }
};
