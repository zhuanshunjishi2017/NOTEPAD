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

    int is_highlight;
} MENU;

extern MENU main_menu[MENU_LEN];
extern MENU sub_menu[MENU_LEN][SUBMENU_LEN];
extern int is_menu_open[MENU_LEN];

void start_exit_dialog(void);
void start_open_dialog(void);



void create_menu_item(MENU *,int,int,int);//生成菜单
void create_submenu_item(MENU *,int,int,int,int);//绘制子菜单

void create_submenu(MENU *,int);

void show_menu(int);//显示菜单
int show_submenu(MENU *,int,int *);



int refresh_submenu(MENU *,int);
int refresh_menu(MENU *,int);




#endif