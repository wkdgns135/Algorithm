#include <bits/stdc++.h>
using namespace std;


bool isPossible(const vector<int>& lectures, int size, int m)
{
    int count = 1;
    int sum = 0;

    for (int lecture : lectures)
    {
        if (lecture > size) return false;

        if (sum + lecture > size)
        {
            count++;
            sum = lecture;
        }
        else
        {
            sum += lecture;
        }
    }

    return count <= m;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;

    vector<int> lectures(n);
    int sum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> lectures[i];
        sum += lectures[i];
        maxLength = max(maxLength, lectures[i]);
    }

    int left = maxLength; 
    int right = sum; 
    int result = right; 

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (isPossible(lectures, mid, m))
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << result;
    return 0;
}