from collections import deque
N, K = list(map(int, input().split()))

def bfs(start):
    visited = [0 for _ in range(100001)]
    
    deq = deque()
    deq.append((start, 0))
    while len(deq)!=0:
        current, second = deq.popleft()
        if(current == K):
            print(second)
            return

        if(0<=current and current<=100000 and visited[current]==0):
                visited[current] = 1
                deq.append((current-1, second+1))
                deq.append((current+1, second+1))
                deq.append((current*2, second+1))

bfs(N)
