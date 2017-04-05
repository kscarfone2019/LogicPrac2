#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


int power(int base, int power);
void printTable(int arg1, char arg2[], int binaryValues[]);
void generateEquation(int binaryV[], char equation[], int n);
int solve(char equationArr[]);

int main() {




    int arg1 = 2; //n
    char arg2[] = "ab&";
    //char arg2[] = "ab&c|";
    char equationArr[50] = "";
    int equationLength = strlen(arg2);
    int pow = power(2, arg1);
    //int *equationArr = malloc(equationLength);
    int *binaryValues = malloc(sizeof(char)*pow);

    //transfer equation array to array with numbers in it 1 or 0
    //then loop through and push/pop
    //print out truth table from there

    //equationArr[0] = '1';
    //loop to change between 0 and 1s
    int rows = power(2, arg1);
    int nVal;
    int it = 0;
    for (int g = 0; g < rows; g++) {
        for (int h = arg1-1; h >= 0; h--) {
            nVal = g>>h;
            //binaryValues[h-arg1-1] = (nVal & 1);
            binaryValues[it] = (nVal & 1);
            it++;
        }

        //printf("\n");
    }

    /*
    for (int b = 0; b < 8; b++) {
        printf("bvbv: %d\n", binaryValues[b]);
    }
    */
    char bv;
    int counter = 0;
    for (size_t v = 0; v < rows; v++) {
        for (int i = 0; i < equationLength; i++) {
            if(arg2[i] == '^') {
                equationArr[i] = '^';
            }
            else if(arg2[i] == '&') {
                equationArr[i] = '&';
            }
            else if(arg2[i] == '|') {
                equationArr[i] = '|';
            }
            else if((arg2[i] != '^') && (arg2[i] != '&') && (arg2[i] != '|') && (arg2[i] != '#')) {

                //equationArr[i] =  '1';
                //convert binaryVals to chars then add to equationArr
                //printf("i: %d\n", i);
                bv = binaryValues[counter] + '0';
                //printf("bv: %c\n", bv);
                equationArr[i] = bv; //THIS IS THE IMPORTANT STEP IN ASSIGNING A DIFFERENT 0 OR 1 FOR EACH ROW
                //printf("intside loops: %s\n", equationArr);
                counter++;
                //printf("%s", equationArr);
            }
        }
    }

    printf("%s\n", equationArr);
    //for switchting between 1 and 0
    //var = var^1
    /*
    printf("printing out equation arr below\n");
    for (size_t x = 0; x < equationLength; x++) {
        printf("%c", equationArr[x]);
    }
    */
    printf("\n");


    //do actial solving when operand found


//printf("result: %c\n", stackPop(&workStack));
free(binaryValues);
printTable(arg1, arg2, binaryValues);
//char *equation = eq;

}

int power(int base, int power) {
    int result = 1;
    for (int i = 0; i < power; i++) {
        result*=base;
    }
    return result;
}

void printTable(int n, char eq[], int binaryVals[]) {
    //char *equation = eq;
    int test[100];
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    for (int x = 0; x < n; x++) {
        printf(" %c ", alpha[x]);
    }
    printf(": %s", eq);
    printf("           :Result");
    printf("\n");
    //each n value takes up 3 spaces and result takes up 17 (9+8)
    int count = (n*3)+(17); //calculate how many dashes needed for table
    for (int b = 0; b < count; b++) {
        printf("-");
    }
    printf("\n");
    //print out binary values
    int numRows = power(2, n);
    int end = (numRows*n);
    for (int k = 0; k < end; k++) {
        if(k%n==0 && (k!=0)&&(k!=(end-1))) {
            printf("\n");
        }
        printf(" %i ", binaryVals[k]);

        test[k] = binaryVals[k];
    }
    printf("\n");





    int test1[100];
    int countVar = 0;
    for (int c = 0; c < numRows; c++) {
        for (int y = 0; y < n; y++) {
            test1[y] = binaryVals[countVar];
            countVar++;
        }
        generateEquation(test1, eq, n);
    }
}



void generateEquation(int binaryV[], char equation[], int n) {
    char testEquation[50] = "";
    char bvs;
    int numOfRows = power(2, n);
    //int results[100];//dynamically allocate this
    int *results = malloc(sizeof(int)*numOfRows);
    //int *binaryValues = malloc(sizeof(char)*pow);
    for (int i = 0; i < numOfRows-1; i++) {
        if(equation[i] == '^') {
            testEquation[i] = '^';
        }
        else if(equation[i] == '&') {
            testEquation[i] = '&';
        }
        else if(equation[i] == '|') {
            testEquation[i] = '|';
        }
        else if((equation[i] != '^') && (equation[i] != '&') && (equation[i] != '|') && (equation[i] != '#')) {


            bvs = binaryV[i] + '0';
            testEquation[i] = bvs; //THIS IS THE IMPORTANT STEP IN ASSIGNING A DIFFERENT 0 OR 1 FOR EACH ROW
            //counter++;
        }
    }
    //printf("test equation: %s\n", testEquation);
    //int moveUp = 0;
    for (int q = 0; q < 3; q++) {
        //results[q] = solve(testEquation);
        //printf("%i\n", solve(testEquation));
    }
    printf("%i\n", solve(testEquation));
    free(results);
    //result[i] = solve(testEquation);
}

int solve(char equationArr[]) {
    stack workStack;
    stackInit(&workStack, 6);

    int equationLength = strlen(equationArr);
    char firstNum, secondNum, one, zero;
    int alpha, beta, result;

    for (int j = 0; j < equationLength; j++) {
        /*
        if(equationArr[j] != '&') {
            if(equationArr[j] != '^') {
                stackPush(&workStack, equationArr[j]);
            }
        */
        if((equationArr[j] != '&') && (equationArr[j] != '^') && (equationArr[j] != '|') && equationArr[j] != '#') {
            stackPush(&workStack, equationArr[j]);
        }

        //AND
        if(equationArr[j] == '&'){
            //pop top two and solve
            firstNum = stackPop(&workStack);
            secondNum = stackPop(&workStack);

            alpha = firstNum - '0'; //1
            beta = secondNum - '0'; //1

            if((alpha && beta) == 1) {
                result = 1;
                one = result + '0';
                stackPush(&workStack, one);
            }
            else {
                result = 0;
                zero = result + '0';
                stackPush(&workStack, zero);
            }
        }
        //XOR so ^ or #
        if(equationArr[j] == '^'){
            //pop top two and solve
            firstNum = stackPop(&workStack);
            secondNum = stackPop(&workStack);

            alpha = firstNum - '0'; //1
            beta = secondNum - '0'; //1

            if((alpha ^ beta) == 1) {
                result = 1;
                one = result + '0';
                stackPush(&workStack, one);
            }
            else {
                result = 0;
                zero = result + '0';
                stackPush(&workStack, zero);
            }
        }
        //(−, |, &, #, > or =)
        //OR
        if(equationArr[j] == '|') {
            //pop top two and solve
            firstNum = stackPop(&workStack);
            secondNum = stackPop(&workStack);

            alpha = firstNum - '0'; //1
            beta = secondNum - '0'; //1
            if((alpha || beta) == 1) {
                result = 1;
                one = result + '0';
                stackPush(&workStack, one);
            }
            else {
                result = 0;
                zero = result + '0';
                stackPush(&workStack, zero);
            }
        }
        //add to array of results
    }
    if(stackIsEmpty(&workStack) == 1) {
        printf("no result stack empty\n");
    }
    else {
        printf("%i\n", stackPop(&workStack));
        return stackPop(&workStack);
    }
return 0; //if nothing happens which shouldnt happen?
}
