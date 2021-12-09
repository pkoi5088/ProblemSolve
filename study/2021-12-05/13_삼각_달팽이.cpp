#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/68645
*/

vector<int> solution(int n) {
    vector<int> answer;
    if(n==1){
        answer.push_back(1);
        return answer;
    }else if(n==2){
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
        return answer;
    }
    
    vector<vector<int>> v;
    v.resize(n);
    for(int i=0;i<n;++i)
        v[i].resize(n,-1);
    int x=0,y=0,cnt=1;
    while(true){
        if(v[x+1][y]!=-1) break;
        //아래
        while(!(x==n-1||v[x+1][y]!=-1)){
            v[x][y]=cnt;
            x+=1;
            cnt+=1;
        }
        
        //오른쪽
        while(!(y==n-1||v[x][y+1]!=-1)){
            v[x][y]=cnt;
            y+=1;
            cnt+=1;
        }
        
        //왼쪽위
        while(!(v[x-1][y-1]!=-1)){
            v[x][y]=cnt;
            x-=1;
            y-=1;
            cnt+=1;
        }
    }
    v[x][y]=cnt;
    for(int i=0;i<n;++i){
        for(int j=0;j<=i;++j){
            answer.push_back(v[i][j]);
        }
    }
    return answer;
}