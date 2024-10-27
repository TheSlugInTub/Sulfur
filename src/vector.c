#include "vector.h"

Vector* vector_init(size_t initial_capacity) 
{
    // Allocate the vector and cast the returned void from malloc to a vector pointer
    Vector* vector = (Vector*)malloc(sizeof(Vector));
    if (vector == NULL) 
    {
        fprintf(stderr, "Failed to allocate memory for vector.\n");
        return NULL;
    }

    // Allocate the initial_capacity
    vector->data = (void**)malloc(initial_capacity * sizeof(void*));
    if (vector->data == NULL) 
    {
        free(vector);
        fprintf(stderr, "Failed to allocate memory for vector data.\n");
        return NULL;
    }

    vector->size = 0;
    vector->capacity = initial_capacity;
    return vector;
}

// Add an element to the vector
int vector_push_back(Vector* vector, void* element) 
{
    // Allocate more memory if the size exceeds the capacity
    if (vector->size >= vector->capacity) 
    {
        size_t new_capacity = vector->capacity * 2;
        // Make new data on a seperate chunk of memory
        void **new_data = realloc(vector->data, new_capacity * sizeof(void*));
        if (new_data == NULL) 
        {
            fprintf(stderr, "Failed to reallocate memory for vector data.\n");
            return -1;
        }

        vector->data = new_data;
        vector->capacity = new_capacity;
    }

    vector->data[vector->size] = element;
    vector->size++;
    return 0;
}

// Get an element from the vector
void* vector_get(Vector* vector, size_t index) 
{
    if (index >= vector->size) 
    {
        fprintf(stderr, "Index out of bounds.\n");
        return NULL;
    }
    return vector->data[index];
}

// Remove an element from the vector by index
int vector_remove(Vector* vector, size_t index) 
{
    if (index >= vector->size) 
    {
        fprintf(stderr, "Index out of bounds.\n");
        return -1;
    }

    memmove(&vector->data[index], &vector->data[index + 1], (vector->size - index - 1) * sizeof(void*));
    vector->size--;
    return 0;
}

// Free the memory used by the vector
void vector_free(Vector* vector) 
{
    free(vector->data);
    free(vector);
}
