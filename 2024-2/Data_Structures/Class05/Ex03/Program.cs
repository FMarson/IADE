using System;
class Program
{
    static void Main()
    {
        int N = 5;
        int sum = SumToN(N);
        Console.WriteLine("Sum from 1 to " + N + ": " + sum);
    }

    static int SumToN(int n)
    {
        if (n == 0)
            return 0;
        return n + SumToN(n - 1);
    }
}