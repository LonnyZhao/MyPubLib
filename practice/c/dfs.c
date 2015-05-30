/*************************************************************************
	> File Name: dfs.c
	> Author: 
	> Mail: 
	> Created Time: 2015年05月30日 星期六 21时33分08秒
 ************************************************************************/

#include<stdio.h>

#define ROW 5
#define COL 4

int map[ROW][COL]=
{
    0, 0, 1, 0,
    0, 0, 0, 0,
    0, 0, 1, 0,
    0, 1, 2, 0,
    0, 0, 0, 1,

};
int bookMap[ROW][COL]={0};

int miniStep = 99999;
void dfs(int x, int y, int expect_x,int expect_y,int step)
{
    int direction[4][2] =
    {
        {0,1},//向右移动一个位置
        {1,0},//向下移动一个位置'
        {0,-1},//向左移动一个位置，
        {-1,0}//向上移动一个位置
    };


    for(int k = 0; k <= 3; ++k)
    {
        int next_x = x + direction[k][0];
        int next_y = y + direction[k][1];
        if(next_x < 0 || next_x >= ROW || next_y < 0 || next_y >= COL)
            continue;
        
        if(next_x == expect_x && next_y == expect_y)
        {
            if((step+1) < miniStep)
            {
                miniStep = step+1;
                return;
            }
        }

        if(0 == map[next_x][next_y] && 0 ==  bookMap[next_x][next_y])
        {
            bookMap[next_x][next_y] = 1;
            dfs(next_x,next_y,expect_x,expect_y,step+1);
            bookMap[next_x][next_y] = 0;
        }
    }
}

int main(void)
{
    dfs(0,0,3,2,0);
    printf("need %d step at least\n",miniStep);
}
