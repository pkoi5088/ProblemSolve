#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer={0,0};
    for(int i=1;i<=2500;++i){
        for(int j=i;j<=2500;++j){
            if(i*j==yellow&&2*i+2*j+4==brown){
                answer[0]=j+2;
                answer[1]=i+2;
                return answer;
            }
        }
    }
}