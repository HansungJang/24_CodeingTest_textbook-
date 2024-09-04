/*

// merge sort�� Ǯ���ϴ� ���� �������� ���� 
�׷��� ���� �������� �ð��� �÷��ɸ�... 
�ٽ� ������ �� �� 

https://namu.wiki/w/%EC%A0%95%EB%A0%AC%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98#s-4.2.3

Sorting ��� 

insertion
merge 
selection 
quick 

- O(n^2)
- O(log n)
Ȥ�� ������ ũ�� / �޸� ũ�Ⱑ ����� ���ٸ� 
���� ���Ĺ���� Ǯ�� ����� �ɼ�����.

data���� MAX, 1,000,000
>> O(N^2) �˰����� ����� ��ƴ�. 

1. ���̵�� 
- merge�� �̿��Ͽ� ���� 
2. �ð����⵵ 
- O(log N)
3. �ڷᱸ�� 
- 
*/


// 1 trial with bug. 
// vector<int> merge_sort(int start, int end, vector<int> elem)
// {
//     int size = (end - start) + 1;
//     int mid = start + size / 2;
 
//     vector<int> left, right, result;
//     vector<int> dummy(0); 

//     if((mid - start) < 1) {return dummy;}

//     for(int i = start; i < mid; i++){left.push_back(elem[i]);}
//     left = merge_sort(start, mid, left); 
    
//     for(int j = mid+1; j < size; j++){right.push_back(elem[j]);}
//     right = merge_sort(mid+1, end, right); 

//     while(left.size() > 0 || right.size() > 0)
//     {
//         if(left.size() > 0 && right.size() > 0)
//         {
//             if(left.front() >= right.front())
//             {
//                 result.push_back(right.front());
//                 right.erase(right.begin()); 
//             } 
//             else
//             {
//                 result.push_back(left.front()); 
//                 left.erase(left.begin()); 
//             }
//         }

//         if(left.size() == 0 && right.size() > 0)
//         {
//             while(right.size() > 0)
//             {
//                 result.push_back(right.front());
//                 right.erase(right.begin()); 
//             }
//         }

//         if(right.size() == 0 && left.size() > 0)
//         {
//             while(left.size() > 0)
//             {
//                 result.push_back(left.front());
//                 left.erase(left.begin()); 
//             }
//         }

//     }

//     return result; 
// }





// reference �����Ͽ� Ǯ�� 
// https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html#google_vignette

#include <iostream>
#include <vector>
using namespace std; 

//merge sort���� ������� ��ġ�⸦ �и��ؾ��� 
// 1�Լ����� 1���� ��ɸ� 
void mergeing(vector<int>& list, int left, int mid, int right)
{
    vector<int> temp; 
    int i = left; 
    int j = mid +1; 

    while(i <= mid && j <= right)
    {
        if(list[i] <= list[j]){temp.push_back(list[i++]);}  
        else{temp.push_back(list[j++]);}
    }

    if(i > mid)
    {
        for(int l = j; l <= right; l++) temp.push_back(list[l]); 
    }
    else
    {
        for(int l = i; l <= mid; l++) temp.push_back(list[l]); 
    }


    for(int l = 0; l <temp.size(); l++)
    {
        int index = l + left; 
        list[index] = temp[l]; 
    }
}


void mergeSort(vector<int>& list, int left, int right)
{
    int mid; 
    
    if(left < right)
    {
        mid = (right + left) / 2; 
        mergeSort(list, left, mid);
        mergeSort(list, mid+1, right); 
        mergeing(list, left, mid, right); 
    }

}


int main()
{
    int N; 
    vector<int> list;

    cin >> N; 
    for(int i = 0; i < N; i++)
    {
        int elem; 
        cin >> elem; 
        list.push_back(elem); 
    } 

    // list = merge_sort(0, list.size(), list); 
    mergeSort(list, 0, N-1); 
    for(int i =0; i < list.size(); i++){ cout << list[i] << endl;}

    return 0; 
}
