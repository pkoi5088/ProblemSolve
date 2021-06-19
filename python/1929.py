M, N=map(int,input().split())
board=[1 for i in range(1000001)]
board[1]=0
for i in range(1,1000001):
    if board[i]==1:
        n=i*2
        while n<=1000000:
            board[n]=0
            n+=i
for i in range(M,N+1):
    if board[i]==1:
        print(i)