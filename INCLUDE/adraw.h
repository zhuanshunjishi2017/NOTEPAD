#ifndef __ADRAW_H__
#define __ADRAW_H__
void draw_neutral32(int x, int y);
void draw_cry32(int x, int y);
void draw_smiley32(int x, int y);
void draw_smiley24(int x, int y);
void DrawRMB32(int x0, int y0, int color);
void DrawCheckmark(int x, int y, int size, int color);
void AutoScaleCheckmark(int x, int y, int color);
void draw_scanline(int x,int y,int l,int n,int color);
void start_scan(int x1,int y1,int x2,int y2,int n,int color,int speeddelay);
void rounded_bar(int x1, int y1, int x2, int y2, int r ,int color1, int color2,int state);
void draw_botton(int x1 ,int y1,int x2,int y2,int Cowercolor,int Bordercolor);
void draw_commoninput(int x1,int y1,char *s);
void draw_confirmbotton(int x1,int y1,char *s);
void draw_checkbutton(int x,int y,int state);
void Line_Thick_color(int x1, int y1, int x2, int y2, int radius,unsigned int color);


#endif
