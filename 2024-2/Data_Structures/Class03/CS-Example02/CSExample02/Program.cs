namespace CSExample02
{
    using System;
    public class Program
    {
        public static void Main()
        {
            // Create character instances
            Character hero = new Character("Hero", 100, 1, 10);
            Mage mage = new Mage("Mage", 80, 1, 5, 50, "Fireball");
            Warrior warrior = new Warrior("Warrior", 120, 1, 15, 20, "Sword");

            // Simulate attacks
            hero.Attack(mage, 20);
            mage.Attack(hero, 25);
            warrior.Attack(mage, 30);

            // Display final state of characters
            Console.WriteLine($"{hero.Name}: HP = {hero.Hp}");
            Console.WriteLine($"{mage.Name}: HP = {mage.Hp}, MP = {mage.Mp}");
            Console.WriteLine($"{warrior.Name}: HP = {warrior.Hp}, Strength = {warrior.Strength}");
        }
    }
}