using System;

class Program
{
    static void Main()
    {
        int num = 123;
        int sumOfDigits = SumOfDigits(num);
        Console.WriteLine("Sum of digits of " + num + ": " + sumOfDigits);
    }

    static int SumOfDigits(int num)
    {
        if (num == 0)
            return 0;
        return (num % 10) + SumOfDigits(num / 10);
    }
}