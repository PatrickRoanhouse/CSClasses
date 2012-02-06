public class Table
{
    // Constructor
  public Table()
  {
    number = 0;
  }


/**
  * Prints a multiplication table using data member 'number'
*/
  public void printTable()
  {
      // Print the header row
    System.out.format("%4s", " "); // Shift header by one space to the right
    for (int n=0; n <= number; n++)
    {
      System.out.format("%4d", n);
    }
    System.out.format("%n");

      // Compute values and print the table
    for (int i=0; i <= number; i++)
    {
      System.out.format("%4d", i);
      for (int k=0; k <= number; k++)
      {
        System.out.format("%4d", k*i);
      }

      System.out.format("%n");
    }
  }
  
/**
  * Checks for valid integer before retaining that value
  * Returns true if integer is valid and false if invalid
*/
  public boolean setNumber(int num)
  {
    if (num <= 12 && num >= 4)
    {
      number = num;
      return true;
    }
    else
    {
      System.out.println("[!] Number must be in between 4 and 12 inclusive");
      return false;
    }
  }

/**
  * Simply display the introduction to std out
*/

  public void displayIntro()
  {
    System.out.println("***Welcome to Multiplication Table Generator***");
    System.out.println("You can enter a number between 4 and 12 (inclusive)");
  }

  private int number;
}
