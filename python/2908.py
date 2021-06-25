List = input().split()
A = int(''.join(list(reversed(List[0]))))
B = int(''.join(list(reversed(List[1]))))
print(A if A>B else B)