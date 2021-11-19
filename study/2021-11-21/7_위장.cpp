#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> idxTable;
    vector<int> count;
    for(int i=0;i<clothes.size();++i){
        string a=clothes[i][0],b=clothes[i][1];
        if(idxTable.find(b)==idxTable.end()){
            idxTable[b]=count.size();
            count.push_back(1);
        }else{
            count[idxTable[b]]+=1;
        }
    }
    
    for(int i=0;i<count.size();++i){
        answer*=count[i]+1;
    }
    return answer-1;
}