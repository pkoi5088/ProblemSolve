#include <iostream>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/20546
*/

void solve() {
    int money,stock[14];
    cin>>money;
    for(int i=0;i<14;++i)
        cin>>stock[i];
    pair<int,int> jun={money,0},sung={money,0};

    int upCount=0,downCount=0;
    for(int i=0;i<14;++i){
        //준성(돈이 되면 바로 사기)
        jun.second+=jun.first/stock[i];
        jun.first-=jun.first/stock[i]*stock[i];

        //성민(카운트 하면서 사기)
        if(i!=0&&stock[i]<stock[i-1]){
            downCount+=1;
            upCount=0;
            //전량매수
            if(downCount>=3){
                sung.second+=sung.first/stock[i];
                sung.first-=sung.first/stock[i]*stock[i];
            }
        }else if(i!=0&&stock[i]>stock[i-1]){
            upCount+=1;
            downCount=0;
            //전량매도
            if(upCount>=3){
                sung.first+=sung.second*stock[i];
                sung.second=0;
            }
        }else{
            upCount=0;
            downCount=0;
        }
    }

    int junMoney=jun.first+jun.second*stock[13];
    int sungMoney=sung.first+sung.second*stock[13];
    if(junMoney>sungMoney){
        cout<<"BNP";
    }else if(junMoney<sungMoney){
        cout<<"TIMING";
    }else{
        cout<<"SAMESAME";
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}