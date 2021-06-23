M=int(input())
N=int(input())
board=[1 for i in range(10001)]
board[1]=0
for i in range(1,10001):
    if board[i]==1:
        n=i*2
        while n<=10000:
            board[n]=0
            n+=i
C=[]
for i in range(M,N+1):
    if board[i]==1:
        C.append(i)

if len(C)==0:
    print(-1)
else:
    print(sum(C))
    print(C[0])