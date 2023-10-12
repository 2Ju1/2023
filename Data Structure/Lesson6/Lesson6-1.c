#define MAX_LIST_SIZE 100
#include <stdio.h>

typedef int element;//int 이제 element로 정의시킬 것
 
typedef struct{
    element arrya[MAX_LIST_SIZE];//배열 정의
    int size; //현재 리스트에 저장된 항목들의 개수
}ArrayListType;

//오류 처리 함수
void effor(char *message){
    fprintf(stderr,"%s\n",message);
    exit(1);
}
// 리스트 초기화 함수
void init(ArrayListType *L){
    L->size=0;//크기는 0부터 시작
}

//리스트가 비어 있으면 1을 반환
//그렇지 않으면 0을 반환
int is_empty(ArrayListType *L){
    return L->size==0;
}

//리스트가 가득 차 있으면 1을 반환
//그렇지 않으면 0을 반환
int is_full(ArrayListType *L){
    return L->size==MAX_LIST_SIZE;
}

element get_entry(ArrayListType *L,int pos){
    if(pos<0||pos>L->size){
        error("위치 오류")//error 함수는 무슨 함수일까?
    }
    return L->array[pos];
}

//리스트 출력
void print_list(ArrayListType *L){
    for(int i=0;i<L->size;i++)
    printf("%d->",L->array[i]);
    printf("\n");
}
//마지막에 삽입하는 함수
void insert_last(ArrayListType *L,element item){
    if(L->size>=MAX_LIST_SIZE){
        error("리스트 오버플로우");
    }
    L->array[L->size++]=item;
}
//특정 위치에 삽입하는 함수
void insert(ArrayListType *L, int pos, element item){
    if(!is_full(L)&&(pos>=0)&&(pos<=L->size)){
        for(int i=(L->size-1);i>=pos;i--){
            L->array[i+1]=L->array[i]//우측으로 하나씩  바꾸기
        }
        L->array[pos]=item;
        L->size++;
    }
}