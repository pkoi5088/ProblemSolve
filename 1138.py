N=int(input())
H=list(map(int,input().split()))
R=[-1 for _ in range(N)]
for i in range(len(H)):
    idx=0
    cnt=0
    while cnt<H[i]:
        if R[idx]==-1:
            cnt+=1
        idx+=1
    while R[idx]!=-1:
        idx+=1
    R[idx]=i+1
for i in R:
    print(i,end=' ')