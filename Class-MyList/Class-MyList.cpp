#include <iostream>

template<typename T>
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
            elementsCount--;

        }

    }

    size_t Size()const
    {
        return elementsCount;
    }
};

int main()
{


    return 0;
}
