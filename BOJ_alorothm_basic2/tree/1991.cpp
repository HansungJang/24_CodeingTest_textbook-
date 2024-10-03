/*
1. ���̵��
- struct �̿��Ͽ� node ����  
- DLL �̿��Ͽ�, tree rnwh rngus 
- main�Լ����� �Է¹��� Node ���� ���ĺ� ������ ���� 
- ���� ���� branching, ���� node�� A ���� ������ node fix 
- VLR: ��� -> L -> R (����Լ�, nullptr, return)
- LVR: stack -> L -> ��� -> R 
- LRV: stack -> L -> R -> ��� 
stack �̿��Ͽ� ���� 

2. ����ð�
����Լ� ������ max Node�� ���� : 26
O(2^n) ��� �ص� < 1�� 
��밡��  

3. �ڷᱸ��
- stack
- DLL 
- tree 
- ��� 

*/

#include <iostream>

using namespace std; 

struct Node 
{
    char letter; 
    Node* left; 
    Node* right; 
}; 

class Tree_table
{
    private: 
        Node* initial;
        Node* start;  

    public: 
    Tree_table(int size)
    {
        initial = new Node[size];
        start = initial; 

        // 1. intialize Node 
        for(int i  = 0; i < size; i++)
        {
            initial[i].letter = 65 + i; 
            initial[i].left = nullptr; 
            initial[i].right = nullptr; 
        } 
    }

    void Linked_node(char parent, char leftAlp, char rightAlp)
    {
        int nodenum = parent - 65; 
        if(leftAlp != '.') initial[nodenum].left = &initial[leftAlp - 65]; 
        if(rightAlp != '.') initial[nodenum].right = &initial[rightAlp - 65];         
    }

    void VLR(Node* parent)
    { 
        if(parent == nullptr) return; 
        printf("%c", parent->letter); 
        VLR(parent->left); 
        VLR(parent->right); 
    }

    void LVR(Node* parent)
    {
        if(parent == nullptr) return; 
        LVR(parent->left); 
        printf("%c", parent->letter); 
        LVR(parent->right); 
    }

    void LRV(Node* parent)
    {
        if(parent == nullptr) return; 
        LRV(parent->left); 
        LRV(parent->right);
        printf("%c", parent->letter);  
    }

    Node* getStart()
    {
        return start; 
    }

    ~Tree_table()
    {
        delete[] initial; 
    }

}; 



int main()
{
    int size = 0; 
    cin >> size;
    Tree_table tree(size);

    for(int i = 0; i < size; i++)
    {
        char parent, left, right; 
        cin >> parent >> left >> right; 
        tree.Linked_node(parent, left, right); 
    } 

    Node* start = tree.getStart(); 
    tree.VLR(start); cout << endl;
    tree.LVR(start); cout << endl;
    tree.LRV(start); 


    return 0; 
}