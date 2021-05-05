'''
Catch study 5/may/2week
강의실 배정
https://www.acmicpc.net/problem/1194

현재 가진 열쇠 비트마스크로 체크
'''

import re
import copy
def find_start(mp):
    for i,line in enumerate(mp):
        idx = line.find('0')
        if idx != -1:
            return i,idx

def bfs(h,w,mp):
    dx,dy = [0,1,0,-1], [1,0,-1,0]
    Q = [{'pos': find_start(mp), 'cnt':0,'key': 0}]
    ck = [[[2147000000 for _ in range(1<<6)]for _ in range(w)] for _ in range(h)]
    while len(Q):
        now = Q[0]
        Q.pop(0)
        y, x = now['pos']
        for z in range(4):
            ny, nx = y+dy[z], x+dx[z]
            n_key = now['key']
            if ny<0 or nx<0 or ny>= h or nx>=w or ck[ny][nx][n_key] <= now['cnt']+1 or mp[ny][nx]=='#' : continue
            
            if mp[ny][nx]=='1':
                return now['cnt']+1
            elif mp[ny][nx]>='a' and mp[ny][nx] <= 'z':
                n_key = (1<<(ord(mp[ny][nx])-ord('a' ))) | n_key
            elif mp[ny][nx] >='A' and mp[ny][nx] <='Z' and (1<<(ord(mp[ny][nx])-ord('A'))) & n_key ==0:
                    continue
            ck[ny][nx][n_key] = now['cnt'] +1
            Q.append({'pos': [ny,nx],'cnt':now['cnt']+1,'key': n_key})

    return -1


h,w = list(map(int, input().split()))
mp = [input() for _ in range(h)]

print(bfs(h,w,mp))
