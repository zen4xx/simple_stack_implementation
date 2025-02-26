#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 16

typedef struct{   
    int arr[MAX_SIZE-1];
    int top;
} Stack;

void init(Stack* stack){
    stack->top = -1;
}

bool is_empty(Stack* stack){
    return stack->top == -1;
}

bool is_full(Stack* stack){
    return stack->top == MAX_SIZE-1;
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
    else{
        printf("%s", "stack overflow\n");
    }    
}    

int main(){
    Stack stack;
    init(&stack);
    
    push(&stack, 1234);
    push(&stack, 32);
    push(&stack, 78);
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));
    push(&stack, 4);
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));
    
}