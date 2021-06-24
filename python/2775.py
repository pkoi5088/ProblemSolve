T = int(input())
while T:
    K = int(input())
    N = int(input())
    board = [i for i in range(1,N+1)]
    for _ in range(K):
        for i in range(1,N):
            board[i] += board[i-1]
    print(board[-1])
    T-=1