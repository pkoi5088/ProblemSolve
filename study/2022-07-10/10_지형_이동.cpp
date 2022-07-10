#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

/*
    https://school.programmers.co.kr/learn/courses/30/lessons/62050
*/

struct Node{
    int x,y,cost;
    Node(int ix,int iy,int ic){
        x=ix,y=iy,cost=ic;
    }
};

struct cmp{
    bool operator()(Node n1,Node n2){
        return n1.cost>n2.cost;
    }
};

int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

int solution(vector<vector<int>> land, int height) {
    int answer = 0,N=land.size(),M=land[0].size();
    vector<vector<bool>> check(N,vector<bool>(M,false));
    
    priority_queue<Node,vector<Node>,cmp> pq;
    pq.push(Node(0,0,0));
    while(!pq.empty()){
        int x=pq.top().x,y=pq.top().y,cost=pq.top().cost;
        pq.pop();
        
        if(check[x][y]) continue;
        check[x][y]=true;
        
        //사다리설치
        answer+=cost;
        
        for(int k=0;k<4;++k){
            int nx=x+dx[k],ny=y+dy[k];
            if(nx<0||nx>=N||ny<0||ny>=M||check[nx][ny]) continue;
            pq.push(Node(nx,ny,(abs(land[x][y]-land[nx][ny])<=height?0:abs(land[x][y]-land[nx][ny]))));
        }
    }
    return answer;
}