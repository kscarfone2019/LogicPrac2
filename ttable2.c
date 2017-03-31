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
    char arg2[] = "ab&";
    char equationArr[] = "";

    int equationLength = strlen(arg2);
    //int *equationArr = malloc(equationLength);

    //transfer equation array to array with numbers in it 1 or 0
    //then loop through and push/pop
    //print out truth table from there
    for (size_t i = 0; i < equationLength; i++) {
        if(arg2[i] != '&') {
            equationArr[i] = '0';
        }
        else {
            equationArr[i] = '&';
        }
    }

    //dp actial solving when operand found
    for (size_t j = 0; j < equationLength; j++) {
        if(equationArr[j] != '&') {
            stackPush(&workStack, equationArr[j]);
        }
        else if(equationArr[j] == '&'){
            //pop top two and solve
            char firstNum = stackPop(&workStack);
            char secondNum = stackPop(&workStack);

            int alpha = firstNum - '0'; //1
            int beta = secondNum - '0'; //1
            printf("alpha: %i\n", alpha);
            printf("beta: %i\n", beta);
            int result = 1;

            result = result &(alpha&0);

            printf("result: %i\n", result);
        }
    }



    /*
    for (size_t i = 0; i < equationLength; i++) {
        printf("%c\n", equationArr[i]);
    }
    //free(equationArr);
    return 1;
    */
}
