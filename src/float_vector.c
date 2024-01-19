#include "float_vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct float_vector {
    int capacity;
    int size;
    float *data;
} FloatVector;

bool _isFull(const FloatVector *vec) {
    return vec->size == vec->capacity;
}

// Cria ou aloca um vetor de floats com uma dada capacidade
FloatVector *createFloatVector(int capacity) {
    FloatVector *vec = (FloatVector*) calloc(1, sizeof(FloatVector));
    vec->size = 0;
    vec->capacity = capacity;
    vec->data = calloc(capacity, sizeof(float));

    return vec;
}

void destroyFloatVector(FloatVector **vec_ref) {
    FloatVector *vec = *vec_ref;
    free(vec->data);
    free(vec); 
    *vec_ref = NULL;
}

int sizeFloatVector(const FloatVector *vec) {
    return vec->size;
}

int capacityFloatVector(const FloatVector *vec) {
    return vec->capacity;
}

float atFloatVector(const FloatVector *vec, int index) {
    if (index < 0 || index >= vec->size) {
        fprintf(stderr, "ERROR in 'at'\n");
        fprintf(stderr, "Index [%d] is out of bounds: [0, %d]\n", index, vec->size);
        exit(EXIT_FAILURE);
    }

    return vec->data[index];
}

float getFloatVector(const FloatVector *vec, int index) {
    return vec->data[index];
}

void appendFloatVector(FloatVector *vec, float val) {
    if(_isFull(vec)) {
        fprintf(stderr, "ERROR in 'append'\n");
        fprintf(stderr, "Vector is full\n");
        exit(EXIT_FAILURE);
    }
    vec->data[vec->size++] = val;
}

void printFloatVector(const FloatVector *vec) {
    puts("------------------------");
    printf("Size: %d\n", vec->size);
    printf("Capacity: %d\n", vec->capacity);
    puts("---");

    for (int i = 0; i < vec->size; i++) {
        printf("[%d] = %f\n", i, vec->data[i]);
    }
    puts("------------------------");
}








