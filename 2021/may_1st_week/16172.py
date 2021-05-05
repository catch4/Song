'''
Catch study 5/may/2week
강의실 배정
https://www.acmicpc.net/problem/16172

알파벳만 남기고 kmp
'''
import re
def getpi(k):
    j = 0
    pi = [0] * len(k)
    for i in range(1, len(k)):
        while j>0 and  k[i] != k[j]:
            j = pi[j-1]
        if pi[i] == pi[j]:
            j+=1
            pi[i] = j
    return pi

def kmp(s, k ):
    j = 0
    pi = getpi(k)
    for i in range(len(s)):
        while j > 0 and s[i] != k[j]:
            j = pi[j-1]
        if s[i] == k[j]:
            if j==len(k)-1:
                return 1
            else:
                j+=1
    return 0

S = input()
K = input()
S = re.sub('[0-9]','',S)

print(kmp(S,K))