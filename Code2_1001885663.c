//Tuan Trinh 1001885663

#include <stdio.h>

#define BITS 8

void ConvertDecimalToBinary(int n1, char arr[])
{
    int temp[BITS] = {};
    for(int i = BITS-1; i >= 0; i--)
    {
        temp[i] = n1;
        n1 = n1>>1;        
    }
    for(int i = 0; i < BITS; i++)
    {
        arr[i] = (temp[i]&1) + 48;
    }
}

int main()
{
    int num1 = -1, num2 = -1;
    char sign[3] = {}, arr[BITS+1] = {};

    printf("\nBitwise Calculator\n\n");
    printf("Enter two base 10 values with a bitwise operator to see the decimal result\nand the binary result. The format is\n\n");
    printf("FirstNumber BitwiseOperator SecondNumber\n\n");
    printf("For example, enter the expression\n\n2 & 3\n\n");
    printf("This calculator can used with &, |, ^, << and >>\n\n");
    printf("Please note that the spaces between numbers and operator is essential\nand the two entered values must be between 0 and 255\n\n");
    
    while(sign, (num1 < 0 || num1 > 255) || (num2 < 0 || num2 > 255))
    {
        printf("Enter expression ");
        scanf("%d %s %d", &num1, sign, &num2);
        if((num1 < 0 || num1 > 255) || (num2 < 0 || num2 > 255))
        {
            printf("\nThe entered expression contains an out of range values.\nPlease reenter the expression using values between 0 and 255.\n\n");
        }
        else if(sign[0] == '^')
        {
            printf("\nIn base 10...\n\n");
            printf("%d %c %d = %d\n\n", num1, sign[0], num2, num1^num2);
            printf("\nIn %d-bit base 2...\n\n", BITS);
            ConvertDecimalToBinary(num1, arr);
            printf("  %s", arr);
            printf("\n%s\n", sign);
            ConvertDecimalToBinary(num2, arr);
            printf("  %s", arr);
            printf("\n  ========\n");
            ConvertDecimalToBinary(num1^num2, arr);
            printf("  %s", arr);
            printf("\n\n");
        }
        else if(sign[0] == '|')
        {
            printf("\nIn base 10...\n\n");
            printf("%d %c %d = %d\n\n", num1, sign[0], num2, num1|num2);
            printf("\nIn %d-bit base 2...\n\n", BITS);
            ConvertDecimalToBinary(num1, arr);
            printf("  %s", arr);
            printf("\n%s\n", sign);
            ConvertDecimalToBinary(num2, arr);
            printf("  %s", arr);
            printf("\n  ========\n");
            ConvertDecimalToBinary(num1|num2, arr);
            printf("  %s", arr);
            printf("\n\n");
        }
        else if(sign[0] == '&')
        {
            printf("\nIn base 10...\n\n");
            printf("%d %c %d = %d\n\n", num1, sign[0], num2, num1&num2);
            printf("\nIn %d-bit base 2...\n\n", BITS);
            ConvertDecimalToBinary(num1, arr);
            printf("  %s", arr);
            printf("\n%s\n", sign);
            ConvertDecimalToBinary(num2, arr);
            printf("  %s", arr);
            printf("\n  ========\n");
            ConvertDecimalToBinary(num1&num2, arr);
            printf("  %s", arr);
            printf("\n\n");
        }
        else if(sign[0] == '<')
        {
            printf("\nIn base 10...\n\n");
            printf("%d %c %d = %d\n\n", num1, sign[0], num2, num1<<num2);
            printf("\nIn %d-bit base 2...\n\n", BITS);
            ConvertDecimalToBinary(num1, arr);
            printf("  %s", arr);
            printf("  << %d\n", num2);
            ConvertDecimalToBinary(num1<<num2, arr);
            printf("  %s", arr);
            printf("\n\n");
        }
        else if(sign[0] == '>')
        {
            printf("\nIn base 10...\n\n");
            printf("%d %c %d = %d\n\n", num1, sign[0], num2, num1>>num2);
            printf("\nIn %d-bit base 2...\n\n", BITS);
            ConvertDecimalToBinary(num1, arr);
            printf("  %s", arr);
            printf("  >> %d\n", num2);
            ConvertDecimalToBinary(num1>>num2, arr);
            printf("  %s", arr);
            printf("\n\n");
        }
        else
        {
            printf("\nOperator %c is not supported by this calculator\n", sign[0]);
        }
    }
    return 0;
}