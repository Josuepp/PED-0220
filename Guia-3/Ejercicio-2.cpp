#include <iostream>
using namespace std;

struct Node {
    int element;
    struct Node *next;
};
typedef struct Node *Stack;

void initialize(Stack *s) {
    *s = NULL;
}

bool empty(Stack *s) {
    return *s == NULL;
}

void push(Stack *s, int e) {
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->element = e;
    node->next = *s;

    *s = node;
}

void pop(Stack *s) {
    if (!empty(s)) {
        struct Node *node = *s;
        *s = (*s)->next;
        delete(node);
    }else {
        return;
    }
}

void showStack(Stack *s) {
    struct Node *node = *s;
    bool isEmpty = false;
    while (!isEmpty)
    {
        if (!empty(&node))
        {
            cout << node->element << " ";
            node = node->next;
        }else {
            isEmpty = true;
        }
    }
}

bool isPair(int num) {
    if (num % 2 == 0)
    {
        return true;
    }else
    {
        return false;
    }
}

int main() {
    Stack sp, si;
    initialize(&sp);
    initialize(&si);

    int n;
    cout << "Ingrese el tamaño de los arreglos; ";
    cin >> n;

    int a[n], b[n], prod[n];

    cout << "\n" << "Ingresando valores para el primer arreglo: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> a[i];
    }

    cout << "\n" << "Ingresando valores para el segundo arreglo: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> b[i];
    }

    cout << "\n" << "Almacenando productos: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Multiplicando a[" << i << "] x b[" << i << "]" << endl;
        prod[i] = a[i] * b[i];
    }
    
    cout << "\n" << "Verficando pares o impares para agregar a pilas: " << endl;
    for (int i = 0; i < n; i++) {
        if (isPair(prod[i]))
        {
            push(&sp, prod[i]);
        }else {
            push(&si, prod[i]);
        }
    }

    cout << "\n" << "Mostrando la pila de los pares" << endl;
    showStack(&sp);

    cout << "\n" << "Mostrando la pila de los impares" << endl;
    showStack(&si);

    cout << endl;
}