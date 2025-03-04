using System.Numerics;

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
            int n = Convert.ToInt32(input[0]);
            int m = Convert.ToInt32(input[1]);

            BigInteger[][] a = new BigInteger[n][];
            for (int i = 0; i < n; i++)
            {
                a[i] = Array.ConvertAll(Console.ReadLine().Split(' '), BigInteger.Parse);
            }

            BigInteger[] b = new BigInteger[n]; // 前缀和
            for (int i = 0; i < n; i++)
            {
                b[i] = 0;
                for (int j = 0; j < m; j++)
                {
                    b[i] += a[i][j];
                }
            }

            Array.Sort(b);
            Array.Reverse(b);

            BigInteger ans = 0;
            for (int i = 0; i < n; i++)
            {
                ans += b[i] * (n - 1 - i) * m;

                for (int j = 0; j < m; j++)
                {
                    ans += a[i][j] * (m - j);
                }
            }
            Console.WriteLine(ans);
        }
    }
}