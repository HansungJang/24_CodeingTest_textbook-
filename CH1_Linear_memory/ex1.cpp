// #  Goal: '���� ũ�� �迭' ���� (���� �޸� �Լ�)

// keywords: ����/���� ����, operator�� ����� wrapper class����

// ���Ӱ� �˰Ե� ����:
// 1. sstream(ostringstram / �پ��� Ÿ���� ���ڿ��� ��ȯ ����),
// 2. friend (private, protected ����� ������ �� ����),
// 3. ' ... '�� �ǹ�  (try-catch������ ��� ���ܸ� ó��)


// input: �л���, �л� ���� 
// design: �迭 
// function: �پ��� ũ�� �迭, �������� �ϳ��� ��ġ�� ���

#include <iostream>
#include <sstream> // string type �Է� 
#include <algorithm>
#include <string>

using namespace std; 


template <typename T> // ������ ���� 
class dynamic_array
{
    T* data; 
    size_t n;

    //�迭 ũ�⸦ ���ڷ� �޴� ������
    public: 
        dynamic_array(int n)
        {
            this->n = n; 
            this->data = new T[n]; 
        }


    //���� ������
        dynamic_array(const dynamic_array<T>& other)
        {
            this->n = other.n;
            this->data = new T[n]; 
            
            // int i = 0; 
            // for(T elem : other.data)
            // {
            //     this.data[i++] = elem; 
            // }

            for(int i = 0; i < n; i++)
            {
                data[i] = other[i];
            } 
        }  


        // member ������ ���� �ϴ� �Լ� 
        T& operator[](int index) // ���� �������� read, write (O)
        {
            return data[index]; 
        }

        const T& operator[](int index) const // only read 
        {
            return data[index]; 
        }

        T& at(int index) // java style 
        {
            if(index < n)
                return data[index]; 
            throw "Index is out of range"; 
        }

        size_t size() const 
        {
            return n; 
        }

        // �ݺ��� ��ȸ�� ���� �ݺ��� ���� �Լ� 
        T* begin() {return data;}
        const T* begin() const {return data;}
        T* end() {return data + n;}
        const T* end() const {return data + n;}

        // �� ���� �ϳ��� ��ġ�� �Լ� 
        friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
        {
            dynamic_array<T> result(arr1.size() +  arr2.size());
            copy(arr1.begin(), arr1.end(), result.begin());
            copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

            return result;  
        }

        // ���ڿ� ���� 
        string to_string(const string& sep = ", ")
        {
            if(n == 0) return ""; 

            ostringstream os; 
            // for(T elem : data)
            for(int i = 0; i < n; i++)
            {
                os << data[i]; 
                if(i < (n-1)) os << sep; 
                
            } 

            return os.str(); 

        }


        ~dynamic_array()
        {
            delete[] data; 
        }

}; 


struct student
{
    string name; 
    int age;  
}; 

ostream& operator<<(ostream& os, const student& s)
{
    return (os<< "[" << s.name << "," << s.age << "]"); 
}

int main()
{
    int nStudents; 
    cout << "1st class student number : "; 
    cin >> nStudents; 
    dynamic_array<student> class1(nStudents);
    for(int i = 0; i < nStudents; i++)
    {
     //   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        string name; 
        int age; 
        cin.ignore();

        cout << (i+1) << "th stdent name : "; 
        getline(cin, name); 
        cout << (i+1) << "th stdent age : "; 
        cin >> age;  

        class1[i] = student{name, age}; 
    }

// ���� �߻� ���� 
    try
    {
        class1.at(nStudents) = student{"John", 8}; 
    }catch(...)
    {
        cout << "exception throw!" << endl; 
    }

// ���� ���� (only value)

    cout << "���� ���� " <<  endl;  
    auto class2 = class1; 

    cout << "1���� �����Ͽ� 2�� ����" << endl;
    cout << "1�� ���� : " << class1.to_string() << endl; 
    cout << "2�� ���� : " << class2.to_string() << endl;

    class2[0].age = 99; 

    cout << "1�� ���� : " << class1.to_string() << endl; 
    cout << "2�� ���� : " << class2.to_string() << endl;

    cout << endl; 

// ���� ���� 
    cout << "���� ���� " << endl;  
    auto* class3 = &class1;

    cout << "1���� �����Ͽ� 3�� ����" << endl;
    cout << "1�� ���� : " << class1.to_string() << endl; 
    cout << "3�� ���� : " << class2.to_string() << endl;

    (class3->begin()->age) = 98; 

    cout << "1�� ���� : " << class1.to_string() << endl; 
    cout << "3�� ���� : " << (*class3).to_string() << endl;


    cout << endl; 

//  �� �б��� ��ġ�� ���� 
    auto class4 = class1 + class2; 
    cout << "1, 2���� ���� 4�� ���� : " << class4.to_string() << endl; 

}