#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
}StackType;
void init_stack(StackType* s) {
    s->top = -1;
}
int is_empty(StackType* s) {
    return (s->top == -1);
}
int is_full(StackType* s) {
    return(s->top == (MAX_STACK_SIZE - 1));
}
void push(StackType* s, int element) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 오류");
    }
    else
        s->data[++(s->top)] = element;
}
int pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 오류");
        exit(1);
    }
    else
        return s->data[(s->top)--];
}


int main() {
    StackType s;
    init_stack(&s);
    int size;
    int array[MAX_STACK_SIZE];
    printf("정수 배열의 크기: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("정수를 입력하시오: ");
        scanf("%d", &array[i]);
        push(&s, array[i]);
    }
    printf("반전된 정수 배열: ");
    for (int i = 0; i < size; i++) {
        printf("%d", pop(&s));
    }
    return 0;

}