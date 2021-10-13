N=int(input())
for _ in range(N):
    r,e,c=map(int,input().split())
    if e-r==c:
        print('does not matter')
    elif e-r>c:
        print('advertise')
    else:
        print('do not advertise')