#ifndef TYPE_HXX
#define TYPE_HXX
#include <cstddef>      //  size_t
#include <stdexcept>    //  std::runtime_error

namespace type {
    /*  Так как очередь это тип данных, не зависящий от какого-то конкретного
        типа данных переменных, которые будут вложены в очередь, прямо как и 
        std::vector<Type>, то создаем шаблон для любого вложенного типа данных.    */
    template <typename AnyType>

    /*───────────────╮
    │  ТИП: ОЧЕРЕДЬ  │  
    ╰───────────────*/
    // Очередь - это контейнер, хранящий элементы в порядке их добавления.
    // Элементы извлекаются из очереди в том же порядке, в котором они были добавлены.
    class queue {
    private:
        struct Node {
            AnyType data;       //  Значение некого типа данных представлено как data
            Node* nextNode;     //  Указатель на следующий элемент очереди

            Node(const AnyType& data) : data(data), nextNode(nullptr) {}    
            /*  Конструктор элемента очереди. 
                Инициализирует данные элемента и устанавливает указатель на 
                следующий элемент в значение nullptr.   */
        };
        
        Node* frontNode;    //  Указатель на первый элемент очереди.
        Node* rearNode;     //  Указатель на последний элемент очереди.
        size_t size;        //  Размером (size) здесь назовем количество элементов очереди.

    public:
        /*  При создании объекта типа queue ставим нулевые указатели на
            первый и последний элементы, так как элементов в очереди еще нет,
            по той же причине размер очереди (количество элементов очереди)
            делаем нулевым.  */
        queue() : frontNode(nullptr), rearNode(nullptr), size(0) {}

        /*  Деструктор, который при вызове удаляет все элементы из 
            очереди, например после delete MyQueue; или по завершению программы.    */
        ~queue() {
            while (!isEmpty()) {
                pop();
            }
        }

        //  Проверка на наличие элементов в очереди.
        bool isEmpty() const {
            return size == 0;
        }

        //  Получение количества элементов в очереди.
        size_t getSize() const {
            return size;
        }

        //  Получение первого элемента очереди.
        const AnyType& getFirst() const {
            if (isEmpty()) {
                throw std::runtime_error("cannot get first item, type::queue is empty!");
            }
            return frontNode->data;
        } 

        //  Получение последнего элемента очереди.
        const AnyType& getLast() const {
            if (isEmpty()) {
                throw std::runtime_error("cannot get last item, type::queue is empty!");
            }
            return rearNode->data;
        }

        /*  Добавление элемента в очередь посредством создания
            нового элемента и добавления указателя (nextNode) на
            этот элемент в предыдущий элемент:
                1. Создаем новый элемент.
                2. Проверяем, пуста ли очередь.
                    2.1. Если очередь пуста, то присваиваем первому и последнему 
                    элементу значение нового элемента.
                    2.2. Если очередь не пуста, то:
                    rearNode->nextNode = newNode;
                        - Здесь мы берем указатель rearNode, который указывает на 
                        последний элемент очереди.
                        - Мы обращаемся к полю nextNode этого элемента и присваиваем
                        ему значение newNode.
                        - Таким образом, мы "присоединяем" новый элемент newNode к 
                        последнему элементу очереди, обновляя указатель nextNode
                        последнего элемента.
                    rearNode = newNode;
                        - После того, как мы "присоединили" новый элемент к последнему
                        элементу очереди, мы обновляем указатель rearNode, чтобы он
                        указывал на новый последний элемент, то есть на newNode.
                    Это позволяет нам добавлять новые элементы в конец очереди, сохраняя
                    правильную структуру очереди.
                3. Добавляем единицу к размеру (size) очереди.    */
        void push(const AnyType& value) {
            Node* newNode = new Node(value);
            if (isEmpty()) {
                frontNode = rearNode = newNode;
            } else {
                rearNode->nextNode = newNode;
                rearNode = newNode;
            }
            ++size;
        }

        /*  Удаление первого элемента очереди посредством привязки указателя
            первого элемента frontNode к следующему после этого frontNode элементу
            посредством frontNode = frontNode->nextNode;,
            а затем удалению предыдущего первого элемента с помощью 
            Node* temporaryNode = frontNode; delete temporaryNode;  */
        void pop() {
            if (isEmpty()) {
                throw std::runtime_error("cannot pop item, type::queue is empty!");
            }
            Node* temporaryNode = frontNode;
            frontNode = frontNode->nextNode;
            delete temporaryNode;
            if (frontNode == nullptr) {
                rearNode = nullptr;
            }
            --size;
        }
    };
}

#endif