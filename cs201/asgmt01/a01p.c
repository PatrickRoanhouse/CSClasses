// do not change this code except in the following ways:
//   * write code for the following functions:
//      * bigOrSmallEndian()
//      * getNextHexInt()
//      * printLinesForNumber()
//   * change studentName by changing "I. Forgot" to your actual name

#include <stdio.h>
#include <stdlib.h>

static char *studentName = "Ladinu Chandrasinghe";

// report whether machine is big or small endian
void bigOrSmallEndian()
{
  int  tst  = 0x42000041;
  char *p   = (char *) &tst;

  printf("byte order: ");

  if (0x41 == *p)
    printf("little-endian\n\n");

  else if (0x42 == *p)
    printf("big-endian\n\n");

  else
    printf("unknown\n\n");

  p = NULL;
}

// get next int (entered in hex) using scanf()
// returns 1 (success) or 0 (failure)
// if call succeeded, return int value via i pointer
int getNextHexInt(int *i)
{
    // replace this code with the call to scanf()
  return scanf("%x", i);
}

// print requested data for the given number
void printNumberData(int i)
{
  int signBit    = i & 0x80000000;  // Extract the first bit
  int expBits    = i & 0x7f800000;  // Extract the exponent bits
  int mantissa   = i & 0x007fffff;  // Extract the fractional bits

  expBits = expBits >> 23;          // Shifting by 23 will allow us to treat it like an integer

  if (signBit != 0)
    signBit = 1;

  printf("signBit %i, ", signBit);
  printf("expBits %3i, ", expBits);
  printf("fractBits 0x%08X\n", mantissa);

    // Check for zero
  if ( (expBits == 0) && (mantissa == 0) )
  {
    if (signBit == 0)
      printf("+zero\n");
    else
      printf("-zero\n");
  }
    // Denormalized values
  else if ( (expBits == 0) && (mantissa != 0) )
    printf("denormalized: exp = %3i\n", (1-127));

    // Normalized values
  else if ( (expBits != 0) && (expBits != 255) )
    printf("normalized:   exp = %3i\n", (expBits - 127));

    // Print infinity
  else if ( (expBits == 255) && (mantissa == 0) )
  {
    if (signBit == 0)
      printf("+infinity\n");
    else
      printf("-infinity\n");
  }
    // Print QNaN
  else if ( (expBits == 255) && (mantissa >= 0x00400000) )
    printf("QNaN\n");

    // Print SNaN
  else if ( (expBits == 255) && (mantissa >= 0x00200000) )
    printf("SNaN\n");
  
  else
    printf("[!] Error: Unexpected input\n");

  printf("\n");
}

// do not change this function in any way
int main(int argc, char **argv)
{
    int     i;                              // number currently being analyzed
    int     nValues;                        // number of values successfully parsed by scanf

    printf("CS201 - A01p - %s\n\n", studentName);
    bigOrSmallEndian();
    for (;;) {
        if (argc == 1)                      // allow grading script to control ...
            printf("> ");                   // ... whether prompt character is printed
        nValues = getNextHexInt(&i);
        printf("0x%08X\n", i);
        if (! nValues) {                    // encountered bad input
            printf("bad input\n");
            while (getchar() != '\n') ;     // flush bad line from input buffer
            continue;
            }
        printNumberData(i);
        if (i == 0)
            break;
        }
    printf("\n");
    return 0;
}
