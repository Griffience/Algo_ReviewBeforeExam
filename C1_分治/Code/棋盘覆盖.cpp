//���̸������� 
//���˸о�������ĸ��������˵ҪСһ��(С�ܶ���ʵ) 

#include<iostream>
#include<stdio.h> 
#include<cmath>
using namespace std;
const int maxn = 128;  //�����������ߴ�  2^k, k<=7ʱMAXN=128����(���и�����Ŀ����,���˱�ֱ���)
int board[maxn][maxn];    //���̣�ÿ��L������һ����ű�ʶ
int tileID = 0;  //���Ʊ�ţ�ÿÿ����һ��L�͹��ƣ��ͱ�ż�1(˵���˾���cnt)

//���̸��ǵݹ麯��
//������tr, tc Ϊ��ǰ���������Ͻ����ꣻsize Ϊ�����̱߳���dr, dc Ϊ�������������ⷽ���λ������
void coverChessboard(int tr, int tc, int size, int dr, int dc) {
    if(size == 1) {
        return; //�����̽�1�����踲��
    }
    tileID++;
    int t = tileID;  //��ǰʹ�õ�L���Ʊ��
    int half = size / 2;
    //�ĸ������̵����ⷽ���ʼ����
    int special[4][2] = {
        {tr + half - 1, tc + half - 1},   //���������̵������Ĭ�������½�
        {tr + half - 1, tc + half},  //���������������Ĭ�������½�
        {tr + half, tc + half - 1},  //���������������Ĭ�������Ͻ�
        {tr + half, tc + half}   //���������������Ĭ�������Ͻ�
    };

    //�����ⷽ�����ڵ������̶�Ӧ��Ĭ������λ�ø�Ϊ�������ⷽ��λ��
    //����������������ʹ�����Ĺ��Ƹ���Ĭ�������
    if(dr < tr + half && dc < tc + half) {
        //���ⷽ��������������
        special[0][0] = dr;
        special[0][1] = dc;
    } else {
        //�����������������ĸ�
        board[tr + half - 1][tc + half - 1] = t;
    }
    if(dr < tr + half && dc >= tc + half) {
        //���ⷽ��������������
        special[1][0] = dr;
        special[1][1] = dc;
    } else {
        //�����������������ĸ�
        board[tr + half - 1][tc + half] = t;
    }
    if(dr >= tr + half && dc < tc + half) {
        //���ⷽ��������������
        special[2][0] = dr;
        special[2][1] = dc;
    } else {
        //�����������������ĸ�
        board[tr + half][tc + half - 1] = t;
    }
    if(dr >= tr + half && dc >= tc + half) {
        //���ⷽ��������������
        special[3][0] = dr;
        special[3][1] = dc;
    } else {
        //�����������������ĸ�
        board[tr + half][tc + half] = t;
    }

    // �ݹ鸲���ĸ�������
    coverChessboard(tr,         tc,         half, special[0][0], special[0][1]); // ����
    coverChessboard(tr,         tc + half,  half, special[1][0], special[1][1]); // ����
    coverChessboard(tr + half,  tc,         half, special[2][0], special[2][1]); // ����
    coverChessboard(tr + half,  tc + half,  half, special[3][0], special[3][1]); // ����
}

int main() {
    int k;  
	cin>>k; 
	
    int boardSize = pow(2,k);  // 2^k
    //��ʼ�����̣�-1��ʾ���ⷽ��
    for(int i=0; i<boardSize; ++i)
        for(int j=0; j<boardSize; ++j)
            board[i][j] = 0;
    //ʾ����������Ŀ˵���ⷽ��������λ��(1, 2),��ʵ��Ӧ���д�λ��������ָ��
    int special_r = 1, special_c = 2;
    board[special_r][special_c] = -1;
    coverChessboard(0, 0, boardSize, special_r, special_c);
    cout << "L�͹��Ƹ��ǽ����������Ʊ�ţ�:" << endl;
    
    //���ӻ�һ�� 
    for(int i=0; i<boardSize; ++i) {
        for(int j=0; j<boardSize; ++j) {
            if(board[i][j] == -1)
                cout << " * ";  //���ⷽ��
            else
                printf("%2d ",board[i][j]);
        }
        cout << endl;
    }
    //output result
    cout << "�ܹ�����: " << tileID << endl;
    return 0;
}

