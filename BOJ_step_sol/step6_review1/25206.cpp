// ����ü ����ϴ� ���� 
/*

1. ���̵�� 
- ����ü �̿��Ͽ� (string, double)�Է����� �޴� �ڷᱸ�� ���� 
- vector ����Ͽ� �������� ����Ʈ ���� 

2. �ð����⵵ 
- O(V)
V = 20 << 1�� // ��밡�� 

3. �ڷᱸ�� 
- vector 

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std; 

struct subject
{
    string tittle; 
    double score; 
    string grade;  
}; 

double cal_grade(string grade)
{
    double elem = 0.0; 
    if(grade[0] == 'A') elem += 4.0; 
    if(grade[0] == 'B') elem += 3.0; 
    if(grade[0] == 'C') elem += 2.0; 
    if(grade[0] == 'D') elem += 1.0; 
    if(grade[0] == 'F') elem += 0.0;

    if(grade.length() > 1)
    {
        if(grade[1] == '+') elem += 0.5; 
    }

    return elem; 
}


int main()
{
    int size = 20; 
    double score_sum = 0.0;
    double  grade_sum = 0.0; 
    double result; 


    vector<subject> subList(size); 

    for(int i =0; i < size; i++)
    {
        cin >> subList[i].tittle >> subList[i].score >> subList[i].grade; 
    } 

    for(int i = 0; i < size; i++)
    {
        if(subList.back().grade != "P")
        {
            score_sum += subList.back().score; 
            grade_sum += cal_grade(subList.back().grade) * subList.back().score;
        } 
        subList.pop_back(); 
    }

    result = grade_sum / score_sum; 
    cout.precision(6); 
    cout.fixed; 
    cout << result; 


    return 0; 
}
