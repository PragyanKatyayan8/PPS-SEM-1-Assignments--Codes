#include <stdio.h>

int main()
{
    double a, b, result;
    char op;

    while (1)
    {
        printf("\nEnter first number: ");

        if (scanf("%lf", &a) != 1)
        {
            printf("Error: Enter a valid number!\n");
            return 0;
        }

        printf("Enter second number: ");

        if (scanf("%lf", &b) != 1)
        {
            printf("Error: Enter a valid number!\n");
            return 0;
        }

        printf("\nSelect operation:\n");
        printf("+  Addition\n");
        printf("-  Subtraction\n");
        printf("*  Multiplication\n");
        printf("/  Division\n");
        printf("x  Exit\n");

        printf("Enter your choice: ");
        scanf(" %c", &op);

        switch (op)
        {
            case '+':
                result = a + b;
                printf("Result = %.10g\n", result);
                break;

            case '-':
                result = a - b;
                printf("Result = %.10g\n", result);
                break;

            case '*':
                result = a * b;
                printf("Result = %.10g\n", result);
                break;

            case '/':
                if (b != 0)
                {
                    result = a / b;
                    printf("Result = %.10g\n", result);
                }
                else
                {
                    printf("Error: Cannot divide by zero.\n");
                }
                break;

            case 'x':
                printf("Operation Ended\n");
                return 0;

            default:
                printf("Error: Invalid operation!\n");
        }
    }

    return 0;
}