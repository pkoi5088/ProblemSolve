#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<bool>> check;
    check.resize(m);
    for(int i=0;i<m;++i)
        check[i].resize(n,false);
    
    bool flag=true;
    while(flag){
        flag=false;
        //체크
        for(int i=0;i<m-1;++i){
            for(int j=0;j<n-1;++j){
                if(board[i][j]!='.'&&board[i][j]==board[i+1][j+1]&&board[i][j]==board[i][j+1]&&board[i][j]==board[i+1][j]){
                    check[i][j]=check[i+1][j+1]=check[i][j+1]=check[i+1][j]=true;
                }
            }
        }
        
        //블록 없애기
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(check[i][j]){
                    answer+=1;
                    board[i][j]='.';
                    check[i][j]=false;
                    flag=true;
                }
            }
        }
        
        for(int j=0;j<n;++j){
            for(int i=m-2;i>=0;--i){
                if(board[i][j]!='.'&&board[i+1][j]=='.'){
                    int x=i;
                    while(x<=m-2&&board[x][j]!='.'&&board[x+1][j]=='.'){
                        swap(board[x][j],board[x+1][j]);
                        x+=1;
                    }
                }
            }
        }
    }
    return answer;
}