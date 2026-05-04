#include <string>
#include <vector>

using namespace std;

int time_to_int(const string& time)
{
    int result = 0;
    result += stoi(time.substr(0, 2)) * 3600;
    result += stoi(time.substr(3, 2)) * 60;
    result += stoi(time.substr(6, 2));
    return result;
}

string int_to_time(int time)
{
    string result = "";
    result += time / 3600 >= 10 ? to_string(time / 3600) : "0" + to_string(time / 3600);
    time %= 3600;
    result += ":";
    result += time / 60 >= 10 ? to_string(time / 60) : "0" + to_string(time / 60);
    time %= 60;
    result += ":";
    result += time >= 10 ? to_string(time) : "0" + to_string(time);
    return result;
}

string solution(string play_time, string adv_time, vector<string> logs)
{
    string answer = "";
    int int_play_time = time_to_int(play_time);
    int int_adv_time = time_to_int(adv_time);

    vector<int> time_table(int_play_time + 2);

    for (const string& log : logs)
    {
        int left = time_to_int(log.substr(0, 8));
        int right = time_to_int(log.substr(9));
        time_table[left]++;
        time_table[right]--;
    }

    int count = 0;
    for (int i = 0; i <= int_play_time; i++)
    {
        count += time_table[i];
        time_table[i] = count;
    }
    
    int max_time = 0;
    long long sum = 0, max_sum;
    
    for(int i = 0; i < int_adv_time; i++){
        sum += time_table[i];
    }
    
    max_sum = sum;
    
    for(int i = int_adv_time; i <= int_play_time; i++){
        sum += time_table[i];
        sum -= time_table[i - int_adv_time];
        if(max_sum < sum){
            max_sum = sum;
            max_time = i - int_adv_time + 1;
        }
    }
    
    return int_to_time(max_time);
}