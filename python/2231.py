def function(N):
    for i in range(N):
        S = str(i)
        m = 0
        for j in range(len(S)):
            m += int(S[j])
            
        if(m+i == N):
            return i

    return 0


N = int(input())
print(function(N))
