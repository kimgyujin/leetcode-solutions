class Solution:
    def numSteps(self, s: str) -> int:
        num = 0
        n = len(s)
        add = 1
        for i in range(n):
            if s[n-1-i]=='1':
                num += add
            add*=2
        res = 0
        while num > 1:
            res+=1
            if num%2==1:
                num+=1
            else:
                num//=2
        return res
        
