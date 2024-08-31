/*
Goal, ���� �ѷ��� ���̰� ū �ﰡ���� ����� �� 
1. ���̵��
- �ﰢ���� ���� ����: �ﰢ���� ����亯 < ������ �κ��� ��.
-  Loop�� �̿��Ͽ� ����亯�� ���� �����ϴ��� Ȯ��
>> ���� �����ϸ� stop

#�ʿ��Լ� 
3���� �ִ��� ã�� �Լ� 
�κ��� �� > �亯 ���� Ȯ�� 

2. �ð����⵵
- O(N) // ���� �� ���� ���� ����
// N�� max���� 100 << 1�� 
//��밡��  
3. �ڷᱸ�� 
- vector, Linked List 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define tri 3 

using namespace std; 


int main()
{
    vector<int> sides; 
    int max, others; 

    for(int i =0; i < tri; i++)
    {
        int elem; 
        cin >> elem; 
        sides.push_back(elem); 
    }
    

    do
    {
        sort(sides.begin(), sides.end()); 
        max = sides.back(); 
        others =  sides[0] + sides[1];
        if(max >= others)
        {
            sides[2] = sides.back() - 1; 
        } 
    }while(max >= others); 

    int max_sum = 0; 
    for(int i = 0; i < tri; i++)
    {
        max_sum += sides[i]; 
    }

    cout << max_sum; 
    return 0; 
}