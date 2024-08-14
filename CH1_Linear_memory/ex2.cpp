// �پ��� Ÿ���� �����ڸ� ����� ������ ������ Ÿ������ �����Ͽ� ���� �� ��� 
// Goal, ��ü ���Ҹ� ������ ��ȸ�ϴ� ��. 

#include <array>
#include <iostream>
#include <type_traits>

using namespace std; 

template<typename ...Args>
//array<?,?> build_array(Args&& ...args); 

auto build_array(Args&&... args) -> array<typename common_type<Args...>::type, sizeof...(args)>
{
    using commonType = typename common_type<Args...>::type; 
    return {forward<commonType>((Args&&)args)...}; 
} 

int main()
{
    auto data = build_array(1, 0u, 'A', 3.2f, true); 

    for(auto i : data)
    {
        cout << i << " "; 
    }
    cout << endl;;     

    return 0; 
}
