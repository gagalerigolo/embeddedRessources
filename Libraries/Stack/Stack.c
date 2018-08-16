/**
 *  @file    Stack.c
 *  @date    16. 08. 2018
 *  @brief   Implementation of a stack
 */

#include <stdbool.h>
#include <stdint.h>

#include "Stack.h"

struct Stack
{
    uint8_t* stack;
    int8_t   top;
    uint8_t  maxCapacity;
};

Stack_t Stack_create(uint8_t* stack, uint8_t size)
{
    Stack_t newStack;

    newStack.stack       = stack;
    newStack.maxCapacity = size;

    Stack_reset(&newStack);

    return newStack;
}

void Stack_reset(Stack_t* stack)
{
    stack->top    = 0;
}

int8_t Stack_push(Stack_t* stack, uint8_t data)
{
    int8_t ErrorCode = -1;

    if (!Stack_isFull(stack))
    {
        stack->stack[stack->top] = data;
		stack->top++;
        ErrorCode = 0;
    }

    return ErrorCode;
}

int8_t Stack_pop(Stack_t* stack, uint8_t* data)
{
    int8_t ErrorCode = -1;

    if (!Stack_isEmpty(stack))
    {
        *data = stack->stack[stack->top];
		stack->top--;
        ErrorCode = 0;
    }

    return ErrorCode;
}

bool Stack_isEmpty(Stack_t* stack)
{
    return (stack->top == -1);
}

bool Stack_isFull(Stack_t* stack)
{
    return (stack->top == stack->maxCapacity - 1);
}
