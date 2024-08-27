/*
stack ���� ����

�ڷᱸ��, Linked List (doubly linked list)


- push 
- pop 
- size 
- empty 
- top 

// 1st trial issue, ��ɾ� �����ߴٰ� ����ϴ� ��
// 2nd trial issue, push ����� ���� ���� (find, stoi)
https://cplusplus.com/reference/string/string/substr/
https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c

*/

#include <iostream>
#include <string>
 
using namespace std; 


struct node
{
    int value; 
    node* next; 
    node* pre; 
}; 

class stack
{
    private:
    int size; 
    node* curr; 

    public: 
    stack()
    {
        size = 0;  
        node* start = new node; 
        start->next = start->pre = nullptr; 
        curr = start;     
    };

    void push(int num)
    {
        node* elem = new node; 
        elem->value = num; 

        curr->next = elem; 
        elem->pre = curr; 
        elem->next = nullptr; 
        curr = curr->next;
        size++; 
    }; 

    void pop()
    {
        if(empty() != 1)
        {
            node* temp = curr; 
            curr->pre->next = nullptr; 
            curr = curr->pre; 
            cout << temp->value << endl; 
            delete temp; 
            size--;
        }
        
        else
        {
            cout << -1 <<endl; 
        }
    }; 

    void getsize(){cout << size << endl;}; 
    int empty(){ return (curr->pre == nullptr) ? 1 : 0;}; 
    void top(){if(empty() != 1){cout << curr->value;} else{cout << -1;} cout << endl;}; 

    ~stack(){if(empty() != 1)
    {
         while(size>0)
         {  
            node* temp = curr; 
            curr->pre->next = nullptr; 
            curr = curr->pre; 
            delete temp; 
            size--;
        }} delete curr;}
}; 


int main()
{
    int N; 
    stack mystack; // class ���� ���
  
    cin >> N; 
    cin.ignore(); 

    string result[N];


    for(int i = 0; i < N; i++)
    {
        string command; 
        getline(cin, command); 
        result[i] = command; 
    }

    for(int i = 0; i < N; i++)
    {        
        if(result[i].find("push") != std::string::npos)
        {
            string num = result[i].substr(result[i].find(" ")); 
            int in = stoi(num); 
            mystack.push(in);
        }
        if(result[i] == "top"){mystack.top();}
        if(result[i] == "pop"){mystack.pop();}
        if(result[i] == "empty"){ cout << mystack.empty() << endl;}
        if(result[i] == "size"){mystack.getsize();}
    }

    return 0; 
}