import math
class Solution:
    def missingRolls(self, rolls: list[int], mean: int, n: int) -> list[int]:
        lenght = len(rolls) + n
        sum_of_rolls = sum(rolls,0)
        missing_rolls_of_sum = mean*lenght - sum_of_rolls
        if missing_rolls_of_sum>n*6 or missing_rolls_of_sum<0:
            return []
        else :
            if math.floor(missing_rolls_of_sum/n) == 0:
                return []
            base_value = math.floor(missing_rolls_of_sum/n)
            temp_rolls_count = math.floor(missing_rolls_of_sum/n)*n
            left_missing_rolls_of_value = missing_rolls_of_sum - temp_rolls_count
            return [base_value+1 if i<left_missing_rolls_of_value else base_value for i in range(n)]
