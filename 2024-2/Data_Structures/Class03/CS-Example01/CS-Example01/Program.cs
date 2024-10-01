using System;
namespace CS_Example01 {
    class Program
    {
        public static void Main(string[] args)
        {
            Person person = new Person();
            person.Name = "Fernando";
            person.Age = 49;
            person.Address = "123 Flower Street";
            Console.WriteLine("Name: " + person.Name);

            person.Introduce();
            person.Birthday();
        }
        }
    }