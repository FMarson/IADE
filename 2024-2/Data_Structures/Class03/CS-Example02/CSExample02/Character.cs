namespace CSExample02
{
    using System;
    public class Character
    {
        // Attributes
        public int Hp { get; set; }
        public int Level { get; set; }
        public int Resistance { get; set; }
        public string Name { get; set; }

        // Constructor
        public Character(string name, int hp, int level, int resistance)
        {
            Name = name;
            Hp = hp;
            Level = level;
            Resistance = resistance;
        }

        // Attack Method
        public virtual void Attack(Character target, int damage)
        {
            Console.WriteLine($"{Name} is attacking {target.Name} with {damage} damage.");
            target.Defend(damage);
        }

        // Defend Method
        public void Defend(int damage)
        {
            int damageReceived = Math.Max(0, damage - Resistance);
            Hp = Math.Max(0, Hp - damageReceived);
            Console.WriteLine($"{Name} defended and received {damageReceived} damage. Remaining HP: {Hp}");
        }
    }
}