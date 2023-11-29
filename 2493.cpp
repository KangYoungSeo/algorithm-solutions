#include <iostream>
#include <stack>

using namespace std;

int n, k;
stack<pair<int, int>> st;

int main(){
    
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin >> n;
    for(int i=1; i <= n; i++){
        cin >> k;
        while(!st.empty()){
            
            if(st.top().second > k){
                
                cout << st.top().first << " ";
                break;
            }
            st.pop();
        }
        
        if(st.empty()) cout << "0 ";
        
        st.push(make_pair(i,k));
    }    
    return 0;
}