#ifndef __MENU_H__
#define __MENU_H__

#define MENU_W 75
#define MENU_H 30
#define SUBMENU_W 128
#define SUBMENU_H 28
#define MENU_LEN 4
#define SUBMENU_LEN 8


//主菜单
typedef struct
{
    char *ch;
    char *en;
    void (*pf)();
} MENU;

void dialog_state(void);

void show_menu(int);//显示菜单

void create_menu(MENU *,int,int,int);//生成菜单
void create_submenu(MENU *,int,int,int,int);//绘制子菜单

void show_submenu(MENU *,int);

int submenu_mouse(MENU *,int,int *);

int refresh_menu(MENU *,int,int *);

int refresh_submenu(MENU *,int,int *);


#endif