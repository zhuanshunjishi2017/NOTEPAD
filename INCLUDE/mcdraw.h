#ifndef __MCDRAW_H__
#define __MCDRAW_H__
void draw_main_toolbotton(int x,int color,char*s1,char*s2);
void draw_main_toolbotton_activate(int x,int color,char*s1,char*s2);
void draw_left_toolbotton(int y,int length,char*s);
void draw_left_toolbotton_activate(int y,int length,char*s);
int main_toolbotton_mouse_press(int x);
int left_toolbotton_mouse_press(int x);
void clear_main_all();
void clear_main_all2();
int rand0_7();
void draw_all_left_toolbutton(int n,int l,char *s[]);
void draw_divider(int y);

#endif
