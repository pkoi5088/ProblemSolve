#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12987
*/

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int left=0,right=B.size()-1,idx=B.size()-1;
    while(left<=right){
        if(A[idx]<B[right]){
            answer+=1;
            right-=1;
        }else{
            left+=1;
        }
        idx-=1;
    }
    
    return answer;
}