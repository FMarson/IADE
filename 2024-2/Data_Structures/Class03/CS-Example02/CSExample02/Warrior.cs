namespace CSExample02
{
    using System;
    public class Warrior : Character
    {
        // Additional attributes for Warrior
        public int Strength { get; set; }
        public string WeaponType { get; set; }

        // Constructor for Warrior
        public Warrior(string name, int hp, int level, int resistance, int strength, string weaponType)
            : base(name, hp, level, resistance)
        {
            Strength = strength;
            WeaponType = weaponType;
        }

        // Overridden Attack Method with Weapon
        public override void Attack(Character target, int baseDamage)
        {
            int totalDamage = baseDamage + Strength;
            Console.WriteLine($"{Name} is attacking {target.Name} with {totalDamage} damage using {WeaponType}.");
            target.Defend(totalDamage);
        }
    }
}