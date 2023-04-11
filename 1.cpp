#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main()
{
    int n;
    cin >> n;
    int a, b;
    while (n--)
    {
        cin >> a >> b;
        v.push_back(a / b);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= v.front(); i++)
    {
        if ()
    }
}