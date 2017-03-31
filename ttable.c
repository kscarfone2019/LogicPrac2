#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include "stack.h"
//false = 0
//true = 1
//need array to hold returned values
int *evaluate(int n, char operand);
void printTable(char a, char b, char c, char d);
int power(int base, int power);
void makeHeader(int n);
//arguments for main: int varSize, char formula
int main() {
    stack workStack;
    stackInit(&workStack, 6);


    int arg1 = 3;
    char arg2[] = "ab&c|";
    //take in equation and add each element to stack
    for (int i = 0; i < 6; i++) {
        if(isalpha(arg2[i])) {
            stackPush(&workStack, arg2[i]);
        }
        else if(arg2[i] == '&'){
            char a = stackPop(&workStack);
            char b = stackPop(&workStack);
            // for loop to change between 0 and 1
            int *firstTwo = evaluate(arg1, '&');

        }

    }

    return 1;
}
int *evaluate(int n, char operand) {

    makeHeader(n);
    int result, nVal;
    //int n = 2;
    //((2^n)-1) for i<=3 instead make var or something
    int rows = power(2, n);
    //int results[rows];
    int *results = malloc(rows);

    for(int i=0;i<=(rows-1);i++) {
        result=1;
        for(int j=n-1;j>=0;j--) {
            nVal=i>>j; //assigns 1 or 0 to result depeing if there equal or not (*bitwise right shift)
            printf(" %d ",nVal & 1);
            result = result &(nVal & 1);

        }
    printf(" :   %d\n", result);
    //results[i] = result;
    //return results;
    }
}
void makeHeader(int n) {
    //portion of code for printing header of table
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    for (int x = 0; x < n; x++) {
        printf(" %c ", alpha[x]);
    }
    printf("   Result");
    printf("\n");
    //each n value takes up 3 spaces and result takes up 9
    int count = (n*3)+(9); //calculate how many dashes needed for table
    for (int b = 0; b < count; b++) {
        printf("-");
    }
    printf("\n");
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
