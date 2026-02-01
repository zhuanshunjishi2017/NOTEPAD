#ifndef GUI_H
#define GUI_H

#define DIALOG_X 170
#define DIALOG_Y 150
#define DIALOG_W 300
#define DIALOG_H 150
#define BUTTON_W 64
#define BUTTON_H 32


typedef struct 
{
    char text[32];
    int width;
    int height;
    void (*func)();
} BUTTON;

typedef struct
{
    char title[32];
    int width;
    int height;
    int x;
    int y;
} WINDOW;

typedef struct 
{
    int relative_x;
    int relative_y;
    int target_x;
    int target_y;
} DRAGPOS;




void draw_button(BUTTON *bu,int x,int y,int state);

void draw_window(WINDOW *win,int state);


int show_exit_dialog(WINDOW *dialog,BUTTON *button,int *flag);

//绘制一个对话框，返回0，1，2
int colorchanger(int color,int state);

DRAGPOS draw_win_frame(WINDOW *win,DRAGPOS *pos,int x,int y,int ,int,int *);

void save_bk_win(WINDOW *win,int x, int y);

#endif