class Solution {
public:
    bool checkInclusion(string s1, string s2) {
          if (s1.length() > s2.length()) return false;

    std::vector<int> s1_count(26, 0);
    std::vector<int> s2_count(26, 0);

    // 1. Populate the frequency map for s1
    for (char c : s1) {
        s1_count[c - 'a']++;
    }

    int left = 0;
    // Right pointer aggressively explores
    for (int right = 0; right < s2.length(); right++) {
        // Add current character to current window
        s2_count[s2[right] - 'a']++;

        // FIXED-SIZE SHRINKING LOGIC:
        // If our window size is strictly larger than s1.length(), 
        // we must drop the leftmost character immediately.
        if (right - left + 1 > s1.length()) {
            s2_count[s2[left] - 'a']--;
            left++; // Slide tail forward by exactly 1 position
        }

        // CHECK CONDITION:
        // Check if our current fixed window matches the target s1 map
        if (s1_count == s2_count) {
            return true;
        }
    }

    return false;
}

int main() {
    std::string s1 = "ab";
    std::string s2 = "eidbaooo";
    
    // Output: 1 (True, because "ba" is a permutation of "ab")
    std::cout << checkInclusion(s1, s2) << "\n"; 
    return 0;
    }
};
