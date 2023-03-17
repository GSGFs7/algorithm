#include <bits/stdc++.h>
using namespace std;

// trie�������ٴ洢�ַ������ϵ����ݽṹ
// һ���ַ�����һ����������ظ������ظ��Ĳ��ֲ�
// ��β�����ַ���һ�����

const int N = 1e5 + 10;
int son[N][26], cnt[N], idx;// �±���0�ĵ㣬���Ǹ��ڵ㣬���ǿսڵ�
char str[N];

void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)// c++���ַ���ĩβ��\0
    {
        int u = str[i] - 'a';// ӳ�䵽0-25
        if (!son[p][u]) son[p][u] = ++idx;// ���û�ж�Ӧ�Ķ��ӣ���ֱ�Ӵ���һ��
        p = son[p][u];
    }
    cnt[p]++;// �������ڵ㣬��ʾ�Ըýڵ��β�ĸ���
}

int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char op[2];
        cin >> op >> str;
        if (op[0] == 'I') insert(str);
        else cout << query(str) << endl;
    }
    return 0;
}

/* һά�ǽ�������������ͽ��֮��Ĺ�ϵ��˭��˭���ӣ����ڵڶ���ά�ȣ�����[0][1]=3, [0]��ʾ���ڵ㣬[1]��ʾ��
 * ��һ�����ӡ�b��,������ӵ��±���3�����������һ��[3][2]=8 ; ˵�����ڵ�Ķ��ӡ�b��Ҳ��һ�����ӡ�c����������ӵ���
 * �����8������������ȥ������һ���ַ���������һ�����][x][y], �����ܿ������ڵڼ��㣬ֻ��֪�������Ķ�����˭��*/