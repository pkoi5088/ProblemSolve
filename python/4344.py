T=int(input())
while T:
    S=list(map(float,input().split()))
    del S[0]
    aver=sum(S)/len(S)
    cnt=0
    for i in S:
        if i>aver:
            cnt+=1
    print(str('%.3f' % round(cnt/len(S) * 100, 3)) + '%')
    T-=1