#include <allfunc.h>
#include <stdlib.h>
#include <time.h>
int rand0_7();

//画出主操作栏矩形按钮
void draw_main_toolbotton(int x,int color,char*s1,char*s2)
{
	bar1(x,590,x+264,750,0xFFFFFF);
	Line_Thick(x,751,x+264,751, 1, 0x000000 );
	Line_Thick(x, 590,x,759, 1, 0xBD32 );
	Line_Thick(x+264,590,x+264,759, 1, 0xBD32 );
	Line_Thick(x+8,755,x+264,755, 2, color );

	puthz(x+21,612,s1, 48,50, 0x000000);
	puthz(x+21,614,s1, 48,50, 0x000000); 
	puthz(x+23,612,s1, 48,50, 0x000000); 
	puthz(x+23,614,s1, 48,50, 0x000000); 
	puthz(x+22,613,s1, 48,50, color); 

	puthz(x+67,678,s2, 48,50, 0x000000);
	puthz(x+67,680,s2, 48,50, 0x000000);
	puthz(x+69,678,s2, 48,50, 0x000000);
	puthz(x+69,680,s2, 48,50, 0x000000);
	puthz(x+68,679,s2, 48,50, color);
}

//画出激活的主操作栏矩形按钮
void draw_main_toolbotton_activate(int x,int color,char*s1,char*s2)
{
	bar1(x+1,0,x+157,93,color);
	Line_Thick(x, 0,x,87, 1, 0x000000 );
	Line_Thick(x+158,0,x+158,87, 1, 0x000000 );
	Line_Thick(x+8,95,x+150,95, 2, color );

	puthz(x+41,7,s1, 32,40, 0xFFFFFF);
	puthz(x+41,9,s1, 32,40, 0xFFFFFF);
	puthz(x+43,7,s1, 32,40, 0xFFFFFF); 
	puthz(x+43,9,s1, 32,40, 0xFFFFFF); 
	puthz(x+42,8,s1, 32,40, 0x000000); 

	puthz(x+41,48,s2, 32,40, 0xFFFFFF);
	puthz(x+41,50,s2, 32,40, 0xFFFFFF);
	puthz(x+43,48,s2, 32,40, 0xFFFFFF);
	puthz(x+43,50,s2, 32,40, 0xFFFFFF);
	puthz(x+42,49,s2, 32,40, 0x000000);
}

//画出左侧操作栏矩形按钮
void draw_left_toolbotton(int y,int length,char*s)
{
	bar1(0,y+1,232,y+length-1,0xFFFFBB);
	Line_Thick(0,y,33,y, 1, 0xBD32 );
	Line_Thick(0,y+length,33,y+length, 1, 0xBD32 );
	Line_Thick(43,y,60,y, 1, 0xBD32 );
	Line_Thick(43,y+length,60,y+length, 1, 0xBD32 );
	Line_Thick(70,y,220,y, 1, 0xBD32 );
	Line_Thick(70,y+length,220,y+length, 1, 0xBD32 );
	puthz(43,y+length/2-15,s, 32,50, 0x000000);

}


//画出激活的左侧操作栏矩形按钮
void draw_left_toolbotton_activate(int y,int length,char*s)
{
	bar1(0,y+1,232,y+length-1,0xBDBD);
	Line_Thick(70,y,103,y, 1, 0xFF00 );
	Line_Thick(70,y+length,103,y+length, 1,0xFF00 );
	Line_Thick(113,y,130,y, 1, 0xFF00 );
	Line_Thick(113,y+length,130,y+length, 1,0xFF00 );
	Line_Thick(140,y,220,y, 1, 0xFF00 );
	Line_Thick(140,y+length,220,y+length, 1,0xFF00 );
	puthz(43,y+length/2-15,s, 32,50, 0x000000);

}

//主操作栏矩形按钮鼠标确认函数
int main_toolbotton_mouse_press(int x)
{
    int start = 233 + (x - 1) * 158;
    return mouse_press(start, 0, start + 158, 90);
}

//左操作栏矩形按钮鼠标确认函数
int left_toolbotton_mouse_press(int x)
{
    int y = 95 + (x - 1)*65;
    return mouse_press(0, y, 234, y + 65);
}

