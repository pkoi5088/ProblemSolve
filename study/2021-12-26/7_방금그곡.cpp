#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/17683
*/

vector<string> parse(string s);
string delHash(string m);

class song{
  public:
    int start=0,end=0;
    string title,melody;
    
    song(vector<string> info){
        start=(info[0][0]-'0')*600+(info[0][1]-'0')*60+(info[0][3]-'0')*10+(info[0][4]-'0');
        end=(info[1][0]-'0')*600+(info[1][1]-'0')*60+(info[1][3]-'0')*10+(info[1][4]-'0');
        title=info[2];
        melody=delHash(info[3]);
    }
};

vector<string> parse(string s){
    vector<string> ret;
    string tmp;
    for(int i=0;i<s.size();++i){
        if(s[i]==','){
            ret.push_back(tmp);
            tmp.clear();
        }else{
            tmp.push_back(s[i]);
        }
    }
    ret.push_back(tmp);
    return ret;
}

string delHash(string m){
    string ret;
    for(int i=0;i<m.size();++i){
        if(m[i]=='#'){
            char nextChar;
            if(ret.back()=='C')
                nextChar='H';
            else if(ret.back()=='D')
                nextChar='I';
            else if(ret.back()=='F')
                nextChar='J';
            else if(ret.back()=='G')
                nextChar='K';
            else if(ret.back()=='A')
                nextChar='L';
            ret.pop_back();
            ret.push_back(nextChar);
        }else{
            ret.push_back(m[i]);
        }
    }
    return ret;
}

bool check(song s,string m){
    while(s.melody.size()<=s.end-s.start){
        s.melody+=s.melody;
    }
    s.melody=s.melody.substr(0,s.end-s.start);
    return s.melody.find(m)!=string::npos;
}

bool cmp(song s1,song s2){
    return (s1.end-s1.start)>(s2.end-s2.start);
}

string solution(string m, vector<string> musicinfos) {
    m=delHash(m);
    vector<song> v;
    for(int i=0;i<musicinfos.size();++i){
        vector<string> tmpv=parse(musicinfos[i]);
        v.push_back(song(tmpv));
    }
    sort(v.begin(),v.end(),cmp);
    for(song& s:v){
        if(check(s,m))
            return s.title;
    }
    return "(None)";
}