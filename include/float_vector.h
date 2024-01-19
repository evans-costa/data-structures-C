#ifndef FLOAT_VECTOR_H
#define FLOAT_VECTOR_H

typedef struct float_vector FloatVector;

FloatVector *createFloatVector(int capacity);
void destroyFloatVector(FloatVector **vec);
int sizeFloatVector(const FloatVector *vec);
int capacityFloatVector(const FloatVector *vec);
float atFloatVector(const FloatVector *vec, int index);
float getFloatVector(const FloatVector *vec, int index);
void appendFloatVector(FloatVector *vec, float val);
void setFloatVector(FloatVector *vec, int index, float val);
void printFloatVector(const FloatVector *vec);

#endif
