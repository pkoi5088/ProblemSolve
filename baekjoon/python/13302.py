dp=[[-1 for _ in range(41)]for _ in range(101)]
tmp=input().split()
N=int(tmp[0])
M=[]
if tmp[1]!='0':
	M=list(map(int,input().split()))

def getDP(i,n):
	if N<i:
		return 0
	if dp[i][n]!=-1:
		return dp[i][n]
	
	dp[i][n]=getDP(i+1,n)+10000
	dp[i][n]=min(dp[i][n],getDP(i+3,n+1)+25000)
	dp[i][n]=min(dp[i][n],getDP(i+5,n+2)+37000)
	if 3<=n:
		dp[i][n]=min(dp[i][n],getDP(i+1,n-3))
	if i in M:
		dp[i][n]=min(dp[i][n],getDP(i+1,n))
	return dp[i][n]

print(getDP(1,0))