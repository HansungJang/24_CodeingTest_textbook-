/*
1. ���̵�� 
- 2�� For Loop => value: 1 && �湮 X => DFS(recursion)
- DFS recursion ���鼭 �ش� ��ǥ�� �߰�, ����� vector�� value���� return, ������ ȣ�� ����

2. �ð����⵵ 
- DFS : O(V + E)
V: maximum V: 25 * 25 == 625 
E: 4 * V : maximum E : 4 * 625 == 2,500 

�ִ� ����: V + E << 1�� 
����, �ش� �˰����� ��밡��

3. �ڷᱸ�� 
-  �׷��� ��ü ���� int[][] 
-  �湮 bool[][] 
-  vector / recurrsion �Լ� (DFS ����) //
-  vector, std::count() �Լ��� ����Ͽ� �������� ���ԵǾ��ִ� ���� ���� ����  
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count  = 0; // ����� village ���� count

int dx[] = {0, 1, 0, -1}; // ��,��,��,��
int dy[] = {1, 0, -1, 0}; 

// idea, DFS�� only ����� �κи� marking
void find_room(vector<vector<int>>& housemap, vector<vector<bool>>& check, int y, int x, int size)
{
    // int vilage_count = 1; 
    ::count+=1;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i]; 

        if(nx < 0 || ny < 0 || nx >= size || ny >= size) return; 

        else
        {
            if(housemap[ny][nx] != 1 || check[ny][nx] != false) return; 
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

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            int elem; 
            cin >> elem; 
            housemap[i].push_back(elem); 
            check[i].push_back(false); 

        }
    }

// ta idea, recurrsion �� �޾ƿ��� ����, �������� ����ϴ� ���� �� 
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
