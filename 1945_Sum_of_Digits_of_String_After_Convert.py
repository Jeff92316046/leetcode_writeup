class Solution:
    def getInt(self,char):
        return ord(char)-96
    def getAllInt(self,char):
        temp = ''
        for i in char:
            temp += str(self.getInt(i))
        return temp
    def fun1(self,string):
        temp = 0
        for i in string:
            temp += int(i)
        return temp

    def getLucky(self, s: str, k: int) -> int:
        temp = self.getAllInt(s)
        for _ in range(k):
            temp = self.fun1(str(temp))
        return temp
