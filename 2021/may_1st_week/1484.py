'''
Catch study 5/may/2week
강의실 배정
https://www.acmicpc.net/problem/1484

투 포인터 사용
'''
G = int(input())
n1,n2 = 1, 2
is_printed = False
while True:
    now = n2 **2 - n1**2
    if now == G:
        print(n2)
        is_printed=True    
    if now>G:
        if n2 == n1+1: break
        else: n1+=1
    else: n2 +=1

if not is_printed:
    print(-1)