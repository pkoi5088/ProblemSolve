N = int(input())

number = [0,1,1,1,1,1,1,1,1,1]

for i in range(1, N):
        tmp = [0,0,0,0,0,0,0,0,0,0]
        for j in range(10):
            if(j == 0):
                tmp[1] += number[j]
            elif(j == 9):
                tmp[8] += number[j]
            else:
                tmp[j - 1] += number[j]
                tmp[j + 1] += number[j]
        number = tmp
print(sum(number) % 1000000000)
