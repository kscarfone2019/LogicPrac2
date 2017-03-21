typedef char stackElement; //

typedef struct {
    stackElement *contents; //array of chars
    int top;
    int maxSize;
} stack;

void stackInit(stack *stackP, int maxSize);
void stackDestroy(stack *stackP);

void stackPush(stack *stackP, stackElement element);
stackElement stackPop(stack *stackP);

int stackIsEmpty(stack *stackP);
int stackIsFull(stack *stackP);

void printStack(stack *stackP);
