#include <allfunc.h>


void main(void)
{      
    // 初始化图形模式
    int gd = VGA, gm = VGAHI;   // gd:图形驱动 gm:图形模式
    int i,j;
    int flag[MENU_LEN] = {0};//刷新标志位（状态锁）
    int subflag[MENU_LEN] = {0};
    int submenuflag[SUBMENU_LEN] = {0};

    int dialogflag[5] = {0};//按钮位按钮位窗口位
    int count_esc = 0;
    int exit_state = 0;

    extern MENU menulist[MENU_LEN];
    extern MENU submenu[MENU_LEN][SUBMENU_LEN];
    extern BUTTON confirm[2];
    extern WINDOW exit_dialog;
    
    extern int is_exit_dialog;
    

    initgraph(&gd, &gm, "BGI"); // 初始化图形模式

    cleardevice();

    update_frame();
    show_menu(BLUE);

    clearEvents();
    mouseinit();

	while (1)
	{
        newmouse(&MouseX, &MouseY, &MouseS); //更新鼠标
        if (!is_exit_dialog)//没有对话框才更新菜单
        {
            if (kbhit() && getch() == 27) is_exit_dialog = count_esc = 1;//检测按下第一次exc
            update_menu(menulist,submenu,flag,subflag,submenuflag);//更新菜单
        }//kbhit()是检测有无按键按下，不然会一直等待输入
        else
        {
            exit_state = update_exit_dialog(&exit_dialog,confirm,
                                    subflag,dialogflag,&count_esc);
            if (exit_state == 2) break;
            if (exit_state == 1)
            {
                is_exit_dialog = 0;
                show_menu(BLUE);
                update_frame();
            } 
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
    {
        if(subflag[i])
            submenu_mouse(submenu[i],i,submenuflag);
    }
    //检测主菜单是否有鼠标扫过
    for (i = 0;i <MENU_LEN;i++)
    {
        if (refresh_menu(menulist+i,i,flag+i))
            break;
    }
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
    extern DRAGPOS position;
    DRAGPOS temp;
    int i,state;
    //预处理，强制关闭菜单
    if (!*(flag+2)) for (i = 0;i< MENU_LEN;i++) if (menu[i]) menu[i] = 0,update_frame();
    //渲染窗口
    state = show_exit_dialog(dialog,button,flag);
    //处理鼠标拖动
    if ((MouseS == 1 && *(flag+3)== 1))
    {
        temp = draw_win_frame(dialog,&position,MouseX,MouseY,
                    position.target_x,position.target_y,flag+4);
        position.target_x = temp.target_x;
        position.target_y = temp.target_y;
        delay(10);
    }
    if (!MouseS && *(flag+3)== 1)
    {
        dialog->x = MouseX + position.relative_x;
        dialog->y = MouseY + position.relative_y;
        position.target_x = MouseX;
        position.target_y = MouseY;
        update_frame();
        *(flag+2) = *(flag+3)= *(flag+4) = 0;//第一次打开窗口，第一次标题栏按下鼠标，第一次拖动
    }
    if (!kbhit()) *count = 2;
    //处理返回值
    if (state == 1) return 1;
    if (state == 2 || ((kbhit() && getch() == 27) && *count == 2)) return 2;
    return 0;
}