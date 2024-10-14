using System;

class Program
{
    static void Main()
    {
        int N = 7;
        int pellNumber = PellNumber(N);
        Console.WriteLine("Pell number at position " + N + ": " + pellNumber);
    }

    static int PellNumber(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        return 2 * PellNumber(n - 1) + PellNumber(n - 2);
    }
}