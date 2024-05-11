# 괄호가 쳐져있는 식의 형태 
# (왼쪽 피연산자, 연산자, 오른쪽 피연산자)
def calc(L,R,op):
    if op == '+':
        # [1,2,3], [4,5] = [1+4, 2+4, 3+4, 1+5, 2+5, 3+5]
        return [l + r for l in L for r in R]
    elif op == '-':
        return [l - r for l in L for r in R]
    else:
        return [l * r for l in L for r in R]

def dfs(exp):
    ## 1. 숫자만 있는 경우
    ## 2. 연산자랑 같이 있는 경우

    # 1. 숫자만 있는 경우 처리
    if exp.isdigit():
        return [int(exp)]
    
    # 2. 연산자 있는 경우 처리

    # A = [1,2,3]
    # B = [4,5,6]
    # A.extend(B) -> [1,2,3,4,5,6]
    n = len(exp)
    res = []
    for i in range(n):
        if exp[i] == '+' or exp[i] == '-' or exp[i] == '*': # 현재 보고 있는 게 연산자인 경우
            L = dfs(exp[0:i])
            R = dfs(exp[i+1:])
            res.extend(calc(L,R,exp[i]))
    return res
class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        return dfs(expression)        
