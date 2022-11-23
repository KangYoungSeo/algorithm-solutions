N = int(input())
arr =  []
delivery = 0

for _ in range(N):
    xy = list(map(int,input().split()))
    arr.append(xy)
    delivery += xy[1]

arr.sort()

max = -1
result = -1

for i in range(N):
    if(i != 0 & arr[i][0] == arr[i-1][0]) :
        delivery -= arr[i][1]
        continue
    total = (N-i)*arr[i][0] - delivery
    if(total > max) :
        result = arr[i][0]
        max = total
    delivery -= arr[i][1]

if(max < 0) : 
    print(0)
else :
    print(result)