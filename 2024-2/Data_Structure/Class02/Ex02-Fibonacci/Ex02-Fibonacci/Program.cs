/*
Exercise 2: Fibonacci Sequence Calculation

Statement:

In this exercise, you must implement a function that calculates the n-th number in the Fibonacci sequence. The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones, starting with 0 and 1. The first numbers in the sequence are: 0, 1, 1, 2, 3, 5, 8, 13, ...

You need to implement the calculation of the n-th Fibonacci number in three different ways:

1. Recursive: Implement a function that calls itself to calculate the Fibonacci number.


2. Iterative: Implement a function that uses a loop to calculate the Fibonacci number.


3. Using Memoization: Implement a function that stores intermediate results to optimize the calculation of Fibonacci numbers.

Requirements:

- The function should handle invalid inputs (negative numbers) by returning an appropriate error or message.
- Each implementation must monitor the time taken for execution and print this time at the end.
- Demonstrate the execution of all three implementations with a practical example.
 */

using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace Ex02_Fibonacci
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = 10; // Example input for Fibonacci calculation

            Console.WriteLine($"Calculating the {n}-th Fibonacci number...\n");

            // Recursive implementation
            Console.WriteLine("Recursive implementation:");
            MeasureExecutionTime(() => { Console.WriteLine($"Result: {FibonacciRecursive(n)}"); });

            // Iterative implementation
            Console.WriteLine("\nIterative implementation:");
            MeasureExecutionTime(() => { Console.WriteLine($"Result: {FibonacciIterative(n)}"); });

            // Memoization implementation
            Console.WriteLine("\nMemoization implementation:");
            MeasureExecutionTime(() => { Console.WriteLine($"Result: {FibonacciMemoization(n)}"); });
        }

        static void MeasureExecutionTime(Action action)
        {
            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();
            action();
            stopwatch.Stop();
            Console.WriteLine($"Time taken: {stopwatch.Elapsed.TotalMilliseconds} ms\n");
        }

        static long FibonacciRecursive(int n)
        {
            if (n < 0) throw new ArgumentException("Input must be a non-negative integer.");
            if (n == 0) return 0;
            if (n == 1) return 1;
            return FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
        }

        static long FibonacciIterative(int n)
        {
            if (n < 0) throw new ArgumentException("Input must be a non-negative integer.");
            if (n == 0) return 0;
            if (n == 1) return 1;

            long a = 0, b = 1, temp = 0;
            for (int i = 2; i <= n; i++)
            {
                temp = a + b;
                a = b;
                b = temp;
            }

            return b;
        }

        static Dictionary<int, long> memo = new Dictionary<int, long>();

        static long FibonacciMemoization(int n)
        {
            if (n < 0) throw new ArgumentException("Input must be a non-negative integer.");

            if (n == 0) return 0;
            if (n == 1) return 1;

            if (memo.ContainsKey(n)) return memo[n];

            memo[n] = FibonacciMemoization(n - 1) + FibonacciMemoization(n - 2);
            return memo[n];
        }
    }
}