#include <iostream>
#include <vector>
using namespace std;

void update(vector<int> & tree, int index, int value)
{
    int const n = tree.size();
    while (index < n)
    {
        tree[index] += value;
        index += (index & -index);
    }
}

int query(const vector<int>& tree, int index)
{
    int sum = 0;
    while (index > 0)
    {
        sum += tree[index];
        index -= (index & -index);
    }
    return sum;
}

vector<int> build(vector<int>& num)
{
    int const n = num.size();
    vector<int> tree(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        update(tree, i + 1, num[i]);
    }
    return tree;
}

int cases = 0;

void solve()
{
    cout << "Case " << ++ cases << ':' << endl;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> tree = build(a);

    while (true)
    {
        string op;
        cin >> op;
        int x, y;
        if (op == "Add")
        {
            cin >> x >> y;
            update(tree, x, y);
        }
        else if (op == "Sub")
        {
            cin >> x >> y;
            update(tree, x, -y);
        }
        else if (op == "Query")
        {
            cin >> x >> y;
            cout << query(tree, y) - query(tree, x - 1) << endl;
        }
        else if (op == "End") break;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}