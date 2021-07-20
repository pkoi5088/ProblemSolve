N=int(input())
num=[0 for _ in range(N)]
check=[0 for _ in range(N)]
cycle=[]

def dfs(n):
	if check[n]==1 and n not in cycle:
		now=n
		while now not in cycle:
			cycle.append(now)
			now=num[now]
	elif check[n]!=2:
		check[n]=1
		dfs(num[n])
	check[n]=2

for i in range(N):
	num[i]=int(input())-1

for i in range(N):
	if check[i]==0 and i not in cycle:
		dfs(i)
		
cycle.sort()
print(len(cycle))
for i in cycle:
	print(i+1)