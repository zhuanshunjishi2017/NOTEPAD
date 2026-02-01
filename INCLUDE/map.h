#ifndef __MAP_H__
#define __MAP_H__
void printPlates(int baseX, int baseY, char plates[8][10]);
void draw_map_clear(void);
void showTransferAnimation1(void);
void showLoadingAnimation(void);
void showTransferAnimation(void);
void draw_the_map();
void draw_map(int *page);
void watcher(int *page);
void handle(int *page) ;
void deal_window(int *page);
void charge_deal(int *page);
void rules(int *page) ;
void history(int *page);
void rules1(int *page);
#endif
