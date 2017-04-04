#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"



int main() {

    stack workStack;
    stackInit(&workStack, 6);


    int arg1 = 2;
    //char arg2[] = "ab&c&";
    char arg2[] = "ab|c&";
    char equationArr[] = "";

    int equationLength = strlen(arg2);
    //int *equationArr = malloc(equationLength);

    //transfer equation array to array with numbers in it 1 or 0
    //then loop through and push/pop
    //print out truth table from there

    //equationArr[0] = '1';

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
        else if(arg2[i] != '^') {
            if(arg2[i] != '&') {
                if(arg2[i] != '|') {
                    equationArr[i] = '1';
                }

            }
        }
    }
    //equationArr[3] = '1';
    printf("\n");
    for (size_t x = 0; x < equationLength; x++) {
        printf("%c", equationArr[x]);
    }
    printf("\n");


    //dp actial solving when operand found
    char firstNum, secondNum, one, zero;
    int alpha, beta, result;
    for (int j = 0; j < equationLength; j++) {
        if(equationArr[j] != '&') {
            if(equationArr[j] != '^') {
                stackPush(&workStack, equationArr[j]);
            }

        }
        //AND
        if(equationArr[j] == '&'){
            //pop top two and solve
            firstNum = stackPop(&workStack);
            secondNum = stackPop(&workStack);
            //printf("first: %c\n", firstNum);
            //printf("second: %c\n", secondNum);

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
        //XOR
        if(equationArr[j] == '^'){
            //pop top two and solve
            firstNum = stackPop(&workStack);
            secondNum = stackPop(&workStack);
            //printf("first: %c\n", firstNum);
            //printf("second: %c\n", secondNum);

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
            //printf("first: %c\n", firstNum);
            //printf("second: %c\n", secondNum);

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

    }
    printf("result: %c\n", stackPop(&workStack));
    //printStack(&workStack);
    //for and '&'
    //get size of stack first

}
