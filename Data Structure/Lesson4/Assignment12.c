#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
    int top;
    char data[MAX_STACK_SIZE];
} StackType;

void init_stack(StackType* s) {
    s->top = -1;
}

int is_empty(StackType* s) {
    return (s->top == -1);
}

int is_full(StackType* s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else
        s->data[++(s->top)] = item;
}

element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return s->data[(s->top)--];
}

element peek(StackType* s) {
    if (is_empty(s)) {
        return '\0';
    }
    else
        return s->data[s->top];
}

int main() {
    int letter_count = 0; // 초기값을 0으로 변경
    char top;
    char ch;
    char line[100];
    StackType s;
    init_stack(&s);

    printf("문자열: ");
    gets(line);
    // 소문자로 변환 저장
    for (int i = 0; i < strlen(line); i++) {
        line[i] = tolower(line[i]);
    }
    printf("압축된 문자열: ");
    for (int i = 0; i < strlen(line); i++) {
        ch = line[i];
        top = peek(&s);
        if (is_empty(&s)) {
            push(&s, ch);
            letter_count = 1; // 여기서 초기화
        }
        else {
            if (ch == top) {
                if ((letter_count) == 1) {
                    letter_count++;
                    pop(&s);
                    push(&s, '0' + letter_count);
                    push(&s, ch);
                }
                else {
                    letter_count++;
                    pop(&s);
                    pop(&s);
                    push(&s, '0' + (letter_count));
                    push(&s, ch);
                }
                
            }
            else {
                push(&s, line[i]);
                letter_count = 1;
            }
        }
    }

    StackType ns;
    init_stack(&ns);

    int i = 0;
    while (!is_empty(&s)) {
        push(&ns, pop(&s));
    }
    while (!is_empty(&ns)) {
        printf("%c", pop(&ns));
    }

    return 0;
}
