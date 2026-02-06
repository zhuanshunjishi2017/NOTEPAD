#include "allfunc.h"
#include "gui.h"

//函数层级 draw,show

BUTTON confirm[2] = {{"确定",BUTTON_W,BUTTON_H,NULL},
                    {"取消",BUTTON_W,BUTTON_H,NULL}};

BUTTON inputs[3] = {{"<",SMALL_BU_SIZE,SMALL_BU_SIZE,NULL},
                    {">",SMALL_BU_SIZE,SMALL_BU_SIZE,NULL},
                    {"拼音",57,SMALL_BU_SIZE,NULL}};

BUTTON scrolls[3] = {{" ",SCROLL_W,12,NULL},
                    {" ",SCROLL_W,SCROLL_H,NULL},
                    {" ",SCROLL_W,12,NULL}};

ENTRY entries[2] = {{ENTRY_W,ENTRY_H},{ENTRY_W,ENTRY_H}};

POSITION dialog_pos = {0};

int dialog_state  = 0;//用于标定有无对话框打开

int is_edit_open = 0;

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
        show_text_16(xstart,ystart,bu->text,DARKGRAY,"HZK\\HZK16");
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
        show_text_16(xstart+2,ystart+2,bu->text,DARKGRAY,"HZK\\HZK16");
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
        show_text_16(xstart,ystart,bu->text,BLUE,"HZK\\HZK16");
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
    //小窗口
    if (state == 0)
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
    if (state == 1)//大窗口
    {
        x = 0;
        y = MENU_H+2;
        xend = SCREEN_W;
        yend = SCREEN_H - BOTTOM_H -2;
        
        
        if (dialog_state) setcolor(LIGHTGRAY);
        else if (!dialog_state) setcolor(BLUE);
        //边框
        rectangle(x,y,xend,yend);
        rectangle(x+2,y+2,xend-2,yend-2);
        rectangle(x+1,y+1,xend-1,yend-1);

        //标题栏
        if (dialog_state) setfillstyle(SOLID_FILL,LIGHTGRAY);
        else if (!dialog_state) setfillstyle(SOLID_FILL,BLUE);

        bar(x,y,xend,y+SUBMENU_H);


        //绘制汉字
        show_text_16(xstart,y+6,win->title,WHITE,"HZK\\HZK16");

        setfillstyle(SOLID_FILL,WHITE);
        bar(x+3,y+SUBMENU_H+1,xend-3-SCROLL_W-2,yend-3);

        if (!dialog_state)
        {
            setcolor(LIGHTGRAY);
            line(x+3,y+SUBMENU_H+1,xend-3,y+SUBMENU_H+1);
            line(x+4,y+SUBMENU_H+2,xend-4,y+SUBMENU_H+2);

            line(x+3,y+SUBMENU_H+1,x+3,yend-3);
            line(x+4,y+SUBMENU_H+2,x+4,yend-4);
        }
    }
}

//状态0空闲，1活动，2悬停
void draw_entry(ENTRY *en,int x,int y,int state)
{
    int xend = x+en->width;
    int yend = y+en->height;
    int color;
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

    if (state == 1 || state == 2) color = BLUE;
    else if(state == 0 )color =  DARKGRAY;

    //settextstyle(SANS_SERIF_FONT, HORIZ_DIR,2);
    show_text_16(x+6, y+8, en->content,color,"HZK\\HZK16");


}

void show_entry(ENTRY *en,int x,int y)
{
    int press_state = mouse_press(x,y,x+ENTRY_W,y+ENTRY_H);
    char input[2] = {0};
    int twinkle_pos = strlen(en->content)*8;
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
    int press_state = mouse_press(x,y,x+button->width,y+button->height);
    //按钮松开
    if ((!press_state || press_state == 2) && (!MouseS) && button->is_press)
    {
        draw_button(button,x,y,0);
        button->is_press = 0;
        return 1;
    }
    if ((press_state==2) && !button->is_highlight)
    {
        draw_button(button,x,y,2);
        button->is_highlight = 1;
        return 0;
    }
    //鼠标离开
    else if (!press_state && button->is_highlight)
    {
        if(!button->is_press) draw_button(button,x,y,0);
        button->is_highlight = 0;
        return 0;
    }
    //鼠标按下
    else if (press_state==1 && !button->is_press)
    {
        draw_button(button,x,y,1);
        button->is_press = 1;
        return 0;
    }

    return 0;
}


