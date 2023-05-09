#include<stdio.h>
#include<stdlib.h>
#define max_size 100
struct stack{
    int data[max_size];
    int top;
};

void push(struct stack *s, int element){
    if(s->top==max_size-1){
        printf("stack overflow");
        exit(1);
    }
   s->data[++s->top] = element;
}

int pop(struct stack*s){
    if(s->top==-1){
        printf("Stack underflow");
        exit(1);
    }
    return s->data[s->top--];
}

int factorial(int n){
    struct stack s;
    s.top=-1;
    push(&s,n);
    int fact=1;
    while(s.top!=-1){
        int num=pop(&s);
        fact=fact*num;
        if(num>1){
            push(&s,num-1);
        }
    }
    return fact;
}

void fibonacci(int n){
    struct stack s;
    s.top=-1;
    push(&s,1);
    push(&s,0);
    int a,b,c;
    for(int i=0;i<n;i++){
        b=pop(&s);
        a=pop(&s);
        c=a+b;
        printf("%d ",c);
        push(&s,b);
        push(&s,c);
    }
}


int main(){
    int n;
    printf("Enter a number to find its factorial:\n ");
    scanf("%d",&n);
    printf("Factorial of %d is %d",n,factorial(n));
     printf("Enter the number of terms to generate in the Fibonacci series:\  ");
    scanf("%d",&n);
    printf("Fibonacci series: ");
    fibonacci(n);
    return 0;
}
 