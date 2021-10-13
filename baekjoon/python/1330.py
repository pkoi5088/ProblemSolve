A=list(map(int,input().split()))
print('>'if A[0]>A[1] else ('==' if A[0]==A[1] else '<'))