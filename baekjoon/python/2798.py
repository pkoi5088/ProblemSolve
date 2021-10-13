List = input().split()
M = int(List[1])
List = input().split()
R = -1

for i in range(len(List)-2):
    for j in range(i+1,len(List)-1):
        for k in range(j+1,len(List)):
            n = int(List[i])+int(List[j])+int(List[k])
            if(n<=M and M-n<M-R):
                R = n

print(R)