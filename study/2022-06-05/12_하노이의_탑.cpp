#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12946
*/

//n개의 원판을 from에서 to로 옮긴다
void function(int n,int from,int to,int tmp,vector<vector<int>>& answer){
    if(n==1){
        answer.push_back({from,to});       
    }else{
        function(n-1,from,tmp,to,answer);
        answer.push_back({from,to});    
        function(n-1,tmp,to,from,answer);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    function(n,1,3,2,answer);
    return answer;
}