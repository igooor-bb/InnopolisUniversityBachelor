#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int intVar;
    float floatVar;
    double doubleVar;

    intVar = INT_MAX;
    floatVar = FLT_MAX;
    doubleVar = DBL_MAX;

    printf("IntVar - Size: %d, Value: %d\n", sizeof(intVar), intVar);
    printf("floatVar - Size: %d, Value: %G\n", sizeof(floatVar), floatVar);
    printf("doubleVar - Size: %d, Value: %G\n", sizeof(doubleVar), doubleVar);

    return 0;
}