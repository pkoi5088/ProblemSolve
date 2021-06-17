from sys import stdin

def isSame(C):
    for i in range(len(C)):
        for j in range(len(C[i])):
            if C[i][j]==1:
                return 0
    return 1

N,M=map(int,stdin.readline().split())
A=[[] for _ in range(N)]
B=[[] for _ in range(N)]
C=[[] for _ in range(N)]
for i in range(N):
    S=list(stdin.readline().rstrip())
    for s in S:
        A[i].append(int(s))
for i in range(N):
    S=list(stdin.readline().rstrip())
    for s in S:
        B[i].append(int(s))
for i in range(N):
    for j in range(M):
        C[i].append(B[i][j]^A[i][j])

if N<3 or M<3:
    print(0 if isSame(C)==1 else -1)
else:
    cnt=0
    for i in range(N-2):
        for j in range(M-2):
            if C[i][j]==1:
                cnt+=1
                for k in range(3):
                    for l in range(3):
                        C[i+k][j+l]=C[i+k][j+l]^1

    print(cnt if isSame(C)==1 else -1)
            