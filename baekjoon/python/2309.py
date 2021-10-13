height=[0 for _ in range(9)]

for i in range(9):
    height[i]=int(input())
height.sort()

def solve():
    i,j=0,1
    flag=0
    while i<9:
        j=i+1
        while j<9:
            S=0
            for idx in range(9):
                if idx!=i and idx!=j:
                    S+=height[idx]
            if S==100:
                for idx in range(9):
                    if idx!=i and idx!=j:
                        print(height[idx])
                return

            j+=1
        i+=1

solve()