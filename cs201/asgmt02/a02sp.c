// starter file for Assignment 02sp

#include <stdio.h>
#include <stdlib.h>

#define PRECISION   3

// you can define new functions between this comment ...

// ... and this comment. If the new functions are called from powD,
// they must be coded in assembly language.

double powD(double n, double exp)
{
// do not change anything above this comment

    // Bools
    typedef enum {true = 1, false = 0} bool;

    unsigned long long nan           =   32760;
    unsigned long long negativeZero  =   1;  
    unsigned long long positiveInf   =   2047;
    unsigned long long negativeInf   =   4095;
    
    negativeZero    =  negativeZero  << 63;
    nan             =  nan           << 48;
    positiveInf     =  positiveInf   << 52;
    negativeInf     =  negativeInf   << 52;

    double power;

      // FPU specific vars
    int controllWord;
    int roundMode   = 3 << 10;

    // Make an absolute value copy of the base
    double nAbs;

    if ( n < 0)
      nAbs = (-1.0)*(n);
    else
      nAbs = n;


    // Check if the base and/or exponent is a NaN
    bool isExpNaN  = false;
    bool isBaseNaN = false;

    if (exp != exp)   // This is because NaN is not equal to anything (including it self).
      isExpNaN  = true;

    if (n != n)
      isBaseNaN = true;


    // Check for +/- infinity of base and exp
    bool isBasePositiveInf = false;
    bool isExpPositiveInf  = false;

    bool isBaseNegativeInf = false;
    bool isExpNegativeInf  = false;

    if ( (n == n) && ( (n-n) != 0.0 ) )
    {
      if (n > 0)
        isBasePositiveInf = true;
      else
        isBaseNegativeInf = true;
    }

    if ( (exp == exp) && ( (exp - exp) != 0 ) )
    {
      if (exp > 0)
        isExpPositiveInf = true;
      else
        isExpNegativeInf = true;
    }

    // Check if exponent is odd/even
    bool isExpOdd  = false;
    bool isExpEven = false;
    double remainder;
    
    asm("fld1                          \n"        // Compute base mod 2 --> (base % 2) = rem
        "fld1                          \n"
        "faddp                         \n"
        "fldl               %[base]    \n"
        "fprem                         \n"
        "fstpl              %[rem]     \n"
        "ffree              %%st       \n"
    
    :[rem] "=m" (remainder)
    :[base] "m" (exp)
    :"eax");

    if (remainder == 0.0)
      isExpEven = true;

    if ( (remainder == -1.0) || (remainder == 1.0) )
      isExpOdd  = true;


    // Check for special values 
    if (isExpNaN || isBaseNaN)
      power = *(double*)&nan;                                               // Output NaN

    else if ( (n == 1.0) || (exp == 0.0) )
      power = 1.0;                                                          // Output 1

    else if ( (n == 0.0) && (exp > 0) )
      power = 0.0;                                                          // Output 0

    else if ( (n == 0.0) && (exp < 0) )
      power = *(double*)&positiveInf;                                       // Output +inf

    else if ( (n == -1.0) && (isBaseNegativeInf || isBasePositiveInf) )
      power = 1.0;                                                          // Output 1

    else if ( (nAbs < 1) && isExpNegativeInf)
      power = *(double*)&positiveInf;                                       // Output +inf

    else if ( (nAbs > 1) && isExpNegativeInf)
      power = 0.0;                                                          // Output 0

    else if ( (nAbs < 1) && isExpPositiveInf)
      power = 0.0;                                                          // Output 0

    else if ( (nAbs > 1) && isExpPositiveInf)
      power = *(double*)&positiveInf;                                       // Output +inf

    else if (isBaseNegativeInf && (exp < 0) && (!isExpEven))
      power = *(double*)&negativeZero;                                      // Output -0

    else if (isBaseNegativeInf && (exp < 0) && isExpEven)
      power = 0.0;                                                          // Output 0

    else if (isBaseNegativeInf && (exp > 0) && (!isExpEven))
      power = *(double*)&negativeInf;                                       // Output -inf

    else if (isBaseNegativeInf && (exp > 0) && isExpEven)
      power = *(double*)&positiveInf;                                       // Output +inf

    else if (isBasePositiveInf && (exp < 0))
      power = 0.0;                                                          // Output 0

    else if (isBasePositiveInf && (exp > 0))
      power = *(double*)&positiveInf;                                       // Output +inf

    else
    {
      // Handle cases in which negative bases are raised to whole numbers
      bool changeSign = false;

      if ( (n < 0) && isExpOdd)
      {
        n          = nAbs;
        changeSign = true;
      }

      else if ( (n < 0) && isExpEven)
        n = nAbs;

      // Compute the power: n^exp = power
      
      asm(  " fldl      %[exp_in]                  \n"    // Push fltn into st0
            " fldl      %[base_in]                  \n"    // Duplicate fltn
            
            // Take st1*ln2(st0) -> st1 -> st0
            " fyl2x                                 \n"
            
            // Set FPU CW to round to zero
            " fstcw     %[cw_in]                    \n"    // Store FPU cw in cw
            " mov       %[cw_in],     %%eax         \n"
            " or        %[rndMode_in], %%eax        \n"
            " mov       %%eax, %[rndMode_in]        \n"
            " fldcw     %[rndMode_in]               \n"
            
            // Get integral part of st0
            " fld       %%st                        \n"
            " frndint                               \n"
            
            // Reset FPU CW to original setting
            " fldcw     %[cw_in]                    \n"
            
            // Get the frational part of st
            " fsubr     %%st, %%st(1)               \n"
            
            // Now we have integrand in st0 and fractional part in st1
            // Raise 2 to the integrand (2^st0)
            " fld1                                  \n"  // Push "1" to st0
            " fscale                                \n"  // st0 * 2^(st1) 
            
            // Push the fractional part to st0
            " fld       %%st(2)                     \n"
            
            // Raise 2 to the fractional part minus 1 (2^st(0)-1)
            " f2xm1                                 \n"
            
            // Add 1 to st0
            " fld1                                  \n"
            " faddp     %%st, %%st(1)               \n"
            
            // Multiply st0 and st1
            " fmulp     %%st, %%st(1)               \n"
            " fstpl     %[power]                    \n"
            :
            [exp_out]     "=m" (exp) ,            // Outputs
            [cw_out]      "=m" (controllWord),
            [power]       "=m" (power),
            [rndMode_out] "=m" (roundMode)
            :
            [exp_in]      "m"  (exp) ,           // Inputs
            [base_in]     "m"  (n) ,
            [cw_in]       "m"  (controllWord),
            [rndMode_in]  "m" (roundMode)
            
            : "eax"                             // clobers
            );
            
      if (changeSign)
        power = (-1.0)*power;
    }

    return power;

// do not change anything below this comment, except for printing out your name
}

int main(int argc, char **argv)
{
    double  n = 0.0;
    double  exp = 0.0;

    printf("CS201 - Assignment 02sp - Ladinu Chandrasinghe\n");
    if (argc > 1)
        n = atof(argv[1]);
    if (argc > 2)
        exp = atof(argv[2]);

    printf("%.*f to the %.*f = %.*f\n",
           PRECISION, n, PRECISION, exp, PRECISION, powD(n, exp));

    return 0;
}
