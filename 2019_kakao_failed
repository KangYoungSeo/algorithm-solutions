#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//동적으로 시간을 늘려 난이도 조절
//목표 : 실패율 구하기
// 실패율이란? 스테이지에 도달했으나, 
// 아직 클리어하지 못한 플레이어수 / 스테이지에 도달한 플레이어수

// 전체 스테이지 개수 N ( 1 <= N <= 500 )
// 개임을 이용하는 사용자가 현재 멈춰있는 스테이지의 번호가 담긴 배열 
// stages ( 1 <=  <= 200000) 
// 20만? 상당히 의심스럽져
// stages 변수 ( 1<=  <= N + 1 )
// 마지막 인텍스 == 다 깬 사용자
// 실패율이 높은 스테이지 -> 내림차순
// 스테이지의 번호가 담겨있는 배열을 return
// 유저가 아에 없을 경우 실패율 0

bool cmp(pair<int, double> a, pair<int, double> b){
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
    
}

vector<int> solution(int N, vector<int> stages) {
    
    
    vector<pair<int, double> > v;
    vector<int> answer;
    int length = stages.size();

    // 스테이지 번호를 1부터 N까지 증가시키며
    for (int i = 1; i <= N; i++) {
        // 해당 스테이지에 머물러 있는 사람의 수 계산
        int cnt = count(stages.begin(), stages.end(), i);

        // 실패율 계산
        double fail = 0;
        if (length >= 1) {
            fail = (double) cnt / length;
        }

        // 리스트에 (스테이지 번호, 실패율) 원소 삽입
        v.push_back({i, fail});
        length -= cnt;
    }

    // 실패율을 기준으로 각 스테이지를 내림차순 정렬
    sort(v.begin(), v.end(), cmp);

    // 정렬된 스테이지 번호 반환
    for (int i = 0; i < N; i++) {
        answer.push_back(v[i].first);
    }
    return answer;
}
