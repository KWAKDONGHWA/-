#include <stdio.h>
#include <stdbool.h>
#define SIZE 30

typedef struct{
    int data[SIZE];
    int front;
    int rear;
}LinearQueue;

void initQueue(LinearQueue *q){
    q->front = 0;
    q->rear = -1;
}

bool isEmpty(LinearQueue *q){
    return q->rear < q->front;
}

bool isFull(LinearQueue *q){
    return q->rear == SIZE-1;
}

bool enqueue(LinearQueue *q, int value){
    if(isFull(q)){
        printf("큐가 가득 찾습니다.\n");
        return false;
    }
    q->rear++;
    q->data[q->rear] = value;
}

int dequeue(LinearQueue *q){
    if(isEmpty(q)){
        printf("큐가 비어있습니다\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front++;
    if(isEmpty(q)) initQueue(q);
    return value;
}

void printQueue(LinearQueue *q){
    if(isEmpty(q)){
        printf("큐가 비어있습니다.\n");
        return;
    }
    printf("queue data : ");
    for(int i = q->front; i <= q->rear; i++){
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main(){
    LinearQueue q;
    initQueue(&q);
    int choice, value;
    while(true){
        printf("\n1. 삽입 \n2. 삭제 \n3. 큐 데이터 출력 \n4. 종료\n");
        printf("선택 : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("삽입할 값을 입력 : ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if(value != -1) printf("deque value : %d\n", value);
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                printf("프로그램 종료합니다.\n");
                return;
            default:
                printf("잘못된 입력입니다. 다시 입력하세요\n");
        }
    }
    
    return 0;
}
