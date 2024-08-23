/*
1. ���̵�� 
- 2�� For Loop => ��: 1, �湮 X  => BFS 
- BFS ���鼭 �׸� ���� +1, �ִ��� ���� 

2. �ð����⵵ 
[���� �����ڷ�] https://velog.io/@jiyaho/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EC%8B%9C%EA%B0%84-%EC%A0%9C%ED%95%9C%EA%B3%BC-%EC%8B%9C%EA%B0%84-%EB%B3%B5%EC%9E%A1%EB%8F%84

- BFS : O(V + E) 
// queue�� �ְ� ���� ����: O(2V) ~= O(V), Queue�� ���� ���� elemet�� Ȯ���ϴ� �۾� edge: O(E)
- V: row * col; 
- E: 4 * V (������ 4����(up, down, left, right))
- V + E: maximum value,  500(row) * 500(col) * 5 = 1,250,000 < 1�� (1�� CPU �ִ� ���� ����)
// ����, TC O(V + E) �˰��� ��밡�� 
// Data���� 500 ����, O(N ^ 3) ������ TC ��밡��

3. �ڷᱸ�� 
- �׷��� ��ü ���� : int [][]
- �湮 bool [][] 
- Queue(BFS) // �׸� Ž�� 

*/


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
    while(art.size() > 0)
    {
        int x = art.front().second; 
        int y = art.front().first; 

        for(int dir = 0; dir < 4; dir++)
        {
            // if(x + dx[dir] < col && y + dy[dir] < row && x + dx[dir] >= 0 && y + dy[dir] >= 0)
            // {
                if(x + dx[dir] < col && y + dy[dir] < row && x + dx[dir] >= 0 && y + dy[dir] >= 0 && map[y + dy[dir]][x + dx[dir]] == 1 && map_visit[y + dy[dir]][x + dx[dir]] == true)
                {
                    art.push(make_pair(y + dy[dir], x + dx[dir]));
                    map_visit[y + dy[dir]][x + dx[dir]] = false; 
                    count++; 
                }
            // }
        }

        art.pop(); 
    }

    return count; 
} 



int main()
{
    int row, col; 

    cin >> row >> col; 

    vector<vector<int>> map; 
    vector<vector<bool>> map_visit; 
    vector<int> art_size; 
    for(int i = 0; i < row; i++)
    {
        vector<int> elem_map; 
        vector<bool> elem_m_visit; 
        for(int j = 0; j < col; j++)
        {
            int elem; 
            cin >> elem; 
            elem_map.push_back(elem); 
            if(elem_map[j] == 1 ) elem_m_visit.push_back(true);
            else{elem_m_visit.push_back(false);}  
        }

        map.push_back(elem_map); 
        map_visit.push_back(elem_m_visit); 
    }


    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(map[i][j] == 1 && map_visit[i][j] == true)
            {
                int size = art_BFS(map, map_visit, i, j, row, col);
                art_size.push_back(size);  
            }
        }
    }

    sort(art_size.begin(), art_size.end()); 
    cout << art_size.size() << endl << art_size.back(); 
        
    return 0; 
}