import math
class Solution:
    def missingRolls(self, rolls: list[int], mean: int, n: int) -> list[int]:
        lenght = len(rolls) + n
        sum_of_rolls = 0
        for i in rolls:
            sum_of_rolls += i
        missing_rolls_of_sum = mean*lenght - sum_of_rolls
        if missing_rolls_of_sum>n*6 or missing_rolls_of_sum<0:
            return []
        else :
            if math.floor(missing_rolls_of_sum/n) == 0:
                return []
            missing_rolls = [math.floor(missing_rolls_of_sum/n) for _ in range(n)]
            temp_rolls_count = math.floor(missing_rolls_of_sum/n)*n
            for i in range(missing_rolls_of_sum - temp_rolls_count):
                missing_rolls[i] += 1
            return missing_rolls