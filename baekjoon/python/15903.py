import heapq

n,m=map(int,input().split())
B=list(map(int,input().split()))
H=[]

for i in range(n):
    heapq.heappush(H,B[i])

for _ in range(m):
    a=heapq.heappop(H)
    b=heapq.heappop(H)
    heapq.heappush(H,a+b)
    heapq.heappush(H,a+b)

print(sum(H))