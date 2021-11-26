#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/42747
*/

int solution(vector<int> citations) {
    int answer=0,N=citations.size(),start=0,end;
    sort(citations.begin(),citations.end());
    end=citations[N-1];
    while(start<=end){
        int mid=(start+end)/2,idx=lower_bound(citations.begin(),citations.end(),mid)-citations.begin();
        //개수 N-idx
        if(mid<=N-idx){
            answer=mid;
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return answer;
}