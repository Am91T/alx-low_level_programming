#include <stdio.h>

int main(void)
{
    int n;
    int a[5] = {0, 1, 2, 3, 4};
    int *p;

    p = &n;
    a[2] = 1024;


    /*
     * Do not touch the following line.
     * It is using the array 'a' without index.
     * Your goal is to make this line print 98
     * by only changing one number.
     */
    *(a + 2) = 98;

    printf("a[2] = %d\n", a[2]);
    return (0);
}
