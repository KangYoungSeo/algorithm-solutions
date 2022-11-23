N = int(input())
#이차원 배열 입력받기
# !!블로그 1번
arr = [list(map(int, input().split())) for _ in range(N)]

#정렬 사용해서 정렬하기
#난 이분 탐색을 사용할 예정임
# 재귀 vs 반복문을 이용한 이분탐색 --> 기억X 서치 필요
# sort 함수 사용하면 바로 풀리나...?

# !! 블로그 2번

arr.sort()

#2차원 배열 출력
for i in arr :
    for j in i:
        print(j,end=" ")
    print()