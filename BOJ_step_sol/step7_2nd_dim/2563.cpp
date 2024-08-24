/*
��ü ũ�� 100 100 
������ 10, ���簢�� 

���� ������ �𼭸� ��ġ, ������ �𼭸� y + 10 ��ġ ����
��ġ�� ���� ���Ͽ� �����ϸ� �Ǵ� ���� 
-> sol �����̰� �ٸ� �������� ������ �ִ��� �Ǻ��ϴ� �Լ� 
-> ��ġ�� ���� ������, ���� 


2���� �迭
- ��ü ��ȭ�� ũ�� 100 * 100; 
- ��ĥ�� �κи��� ���ϴ� ����; 

- �־��� index�κ��� 10 * 10 ���� ��ĥ�ϴ� �Լ� 
- ��ĥ�� �κ� count 
- ��ĥ�� �κ����� Ȯ���ϴ� �Լ� 


O(n^2) // n: 100 100 * 100 < <1��> ���� ��밡�� 

*/

#include <iostream>
#define Size 100

using namespace std; 

void markarea(bool** board, int x, int y )
{
    int dx =  x; 
    int dy = (100 - y) - 10; 

    for(int i = 0; i < 10; i++)
    {
        for(int j =0; j < 10; j++)
        {
            if(board[dy + i][dx + j] == false)
            {
                board[dy + i][dx + j] = true; 
            }
        }
    }
}

int main()
{
    bool** board = new bool*[Size]; 
    for(int i = 0; i < Size; i++)
    {
        board[i] = new bool[Size]; 
    } 

    for(int i = 0; i < Size; i++)
    {
        for(int j = 0; j < Size; j++)
        {
            board[i][j] = false; 
        }
    }

    int color_p_num; 

    cin >> color_p_num; 
    for(int i = 0; i < color_p_num; i++)
    {
        int x, y; 
        cin >> x >> y; 
        markarea(board, x, y); 
    }


    int area = 0; 
    for(int i = 0; i < Size; i++)
    {
        for(int j =0; j < Size; j++)
        {
            if(board[i][j] == true) area++; 
        }
    }

    cout << area; 

    for(int i = 0; i < Size; i++)
    {
        delete board[i]; 
    } 
    delete[] board; 
    return 0; 
}