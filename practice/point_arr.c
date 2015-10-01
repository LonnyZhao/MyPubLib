/*************************************************************************
	> File Name: point_arr.c
	> Author: 
	> Mail: 
	> Created Time: 2015年09月20日 星期日 16时08分16秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct channel_info_s
{
    unsigned int id;
    unsigned int type;
}channel_info_t;

channel_info_t * g_unit_channel_map[4] = {NULL};


void init()
{
    g_unit_channel_map[0] = (channel_info_t *)malloc(sizeof(channel_info_t)*128);
}

int main()
{
    init();
    g_unit_channel_map[0][10].id = 10;
    g_unit_channel_map[0][10].type = 12;

    printf("channel_id=%d, channel_type=%d\n", g_unit_channel_map[0][10].id,g_unit_channel_map[0][10].type);

    free(g_unit_channel_map[0]);
}

