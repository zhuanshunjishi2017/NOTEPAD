#include <allfunc.h>


void main(void)
{      
    // 初始化图形模式
    int gd = VGA, gm = VGAHI;   // gd:图形驱动 gm:图形模式
    int i,j;

    int run_state = 1;//标定运行状态
    int flag[MENU_LEN] = {0};//刷新标志位（状态锁）
    int subflag[MENU_LEN] = {0};
    int submenuflag[SUBMENU_LEN] = {0};
    
    int exit_dialog_flag[5] = {0};
    //按钮1状态 按钮2状态 窗口是否打开 是否在标题栏按下鼠标 是否拖动
    int count_esc = 0;
    int exit_state = 0;  
    
    int open_dialog_flag[11] = {0};
    char filedir[2][32] = {0};
    int open_state = 0;
    ////第一次出现 第一次按下 第一次悬停 闪烁计数 
    
    extern ENTRY example;

    initgraph(&gd, &gm, "BGI"); // 初始化图形模式

    cleardevice();

    update_frame();
    show_menu(BLUE);

    clearEvents();
    mouseinit();

	while (run_state)
	{
        newmouse(&MouseX, &MouseY, &MouseS); //更新鼠标

        switch (dialog_state)//处理对话框事件
        {
            case DIALOG_EMPTY://没有对话框才更新菜单
                if (kbhit() && getch() == 27) dialog_state = count_esc = 1;//检测按下第一次esc
                //kbhit()是检测有无按键按下，不然会一直等待输入
                update_menu(menulist,submenu,flag,subflag,submenuflag);//更新菜单
                break;
            case DIALOG_EXIT://退出对话框
                exit_state = update_exit_dialog(&exit_dialog,confirm,
                                        subflag,exit_dialog_flag,&count_esc);
                if (exit_state == 2) run_state = 0;
                if (exit_state == 1)
                {
                    dialog_state = DIALOG_EMPTY;//设为无对话框状态
                    show_menu(BLUE);
                    update_frame();//更新框架
                } 
                break;
            case DIALOG_OPEN:
                if (kbhit() && getch() == 27)
                {
                    for (i = 0;i < 11;i++) open_dialog_flag[i] = 0;
                    dialog_state = DIALOG_EMPTY;//设为无对话框状态
                    MouseForm = 0;
                    show_menu(BLUE);
                    update_frame();//更新框架
                    break;
                };
                open_state = update_open_dialog(&open_dialog,confirm,
                                entries,subflag,open_dialog_flag,filedir);
                if (open_state)
                {
                    dialog_state = DIALOG_EMPTY;//设为无对话框状态
                    show_menu(BLUE);
                    update_frame();//更新框架
                }
                break;
        }
        
	}
    closegraph();//关闭图形界面 
}


//刷新除去菜单栏以外的整个框架
void update_frame(void)
{
    setbkcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(0,MENU_H+2,640,480);
}

//更新菜单的主函数
void update_menu(MENU *menulist,MENU (*submenu)[SUBMENU_LEN],
                    int *flag,int* subflag,int *submenuflag)
{
    //检测打开的菜单是否有鼠标扫过和点击
    int i,j;
    for (i = 0; i<MENU_LEN;i++)
        if(subflag[i]) submenu_mouse(submenu[i],i,submenuflag);
    
    //检测主菜单是否有鼠标扫过
    for (i = 0;i <MENU_LEN;i++)
        if (refresh_menu(menulist+i,i,flag+i)) break;

    //检测主菜单是否被鼠标单击
    for (i =0;i < MENU_LEN;i++)
    {
        if(refresh_submenu(submenu[i],i,subflag+i))
        {
            for (j = 0; j < MENU_LEN;j++)
                if (subflag[j] && (j != i))
                    subflag[j] = 0;
            break;
        }
    }
}

//更新退出提醒窗口
int update_exit_dialog(WINDOW *dialog,BUTTON *button,int *menu,int *flag,int *count)
{

    int i,state;
    //预处理，强制关闭菜单
    if (!*(flag+2)) for (i = 0;i< MENU_LEN;i++) if (menu[i]) menu[i] = 0,update_frame();
    //渲染窗口
    state = show_exit_dialog(dialog,button,flag);
    
    tackle_drag_window(dialog,&dialog_pos,flag+2);//前两个标志位用于标注按钮状态，故从第三个开始传入
    
    if (!kbhit()) *count = 2;
    //处理返回值
    if (state == 1) return 1;
    if (state == 2 || ((kbhit() && getch() == 27) && *count == 2)) return 2;
    return 0;
}


int update_open_dialog(WINDOW *dialog,BUTTON *button,ENTRY *entry,
                                int *menu,int *flag,char (*dir)[32])
{
    int i,state;
    //预处理，强制关闭菜单
    if (!*(flag+2)) for (i = 0;i< MENU_LEN;i++) if (menu[i]) menu[i] = 0,update_frame();
    //渲染窗口
    state = show_open_dialog(dialog,entries,button,flag);
    
    tackle_drag_window(dialog,&dialog_pos,flag+2);//前两个标志位用于标注按钮状态，故从第三个开始传入

    if (state == 2) 
    {
        strcpy(dir[0],entry->content);
        strcpy(dir[1],(entry+1)->content);
    }
    return state;
}



//处理窗口拖动函数
//标志位分别是第一次打开窗口，第一次标题栏按下鼠标，第一次拖动
void tackle_drag_window(WINDOW *win,DRAGPOS *pos,int *flag)
{
    DRAGPOS temp;
    //处理鼠标拖动
    if ((MouseS == 1 && *(flag+1)== 1))
    {
        clrmous(MouseX, MouseY);
        //画边框
        temp = draw_win_frame(win,pos,MouseX,MouseY,
                    pos->target_x,pos->target_y,flag+2);
        pos->target_x = temp.target_x;//pos里存储的始终比鼠标慢一帧
        pos->target_y = temp.target_y;

    }
    //拖动完释放鼠标
    if (!MouseS && *(flag+1)== 1)
    {
        //更新窗口的位置
        win->x = MouseX + pos->relative_x;
        win->y = MouseY + pos->relative_y;//这里只用更新位置不用渲染
        pos->target_x = MouseX;
        pos->target_y = MouseY;
        update_frame();
        *(flag) = *(flag+1)= *(flag+2) = 0;
        //第一个：迫使窗口重新渲染
    }
}