int show_dialog(WINDOW *dialog)
{
    int i;
    int value;
    //初始化首次绘制
    if (!dialog->is_open)
    {
        clrmous(MouseX, MouseY);
        if (!dialog->is_fullscreen)
        {
            for (i = 0;i< MENU_LEN;is_menu_open[i++] = 0);
            update_frame();
        }

        if (!dialog->is_fullscreen) show_menu(LIGHTGRAY);

        dialog->update(dialog,INIT);

        dialog->is_open = 1;
        return 0;
    }
    //处理拖动事件
    if (!dialog->is_fullscreen)
        tackle_drag_window(dialog,&dialog_pos);
    //处理按钮
    if (!dialog->is_title_click)
    {
        if(value = dialog->update(dialog,UPDATE))
        {
            dialog->is_open = 0;

            dialog->x = (SCREEN_W - dialog->width) / 2;
            dialog->y = (SCREEN_H - dialog->height)/ 2;

            MouseForm = 0;
            return value;
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

void show_bottom_bar(BUTTON *bu,int state)
{
    int x = 0, y = SCREEN_H - BOTTOM_H;
    if (state == INIT)
    {
        setcolor(DARKGRAY);
        line(x,y -1 ,x+SCREEN_W,y - 1);

        setfillstyle(SOLID_FILL,LIGHTGRAY);
        bar(x,y,SCREEN_W,SCREEN_H);

        create_bar(x+3,y+3,x+130,SCREEN_H-3);
        show_text_16(x+11,y+10,"第1行，第1列",DARKGRAY,"HZK\\HZK16");

        create_bar(x+134,y+3,x+500,SCREEN_H-3);
        show_text_16(x+142,y+10,"1.你 2.我 3.这 4.在 5.好 6.不 7.是 8.那",BLUE,"HZK\\HZK16");

        draw_button(bu,x+507,y+4,0);
        draw_button(bu+1,x+542,y+4,0);
        draw_button(bu+2,x+577,y+4,0);



    }
    else if (state = UPDATE)
    {
        show_button(bu,x+507,y+4);
        show_button(bu+1,x+542,y+4);
        show_button(bu+2,x+577,y+4);
    }
}

void create_bar(int x,int y,int xend,int yend)
{
    //高光
    setcolor(WHITE);
    line(x+1,yend-1,xend-1,yend-1);
    line(x,yend,xend,yend);

    line(xend-1,y+1,xend-1,yend-1);
    line(xend,y,xend,yend);

    //阴影
    setcolor(DARKGRAY);

    line(x+1,y+1,xend-1,y+1);
    line(x,y,xend,y);

    line(x+1,y+1,x+1,yend-1);
    line(x,y,x,yend);
}

void create_scroll(BUTTON *bu,int x,int y,int state)
{
    int xend = x + SCROLL_W + 2, yend = SCREEN_H - BOTTOM_H - 5;

    if (state == INIT)
    {
        setcolor(DARKGRAY);
        rectangle(x, y, x+1, yend);

        //setcolor(WHITE);
        //rectangle(xend -1,y,xend,yend);

        setfillstyle(SOLID_FILL,LIGHTGRAY);
        bar(x+2,y+2,xend-2,yend-2);


        draw_button(bu,x+1,y+1,0);
        draw_button(bu + 1, x + 1, y + 15,0);
        draw_button(bu + 2, x + 1,yend - 13,0);
    }
}