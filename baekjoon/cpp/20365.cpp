#include <iostream>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
    int N,B=0,R=0;
    cin>>N;
    string str;
    cin>>str;
    if(N==1) cout<<1;
    else{
        for(int i=1;i<str.size();++i){
            if(str[i-1]!=str[i]){
                if(str[i-1]=='B'){
                    B+=1;
                }else{
                    R+=1;
                }
            }
        }
        if(str[N-1]=='B'){
            B+=1;
        }else{
            R+=1;
        }
        cout<<min(B,R)+1;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}