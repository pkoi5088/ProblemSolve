N,K=map(int,input().split())
if K*(K+1)//2>N:
    print(-1)
else:
    rest=N-K*(K+1)//2
    if rest%K==0:
        print(K-1)
    else:
        print(K)