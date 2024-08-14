// vector ���� (���� �޸� �Լ�)
// input: �л���, �л� ���� 
// design: �迭 
// function: �پ��� ũ�� �迭, �������� �ϳ��� ��ġ�� ���

#include <iostream>
#include <sstream> // string type �Է� 
#include <algorithm>

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
            
            int i = 0; 
            for(T elem : other.data)
            {
                this.data[i++] = elem; 
            } 
        }  


        // member ������ ���� �ϴ� �Լ� 
        T& operator[](int index) // ���� �������� read, write (O)
        {
            return this.data[index]; 
        }

        const T& operator[](int index) const // only read 
        {
            return this.data[index]; 
        }

        T& at(int index) // java style 
        {
            if(index < n)
                return this->data[index]; 
            throw "Index is out of range"; 
        }

        size_t size() const 
        {
            return this.n; 
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
            copy(arr1.begin(), arr1.end(), data.begin());
            copy(arr2.begin(), arr2.end(), data.begin() + arr1.size());

            return data;  
        }

        // ���ڿ� ���� 
        string to_string(const string& sep = ", ")
        {
            if(this.n == 0) return ""; 

            ostringstream os; 
            for(T elem : data)
            {
                os << elem; 
                if(elem != data[n-1]) os << sep; 
                
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
        string name; 
        int age; 
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