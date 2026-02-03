#ifndef GUI_H
#define GUI_H

#define SMALL_DIALOG_X 170
#define SMALL_DIALOG_Y 150
#define SMALL_DIALOG_W 300
#define SMALL_DIALOG_H 150

#define MID_DIALOG_X 160
#define MID_DIALOG_Y 135
#define MID_DIALOG_W 320
#define MID_DIALOG_H 175

#define ENTRY_W 295
#define ENTRY_H 32

#define BUTTON_W 64
#define BUTTON_H 32


typedef struct 
{
    char text[32];
    int width;
    int height;
    void (*func)();

    int is_highlight;

} BUTTON;

typedef struct
{
    char title[32];
    int width;
    int height;
    int x;
    int y;

    int relative_x;
    int relative_y;

    int is_open;
    int is_title_click;
    int is_drag;

} WINDOW;

typedef struct
{
    int width;
    int height;
    char content[128];

    int is_show;
    int is_focus;
    int is_highlight;
    int count_twinkle;

} ENTRY;

typedef struct 
{
    int target_x;
    int target_y;
} POSITION;

extern BUTTON confirm[2];
extern WINDOW exit_dialog;
extern WINDOW open_dialog;

extern ENTRY entries[2];

extern POSITION dialog_pos;

extern int dialog_state;


void draw_button(BUTTON *bu,int x,int y,int state);
void draw_window(WINDOW *win,int state);
void draw_entry(ENTRY *en,int x,int y,int state);

void show_entry(ENTRY *en,int x,int y);
int show_button(BUTTON *button,int x,int y);

void init_entry(ENTRY *en);

int show_open_dialog(WINDOW *win,ENTRY *entry,BUTTON *button);
int show_exit_dialog(WINDOW *dialog,BUTTON *button);

void tackle_drag_window(WINDOW *win,POSITION *pos);

POSITION draw_win_frame(WINDOW *,POSITION *);

void save_bk_win(WINDOW *win,int x, int y);

void getdir(char *);

#endif