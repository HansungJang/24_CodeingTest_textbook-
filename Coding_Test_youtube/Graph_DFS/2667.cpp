/*
1. 아이디어 
- 2중 For Loop => value: 1 && 방문 X => DFS(recursion)
- DFS recursion 돌면서 해당 좌표값 추가, 저장된 vector의 value갯수 return, 단지의 호수 갱신

2. 시간복잡도 
- DFS : O(V + E)
V: maximum V: 25 * 25 == 625 
E: 4 * V : maximum E : 4 * 625 == 2,500 

최대 연산: V + E << 1억 
따라서, 해당 알고리듬은 사용가능

3. 자료구조 
-  그래프 전체 지도 int[][] 
-  방문 bool[][] 
-  vector / recurrsion 함수 (DFS 구현) //
-  vector, std::count() 함수를 사용하여 단지별로 포함되어있는 방의 갯수 저장  
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count  = 0; // 연결된 village 갯수 count

int dx[] = {0, 1, 0, -1}; // 하,우,상,좌
int dy[] = {1, 0, -1, 0}; 

// idea, DFS는 only 연결된 부분만 marking
void find_room(vector<vector<int>>& housemap, vector<vector<bool>>& check, int y, int x, int size)
{
    // int vilage_count = 1; 
    ::count+=1;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i]; 

        // return을 사용하면 다음방향 고려 X
        // 재귀를 사용한다고 다음 방향 탐색이 불가능하도록 하는게 아님!  
        // 재귀에서 중요한 것은 종료 조건인데 다음 함수는 for-loop가 유한한 범위를 순환. 따라서 Foor-Loop의 갯수를 높여주면 됨.  

        if(nx < 0 || ny < 0 || nx >= size || ny >= size) continue;//return; 
        //else if(housemap[ny][nx] != 1 || check[ny][nx] != false) continue;  

        else
        {
            if(housemap[ny][nx] == 1 && check[ny][nx] == false) // return 0; 
            // else 
            {
                check[ny][nx] = true; 
                // return (vilage_count + find_room(housemap, check, ny, nx, size)); 
                //vilage_count += 
                find_room(housemap, check, ny, nx, size); 
            }
        }

    }

    return; 
    // return vilage_count;
}


int main()
{
    int size; 
    cin >> size; 
    
    // int housemap[size][size] = {0,};
    // bool check[size][size] = {false, };

    vector<vector<int>> housemap(size); 
    vector<vector<bool>> check(size); 
    vector<int> village; 


    // 입력 고려되지 않은 부분 (입력이 붙어서 입력 됨.)
    for(int i= 0; i < size; i++)
    {
        cin.ignore(); 
        string elem; 
        getline(cin, elem); 
        for(int j =0; j < elem.length(); j++)
        {
            if(elem[j] == '1') {housemap[i].push_back(1);}
            else{housemap[i].push_back(0);}
            check[i].push_back(false); 
        }
    }


// ta idea, recurrsion 값 받아오기 보다, 전역변수 사용하는 것이 편리 
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(housemap[i][j] == 1 && check[i][j] == false)
            {
                check[i][j] = true; 
                find_room(housemap, check, i, j, size);
                village.push_back(::count); 
                ::count = 0; 
            }
        }
    }

    sort(village.begin(), village.end()); 
    cout << village.size() << endl; 
    for(int i = 0; i < village.size(); i++)
    {
        cout << village[i] << endl; 
    }


    return 0; 
}
