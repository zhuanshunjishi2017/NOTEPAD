#include "allfunc.h"
#include "dialog.h"

WINDOW exit_dialog = {"提示",SMALL_DIALOG_W,SMALL_DIALOG_H,
                    SMALL_DIALOG_X,SMALL_DIALOG_Y,
                    &update_exit_dialog,confirm};

WINDOW open_dialog = {"打开文件",MID_DIALOG_W,MID_DIALOG_H,
                    MID_DIALOG_X,MID_DIALOG_Y,
                    &update_open_dialog,confirm,entries};

WINDOW about_dialog = {"关于",SMALL_DIALOG_W,MID_DIALOG_H,
                    SMALL_DIALOG_X,MID_DIALOG_Y,
                    &update_about_dialog,confirm};

WINDOW edit_window = {"[未保存] untitled.txt",SCREEN_W,0,
                    0,MENU_H+3,&update_edit_window,0,0,1};


int update_exit_dialog(WINDOW *dialog,int state)
{
    int x = dialog->x, y = dialog->y;
    if (state == INIT)
    {
        draw_window(dialog,dialog->is_fullscreen);
        prt_hz16(x+55,y+60,"确实要退出“记事本”吗？",BLUE,"HZK\\HZK16");
        draw_button(dialog->button,dialog->x+70,dialog->y+100,0);
        draw_button(dialog->button+1,dialog->x+160,dialog->y+100,0);
        return 0;
    }
    if (state == UPDATE)
    {
        if(show_button(dialog->button,x+70,y+100))
            return 2;//确认
        if(show_button(dialog->button+1,x+160,y+100)
         || (kbhit() && getch() == 27))//取消
            return 1;
    }
    return 0;
}

int update_open_dialog(WINDOW *dialog,int state)
{
    char dir[64];
    int x = dialog->x, y = dialog->y;
    if (state == INIT)
    {
        draw_window(dialog,dialog->is_fullscreen);

        prt_hz16(x+15,y+40,"当前路径：",BLUE,"HZK\\HZK16");
        getdir(dir);
        show_text_16(x+15, y+65, dir,BLUE,"HZK\\HZK16");
        prt_hz16(x+15,y+98,"在此处键入文件名称以打开",BLUE,"HZK\\HZK16");

        init_entry(dialog -> entry);
        draw_entry(dialog -> entry,x+12,y+130,0);

        
        draw_button(dialog->button, x+243, y+40, 0);
        draw_button(dialog->button + 1, x+243, y+85, 0);
        return 0;
    }
    if (state == UPDATE)
    {
        show_entry(dialog->entry,x+12,y+130);

        if(show_button(dialog->button,x+243,y+40))
            return 2;
        if(show_button(dialog->button+1,x+243,y+85) 
         || (kbhit() && getch() == 27))
            return 1;
    }
    return 0;
}

void getdir(char *str)
{
    int current_drive;
            
    current_drive = getdisk();  // 返回：0=A, 1=B, 2=C, ...
    str[0] = 'A' + current_drive;
    str[1] = ':',str[2] = '\\';
    getcurdir(current_drive + 1, str+3);
}

int update_about_dialog(WINDOW *dialog,int state)
{
    int x = dialog->x, y = dialog->y;
    if (state == INIT)
    {
        draw_window(dialog,dialog->is_fullscreen);

        prt_hz24(x+15,y+45,"记事本",BLUE,"HZK\\HZK24S");

        show_text_16(x+15,y+80,"版本:Beta0.1",BLUE,"HZK\\HZK16");

        prt_hz16(x+15,y+110,"浮沉子",BLUE,"HZK\\HZK16");

        
        draw_button(dialog->button, x+220, y+130, 0);
        return 0;
    }
    if (state == UPDATE)
    {
        if(show_button(dialog->button,x+220,y+130) 
         || (kbhit() && getch() == 27))
            return 1;
    }
    return 0;
}

int update_edit_window(WINDOW *dialog,int state)
{
    char dir[64];
    int x = dialog->x, y = dialog->y;
    if (state == INIT)
    {
        draw_window(dialog,dialog->is_fullscreen);
        create_scroll(scrolls,x + dialog->width -3-SCROLL_W-2 ,y + SUBMENU_H,INIT);

        show_bottom_bar(inputs,INIT);
        return 0;
    }
    if (state == UPDATE)
    {
        show_bottom_bar(inputs,UPDATE);
    }
    return 0;
}
