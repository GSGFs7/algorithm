#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double p = (a+b+c)/2;

    double res = sqrt(p*(p-a)*(p-b)*(p-c));

    printf("%.1lf", res);
    return 0;
}

// Ϊʲô���ܶ�����ƽ����
// ���ݷ�Χ��r̫С�ˣ�

/*
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double p = (a+b+c) / 2;
    double k = p*(p-a)*(p-b)*(p-c);

    double l = 0, r = 1000;
    while (r - l > 0.001)
    {
        double mid = (l + r) / 2;
        if (mid * mid >= k) r = mid;
        else l = mid;
    }
    
    printf("%.1lf\n", l);
    return 0;
}
 */