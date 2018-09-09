#include<stdio.h>

#define DECLARE(name, type) typename##_##type##_type

union un{
    float f;
    int i;
};


int main()
{
    float d[] = {0.0809, 0.0739, 0.0735, 0.0761, 0.0713, 0.0708};
    float x[6];
    float y[] = {0, 0.1, 0.2, 0.3, 0.4, 0.5};
    int i, j;

    for(j = 0; j < 6; j++) {
        x[j] = 2*0.1098438 - d[j] + 1;
        printf("%f\t", x[j]);
    }


    printf("\n");
    for(i = 0; i < 6; i++) {
        float z;
        z = (-y[i] * y[i] + y[i] - x[i] * y[i]);
        printf("%f\n", z);
    }

    //DECLARE(val, int) = 0;
    
    // printf("%d", val_int_type);
    int k = 0;
    printf("%d\t%d\t%d\n", k++, k++, k++);


    union un fi;
    fi.f = 3.141592653;
    printf("%d\n", fi.i);

    getchar();
	return 0;
}