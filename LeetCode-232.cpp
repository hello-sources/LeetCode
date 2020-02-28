//code 1
typedef struct {
    int head, tail;
    int *data;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *m = (MyQueue *)malloc(sizeof(MyQueue));
    m->data = (int *)malloc(sizeof(int) * 1000);
    m->head = m->tail = 0;
    return m;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    obj->data[obj->tail] = x;
    // obj->size++;
    obj->tail++;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int num = obj->data[obj->head];
    obj->data[obj->head++] = 0;
    return num;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    return obj->data[obj->head];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return obj->head == obj->tail;
}

void myQueueFree(MyQueue* obj) {
    if (obj == NULL) return ;
    free(obj->data);
    free(obj);
    return ;
}



//code 2
//以下就是栈的一些基本操作
typedef struct MyStack {
    int *data;
    int top;
} MyStack;

MyStack *MyStackCreate(int size) {
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->data = (int *)malloc(sizeof(int) * size);
    s->top = -1;
    return s;
}

void MyStackPush(MyStack *obj, int x) {
    obj->data[++(obj->top)] = x;
}

int MyStackPop(MyStack *obj) {
    return obj->data[(obj->top)--];
}

int MyStackTop(MyStack *obj) {
    return obj->data[obj->top];
}

int MyStackEmpty(MyStack *obj) {
    return obj->top == -1;
}

void MyStackFree(MyStack *obj) {
    if (obj == NULL) return;
    free(obj->data);
    free(obj);
    return ;
}

//以下就是用两个栈模拟队列先进先出功能
typedef struct {
    MyStack *s1, *s2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    int size = 1024;
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));//队列的初始化操作
    q->s1 = MyStackCreate(size);//栈初始化操作
    q->s2 = MyStackCreate(size);
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    MyStackPush(obj->s1, x);//我们把1栈作为入栈元素入口
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
   if (MyStackEmpty(obj->s2)) {
       while (!MyStackEmpty(obj->s1)) {
           MyStackPush(obj->s2, MyStackPop(obj->s1));//如果1栈非空，且2栈空，那么就把1栈元素出栈放到2栈中，这样就实现了栈1的逆序排放
       }
   }
   return MyStackPop(obj->s2);//栈2的栈顶元素就是对饮栈1栈底元素
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (MyStackEmpty(obj->s2)) {
        while (!MyStackEmpty(obj->s1)) {
            MyStackPush(obj->s2, MyStackPop(obj->s1));//与出队操作一样，将栈1逆序放到栈2中，栈2对应的栈顶元素就是栈1的栈底元素
        }
    }
    return MyStackTop(obj->s2);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return MyStackEmpty(obj->s1) && MyStackEmpty(obj->s2);//两个栈同时为空则对应队列为空
}

void myQueueFree(MyQueue* obj) {
    if (obj == NULL) return ;
    MyStackFree(obj->s1);
    MyStackFree(obj->s2);
    free(obj);
    return ;
}
