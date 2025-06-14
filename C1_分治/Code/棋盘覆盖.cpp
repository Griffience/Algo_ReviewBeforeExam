//棋盘覆盖问题 
//个人感觉考这个的概率相对来说要小一点(小很多其实) 

#include<iostream>
#include<stdio.h> 
#include<cmath>
using namespace std;
const int maxn = 128;  //假设棋盘最大尺寸  2^k, k<=7时MAXN=128够用(自行根据题目来看,错了别怪鄙人)
int board[maxn][maxn];    //棋盘，每个L骨牌用一个编号标识
int tileID = 0;  //骨牌编号，每每放下一个L型骨牌，就编号加1(说白了就是cnt)

//棋盘覆盖递归函数
//参数：tr, tc 为当前子棋盘左上角坐标；size 为子棋盘边长；dr, dc 为该子棋盘中特殊方格的位置坐标
void coverChessboard(int tr, int tc, int size, int dr, int dc) {
    if(size == 1) {
        return; //子棋盘仅1格，无需覆盖
    }
    tileID++;
    int t = tileID;  //当前使用的L骨牌编号
    int half = size / 2;
    //四个子棋盘的特殊方格初始坐标
    int special[4][2] = {
        {tr + half - 1, tc + half - 1},   //左上子棋盘的特殊格默认在右下角
        {tr + half - 1, tc + half},  //右上子棋盘特殊格默认在左下角
        {tr + half, tc + half - 1},  //左下子棋盘特殊格默认在右上角
        {tr + half, tc + half}   //右下子棋盘特殊格默认在左上角
    };

    //将特殊方格所在的子棋盘对应的默认特殊位置改为真正特殊方格位置
    //其他三个子棋盘则使用中心骨牌覆盖默认特殊格
    if(dr < tr + half && dc < tc + half) {
        //特殊方格在左上子棋盘
        special[0][0] = dr;
        special[0][1] = dc;
    } else {
        //覆盖左上子棋盘中心格
        board[tr + half - 1][tc + half - 1] = t;
    }
    if(dr < tr + half && dc >= tc + half) {
        //特殊方格在右上子棋盘
        special[1][0] = dr;
        special[1][1] = dc;
    } else {
        //覆盖右上子棋盘中心格
        board[tr + half - 1][tc + half] = t;
    }
    if(dr >= tr + half && dc < tc + half) {
        //特殊方格在左下子棋盘
        special[2][0] = dr;
        special[2][1] = dc;
    } else {
        //覆盖左下子棋盘中心格
        board[tr + half][tc + half - 1] = t;
    }
    if(dr >= tr + half && dc >= tc + half) {
        //特殊方格在右下子棋盘
        special[3][0] = dr;
        special[3][1] = dc;
    } else {
        //覆盖右下子棋盘中心格
        board[tr + half][tc + half] = t;
    }

    // 递归覆盖四个子棋盘
    coverChessboard(tr,         tc,         half, special[0][0], special[0][1]); // 左上
    coverChessboard(tr,         tc + half,  half, special[1][0], special[1][1]); // 右上
    coverChessboard(tr + half,  tc,         half, special[2][0], special[2][1]); // 左下
    coverChessboard(tr + half,  tc + half,  half, special[3][0], special[3][1]); // 右下
}

int main() {
    int k;  
	cin>>k; 
	
    int boardSize = pow(2,k);  // 2^k
    //初始化棋盘，-1表示特殊方格
    for(int i=0; i<boardSize; ++i)
        for(int j=0; j<boardSize; ++j)
            board[i][j] = 0;
    //示例：假设题目说特殊方格在棋盘位置(1, 2),在实际应用中此位置由输入指定
    int special_r = 1, special_c = 2;
    board[special_r][special_c] = -1;
    coverChessboard(0, 0, boardSize, special_r, special_c);
    cout << "L型骨牌覆盖结果（输出骨牌编号）:" << endl;
    
    //可视化一下 
    for(int i=0; i<boardSize; ++i) {
        for(int j=0; j<boardSize; ++j) {
            if(board[i][j] == -1)
                cout << " * ";  //特殊方格
            else
                printf("%2d ",board[i][j]);
        }
        cout << endl;
    }
    //output result
    cout << "总骨牌数: " << tileID << endl;
    return 0;
}

