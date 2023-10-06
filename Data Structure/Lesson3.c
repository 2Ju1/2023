#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
element stack[MAX_STACK_SIZE];//1차원 배열 만들기
int top = -1;//위치 나타내는 것 만들기

//공백 검출 함수
int is_empty() {
	return (top == -1);
}
//포화 상태 검출 함수
int is_full() {
	return(top == (MAX_STACK_SIZE - 1));
}
//삽입함수
void push(element item) {
	if (is_full()) 
		fprintf(stderr, "스택포화 에러\n");
	else 
		stack[++top] = item;
}
//삭제함수
//element를 int 의미하므로 반환값이 배열의 값임을 이런 식으로 나타낸 것
element pop() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
	}
	else
		return stack[top--];
}//근데 이러면 값이 반환되지 않나? 맞는 듯

int main(void) {
	push(1);
	push(2);
    push(3);
}
