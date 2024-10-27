#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    void** data;     // Array of void pointers to store any type
    size_t size;     // Current number of elements in the vector
    size_t capacity; // Amount of data allocated for the vector
} Vector;

// Initialize the vector
Vector* vector_init(size_t initial_capacity);

// Push an element into a vector
int vector_push_back(Vector* vector, void* element);

// Get the data at an index of the vector
void* vector_get(Vector* vector, size_t index);

// Remove an element from the vector by index
int vector_remove(Vector* vector, size_t index);

// Free the memory used by the vector
void vector_free(Vector* vector);
