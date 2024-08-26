/*
9�� �Է� ���� �߿��� �ִ밪, �ش� ���� index ��� 
algorithm, find �� ����Ҽ��� ������ �ش� �κ� ����ð� ����� ��ŭ ���� 

big-o notaion
O(3*n) �ð�, 
�׳� �Է½ÿ� �ش� ���� ���Ѵٸ� O(n) �ð��� ������ �ִ� �۾�; 
�� �ش�񱳸� ���ؼ� ������ ���� : maxnum, max_index �� ���� ������ �߰��� �ʿ��ϴٴ� �κ��� ������ 
TC >> SC���� �ǹ��ִٰ� �Ǵ��Ͽ� 

for-loop�� �̿��� Ǯ�̷� ���� 
 */

#include <iostream>
#define size 9

using namespace std; 
int main()
{
    int number[size] = {0,}; 
    int maxnum = 0, maxindex = 0; 

    for(int i = 0; i < size; i++)
    {
        cin >> number[i]; 
        if(number[i] > maxnum)
        {
            maxnum = number[i];
            maxindex = i; 
        }
    }

    cout << maxnum << endl << (maxindex + 1) << endl; 

    return 0; 
}