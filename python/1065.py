def function(i):
    A=list(str(i))
    if len(A)==1:
        return True
    tmp=int(A[1])-int(A[0])
    for i in range(1,len(A)-1):
        if int(A[i+1])-int(A[i])!=tmp:
            return False
    return True

N=int(input())
cnt=0
for i in range(1,N+1):
    if function(i):
        cnt+=1
print(cnt)