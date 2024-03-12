import sys
import heapq

def find(key):

    queue = []
    heapq.heappush(queue, [0, key])
    result[key] = 0


    while queue:

        queue_distance, now_key = heapq.heappop(queue)

        if result[now_key] < queue_distance:
            continue
       
        for i in l[now_key]:
            
            distance = i[1] + queue_distance

            next_key = i[0]

            
            if result[next_key] > distance:

                result[next_key] = distance
                heapq.heappush(queue, [distance, next_key])

V, e = map(int, sys.stdin.readline().strip().split())

k = int(sys.stdin.readline().strip())

l = [[] for i in range(V+1)]

result = [30000001 for i in range(V+1)]

for i in range(e):
    u, v, w = map(int, sys.stdin.readline().strip().split())
    l[u].append([v,w])

find(k)

for i in result[1:]:
    if i == 30000001:
        print("INF")
    else:
        print(i)