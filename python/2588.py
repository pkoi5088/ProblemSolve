A = int(input())
B = int(input())
R = 0
for i in range(3):
    C = B % 10
    print(A*C)
    R += A*C*(10**i)
    B = B//10
print(R)
