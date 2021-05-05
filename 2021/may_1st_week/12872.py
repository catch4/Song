'''
Catch study 5/may/2week
플레이리스트 
https://www.acmicpc.net/problem/12872

fail
'''

n,m,p = list(map(int,input().split()))
MAX = 1000000007

def nCr(n, r):
    ncr = [[0 for _ in range(r+1)] for _ in range(n+1)]

    for i in range(n+1):
        ncr[i][0] = 1
    for i in range(r+1):
        ncr[i][i] = 1

    for i in range(1, n+1):
        for j in range(1, r+1):
            ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1]

    return ncr[n][r]

def make_answer(n,m,p,MAX):
    if n<=m and n<p:
        return 0
    else:
        
        answer = 1
        cnts = [0] *p
        for i in range(p):
            if i<=m:
                cnts[i]= n-i
            else:
                cnts[i] = n-m
            answer = (answer*cnts[i])%MAX
        return answer

answer = 0 
pre = 0
for r in range(1,n+1):
    answer = make_answer(r,m,p,MAX) * nCr(n,r) - pre
    if answer <0:
        answer += MAX
    pre = answer
print(answer)