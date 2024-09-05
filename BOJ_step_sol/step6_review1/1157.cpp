/*
���� ���� ���� �ܾ� ���� ��� 

1. ���̵��
- ���ڿ� ascii �ڵ� ��ȯ
- index�� count, �ִ� ��ȣ �ε��� ���

2. �ð����⵵ 
- O(N) , �Է¹��� ���ڿ��� ����, ���ĺ� ���� 
max N << 1�� ��밡�� 

3. �ڷᱸ�� 
- �迭 

*/

#include <iostream>
#define alpsize 26 

using namespace std; 

void Convert(string& str1)
{
    for(int i = 0; i < str1.length(); i++)
    {
        char elem = str1[i];
        if(elem >= 97 && elem < 123) // �ҹ����� ���
        {
            elem -= 32;
            str1[i] = elem; 
        }
    }
}

int* Countalp(string& str1)
{
    int alp[alpsize] = {0, }; 
    int* alpptr = alp; 

    for(int i = 0; i < str1.length(); i++)
    {
        int elem_index = str1[i] - 65; 
        alp[elem_index]++; 
    }

    return alpptr; 
}


char Findmax(int* alp)
{
    int max = 0; 
    int multi = 0; 
    char max_char; 

    for(int i = 0; i< alpsize; i++)
    {
        if(max < alp[i])
        {
            multi = 0; 
            max = alp[i]; 
            max_char = i + 65; 
        }

        else if(max == alp[i] && max > 0)
        {
            multi = 1; 
            max_char = '?'; 
        }
    }

    return max_char; 
} 

int main()
{
    string input; 
    char max; 
    int* alplist; 

    getline(cin, input); 
    Convert(input); 
    alplist = Countalp(input);
    max = Findmax(alplist); 

    cout << max; 
    return 0; 
}