from sys import stdin

T=int(stdin.readline())
while T:
    N=int(stdin.readline())
    rank=[]
    for _ in range(N):
        a,b=map(int,stdin.readline().split())
        rank.append((a,b))
    rank.sort(key=lambda x:(x[0],x[1]))

    standard=rank[0][1]
    cnt=1
    for idx in range(1,len(rank)):
        idxRank=rank[idx][1]
        if idxRank<standard:
            cnt+=1
            standard=idxRank

    print(cnt)
    T-=1