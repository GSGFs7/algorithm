// bitset 压位
#include <iostream>
#include <bitset>

using namespace std;

// bool类型只使用一个位但是占用一个字节，可以用bitset压位

int main()
{
    bool a[10000][10000];// 100MB -> 12MB
    bitset<10000> s;
    // 支持所有操作符
    /*
     * ~,&,|,^
     * >>,<<
     * ==,!=
     * []    // 取出某一位
     * count()   返回有多少个1
     * any()     是否至少有一个1
     * none()    判断是否全为0
     * set()     把所有位设置成1
     * set(k, v) 把第k位设置成v
     * reset()   把所有位设置成0
     * flip()    等价于~，取反
     * flip(k)   把第k位取反
     */
}