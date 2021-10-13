board=[1 for _ in range(10000)]

for i in range(1,10001):
    number=i+sum([int(j) for j in str(i)])
    if number<=10000:
        board[number-1]=0

for i in range(10000):
    if board[i]==1:
        print(i+1)