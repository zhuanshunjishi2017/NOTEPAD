#include <allfunc.h>


void main(void)
{      
    // 初始化图形模式
    int gd = VGA, gm = VGAHI;   // gd:图形驱动 gm:图形模式
    int i,j;
    int run_state = 1;//标定运行状态

    int dialog_return = 0;  
    char filedir[2][32] = {0};
    ////第一次出现 第一次按下 第一次悬停 闪烁计数 
    

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
                if (kbhit() && getch() == 27)
                    dialog_state = DIALOG_EXIT;//按下第一次esc
                update_menu(main_menu,sub_menu,is_menu_open);//更新菜单
                break;
            case DIALOG_EXIT://退出对话框
                dialog_return = show_exit_dialog(&exit_dialog,confirm);
                if (dialog_return == 2) run_state = 0;
                if (dialog_return == 1)
                {
                    dialog_state = DIALOG_EMPTY;//设为无对话框状态
                    show_menu(BLUE);
                    update_frame();//更新框架
                } 
                break;
            case DIALOG_OPEN:
                dialog_return = show_open_dialog(&open_dialog,entries,confirm);
                if (dialog_return)
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
void update_menu(MENU *mainmenu,MENU (*submenu)[SUBMENU_LEN],int* subflag)
{
    //检测打开的菜单是否有鼠标扫过和点击
    int i,j;
    for (i = 0; i<MENU_LEN;i++)
        if(subflag[i]) refresh_submenu(submenu[i],i);
    
    //检测主菜单是否有鼠标扫过
    for (i = 0;i <MENU_LEN;i++)
        if (refresh_menu(mainmenu+i,i)) break;

    //检测主菜单是否被鼠标单击
    for (i =0;i < MENU_LEN;i++)
    {
        if(show_submenu(submenu[i],i,subflag+i))
        {
            for (j = 0; j < MENU_LEN;j++)//关闭别的菜单
                if (subflag[j] && (j != i))
                    subflag[j] = 0;
            break;
        }
    }
}
