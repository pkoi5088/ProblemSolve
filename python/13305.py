N=int(input())
D=list(map(int,input().split()))
P=list(map(int,input().split()))

#현재 위치
idx,result=0,0
while idx<N-1:
    ndx=idx+1
    move=D[idx]
    while P[idx]<=P[ndx] and ndx!=N-1:
        move+=D[ndx]
        ndx+=1
    result+=move*P[idx]
    idx=ndx
print(result)