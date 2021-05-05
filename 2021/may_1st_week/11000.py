'''
Catch study 5/may/2week
강의실 배정
https://www.acmicpc.net/problem/11000

끝나는 시간 빠른 것 부터 계산
'''

import heapq

n = int(input())
c = [list(map(int,input().split())) for _ in range(n)]
c.sort(key=lambda x: x[0])
heap = []
for s,t in c:
    if not len(heap):
        heapq.heappush(heap,t)
    else:
        if heap[0] <= s:
            heapq.heappop(heap)
            heapq.heappush(heap,t)
        else:
            heapq.heappush(heap,t)

print(len(heap))