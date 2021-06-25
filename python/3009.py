A=list(map(int,input().split()))
B=list(map(int,input().split()))
C=list(map(int,input().split()))
X, Y = 0, 0
if A[0]==B[0]:
    X=C[0]
elif A[0]==C[0]:
    X=B[0]
else:
    X=A[0]

if A[1]==B[1]:
    Y=C[1]
elif A[1]==C[1]:
    Y=B[1]
else:
    Y=A[1]

print(X,end=' ')
print(Y)