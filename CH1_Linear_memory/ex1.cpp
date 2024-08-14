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



        ~dynamic_array()
        {
            delete[] data; 
        }

}; 

