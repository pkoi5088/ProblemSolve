idx=1
while 1:
    L,P,V=map(int,input().split())
    if (L==0 and P==0 and V==0):
        break
    times=(V//P)*L
    remain=min(V%P,L)
    result=times+remain
    print('Case %d: %d'%(idx,result))
    idx+=1