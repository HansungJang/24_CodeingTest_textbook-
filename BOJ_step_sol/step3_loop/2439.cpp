// ������ ���� ����  : flag ����ϴ� ���� 
/*
[reference]
- flag / https://cplusplus.com/reference/ios/ios_base/flags/
- setf / https://cplusplus.com/reference/ios/ios_base/setf/

flag ��� ���� 
 #include <iostream>     // std::cout, std::ios

int main () {
  std::cout.setf ( std::ios::right, std::ios::basefield );  // set hex as the basefield
  std::cout.setf ( std::ios::showbase );                  // activate showbase
  std::cout.width(10);
  std::cout << 100 << '\n';
  std::cout.unsetf ( std::ios::showbase );                // deactivate showbase
  std::cout << 100 << '\n';
  return 0;
}

[��� ���] 
- ��ü ũ�� 10 (������ ����) 100
- ��ü ũ�� 10 (���� ���� : default) 100


cout�� flag�� ����� ��, 
cout.setf(��� ����(��/����/internal), ��� ����, �ε��Ҽ��� ǥ��) ������ �Ҽ� ���� 
cout.setf
 */
#include <iostream>
using namespace std; 

int main()
{
    int num; 
    for(int i = 1; i < num; i++)
    {
        for(int num = 0; num < i; num++) printf
    }
    return 0; 
}