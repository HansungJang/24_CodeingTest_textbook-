/*
- ��� ����� �� Ȯ�� 
- ���̰� �޶��� ��, for-loop ���δ� ���� �Ұ���

[Youtube - ���̵��]

1. ���̵�� 
- ��Ʈ��ŷ ����Լ� �ȿ���, fot ���鼭 ���� ����(�̶� �湮���� Ȯ��)
- ����Լ� M���� ���ð������Ʈ ��

- 1���� N�߿� �ϳ��� ������ ��
- ���� 1���� N���� ������ �� �̹� ������ ���� �ƴ� ��� ���� 
- M���� ������ ��� ����Ʈ 

2. �ð����⵵
- �ߺ��� ���� case, O(N^N) << 1�� (N < 8)
- �ߺ��� �Ұ��� case, O(N!) << 1�� ( N < 10)

�� ����; �ߺ� �Ұ� Max: 8 
-> O(N!) ��밡�� 

3. �ڷᱸ�� 
- bool [] �ߺ� üũ 
- int [] ������ �� ���� 


issue Note 
- 1 trial, �ð��ʰ�
>> sol ��Ʈ����ŷ, ��� ���� ���(I/O ����ȭ), reference operator���, .... 
-> ��Ʈ����ŷ, (30 ~ 31 ����� ��) ���� ũ�� �ش��ϴ� sol, �츮������ ��� �������� ����.  
-> 

- 2 trial, fixed ��� 
>> ����� ����ȭ�� �������μ� ����ӵ��� ������Ŵ.   
*/

#include <iostream>
#include <vector>

using namespace std; 

vector<int> elem; 

void backtrack(bool check[], int N, int M)
{
    if(elem.size() == M) 
    {
        for(int i : elem) cout << i << " ";
        cout << endl; 
        return;  
    }

    for(int i = 1; i <= N; i++)
    {
        if(check[i] == false)
        {
            check[i] = true; 
            elem.push_back(i); 
            backtrack(check, N, M); 
            check[i] = false; 
            elem.pop_back(); 
        }

    }
}



int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M; 
    cin >> N >> M; 
    
    bool check[N+1] = {false, }; 
    backtrack(check, N, M);


    return 0; 
}