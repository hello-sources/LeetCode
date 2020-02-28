//code 1
typedef struct {
    int *data;
    int head, tail, size;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *m = (MyStack *)malloc(sizeof(MyStack));
    m->data = (int *)malloc(sizeof(int) * 1000);
    m->head = m->tail = m->size = 0;
    return m;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    for (int i = obj->size ; i >= 1; i--) {
        obj->data[i] = obj->data[i - 1];
    }
    obj->data[0] = x;
    obj->size++;
    
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int num = obj->data[0];
    for (int i = 1; i < obj->size; i++) {
        obj->data[i - 1] = obj->data[i]; 
    }
    obj->size--;
    return num;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->data[0];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->size == 0;
}

void myStackFree(MyStack* obj) {
    if (obj == NULL) return ;
    free(obj->data);
    free(obj);
    return ;
}



// code 2
//使用两个队列模拟栈的先进后出性质
typedef struct MyQueue{
    int *data;
    int head, tail;
    int size, cnt;//定义一个统计值，用来避免队列的“假溢出”
} MyQueue;

//队列初始化
MyQueue *MyQueueCreate(int size) {
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->data = (int *)malloc(sizeof(int) * size);
    q->head = q->tail = 0;
    q->cnt = 0;
    q->size = size;
    return q;
}

//入队操作
void MyQueuePush(MyQueue *obj, int x) {
    if (obj == NULL) return ;
    if (obj->cnt == obj->size) return ;
    obj->data[obj->tail++] = x;
    if (obj->tail == obj->size) obj->tail -= obj->size;//使用循环队列
    obj->cnt += 1;//对应元素统计值要加一
    return ;
}

//出队操作
int MyQueuePop(MyQueue *obj) {
    if (obj == NULL) return 0;
    if (obj->cnt == 0) return 0;
    obj->head += 1;
    if (obj->head == obj->size) obj->head -= obj->size;
    obj->cnt -= 1;
    return 1;
}

//队首元素输出
int MyQueueFront(MyQueue *obj) {
    return obj->data[obj->head];
}

//队列判空操作
int MyQueueEmpty(MyQueue *obj) {
    return obj->cnt == 0;
}

//释放空间操作
void MyQueueFree(MyQueue *obj) {
    if (obj == NULL) return ;
    free(obj->data);
    free(obj);
    return ;
}

typedef struct {
    MyQueue *q1, *q2;//定义两个队列来模拟栈
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    int size  =1024;//由于要初始化两个队列空间，暂时设定队列大小为1024
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->q1 = MyQueueCreate(size);
    s->q2 = MyQueueCreate(size);
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (!MyQueueEmpty(obj->q1)) {
        MyQueuePush(obj->q1, x);//判断栈1否为空，为空则直接插入到栈1中
    } else {
        MyQueuePush(obj->q2, x);//否则插入到队列2中，便于弹栈
    }
    return ;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    MyQueue *p = MyQueueEmpty(obj->q1) ? obj->q2 : obj->q1;//如果队列1为空p指向队列2
    MyQueue *q = MyQueueEmpty(obj->q1) ? obj->q1 : obj->q2;//如果队列1为空q指向队列1
    int element = MyQueueFront(p);//对应栈顶元素就是对应队列p的头元素，记录栈顶元素
    MyQueuePop(p);//栈顶元素出栈
    while (!MyQueueEmpty(p)) {//把队列p中的元素全部放到队列q中去
        MyQueuePush(q, element);
        element = MyQueueFront(p);
        MyQueuePop(p);
    }
    return element;//返回的是栈顶元素
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    MyQueue *p = MyQueueEmpty(obj->q1) ? obj->q2 : obj->q1;
    MyQueue *q = MyQueueEmpty(obj->q1) ? obj->q1 : obj->q2;//通入队列操作一样
    int element;//但是不需要记录对应队列元素
    while (!MyQueueEmpty(p)) {
        element = MyQueueFront(p);
        MyQueuePop(p);//把队列p中元素全部转移到队列q中去，并且释放队列p中元素
        MyQueuePush(q, element);
    }
    return element;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return MyQueueEmpty(obj->q1) && MyQueueEmpty(obj->q2);//判断两个队列是否都为空
}

void myStackFree(MyStack* obj) {
    if (obj == NULL) return ;
    MyQueueFree(obj->q1);
    MyQueueFree(obj->q2);
    free(obj);
    return ;
}
