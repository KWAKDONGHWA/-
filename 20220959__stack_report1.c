#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int *data;  
    int top;     
    int capacity;  
} Stack;

void initStack(Stack *s) {
    s->top == -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX -1;
}

void expandStack(Stack *s) {
    int newCapacity = s->capacity + 5;
    int *newData = (int *)realloc(s->data, newCapacity * sizeof(int));
    if (newData == NULL) {
        printf("메모리 재할당 실패!\n");
        exit(1);
    }
    s->data = newData;
    s->capacity = newCapacity;
    printf("스택 용량이 %d로 증가했습니다.\n", s->capacity);
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        expandStack(s);
    }
    s->data[++(s->top)] = value;
    printf("%d을(를) 스택에 추가했습니다.\n", value);
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("스택 언더플로우! 제거할 요소가 없습니다.\n");
        return -1; 
    }
    printf("제거된 값: %d\n", s->data[s->top]);
    return s->data[(s->top)--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("스택이 비어 있습니다! 확인할 값이 없습니다.\n");
        return -1;
    }
    printf("최상단 값: %d\n", s->data[s->top]);
    return s->data[s->top];
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("스택이 비어 있습니다!\n");
        return;
    }
    printf("스택 내용: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

void freeStack(Stack *s) {
    free(s->data);
    printf("스택 메모리를 해제했습니다.\n");
}

int main() {
    Stack s;
    char str[MAX];
    initStack(&s);
    
    printf("문자열 입력 : ");
    fgets(str, MAX, stdin);
    
    for(int i = 0; str[i] != '\0'; i++)     push(&s, str[i]);
    printf("거꾸로 된 문자열 : ");
    while(!isEmpty(&s)){
        printf("%c", pop(&s));
    }
    printf("\n");
    
    return 0;
    
}
