#include <stdio.h>

const int SUM = 1400;
const int A = 10;
const int B = 20;
const int C = 30;
const int N = 100;

int main(void)
{
    int input, flag = 0, maxC = 0, maxB = 0, maxA = 0;
    //Counting; how many of 10 or 20 or 30 do we have?
    do
    {
        scanf("%i", &input);
        if (input == A)
        {
            maxA++;
        }
        else if(input == B)
        {
            maxB++;
        }
        else if(input == C)
        {
            maxC++;
        }
        //IF none of above so its user mistake ...
        else
        {
            printf("ERROR, int must be 10 or 20 or 30\n");
            flag--;
        }
        flag++;
    }
    //Here in our problem N is 100 and is changeable
    while (flag != N);
    //Counter of ways
    int counter = 0;
    for(int c = 0; c * C <= SUM && c <= maxC; c++)
    {
        for(int b = 0; (b * B + c * C) <= SUM && b <= maxB; b++)
        {
            for(int a = 0; (a * A + b * B + c * C) <= SUM && a <= maxA; a++)
            {
                if ((a * A + b * B + c * C) == SUM)
                {
                    printf("nuber of 30s: %i nuber of 20s: %i number of 10s: %i\n", c, b, a);
                    counter++;
                    break;
                }
            }
        }
    }
    //In case we Can't sum these numbers to be 1400:
    if (counter == 0)
    {
        printf("CAN NOT Make 1400 with adding up these numbers.\n");
        return 1;
    }
    //
    printf("Number of ways: %i\n", counter);
    return 0;
}