import sys
input=sys.stdin.readline
T=int(input())
while T:
    A=list(map(int,input().split()))
    print(sum(A))
    T-=1