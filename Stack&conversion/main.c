//栈的应用举例：数制转换
//对于输入的任意一个非负十进制整数，打印输出与其等值的八进制数
#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100 //存储空间初始分配量 100
#define STACKINCREMENT 10 //存储空间分配增量

typedef struct SqStack{
    int *top;//定义栈顶指针
    int *base;//在栈构造之前和销毁之后，base的值为NULL，这也是栈底指针
    int stacksize;//当前已分配的存储空间，以元素为单位
}SqStack;

void InitStack(SqStack* S){
    S->base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
    if(!S->base)
        exit(0);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
}

void GetTop(SqStack *S){
    printf("%d\n",*(S->top-1));//插入一个数后，top++了，所以要减1
}

void Push(SqStack *S,int c){
    if(S->top - S->base >= STACK_INIT_SIZE){
        S->base = (int*)realloc(S->base,(S->stacksize + STACKINCREMENT)*sizeof(int));
    }
    S->stacksize += STACKINCREMENT;
    S->top = S->base + S->stacksize;
    *(S->top) = c;
    printf("%d is pushed in!\n",c);
    S->top++;
}

void ClearStack(SqStack *S){
    S->base=NULL;
}

void Pop(SqStack *S){
    if(S->top == S->base)
        printf("The stack is empty!");
    else{
    printf("%d is poped out!\n",*(S->top-1));
    S->top--;
    }
}

int main() {
    SqStack *S;//在栈构造之前和销毁之后，base的值为NULL
    //不要等值于NULL，不然后面给S malloc动态分配空间时，会访问到被释放的空间，造成编译错误
    InitStack(S);
    Push(S, 1);
    Push(S, 2);
    GetTop(S);
    Pop(S);
    ClearStack(S);
    return 0;
}
