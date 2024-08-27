/*
1. idea

[answer - idea]
- Loop�� ����Ͽ� Ȯ���ϴ� ����� ���α׷����� ���õ� �ð� ���⵵ ���� X 
- ����, ������ �ٲپ <(��ǥ �Ÿ� - �̲�����) / (�̵��Ÿ� - �̲�����); �̵��� ��¥>
�̵��� ��¥ * (1�� �̵��Ÿ� | ��ǥ�Ÿ� - �̲�����) + �̲����� / ������ ���� �̲����� �����Ƿ� >= (��ǥ �Ÿ�) 


- �ش� ���� ������ ������ 10���� �ƴ�. 
������ ���� �� ��. 

- for loop ���鼭, �ش� ���� �����ߴ��� Ȯ�� 
- 10�� �̻� �ڷ��� ������ ��, ó���� �����Ѱ�


����ð��� O(n) �̸����� ������ ��. 
O(log N) ? tree�� �̿��ϴ� ����? 

10�� �̻� �ڷḦ �����ϴ� �ڷ��� (long long)



+ - goal 

-  2 1 5 , 4
-  

//���� ������ 
day -> night ������ �ջ��� �̷��������. 
���� �߿� 
2 2 
1 1

2 3 
1 2

2 4 
1 3

2 5

2. �ð� ���⵵ 
>> O(n), n == 10�� >> 1��  ���� 
>>  ���� �ʿ䰡 ����. 

[answer idea] 
>> O(1)

3. �ڷᱸ�� 
- maxheap 
>> 

[answer idea] - none, just variable


*/
#include <iostream>

using namespace std; 

int main()
{
    long long int A, B, V;
    // long long int counter = 0;
    // int result = 0; 

    cin >> A >> B >> V; 


// 1st - trial (wrong answer, timee over)
    // while(counter < V)
    // {
    //     result++; 
    //     counter += A; 
    //     if(counter >= V) break; 
    //     counter -= B; 
    // }

// 2nd trial 
    long long int result; 

    // result = (V - B) / (A - B); 

// 3rd -trial [final answer]
// ���� �ٿ����� �ʴ� ������ ���� ������ ó�� ���� �߰� 

    result = ((V - B) % (A - B) != 0 ) ? ((V - B) / (A - B)) +1 : ((V - B) / (A - B)); 


    cout << result; 



    return 0; 
}
