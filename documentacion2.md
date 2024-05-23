# documentacion 2 
# .cpp
``` 
#include "SLList.h"

template<typename Object>
SLList<Object>::Node::Node(const Object &d, Node *n)
        : data{d}, next{n} {}

template<typename Object>
SLList<Object>::Node::Node(Object &&d, Node *n)
        : data{std::move(d)}, next{n} {}

template<typename Object>
SLList<Object>::iterator::iterator() : current{nullptr} {}

template<typename Object>
Object &SLList<Object>::iterator::operator*() {
    if(current == nullptr)
        throw std::logic_error("Trying to dereference a null pointer.");
    return current->data;
}

template<typename Object>
typename SLList<Object>::iterator &SLList<Object>::iterator::operator++() {
    if(current)
        current = current->next;
    else
        throw std::logic_error("Trying to increment past the end.");
    return *this;
}

template<typename Object>
typename SLList<Object>::iterator SLList<Object>::iterator::operator++(int) {
    iterator old = *this;
    ++(*this);
    return old;
}

template<typename Object>
bool SLList<Object>::iterator::operator==(const iterator &rhs) const {
    return current == rhs.current;
}

template<typename Object>
bool SLList<Object>::iterator::operator!=(const iterator &rhs) const {
    return !(*this == rhs);
}

template<typename Object>
SLList<Object>::iterator::iterator(Node *p) : current{p} {}

template<typename Object>
SLList<Object>::SLList() : head(new Node()), tail(new Node()), theSize(0) {
    head->next = tail;
}

template<typename Object>
SLList<Object>::SLList(std::initializer_list <Object> init_list) {
    head = new Node();
    tail = new Node();
    head->next = tail;
    theSize = 0;
    for(const auto& x : init_list) {
        push_front(x);
    }
}

template<typename Object>
SLList<Object>::~SLList() {
    clear();
    delete head;
    delete tail;
}

template<typename Object>
typename SLList<Object>::iterator SLList<Object>::begin() { return {head->next}; }

template<typename Object>
typename SLList<Object>::iterator SLList<Object>::end() { return {tail}; }

template<typename Object>
int SLList<Object>::size() const { return theSize; }

template<typename Object>
bool SLList<Object>::empty() const { return size() == 0; }

template<typename Object>
void SLList<Object>::clear() { while (!empty()) pop_front(); }

template<typename Object>
Object &SLList<Object>::front() {
    if(empty())
        throw std::logic_error("List is empty.");
    return *begin();
}

template<typename Object>
void SLList<Object>::push_front(const Object &x) { insert(begin(), x); }

template<typename Object>
void SLList<Object>::push_front(Object &&x) { insert(begin(), std::move(x)); }

template<typename Object>
void SLList<Object>::pop_front() {
    if(empty())
        throw std::logic_error("List is empty.");
    erase(begin());
}

template<typename Object>
typename SLList<Object>::iterator SLList<Object>::insert(iterator itr, const Object &x) {
    Node *p = itr.current;
    Node *newNode = new Node{x, p->next};
    p->next = newNode;
    theSize++;
    return iterator(newNode);
}

template<typename Object>
typename SLList<Object>::iterator SLList<Object>::insert(iterator itr, Object &&x) {
    Node *p = itr.current;
    Node *newNode = new Node{std::move(x), p->next};
    p->next = newNode;
    theSize++;
    return iterator(newNode);
}

template<typename Object>
typename SLList<Object>::iterator SLList<Object>::erase(iterator itr) {
    if (itr == end())
        throw std::logic_error("Cannot erase at end iterator");
    Node *p = head;
    while (p->next != itr.current) p = p->next;
    Node *toDelete = itr.current;
    p->next = itr.current->next;
    delete toDelete;
    theSize--;
    return iterator(p->next);
}

template<typename Object>
void SLList<Object>::print() {
    iterator itr = begin();
    while (itr != end()) {
        std::cout << *itr << " ";
        ++itr;
    }
    std::cout << std::endl;
}

template<typename Object>
void SLList<Object>::init() {
    theSize = 0;
    head->next = tail;
}
```

> //empezamos metiendo que este codigo va estar conectado con SLList.h
> //y luego en las primeras lineas del codigo declaramos Object como un template, osea
> que se pueda adaptar dependiendo del dato y en la otra linea lo leera lo que reciba de informacion
> del resultado
> //y mas abajo ponen iteradores que en pocas palabras son punteros que permiten
> leer o escribir valores hacia  los distintos elementos que hacen una lista. 
> //y luego lee lo que cambio de valores si es que hay para mostrarlos,
> //y un poco mas abajo hay dos bool que uno dice que si cambia la informacion o se sobreescribe que vuelva 
> //y el otro bool es para saber si a cambiado algo la informacion volver un poco hacia atras
> //y luego un poco mas abajo pondra lo que tendra el listado y que podra ser visitado por 
> la persona a gracias del iterador, y ma sabajo sigue complementandose lo que hara este listado
> con la cabeza siendo un nuevo nodo, osea un nuevo elemnto enlazado y al igual la cola y tambien se plantea que el 
> tamaño sea 0 por ahora y dice que la cabeza se enlace con la cola y mas abajo dicen que ambos tengan la funcion Node
> cosa que se vera en el .h continuando hay un ciclo for que pone en auto x, y se pondra en init_list y se hara una pequeña lista con x
> //y luego hay un destructor, que borra la cabeza y la cola
> //y luego en resumido pues empieza con el begin que es un iterador que apunta el primer elemnto de la lista y luego el sgundo el final de lista
> //y luego el de abajo retoma el tamaño de la lista, y luego mas abaja hay un bool y dice que si esta vacio si es que 0 entonces es verdadero
> no lo es si no es 0,
> //y luego el siguiente codigo  lo que dice es que si se activa
> lo que hara es que limpiara y dejara vacio hasta que la lista este vacia y luego vuelve si la lista esta vacia mandara un mensaje de error
> //y luego ponen un constructor que lo que hara, es reescribir informacion haciendo nuevos elementos y poniendolos en la lista
> y luego sumar la lista si es que se va hacer mas grande
>//y luego mas abajo se cambia  los datos poniendolos abajo y creando una nueva celda
> //y en esta parte del codigo, elimina la celda, junto con la informacion
> //y en la siguiente linea muestra la informacion al usuario desde el inicio hasta el final

