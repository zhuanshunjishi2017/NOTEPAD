#ifndef __login_H__
#define __login_H__
#include "allfunc.h"
#pragma pack(push, 1) // 设置为1字节对齐
 typedef struct
    {
        char user_name[10];         // 用户名
        char pass_word[10];         // 密码
        int fine[8];                // 第一项违章金额，第二项违章扣分,后六项对应申诉要求,
        int if_fine;                // 是否违章
        int if_against;             // 是否申诉
        char fine_time[20];         // 违章时间
        char carboard[80];       // 车牌号，每个车牌号最多9个字符 + '\0'
        char brand[10];            // 车辆品牌
        int location;             // 违章地点
        int violation;           // 违章行为*/
        
    } USERS;
 #pragma pack(pop)   
//管理登录
void staff_login(int* func);

//绘制登录界面
void draw_user_login(void);
//用户登录函数
void user_login(int *func,int *unum);
//注册
void rigister_login(int *func);


#endif