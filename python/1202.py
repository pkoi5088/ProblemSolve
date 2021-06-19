from sys import stdin
import heapq

N,K=map(int,stdin.readline().split())
J=[]
B=[]
for _ in range(N):
    m,v=map(int,stdin.readline().split())
    J.append((m,v))
for _ in range(K):
    c=int(stdin.readline())
    B.append(c)

J.sort(key=lambda x:(x[0],-x[1]))
B.sort()

idx=0
result=0
h=[]
for bag in B:
    while idx<N and J[idx][0]<=bag:
        heapq.heappush(h,-J[idx][1])
        idx+=1
    if len(h)>0:
        best=heapq.heappop(h)
        result+=-best

print(result)