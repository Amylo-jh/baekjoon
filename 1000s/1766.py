from collections import deque
from queue import PriorityQueue

n, m = map(int, input().split())

arr = [[] for i in range (n+1)]
indegree = [0 for i in range (n+1)]

for i in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)
    indegree[b] += 1

pq = PriorityQueue()
for i in range(1, n+1):
    if indegree[i] == 0:
        pq.put(i);

while not pq.empty():
    top = pq.get()
    print(top, end=" ")

    for i in range(len(arr[top])):
        indegree[arr[top][i]] -= 1
        if indegree[arr[top][i]] == 0:
            pq.put(arr[top][i])