//동적 배열 스택_빌리고 반납하기_부족하면 더 빌리기 realloc함수로(교과서 4.5)
//malloc, realloc 어렵게 생각하지 말 것. 그냥 다른 영역의 메모리 연결시켜주는 것
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element* data;//포인터로 정의
	int capacity;//현재 크기
	int top;
}StackType;

int main() {
	StackType s;
	init_stack(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	free(s);//반납하기
}

//스택 생성 함수
void init_stack(StackType* s) {
	s->top = -1;
    s->capacity=1;
    s->data=(element*)malloc(s->capacity*sizeof(element));
    //1개 요소 저장할 수 있는 공간 확보
}
//스택 삭제 함수
void delete(StackType *s){
    free(s);
}
//공백 상태 검출 함수
int is_empty(StackType* s) {
	return(s->top == -1);
}
//포화 상태 검출 함수
int is_full(StackType* s) {
	return(s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity*=2;//공간 늘려줄게
        s->data=(element*)realloc(s->data,s->capacity*sizeof(element));
        //늘려진 공간만큼 realloc으로 재할당 받기
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