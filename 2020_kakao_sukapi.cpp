#include <string>
#include <vector>
/*
    스카피 레스토랑 -> 리모델링
    
    동그람 -> linked queue
    외벽의 총 둘레 = n미터
    -> 몇몇 지점은 '추위가 심할 경우 손상되는 취약한 지점' 있음
    
    내부 공사 도중, 손상 여부 점검해야함
    1시간안에 가능하도록!
    
    친구들이 1시간 동안 이동할 수 있는 거리 제각각임
    '최소한의' 친구들을 투입해 취약 지점을 점검 &
    나머지 친구들은 내부 공사 help
    출발 지점부터 시계, 혹은 반시계 방향으로 외벽을 따라서만 이동
    
    레스토랑 정북 방향 지점 = 0
    취약 지점의 위치 = 정북 방향 지점으로부터 시계 방향으로 떨어진 거리
    
    외벽의 길이 = n ( 1<= n <= 200)
    취약 지점의 위치가 담긴 배열 = weak   ( 1 <= weak <= 15 )
    각 친구가 1시간 동안 이동할 수 있는 거리가 담긴 배열 = dist 
        (1 <= dist <= 8)
    취약 지점을 점검하기 위해 보내야 하는 친구 수의 최소값 = return
        (해당 인물을 통해서 전부 점검할 수 없는 경우)
    
    
    방법 1) solution - brute force, greedy algorithm 
        즉, 모든 경우의 수를 다 계산해보는 것이다
        (사실 저 두개의 차이를 잘 모른다. brute force = 모든 경우의 수 따지기!
                                    greedy algorithm = 욕심쟁이다!
                                    우리가 원하는 답을 재귀호출 처럼
                                    여러 개의 조각으로 쪼개고,
                                    각 단계마다 답의 한 부분을 만듬
                                    어떻게 보면 완전 탐색, 동적 계획법 알고리즘
                                    과 비슷할지도)
*/

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    return answer;
}
