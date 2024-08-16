#include <iostream>
#include <algorithm>

// �ڵ� ����! �� ����ü�� �Լ����� ���� ��ġ�� ���� �����ִ�. 
// ���� 1. ����ü�� �Լ��� ���� ���� �� ��ġ ����
// singly_ll_iterator�� ���� ��ġ�� ���� ��ġ�� class ���ο��� ���� ���� ����.
// ���� 2. private, public ���� ���� ���� 
using namespace std; 

struct singly_ll_node
{
    int data; 
    singly_ll_node* next; 
};

// struct singly_ll_iterator; // iterator�� ���� forward ����
// struct singly_ll_iterator
// {
//     private: 
//         singly_ll::node_ptr ptr; 
//     public: 
//         singly_ll_iterator(singly_ll::node_ptr p) : ptr(p) {}
//         int& operator*() { return ptr->data; }
//         singly_ll::node_ptr get() { return ptr; }
//         singly_ll_iterator& operator++() // ���� ���� 
//         {
//             ptr = ptr->next; 
//             return *this; 
//         } 

//         singly_ll_iterator operator++(int) // ���� ���� 
//         {
//             singly_ll_iterator result = *this; 
//             ++(*this); 
//             return result; 
//         }

//         friend bool operator==(const singly_ll_iterator& left, singly_ll_iterator& right)
//         {
//             return left.ptr == right.ptr;
//         }

//         friend bool operator!=(const singly_ll_iterator& left, singly_ll_iterator& right)
//         {
//             return left.ptr != right.ptr;
//         }
// }; 



class singly_ll
{
    public: 
        using node = singly_ll_node; 
        using node_ptr = node*; 

    private: 
        node_ptr head = nullptr;

    // singly_ll(const singly_ll& other);
    // singly_ll(const std::initializer_list<int>& list);
    public: 
        struct singly_ll_iterator
        {
            private: 
                singly_ll::node_ptr ptr; 
            public: 
                singly_ll_iterator(singly_ll::node_ptr p) : ptr(p) {}
                int& operator*() { return ptr->data; }
                singly_ll::node_ptr get() { return ptr; }
                singly_ll_iterator& operator++() // ���� ���� 
                {
                    ptr = ptr->next; 
                    return *this; 
                } 

                singly_ll_iterator operator++(int) // ���� ���� 
                {
                    singly_ll_iterator result = *this; 
                    ++(*this); 
                    return result; 
                }

                friend bool operator==(const singly_ll_iterator& left, singly_ll_iterator& right)
                {
                    return left.ptr == right.ptr;
                }

                friend bool operator!=(const singly_ll_iterator& left, singly_ll_iterator& right)
                {
                    return left.ptr != right.ptr;
                }
        }; 

        void push_front(int val);
        void pop_front();
        singly_ll_iterator begin(){ return singly_ll_iterator(head); }
        singly_ll_iterator end() { return singly_ll_iterator(NULL); }
        singly_ll_iterator begin() const { return singly_ll_iterator(head); }
        singly_ll_iterator end() const { return singly_ll_iterator(NULL); }

        singly_ll() = default; 

        singly_ll(const singly_ll& other) : head(NULL)
        {
            if (other.head)
            { 
                head = new node{0, NULL}; 
                auto cur = head; 
                auto it = other.begin(); 
                while (true) {
                    cur->data = *it; 
                    auto tmp = it; 
                    ++tmp; 
                    if (tmp == other.end()) break; 
                    cur->next = new node{0, NULL};
                    cur = cur->next;
                    it = tmp; 
                }
            }
        }

        singly_ll(const std::initializer_list<int>& list) : head(NULL)
        {
            for (auto it = rbegin(list); it != rend(list); ++it) push_front(*it); 
        }


};



// singly_ll::singly_ll(const singly_ll& other) : head(NULL)
// {
//     if (other.head)
//     {
//         head = new node{0, NULL}; 
//         auto cur = head; 
//         auto it = other.begin(); 
//         while (true) {
//             cur->data = *it; 
//             auto tmp = it; 
//             ++tmp; 
//             if (tmp == other.end()) break; 
//             cur->next = new node{0, NULL};
//             cur = cur->next;
//             it = tmp; 
//         }
//     }
// }

// singly_ll::singly_ll(const std::initializer_list<int>& list) : head(NULL)
// {
//     for (auto it = rbegin(list); it != rend(list); ++it) push_front(*it); 
// }

void singly_ll::push_front(int val)
{
    auto new_node = new node{val, NULL}; 
    if (head != NULL)
        new_node->next = head; 
    head = new_node; 
} 

void singly_ll::pop_front()
{
    if (head != NULL)
    {
        node_ptr temp = head; 
        head = temp->next;
        delete temp; 
    }
}

int main()
{
    singly_ll sll = {1, 2, 3}; 
    sll.push_front(0); 

    cout << "1st list: "; 
    for (auto i : sll)
        cout << i << " "; 
    cout << endl; 

    auto sll2 = sll; 
    sll2.push_front(-1); 
    cout << "copy 1st list, after insert front (-1): ";
    for (auto i : sll2)
        cout << i << " "; 
    cout << endl;

    cout << "after deep copy : "; 
    for (auto i : sll)
        cout << i << " "; 
    cout << endl;  
    
    return 0; 
}
