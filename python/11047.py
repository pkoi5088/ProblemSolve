N,K=map(int,input().split())
C=[int(input()) for _ in range(N)]
idx=N-1
cnt=0
while idx>=0:
    number=K//C[idx]
    K-=number*C[idx]
    cnt+=number
    if K==0:
        break
    idx-=1
print(cnt)