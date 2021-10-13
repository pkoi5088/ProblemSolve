N=input()
A=['H']
A+=list(input())
B=['H']
B+=(list(input()))
A.append('H'); B.append('H')

cnt=0
for i in range(1,len(A)-1):
    if A[i]!=B[i] and A[i-1]==B[i-1]:
        cnt+=1

print(cnt)