A=[]
for _ in range(9):
    A.append(int(input()))
print(max(A))
print(A.index(max(A))+1)