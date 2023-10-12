#include <iostream>
#include <queue>
#include <vector>
 
#define MAX 110
using namespace std;
 
int n, k;
deque<int> bowl[MAX];
 
int dx[] = { 0, -1 };
int dy[] = { 1, 0 };

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        bowl[0].push_back(a);
    }
}

bool check() {         //큰 값, 작은 값을 찾고 그 둘의 차를 구함.
    int minFish = 987654321;
    int maxFish = -987654321;
    for (int i = 0; i < bowl[0].size(); i++) {
        minFish = min(minFish, bowl[0][i]);
        maxFish = max(maxFish, bowl[0][i]);
    }
 
    return maxFish - minFish <= k ? true : false;
}

void addFish() {        //물고기 추가

    int minFish = 987654321;

    vector<int> idxV;

    for (int i = 0; i < bowl[0].size(); i++) {


        if (bowl[0][i] < minFish) {
            minFish = bowl[0][i];
            idxV.clear();
            idxV.push_back(i);
        } else if (bowl[0][i] == minFish) {
            idxV.push_back(i);
        }
    }
 
    for (auto idx : idxV) {
        bowl[0][idx]++;
    }
}
 
bool canBuild(int w, int h) {   //어항 제작 가능 여부 파악

    if (bowl[0].size() - w < h) return false;
    return true;
}
 
void print() {          //출력 debug
    for (int i = 0; i < 5; i++) {
        if (bowl[i].size() == 0) continue;
        for (int j = 0; j < bowl[i].size(); j++) {
            printf("%2d ", bowl[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}
 
int buildBowl() {       //어항 제작 1, 왼쪽 칸부터 접어서 커지기

    int width = 1;
    int height = 1;
    bool flag = false;
 
    while (1) {

        if (canBuild(width, height) == false) break;        //어항 제작 가능여부 ( 길이 비교 )
        
        int tmpWidth = width;
 
        for (int i = 0; i < width; i++, tmpWidth--) {
            int idx = 0;

            //bowl 
            for (int j = 0; j < height; j++, idx++) 
                bowl[tmpWidth].push_back(bowl[idx][i]);
            
        }
 
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) bowl[i].pop_front();
        }
 
        if (flag == false) {

            height++;
            flag = true;

        } else {

            width++;
            flag = false;
            
        }
    }
    return height;
}
 
void adjustFish(int height) {   //인접 칸 물고기 배분 

    deque<int> tmpbowl[MAX];

    for (int i = 0; i < height; i++) tmpbowl[i] = bowl[i];

    for (int i = height - 1; i >= 0; i--) {

        for (int j = 0; j < bowl[i].size(); j++) {

            int x = i;
            int y = j;

            int num = bowl[x][y];

            //인접한 부분에서 차이를 /5 한 몫이 0보다 크다면, 
            for (int k = 0; k < 2; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && ny < bowl[i].size()) {

                    int num2 = bowl[nx][ny];
                    int diff = abs(num - num2) / 5;


                    // 물고기 값을 몫 만큼 분배 (단, 동시 비교를 위해 tmpbowl에 저장)
                    if (diff > 0) {
                        if (num > num2) {
                            tmpbowl[x][y] -= diff;
                            tmpbowl[nx][ny] += diff;
                        } else {
                            tmpbowl[nx][ny] -= diff;
                            tmpbowl[x][y] += diff;
                        }
                    }
                    
                }
            }
        }
    }
 
    for (int i = 0; i < height; i++) {
        bowl[i] = tmpbowl[i];
    }
}
 
void spreadBowl(int height) {   //일열로 내려놓기

    int width = bowl[height - 1].size();
    int size = bowl[0].size();

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            bowl[0].push_back(bowl[j][i]);
        }
    }

    for (int i = 1; i < height; i++) bowl[i].clear();
        
    for (int i = width; i < size; i++) bowl[0].push_back(bowl[0][i]);
        
    for (int i = 0; i < size; i++) bowl[0].pop_front();

}
 
void buildBowl2() {             //어항 제작 2, N/2로 최대한 접기
    int n = bowl[0].size();
    for (int i = 0; i < n / 2; i++) {
        bowl[1].push_front(bowl[0][i]);
    }
    for (int i = 0; i < n / 2; i++) {
        bowl[0].pop_front();
    }
    for (int i = 0; i < n / 4; i++) {
        bowl[2].push_front(bowl[1][i]);
        bowl[3].push_front(bowl[0][i]);    
    }
    for (int i = 0; i < n / 4; i++) {
        bowl[0].pop_front();
        bowl[1].pop_front();
    }
}
 
void solution() {
    int answer = 0;

    while (1) {

        if (check() == true) {      //차이값 비교
            cout << answer << endl;
            break;
        }
 
        addFish();                  //새로운 물고기 추가

        int height = buildBowl();   //어항 제작 1, 왼쪽 칸부터 어항 높이 계산

        adjustFish(height);         //인접 칸 물고기 배분

        spreadBowl(height);         //일열로 내려놓기

        buildBowl2();               //어항 제작 2, N/2 접기 

        adjustFish(4);              //인접 칸 물고기 배분 

        spreadBowl(4);              //일열로 내려놓기

        answer++;
        
    }
}

int main(void) {

    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    input();
    solution();
    return 0;
}