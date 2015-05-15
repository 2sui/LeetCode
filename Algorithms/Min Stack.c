/*
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
*/

/****************************************************************************************/

typedef struct Stack{
    int data;
    struct Stack *next;
    struct Stack *last;
} MinStack;

MinStack elm, min, *elmTop = 0, *minTop = 0;

void minStackCreate(MinStack *stack, int maxSize) {
    elm.last = 0;
    elm.next = 0;
    min.last = 0;
    min.next = 0;
    elmTop = &elm;
    minTop = &min;
    stack = &elm;
}

void minStackPush(MinStack *stack, int element) {
    if (elmTop == &elm)
    {
        elm.next = (MinStack*)malloc(sizeof(MinStack));
        elm.next->last = &elm;
        elm.next->next = 0;
        elmTop = elm.next;
        elmTop->data = element;
        min.next = (MinStack*)malloc(sizeof(MinStack));
        min.next->last = &min;
        min.next->next = 0;
        minTop = min.next;
        minTop->data = element;
        return;
    }
    
    elmTop->next = (MinStack*)malloc(sizeof(MinStack));
    elmTop->next->last = elmTop;
    elmTop->next->next = 0;
    elmTop = elmTop->next;
    elmTop->data = element;
    
    if (element <= minTop->data)
    {
        minTop->next = (MinStack*)malloc(sizeof(MinStack));
        minTop->next->last = minTop;
        minTop->next->next = 0;
        minTop = minTop->next;
        minTop->data = element;
        
    }
}

void minStackPop(MinStack *stack) {
    if (elmTop->data == minTop->data)
    {
        minTop = minTop->last;
        //free(minTop->next);
        minTop->next = 0;
    }
    
    elmTop = elmTop->last;
    //free(elmTop->next);
    elmTop->next = 0;
}

int minStackTop(MinStack *stack) {
    return elmTop->data;
}

int minStackGetMin(MinStack *stack) {
    return minTop->data;
}

void minStackDestroy(MinStack *stack) {
    while (elmTop != &elm)
    {
        minStackPop(&elm);
    }
}