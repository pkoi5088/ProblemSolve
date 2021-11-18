#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[4][3][3][3];
vector<vector<string>> setIdx={
    {"-","cpp","java","python"},
    {"-","backend","frontend"},
    {"-","junior","senior"},
    {"-","chicken","pizza"}
};

vector<string> split(string str,char c){
    vector<string> ret;
    string tmp;
    for(int i=0;i<str.size();++i){
        if(str[i]==c){
            if(tmp!="and"){
                ret.push_back(tmp);
            }
            tmp.clear();
        }else{
            tmp.push_back(str[i]);
        }
    }
    ret.push_back(tmp);
    return ret;
}

void setIndex(int&a,int&b,int&c,int&d,vector<string>& q){
    for(a=0;q[0]!=setIdx[0][a];++a);
    for(b=0;q[1]!=setIdx[1][b];++b);
    for(c=0;q[2]!=setIdx[2][c];++c);
    for(d=0;q[3]!=setIdx[3][d];++d);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    //inputinfo
    for(int i=0;i<info.size();++i){
        vector<string> pinfo=split(info[i],' ');
        int a,b,c,d;
        setIndex(a,b,c,d,pinfo);
        for(int x=0;x<2;++x){
            for(int y=0;y<2;++y){
                for(int z=0;z<2;++z){
                    for(int w=0;w<2;++w){
                        v[x*a][y*b][z*c][w*d].push_back(stoi(pinfo[4]));
                    }
                }
            }
        }
    }
    
    for(int x=0;x<4;++x){
        for(int y=0;y<3;++y){
            for(int z=0;z<3;++z){
                for(int w=0;w<3;++w){
                    sort(v[x][y][z][w].begin(),v[x][y][z][w].end());
                }
            }
        }
    }
    
    //query
    for(int i=0;i<query.size();++i){
        vector<string> pquery=split(query[i],' ');
        int a,b,c,d;
        setIndex(a,b,c,d,pquery);
        answer.push_back(v[a][b][c][d].end()-lower_bound(v[a][b][c][d].begin(),v[a][b][c][d].end(),stoi(pquery[4])));
    }
    return answer;
}