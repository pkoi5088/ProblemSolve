#include <string>
#include <vector>

using namespace std;

int getIdx(int start,int end,string number){
    int ret=start;
    for(int i=start;i<=end;++i){
        if(number[ret]<number[i])
            ret=i;
    }
    return ret;
}

void f(int start,int end,int k,string& number,string& ret){
    if(k<0||end-start+1==k) return;
    int idx=getIdx(start,end,number);
    //앞에 개수 idx-start
    if(idx-start<k){
        //앞에 idx-start개 다 지우고 idx+1부터 k-idx-start개를 더 지운다
        ret.push_back(number[idx]);
        f(idx+1,end,k-(idx-start),number,ret);
    }else{
        //앞에서 k개 지우고 number[idx:end]추가
        f(start,idx-1,k,number,ret);
        for(int i=idx;i<=end;++i){
            ret.push_back(number[i]);
        }
    }
}

string solution(string number, int k) {
    string answer = "";
    f(0,number.size()-1,k,number,answer);
    return answer;
}