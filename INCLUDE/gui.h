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

#define SMALL_BU_SIZE 28

#define SCROLL_W 18
#define SCROLL_H 30


typedef struct 
{
    char text[32];
    int width;
    int height;
    void (*func)();

    int is_highlight;
    int is_press;

} BUTTON;

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

typedef struct window
{
    char title[32];
    int width;
    int height;
    int x;
    int y;

    int (*update)(struct window *,int);

    BUTTON *button;
    ENTRY *entry;

    int is_fullscreen;

    int relative_x;
    int relative_y;

    int is_open;
    int is_title_click;
    int is_drag;

} WINDOW;



typedef struct 
{
    int target_x;
    int target_y;
} POSITION;

extern BUTTON confirm[2];

extern ENTRY entries[2];

extern BUTTON inputs[3];

extern BUTTON scrolls[3];

extern POSITION dialog_pos;

extern int dialog_state;

extern int is_edit_open;


void draw_button(BUTTON *bu,int x,int y,int state);
void draw_window(WINDOW *win,int state);
void draw_entry(ENTRY *en,int x,int y,int state);

void show_entry(ENTRY *en,int x,int y);
int show_button(BUTTON *button,int x,int y);

void init_entry(ENTRY *en);

int show_dialog(WINDOW *dialog);

void tackle_drag_window(WINDOW *win,POSITION *pos);

POSITION draw_win_frame(WINDOW *,POSITION *);

void save_bk_win(WINDOW *win,int x, int y);

void show_bottom_bar(BUTTON *,int);
void create_bar(int x,int y,int xend,int yend);
void create_scroll(BUTTON *bu,int x,int y,int state);


#endif