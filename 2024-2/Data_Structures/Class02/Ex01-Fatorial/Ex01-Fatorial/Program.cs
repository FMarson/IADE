/*
Exercise 1: Factorial Calculation

Statement:

In this exercise, you must implement a function that calculates the factorial of a non-negative integer (n). The factorial of a number n is defined as the product of all positive integers from 1 to n, and is represented by n!. For example, 5! = 5 × 4 × 3 × 2 × 1 = 120.

You need to implement the factorial calculation in three different ways:

1. Recursive: Implement a function that calls itself to calculate the factorial.


2. Iterative: Implement a function that uses a loop to calculate the factorial.


3. Using Memoization: Implement a function that stores intermediate results to optimize the factorial calculation.

Requirements:

- The function should handle invalid inputs (negative numbers) by returning an appropriate error or message.
- Each implementation must monitor the time taken for execution and print this time at the end.
- Demonstrate the execution of all three implementations with a practical example.
 */
using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace Ex01_Fatorial {
    internal class Program {
        static void Main(string[] args)
        {
            int n = 15; // Example input

            Console.WriteLine($"Calculating factorial of {n}...\n");

            // Recursive implementation
            Console.WriteLine("Recursive implementation:");
            MeasureExecutionTime(() => {
                Console.WriteLine($"Result: {FactorialRecursive(n)}");
            });

            // Iterative implementation
            Console.WriteLine("\nIterative implementation:");
            MeasureExecutionTime(() => {
                Console.WriteLine($"Result: {FactorialIterative(n)}");
            });

            // Memoization implementation
            Console.WriteLine("\nMemoization implementation:");
            MeasureExecutionTime(() => {
                Console.WriteLine($"Result: {FactorialMemoization(n)}");
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

        static long FactorialRecursive(int n)
        {
            if (n < 0) throw new ArgumentException("Input must be a non-negative integer.");
            if (n == 0 || n == 1) return 1;
            return n * FactorialRecursive(n - 1);
        }

        static long FactorialIterative(int n)
        {
            if (n < 0) throw new ArgumentException("Input must be a non-negative integer.");
            long result = 1;
            for (int i = 2; i <= n; i++)
            {
                result *= i;
            }
            return result;
        }

        static Dictionary<int, long> memo = new Dictionary<int, long>();

        static long FactorialMemoization(int n)
        {
            if (n < 0) throw new ArgumentException("Input must be a non-negative integer.");
        
            if (n == 0 || n == 1) return 1;
        
            if (memo.ContainsKey(n)) return memo[n];

            memo[n] = n * FactorialMemoization(n - 1);
            return memo[n];
        }
    }
}
