X=int(input())
N=1
while not(N*(N+1)//2>=X):
    N+=1
X-=(N-1)*N//2
if N%2==0:
    print(str(X)+'/'+str(N-X+1))
else:
    print(str(N-X+1)+'/'+str(X))