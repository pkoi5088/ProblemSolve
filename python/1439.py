board=list(input())
cnt=0
for i in range(len(board)-1):
    if board[i]!=board[i+1]:
        cnt+=1
print((cnt+1)//2)