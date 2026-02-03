#include "allfunc.h"
#include "gui.h"

//函数层级 draw,show,update

WINDOW exit_dialog = {"提示",SMALL_DIALOG_W,SMALL_DIALOG_H,
                    SMALL_DIALOG_X,SMALL_DIALOG_Y};

WINDOW open_dialog = {"打开文件",MID_DIALOG_W,MID_DIALOG_H,
                    MID_DIALOG_X,MID_DIALOG_Y};

BUTTON confirm[2] = {{"确定",BUTTON_W,BUTTON_H,NULL},
                    {"取消",BUTTON_W,BUTTON_H,NULL}};

ENTRY entries[2] = {{ENTRY_W,ENTRY_H},{ENTRY_W,ENTRY_H}};

POSITION dialog_pos = {0};

int dialog_state  = 0;//用于标定有无对话框打开
void *winbuffer = NULL;//窗口移动时储存图像



void draw_button(BUTTON *bu,int x,int y,int state)
{
    int xend = x+bu->width;
    int yend = y+bu->height;
    int len = strlen(bu->text);
    int xstart = (x + xend)/2 - len*4;
    int ystart = (y + yend)/2 - 8;
    clrmous(MouseX, MouseY);
    //闲置状态
    if (state == 0)
    {
        setcolor(DARKGRAY);
        
        //边框
        rectangle(x,y,xend,yend);

        //边框加粗
        line(x-1,y,x-1,yend);
        line(xend+1,y,xend+1,yend);
        line(x,y-1,xend,y-1);
        line(x,yend+1,xend,yend+1);

        //阴影
        line(x+1,yend-1,xend-1,yend-1);
        line(x+2,yend-2,xend-2,yend-2);

        line(xend-1,y+1,xend-1,yend-1);
        line(xend-2,y+2,xend-2,yend-2);

        //高光
        setcolor(WHITE);

        line(x+1,y+1,xend-1,y+1);
        line(x+2,y+2,xend-2,y+2);

        line(x+1,y+1,x+1,yend-1);
        line(x+2,y+2,x+2,yend-2);

        setfillstyle(SOLID_FILL,LIGHTGRAY);
        bar(x+3,y+3,xend-3,yend-3);

        //绘制汉字
        prt_hz16(xstart,ystart,bu->text,DARKGRAY,"HZK\\HZK16");
    }
    //按下状态
    if (state == 1)
    {
        setcolor(DARKGRAY);
        
        //边框
        rectangle(x,y,xend,yend);

        //边框加粗
        //setcolor(BLUE);
        line(x-1,y,x-1,yend);
        line(xend+1,y,xend+1,yend);
        line(x,y-1,xend,y-1);
        line(x,yend+1,xend,yend+1);

        //阴影
        setcolor(WHITE);
        line(x+1,yend-1,xend-1,yend-1);
        line(x+2,yend-2,xend-2,yend-2);

        line(xend-1,y+1,xend-1,yend-1);
        line(xend-2,y+2,xend-2,yend-2);

        //高光
        setcolor(LIGHTGRAY);

        line(x+1,y+1,xend-1,y+1);
        line(x+2,y+2,xend-2,y+2);

        line(x+1,y+1,x+1,yend-1);
        line(x+2,y+2,x+2,yend-2);

        setfillstyle(SOLID_FILL,WHITE);
        bar(x+3,y+3,xend-3,yend-3);

        //绘制汉字
        prt_hz16(xstart,ystart,bu->text,DARKGRAY,"HZK\\HZK16");
    }
    //悬停状态
    if (state == 2)
    {
        setcolor(BLUE);
        
        //边框
        rectangle(x,y,xend,yend);

        //边框加粗
        line(x-1,y,x-1,yend);
        line(xend+1,y,xend+1,yend);
        line(x,y-1,xend,y-1);
        line(x,yend+1,xend,yend+1);

        //阴影
        setcolor(DARKGRAY);
        line(x+1,yend-1,xend-1,yend-1);
        line(x+2,yend-2,xend-2,yend-2);

        line(xend-1,y+1,xend-1,yend-1);
        line(xend-2,y+2,xend-2,yend-2);

        //高光
        setcolor(WHITE);

        line(x+1,y+1,xend-1,y+1);
        line(x+2,y+2,xend-2,y+2);

        line(x+1,y+1,x+1,yend-1);
        line(x+2,y+2,x+2,yend-2);

        setfillstyle(SOLID_FILL,LIGHTGRAY);
        bar(x+3,y+3,xend-3,yend-3);

        //绘制汉字
        prt_hz16(xstart,ystart,bu->text,BLUE,"HZK\\HZK16");
    }

}

