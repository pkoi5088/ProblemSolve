#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long& number:numbers){
        if(number%2==0)
            answer.push_back(number+1);
        else{
            long long x=(number^(number+1))+1;
            answer.push_back(number+x/4);
        }
    }
    return answer;
}