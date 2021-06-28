N=int(input())
while N:
    A=list(map(int,input().split(',')))
    print(sum(A))
    N-=1