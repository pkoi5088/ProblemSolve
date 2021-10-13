N=int(input())
weight=list(map(int,input().split()))
weight.sort()
K=weight[0]+1
if K>2:
    print(1)
else:
    for i in range(1,N):
        if weight[i]>K:
            break
        K+=weight[i]
    print(K)