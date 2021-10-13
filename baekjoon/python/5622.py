S = input()
R = 0
for i in S:
    if(i=='Z'):
        R += 10
    elif(i>='S'):
        R += ((ord(i)-66)//3)+3
    else:
        R += ((ord(i)-65)//3)+3
print(R)
