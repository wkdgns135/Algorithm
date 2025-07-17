#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    while(k--){
        auto iter = number.begin();
        for(iter; iter != number.end(); iter++){
            if(*iter < *next(iter)){
                number.erase(iter);
                break;
            }
        }
        if(iter == number.end()) number.erase(min_element(number.begin(), number.end()));
    }
    return number;
}