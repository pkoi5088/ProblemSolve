N = int(input())
value = [-1]*(N+1)
dp = [-1]*(N+1)

for i in range(1, N+1):
    value[i] = int(input())

def function(n):
    if dp[n]!=-1:
        return dp[n]
    dp[n] = max(function(n-2),function(n-3)+value[n-1])+value[n]
    return dp[n]

if N==1:
    print(value[1])
elif N==2:
    print(value[1]+value[2])
elif N==3:
    print(max(value[1],value[2])+value[3])
else:
    dp[1] = value[1]
    dp[2] = value[1]+value[2]
    dp[3] = max(value[1],value[2])+value[3]
    print(function(N))
          