void draw_window(WINDOW *win,int state)
{
    int x = win->x, y = win->y;
    int xend = x+win->width;
    int yend = y+win->height;
    int len = strlen(win->title);
    int xstart = (x + xend)/2 - len*4;
    clrmous(MouseX, MouseY);
    //活动状态
    if (state == 1)
    {     
        setcolor(BLUE);
        
        //边框
        rectangle(x,y,xend,yend);
        rectangle(x-2,y-2,xend+2,yend+2);
        rectangle(x-3,y-3,xend+3,yend+3);
        rectangle(x-4,y-4,xend+4,yend+4);

        setcolor(WHITE);
        rectangle(x-1,y-1,xend+1,yend+1);
        
        //阴影
        setfillstyle(SOLID_FILL,DARKGRAY);
        bar(xend+5,y,xend+8,yend+8);
        bar(x,yend+5,xend+8,yend+8);

        //标题栏
        setfillstyle(SOLID_FILL,BLUE);
        bar(x,y,xend,y+SUBMENU_H);

        //绘制汉字
        prt_hz16(xstart,y+6,win->title,WHITE,"HZK\\HZK16");

        setfillstyle(SOLID_FILL,WHITE);
        bar(x+1,y+SUBMENU_H+1,xend-1,yend-1);
    }
}

//状态0空闲，1活动，2悬停
void draw_entry(ENTRY *en,int x,int y,int state)
{
    int xend = x+en->width;
    int yend = y+en->height;
    clrmous(MouseX, MouseY);
    //闲置状态
    if (state == 0) setcolor(DARKGRAY);

    //活动状态
    if (state == 1) setcolor(LIGHTBLUE);

    //悬停状态
    if (state == 2) setcolor(BLUE);

    //边框
    rectangle(x,y,xend,yend);

    //边框加粗
    line(x-1,y,x-1,yend);
    line(xend+1,y,xend+1,yend);
    line(x,y-1,xend,y-1);
    line(x,yend+1,xend,yend+1);

    setcolor(WHITE);
    line(x+1,yend-1,xend-1,yend-1);
    line(x+2,yend-2,xend-2,yend-2);

    line(xend-1,y+1,xend-1,yend-1);
    line(xend-2,y+2,xend-2,yend-2);

    //高光
    setcolor(LIGHTGRAY);

    line(x+1,y+1,xend-1,y+1);
    line(x+2,y+2,xend-2,y+2);

    line(x+1,y+1,x+1,yend-1);
    line(x+2,y+2,x+2,yend-2);

    setfillstyle(SOLID_FILL,WHITE);
    bar(x+3,y+3,xend-3,yend-3);

    if (state == 1 || state == 2) setcolor(BLUE);
    else if(state == 0 )setcolor(DARKGRAY);

    //settextstyle(SANS_SERIF_FONT, HORIZ_DIR,2);
    outtextxy(x+6, y+5, en->content);


}
//第一次出现 第一次按下 第一次悬停 闪烁计数
void show_entry(ENTRY *en,int x,int y)
{
    int press_state = mouse_press(x,y,x+ENTRY_W,y+ENTRY_H);
    char input[2] = {0};
    int twinkle_pos = strlen(en->content)*10;
    int content_len;
        
    if (en->is_focus)//如果处于焦点状态
    {
        //处理光标闪烁
        en->count_twinkle++;
        if (en->count_twinkle == 50)
        {
            setfillstyle(SOLID_FILL,BLUE);
            bar(x+6+twinkle_pos,y+8,x+6+twinkle_pos+1,y+25);
        }

        if (en->count_twinkle == 100)
        {
            en->count_twinkle = 0;
            setfillstyle(SOLID_FILL,WHITE);
            bar(x+6+twinkle_pos,y+8,x+6+twinkle_pos+1,y+25);
        } 
        delay(10);
        //处理输入
        if (kbhit())
        {
            *input = getch();
            if (*input == 13 || *input == 27)//回车或esc
            {
                draw_entry(en,x,y,0);

                en->is_focus = 0;
                en->is_highlight = 0;
                en->count_twinkle = 0;

                MouseForm = 0;
                return;
            }
            content_len = strlen(en->content);
            if (*input == 8 && content_len)//输入回格
            {
                en->content[--content_len] = 0;
                draw_entry(en,x,y,1);
                return;
            }
            //如果输入的是可显示字符
            else if (*input >= 32 && *input <= 126)
            {
                strcat(en->content,input);
                draw_entry(en,x,y,1);
                return;
            }
        }

    }
    //首次出现
    if (!en->is_show)
    {
        draw_entry(en,x,y,0);
        en->is_show = 1;
        return;
    }

    //按下与释放
    if (press_state == 1 && !en->is_focus)
    {
        draw_entry(en,x,y,1);
        en->is_focus = 1;
        return;
    }
    else if (press_state == 0 && en->is_focus && MouseS)
    {
        draw_entry(en,x,y,0);
        en->is_focus = 0;
        return;
    }//在别处点击
    
    if (press_state == 2 && !en->is_highlight)//悬停
    {
        if(!en->is_focus) draw_entry(en,x,y,2);//非焦点
        en->is_highlight = 1;
        MouseForm = 2;
        return;
    }
    if (press_state == 0 && en->is_highlight)
    {
        if(!en->is_focus) draw_entry(en,x,y,0);//只有处于非输入状态才变灰
        en->is_highlight = 0;

        MouseForm = 0;
        return;
    }

}

