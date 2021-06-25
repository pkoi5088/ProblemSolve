from sys import stdin

R,C=map(int,stdin.readline().split())

B=[[] for _ in range(R)]
move=[(-1,1),(0,1),(1,1)]
for i in range(R):
    M=list(stdin.readline())
    M.pop()
    B[i]=M

def find(loc):
    x,y=loc[0],loc[1]
    B[x][y]='X'
    if y==C-1:
        return 1
    else:
        for i in move:
            nx,ny=x+i[0],y+i[1]
            if nx>=R or nx<=-1:
                continue
            elif B[nx][ny]!='.':
                continue
            else:
                if find((nx,ny))==1:
                    return 1
        return 0

idx,cnt=0,0

while idx<R:
    if find((idx,0))==1:
        cnt+=1
    idx+=1
print(cnt)