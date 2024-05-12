#define FILE_NAME "input.txt"
#define  RAND_GEN  200000

/* spooky include headers (ooo) */
#include <stdio.h>
#include <sys/random.h>

int main() {
    /* Initialize variables:
     * f: the file
     * r: the int
     * sz_r: the size of the int */
    FILE *f = fopen(FILE_NAME, "wb");
    if (!f) return 1;
    signed long long r;
    size_t sz_r = sizeof(r);

    /* Write to the file loop. */
    int i;
    for (i=0; i<RAND_GEN; i++) {
        if (getrandom(&r, sz_r, 0) == sz_r) {
            fprintf(f, "%lld\n", r);
        }
        else return 1;
    }

    /* Exit. */
    return fclose(f);
}