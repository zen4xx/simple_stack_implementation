#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{   
    int* arr;
    int top;
    int max_size;
    bool is_dynamic;
} Stack;

void init(Stack* stack, int size, bool is_dynamic){
    stack->top = -1;
    stack->max_size = size;
    stack->arr = malloc(stack->max_size*sizeof(int));
    stack->is_dynamic = is_dynamic;
}

void destroy(Stack* stack){
    stack->top = -1;
    free(stack->arr);
}

bool is_empty(Stack* stack){
    return stack->top == -1;
}

bool is_full(Stack* stack){
    return stack->top == stack->max_size-1;
}

int pop(Stack* stack){
    if(!is_empty(stack)){
        int poped = stack->arr[stack->top];
        --stack->top;
        return poped;
    }
    else {
        printf("%s", "stack underflow");
        return 0;
    }
}    

void push(Stack* stack, int value){
    if(!is_full(stack)){
        stack->arr[++stack->top] = value;
    }    
    else if (!stack->is_dynamic){
        printf("%s", "stack overflow\n");
    }    
    else{
        stack->arr = realloc(stack->arr, stack->max_size *= 2);
        stack->arr[++stack->top] = value;
    }
}    

int peek(Stack* stack){
    return stack->arr[stack->top];
}

void print_stack(Stack* stack){
    for(int i = 0; i <= stack->top; ++i){
        printf("%d\n", stack->arr[i]);
    }
}

int main(){
    Stack stack;
    init(&stack, 4, 1);
    
    push(&stack, 1234);
    push(&stack, 32);
    push(&stack, 78);
    push(&stack, 4);
    push(&stack, 5);
    printf("%d\n", pop(&stack));
    
    destroy(&stack);
}