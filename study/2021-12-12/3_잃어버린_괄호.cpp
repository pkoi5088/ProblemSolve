#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/1541
*/

void solve() {
    //-1:+, -2:-
    vector<int> v;
    string str,tmp;
    cin>>str;
    for(int i=0;i<str.size();++i){
        if(str[i]=='+'||str[i]=='-'){
            v.push_back(stoi(tmp));
            v.push_back(str[i]=='+'?-1:-2);
            tmp.clear();
        }else{
            tmp.push_back(str[i]);
        }
    }
    v.push_back(stoi(tmp));

    vector<int> ret;
    ret.push_back(v[0]);
    for(int i=1;i<v.size();++i){
        if(v[i]==-1){
            ret[ret.size()-1]+=v[i+1];
        }else if(v[i]==-2){
            ret.push_back(-2);
            ret.push_back(v[i+1]);
        }
    }

    for(int i=2;i<ret.size();i+=2){
        ret[0]-=ret[i];
    }
    cout<<ret[0];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}