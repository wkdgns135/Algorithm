#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <limits>

using namespace std;

vector<int> solution(vector<string> gems)
{
    unordered_set<string> kinds(gems.begin(), gems.end());
    const int need = (int)kinds.size();

    unordered_map<string, int> cnt;
    int have = 0;

    int bestLen = numeric_limits<int>::max();
    int bestL = 0, bestR = 0;

    int l = 0;
    for (int r = 0; r < (int)gems.size(); r++)
    {
        if (++cnt[gems[r]] == 1) have++;

        while (have == need && l <= r)
        {
            int len = r - l + 1;
            if (len < bestLen)
            {
                bestLen = len;
                bestL = l;
                bestR = r;
            }

            if (--cnt[gems[l]] == 0) have--;
            l++;
        }
    }

    return { bestL + 1, bestR + 1 };
}