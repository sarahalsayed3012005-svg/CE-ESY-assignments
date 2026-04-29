#include <stdio.h>
#include <string.h>

#define SIZE 12 

typedef struct {
    char data[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

void initBuffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}

int isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

void push(CircularBuffer *cb, char item) {
    if (isFull(cb)) {
        printf("\n[Warning] Buffer Overflow! Cannot add: %c", item);
        return;
    }
    cb->data[cb->tail] = item;
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count++;
}

char pop(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        return '\0';
    }
    char item = cb->data[cb->head];
    cb->head = (cb->head + 1) % SIZE;
    cb->count--;
    return item;
}

int main() {
    CircularBuffer cb;
    initBuffer(&cb);

    char name[50];
    char combined[100];

    printf("Enter your name: ");
    scanf("%s", name);

    strcpy(combined, name);
    strcat(combined, "CE-ESY");

    printf("\nFull string: %s", combined);
    printf("\nBuffer size: %d", SIZE);
    printf("\n---------------------------");

    for (int i = 0; i < strlen(combined); i++) {
        push(&cb, combined[i]);
    }

    printf("\n\nReading from buffer: ");
    while (!isEmpty(&cb)) {
        printf("%c", pop(&cb));
    }

    if (isEmpty(&cb)) {
        printf("\n\nStatus: Buffer is empty now.\n");
    }

    return 0;
}