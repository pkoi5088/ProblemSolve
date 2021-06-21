from sys import stdin
import heapq

N=int(stdin.readline())
H=[]

for i in range(N):
    heapq.heappush(H,int(stdin.readline()))

if N==1:
    print(0)
else:
    result=0
    while len(H)!=1:
        a=heapq.heappop(H)
        b=heapq.heappop(H)
        result+=a+b
        heapq.heappush(H,a+b)

    print(result)