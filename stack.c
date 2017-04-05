/*
code for stack taken in part from: INCLUDE IN REPORT
https://www.cs.bu.edu/teaching/c/stack/array/
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void stackPush(stack *stackP, stackElement element) {
    if(stackIsFull(stackP)) {
        printf("element can't be pushed, stack is full\n");
    }
    //int index = stackP->top++;
    stackP->contents[++stackP->top] = element;
}

stackElement stackPop(stack *stackP) {
    if(stackIsEmpty(stackP)) {
        printf("nothing to pop, stack empty\n");
        exit(1);
    }
    //return the top value and then subtract one from top
    /*
    char temp = stackP->contents[stackP->top];
    stackP->contents[stackP->top] = NULL;
    stackP->top--;
    return temp;
    */
    return stackP->contents[stackP->top--];
}

int stackIsEmpty(stack *stackP) {
    if(stackP->top < 0) {
        return 1;
    }
    return 0;
}

int stackIsFull(stack *stackP) {
    if(stackP->top >= stackP->maxSize-1) {
        return 1;
    }
    return 0;
}

void stackInit(stack *stackP, int maxSize) {
    stackElement *newContents;
    newContents = (stackElement *)malloc(sizeof(stackElement)*maxSize);

    stackP->contents = newContents;
    stackP->maxSize = maxSize;
    stackP->top = -1;
}

void stackDestroy(stack *stackP) {
    free(stackP->contents);
    stackP->contents = NULL;
    stackP->maxSize = 0;
    stackP->top = -1;
}

void printStack(stack *stackP) {
    int count = stackP->maxSize;
    for (int i = 0; i < count; i++) {
        stackElement temp = stackP->contents[i];
        printf("%c ", temp);
    }
}
