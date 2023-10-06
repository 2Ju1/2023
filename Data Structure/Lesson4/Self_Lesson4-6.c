#define MAX_STACK_SIZE 100
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char data[100];
    int top;
}StackType;

void init_stack(StackType* s) {
    s->top = -1;
}

int is_empty(StackType* s) {
    return(s->top == -1);
        
}
int is_full(StackType* s) {
     return(s->top == (100 - 1));
     
}
void push(StackType* s, char item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else
        s->data[++(s->top)] = item;
}
char pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return s->data[(s->top)--];
}

//이게 피연산자인지 연산자인지 검사하는 함수
int op_test(char* p, int i) {
    switch (p[i]) {
    case '+':case'-':case'*':case'/':
        return 1;
        break;

    default:
        return 0;
        break;
    }
}
//op 나왔을 경우 계산하는 함수
int cal(StackType* s, char* p, int i) {
    int n1 = pop(s) - '0';
    int n2 = pop(s) - '0';
    switch (p[i]) {
    case '+':
        return n2 + n1 ;
        break;
    case '-':
        return n2 - n1 ;
        break;
    case '*':
        return n2 * n1 ;
        break;
    case '/':
        return n2 / n1 ;
        break;
    }
}
//결과값 계산하는 함수
int eval(char* p) {
    //스택 만들었음
    StackType s;
    init_stack(&s);
    for (int i = 0; i < strlen(p); i++) {
        if (op_test(p, i)) {
            push(&s, cal(&s, p, i)+'0');//연산결과를 문자로 변환해서 스택에 저장
        }
        else {
            push(&s, p[i]);
        }
    }
    return s.data[s.top]-'0';//스캑의 최종결과를 문자에서 정수로 변환

}

int main() {
 
    char p[] = "82/3-32*+";
    printf("후위표기식은 %s", p);//*p라고쓰면 첫번째 문자만 나온다고 함. 해보자
    int result;
        result = eval(p);//이러면 p라는 내가 만든 문자열의 주소값이 들어가는데?
    printf("결과값은 %d\n", result);
    return 0;

}

