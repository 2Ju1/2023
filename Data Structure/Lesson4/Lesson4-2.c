//배열과 top을 하나의 구조체로 묶기 교과서 4.3
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

//스택 초기화 함수
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
void push(StackType* s,element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}
//삭제 함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
//피크함수
element peek(StackType *s){
	if(is_empty(s)){
		fprintf(stderr,"스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
int main() {
	StackType s;
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

}
/*참고 s 말고 주소값으로 저장하면& 안 써도 됨
StackTye* ps = &s; 하고 나머지 &s자리에 ps*/
