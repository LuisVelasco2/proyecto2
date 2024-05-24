# AVItree
## .h
>primero el codigo
```
#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;
    int height;
};

class AVLTree {
    public:
    void printTree() {
        printTree(root, 0, 10);
    }
private:
    Node* root;

    int getNodeHeight(Node* N) {
        if (N == nullptr)
            return 0;
        return N->height;
    }

    int maxHeight(int a, int b) {
        return (a > b)? a : b;
    }

    Node* newNode(int value) {
        Node* node = new Node();
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;
        node->height = 1;
        return(node);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = maxHeight(getNodeHeight(y->left), getNodeHeight(y->right)) + 1;
        x->height = maxHeight(getNodeHeight(x->left), getNodeHeight(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = maxHeight(getNodeHeight(x->left), getNodeHeight(x->right)) + 1;
        y->height = maxHeight(getNodeHeight(y->left), getNodeHeight(y->right)) + 1;

        return y;
    }

    int getBalance(Node* N) {
        if (N == nullptr)
            return 0;
        return getNodeHeight(N->left) - getNodeHeight(N->right);
    }

    Node* insertNode(Node* node, int value) {
        if (node == nullptr)
            return(newNode(value));

        if (value < node->value)
            node->left = insertNode(node->left, value);
        else if (value > node->value)
            node->right = insertNode(node->right, value);
        else
            return node;

        node->height = 1 + maxHeight(getNodeHeight(node->left), getNodeHeight(node->right));

        int balance = getBalance(node);

        if (balance > 1 && value < node->left->value)
            return rightRotate(node);

        if (balance < -1 && value > node->right->value)
            return leftRotate(node);

        if (balance > 1 && value > node->left->value) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && value < node->right->value) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    Node* deleteNode(Node* root, int value) {
        if (root == nullptr)
            return root;

        if ( value < root->value )
            root->left = deleteNode(root->left, value);
        else if( value > root->value )
            root->right = deleteNode(root->right, value);
        else {
            if( (root->left == nullptr) || (root->right == nullptr) ) {
                Node *temp = root->left ? root->left : root->right;

                if(temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;

                delete temp;
            }
            else {
                Node* temp = minValueNode(root->right);

                root->value = temp->value;

                root->right = deleteNode(root->right, temp->value);
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + maxHeight(getNodeHeight(root->left), getNodeHeight(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void deleteTree(Node* node) {
        if (node == nullptr)
            return;

        deleteTree(node->left);
        deleteTree(node->right);

        delete node;
    }

public:
    AVLTree() : root(nullptr) {}

    ~AVLTree() {
        deleteTree(root);
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }

    void inorderTraversal(Node* node) {
        if (node == nullptr)
            return;

        inorderTraversal(node->left);
        std::cout << node->value << " ";
        inorderTraversal(node->right);
    }

    void preorderTraversal(Node* node) {
        if (node == nullptr)
            return;

        std::cout << node->value << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(Node* node) {
        if (node == nullptr)
            return;

        postorderTraversal(node->left);
        postorderTraversal(node->right);
        std::cout << node->value << " ";
    }
    void printTree(Node* root, int space = 0, int COUNT = 10) {
        if (root == nullptr) {
            return;
        }

        space += COUNT;
        printTree(root->right, space);

        std::cout << std::endl;

        for (int i = COUNT; i < space; i++) {
            std::cout << " ";
        }

        std::cout << root->value << "\n";

        printTree(root->left, space);
    }
};


#endif // AVLTREE_H


```

> ahora el codigo
- empezamos con su definicion  y luego mete la blibloteca que vamos a utilizar
- y luego define una estructura Node que es un nodo para el árbol AVL
- y cada nodo contiene un valor con punteros a los nodos izquierdo y derecho
- y la altura del nodo
- y luego se cra la clase AVLTree que imprime la ruta de 0 a 10
- y luego cierran para crear lo privado lo que anda de la clase y esta lo que crea es que nodo
- es igual a ruta
- y luego dice que el nodo va ser N y que si N da a un puntero nulo regresara hacia arriba
- y luego pone una crea  una funcion que practicamente regresa si es que uno es mayor que el otro lo cambiara para que sean parejos
- y luego mas abajo dicen que el nodo va hacer un nuevo nodo y le pondra un valor, en este caso dice que tanto a la izquierda y derecha seran nulos
- y que las ramas seran solo uno y que vuelvan a nodo
- y luego habla sobre como hace una rotación para la derecha en el arbol.
- y luego mas abajo es lo mismo pero para la izquierda
-  y luego crean getBlance que es practicamente  un Nodo con N y dice que si node es nulo vuelva a new nodo con valor
- lo que practicamente tenga un balance y evite que tenga uno mas si es posible, si tiene uno mas movera el arbol para que este balanceado
- cuanto es el blance si este pasa de 1 o -1 y luego regresa a nodo
- y luego se crea una funcion se creo queda el valor minino, que practicamente hara que un valor nulo
- y luego habla sobre como borrar un nodo y es que si el valor es mayor se borrara para lograr reacomodarlo todo
- y si tenemos que mencionar paso a paso esta checando los valores y si es que la ruta es mas grande que el valor practicamente lo va borrar
- y si no  borrara la parte de la derecha (lo anterior se hacia si pero en la izquierda)
- y si la ruta izquierda y derecha es igual a nulo entonces va a ver que si es la expresión condicional. Si ruta de la izquierda no es nulo, entonces devuelve ruta de la derecha
- y si el temporal es nula entonces la ruta tambien es nula y tambien la ruta es por que temp entonces se borrara el temporal
- y tambien si no nodo por temp va ser igual al valor del nodo por la derecha
- y el valor de ruta que es valor va ser igual temp por valor
- y la ruta de la derecha va borrar tanto su temporal valor y la rama de la derecha}
- y si la ruta da nula pues volvera a root y luego la ruta va a ser una ves mas larga haciendo un nodo mas
- y luego habla del balance chencando si tiene el balance correcto el arbol si es asi para no borralo y mantenerlo y si es asi pues borrar para luego crear
- y luego habla de borrar el arbol en un void que en pocas palabras borra el lado derecho y izquierdo del arbol
- y luego habla que en publico sobre ruta que tiene nulo por dentro y luego poenn como borrar el arbol de la ruta
- y luego tiene para meter rutas para el arbol que practicmaente ponen nodo que son rutas con valores y luego para remover que solo borra un nodo y es a un valor (no todo el arbol como el deleteTree)
- y luego toca el void pre ordenar el camino donde se checa el nodo izquierda y derecha y su valor para saber donde se va poner
- y luego habla del despues de ordenar y es que si el nodo es nulo que entonces refrese  y luego lo que hace es ver tanto el nodo de la izquierda y la derecha y va poner el valor 
- y ya casi por ultimo imprime el arbol, el valor de la derecha y izquierda  y que le de un espacio y por ultimo termina la definicion
