class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";

        // Store: length + '#' + actual string
        for (auto x : strs) {
            ans += to_string(x.size()) + "#" + x;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while (i < s.size()) {

            // 1. Read the length until '#'
            int len = 0;

            while (s[i] != '#') {
                len = len * 10 + (s[i] - '0');
                i++;
            }

            // 2. Skip '#'
            i++;

            // 3. Take exactly 'len' characters
            string str = s.substr(i, len);

            ans.push_back(str);

            // 4. Move i to the beginning of next encoded string
            i += len;
        }

        return ans;
    }
};
