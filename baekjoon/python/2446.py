N=int(input())
start=2*N-1
for i in range(N):
    for j in range(i):
        print(' ',end='')
    for j in range(start-2*i):
        print('*',end='')
    print('')

for i in range(1,N):
    for j in range(N-i-1):
        print(' ',end='')
    for j in range(2*i+1):
        print('*',end='')
    print('')
    