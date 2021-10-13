S=list(input())
result=10
for i in range(1,len(S)):
    if S[i-1]==S[i]:
        result+=5
    else:
        result+=10
print(result)