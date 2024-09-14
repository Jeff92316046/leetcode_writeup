class Solution:
    def longestSubarray(self, nums: list[int]) -> int:
        index_temp = []
        max_n = max(nums)
        for i in range(len(nums)):
            if(nums[i] == max_n):
                index_temp.append(i)
        print(index_temp)
        max_contiguous_count = 0
        count_temp = 0 
        pre_num_temp = 0
        for i in index_temp:
            if pre_num_temp+1 == i:
                count_temp += 1
            else:
                count_temp = 1
            if max_contiguous_count < count_temp:
                max_contiguous_count = count_temp
            pre_num_temp = i
        
        return max_contiguous_count