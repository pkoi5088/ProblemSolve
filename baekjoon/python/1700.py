from sys import stdin

N,K=map(int,stdin.readline().split())
S=list(map(int,stdin.readline().split()))
plug=[-1 for _ in range(N)]
cnt=0

for idx in range(K):
    if S[idx] in plug:
        continue
    elif -1 in plug:
        plug[plug.index(-1)]=S[idx]
    else:
        cnt+=1
        tmp=[]
        for pidx in range(N):
            M=idx+1
            while M<K:
                if S[M]==plug[pidx]:
                    break
                M+=1
            tmp.append((pidx,-M))
        tmp.sort(key=lambda x:x[1])
        plug[tmp[0][0]]=S[idx]

print(cnt)