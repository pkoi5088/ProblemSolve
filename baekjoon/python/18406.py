N=list(input())
sum=0
for i in range(len(N)//2):
    sum+=int(N[i])
for i in range(len(N)//2,len(N),1):
    sum-=int(N[i])
print('LUCKY' if sum==0 else 'READY')