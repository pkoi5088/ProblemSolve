#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long& number:numbers){
        if(number%2==0)
            answer.push_back(number+1);
        else{
            long long xor1=number^(number+1);
            xor1+=1;
            xor1/=2;
            answer.push_back((number|xor1)^(xor1/2));
        }
    }
    return answer;
}