N=int(input())
B=list(input())
idx,flag=0,1
cnt=0
while idx<N:
    if B[idx]=='S':
        cnt+=1
        idx+=1
    else:
        cnt+=1+flag
        flag=0
        idx+=2
print(cnt) 