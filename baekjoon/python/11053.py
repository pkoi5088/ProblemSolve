N = int(input())
array = list(map(int, input().split()))
DP = [0 for _ in range(N)]
for i in range(N):
    for j in range(i):
        if array[i] > array[j] and DP[i] < DP[j]:
            DP[i] = DP[j]
    DP[i] += 1

print(max(DP))