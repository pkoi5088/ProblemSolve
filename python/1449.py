N,L=map(int,input().split())
location=list(map(int,input().split()))
location.sort()

idx=0
cnt=0
while idx<N:
    cnt+=1
    end=location[idx]+L-1
    while idx<N and location[idx]<=end:
        idx+=1
print(cnt)