#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Simiso and Aldo"
#define YEAR 2022
// Code was written by both Simiso Gwala (GWLSIM005) and Aldo Antonio (ANTALD001)

float log_a_to_base_b(int a, int b)
{
    /* This function takes converts log of base 2 values to log of any base with input (which is the decimal value in this project)*/
    return log2(a) / log2(b);
}

void Dec2RadixI(int decValue, int radValue)
{
    // This function will convert from decimal to any radix_i of 2 to 16
    // Conditional statement to convert from base 10 to base 2-10
    if(radValue<=10)
    {
        int i = 0;
        int res = 1;
        int rem = 0;
        long double dec_in = decValue;
        long double rad_in = radValue;
        int rev_array = 0;
        int info_bits;
        float logs = log_a_to_base_b(decValue, radValue) - ceil(log_a_to_base_b(decValue, radValue));

        /* This loop checks if the log of the decimal number is a whole number or not, and is
        adjusted for by adding 1 to ensure the correct number of bits for the conversion of the
        positive decimal number*/
        if(logs == 0)
        {
            info_bits = ceil(log_a_to_base_b(decValue, radValue));
            info_bits++;
        }
        else
        {
            info_bits = ceil(log_a_to_base_b(decValue, radValue));
        }

        // printf("%d", info_bits);
        char b[info_bits];

        // The while loop converts from decimal to user specified radix_i between 2 and 10, through successive division, and stores value in array from back to front
        while(res>0)
        {
            res = dec_in/rad_in - (dec_in/rad_in-floor(dec_in/rad_in));
            rem = ceil(((dec_in-rad_in*res)/rad_in)*rad_in);
            b[i] = rem;
            dec_in = res;
            i++;
        }

        // The for loop reverses the array the converted value is stored in
        for(int i = 0; i<(info_bits/2); i++)
        {
            rev_array = b[i];
            b[i] = b[info_bits - i - 1];
            b[info_bits - i - 1] = rev_array;
        }

        // Printing statment of the resulting conversion
        printf("The radix-%d value is {", radValue);
        for(int i = 0; i<info_bits; i++)
        {
                printf("%d", b[i]);
        }
        printf("}(BASE_%d)\n\n", radValue);
    }
    // Conditional statement to convert from base 10 to base 11 to 16
    else
    {
        int i = 0;
        int res = 1;
        int rem = 0;
        long double rem_alpha;
        long double dec_in = decValue;
        long double rad_in = radValue;
        int rev_array = 0;
        int info_bits;

        /* This loop checks if the log of the decimal number is a whole number or not, and is
        adjusted for by adding 1 to ensure the correct number of bits for the conversion of the
        positive decimal number*/
        float logs = log_a_to_base_b(decValue, radValue) - ceil(log_a_to_base_b(decValue, radValue));

        if(logs == 0)
        {
            info_bits = ceil(log_a_to_base_b(decValue, radValue));
            info_bits++;
        }
        else
        {
            info_bits = ceil(log_a_to_base_b(decValue, radValue));
        }

        // printf("%d", info_bits);
        char b[info_bits];

        // The while loop converts from decimal to user specified radix_i between 11 and 16, through successive division, and stores value in array from back to front
        while(res>0)
        {
            res = dec_in/rad_in - (dec_in/rad_in-floor(dec_in/rad_in));
            rem = ceil(((dec_in-rad_in*res)/rad_in)*rad_in);

            // The conditional statement checks if returned number is greater than 9, which then the correct alphabet is assigned to
            if(rem>9)
            {
               switch(rem)
                {
                    case 10:
                        rem = 'A';
                        break;
                    case 11:
                        rem = 'B';
                        break;
                    case 12:
                        rem = 'C';
                        break;
                    case 13:
                        rem = 'D';
                        break;
                    case 14:
                        rem = 'E';
                        break;
                    case 15:
                        rem = 'F';
                        break;
                    default:
                        break;
                }
                b[i] = rem;
                dec_in = res;
                i++;
            }
            else
            {
                b[i] = rem;
                dec_in = res;
                i++;
            }
        }

        // The for loop reverses the array the converted value is stored in
        for(int i = 0; i<(info_bits/2); i++)
        {
            rev_array = b[i];
            b[i] = b[info_bits - i - 1];
            b[info_bits - i - 1] = rev_array;
        }

        // Printing statment of the resulting conversion
        printf("The radix-%d value is {", radValue);
        for(int i = 0; i<info_bits; i++)
        {
            if(b[i] == 0 || b[i] == 1 || b[i] == 2 || b[i] == 3 || b[i] == 4 || b[i] == 5 || b[i] == 6 || b[i] == 7 || b[i] == 8 || b[i] == 9)
            {
                printf("%d", b[i]);
            }
            else
            {
                printf("%c", b[i]);
            }
        }
        printf("}(BASE_%d)\n\n", radValue);
    }
}

void main(void)
{
    /* The following lines display the header of the converter, displaying info of the title of the converter, the author's name and year developed*/
    printf("*****************************\n");
    printf("%s\n", TITLE);
    printf("Written by: %s\n", AUTHOR);
    printf("Date: %d\n", YEAR);
    printf("*****************************\n\n\n");

    int decValue = 10; // A number greater than 0 to initiate while loop

    while(decValue>=0)
    {
        // Ask user to enter a positive decimal integer
        printf("Enter positive decimal number: ");
        scanf("%d", &decValue);

        if(decValue<0)
        {
            printf("EXIT");
            break;
        }
        else
        {
            printf("The number you have entered is %d\n\n", decValue);

            // Ask user to enter a radix for the number system
            int rad;

            printf("Enter a radix for the converter between 2 and 16: ");
            scanf("%d", &rad);

            // While loop to check if entered radix value is between 2 and 16
            while(rad != "place_holder_for_while_loop_to_be_initiated")
            {
                if(rad<2)
                {
                    printf("Radix value must be between 2 and 16: ");
                    scanf("%d", &rad);
                }
                else if(rad>16)
                {
                    printf("Radix value must be between 2 and 16: ");
                    scanf("%d", &rad);
                }
                else
                {
                    break;
                }
            }

            if(decValue == 0)
            {
                /* Displays the radix valued entered along with Shannon's Theorem, integer division result and the remainder*/
                float log_value = log_a_to_base_b(decValue, 2);
                printf("The radix you have entered is %d\n", rad);
                printf("The log2 of the number is %0.2f\n\n",rad, log_value);
                printf("The integer result of the number divided by %d is %d\nThe remainder is %d\n\n", rad, decValue/rad, decValue%rad);
                printf("{0}(BASE_%d)\n\n", rad);
            }
            else
            {
                /* Displays the radix valued entered along with Shannon's Theorem, integer division result and the remainder*/
                float log_value = log_a_to_base_b(decValue, 2);
                printf("The radix you have entered is %d\n", rad);
                printf("The log2 of the number is %0.2f\n\n",rad, log_value);
                printf("The integer result of the number divided by %d is %d\nThe remainder is %d\n\n", rad, decValue/rad, decValue%rad);

                Dec2RadixI(decValue, rad);
            }
        }
    }
}
