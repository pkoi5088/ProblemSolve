N=int(input())
weight=[int(input()) for _ in range(N)]
weight.sort(reverse=True)

idx=0
M=-1
while idx<N:
    M=max(M,weight[idx]*(idx+1))
    idx+=1
print(M)