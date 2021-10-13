from math import gcd
T = int(input())
while T:
    A = list(map(int,input().split()))
    print(A[0]*A[1]//gcd(A[0],A[1]))
    T -= 1

