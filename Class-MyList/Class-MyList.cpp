#include <iostream>

template<typename T>
class List
{
private:
    struct Node
    {
        T element;
        Node* prev = nullptr;
        Node* next = nullptr;

    };

    Node* first = nullptr;
    Node* last = nullptr;

    int elementsCount = 0;
public:
    List() = default;

    List(const List<T>& l) //  конструктора копирования 
    {
        elementsCount = l.elementsCount;

        for (Node* temp = l.first; temp != nullptr; temp = temp->next)
        {
            PushBack(temp->element);
        }

    }
     
    void PushBack(const T& elem)
    {
        Node* node = new Node(elem, last, nullptr);

        if (last != nullptr)
        {
            last->next = node;
        }

        else
        {
            first = node;
        }

        last = node;
        ++elementsCount;
    }

    void PushFront(const T& elem)
    {
        Node* node = new Node(elem, first, nullptr);

        if (first != nullptr)
        {
            first->prev = node;
        }

        else
        {
            last = node;
        }

        first = node;
        ++elementsCount;

    }

    void PopBack()
    {
        if (last != nullptr)
        {
            Node* temp = last;
            last = last->prev;

            if (last != nullptr)
            {
                last->next = nullptr; // удаление 
            }

            else
            {
                first = nullptr;
            }

            delete temp;
            elementsCount--;
        }

    }

    void PopFront()
    {
        if (first != nullptr)
        {
            Node* temp = first;
            first = first->next;

            if (first != nullptr)
            {
                first->prev = nullptr;
            }

            else
            {
                last = nullptr;
            }

            delete temp;
            --elementsCount;

        }

    }

    size_t Size()const
    {
        return elementsCount;
    }

    void clear() 
    {
        while (elementsCount > 0) 
        {
            PopFront(); // или PopBack()
        }
    }

    List& operator= (const List& l) 
    {
        clear();

        Node* node;
        for (node = l.first; node != nullptr; node = node->next)
        {
            PushBack(node->element); 
        }

        elementsCount = l.elementsCount; 
        
        return *this;
    }

    const T& Front()const
    {
        return first->element;
    }


    bool Empty()const
    {
        return first == nullptr;
    }

    ~List()
    {
        clear();
    }
};



int main()
{
    List<int> l1;
    List<int> l2;
    l1.PushBack(1);
    l1.PushBack(2);
    l1.PushBack(3);
    l2.PushBack(4);
    l2.PushBack(7);
    l2.PushBack(7);
    l1 = l2;

    while (!l1.Empty())
    {
        std::cout << l1.Front() << std::endl;
        l1.PopFront();
    }


    return 0;
}
