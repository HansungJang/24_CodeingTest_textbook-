// �� �̵� ���� / ����� �ڷ� �����; DLLȰ�빮�� 
 // dequeue, queue�� Ȱ���� Ǯ�� 
// �ش� ������ ���� �������� Ȯ��; �迭���ؼ� �ش� ���� �ذ� ����
#include <iostream>
#include <queue>  
#include <utility> //pair, make_pair

using namespace std; 

typedef struct 
{
    int x;
    int y; 
} position;


void intialize_board(int **board, int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }
}

void Printall(int **board, int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << board[i][j] << " "; 
        }
        cout << endl; 
    }
}


int main()
{

    int N; // board size (2 <= N <= 100)
    int K; // K apples number (0 <= K <= 100)
    int **board, **snake_body_mark; 
    int count = 0; 
    int snake_size = 1;  
    int L; // change direction number 
    //queue<int> dir; // snake_move direction (0: right, 1: down, 2: left, 3: up)
    int dx[] = {1, 0, -1, 0}; 
    int dy[] = {0, 1, 0, -1}; 
    queue<position> snake_body; 
    position intial = {0, 0}; 
    snake_body.push(intial); 

// #1. Game board ���� 
    cin >> N; 
    board = new int*[N]; 
    snake_body_mark = new int*[N]; 
    for(int i = 0; i < N; i++)
    {
        board[i] = new int[N];
        snake_body_mark[i] = new int[N]; 
    }

    intialize_board(board, N);
    intialize_board(snake_body_mark, N);
    snake_body_mark[0][0] = 1; 


    // ��� ����
    cin >> K; 
    for(int i = 0; i < K; i++)
    {
        int x, y; 
        cin >> x >> y; 
        x -=1; y-=1; 
        board[x][y] = 1;  
    }

    // cout << "Game Board" << endl;
    // Printall(board, N);
    // cout << endl; 

    // cout << "Snake Loactaion" <<endl; 
    // Printall(snake_body_mark, N); 
    // cout << endl;  
    
    // ���� ���� 
    cin >> L; 
    queue<int> dir;
    queue<int> dir_change_time; 
    
    dir.push(0); 

    for(int i = 0; i < L; i++)
    {
        int time; 
        char cdir;

        cin >> time >> cdir; 
        dir_change_time.push(time);
        if(cdir == 'D')
        {
            dir.push((dir.back() + 1) %4);  
        } 
        else { dir.push((dir.back() + 3) %4); }

    }


// #3. ���� ����   


// #2. ���� ���� ���� 
    //#1) ���� �̵� ������ index ��
    //#2) ���� �̵� ������ �ڱ� ���� ����ϴ� ���

    while(true)
    {
        if(count == dir_change_time.front()){dir.pop(); dir_change_time.pop();}
        
        int head_next_x =  snake_body.back().x + dx[dir.front()]; 
        int head_next_y =  snake_body.back().y + dy[dir.front()];

        //���� ���� 
        if(head_next_x >= N || head_next_y >= N || head_next_x < 0 || head_next_y < 0) break;  // ���� �� �̵�  
        if(snake_body_mark[head_next_x][head_next_y] == 1 && head_next_x !=  snake_body.front().x && head_next_y !=  snake_body.front().y ) break; // �ڽ��� ���� ����� ��� 

        //���� �̵� 
        position next_pos = {head_next_x, head_next_y}; 


        if(board[head_next_x][head_next_y] == 1)
        {
            snake_size++; 
            board[head_next_x][head_next_y] = 0; 
        }
        else
        {
            snake_body_mark[snake_body.front().x][snake_body.front().y] = 0;
            snake_body.pop(); 
        }

        snake_body.push(next_pos); 
        snake_body_mark[head_next_x][head_next_y] = 1;

        count ++; 
        
    }
    
    cout << count ;

    
    
    for(int i = 0; i < N; i++) {delete board[i], snake_body_mark[i];} 
    delete[] board, snake_body_mark; 

    return 0; 
}