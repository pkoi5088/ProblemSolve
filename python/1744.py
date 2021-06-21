from sys import stdin

N=int(stdin.readline())
S=[]
for _ in range(N):
    S.append(int(stdin.readline()))
S.sort(reverse=True)
lidx=0
ridx=N-1
result=0
while lidx<N:
    if lidx!=N-1:
        if (S[lidx]>1 and S[lidx+1]>1):
            result+=S[lidx]*S[lidx+1]
            lidx+=1
        else:
            break
    else:
        result+=S[lidx]
    lidx+=1

while ridx>0:
    if ridx!=1:
        if (S[ridx]<1 and S[ridx-1]<1):
            result+=S[ridx]*S[ridx-1]
            ridx-=1
        else:
            break
    else:
        result+=S[ridx]
    ridx-=1

for i in range(lidx,ridx+1):
    result+=S[i]
print(result)