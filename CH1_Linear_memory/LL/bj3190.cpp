// // DUMMY ���� ��Ģ 
// // intial: start: [0][0] index, ����: 1 
// // size : N * N 
// // �ʿ� ���, ���� +1 
// // ó�� �̵��� ������ 
// // ���� ��ų� �ڱ��ڽſ��� ������ over 


// #include <iostream>
// #include <queue>
// #include <algorithm>
// //#include <utility>

// using namespace std; 

// typedef struct 
// {
//     int y; 
//     int x;
// } snake_elem; 

// // ���� �̵�
// // [][+1] : r,  [+1][]: down , [][-1] : l, [-1][]: up : �ð����  
// // D: �ð���� L: �ݽð���� 


// typedef struct 
// {
//     int time; 
//     char rotate;
// } move_rotate; 


// class snake
// {
//     private: 
//         queue<snake_elem> body; 
//         int size;
//         char move; 

//     public: 
//     snake()
//     {
//         snake_elem intial; 
//         intial.x = intial.y = 0; 
//         body.push(intial);

//         size = 1; 
//         move = 'r'; 
//     }
//     void movesnake(int **gamefield) // [y][x] ���� ��ĭ �̵��ϴ� �Լ� 
//     {
//         snake_elem move_elem; 

//         if(move == 'r')
//         {
//             move_elem.x = body.back().x + 1;
//             move_elem.y = body.back().y; 
//         }
//         else if(move == 'u')
//         {
//             move_elem.x = body.back().x;
//             move_elem.y = body.back().y -1; 
//         } 
//         else if(move == 'l')
//         {
//             move_elem.x = body.back().x -1;
//             move_elem.y = body.back().y; 
//         }
//         else 
//         {
//             move_elem.x = body.back().x;
//             move_elem.y = body.back().y +1; 
//         }

//         body.push(move_elem);
//         if(gamefield[move_elem.y][move_elem.x] != 1) body.pop(); 
//     }; 

//     bool gameover()
//     {
//         bool result = false; 
//         // head: back()�� ������ ���ؼ� �� �� ����
//         // #1. head�� tail ��ġ�� ���� 
//         // #2. ���� ����� ���� 

//         snake_elem head = body.back();  
//         snake_elem tail = body.front(); 

//         result = find(body.front(), body.back(), head); 



//         // if(head.x)



//     }; 

//     void insertBody(){}; 
//     void setmove(){}; 
 
// }; 


// int main()
// { 
//     queue<snake_elem> snake;
//     // snake_elem* apple_position; 
//     queue<move_rotate> move_point; 

//     char snake_move = 'r'; // ���� �̵� ���� 
//     int size = 1; 
//     int apples; 
//     int rotate_num; 
//     int count = 0 ; // ���� ���� �ð� Ȯ��

//     int** gamefield; 

// // #1. ���� field ũ�� ���� �Է¹ޱ� 
//     cin >> size; 
//     gamefield = new int*[size];
//     for(int i = 0; i < size; i++){gamefield[i] = new int[size];}
//     for(int i = 0; i < size; i++) // �ʱ�ȭ 
//     {
//         for(int j =0; j < size; j++)
//         {
//             gamefield[i][j] = 0; 
//         }
//     }

//     cin >> apples; 
//    // apple_position = new snake_elem[apples]; 
//     for(int i =0; i < apples; i++)
//     {
//         int x, y; 
//         cin >> x >> y; 
//         x -=1; y-=1;
//         gamefield[x][y] = 1; // 1: apple �ǹ� 
//     }

//     cin >> rotate_num; 

//     for(int i =0; i < rotate_num; i++)
//     {
//         move_rotate minfo; 
//         int move_time; 
//         char movepoint; 

//         cin >> move_time >> movepoint; 
//         minfo.time = move_time; 
//         minfo.rotate = movepoint;

//         move_point.push(minfo);  
//     }


// // #2. ���� 




//     for(int i = 0; i < size; i++){delete[] gamefield[i];}
//     delete gamefield; 
//     return 0; 
// }

// [����] https://hagisilecoding.tistory.com/82
#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n, t1, t2 , k;
    int map[102][102] = {0};
    bool visit[102][102] = {false};
    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> t1 >> t2;
        map[t1 - 1][t2 - 1] = 1;
    } // �������� ������ 1,1�� �������� �ϰ� �ְ� ���� 0,0�� �������� �ϱ����ؼ� -1����.
 
    int cnt = 0;
    char t3;
 
    int dx[4] = {1, 0, -1, 0}; // ��, ��, ��, ��
    int dy[4] = {0, 1, 0, -1};
    int dir = 0;
    int x = 0;
    int y = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    int bt1 = 0;
    int l;
    cin >> l;
    for (int i = 0; i < l;i++){
        cin >> t1 >> t3;
        
        while(cnt < t1 || i == l-1){ 
            // ������ �Է±��� ������ ������ ���� ��� ���� ���������� ���������.
            cnt++;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
 
            if(nx >=0 && ny >=0 && nx<n && ny<n && !visit[ny][nx]){
                // ������ ������ ���� ����
                if(map[ny][nx] == 1){ // ����� �Ծ��� ��
                    map[ny][nx] = 0; // ��� �����ְ�
                    q.push(make_pair(nx, ny)); // �� ��ǥ�� �߰�
                    visit[ny][nx] = true; // �� �ִٴ°� ��ǥ ǥ��
                }else{// ��� ���� ��
                    q.push(make_pair(nx, ny)); 
                    visit[ny][nx] = true; 
                    visit[q.front().second][q.front().first] = false;
                    // ���� �κо����ֱ�
                    q.pop();
                }
            }else{
                cout << cnt;
                return 0;
            }        
            x = nx;
            y = ny;
            if(cnt == t1){
                if(t3 == 'D'){ // ���� ȸ��
                    dir = (dir + 1) % 4; 
                }else{ // ���� ȸ��
                    dir = (dir + 3) % 4;
                }
            }
        }
    }
    return 0;
} // 1h