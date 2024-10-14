using System;

class Program
{
    static void Main()
    {
        int n = 4;
        int sf = superFactorial(n);
        Console.WriteLine("Superfactorial of " + n + ": " + sf);
    }

    static int superFactorial(int n)
    {
        if (n == 1)
            return 1;
        return factorial(n) * superFactorial(n - 1);
    }

    static int factorial(int n)
    {
        if (n == 1)
            return 1;
        return n * Factorial(n - 1);
    }
}