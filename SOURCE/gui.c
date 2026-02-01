#include "allfunc.h"
#include "gui.h"


//BUTTON example = {"示例按钮",80,40,NULL};

//WINDOW win = {"示例窗口",360,240};

WINDOW exit_dialog = {"提醒",300,150,DIALOG_X,DIALOG_Y};
BUTTON confirm[2] = {{"确定",BUTTON_W,BUTTON_H,NULL},
                    {"取消",BUTTON_W,BUTTON_H,NULL}};

DRAGPOS position = {0};

int is_exit_dialog  = 0;//用于标定有无对话框打开
void *winbuffer = NULL;




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
        //关闭按钮
        setfillstyle(SOLID_FILL,LIGHTGRAY);
        bar(x+1,y+1,x+SUBMENU_H-1,y+SUBMENU_H-1);
        setcolor(DARKGRAY);
        line(x+1,y+1,x+1,y+SUBMENU_H-1);
        line(x+1,y+1,x+SUBMENU_H-1,y+1);

        setcolor(WHITE);
        line(x+1,y+SUBMENU_H-1,x+SUBMENU_H-1,y+SUBMENU_H-1);
        line(x+SUBMENU_H-1,y+1,x+SUBMENU_H-1,y+SUBMENU_H-1);

        setfillstyle(SOLID_FILL,DARKGRAY);
        bar(x+SUBMENU_H/2-7,y+SUBMENU_H/2-1,x+SUBMENU_H/2+7,y+SUBMENU_H/2+1);

        //绘制汉字
        prt_hz16(xstart,y+6,win->title,WHITE,"HZK\\HZK16");

        setfillstyle(SOLID_FILL,WHITE);
        bar(x+1,y+SUBMENU_H+1,xend-1,yend-1);
    }
}

int show_exit_dialog(WINDOW *dialog,BUTTON *button,int *flag)
{
    int x = dialog->x, y = dialog->y;

    int state1 = mouse_press(x+70,y+100,x+70+BUTTON_W,y+100+BUTTON_H);
    int state2 = mouse_press(x+160,y+100,x+160+BUTTON_W,y+100+BUTTON_H);
    int dragaera = mouse_press(x,y,x+DIALOG_W,y+SUBMENU_H);
    char *text = "这将结束本次“记事本”操作";

    //初始化首次绘制
    if (!*(flag+2))
    {
        show_menu(LIGHTGRAY);

        draw_window(dialog,1);
        prt_hz16(x+40,y+60,text,BLUE,"HZK\\HZK16");
        draw_button(button,x+70,y+100,0);
        draw_button(button+1,x+160,y+100,0);


        *(flag+2) = 1;
        return 0;
    }
    //处理拖动事件
    if (dragaera == 1 && !*(flag+3))
    {
        *(flag+3) = 1;
        position.relative_x = x - MouseX;
        position.relative_y = y - MouseY;
        position.target_x = MouseX;
        position.target_y = MouseY;
    }
    if (!*(flag+3))
    {
        //处理确定按钮状态
        if ((state1==2)&&!*flag)
        {
            draw_button(button,x+70,y+100,2);
            *flag = 1;
            return 0;
        }
        else if (!state1&&*flag)
        {
            draw_button(button,x+70,y+100,0);
            *flag = 0;
            return 0;
        }
        else if (state1==1)
        {
            draw_button(button,x+70,y+100,1);
            delay(100);
            return 2;
        }


        //处理取消按钮状态
        else if ((state2==2)&&!*(flag+1))
        {
            draw_button(button+1,x+160,y+100,2);
            *(flag+1) = 1;
            return 0;
        }
        else if (!state2&&*(flag+1))
        {
            draw_button(button+1,x+160,y+100,0);
            *(flag+1)= 0;
            return 0;
        }
        else if (state2 == 1)
        {
            draw_button(button+1,x+160,y+100,1);
            delay(100);
            *(flag+3) = *(flag+2)= *(flag+1)= *flag = 0;//归位
            dialog->x = DIALOG_X;
            dialog->y = DIALOG_Y;
            return 1;
        }
    }
    return 0;
}

int colorchanger(int color,int state)
{
    switch (state)
    {
        case 0:
            switch (color)
            {
            case BLUE:return LIGHTBLUE;
            case DARKGRAY:return LIGHTGRAY;
            case LIGHTGRAY:return WHITE;
            case WHITE:return DARKGRAY;
            default:return 0;
            }
        case 1://还原
            switch (color)
            {
            case LIGHTBLUE:return BLUE;
            case LIGHTGRAY:return DARKGRAY;
            case WHITE:return LIGHTGRAY;
            case DARKGRAY:return WHITE;
            default:return 0;
            }
    }
    return 0;
}


//绘制拖动窗口的框架
DRAGPOS draw_win_frame(WINDOW *win,DRAGPOS *pos,int x,int y,int xf,int yf,int *flag)
{
    
    int w = win->width,h = win->height;
    int xend ,yend;
    int i,j;
    DRAGPOS result;
    
    x += pos->relative_x;
    y += pos->relative_y;//从鼠标到窗口边缘
    xf += pos->relative_x;
    yf += pos->relative_y;//旧的坐标
    xend = x + w; yend = y + h;

    if (x<4) x = 4;
    if (y<4) y = 4;

    if (!*flag) 
    {
        free(winbuffer);
        clrmous(MouseX, MouseY);
        save_bk_win(win,x,y);
        *flag = 1;//第一次先储存
        putimage(xf-4, yf-4, winbuffer, COPY_PUT);
    }
    if (!(y == yf && x == xf))
    {

        if (winbuffer != NULL)
        {
            //将上次储存的照片放回原位
            putimage(xf-4, yf-4, winbuffer, COPY_PUT); 
            //释放内存
            //putimage(10, 10, winbuffer, COPY_PUT); 
            free(winbuffer);
        }
       
        clrmous(MouseX, MouseY);
        //在绘制边框前先储存会被边框遮住的照片
        save_bk_win(win,x,y);

        rectangle(x-4,y-4,xend+4,yend+4);
        rectangle(x-3,y-3,xend+3,yend+3);
    }
    result.target_x = x -pos->relative_x;
    result.target_y = y -pos->relative_y;
    return result;
}

void save_bk_win(WINDOW *win,int x, int y)
{
    int size; // 背景图像大小
    int w = win->width,h = win->height;
    int xend = (x+w+4<640)?x+w:640-4;
    int yend = (y+h+4<480)?y+h:480-4;
    // 计算鼠标光标区域的大小
    size = imagesize(x-4,y-4,xend+4,yend+4);
    // 分配内存用于保存背景
    if (winbuffer = malloc(size))
    {
        getimage(x-4,y-4,xend+4,yend+4,winbuffer); // 保存背景
    }
}