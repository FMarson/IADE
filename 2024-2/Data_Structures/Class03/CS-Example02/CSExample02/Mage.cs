namespace CSExample02
{
    using System;
    public class Mage : Character
    {
        // Additional attributes for Mage
        public int Mp { get; set; }
        public string MagicType { get; set; }

        // Constructor for Mage
        public Mage(string name, int hp, int level, int resistance, int mp, string magicType)
            : base(name, hp, level, resistance)
        {
            Mp = mp;
            MagicType = magicType;
        }

        // Overridden Attack Method with Magic
        public override void Attack(Character target, int magicDamage)
        {
            if (Mp >= 10) // Assuming each magic attack costs 10 MP
            {
                Mp -= 10;
                Console.WriteLine($"{Name} is attacking {target.Name} with {magicDamage} magic damage using {MagicType}. Remaining MP: {Mp}");
                target.Defend(magicDamage);
            }
            else
            {
                Console.WriteLine($"{Name} does not have enough MP to cast a spell.");
            }
        }
    }
}