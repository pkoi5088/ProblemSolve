from sys import stdin

T=int(stdin.readline())

while T:
    B=[]
    N,M=map(int,stdin.readline().split())
    cnt=0
    check=[0 for _ in range(N)]
    for _ in range(M):
        a,b=map(int,stdin.readline().split())
        B.append((a,b))
    B.sort(key=lambda x: (x[1],x[0]))

    for i in B:
        start=i[0]-1
        end=i[1]-1
        for idx in range(start,end+1):
            if check[idx]==0:
                check[idx]=1
                cnt+=1
                break
    print(cnt)
    T-=1