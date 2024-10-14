using System;

class Program
{
    static void Main()
    {
        int[] arr = { 1, 2, 3, 4, 5 };
        int sum = SumArray(arr, 0);
        Console.WriteLine("Sum of array elements: " + sum);
    }

    static int SumArray(int[] arr, int index)
    {
        if (index == arr.Length)
            return 0;
        return arr[index] + SumArray(arr, index + 1);
    }
}