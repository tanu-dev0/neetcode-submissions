class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        seen = {}
        ans=[]
        for x in nums:
            if x in seen:
                seen[x]+=1
            else:
                seen[x]=1

        sorted_seen=sorted(seen.items(), key= lambda x:x[1], reverse=True) 
        for x in sorted_seen:
            ans.append(x[0])
            if len(ans)==k:
                return ans
            
         
        