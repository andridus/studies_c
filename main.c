#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdarg.h>

typedef struct {
    int age;
} person;

person person_copy(person *p) {
    person p0;
    p0 = *p;
    return p0;
}
void *foo(char *my_type, ...)
{
    switch (my_type[0])
    {
        case 'I':
        {
            va_list args;
            va_start(args, my_type);
            int i0 = va_arg(args, int);
            int *i;
            i = malloc(sizeof(int));
            *i = 1 + i0;
            va_end(args);
            return i;
        }
        case 'F':
        {
            va_list args;
            va_start(args, my_type);
            double f0 = va_arg(args, double);
            double *f;
            f = malloc(sizeof(double));
            *f = 1 + f0;
            va_end(args);
            return f;
        }
        case 'O':
        {
            va_list args;
            va_start(args, my_type);
            person p0 = va_arg(args, person);
            person *ptr = malloc(sizeof(p0));
            memcpy(ptr, &p0, sizeof(person));
            va_end(args);
            (*ptr).age += 2;
            printf("person age  em p0 is %d\n", p0.age);
            printf("person age  em p is %d\n", ptr->age);
            return ptr;
        }
        default:
            return NULL;
    }

}
int main(void)
{
    int *ii = NULL;
    double *dd = NULL;
    person *pp = NULL;
    person p;
    p.age = 5;

    ii = foo("I", 100);
    dd = foo("F");
    pp = foo("O", p);
    printf("Integer is %d\n", *ii);
    free(ii);
    printf("Double is %f\n", *dd);
    free(dd);

    printf("person age is %d\n", p.age);
    printf("person age is %d\n", pp->age);
    free(pp);
    free(&p);
    exit(0);
}
