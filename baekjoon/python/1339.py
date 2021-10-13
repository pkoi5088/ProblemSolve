from sys import stdin

N=int(stdin.readline())
S={}
for _ in range(N):
    word=list(input())
    idx=0
    L=len(word)
    while idx<L:
        if word[idx] in S.keys():
            S[word[idx]]+=pow(10,L-idx-1)
        else:
            S[word[idx]]=pow(10,L-idx-1)
        idx+=1
result=sorted(S.items(),key=lambda x:-x[1])
number=9
R=0
for i in result:
    R+=i[1]*number
    number-=1
print(R)