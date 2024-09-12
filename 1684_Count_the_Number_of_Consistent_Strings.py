class Solution:
    def countConsistentStrings(self, allowed: str, words: list[str]) -> int:
        allowed_set = set(allowed)
        count = 0
        for i in words:
            if set(i).issubset(allowed_set):
                count += 1
        return count