/**
 *  @file    CircularBuffer.c
 *  @date    Created on: 14. 08. 2018
 *  @brief   Implementation of a circular buffer
 */

#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include <stdint.h>

typedef struct CircularBuffer CircularBuffer_t;

typedef enum
{
    OVERWRITE_WHEN_FULL,
    PRESERVE_WHEN_FULL
} E_ACTION_WHEN_FULL;

CircularBuffer_t CircularBuffer_init(uint8_t* buffer, uint8_t size);

void CircularBuffer_reset(CircularBuffer_t* circularBuffer);

int8_t CircularBuffer_put(CircularBuffer_t* circularBuffer, uint8_t data, E_ACTION_WHEN_FULL ActionWhenFull);

int8_t CircularBuffer_get(CircularBuffer_t* circularBuffer, uint8_t* data);

bool CircularBuffer_isEmpty(CircularBuffer_t* circularBuffer);

bool CircularBuffer_isFull(CircularBuffer_t* circularBuffer);

uint8_t CircularBuffer_capacity(CircularBuffer_t* circularBuffer);

uint8_t CircularBuffer_size(CircularBuffer_t* circularBuffer);

#endif // CIRCULAR_BUFFER_H_
