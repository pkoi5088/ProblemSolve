T=int(input())
while T:
    S=list(input())
    sum=0
    start=0
    for i in S:
        if i=='O':
            start+=1
            sum+=start
        else:
            start=0
    print(sum)
    T-=1