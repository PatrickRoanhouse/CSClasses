import java.util.Scanner;

public class TableDriver
{
  public static void main(String [] args)
  {
    int inputNumber;
    boolean validInt = false;
    Table table      = new Table();
    Scanner input    = new Scanner(System.in);

    table.displayIntro();

      // Keep asking for a number until a valid one has been entered
    while (!validInt)
    {
      System.out.print("Enter a number: ");
      inputNumber = input.nextInt();

      if ( table.setNumber(inputNumber) )
      {
        validInt = true;
      }
    }

    table.printTable();

  }
}
