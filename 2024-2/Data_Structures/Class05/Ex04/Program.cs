class Program
{
    static void Main()
    {
        string input = "hello";
        string reversed = ReverseString(input);
        Console.WriteLine("Reversed string: " + reversed);
    }
	
	static string ReverseString(string str)
    {
       ReverseString(str, input.Length - 1);
    }

    static string ReverseString(string str, int index)
    {
        // Base case: if index is less than 0, return an empty string
        if (index < 0)
            return "";

        // Recursive case: return the character at the current index plus the rest
        return str[index] + ReverseString(str, index - 1);
    }
}
