using System;
using LinkedList;

class Program
{
    static void Main(string[] args)
    {
        DoublyLinkedList<int> list = new DoublyLinkedList<int>();
        list.AddLast(10);
        list.AddLast(20);
        list.AddLast(30);

        Console.WriteLine("List:");
        list.PrintForward();

        Console.ReadLine();
    }
}