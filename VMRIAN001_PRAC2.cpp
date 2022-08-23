#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

//Conversion function
char* Dec2RadixI(int decValue, int radValue)
{
    char arrRad[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};         //array with hexadecimal digits
    int log;                                             //log2 of the decimal number gives the size of the converted digit
    log = ceil(log2(decValue));
    char arrH[log];                                      //temp array arrH is initialized and swooped arr arrSwoop
    char str[log];
    char arrSwoop[log];

    int i,qi,ri,di,c,k;                                  //integer values initialized
    i = 0;

    //WHILE loop starting
    di = decValue;                                       //temp decimal value
    while (di>0)
    {
        qi = trunc(di/radValue);                         //decimal value divided by radx value
        ri = di%radValue;                                //remainder is first digited
        arrH[i]= arrRad[ri];                             //associated hexadecimal digit stored in temp array
        di = qi;                                         //new temp value
        i = i+1;                                         //counter incremented
    }
    //end of WHILE loop

    k = 0;                                                //new counter for second loop

    //FOR loop runs from i-1 to zero
    for (int (c = i-1); c>-1; c--)
    {
       arrSwoop[k] = arrH[c];                            //last digit of arrH becomes first digit of arrSwoop

       k = k + 1;                                          //counter incremented
    }
    //end of FOR loop

    //Cannot print array, converting array to string and printing
    arrSwoop[k] = '\0';
    strcpy(str,arrSwoop);
    printf("The radix-%d value is %s\n",radValue, str);


    return 0;                                           //no value returned

}

//main function
int main()
{
    int num , radx , rem, div;                         //variables initialized
    float log;                                         //variable log is a float value.

    //defining constants
    #define TITLE "DECIMAL TO RADIX-i converter"
    #define AUTHOR "Ian van der Merwe"
    #define YEAR "2022"


    //printing header
    printf("*****************************\n");
    printf("%s\n",TITLE);
    printf("Written by: %s \n", AUTHOR);
    printf("Date: %s\n",YEAR);
    printf("*****************************\n");

    //initializing first input
    printf("Enter a decimal number: ");
    scanf("%d",&num);

   //WHILE loop - checks if the value input is > 0, if not loop is exited
    while (num >=0)
    {
        if (num>0)
        {
        //radx number is input and the num and radix is printed
        printf("The decimal number you have entered is %d \n", num);
        printf("Enter a radix for the conversion between 2 and 16: ");
        scanf("%d",&radx);
        printf("The radix you have entered is %d \n", radx);

        //calculations done and results printed
        log = log2(num);
        div = num/radx;
        rem = num%radx;
        printf("The log2 of the number is %4.2f \n",log);
        printf("The integer result of the number divided by %d is %d\n",radx,div);
        printf("The remainder is %d\n",rem);

        //function is called, two inputs included for calculations
        Dec2RadixI(num,radx);
        }

        else
        {
        printf("The decimal number you have entered is %d \n", num);
        printf("Enter a radix for the conversion between 2 and 16: ");
        scanf("%d",&radx);
        printf("The radix you have entered is %d \n", radx);

        //calculations done and results printed
        log = log2(num);
        div = num/radx;
        rem = num%radx;

        printf("The log2 of the number is %4.2f \n",log);
        printf("The integer result of the number divided by %d is %d\n",radx,div);
        printf("The remainder is %d\n",rem);
        printf("The radix-%d value is 0\n",radx);
        }

        //new decimal number is input and loop repeats
        printf("Enter a decimal number: ");
        scanf("%d",&num);
    } 
        //end of WHILE loop

    printf("EXIT");                                                
        //terminate program

}
