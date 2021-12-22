#include <string>
using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/49994
*/

int solution(string dirs) {
    //0은 위, 1은 옆
    bool visit[11][11][2]={false,};
    int answer = 0,x=5,y=5;
    for(char& dir:dirs){
        if(dir=='U'&&y!=10){
            visit[x][y][0]=true;
            y+=1;
        }else if(dir=='D'&&y!=0){
            visit[x][y-1][0]=true;
            y-=1;
        }else if(dir=='R'&&x!=10){
            visit[x][y][1]=true;
            x+=1;
        }else if(dir=='L'&&x!=0){
            visit[x-1][y][1]=true;
            x-=1;
        }
    }
    for(int i=0;i<11;++i){
        for(int j=0;j<11;++j){
            for(int k=0;k<2;++k){
                answer+=(visit[i][j][k]==true?1:0);
            }
        }
    }
    return answer;
}