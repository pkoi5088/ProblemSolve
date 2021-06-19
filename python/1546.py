N=input()
A=list(map(float,input().split()))
M=max(A)
for i in range(len(A)):
    A[i]= A[i]/M*100
print(sum(A)/len(A))