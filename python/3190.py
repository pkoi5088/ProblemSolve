from collections import deque 

def out(N, next):
    if next[0]<0 or next[0]>=N or next[1]<0 or next[1]>=N:
        return True
    return False

N=int(input())
board=[[0 for _ in range(N)] for _ in range(N)]
K=int(input())
for _ in range(K):
    A=list(map(int,input().split()))
    board[A[0]-1][A[1]-1]=1
L=int(input())
rotate=deque()
for _ in range(L):
    A=list(input().split())
    rotate.append((int(A[0]),A[1]))

#동남서북
dx=[0,1,0,-1]
dy=[1,0,-1,0]

#꼬리, 방향, 시간
x,y = 0,0
board[x][y] = 2
snake=deque()
snake.append((x,y))
direction=0
time=0

while True:
    #전진
    nx=x+dx[direction]
    ny=y+dy[direction]
    if 0<=nx and nx<N and 0<=ny and ny<N and board[nx][ny] != 2:
        if board[nx][ny]==0:
            board[nx][ny]=2
            snake.append((nx,ny))
            px,py = snake.popleft()
            board[px][py] = 0
        else:
            board[nx][ny]=2
            snake.append((nx,ny))
    else:
        time+=1
        break
    x,y = nx,ny
    time+=1
    
    #전진 후 회전처리
    if len(rotate)!=0 and rotate[0][0]==time:
        if rotate[0][1]=='L':
            direction=(direction-1)%4
        else:
            direction=(direction+1)%4
        rotate.popleft()

print(time)