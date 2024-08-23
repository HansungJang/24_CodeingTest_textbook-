// ���� �ڷᱸ��; index ���� ������ Ȱ���ϴ� ���� 
// ������ ���� ���ڴ� �� �� �̻� �������� �ʴ´�.
// ��, ������ �ð�������θ� ���ư���. 


// ���� �ؼ�;  "ȭ��ǥ�� ����Ű�� ���ڰ� ���� ����" ���ǿ� ���ؼ� �ؼ��ϴµ� �ð��� �÷��ɸ�. 
// 1 trial ��������. "���� ���ڰ� 2�� �̻� �������� �ʴ´�" ���� ����... (�Է� ���ǿ��� ������ �Ǿ� ���� �����Ƿ� ������ �ʿ�!)

#include <iostream>
#include <algorithm> // find �Լ� ��� (�ߺ� ���� Ȯ��)
#include <queue>

using namespace std; 


int reIndex(int curr_index, int num, int N)
{
    int result = curr_index + num; 
    // if(result > (N -1)) result -= N;
    if(result > (N -1)) result %= N; // 1 trial���� error�� �߻��� ����
    return result;  
}

void printStr(char* result, int N, int curr_index)
{
    for(int i = curr_index; i >= 0; i--) cout << result[i];
    for(int i = N-1; i > curr_index; i--) cout << result[i];
}

 
int main()
{
    int N, K; // N: size, K: rotate number
    // queue<int> chage_num; 
    // queue<char> alpha; 
    int curr_index = 0; 
    char* output; 

    cin >> N >> K; 
// #1. ���ڿ� �ʱ�ȭ 
    output = new char[N]; 
    for(int i = 0; i < N; i++) output[i] = '?'; 

// #2. �Է� ���� 
    for(int i = 0; i < K; i++)
    {
        int num; 
        char alp; 
        cin >> num >> alp; 
        // chage_num.push(num);
        char* dup_check = find(output, output + N, alp); 

        curr_index = reIndex(curr_index, num, N); 
        if(output[curr_index] != '?' && output[curr_index] != alp){curr_index = -1; break;}
        // else if(dup_check != output + N && dup_check != output + curr_index) {curr_index = -1; break;}
        else if(output[curr_index] != alp && dup_check != output + N) {curr_index = -1; break;}

        else
        {
            output[curr_index] = alp; 
        } 
    }

// #3. ��� 
    if(curr_index < 0) cout << "!"; 
    else
    {
        printStr(output, N, curr_index);
    }

    delete output; 
    return 0; 
}

// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;

// int N, K;
// void setpan(vector<char> &pan) {
// 	for (int i = 0; i < N; i++) {
// 		pan[i] = '?';
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false); 
//     //C++ ǥ�� ��Ʈ������ Cǥ�� ��Ʈ����� ������ ����� ���� �Ŀ� ����ȭ ���� ����
//     //c / c++ ����� ������ ȥ���Ͽ� ����ϴ� ���� ����� ������ Ȯ���ϴ� ����
//     //[reference] https://hegosumluxmundij.tistory.com/54  
// 	cin.tie(0); cout.tie(0);
// 	cin >> N >> K;
// 	vector<char> pan(N);
// 	setpan(pan);
// 	int index;
// 	for (int i = 0; i < K; i++) {
// 		int count; char tmpc;
// 		cin >> count >> tmpc;
// 		if (i == 0) { pan[0] = tmpc; index = 0; continue; }
// 		index = (count + index) % N;
// 		//������ �� ��������(���� �ڸ�)�� ���� �� �ִ�. �װ͸��� �ƴϸ� Ʋ�� ����
// 		if (pan[index] != '?'&& pan[index] != tmpc) { cout << "!"; return 0; }
// 		else {
// 			pan[index] = tmpc;
// 		}
// 	}
// 	//�ߺ�üũ
// 	for (int i = 0; i < N; i++) {
// 		for (int j = i + 1; j < N; j++) {
// 			if(pan[i]!='?' &&pan[i]==pan[j]) { cout << "!"; return 0; }
// 		}
// 	}
// 	for (int i = 0; i < N; i++) {
// 		cout << pan[index];
// 		index--;
// 		if (index == -1) index = N - 1;
// 	}
// 	return 0;
// }