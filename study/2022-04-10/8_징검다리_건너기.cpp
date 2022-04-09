#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/64062
*/

//cut이상인 돌이 연속해서 k개가 나온다
bool check(vector<int>& stones,int cut,int k){
    int cnt=0;
    for(int i=0;i<stones.size();++i){
        if(stones[i]<=cut){
            cnt+=1;
        }else{
            cnt=0;
        }
        
        if(cnt>=k) return true;
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int start=0,end=200000001;
    while(start<=end){
        int mid=(start+end)/2;
        if(check(stones,mid,k)){
            answer=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return answer;
}