class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        seen={}
        for x in strs:
            x_new="".join(sorted(x))
            if x_new in seen:
                seen[x_new].append(x) 
            else:
                seen[x_new]=[x]
        return list(seen.values())