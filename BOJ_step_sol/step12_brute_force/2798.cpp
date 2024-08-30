/*

# 1-trial: 
1. idea.

�迭 ����� 
DP ���� 
0-1 knapsack 

row: �ش����� index ���� ī�尡 ���Ե� ����� �� 
col: n-1_C_2 = (n-1) * (n-2) / 2  
������ �������� ǥ���ϴ� boolean table



ī�� �������� ����
�ִ밪 ���� �� ���� 
���� M�ʰ� ���� 

2. �ð����⵵: O(n^3)
>> n max: 100, ���� 10^6 << 1��(10^8) ��밡�� 

3. �ڷᱸ�� 

# 2-trial; 
1. ���̵��: ���ռ� ��ŭ 3�� for-loop 

- n_C_3; ��ü ������ ī���� ���� / Ƚ�� 
- 3�� for-loop���� 1��°(0 ~ n-2), 2��° (i+1 ~ n-1), 3��°(j+1 ~ n)
// �� loop�� ������ ���� �ε����� ������ ���� �ε������� Ŀ����. 
- sort �Լ��� ���ؼ� ã����, ������������ ���� 
- for loop ���鼭 Max�� Ȯ�� 

2. �ð����⵵: 
- TC(N^3)
ī���� ���� ���ؼ� TC ���� (MAX: 100)
100_C_3 = (98 * 99 * 100) / (2 * 3) = 161,700  << 1�� 
>> 3�� Loop ��밡��

3. �ڷᱸ�� 
- vector: 
- 3�� for-loop 
*/

#include <iostream>
#include <vector>
#include <algorithm> // sort 
#define card_fac 6 // card factorial value 


using namespace std; 

int SIZE(int size)
{
    int result = 1;
    for(int i = (size -2); i <= size; i++){result *= i;}
    result /= card_fac;  
    return result; 
}

int main()
{
    int size; 
    vector<int> card; 
    vector<int> sum_list; 
    int max = 0; 
    int N, M; // N: card ����, M: target�� 

    cin >> N >> M; 
    size = SIZE(N); 

    for(int i = 0; i < N; i++)
    {
        int elem; 
        cin >> elem; 
        card.push_back(elem); 
    }

    sort(card.begin(), card.end()); 

    for(int i = 0; i < N -2; i++)
    {
        for(int j = i+1; j < N-1; j++)
        {
            for(int k = j+1; k < N; k++)
            {
                int elem = card[i] + card[j] + card[k]; 
                if(elem > M){break;} 
                sum_list.push_back(elem); 
            }
        }
    }

    sort(sum_list.begin(), sum_list.end()); 

    cout << sum_list.back(); 

    return 0; 
}