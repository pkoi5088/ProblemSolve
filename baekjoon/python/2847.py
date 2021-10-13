from sys import stdin

N=int(stdin.readline())
S=[]
for _ in range(N):
    S.append(int(stdin.readline()))

if N==1:
    print(1)
else:
    result=0
    for idx in range(N-2,-1,-1):
        if S[idx]>=S[idx+1]:
            result+=S[idx]-S[idx+1]+1
            S[idx]=S[idx+1]-1
    print(result)            