//左操作栏所有内容清除函数
void clear_main_all()
{
    bar1(0,95,232,768,0xFFFFFF);
}

//左操作栏所有内容清除函数2
void clear_main_all2()
{
    bar1(0,95,232,768,0xFFFFBB);
}

int rand0_7()
{
    //srand(time(NULL));
    return rand() % 11; // 生成0到7的随机数
}



void draw_all_left_toolbutton(int n,int l,char *s[])
{
    int i = 0;
    for (; i < n; i++) 
	{
        draw_left_toolbotton(95+ i * l, l, s[i]);
    }
}


//画出工作区分隔栏
void draw_divider(int y)
{

    Line_Thick(239, y, 258, y + 7, 1, 0x00FF00 );
    Line_Thick(258, y + 7, 296, y + 16, 1, 0x00FF00 );
    Line_Thick(296, y + 16, 331, y + 22, 1, 0x00FF00 );
    Line_Thick(331, y + 22, 387, y + 27, 1, 0x00FF00 );
    Line_Thick(387, y + 27, 426, y + 27, 1, 0x00FF00 );
    Line_Thick(426, y + 27, 436, y + 29, 1, 0x00FF00 );
    Line_Thick(436, y + 29, 535, y + 25, 1, 0x00FF00 );
    Line_Thick(535, y + 25, 618, y + 22, 1, 0x00FF00 );
    Line_Thick(618, y + 22, 720, y + 16, 1, 0x00FF00 );
    Line_Thick(720, y + 16, 802, y + 15, 1, 0x00FF00 );
    Line_Thick(802, y + 15, 881, y + 17, 1, 0x00FF00 );
    Line_Thick(881, y + 17, 904, y + 20, 1, 0x00FF00 );
    Line_Thick(904, y + 20, 955, y + 27, 1, 0x00FF00 );
    Line_Thick(955, y + 27, 975, y + 31, 1, 0x00FF00 );
    Line_Thick(975, y + 31, 1003, y + 38, 1, 0x00FF00 );
    Line_Thick(1003, y + 38, 1024, y + 45, 1, 0x00FF00 );

    Line_Thick(239, y + 21, 281, y + 31, 2, 0xffaaaa );
    Line_Thick(281, y + 31, 324, y + 37, 2, 0xffaaaa );
    Line_Thick(324, y + 37, 369, y + 41, 2, 0xffaaaa );
    Line_Thick(369, y + 41, 425, y + 41, 2, 0xffaaaa );
    Line_Thick(425, y + 41, 474, y + 40, 2, 0xffaaaa );
    Line_Thick(474, y + 40, 490, y + 36, 2, 0xffaaaa );
    Line_Thick(490, y + 36, 517, y + 32, 2, 0xffaaaa );
    Line_Thick(517, y + 32, 573, y + 22, 2, 0xffaaaa );
    Line_Thick(573, y + 22, 617, y + 13, 2, 0xffaaaa );
    Line_Thick(617, y + 13, 662, y + 5, 2, 0xffaaaa );
    Line_Thick(662, y + 5, 705, y - 2, 2, 0xffaaaa );
    Line_Thick(705, y - 2, 745, y - 9, 2, 0xffaaaa );
    Line_Thick(745, y - 9, 783, y - 11, 2, 0xffaaaa );
    Line_Thick(783, y - 11, 810, y - 12, 2, 0xffaaaa );
    Line_Thick(810, y - 12, 829, y - 10, 2, 0xffaaaa );
    Line_Thick(829, y - 10, 875, y - 8, 2, 0xffaaaa );
    Line_Thick(875, y - 8, 903, y - 3, 2, 0xffaaaa );
    Line_Thick(903, y - 3, 931, y + 3, 2, 0xffaaaa );
    Line_Thick(931, y + 3, 952, y + 9, 2, 0xffaaaa );
    Line_Thick(952, y + 9, 987, y + 19, 2, 0xffaaaa );
    Line_Thick(987, y + 19, 1024, y + 33, 2, 0xffaaaa );
}



