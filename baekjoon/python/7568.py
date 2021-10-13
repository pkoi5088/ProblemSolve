N=int(input())
A=[]; B=[]
for _ in range(N):
    x, y = map(int,input().split())
    A.append((x,y))

for i in A:
    cnt=0
    for j in A:
        if i!=j and i[0]<j[0] and i[1]<j[1]:
            cnt+=1
    B.append(cnt+1)

for i in B:
    print(i)