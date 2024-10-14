using System;

class Program
{
    static void Main()
    {
        int N = 3;
        int sumOfCubes = SumOfCubes(N);
        Console.WriteLine("Sum of cubes up to " + N + ": " + sumOfCubes);
    }

    static int SumOfCubes(int n)
    {
        if (n == 0)
            return 0;
        return (n * n * n) + SumOfCubes(n - 1);
    }
}