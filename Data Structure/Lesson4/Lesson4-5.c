//괄호 검사 알고리즘
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
element data[MAX_STACK_SIZE];
int top;
}StackType;

//초기 설정 함수
void init_stack(StackType* s){
s->top=-1;
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
		return;//왜 이걸로 나가는거지?
	}
	else
		s->data[++(s->top)] = item;
}
//삭제 함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);//이번에는 왜 이걸로 나가고?
	}
	else return s->data[(s->top)--];
}

//맞는지 확인하는 함수 핵심 함수에 해당
int check_matching(const char *in){//const char이 뭐야?
    StackType s;
    char ch, open_ch;
    int i,n=strlen(in);//n은 문자열의 길이를 의미
    init_stack(&s);
//여는 괄호면 넣고 닫는 괄호면 넣어진 값들과 하나씩 꺼내면서 비교
    for(i=0;i<n;i++){
        ch=in[i];
        switch(ch){
            case'(':case'[':case'{':
            push(&s,ch);
            break;
            case')':case']':case'}':
            if(is_empty(&s))return 0;
            else{
                open_ch=pop(&s);
                if((open_ch=='('&&ch!=')')||(open_ch=='['&&ch!=']'||open_ch=='{'&&ch!='}')){
                    return 0;
                }
            }
            break;
        }
        
    }
    if(!is_empty(&s))return 0;//for문 다 돌았는데도 남아있으면 오류
    return 1;
}
int main(){
    char *p="{A[(i+1)]=0;}";//문자가 아닌 경우 switch문에서는 어떻게 되는 것일까_이경우 case없으니까
    //그냥 다음 것 확인하는 것 
    if(check_matching(p)==1)
    printf("%s 괄호검사 성공\n",p);//왜 %s일까
    else
    printf("%s 괄호검사 실패\n",p);
    return 0;
}