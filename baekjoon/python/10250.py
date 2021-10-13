T=int(input())
while T:
    H, W, N=map(int,input().split())
    X=N%H #층
    Y=N//H+1 #호
    if X==0:
        X=H
        Y-=1
    print(X*100+Y)
    T-=1