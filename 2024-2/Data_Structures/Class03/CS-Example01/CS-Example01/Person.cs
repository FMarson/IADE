using System;
namespace CS_Example01
{
    public class Person
    {
        // Attributes defined as private
        private string name;
        private int age;
        private string address;

        // Getters and Setters
        public string Name
        {
            get { return name; }
            //set { name = value; }
        }

        public int Age
        {
            get { return age; }
            set { age = value; }
        }

        public string Address
        {
            get { return address; }
            set { address = value; }
        }

        // Methods
        public void Introduce()
        {
            Console.WriteLine($"Hello, my name is {name}, I am {age} years old and I live at {address}.");
        }

        public void Birthday()
        {
            age++;
            Console.WriteLine($"Happy birthday, {name}! Now you are {age} years old.");
        }
    }
}