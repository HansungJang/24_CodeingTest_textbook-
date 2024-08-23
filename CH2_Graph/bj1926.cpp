// BFS ����, 
// �׸��� ���� ���� �Ǿ��ִ� ������ ��� �ϴ� ���� 

// s 11 27 e 12 37 (1 - trial )

// idea. 

// 1.  1�� �����, ���� or �Ʒ� ���� 1�� �ִ��� Ȯ��. 
// ���� �� [][+1], �Ʒ� [+1][] (ptr + rowũ�� ��ŭ ������ �ִٴ� ��)


// 2. �̹� Ȯ���� �ڷ�� �ߺ��ؼ� Ȯ���ϸ� �ȵ�. <how>
// �湮�� Ȯ���ϴ� �� ��ü �̹� �湮�� elem�� ���ؼ� 1��� 2�� / �ߺ� ���� 

// 3. 

// 1. 2�� for Loop Ȱ�� (row * col) Ž���ϸ鼭 
// 2. ���� elem == 1�� ��� (count ++; size ++;), �ش� elem = 2; 
// ���� Ž���� BFS: queue�� �̿��Ͽ� Ž�� (value�� 1�� ptr�� ����)
// curr_index + 1 == 1 or curr_index + row == 1  Ȯ�� 
// �´ٸ�  size++; �ش� *index_elem = 2�� ����; 
// 3. ��ǰ�� ��, size�� ����ū �� : algorithm sort�Լ� �̿��Ͽ� ���� ������ ��, ũ�� ����

// TC. O(N^2) 



// Data_strcture. queue, BFS 

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std; 

int main()
{
    int row, col; 
    int** canvas; 
    vector<int> art; 


    cin >> row >> col; 
    canvas = new int*[row];
    for(int i = 0; i < row; i++) canvas[i] = new int[col];  

// �Է� 
    for(int i =0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            int elem; 
            cin >> elem; 
            canvas[i][j] = elem; 
        }
    }

// �׸�ã�� 
// queue front�� ��ġ���� (right, down Ȯ��) �߰� 
// �������� row > , col > 


    for(int i = 0; i < row; i++)
    {
 
        for(int j =0; j < col; j++)
        {       
            queue<pair<int, int>> posit; 
            int size = 0; 
            if(canvas[i][j] == 1)
            {
                canvas[i][j] = 2; // �湮 check 
                size++; 
                posit.push(make_pair(i, j)); 
            //  Ž��     
                while(posit.size() > 0)
                {
                    // if(*(posit.front() + 1) == 1 && (j+1) < col) {posit.push(&canvas[i][j + 1]); size++; canvas[i][j + 1] = 2;}// �������� Ȯ�� 
                    // if(*(posit.front() + col) == 1 && (i+1) < row) {posit.push(&canvas[i + 1][j]); size++; canvas[i + 1][j] = 2;}// �Ʒ� Ȯ�� 
                    int x = posit.front().second; 
                    int y = posit.front().first;
                    // if((x+1) < col && (y+1) < row)
                    // {
                    // ���ǹ� ���� Ž������ �޶���
                        if((x+1) < col && canvas[y][x + 1] == 1 ) {posit.push(make_pair(y, x + 1)); size++; canvas[y][x + 1] = 2;}// �������� Ȯ�� 
                        if((y+1) < row && canvas[y + 1][x] == 1 ) {posit.push(make_pair(y + 1, x)); size++; canvas[y + 1][x] = 2;}// �Ʒ� Ȯ�� 
                        if((x-1) < col && (x-1) > 0  &&  canvas[y][x - 1] == 1 ) {posit.push(make_pair(y, x - 1)); size++; canvas[y][x - 1] = 2;}// ���� Ȯ�� 
                        if((y-1) < row && (y-1) > 0  && canvas[y - 1][x] == 1 ) {posit.push(make_pair(y - 1, x)); size++; canvas[y - 1][x] = 2;}// �� Ȯ�� 

                    // } 
                    posit.pop(); 
                }

            } 
            if(size > 0) art.push_back(size); 
        }

    }


    sort(art.begin(), art.end());
    cout << art.size() << endl << art.back(); 


    for(int i = 0; i < row; i++) {delete canvas[i];}  
    delete[] canvas; 
    return 0; 
}