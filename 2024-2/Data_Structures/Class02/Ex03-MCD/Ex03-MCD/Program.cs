/*
Exercise 3: Maximum Common Divisor (MCD) Calculation

Statement:

In this exercise, you must implement a function that calculates the maximum common divisor (MCD) of two non-negative integers. The MCD of two numbers is the largest number that divides both without leaving a remainder. For example, the MCD of 8 and 12 is 4.

You need to implement the MCD calculation in three different ways:

1. Recursive: Implement a function that uses the Euclidean algorithm to calculate the MCD recursively.


2. Iterative: Implement a function that uses a loop to apply the Euclidean algorithm and calculate the MCD.


3. Free: Implement a function that calculates the MCD using another factorization method of two numbers.

Requirements:

- The function should handle invalid inputs (such as negative numbers or zero) by returning an appropriate error or message.
- Each implementation must monitor the time taken for execution and print this time at the end.
- Demonstrate the execution of all three implementations with practical examples using different pairs of numbers.

 */
using System.Diagnostics;
using System;

namespace Ex03_MCD
{
    internal class Program
    { 
        
    static void Main(string[] args)
    {
        long a = 48896545; // Example input for first number
        long b = 187840; // Example input for second number

        Console.WriteLine($"Calculating MCD of {a} and {b}...\n");

        // Recursive implementation
        Console.WriteLine("Recursive implementation:");
        MeasureExecutionTime(() => {
            Console.WriteLine($"Result: {MCDRecursive(a, b)}");
        });

        // Iterative implementation
        Console.WriteLine("\nIterative implementation:");
        MeasureExecutionTime(() => {
            Console.WriteLine($"Result: {MCDIterative(a, b)}");
        });

        // Factorization implementation
        Console.WriteLine("\nFactorization implementation:");
        MeasureExecutionTime(() => {
            Console.WriteLine($"Result: {MCDFactorization(a, b)}");
        });
    }

    static void MeasureExecutionTime(Action action)
    {
        Stopwatch stopwatch = new Stopwatch();
        stopwatch.Start();
        action();
        stopwatch.Stop();
        Console.WriteLine($"Time taken: {stopwatch.Elapsed.TotalMilliseconds} ms\n");
    }

    static long MCDRecursive(long a, long b)
    {
        if (a < 0 || b < 0) throw new ArgumentException("Input must be non-negative integers.");
        if (b == 0) return a;
        return MCDRecursive(b, a % b);
    }

    static long MCDIterative(long a, long b)
    {
        if (a < 0 || b < 0) throw new ArgumentException("Input must be non-negative integers.");
        while (b != 0)
        {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static long MCDFactorization(long a, long b)
    {
        if (a < 0 || b < 0) throw new ArgumentException("Input must be non-negative integers.");
        
        // Get factors of both numbers
        long mcd = 1;
        for (int i = 2; i <= Math.Min(a, b); i++)
        {
            while (a % i == 0 && b % i == 0)
            {
                mcd *= i;
                a /= i;
                b /= i;
            }
        }
        return mcd;
    }
}

    
}