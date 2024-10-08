/*
1. 아이디어 
- 2중 For Loop => 값: 1, 방문 X  => BFS 
- BFS 돌면서 그림 갯수 +1, 최댓값을 갱신 

2. 시간복잡도 
[보충 참고자료] https://velog.io/@jiyaho/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EC%8B%9C%EA%B0%84-%EC%A0%9C%ED%95%9C%EA%B3%BC-%EC%8B%9C%EA%B0%84-%EB%B3%B5%EC%9E%A1%EB%8F%84

- BFS : O(V + E) 
// queue에 넣고 빼는 과정: O(2V) ~= O(V), Queue에 집어 넣을 elemet를 확인하는 작업 edge: O(E)
- V: row * col; 
- E: 4 * V (방향이 4방향(up, down, left, right))
- V + E: maximum value,  500(row) * 500(col) * 5 = 1,250,000 < 1억 (1초 CPU 최대 연산 범위)
// 따라서, TC O(V + E) 알고리듬 사용가능 
// Data범위 500 이하, O(N ^ 3) 이하의 TC 사용가능

3. 자료구조 
- 그래프 전체 지도 : int [][]
- 방문 bool [][] 
- Queue(BFS) // 그림 탐색 

*/


// issue note, 
// 1. BFS 탐색 조건 if문 (데이터의 범위, 탐색조건) 2가지를 통합하여 조건을 생성하려고 하니 조건문 길고 해당 과정에서 논리 오류 발생 
// -> sol, 종료 및 탈출 조건으로 역조건을 사용
// 2. element 탐색 조건 4방향 및 visit 배열 (초기화 부분) -> 초기화는 false 통일, 방문시 true로 선언 표기 
// 3. segemntation fault(조건문 && 연산도 순서가 존재) 및 access empty container(queue.empty() 인 상황에서 해당 elemnt 를 접근하려고하는 경우) run-time error가 발생하니 조건문으로 대비할 것.  

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std; 

int art_BFS(vector<vector<int>>& map, vector<vector<bool>>& map_visit, int  i, int j, int row, int col)
{
    int count = 1; 
    queue<pair<int, int>> art; 
    int dx[] = {1 , 0, -1, 0}; 
    int dy[] = {0, 1, 0, -1}; 


    art.push(make_pair(i, j)); 
    map_visit[i][j] = true; 
    while(art.size() > 0)
    {
        int x = art.front().second; 
        int y = art.front().first; 
        art.pop(); 

        for(int dir = 0; dir < 4; dir++)
        {

            int nx = x + dx[dir]; 
            int ny = y + dy[dir]; 

            if(nx < 0 || ny < 0 || nx >= col || ny >= row) continue; 
            
            if(map[ny][nx] == 1 && map_visit[ny][nx] == false)
                {
                    art.push(make_pair(ny, nx));
                    map_visit[ny][nx] = true; 
                    count++; 
                }
        }

    }

    return count; 
} 



int main()
{
    int row, col; 
    vector<vector<int>> map; 
    vector<vector<bool>> map_visit; 
    vector<int> art_size; 

    cin >> row >> col; 

    for(int i = 0; i < row; i++)
    {
        vector<int> elem_map; 
        vector<bool> elem_m_visit; 
        for(int j = 0; j < col; j++)
        {
            int elem; 
            cin >> elem; 
            elem_map.push_back(elem); 
            elem_m_visit.push_back(false);
        }

        map.push_back(elem_map); 
        map_visit.push_back(elem_m_visit); 
    }


    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(map[i][j] == 1 && map_visit[i][j] == false)
            {
                int size = art_BFS(map, map_visit, i, j, row, col);
                art_size.push_back(size);  
            }
        }
    }

    sort(art_size.begin(), art_size.end()); 
    cout << art_size.size() << endl; 
    if(!art_size.empty()) cout << art_size.back(); 
    else{cout << 0 ; }

    return 0; 
}