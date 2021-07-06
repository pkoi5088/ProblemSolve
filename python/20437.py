import collections

def solve():
    alpha=[collections.deque([]) for _ in range(26)]
    W=list(input())
    K=int(input())
    if K==1:
        print(1,1)
    else:
        m,M=20001,-1
        for i in range(len(W)):
            if len(alpha[ord(W[i])-ord('a')])!=K-1:
                alpha[ord(W[i])-ord('a')].append(i)
            else:
                m=min(i-alpha[ord(W[i])-ord('a')][0]+1,m)
                M=max(i-alpha[ord(W[i])-ord('a')][0]+1,M)
                alpha[ord(W[i])-ord('a')].popleft()
                alpha[ord(W[i])-ord('a')].append(i)
        if m==20001:
            print(-1)
        else:
            print(m,M)

T=int(input())
for _ in range(T):
    solve()