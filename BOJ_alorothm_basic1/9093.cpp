/*
�ܾ� ������ 
- �ܾ��� ���� ���� / queue 
- �ܾ��� ���� / vector 

1. ���̵�� 
- for-loop ���鼭 ���ڿ� ���� queue 
- ������ ���ڿ� ���� �������� substr, find, vector  
- �¿���� / return string ���� �ް�  ( swap / vector.push_pop() ���� �̿�)
- queue.front() ���ڿ���  ���� ������ vector�� ����, vector.size() > 0 �ݺ� 

2. �ð����⵵ 
- O (n)
// ��ü ������ ��(n) * maximum �ܾ��� �� << 500  
// ����, TC << T(500 * n) �̹Ƿ� 
// ������ 1�ﲲ �̹��� ��� ������ ���� 

3. �ڷᱸ�� 
- �����ڷᱸ�� (queue, stack)
- queue, vector 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std; 


void swapWord(string word)
{
    vector<char> copy;
    for(int i = 0; i < word.length(); i++)
    {
        copy.push_back(word[i]); 
    }  

   while(copy.size() > 0)
    {
        cout << copy.back();
        copy.pop_back();  
    }
}


int main()
{
    int size; 
    queue<string> str_list; 

    cin >> size; 
    cin.ignore(); 
    for(int i = 0; i < size; i++)
    {
        string elem; 
        getline(cin, elem); 
        str_list.push(elem);
    }


    while(str_list.size() > 0)
    {
        string str1 = str_list.front(); 
        str_list.pop(); 

        while(str1.length() > 0)
        {
            size_t pos = str1.find_first_of(" ");
            string word = str1.substr(0, pos);
            str1 = str1.substr(pos + 1);

// �ܾ� �ݴ�� 
            swapWord(word); 
            cout << " ";  

            if(pos == str1.length())
            {
                swapWord(str1);
                break;
            }  // ���ڿ��� ������ ���� ��� ������ �ܾ�
        }
        if(str_list.size() > 0) cout << endl; 
    }
    return 0; 
}