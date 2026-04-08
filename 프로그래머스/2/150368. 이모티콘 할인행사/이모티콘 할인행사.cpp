#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> users;
vector<int> answer, emoticons, temp;
static constexpr int discounts[4] = {10, 20, 30, 40};

void bt(int depth)
{
    if (depth == emoticons.size())
    {
        int maxCount = 0, maxPrice = 0;
        for (auto& user : users)
        {
            int discount = user[0], price = user[1];
            int sum = 0;
            for (int i = 0; i < temp.size(); i++)
            {
                if (temp[i] >= discount)
                {
                    float x = (1 - temp[i] * 0.01);
                    sum += emoticons[i] * x;
                }
            }
            if (sum >= price) maxCount++;
            else maxPrice += sum;
        }

        if (answer[0] == maxCount && answer[1] < maxPrice) answer[1] = maxPrice;
        else if (answer[0] < maxCount) answer[0] = maxCount, answer[1] = maxPrice;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        temp[depth] = discounts[i];
        bt(depth + 1);
    }
}

vector<int> solution(vector<vector<int>> in_users, vector<int> in_emoticons)
{
    users = move(in_users);
    emoticons = move(in_emoticons);
    temp.resize(emoticons.size());
    answer.resize(2);
    bt(0);

    return answer;
}