#include <iostream>
#include <forward_list>
#include <vector>

using namespace std; 

int main()
{
    // #1. vector�� ����Ͽ� ����� ����, ���ٽð� ���! 
    vector<string> winner = {
        "Max Verstappen",   // 2023
        "Max Verstappen",   // 2022
        "Esteban Ocon",     // 2021
        "Lewis Hamilton",   // 2020
        "Lewis Hamilton",   // 2019
        "Lewis Hamilton",   // 2018
        "Sebastian Vettel", // 2017
        "Lewis Hamilton",   // 2016
        "Sebastian Vettel", // 2015
        "Daniel Ricciardo"  // 2014
    };

    auto it = winner.begin(); // ����ð� | �����Ϳ� �����ϴµ� �ɸ��� �ð�
    cout << "Current winner : " << *it << endl; 
    it += 8; // constant time, random access iterator 
    cout << "Last 8 years ago, winner : " <<  *it << endl; 
    advance(it, -3); 
    cout << "After 3 years later winner : " << *it <<endl;


    // #2. forward_list�� �̿��Ͽ� ����� ����, ���� �ð� ����� ������ ����! 
    forward_list<string> fwd(winner.begin(), winner.end()); 
    
    auto it1 = fwd.begin(); 
    cout << "Current winner : " << *it1 << endl;

    advance(it1, 5); // linear time, forward iterator 
    cout << "Last 5 years ago, winner : " <<  *it1 << endl;
 
    advance(it1, -3); // cannot access, forward iterator�� �������� �ۿ� �ȵ�.  // with error! segementaiton error occur!  
    cout << "Last 3 years ago, winner : " <<  *it1 << endl;
    


    return 0; 
}