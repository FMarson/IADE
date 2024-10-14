using System;

class Program
{
    static void Main()
    {
        int N = 4;
        int fact = factorial(N);
        Console.WriteLine("Factorial of " + N + ": " + fact);
    }

    static int factorial(int n)
    {
        if (n == 1)
            return 1;
        return n * factorial(n - 1);
    }
}