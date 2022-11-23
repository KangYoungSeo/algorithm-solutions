K, N = map(int, input().split())
arr = []

for _ in range(K):
    x = int(input())
    arr.append(x)

arr.sort()
result = 0

def binary(start, end):
    mid = (start + end)//2
    total = 0
    for j in arr : 
        total += (arr[j] // mid)

    if N > total:
        binary(start, mid-1)
    elif total == N:
        result = mid
    elif total > N:
        binary(mid+1, end)


binary(0, arr[len(arr)-1])

print(result)