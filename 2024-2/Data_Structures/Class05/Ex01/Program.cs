using System;

class Program
{
    static void Main(){
        PrintNumbers(5);
    }

    static void PrintNumbers(int n)
    {
        Console.WriteLine(n);
        if (n > 0){
            PrintNumbers(n-1);
        }
    }
}