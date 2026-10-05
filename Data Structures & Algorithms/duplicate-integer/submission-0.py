class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        frequency = {}

        for x in nums:
            if x in frequency:
                frequency[x]+=1
            else:
                frequency[x]=1

        for value in frequency.values():
            if value>1:
                return True

        return False

