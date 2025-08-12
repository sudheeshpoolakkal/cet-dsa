#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int top = -1, max;

/* Stack operations */
void push(int stack[], int element);
int pop(int stack[]);
int isEmpty();
int isFull();
int peek(int stack[]);

/* Postfix evaluation functions */
int evaluatePostfix(char* expression);
int isOperator(char c);
int performOperation(int operand1, int operand2, char operator);

int main()
{
    char expression[100];

    printf("=== Postfix Expression Evaluator ===\n");
    printf("Enter the maximum size for the stack: ");
    if (scanf("%d", &max) != 1 || max <= 0) {
        printf("Invalid stack size.\n");
        return 1;
    }

    printf("\nEnter a postfix expression: ");
    scanf(" %[^\n]", expression); /* Read entire line including spaces */

    int result = evaluatePostfix(expression);

    if (result != -1) {
        printf("\nResult of the postfix expression is = %d\n",  result);
    }

    return 0;
}

int evaluatePostfix(char* expression)
{
    /* Create dynamic stack */
    int *stack = (int *)malloc(max * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    top = -1; /* Reset top */
    int i = 0;
    int len = (int)strlen(expression);

    /* Note: step-by-step logging intentionally omitted */

    while (i < len) {
        /* Skip spaces */
        if (expression[i] == ' ') {
            i++;
            continue;
        }

        /* If the character is a digit */
        if (isdigit((unsigned char)expression[i])) {
            int num = 0;
            /* Handle multi-digit numbers */
            while (i < len && isdigit((unsigned char)expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            push(stack, num);
        }
        /* If the character is an operator */
        else if (isOperator(expression[i])) {
            if (top < 1) {
                printf("Error: Insufficient operands for operator '%c'\n", expression[i]);
                free(stack);
                return -1;
            }

            int operand2 = pop(stack);
            int operand1 = pop(stack);
            int result = performOperation(operand1, operand2, expression[i]);

            /* If performOperation encountered division/modulo by zero, it prints an error and returns 0.
               The evaluator continues to push the result (preserving original behaviour). */
            push(stack, result);
            i++;
        }
        else {
            printf("Error: Invalid character '%c' in expression\n", expression[i]);
            free(stack);
            return -1;
        }
    }

    /* The final result should be the only element left in the stack */
    if (top == 0) {
        int finalResult = pop(stack);
        free(stack);
        return finalResult;
    } else if (top > 0) {
        printf("Error: Too many operands in the expression\n");
        free(stack);
        return -1;
    } else {
        printf("Error: No result found\n");
        free(stack);
        return -1;
    }
}

void push(int stack[], int element)
{
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", element);
        return;
    }
    top++;
    stack[top] = element;
}

int pop(int stack[])
{
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop from empty stack\n");
        return -1;
    }
    int element = stack[top];
    top--;
    return element;
}

int isEmpty()
{
    return (top == -1);
}

int isFull()
{
    return (top == max - 1);
}

int peek(int stack[])
{
    if (isEmpty()) {
        printf("Stack is empty. Nothing to peek!\n");
        return -1;
    }
    return stack[top];
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

int performOperation(int operand1, int operand2, char operator)
{
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Error: Division by zero!\n");
                return 0;
            }
            return operand1 / operand2;
        case '%':
            if (operand2 == 0) {
                printf("Error: Modulo by zero!\n");
                return 0;
            }
            return operand1 % operand2;
        case '^':
              return (int)pow(operand1, operand2);
        default:
            printf("Error: Unknown operator '%c'\n", operator);
            return 0;
    }
}
