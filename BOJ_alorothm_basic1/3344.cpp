/*
N-Quuen ���� ���� 
�ش� ������ ���  ������Ű�� quene�� �ڸ� index ����ϸ� ��. 

- N���� ���� 1���� �����ϴ� Ǯ�̷� ����
- ������ ù��° �࿡ ���� ��ġ;
- ���Ŀ� 2��° ����� 4���� ���ǿ� ������ Ȯ���ϸ� �´ٸ� ���������� �Ѿ

2. �ð����⵵; O(N^2)
- 1 ~ (n-1)�� ���� for-loop���� ��ȸ, 
- 0 ~ (n-1)��°�� colum�� <4���� ������ �����ϸ�> �ش� �ε��� ����, ���������� �̵�


3. �ڷᱸ��; GREEDY or DP 


condition
1. ��� �࿡�� �ּ� 1���� queen�� �ִ�.
2. ��� �࿡ 1�� �ʰ��ϴ� queen�� ������ �ȵȴ�.
3. ��� ���� 1�� �ʰ��ϴ� queen�� ������ �ȵȴ�. 
4. �밢�� �� (������) 1�� �ʰ��ϴ� queen�� ������ �ȵȴ�.
5. �밢�� �� (����) 1�� �ʰ��ϴ� queen�� ������ �ȵȴ�.

*/


#include <iostream>
#include <queue>
#include <ctime> // ���۽ð� ���� �ٲ�� �ϱ� ���ؼ� 
#include <cstdlib> // random 

using namespace std; 


bool condition1(bool** board, int size, int row, int col)
{
    bool check = true; 
    for(int i =0; i < size; i++)
    {
        if(board[row][i] == true){check = false; break;}
    }
    return check; 
}

bool condition2(bool** board, int size, int row, int col)
{
    bool check = true;

    for(int i = 0; i < size; i++)
    {
        if(board[i][col] == true) {check = false;  break;}
    }
    return check; 
}

bool condition3(bool** board, int size, int row, int col)
{
    bool check = true; 
    int crow = row -1; 
    int ccol = col +1; 

    while(crow >= 0 && ccol < size)
    {
        if(board[crow][ccol] == true){check = false; break;}
        crow -= 1; 
        ccol += 1; 
    }
    
    return check; 
}

bool condition4(bool** board, int size, int row, int col)
{
    bool check = true; 
    int crow = row -1; 
    int ccol = col -1; 
    
    while(crow >= 0 && ccol >= 0)
    {
        if(board[crow][ccol] == true){check = false; break;}
        crow -= 1; 
        ccol -= 1; 
    }
    
    return check; 
}


int queen_insert(bool** board, int size, int row)
{
    int index = 0; 
   

    for(int i = 0; i < size; i++)
    {
        bool con1 = condition1(board, size, row, i);
        bool con2 = condition2(board, size, row, i); 
        bool con3 = condition3(board, size, row, i);
        bool con4 = condition4(board, size, row, i);

        if(con1 && con2 && con3 && con4){index = i; break;}
    }

    return index; 
}


int main()
{

    srand((unsigned int)time(NULL)); 
    int size; 
    queue<int> queen_index; 
     
    cin >> size; 
    
    bool col_check[size] = {false, };
    bool board[size][size] = {false, }; 
    bool* boardptr[size]; 
    for(int i = 0; i < size; i++){boardptr[i] = board[i];}

    int first_colum_index = rand() % size; 
    queen_index.push(first_colum_index); 
    
    board[0][first_colum_index] = true; 
    for(int i = 1; i < size; i++)
    {
        int col = queen_insert(boardptr, size, i); 
        board[i][col] = true;  
        col_check[col] = true; 
        queen_index.push(col + 1);
       
    }

    while(queen_index.size() > 0)
    {
        cout << queen_index.front() <<endl; 
        queen_index.pop(); 
    }

    return 0; 
}