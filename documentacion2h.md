# .h

```
#ifndef SLLLIST_H
#define SLLLIST_H

#include <iostream>
#include <utility>

template<typename Object>
class SLList {
public:
    struct Node {
        Object data;
        Node *next;

        Node(const Object &d = Object{}, Node *n = nullptr);

        Node(Object &&d, Node *n = nullptr);
    };

public:
    class iterator {
    public:
        iterator();

        Object &operator*();

        iterator &operator++();

        const iterator operator++(int);

        bool operator==(const iterator &rhs) const;

        bool operator!=(const iterator &rhs) const;

    private:
        Node *current;

        iterator(Node *p);

        friend class SLList<Object>;
    };

public:
    SLList();

    SLList(std::initializer_list <Object> init_list);

    ~SLList();

    iterator begin();

    iterator end();

    int size() const;

    bool empty() const;

    void clear();

    Object &front();

    void push_front(const Object &x);

    void push_front(Object &&x);

    void pop_front();

    iterator insert(iterator itr, const Object &x);

    iterator insert(iterator itr, Object &&x);

    iterator erase(iterator itr);

    void print();

private:
    Node *head;
    Node *tail;
    int theSize;

    void init();
};

#include "SLList.cpp"

#endif
```

> al principio del .h esta definiendo que si no esta definido el slllist.h que lo defina
>y luego incluye bliblotecas para utilizar en el .h
> y luego aparece un template, que nos ayudara a modificar a futuro
> y luego empieza la clase listado, y empezamos en esta con empezando referenciando el nodo y esta por dentro
> habla sobre objetos y como el nodo pasa al siguiente y tiene un constructor que pone un indicador en nulo y se guardara
> y en la otra muestra el resultado
>// y en la otra habre un iterador que nos ayuda a mover la lista
> // y luego nos da un operador que ayuda a sobreescribir y en de abajo nos ayuda  a que cuando termine baje y gracias al iterador podemos cambiar los valores
> //y esta estamos diciendo que cada linea se convertira un valor sin embargo no sera lo que escribimos y la informacion
>// y luego checa que si es verdadero el operador que si lo movio correctamente y mas abajo checa si el operador si a cambiado
> // y luego en el primer privado nos menciona que el nodo que hace mencion al iterador
> //y luego en el parte friend perimte que la clase iterador permita que la clase sllist pueda ir a la varriable current
> //y luego empiezan hacer constructores y destructores de SLList
> //y luego empiezan un monton constructores algunos siendo void esperando siendo llamados, iteradores para volver hacia los objetos
> //y luego en la ulitma seccion del privado nos dicen que que iran de arriba a abajo de la lista y checaran tambien los lados
> //y crean un void que conecta practicamente desde arriba hasta abajo
> //y lo ultimo meten SLList.cpp y se acaba la definicion