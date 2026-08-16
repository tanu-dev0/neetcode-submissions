class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string> > mp;
       for(auto x: strs){
        string copy=x;
        sort(copy.begin(),copy.end());
        mp[copy].push_back(x);
       }
         

        vector<vector<string>> ans;
       for(auto it : mp){
       ans.push_back(it.second);
       }
        return ans; 
    }
};
