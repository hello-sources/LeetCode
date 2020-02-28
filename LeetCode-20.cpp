//code 1
typedef struct Stack {
    char *data;
    int top, size;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (char *)malloc(sizeof(char) * n);
    s->top = -1;
    s->size = n;
    return s;
}

int empty(Stack *s) {
    return s->top == -1;
}

int front(Stack *s) {
    return s->data[s->top];
}

int expand(Stack *s) {
    int extr = s->size;
    int *p;
    while (extr) {
        p = (int *)realloc(s->data, sizeof(extr + s->size));
        if (p) break;
        extr /= 2;
    }
    if (p == NULL) return 0;
    s->size += extr;
    s->data = p;
    return 1;
}

int push(Stack *s,char val) {
    if (s == NULL) return 0;
    if (s->top + 1 == s->size) {
        if (!expand(s)) return 0;
    }
    s->data[++(s->top)] = val;
    return 1;
}

int pop(Stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    s->top--;
    return 0;
}

char seek(Stack *s) {
    return s->data[s->top];
}

void clear(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

bool isValid(char * s){
    int len  = strlen(s);
    Stack *stack = init(len);
    for (int i = 0; i < len; i++) {
        switch (s[i]) {
            case '(':
            case '[':
            case '{': {
                push(stack,s[i]);
                break;
            }
            case ')': {
                if (empty(stack)) return false;
                if (seek(stack) != '(') return false;
                pop(stack);
                break;
            }
            case ']': {
                if (empty(stack)) return false;
                if (seek(stack) != '[') return false;
                pop(stack);
                break;
            }
            case '}': {
                if (empty(stack)) return false;
                if (seek(stack) != '{') return false;
                pop(stack);
                break;
            }
        }
    }
    return empty(stack);
}

//code 2
//用数组模拟栈
bool isValid(char *s) {
    int len = strlen(s);//首先求出字符串长度，好用来动态开辟数组空间
    char *stack = (char *)malloc(sizeof(char) * len);
    int top = -1, flag = 1;//用flag标记，栈顶元素标记为-1
    while (s[0]) {
        switch (s[0]) {
            case '(':
            case '[':
            case '{': stack[++top] = s[0]; break;//模拟对应左括号入栈操作
            case ')': flag = (top != -1 && stack[top--] == '('); break;//栈不为空，且栈顶元素对应为左括号，使得左右括号匹配上，更新flag
            case ']': flag = (top != -1 && stack[top--] == '['); break;
            case '}': flag = (top != -1 && stack[top--] == '{'); break;
        }
        if (!flag) break;//判断对应的flag如果flag为0，表示有不匹配的括号
        s++;//否则继续向传入数组下一个移动
    }
    free(stack);//释放申请的空间
    return (flag && top == -1);//最后判断栈是否为空，且对应标记为1，表示都匹配成功
}
