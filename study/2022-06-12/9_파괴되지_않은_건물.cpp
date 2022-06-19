#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/92344
*/

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0,N=board.size(),M=board[0].size();
    vector<vector<int>> delta(N+1,vector<int>(M+1,0));
    for(int i=0;i<skill.size();++i){
        int type=skill[i][0],degree=skill[i][5];
        int x1=skill[i][1],y1=skill[i][2];
        int x2=skill[i][3],y2=skill[i][4];
        if(type==1){
            delta[x1][y1]-=degree;
            delta[x2+1][y2+1]-=degree;
            delta[x1][y2+1]+=degree;
            delta[x2+1][y1]+=degree;
        }else{
            delta[x1][y1]-=-degree;
            delta[x2+1][y2+1]-=-degree;
            delta[x1][y2+1]+=-degree;
            delta[x2+1][y1]+=-degree;
        }
    }
    
    for(int i=0;i<N;++i){
        for(int j=1;j<M;++j){
            delta[i][j]+=delta[i][j-1];
        }
    }
    for(int i=0;i<M;++i){
        for(int j=1;j<N;++j){
            delta[j][i]+=delta[j-1][i];
        }
    }
    
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(delta[i][j]+board[i][j]>0) answer+=1;
        }
    }
    return answer;
}