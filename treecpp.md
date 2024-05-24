# tree
## .cpp

> primero el codigo

```
#include "Tree.h"


template <typename T>
Node<T>::Node(T data) : data(data), firstChild(nullptr), nextSibling(nullptr) {}

template <typename T>
Tree<T>::Tree() : root(nullptr) {}

template <typename T>
Node<T>* Tree<T>::addNode(T data, Node<T>* parent) {
    Node<T>* newNode = new Node<T>(data);

    if(parent) {
        if(parent->firstChild) {
            Node<T>* sibling = parent->firstChild;
            while(sibling->nextSibling) {
                sibling = sibling->nextSibling;
            }
            sibling->nextSibling = newNode;
        } else {
            parent->firstChild = newNode;
        }
    } else {
        root = newNode;
    }

    return newNode;
}

template <typename T>
void Tree<T>::printTree(Node<T>* node, int level) {
    if(!node) return;

    for(int i = 0; i < level; i++) std::cout << "--";
    std::cout << node->data << '\n';

    printTree(node->firstChild, level + 1);
    printTree(node->nextSibling, level);
}

```


> ahora continuaremos con la explicacion del codigo
- empezamos metiendo el .h
- y luego metemos un template y va ser llamado por T
- y luego aclarar que los nodos tendran datos y estos datos si tienen hijos y hermanos seran estos con informacion nulas
- y esta sera un constructor
- y luego el arbol sra un contructor que marcara una root aunque en este caso tendra una ruta nula
- y luego llama otro template, y lo que dice datos t y nodo tendra la informacion de parent y seran un constructor
- y empiezan a declarar que newNode es nuevo nodo con datos
- y mas abajo dicen que si hay padres tienen que haber el primer hijo
- y dice tambien que los hermanos son los primeros hijos de los padres
- y dice que van hacer un while que si hay hermanos va ver otros hermanos y hay un puntero que apunta otro hermano
- y mas abajo dice que si hay mas hermanos se crean un nuevo nodo
- y si no los primeros hijos de nuevo nodo crearan un nuevo nodo oviamente despues de los padres
- y si no los root crearan un nuevo nodo
- y vuelve a newNode
- y por casi terminar, tiene otro template llamandolo
- este lo que hace es un void  llamado tree que practicamente lo que hace resumidamente
- crea una funcion llamado prinTree cual sera un constructor y crea una variable un level
- y dice que si es diferente a node regrese a que sea diferente
- y luego crea un for y crea que 1 sea igual a 0 y sera diferenciado con los level de cuantos haiga y la i tiene que ser mayor que esto para que esto pare suamndose  1 a 1
- y luego dice que el nodo va tener datos para luego y un salto de linea y lo va imprimir 
- y el luego se ejecuta el printTree, que con un constructor, hara un nodo tendra el primer hijo y sumara en 1, y un poco mas abajo dice que el nodo va ser el proximo hermano sea un nivel
