/*
���� : https://st-lab.tistory.com/212
[reference] https://cplusplus.com/reference/ios/fixed/
*/


#include <iostream>

using namespace std; 

int main()
{
    long double a, b; 
    cin >> a >> b; 
    cout.precision(12); // ����� �ڸ��� ���� 
    cout << fixed; // �Ή��Ҽ����� �ڸ����� precision���� ������ ũ�⸸ŭ ����ϰڴٴ� �ǹ� 
    cout << (a / b) << endl; 
    return 0; 
}  