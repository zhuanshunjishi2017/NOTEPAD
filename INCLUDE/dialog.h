#ifndef DIALOG_H
#define DIALOG_H

extern WINDOW exit_dialog;
extern WINDOW open_dialog;
extern WINDOW about_dialog;

extern WINDOW edit_window;

int update_exit_dialog(WINDOW *dialog,int state);
int update_open_dialog(WINDOW *dialog,int state);
int update_about_dialog(WINDOW *dialog,int state);

int update_edit_window(WINDOW *dialog,int state);

void getdir(char *);

#endif