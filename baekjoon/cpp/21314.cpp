#include <iostream>
#include <string>
#define endl '\n'

using namespace std;

string getMax(string str){
    string ret="";
    int cnt=0;
    for(int i=0;i<str.size();++i){
        if(str[i]=='K'){
            ret.push_back('5');
            while(cnt!=0){
                ret.push_back('0');
                cnt-=1;
            }
        }else{
            cnt+=1;
        }
    }
    
    while(cnt!=0){
        ret.push_back('1');
        cnt-=1;
    }
    return ret;
}

string getMin(string str){
    string ret="";
    int cnt=0;
    for(int i=0;i<str.size();++i){
        if(str[i]=='K'){
            if(cnt!=0){
                ret.push_back('1');
                cnt-=1;
                while(cnt!=0){
                    ret.push_back('0');
                    cnt-=1;
                }
            }
            ret.push_back('5');
        }else{
            cnt+=1;
        }
    }
    
    if(cnt!=0){
        ret.push_back('1');
        cnt-=1;
        while(cnt!=0){
            ret.push_back('0');
            cnt-=1;
        }
    }
    return ret;
}

void solve() {
    string str;
    cin>>str;
    cout<<getMax(str)<<endl;
    cout<<getMin(str);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}