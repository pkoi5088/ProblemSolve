#include <string>
#include <vector>
#include <map>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/17684
*/

map<string,int> table;

string getMax(string msg) {
    string ret, tmp;
    for (int i = 0; i < msg.size(); ++i) {
        ret = tmp;
        tmp.push_back(msg[i]);
        if (table.find(tmp) == table.end())
            return ret;
    }
    ret = tmp;
    return ret;
}

vector<int> solution(string msg) {
    vector<int> answer;
    int cnt=27;
    for(string tmp="A";tmp[0]<='Z';++tmp[0])
        table[tmp]=tmp[0]-'A'+1;
    if(msg.size()==1){
        answer.push_back(table[msg]);
        return answer;
    }
    while(!msg.empty()){
        string maxStr=getMax(msg);
        msg.erase(0,maxStr.size());
        if(!msg.empty())
            table[maxStr+msg[0]]=cnt++;
        answer.push_back(table[maxStr]);
    }
    return answer;
}