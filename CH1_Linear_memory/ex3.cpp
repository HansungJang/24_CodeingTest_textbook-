// # remove_if �Լ� ���� (Ư�� ���ǿ� �ش��ϴ� ���� ����)

#include <string>
#include <iostream>
#include <forward_list>


using namespace std; 


struct citizen
{
    string name; 
    int age; 
}; 

ostream &operator<<(std::ostream &os, const citizen &c)
{
    return (os << "[" << c.name << ", " << c.age << "]"); 
}


void print_citizen(forward_list<citizen> citizens)
{
    for(const auto &c : citizens)
        cout << c << " ";
    cout << endl; 
}

int main()
{
    forward_list<citizen> citizens = {{"kim", 22}, {"Cim", 16}, {"aim", 28},{"dim", 14}}; 
    auto citizens_copy = citizens; 

    cout << "Total citizen: "; 
    print_citizen(citizens); 
    // for(const auto &c : citizens)
    //     cout << c << " ";
    // cout << endl; 

    
    // #1. remove_if ���� 
    // ��ǥ���� ���� �ù� (age < 19) ������ �ù� ���� 
    // remove_if�� ������ �����ϴ� member�� ������. 

    citizens.remove_if([](const citizen &c)
    {
        return (c.age < 19); 
    });  
    print_citizen(citizens);

    // #2. û�ҳ� ���
    citizens_copy.remove_if([](const citizen &c)
    {
        return (c.age > 19); 
    });  
    print_citizen(citizens_copy);

    return 0; 
}