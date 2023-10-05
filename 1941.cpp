#include<iostream>
#include<cstring>
#include<string>
#include<queue>
 
#define endl "\n"
using namespace std;
 
int MAP[5][5], Answer;
bool Select[25];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1 ,0, 0 };
 
void Input()        //입력값
{
    for (int i = 0; i < 5; i++)
    {
        string Inp;
        cin >> Inp;
        for (int j = 0; j < Inp.length(); j++)
        {
            if (Inp[j] == 'Y') MAP[i][j] = 1;
            else if (Inp[j] == 'S') MAP[i][j] = 2;
        }
    } 
}
 
bool MoreThanFour()     // 해당 내역 4개 이상인지, 단순 계산
{
    int Cnt = 0;
    for (int i = 0; i < 25; i++)
    {
        if (Select[i] == true)
        {
            int x = i / 5;
            int y = i % 5;
 
            if (MAP[x][y] == 2) Cnt++;
        }
    }
    if (Cnt >= 4) return true;
    else return false;
}



 bool Adjacency()           //선택된 블럭들의 인접 여부 파악
{
    queue <pair<int, int>> Q;
		

		// 보드에서 실제 선택된 블럭인지 확인 여부
    bool Check_Select[5][5];

		// 얘는 이 인접했는지 아닌지 판단할 때 확인한 블럭인지 여부
    bool Queue_Select[5][5];

    bool Check_Answer = false;
 
    memset(Queue_Select, false, sizeof(Queue_Select));
    memset(Check_Select, false, sizeof(Check_Select));
 
    int Tmp = 0;

		//해당 맵에서 선택되었는지 여부를 Check_Select라는 2차원 배열에 저장
		//이 사람이 애초에 2차원으로 선언을 안해둬서 그 처리를 하는 거라서
		// 불필요한 과정일지도, 허나 첫 탐색을 위한 기준점을 찾고 있음
		// 근데 사실 그 기준점을 애초에 함수 선언할 때 전달해도 괜찮을 것 같음

    for (int i = 0; i < 25; i++)
    {
        if (Select[i] == true)
        {            
            int x = i / 5;
            int y = i % 5;
            Check_Select[x][y] = true;
 
            if (Tmp == 0)
            {
                Q.push(make_pair(x, y));
                Queue_Select[x][y] = true;
                Tmp++;
            }
        }
    }
 
    int Cnt = 1;

		//첫 블럭부터 탐색 시작
    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
				 

				//세어 봤을 때 Cnt가 7이면 인접해 있는 거니까 break후 true 반환
        if (Cnt == 7)
        {
            Check_Answer = true;
            break;
        }
			 
				//상하좌우를 확인
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
						//상하좌우를 파악하는 부분에서
            if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5){
            
								//보드에서 선택됐는데 + 인접했는지를 확인 아직 안했을 때
                if (Check_Select[nx][ny] == true && Queue_Select[nx][ny] == false)
                {
										//인접 했다고 선언하고
                    Queue_Select[nx][ny] = true;

										//Queue에 저장하기 => 다른 인접 부분 확인
                    Q.push(make_pair(nx, ny));

										//개수 추가 
                    Cnt++;
                }
            }
        }
    }
 
    if (Check_Answer == true) return true;
    return false;
}

void DFS(int Idx, int Cnt)
{
    if (Cnt == 7)
    {
        if (MoreThanFour() == true)
        {
            if (Adjacency() == true) Answer++;
        }
        return;
    }
 
    for (int i = Idx; i < 25; i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;
        DFS(i, Cnt + 1);
        Select[i] = false;
    }
}
 
void Solution()
{
    DFS(0, 0);
    cout << Answer << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    Solve();
 
    return 0;
}