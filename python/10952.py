while True:
    A=list(map(int,input().split()))
    if sum(A)==0:
        break
    print(sum(A))