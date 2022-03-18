#include <stdio.h>
#include<cs50.h>
#include <math.h>

// Amex has 15 digits, starts with 34 or 37
// Mastercard has 16 digits, starts with 51 52 53 54 55
// Visa has 13 or 16 digits, starts with 4
// Checksum even and odd placed digits
// If checksum last digit is 0, valid
// AMEX (371449635398431), MASTERCARD (2223016768739313), VISA (4012888888881881)

int main(void)
{   // Prompt user for number = n
    long n = get_long("Please enter your credit card number \n");
    // Check number has 13, 15, 16 digits, INVALID if no, make a while loop
    int i = 0;
    long cc = n;
    while (cc > 0)
    {   // Loop divide n then add to counter i to count digits in n
        cc = cc / 10;
        i++;
    }
    if (i == 13 || i == 15 || i == 16)
        { // Check sum if valid or not
            long ss = n / 10;
            int x = 0;
            // Checksum even start
            while (ss>0)
            {   // Sum even digits first, starting second-to-last (371449635398431)
                int digit1 = ss % 10;
                // Multiply even digits by 2, digit2
                int digit2 = digit1 * 2;
                // Add products %digits(digit3) together = x
                int digit3;
                if (digit2 >= 10)
                {
                    digit3 = (digit2 % 10) + 1;
                }
                else
                {
                    digit3 = digit2 % 10;
                }
                x += digit3;
                ss /= 100;
            }
            long ff = n;
            int y = 0;
            // Checksum odd start
            // Checksum odd digits = y
            while (ff>0)
            {
                int dygyt1 = ff % 10;
                y += dygyt1;
                ff /= 100;
            }
                long jj = n;
                int q = 0;
                // Digit counter for n
                while (jj > 0)
            {   // Loop divide n then add to counter j to count digits in n
                jj /= 10;
                q++;
            }
            // Add odd digits to x, x+y=z
            int z = (x + y) % 10;
            long hh = n;
            // Check if last digit of x+y is 0,valid / not 0, print INVALID (371449635398431)
            if (z == 0)
            {   // Valid, check for starting digits 34, 37 AMEX|| 51, 52, 53, 54, 55 MASTERCARD|| 4 VISA, else INVALID
                // Digits: 13 Visa, 15 Amex, 16 Visa or Mastercard
                // Visa
                if(q==13)
                {
                    if(hh/1000000000000 == 4)
                    {
                        printf("VISA\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }
                // Amex
                else if (q==15)
                {
                    if (hh/10000000000000 == 34 || hh/10000000000000 == 37)
                    {
                        printf("AMEX\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }
                // Mastercard or Visa
                else if (q==16)
                {
                    if (hh/100000000000000 == 51 || hh/100000000000000 == 52|| hh/100000000000000 == 53|| hh/100000000000000 == 54|| hh/100000000000000 == 55)
                    {
                        printf("MASTERCARD\n");
                    }
                    else if (hh/1000000000000000 == 4)
                    {
                        printf("VISA\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
            // Output: Print AMEX VISA MASTERCARD INVALID
        }
    else
    {
        printf("INVALID\n");
    }
}