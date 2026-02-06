#include "allfunc.h"
#include "menu.h"
#include "gui.h"


MENU main_menu[MENU_LEN] = {{"文件"},
                    {"编辑"},
                    {"查看"},
                    {"帮助"}};

MENU sub_menu[MENU_LEN][SUBMENU_LEN] = {{{"新建(N)",&start_edit_window},
                    {"打开(O)",&start_open_dialog},
                    {"保存(S)"},
                    {"另存为(A)"},
                    {"<divideline>"},
                    {"关闭文件(C)",&close_edit_window},
                    {"退出程序Esc",&start_exit_dialog},
                    {"<endline>"}},
                {{"全部选择(A)"},
                    {"<divideline>"},
                    {"复制(C)"},
                    {"剪切(T)"},
                    {"粘贴(P)"},
                    {"删除(L)"},
                    {"<endline>"}},
                {{"查找(F)"},
                    {"<divideline>"},
                    {"格式设定(S)"},
                    {"<endline>"}},
                {{"显示帮助(H)"},
                    {"<divideline>"},
                    {"关于记事本(A)",&start_about_dialog},
                    {"<endline>"}}};

int is_menu_open[MENU_LEN] = {0};


void start_exit_dialog(void)
{
    extern int dialog_state;
    dialog_state = DIALOG_EXIT;
}

void start_open_dialog(void)
{
    extern int dialog_state;
    dialog_state = DIALOG_OPEN;
}

void start_about_dialog(void)
{
    extern int dialog_state;
    dialog_state = DIALOG_ABOUT;
}

void start_edit_window(void)
{
    extern int is_edit_open;
    is_edit_open = 1;
}

void close_edit_window(void)
{
    extern int is_edit_open;
    is_edit_open = 0;
    update_frame();
}

void create_menu_item(MENU *m,int x,int fg,int bg)
{
    setfillstyle(SOLID_FILL,bg);
    bar(x,0,x+MENU_W,MENU_H);
    show_text_16(x+10,7,m->text,fg,"HZK\\HZK16");
}

void create_submenu_item(MENU *sub,int x,int y,int fg,int bg)
{
    //填充背景
    setfillstyle(SOLID_FILL,bg);
    bar(x,y,x+SUBMENU_W,y+SUBMENU_H);

    //绘制文字
    setcolor(fg);
    show_text_16(x+9,y+6,sub->text,fg,"HZK\\HZK16");

    //两侧边框
    setcolor(DARKGRAY);
    line(x-1,y,x-1,y+SUBMENU_H);
    line(x+SUBMENU_W+1,y,x+SUBMENU_W+1,y+SUBMENU_H);

    //右侧阴影
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(x+SUBMENU_W+1,y,x+SUBMENU_W+3,y+SUBMENU_H+1);

}

void create_submenu(MENU *subm,int x)//x为绝对横坐标
{
    int y = MENU_H+1;
    while (1)
    {
        y++;
        if (!strcmp(subm->text,"<endline>"))
        {
            setcolor(DARKGRAY);
            line(x-1,y,x+SUBMENU_W+1,y);

            //下侧阴影
            setfillstyle(SOLID_FILL,DARKGRAY);
            bar(x+2,y+1,x+SUBMENU_W+3,y+3);

            break;
        }
        else if(!strcmp(subm->text,"<divideline>"))
        {
            setcolor(DARKGRAY);
            line(x-1,y,x+SUBMENU_W+1,y);
        }
        else
        {
            create_submenu_item(subm,x,y,BLUE,WHITE);
            y += SUBMENU_H;
        }
        subm++;
    }
}
//用于根据鼠标状态改变子菜单形态
int refresh_submenu(MENU *subm,int x)//x为第几个菜单
{
    int y = MENU_H+1;
    int state;
    while (strcmp(subm->text,"<endline>"))
    {
        y++;
        if(strcmp(subm->text,"<divideline>"))
        {
            state = mouse_press(8+x*MENU_W,y,8+x*MENU_W+SUBMENU_W,y+SUBMENU_H);
            //若是按下鼠标且菜单有对应的函数
            if (state == 1&&(subm->pf))
            {
                subm->pf();
                return 1;
            }
            //没有按下只是悬停
            else if (state&&!subm->is_highlight)
            {
                clrmous(MouseX, MouseY);
                create_submenu_item(subm,8+x*MENU_W,y,WHITE,BLUE);
                subm->is_highlight = 1;
                return 1;
            }
            //从悬停状态离开
            else if (!state&&subm->is_highlight)
            {
                clrmous(MouseX, MouseY);
                create_submenu_item(subm,8+x*MENU_W,y,BLUE,WHITE);
                subm->is_highlight = 0;
                return 1;
            }
            y += SUBMENU_H;
        }
        subm++;
    }
    return 0;
}

void show_menu(int color)
{
    int i;

    clrmous(MouseX, MouseY);

    settextstyle(TRIPLEX_FONT, HORIZ_DIR,1);

    setfillstyle(SOLID_FILL,WHITE);
    bar(0,0,640,MENU_H);
    
    for (i = 0;i < 4;i++)
        create_menu_item(main_menu+i,8+i*MENU_W,color,WHITE);

    setcolor(DARKGRAY);
    line(0,MENU_H+1,640,MENU_H+1);//画分割线

}

int refresh_menu(MENU *m,MENU *subm,int x,int *flag)
{
    //鼠标按下
    if (mouse_press(8+x*MENU_W,0,8+(x+1)*MENU_W,36)&&!m->is_highlight)
    {
        clrmous(MouseX, MouseY);
        create_menu_item(m,8+x*MENU_W,WHITE,BLUE);
        m->is_highlight = 1;
        return 0;
    }
    else if (!mouse_press(8+x*MENU_W,0,8+(x+1)*MENU_W,36)&&m->is_highlight)
    {
        clrmous(MouseX, MouseY);
        create_menu_item(m,8+x*MENU_W,BLUE,WHITE);
        m->is_highlight = 0;
        return 0;
    }

    if ((mouse_press(8+x*MENU_W,0,8+(x+1)*MENU_W,36)==1)&&!*flag)
    {
        clrmous(MouseX, MouseY);
        update_frame();
        create_submenu(subm,8+x*MENU_W);
        *flag = 1;
        return 1;
    }
    //鼠标在别处按下
    else if (!mouse_press(8+x*MENU_W,0,8+(x+1)*MENU_W,36)&&(MouseS==1)&&*flag)
    {
        clrmous(MouseX, MouseY);
        update_frame();
        *flag = 0;
        return 1;
    }
    return 0;
}