//处理按钮状态
int show_button(BUTTON *button,int x,int y)
{
    int press_state = mouse_press(x,y,x+BUTTON_W,y+BUTTON_H);
    //鼠标悬停
    if ((press_state==2) && !button->is_highlight)
    {
        draw_button(button,x,y,2);
        button->is_highlight = 1;
        return 0;
    }
    //鼠标离开
    else if (!press_state && button->is_highlight)
    {
        draw_button(button,x,y,0);
        button->is_highlight = 0;
        return 0;
    }
    //鼠标按下
    else if (press_state==1)
    {
        draw_button(button,x,y,1);
        button->is_highlight = 0;
        delay(100);
        return 1;
    }
    return 0;
}

//这个函数需要3个flag
int show_exit_dialog(WINDOW *dialog,BUTTON *button)
{
    int x = dialog->x, y = dialog->y;
    int i;

    //初始化首次绘制
    if (!dialog->is_open)
    {
        for (i = 0;i< MENU_LEN;is_menu_open[i++] = 0);
        update_frame();
        show_menu(LIGHTGRAY);

        draw_window(dialog,1);
        prt_hz16(x+55,y+60,"确实要退出“记事本”吗？",BLUE,"HZK\\HZK16");
        draw_button(button,x+70,y+100,0);
        draw_button(button+1,x+160,y+100,0);


        dialog->is_open = 1;
        return 0;
    }
    //处理拖动事件
    tackle_drag_window(dialog,&dialog_pos);

    //处理按钮
    if (!dialog->is_title_click)
    {
        if(show_button(button,x+70,y+100)) return 2;//确定要退出程序，直接返回

        if(show_button(button+1,x+160,y+100) || (kbhit() && getch() == 27))
        {
            dialog->is_open = 0;

            dialog->x = SMALL_DIALOG_X;
            dialog->y = SMALL_DIALOG_Y;
            return 1;
        }
    }
    return 0;
}

void init_entry(ENTRY *en)
{
    en->is_show = 0;
    en->is_focus = 0;
    en->is_highlight = 0;
    en->count_twinkle = 0;
}

//显示打开文件的窗口
int show_open_dialog(WINDOW *dialog,ENTRY *entry,BUTTON *button)
{
    int x = dialog->x, y = dialog->y;
    int i;
    char dir[64];

    //初始化
    if (!dialog->is_open)
    {
        for (i = 0;i< MENU_LEN;is_menu_open[i++] = 0);
        update_frame();
        show_menu(LIGHTGRAY);

        draw_window(dialog,1);

        prt_hz16(x+15,y+40,"当前路径：",BLUE,"HZK\\HZK16");
        setcolor(BLUE);
        getdir(dir);
        outtextxy(x+15, y+65, dir);
        prt_hz16(x+15,y+98,"在此处键入文件名称以打开",BLUE,"HZK\\HZK16");

        init_entry(entry);
        draw_entry(entry,x+12,y+130,0);

        
        draw_button(button,x+243,y+40,0);
        draw_button(button+1,x+243,y+85,0);

        dialog->is_open = 1;
        return 0;
    }

    //处理拖动事件
    tackle_drag_window(dialog,&dialog_pos);

    //处理按钮
    if (!dialog->is_title_click)
    {
        show_entry(entry,x+12,y+130);//前五个已被占用,一个输入框需要五个
        
        if(show_button(button,x+243,y+40)) 
        {   
            dialog->x = MID_DIALOG_X;
            dialog->y = MID_DIALOG_Y;
            dialog->is_open = 0;
            MouseForm = 0;

            return 2;//确定要退出程序，直接返回
        }
        if(show_button(button+1,x+243,y+85) || (kbhit() && getch() == 27))
        {
            
            dialog->x = MID_DIALOG_X;
            dialog->y = MID_DIALOG_Y;
            dialog->is_open = 0;
            MouseForm = 0;

            return 1;
        }

    }
    return 0; 
}

