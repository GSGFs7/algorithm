/*
给出两个数组a和b, 问在b中选取一个数减去a中的, 是否可以使a中的数非递减排序?

从第一个数开始每次都选取可以选取的最小的数, 如果这样还是不能满足条件就是不可以实现的.
数据范围很大, 需要二分.
明明这么简单的题, 写if else把自己写死了.
*/

namespace 你好
{
    class 你好
    {
        static void Main()
        {
            int T = Convert.ToInt32(Console.ReadLine());
            while (T-- > 0)
            {
                Function.Solve();
            }
        }
    }

    class Function
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            // int n = Convert.ToInt32(input[0]);
            // int m = Convert.ToInt32(input[1]);

            int[] a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int[] b = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

            Array.Sort(b);

            a[0] = Math.Min(b.First() - a[0], a[0]);
            for (int i = 1; i < a.Length; i++)
            {
                int index = BinarySearch(b, a[i] + a[i - 1]);
                int maxn = Math.Max(a[i], b[index] - a[i]);
                int minn = Math.Min(a[i], b[index] - a[i]);

                // 先选小的, 在选大的, 大的还是小就不行
                if (minn >= a[i - 1])
                {
                    a[i] = minn;
                }
                else if (maxn >= a[i - 1])
                {
                    a[i] = maxn;
                }
                else
                {
                    Console.WriteLine("NO");
                    return;
                }
            }

            Console.WriteLine("YES");
        }

        // 第一个大于或是等于的位置
        static int BinarySearch(int[] a, int target)
        {
            int l = 0, r = a.Length - 1;
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (a[mid] < target) l = mid + 1;
                else r = mid;
            }
            return l;
        }
    }
}