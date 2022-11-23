
#input
N = int(input())
sang = sorted(map(int, input().split()))
M = int(input())
check = list(map(int, input().split()))
result = []

#binary search
def binary(k, lst, start, end):
    mid = (start+end) // 2
    if start > end:
        result.append(str(0))
    elif k == lst[mid]:
        result.append(str(1))
    elif k > lst[mid]:
        binary(k, lst, mid+1, end)
    else:
        binary(k, lst, start, mid-1)


#check numbers
for i in check:
    start = 0
    end = len(sang)-1
    binary(i, sang, start, end)

print(' '.join(result))