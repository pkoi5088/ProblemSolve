N,K=map(int,input().split())
S=list(input())
cnt=0
# 0 is not eat, 1 is eat
eat=[0 for _ in range(len(S))]

for i in range(len(S)):
    if S[i]=='P':
        flag=1
        #left side
        for j in range(K,0,-1):
            if i-j>=0 and S[i-j]=='H' and eat[i-j]==0:
                eat[i-j]=1
                cnt+=1
                flag=0
                break
        
        #right side
        if(flag):
            for j in range(1,K+1):
                if i+j<N and S[i+j]=='H' and eat[i+j]==0:
                    eat[i+j]=1
                    cnt+=1
                    break
print(cnt)