#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/60063
*/

//state 0:가로 1:세로
struct Node{
    int x,y,state,dist;
    Node(int ix,int iy,int is,int id){
        x=ix,y=iy,state=is,dist=id;
    }
};

bool goalCheck(int x,int y,int state,int N,vector<vector<int>>& board){
    int nx=x,ny=y;
    if(state==0) ny+=1;
    else nx+=1;
    return (x==N-1&&y==N-1)||(nx==N-1&&ny==N-1);
}

//board[x][y]에서 state가 가능한가?
bool validCheck(int x,int y,int state,int N,vector<vector<int>>& board){
    int nx=x,ny=y;
    if(state==0) ny+=1;
    else nx+=1;
    if(x<0||x>=N||nx<0||nx>=N) return false;
    if(y<0||y>=N||ny<0||ny>=N) return false;
    if(board[x][y]==0&&board[nx][ny]==0) return true;
    else return false;
}

//다음으로 이동 가능한 위치들 반환
vector<Node> getNext(int x,int y,int state,int N,vector<vector<int>>& board){
    vector<Node> ret;
    //무회전
    if(validCheck(x-1,y,state,N,board))
        ret.push_back(Node(x-1,y,state,-1));
    if(validCheck(x+1,y,state,N,board))
        ret.push_back(Node(x+1,y,state,-1));
    if(validCheck(x,y+1,state,N,board))
        ret.push_back(Node(x,y+1,state,-1));
    if(validCheck(x,y-1,state,N,board))
        ret.push_back(Node(x,y-1,state,-1));
    
    //회전
    if(state==0){
        //위로 회전
        if(x!=0&&board[x-1][y]==0&&board[x-1][y+1]==0){
            ret.push_back(Node(x-1,y,1,-1));
            ret.push_back(Node(x-1,y+1,1,-1));
        }
        
        //아래로 회전
        if(x!=N-1&&board[x+1][y]==0&&board[x+1][y+1]==0){
            ret.push_back(Node(x,y,1,-1));
            ret.push_back(Node(x,y+1,1,-1));
        }
    }else{
        //왼쪽 회전
        if(y!=0&&board[x][y-1]==0&&board[x+1][y-1]==0){
            ret.push_back(Node(x,y-1,0,-1));
            ret.push_back(Node(x+1,y-1,0,-1));
        }
        
        //오른쪽 회전
        if(y!=N-1&&board[x][y+1]==0&&board[x+1][y+1]==0){
            ret.push_back(Node(x,y,0,-1));
            ret.push_back(Node(x+1,y,0,-1));
        }
    }
    return ret;
}

int solution(vector<vector<int>> board) {
    int answer = 0,N=board.size();
    vector<vector<vector<bool>>> check(N,vector<vector<bool>>(N,vector<bool>(2,false)));
    queue<Node> q;
    q.push(Node(0,0,0,0));
    check[0][0][0]=true;
    
    while(!q.empty()){
        int x=q.front().x,y=q.front().y,state=q.front().state,dist=q.front().dist;
        q.pop();
        
        if(goalCheck(x,y,state,N,board)){
            answer=dist;
            break;
        }
        
        vector<Node> next=getNext(x,y,state,N,board);
        for(int i=0;i<next.size();++i){
            int nx=next[i].x,ny=next[i].y,ns=next[i].state;
            if(check[nx][ny][ns])
                continue;
            q.push(Node(nx,ny,ns,dist+1));
            check[nx][ny][ns]=true;
        }
    }
    return answer;
}