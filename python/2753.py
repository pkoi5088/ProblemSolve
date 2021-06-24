N = int(input())
print(1 if N%4==0 and (N%400==0 or N%100!=0) else 0)

