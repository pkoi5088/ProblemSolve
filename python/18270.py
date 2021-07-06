import itertools

def function(board,beside):
    for i in beside:
        front=i[0]; back=i[1]
        location=board.index(back)
        if location==0 and board[1]!=front:
            return False
        elif location==7 and board[6]!=front:
            return False
        elif board[location-1]!=front and board[location+1]!=front:
            return False
    return True

order=['Beatrice', 'Belinda', 'Bella', 'Bessie', 'Betsy', 'Blue', 'Buttercup', 'Sue']
N=int(input())
board=list(itertools.permutations(order))
beside=[]
while N:
    A=list(input().split())
    beside.append([A[0],A[5]])
    N-=1
flag = False
for i in board:
    if function(list(i),beside):
        for j in list(i):
            print(j)
            flag=True
    if flag:
        break