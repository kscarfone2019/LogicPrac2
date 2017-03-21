#include <stdio.h>

int main() {
    int test = fun(7);
    printf("%i\n", test);
    return 1;
}
int fun(int a) {
    int r=1;
    while(a--) {
        r*= 2;
    }
return r;
}
