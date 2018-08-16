/**
 *  @file    CircularBuffer.c
 *  @date    Created on: 14. 08. 2018
 *  @brief   Implementation of a circular buffer
 */

#include <stdbool.h>
#include <stdint.h>

#include "CircularBuffer.h"

struct CircularBuffer
{
    uint8_t* buffer;
    uint8_t  bufferHead;
    uint8_t  bufferTail;
    uint8_t  maxCapacity;
    uint8_t  remainingCapacity;
    bool     isFull;
};

static void incPointer(CircularBuffer_t* circularBuffer)
{
    if (circularBuffer->isFull)
    {
        circularBuffer->bufferTail = (circularBuffer->bufferTail + 1) % circularBuffer->maxCapacity;
    }

    circularBuffer->bufferHead = (circularBuffer->bufferHead + 1) % circularBuffer->maxCapacity;

    circularBuffer->isFull = (circularBuffer->bufferHead == circularBuffer->bufferTail);

    circularBuffer->remainingCapacity--;
}

static void decPointer(CircularBuffer_t* circularBuffer)
{
    circularBuffer->isFull = false;
    circularBuffer->bufferTail   = (circularBuffer->bufferTail + 1) % circularBuffer->maxCapacity;

    circularBuffer->remainingCapacity++;
}

CircularBuffer_t CircularBuffer_init(uint8_t* buffer, uint8_t size)
{
    CircularBuffer_t newCircularBuffer;

    newCircularBuffer.buffer       = buffer;
    newCircularBuffer.maxCapacity = size;

    CircularBuffer_reset(&newCircularBuffer);

    return newCircularBuffer;
}

void CircularBuffer_reset(CircularBuffer_t* circularBuffer)
{
    circularBuffer->bufferHead   = 0;
    circularBuffer->bufferTail   = 0;
    circularBuffer->isFull = false;
}

int8_t CircularBuffer_put(CircularBuffer_t* circularBuffer, uint8_t data, E_ACTION_WHEN_FULL ActionWhenFull)
{
    int8_t ErrorCode = ERROR_OK;

    if (ActionWhenFull == OVERWRITE_WHEN_FULL || !CircularBuffer_isFull(circularBuffer))
    {
        circularBuffer->buffer[circularBuffer->bufferHead] = data;
        incPointer(circularBuffer);
        ErrorCode = 0;
    }

    return ErrorCode;
}

int8_t CircularBuffer_get(CircularBuffer_t* circularBuffer, uint8_t* data)
{
    int8_t ErrorCode = ERROR_OK;

    if (!CircularBuffer_isEmpty(circularBuffer))
    {
        *data = circularBuffer->buffer[circularBuffer->bufferTail];
        decPointer(circularBuffer);

        ErrorCode = 0;
    }

    return ErrorCode;
}

bool CircularBuffer_isEmpty(CircularBuffer_t* circularBuffer)
{
    return (!circularBuffer->isFull && (circularBuffer->bufferHead == circularBuffer->bufferTail));
}

bool CircularBuffer_isFull(CircularBuffer_t* circularBuffer)
{
    return circularBuffer->isFull;
}

uint8_t CircularBuffer_capacity(CircularBuffer_t* circularBuffer)
{
    return circularBuffer->maxCapacity;
}

uint8_t CircularBuffer_size(CircularBuffer_t* circularBuffer)
{
    return (circularBuffer->maxCapacity - circularBuffer->remainingCapacity);
}
