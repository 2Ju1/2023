#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int name;
    char data;
}Box;
typedef struct {
    Box line[MAX_STACK_SIZE];
    int top;
}StackType;

//초기 설정 함수
void init_stack(StackType* s) {
    s->top = -1;
}

//공백 상태 검출 함수
int is_empty(StackType* s) {
    return(s->top == -1);
}
//포화 상태 검출 함수
int is_full(StackType* s) {
    return(s->top == (MAX_STACK_SIZE - 1));
}
//삽입함수
void push(StackType* s, char item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else
        s->line[++(s->top)].data = item;
}

//삭제 함수
char pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->line[(s->top)--].data;
}

void check_matching(char line[]) {
    int n = strlen(line);
    char ch;
    int num=0;
    //스택 생성해주기
    StackType s;
    init_stack(&s);
    //for문으로 한 글자씩 확인
    for (int i = 0; i < n; i++) {
        ch = line[i];
        switch (ch) {
        case '(':
            push(&s, ch);
            s.line[s.top].name =++num;//스택 변동과 상관 없이 횟수 세주는 숫자 필요
            printf("%d ", s.line[s.top].name);
            break;

        case ')':
            printf("%d ", s.line[s.top].name);
            pop(&s);
            break;
        }
    }

}
int main() {
    char line[100];
    printf("수식: ");
    gets_s(line, 100);
    printf("괄호수: ");
    check_matching(line);
    return 0;
}