import sys
input = sys.stdin.readline
from collections import deque

m, n, h = map(int, input().split())
arr = [[list(map(int, input().split())) for _ in range(n)] for _ in range(h)]

bfs_queue = deque()
for i in range(h):
    for j in range(n):
        for k in range(m):
            if arr[i][j][k] == 1:
                bfs_queue.append((i, j, k, 0))

max_day = 0
while bfs_queue:
    i, j, k, day = bfs_queue.popleft()
    max_day = max(max_day, day)
    for di, dj, dk in [[1, 0, 0], [-1, 0, 0], [0, 1, 0], [0, -1, 0], [0, 0, 1], [0, 0, -1]]:
        ni, nj, nk = i + di, j + dj, k + dk
        if 0 <= ni < h and 0 <= nj < n and 0 <= nk < m:
            if arr[ni][nj][nk] == 0:
                arr[ni][nj][nk] = 1
                bfs_queue.append((ni, nj, nk, day+1))

flag = True
for i in range(h):
    for j in range(n):
        for k in range(m):
            if arr[i][j][k] == 0:
                flag = False

if flag == False:
    print(-1)
else:
    print(max_day)
