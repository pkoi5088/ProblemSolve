#include <iostream>
#include <string>
#include <algorithm>
#define MAX 100
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/3687
*/

//min 최소값, max 최대값
string dpMin[MAX],dpMax[MAX];
int arr[10]={6,2,5,5,4,5,6,3,7,6};

string toString(int a){
    if(a=0) return "0";
    string ret;
    while(a!=0){
        ret.push_back(a%10);
        a/=10;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

string sum(string a,string b){
    string ret;
    int tmp=0;
    while(!a.empty()&&!b.empty()){
        tmp+=a.back()-'0'+b.back()-'0';
        ret.push_back(tmp%10+'0');
        tmp/=10;
    }

    while(!a.empty()){
        tmp+=a.back()-'0';
        ret.push_back(tmp%10+'0');
        tmp/=10;
    }

    while(!b.empty()){
        tmp+=b.back()-'0';
        ret.push_back(tmp%10+'0');
        tmp/=10;
    }
    if(tmp!=0) ret.push_back(tmp);
    reverse(ret.begin(),ret.end());
    return ret;
}

string getDPMin(int n){
    string& ret=dpMin[n];
    if(ret!="") return ret;

}

void solve() {
    dpMin[2]="1";
    dpMin[3]="7";
    dpMin[4]="4";
    dpMin[5]="2";
    dpMin[6]="6";
    dpMin[7]="8";
    dpMax[2]="1";
    dpMax[3]="7";
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;

    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}