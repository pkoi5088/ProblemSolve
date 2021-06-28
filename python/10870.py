def function(N):
    return (N if N==0 or N==1 else function(N-1)+function(N-2))

N = int(input())
print(function(N))