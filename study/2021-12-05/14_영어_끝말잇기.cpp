#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> table;
    int idx=0,count=1;
    while(true){
        for(int i=1;i<=n;++i){
            if(idx>=words.size()||(idx>0&&words[idx-1].back()!=words[idx][0])||table.find(words[idx])!=table.end()){
                if(idx==words.size()){
                    answer.push_back(0);
                    answer.push_back(0);
                    return answer;
                }
                answer.push_back(i);
                answer.push_back(count);
                return answer;
            }
            table.insert(words[idx++]);
        }
        count+=1;
    }    
}