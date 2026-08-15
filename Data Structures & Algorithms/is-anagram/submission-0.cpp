class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> smap;
         unordered_map<char,int> tmap;
         for(auto x: s){
            smap[x]++;
         }
         for(auto x: t){
            tmap[x]++;
         }
        if (smap==tmap){
            return true;
        } else return false;
    }
};
