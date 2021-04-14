'''
Catch study 14/apr/2week
백준_A와 B
https://www.acmicpc.net/problem/12904

풀이
뒤에서 부터 없애면서 입력값과 같아질 수 있는 지 확인
B인 경우는 없애고 뒤집기.
'''
S = input()
T = input()

while len(S) != len(T):
    if T[-1]=='A':
        T = T[:-1]
    else:
        T = T[:-1][::-1]
print(1 if S==T else 0)