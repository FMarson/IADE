using System;

class Program
{
    static void Main()
    {
        int N = 10;
        int tetranacci = Tetranacci(N);
        Console.WriteLine("Tetranacci number at position " + N + ": " + tetranacci);
    }

    static int Tetranacci(int n)
    {
        if (n == 0 || n == 1 || n == 2)
            return 0;
        if (n == 3)
            return 1;
        return Tetranacci(n - 1) + Tetranacci(n - 2) + Tetranacci(n - 3) + Tetranacci(n - 4);
    }
}