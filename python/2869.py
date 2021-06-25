import math
A=list(map(int,input().split()))
B=A[1]; V=A[2]; A=A[0]
K = (V-B)/(A-B)
print(math.ceil(K))