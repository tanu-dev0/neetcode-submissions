class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen={}
        for i,x in enumerate(nums):
            needed=target-x
            if needed in seen:
                return [seen[needed],i]
            else:
                seen[x]=i
            
           
            

                
         