A=list(map(int,input().split()))
K=A[0]-1; N=A[1]

board=[]
A=list(map(int,input().split()))
for i in range(0,N-1):
    for j in range(i+1,N):
        board.append([A[i],A[j]])

while K:
    A=list(map(int,input().split()))
    remove = []
    for i in board:
        first = i[0]
        second = i[1]
        if A.index(first) > A.index(second):
            remove.append(i)

    for i in remove:
        board.remove(i)
    K-=1

print(len(board))
