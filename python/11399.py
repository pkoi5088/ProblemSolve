N=int(input())
S=list(map(int,input().split()))
S.sort()
for i in range(1,N):
    S[i]+=S[i-1]
print(sum(S))