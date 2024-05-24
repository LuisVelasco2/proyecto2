# tree 
## .h
> mencionaremos primero el codigo y leugo documentamos
```
#ifndef TREE_H
#define TREE_H

#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* firstChild;
    Node* nextSibling;

    explicit Node(T data);
};

template <typename T>
class Tree {
public:
    Node<T>* root;

    Tree();

    Node<T>* addNode(T data, Node<T>* parent = nullptr);

    void printTree(Node<T>* node, int level = 0);
};

#include "Tree.cpp"

#endif //TREE_H
```



> empezamos  con la documentacion
- obviamente empieza diciendo que si no se encuentra la definicion tree.h lo va definir
- luego mete la blibloteca que utilizara en el codigo
- y luego pone un template que sera llamado con T
- y luego empieza la clase Node, que dentro de este esta el publico
- dentro habla que t es un data
- del nodo puede tener hijos y tambien hermanos (obviamente creando un nuevo nodo)
- se llama de nuevo un template
- la clase arbol empieza
- aqui se habla de un constructor llamado arbol, y luego los siguientes son para hacer celdas
- y luego meten el tree.cpp y termina la definicion