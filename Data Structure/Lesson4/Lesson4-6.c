#include <stdio.h>
#include <stdlib.h>
#define MAX_STAK_SIZE 100

typedef struct {
    char data[MAX_STAK_SIZE];
    int top;
}StackType;
void init_stack(StackType*s){
    s->top=-1;
}
int is_empty(StackType*s){
    return (s->top==-1);
}
int is_full(StackType*s){
    return(s->top==(MAX_STAK_SIZE-1));
}
void push(StackType *s,char element){
    if(is_full(s)){
        fprintf(stderr,"스택 포화 오류");
    }else
    s->data[++(s->top)]=element;
}
char pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr,"스택 공백 오류");
    }else
    return s->data[(s->top)--];
}

//후위 표기 수식 계산 함수
int eval(char exp[]){
    int op1,op2,value,i=0;
    int len=strlen(exp);//기억하기_배열의 크기를 알 수 있는 함수
    char ch;//한글자 한글자를 위해 정의한 것 것
    StackType s;// 스택을 만들어주기_왜 귀찮게 포인터로 선언하지 않는 것일까
    init_stack(&s);//만들었으니 초기화4

    for(i=0;i<len;i++){//for문 돌면서 exp[]의 값 하나씩 읽어올 것
      ch=exp[i];

      if(ch!='+'&&ch!='-'&&ch!='*'&&ch!='/'){
        value=ch-'0';//값을 int로 넣어주기 위해서
        push(&s,value);//스택의 데이터 push할 때 데이터 char이어야 하는 거 아님? 
        //아님 굳이 위에서 왜 int로?
      }
      else{//연산자라면 피연산자 끄집어 오기
      op2=pop(&s);
      op1=pop(&s);

      switch(ch){
        case'+':push(&s,op1+op2);break;
        case'-':push(&s,op1-op2);break;
        case'*':push(&s,op1*op2);break;
        case'/':push(&s,op1/op2);break;
      }
      }

    }
    return pop(&s);

}

int main(){
    int result;
    printf("후위표기식은 82/3-32*+\n");//여기서 이 배열 지칭할 수 있도록 포인터로 지칭하면 안 되나?
    result=eval("82/3-32*+");
    printf("결과값은 %d\n",result);
    return 0;
}