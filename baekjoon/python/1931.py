N=int(input())
C=[]
for _ in range(N):
    s,e=map(int,input().split())
    C.append((s,e))
conference=sorted(C,key=lambda x:(x[1],x[0]))

idx=1
cnt=1
endTime=conference[0][1]
while idx<N:
    if conference[idx][0]>=endTime:
        endTime=conference[idx][1]
        cnt+=1
    idx+=1
print(cnt)