void getdir(char *str)
{
    int current_drive;
            
    current_drive = getdisk();  // 返回：0=A, 1=B, 2=C, ...
    str[0] = 'A' + current_drive;
    strcat(str,":\\");
    getcurdir(current_drive + 1, str+3);
}

//处理窗口拖动
void tackle_drag_window(WINDOW *win,POSITION *pos)
{
    POSITION temp;
    int title_state = mouse_press(win->x, win->y,
                        win->x + win->width, win->y+SUBMENU_H);
    //拖动初始化
    if (title_state == 1 && !win->is_title_click)
    {
        win->is_title_click = 1;//拖动标志位

        win->relative_x = win->x - MouseX;
        win->relative_y = win->y - MouseY;

        pos->target_x = MouseX;
        pos->target_y = MouseY;
    }
    //拖动中
    if ((MouseS == 1 && win->is_title_click == 1))
    {
        clrmous(MouseX, MouseY);
        //画边框
        temp = draw_win_frame(win,pos);
        pos->target_x = temp.target_x;//pos里存储的始终比鼠标慢一帧
        pos->target_y = temp.target_y;

    }
    //拖动完释放鼠标
    if (!MouseS && win->is_title_click)
    {
        //更新窗口的位置
        win->x = MouseX + win->relative_x;
        win->y = MouseY + win->relative_y;//这里只用更新位置不用渲染

        pos->target_x = MouseX;
        pos->target_y = MouseY;
        update_frame();
        
        win->is_open = 0;
        win->is_title_click = 0;
        win->is_drag = 0;
        //第一个：迫使窗口重新渲染
    }
}

//绘制拖动窗口的框架
POSITION draw_win_frame(WINDOW *win,POSITION *former)
{
    
    int w = win->width,h = win->height;
    int xend ,yend;
    int i,j;
    int x = MouseX, y = MouseY;
    int xf = former->target_x, yf = former->target_y;
    POSITION result;
    
    x  += win->relative_x;
    y  += win->relative_y;//从鼠标到窗口边缘

    xf += win->relative_x;
    yf += win->relative_y;//旧的坐标鼠标到窗口边缘

    xend = (x+w+4<640-1)?x+w:640-4-1;
    yend = (y+h+4<480-1)?y+h:480-4-1;//超过这个范围好像会溢出？

    if (x<4) x = 4;
    if (y<4) y = 4;

    if (!win->is_drag) 
    {
        free(winbuffer);
        //clrmous(MouseX, MouseY);
        save_bk_win(win,x,y);
        win->is_drag = 1;//第一次先储存
        putimage(xf-4, yf-4, winbuffer, COPY_PUT);
        line(640,0,640,480);
    }

    if (!(y == yf && x == xf))//出现移动
    {
        
        if (winbuffer)
        {
            //将上次储存的照片放回原位
            putimage(xf-4, yf-4, winbuffer, COPY_PUT); 
            //释放内存
            free(winbuffer);
        }
        
        //在绘制边框前先储存会被边框遮住的照片
        save_bk_win(win,x,y);
        
        //绘制矩形
        rectangle(x-4,y-4,xend+4,yend+4);
        rectangle(x-3,y-3,xend+3,yend+3);
    }
    result.target_x = x -win->relative_x;
    result.target_y = y -win->relative_y;
    return result;
}

void save_bk_win(WINDOW *win,int x, int y)
{
    int size; // 背景图像大小
    int w = win->width,h = win->height;
    int xend = (x+w+4<640-1)?x+w:640-4-1;
    int yend = (y+h+4<480-1)?y+h:480-4-1;
    // 计算鼠标光标区域的大小
    size = imagesize(x-4,y-4,xend+4,yend+4);
    // 分配内存用于保存背景
    if (winbuffer = malloc(size))
    {
        getimage(x-4,y-4,xend+4,yend+4,winbuffer); // 保存背景
    }
}
