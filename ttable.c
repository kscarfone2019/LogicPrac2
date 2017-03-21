#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "stack.h"
//false = 0
//true = 1
//need array to hold returned values
void evaluateAnd();
void printTable(char a, char b, char c, char d);
int power(int base, int power);
//arguments for main: int varSize, char formula
int main() {
    stack workStack;
    stackInit(&workStack, 3);


    int arg1 = 2;
    char arg2[] = "ab&cd&";
    //take in equation and add each element to stack
    for (size_t i = 0; i < 3; i++) {
        if(isalpha(arg2[i])) {
            stackPush(&workStack, arg2[i]);
        }
        else if(arg2[i] == '&'){
            char temp1 = stackPop(&workStack);
            char temp2 = stackPop(&workStack);
            // for loop to change between 0 and 1
            evaluateAnd(arg1);

        }

    }

    return 1;
}
void evaluateAnd(int n) {
    int and, result;
    //int n = 2;
    //((2^n)-1) for i<=3 instead make var or something
    int rows = power(2, n);
    for(int i=0;i<=(rows-1);i++) {
        and=1;
        for(int j=n-1;j>=0;j--) {
            result=i>>j; //assigns 1 or 0 to result depeing if there equal or not
            printf("%d\t",result & 1);
            and=and &(result & 1); //line that changes between and or/ so on
        }
    printf("%d\n", and);
    }
}
int power(int base, int power) {
    int result = 1;
    for (int i = 0; i < power; i++) {
        result*=base;
    }
    return result;
}
/*
void printTable(char a, char b, char c, char d) {
    printf("a b : ab& : Result\n");
    printf("------------------\n");
    printf("0 0         %c\n", a);
    printf("1 1         %c\n", b);
    printf("1 0         %c\n", c);
    printf("0 1         %c\n", d);

}
*/
