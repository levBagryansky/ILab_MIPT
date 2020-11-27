# include <stdio.h>
# include <stdlib.h>
# include <assert.h>

# define poison -1
# define error1 -1
# define error2 -2
# define error3 -3
# define goodStack 0
struct Stack
{
    int top;
    int capacity;
    int* arr;
};

struct Stack* createStack (int capacity);
void printStack (struct Stack* pStack);
int verifyStack(struct Stack* pStack);
void push(struct Stack* pStack, int data);
int pop(struct Stack* pStack);
void StackDestruct (struct Stack** pStack);


int main ()
{
    struct Stack* pNewStack = createStack (1);
    printStack(pNewStack);
    //printf("Error code %i\n", verifyStack(pNewStack));
    push(pNewStack, 1);
    push(pNewStack, 3);
    push(pNewStack, 5);
    push(pNewStack, 7);

    printStack(pNewStack);
    printf("Pop %i\n", pop(pNewStack));
    printStack(pNewStack);
    StackDestruct(&pNewStack);
    printStack(pNewStack);
    int* test = (int*) calloc (4, sizeof(int));
    printf("%i\n", test);

    free(test);
    printf("%i", test);
}


struct Stack* createStack (int capacity)
{
    struct Stack* pStack = (struct Stack*) calloc (1, sizeof(struct Stack));
    pStack -> capacity = capacity;
    pStack -> top = 0;
    pStack -> arr = (int*) calloc (capacity, sizeof(int));
    int* n_arr = pStack -> arr;
    for(int i = 0; i < capacity; i++)
    {
        *(n_arr + i) = poison;
    }
    return pStack;
}

void printStack (struct Stack* pStack)
{
    if(pStack == 0)
    {
        printf("Stack does not exist\n");
        exit(1);
    }

    int top  = pStack -> top;
    int capacity = pStack -> capacity;
    int* arr = pStack -> arr;
    printf("\nPrinting Stack...\ntop is %i,\ncapacity is %i,\npoison is %i\n",
           top, capacity, poison);
    printf("data before top:\n");
    for (int i = 0; i < top; i++)
    {
        printf ("%2i|%5i\n", i, *(arr + i));
    }
    printf("data after top:\n");
    for (int i = top; i < capacity; i++)
    {
        printf ("%2i|%5i\n", i, *(arr + i));
    }
    printf("\n");
}

int verifyStack(struct Stack* pStack)
{
    int top  = pStack -> top;
    int capacity = pStack -> capacity;
    int* arr = pStack -> arr;
    if (top >  capacity)
    {
        return error1;
    }
    for (int i = top; i < capacity; i++)
    {
        if ((*(arr + i)) != poison)
            return error2;
    }
    if (pStack == NULL)
        return error3;
    return goodStack;
}

void push(struct Stack* pStack, int data)
{
    //printf("Error code %i\n", verifyStack(pStack));
    //assert(verifyStack(pStack) != goodStack);
    int errorCode = verifyStack(pStack);
    if (errorCode != goodStack)
    {
        printf("code error %i\n", errorCode);
        exit(1);
    }
    int top = pStack -> top;
    int capacity = pStack -> capacity;
    int* arr = pStack -> arr;
    if (top < capacity)
    {
        arr[top]  = data;
        (pStack -> top) += 1;
    }
    else
    {
        pStack -> arr = (int*) realloc(pStack -> arr, 2 * capacity * sizeof(int));
        capacity = 2 * capacity;
        arr = pStack -> arr;
        for(int i = top; i <  capacity; i++)
        {
            arr[i] = poison;
        }
        arr[top] = data;
        pStack -> top += 1;
        pStack -> capacity = capacity;
    }


}

int pop(struct Stack* pStack)
{
    int errorCode = verifyStack(pStack);
    if (errorCode != goodStack)
    {
        printf("code error %i\n", errorCode);
        exit(1);
    }

    int* arr = pStack -> arr;
    if(pStack -> top == 0)
    {
        printf("Stack is empty\n");
        exit(1);
    }

    pStack -> top-= 1;
    int top = pStack -> top;
    int data = arr[top];
    arr[top] = poison;
    return data;
}

void StackDestruct (struct Stack** ppStack)
{
    free((*ppStack) -> arr);
    free(*ppStack);
    (*ppStack) = 0;
}

