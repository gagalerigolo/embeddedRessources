/**
 *  @file    Stack.c
 *  @date    16. 08. 2018
 *  @brief   Implementation of a Stack
 */

#ifndef STACK_H_
#define STACK_H_

#include <stdint.h>

typedef struct Stack Stack_t;

Stack_t Stack_create(uint8_t* stack, uint8_t size);

void Stack_reset(Stack_t* stack);

int8_t Stack_push(Stack_t* stack, uint8_t data);

int8_t Stack_pop(Stack_t* stack, uint8_t* data);

bool Stack_isEmpty(Stack_t* stack);

bool Stack_isFull(Stack_t* stack);

#endif // STACK_H_
