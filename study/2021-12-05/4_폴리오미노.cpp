#include <iostream>
#include <string>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/1343
*/

void f(int n,string& ret){
    while(n>0){
        if(n>=4){
            ret+="AAAA";
            n-=4;
        }else{
            ret+="BB";
            n-=2;
        }
    }
}

void solve() {
    string str,ret;
    cin>>str;
    str.push_back('.');
    for(int i=0,cnt=0;i<str.size();++i){
        if(str[i]=='.'){
            if(cnt%2){
                cout<<-1;
                return;
            }else{
                f(cnt,ret);
            }
            ret.push_back('.');
            cnt=0;
        }else{
            cnt+=1;
        }
    }
    ret.pop_back();
    cout<<ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}