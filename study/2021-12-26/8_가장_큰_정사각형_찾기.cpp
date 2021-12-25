#include <iostream>
#include<vector>
using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12905
*/

int min(int a,int b,int c){
    if(a<b)
        return (a<c?a:c);
    return (b<c?b:c);
}

int solution(vector<vector<int>> board)
{
    int answer=0;
    for(int i=0;i<board.size();++i){
        for(int j=0;j<board[0].size();++j){
            if(board[i][j]==0) continue;
            if(i==0||j==0){
                answer=max(answer,1);
                continue;
            }
            if(board[i-1][j-1]==0||board[i][j-1]==0||board[i-1][j]==0)
                answer=max(answer,1);
            else{
                int tmp=min(board[i-1][j-1],board[i-1][j],board[i][j-1])+1;
                board[i][j]=tmp;
                answer=max(answer,tmp*tmp);
            }
        }
    }
    return answer;
}