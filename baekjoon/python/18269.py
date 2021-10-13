def function(S,N):
    #i는 sub의 길이
    #j는 sub시작 index
    for i in range(1,N+1):
        A=[]
        flag=True
        sub=''
        for j in range(N-i+1):
            sub=S[j:j+i]
            if sub in A:
                flag=False
                break
            A.append(sub)
        if flag:
            return len(sub)

N=int(input())
S=input()
print(function(S,N))