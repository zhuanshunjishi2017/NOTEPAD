#include"allfunc.h"
void second_deal_window(int *page)
{
    char* location[] = {
        "华科附小", "图书馆", "机械楼", "管理学院", "体育馆", 
        "南二门", "计算机学院", "船海学院", "中操场", "东二区宿舍", 
        "青年园", "学术交流中心"
    };
    char *locations[20][4] = {
        {"未按规定停车，堵塞消防通道", "车辆占用人行道", "车辆停在禁停区域", "车辆停在校园出入口"},
        {"车辆停在图书馆入口", "未按规定停车", "占用残疾人停车位", "车辆停在绿化带内"},
        {"车辆停在机械楼出入口", "未按规定停车", "车辆停在消防栓前", "车辆停在应急通道"},
        {"车辆停在管理学院入口", "未按规定停车", "占用taff停车位", "车辆停在绿化带内"},
        {"车辆停在体育馆入口", "未按规定停车", "车辆停在应急通道", "车辆停在观众通道"},
        {"车辆停在南二门出入口", "未按规定停车", "车辆停在人行道上", "车辆停在禁停区域"},
        {"占用实验室设备装卸区", "停在学院正门台阶前", "占用新能源车充电位", "挤占教授专用停车区"},
        {"停放在试验池通道", "在学院交叉路口违停", "占用访客车位", "在消防栓前违规停车"},
        {"停放在运动场应急通道", "占用跑道周边缓冲区", "在观众席出入口停车", "挤占操场外围非机动车道"},
        {"堵塞宿舍楼消防通道", "占用垃圾清运专用车位", "在宿舍自行车棚前停车", "夜间违停于临时禁停区"},
        {"驶入园区绿地停车", "占用林间步行道", "在湖边观景平台违停", "停放在园内狭窄路段"},
        {"在会议车辆入口处停车", "停放在中心景观绿化带","堵塞交流人员进出通道","未按规定停车"}
    };
    FILE *fp ;
    int click = -1;
    long current_pos;
    USERS user;
    long file_size;
    char username[10];

    fp = fopen("data.dat", "rb+"); // 以读写模式打开文件
    if(fp==NULL)
    {
        printf("error!\n");
        exit(0);
    }
    {
        int j;
        USERS temp;
        int found_count =0;
        int record_count = 0;
        int file_size=0;
        fseek(fp, 0, SEEK_END);
        file_size = ftell(fp);
        record_count = file_size / sizeof(USERS);
        fseek(fp, 0, SEEK_SET);
        // 读取文件中的所有记录 
        for (j = 0; j < record_count; j++) 
        {
            
            current_pos = ftell(fp);  // 记录当前文件指针位置
            if (fread(&temp, sizeof(USERS), 1, fp) != 1) 
            {
                perror("读取记录失败");
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            if (temp.if_fine==2)
             {  // 查找if_fine==2的记录
                
                found_count++;
                break;
            }
        }
          // 如果没有找到符合条件的记录
        if (found_count == 0) 
        {
            bar1(400, 300, 624, 350, 0xFFFFFF);
            puthz(400, 300, "无违章记录可处理", 32, 40, 0xFF0000);
            fclose(fp);
            return;
        }
    }
    srand((unsigned)time(NULL)); 
    memset(&user, 0, sizeof(USERS));
    bar1(300, 400, 800, 600, 0xFFFFFF);
    fseek(fp, current_pos, SEEK_SET);
    fread(&user, sizeof(USERS), 1, fp);
    user.if_fine = 1;
    fseek(fp, current_pos, SEEK_SET);  // 定位到当前记录的起始位置
    fwrite(&user, sizeof(USERS), 1, fp);// 写入修改后的数据
    
    /*sprintf(buffer, "%p", fp);
    put_asc16_size(0, 100, 3, 3, buffer, 0x000000);*/
    // 2. 修改数据以表示第二次违章内容
    user.location = rand() % 12;  // 随机生成新的违章地点
    user.violation = rand() % 4;  // 随机生成新的违章行为
    user.if_against = 0;          // 标记为重复违章
    user.if_fine = 1;             // 重置处罚状态
    // 3. 将修改后的数据写回文件
    // 关闭鼠标显示
    mouse_off(&mouse);
    bar1(0, 0, 1024, 768, 0xFFFFFF);
    Readbmp64k(0, 0, "bmp\\user1.bmp");
    // 绘制界面元素
    puthz(50, 50, "处理详情页", 48, 50, 0x000000);
    rounded_bar(100, 150, 924, 600, 20, 0xFFFFFF, 0x000000, 0);
    // 显示当前记录信息
    puthz(150, 180, "违停车牌", 32, 40, 0x000000);

    {
        int row, col, offset;
        int x, y;
        int baseX = 350, baseY = 180;
        char plateBuf[80];
        char temp1[10];
        // 定位到车牌数据开始处，并读取 80 字节车牌数据（8个车牌，每个10字节）
        fseek(fp,60+current_pos, SEEK_SET);  // 跳过前60字节,输出车牌号
        fread(plateBuf, sizeof(plateBuf), 1, fp);
        
        // 初始化坐标，只初始化一次，保证所有输出在同一行
        x = baseX;
        y = baseY;
        
        // 遍历8个车牌部分
        for(row = 0; row < 8; row++)
        {
            offset = row * 10;
            for(col = 0; col < 10 && plateBuf[offset + col] != '\0'; )
            {
                // 如果为中文字符（GBK编码下，中文为双字节判断）
                if((unsigned char)plateBuf[offset + col] >= 0xA0)
                {
                    char temp1[3];
                    temp1[0] = plateBuf[offset+col];
                    temp1[1] = plateBuf[offset+col+1];
                    temp1[2] = '\0';
                    puthz(x, y, temp1, 32, 30, 0x000000);
                    col += 2;
                    x += 32;
                }
                else  // 英文或数字为单字节
                {
                    Put_Asc16_Size(x, y, 3, 3, plateBuf[offset+col], 0x000000);
                    col++;
                    x += 30;
                }
            }
        }
    }
  
    // 关闭文件
    fclose(fp);
    //puthz(300, 180, v[current_index].carboard, 32, 40, 0x000000);
    puthz(150, 230, "违停地点", 32, 40, 0x000000);
    puthz(330, 230, location[user.location], 32, 40, 0x000000);
    puthz(150, 280, "违停行为", 32, 40, 0x000000);
    puthz(330, 280, locations[user.location][user.violation], 32, 40, 0x000000);
    //行为对应照片打印
    //第一类：消防相关违规
    if  ((user.location == 0 && user.violation == 0) ||  // 堵塞消防通道
    (user.location == 2 && user.violation == 2) ||  // 消防栓前
    (user.location == 4 && user.violation == 2) ||  // 应急通道
    (user.location == 9 && user.violation == 0) ||  // 宿舍消防通道
    (user.location == 11 && user.violation == 0)){  // 宿舍消防通道
    Readbmp64k(300, 350, "bmp\\3.bmp");
    }
    // 第二类：出入口违规
    if((user.location == 0 && user.violation == 3) ||  // 校园出入口
    (user.location == 1 && user.violation == 0) ||  // 图书馆入口
    (user.location == 2 && user.violation == 0) ||  // 机械楼出入口
    (user.location == 3 && user.violation == 0) ||  // 管理学院入口
    (user.location == 4 && user.violation == 0) ||  // 体育馆入口
    (user.location == 5 && user.violation == 0)) { // 南二门出入口
    Readbmp64k(300, 350, "bmp\\5.bmp");
    } 
    
    // 第三类：特殊车位占用//(v[current_index].location == 11 && v[current_index]v.violation == 1))
    if ((user.location == 1 && user.violation == 2) ||  // 残疾人车位
    (user.location == 3 && user.violation == 2) ||  // 教职工车位
    (user.location == 6 && user.violation == 2) ||  // 新能源充电位
    (user.location == 7 && user.violation == 2) ||  // 访客车位
    (user.location == 9 && user.violation == 1) )  // 垃圾清运车位
    {// 垃圾清运车位
    Readbmp64k(300, 350, "bmp\\1.bmp");
    }
    // 第四类：绿化/人行道违规 (click=4)
    if ((user.location == 0 && user.violation == 1) ||  // 占用人行道
    (user.location == 1 && user.violation == 3) ||  // 绿化带内
    (user.location == 3 && user.violation == 3) ||  // 绿化带内
    (user.location == 5 && user.violation == 2) ||  // 人行道上
    (user.location == 10 && user.violation == 1)) {  // 景观绿化带
    Readbmp64k(300, 350, "bmp\\6.bmp");
    }
// 第五类：特殊区域违规 (click=5)
    if((user.location == 6 && user.violation == 1) ||  // 学院台阶前
    (user.location == 7 && user.violation == 1) ||  // 交叉路口
    (user.location == 8 && user.violation == 1) ||  // 跑道缓冲区
    (user.location == 9 && user.violation == 3) ||  // 夜间违停
    (user.location == 11 && user.violation == 3)) {  // 夜间违停
    Readbmp64k(300, 350, "bmp\\2.bmp");
    }
    
    // 第六类：其他违规 (click=6)
    else{
        Readbmp64k(300, 350, "bmp\\4.bmp");
    }
     // 扣分选项按钮
    bar1(220, 520, 350, 560, 0xFFD700);
    puthz(230, 520, "扣四分", 32, 40, 0x000000);
    bar1(420, 520, 550, 560, 0xFFD700);
    puthz(430, 520, "扣八分", 32, 40, 0x000000);
    bar1(620, 520, 750, 560, 0xFFD700);
    puthz(630, 520, "扣十二分", 32, 40, 0x000000);
    draw_botton(600, 405, 700, 455, 0xFFFFFF, 0x000000);
    puthz_coverd(590, 415, "误判认定", 2, 32, 30, 0x000000);
    // 操作按钮
    draw_botton(250, 635, 350, 695, 0xFFFFFF, 0x000000);
    puthz_coverd(230, 652, "返回上页", 4, 32, 30, 0x000000);
    draw_botton(440, 635, 560, 695, 0xFFFFFF, 0x000000);
    puthz_coverd(430, 652, "提交处理", 4, 32, 30, 0x000000);
    draw_botton(660, 635, 760, 695, 0xFFFFFF, 0x000000);
    puthz_coverd(650, 652, "规则查看", 2, 32, 30, 0x000000);
    
    // 主循环
    while (1) 
    {
        mouse_show(&mouse);
        
        //希望变色（实现提示）
        if(mouse_press(600, 405, 700, 455)==1)
        {
            draw_botton(600, 405, 650, 455, 0xFFFFFF, 0x32CD320);
            puthz_coverd(590, 415, "误判认定", 2, 32, 30, 0x000000);
            click=0;
        }
        if (mouse_press(220, 520, 350, 560)==1) 
        {
            bar1(220, 520, 350, 560, 0x32CD32);
            puthz(230, 520, "扣四分", 32, 40, 0x000000);
            click=4;
        }
        if(mouse_press(420, 520, 550, 560)==1)
        {
            bar1(420, 520, 550, 560, 0x32CD32);
            puthz(430, 520, "扣八分", 32, 40, 0x000000);
            click=8;
        }
        if(mouse_press(620, 520, 750, 560)==1)
        {
            bar1(620, 520, 750, 560, 0x32CD32);
            puthz(630, 520, "十二分", 32, 40, 0x000000);
            click=12;
        }
         if (mouse_press(440, 635, 560, 695) == 1 && click != -1) 
        {    
            // 更新当前记录的处罚信息
            user.if_fine = 1;
            user.fine[0] = click * 10;  // 罚款金额
            user.fine[1] = click;      // 扣分值
            if (click == 0) 
            {
                user.if_fine = 0;  // 如果选择误判认定，则清除处罚标记
            }

            // 将最新的处罚记录追加到文件末尾
            
            if (fp== NULL) 
            {
                perror("无法打开文件进行追加写入");
               
                exit(0);
            }
            fp= fopen("data.dat", "rb+"); // 以读写模式打开文件
            fseek(fp, 0, SEEK_END);  // 定位到当前记录
            if (fwrite(&user, sizeof(USERS), 1, fp) != 1)
             {
                perror("写入失败");
                
                exit(0);
            }
            fflush(fp); // 刷新文件缓冲区
            // 跳转到历史记录页面
            showTransferAnimation1();
            fclose(fp);
            *page=7;
            break;
            }
             // 返回按钮
        if (mouse_press(250, 635, 350, 695) == 1) 
        {
            *page = 7;
            
            break;
        }
        // 规则查看
        if (mouse_press(660, 635, 760, 695) == 1) 
        {
            *page = 11;
            break;
        }
    }
}
int watch_func1(USERS temp)
{
                char* location_output[12] = {0};
                char* violation_output[12][4] = {0};
                // 显示查询界面
                bar1(35, 91, 500, 500, 0xFFFFFF);

                if(temp.if_fine==1||temp.if_fine==2) 
                {
                    prt_hz16_asc16_size(150, 100, 2, 2, temp.carboard, 0x000000, "HZK\\hzk16");
                        if(temp.if_fine==2)
                        {
                            puthz(300,150,"（已处理）", 32, 30, 0x000000);
                        }
                        puthz(35, 200, "违章类型", 32, 30, 0x000000);
                        puthz(35, 250, "违章地点", 32, 30, 0x000000);
                        puthz(35, 300, "违章时间", 32, 30, 0x000000);
                     
                        // 读取 location 和 violation
                        // 输出违章时间
                        puthz(190, 300, temp.fine_time, 32, 30, 0x000000);

                        // 检查 location 和 violation 的范围
                        if (temp.location >= 0 && temp.location < 12 && temp.violation >= 0 && temp.violation < 4)
                        {
                            // 根据 location 和 violation 的值输出对应的字符串
                            location_input(location_output, temp.location);
                            violation_input(violation_output, temp.location, temp.violation);

                            if (location_output[temp.location] != NULL)
                            {
                                puthz(190, 200, location_output[temp.location], 32, 30, 0x000000);
                                free(location_output[temp.location]);  // 释放内存
                            }

                            if (violation_output[temp.location][temp.violation] != NULL)
                            {
                                puthz(190, 250, violation_output[temp.location][temp.violation], 32, 30, 0x000000);
                                free(violation_output[temp.location][temp.violation]);  // 释放内存
                            }
                        }
                    
                        else
                        {
                            puthz(190, 200, "无违章记录", 32, 30, 0x000000);
                            puthz(190, 250, "您是违法好公民，请继续加油哟", 24, 25, 0x000000);
                        }
                    
                    return 1; // 标记为查询界面已打开
                }
                
                else if(temp.if_fine==0)
                {
                    puthz(140, 160, "无违章记录", 48, 50, 0x000000);
                    puthz(140, 250, "您是违法好公民，请继续加油哟", 24, 25, 0x000000);
                    return 1; // 标记为查询界面已打开
                }
                else
                {
                    puthz(190, 200, "读取违章信息失败", 32, 30, 0xFF068);
                    puthz(190, 250, "请检查数据文件", 24, 25, 0xFF068);
                    return 1; // 标记为查询界面已打开
                }
}
int watch_func2(USERS temp)
{
    
    bar1(35, 91, 500, 500, 0xFFFFFF);
    if(temp.if_fine==1||temp.if_fine==2) 
    {
        int col;
        int x;
        int baseX = 150;
        // 初始化坐标，只初始化一次，保证所有输出在同一行
        x = baseX;
        for(col = 0; col < 10 && temp.carboard[ col] != '\0'; )
            {
                // 如果为中文字符（GBK编码下，中文为双字节判断）
                if((unsigned char)temp.carboard[ col] >= 0xA0)
                {
                    char temp2[3];
                    temp2[0] = temp.carboard[col];
                    temp2[1] = temp.carboard[col+1];
                    temp2[2] = '\0';
                    puthz(x, 100, temp2, 32, 30, 0x000000);
                    col += 2;
                    x += 32;
                }
                else  // 英文或数字为单字节
                {
                    Put_Asc16_Size(x, 100, 3, 3, temp.carboard[col], 0x000000);
                    col++;
                    x += 30;
                }
            }
            if  ((temp.location == 0 && temp.violation == 0) ||  // 堵塞消防通道
				                (temp.location == 2 && temp.violation == 2) ||  // 消防栓前
				                (temp.location == 4 &&temp.violation == 2) ||  // 应急通道
				                (temp.location == 9 && temp.violation == 0) ||  // 宿舍消防通道
				                (temp.location == 11 && temp.violation == 0))
                                {  // 宿舍消防通道
				                Readbmp64k(50, 150, "bmp\\31.bmp");
				                }
            else if((temp.location == 0 && temp.violation == 3) ||  // 校园出入口
            (temp.location == 1 &&temp.violation == 0) ||  // 图书馆入口
            (temp.location == 2 && temp.violation == 0) ||  // 机械楼出入口
            (temp.location == 3 && temp.violation == 0) ||  // 管理学院入口
            (temp.location == 4 && temp.violation == 0) ||  // 体育馆入口
            (temp.location == 5 &&temp.violation == 0)) 
            { // 南二门出入口
        
            Readbmp64k(50, 150,  "bmp\\51.bmp");
            } 
            else if ((temp.location == 1 && temp.violation == 2) ||  // 残疾人车位
            (temp.location == 3 && temp.violation == 2) ||  // 教职工车位
            (temp.location == 6 && temp.violation == 2) ||  // 新能源充电位
            (temp.location == 7 && temp.violation == 2) ||  // 访客车位
            (temp.location == 9 && temp.violation == 1) )  // 垃圾清运车位
            {
            Readbmp64k(50, 150,  "bmp\\11.bmp");
            }
            else if ((temp.location == 0 && temp.violation == 1) ||  // 占用人行道
            (temp.location == 1 && temp.violation == 3) ||  // 绿化带内
            (temp.location == 3 && temp.violation == 3) ||  // 绿化带内
            (temp.location == 5 && temp.violation == 2) ||  // 人行道上
            (temp.location == 10 && temp.violation == 1)) 
            {  // 景观绿化带
            Readbmp64k(50, 150,  "bmp\\61.bmp");
            }
            else // 第五类：特殊区域违规
            if((temp.location == 6 && temp.violation == 1) ||  // 学院台阶前
            (temp.location == 7 && temp.violation == 1) ||  // 交叉路口
            (temp.location == 8 && temp.violation == 1) ||  // 跑道缓冲区
            (temp.location == 9 && temp.violation == 3) ||  // 夜间违停
            (temp.location == 11 && temp.violation == 3)) 
            {  // 夜间违停
            Readbmp64k(50, 150,  "bmp\\21.bmp");
            }
            // 第六类：其他违规
            else
            {
                Readbmp64k(50, 150, "bmp\\41.bmp");
            }
            return 1; // 标记为查询界面已打开
        }
        else
        {
        puthz(140, 160, "无违章记录", 48, 50, 0x000000);
        puthz(140, 250, "您是违法好公民，请继续加油哟", 24, 25, 0x000000);
        return 1; // 标记为查询界面已打开
        }
}
void put_car_picture(USERS temp)
{
    if(strcmp(temp.brand,"1")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "BMW730i(黑色)", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\bmw.bmp");
        }
        else if(strcmp(temp.brand,"2")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "Maybach", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\benz.bmp");
        }
        else if(strcmp(temp.brand,"3")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "Audi A8", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\audi.bmp");
        }
        else if(strcmp(temp.brand,"4")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "TOYOTA", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\toyota.bmp");
        }
        else if(strcmp(temp.brand,"5")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "MAGOTAN", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\vw.bmp");
        }
        else if(strcmp(temp.brand,"6")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "Ford-Focus", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\focus.bmp");
        }
        else if(strcmp(temp.brand,"7")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "五菱MINI", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\mini.bmp");
        }
        else if(strcmp(temp.brand,"8")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "ID.6(eletric)", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\ID.bmp");
        }
        else if(strcmp(temp.brand,"9")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "Tesla-Model3", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\tesla.bmp");
        }
        else if(strcmp(temp.brand,"b")==0)
        {
            prt_hz16_asc16_size(110, 380, 3, 3, "Dodge-Challenger", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\police.bmp");
        }
        else if(strcmp(temp.brand,"c")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "Scania", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\scania.bmp");
        }
        else if(strcmp(temp.brand,"0")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "Audi-Q5L", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\audiQ5.bmp");
        }
}
 int deal_func1()
{
    int current_rating = 0; // 当前评分
    int i;
    int new_rating = 0;
    int update_needed = 0; // 标记是否需要更新界面

    while (1)
    {
        mouse_show(&mouse);

        // 减少鼠标检测频率
        new_rating = 0;
        for(i = 0; i < 10; i++)
        {
            int boxX1 = 350 + i * (40 + 5);
            int boxY1 = 520;
            int boxX2 = boxX1 + 40;
            int boxY2 = boxY1 + 40;
            if(mouse_press(boxX1, boxY1, boxX2, boxY2) == 1)
            {
                new_rating = i + 1;
                // 减少延迟时间
                delay(100); 
                update_needed = 1;
                break;
            }
        }

        if(update_needed)
        {
            // 每次评分时先清除整个评分区域（由评分框构成的区域），确保之前的笑脸被覆盖
            int totalWidth = 10 * (45) - 5;
            bar1(350, 520, 350 + totalWidth, 520 + 40, 0xFFFFFF);
            for(i = 0; i < 10; i++)
            {
                int boxX1 = 350 + i * (45);
                int boxY1 = 520;
                int boxX2 = boxX1 + 40;
                int boxY2 = boxY1 + 40;
                // 绘制不填色的矩形边框
                bar2(boxX1, boxY1, boxX2, boxY2, 0x000000);
            }
            // 更新当前评分为新评分
            current_rating = new_rating;
            mouse_off(&mouse);
            // 重绘从第一个评分框到当前评分框的笑脸
            for(i = 0; i < current_rating; i++)
            {
                int boxX1 = 350 + i * (45);
                int centerX = boxX1 + 20;
                // 根据评分值判断采用哪种表情
                if(current_rating < 4)
                {
                    bar1(230, 600, 920, 650, 0xFFFFFF);
                    draw_cry32(centerX - 16, 525);
                    puthz(240, 610, "抱歉此次服务使您感到不满意，如有问题请", 24,25,  0xFF068);
                    puthz(715, 610, "前往处罚反馈页面", 24,25,  0xCD5C5C);
                    Line3(715,640,910,640,1,0xCD5C5C);
                }
                else if(current_rating >= 4 && current_rating <= 7)
                {
                    bar1(230, 600, 920, 650, 0xFFFFFF);
                    mouse_off(&mouse);
                    draw_neutral32(centerX - 16, 525);
                    // 评分中：中性表情，对应感谢反馈
                    puthz(350, 610,  "感谢反馈，我们的服务将继续提升", 24,25,  0xFF068);
                }
                else  // current_rating >= 8
                {
                    bar1(230, 600, 920, 650, 0xFFFFFF);
                    mouse_off(&mouse);
                    draw_smiley32(centerX - 16, 525);
                    // 评分高：笑脸，对应感谢全力支持
                    puthz(350, 610, "感谢您的全力支持，我们将竭诚为您服务", 24,25, 0xFF068);
                }
            }
            update_needed = 0;
        }

        if(mouse_press(715,610,910, 650)==1) 
        {
            mouse_off(&mouse);
            delay(100);
            // 调试输出
            return 27;    // 跳转到处罚反馈页面
        }
        else if(mouse_press(420, 680, 540, 740)==1)
        {
            // 同时重置评分变量
            current_rating = 0;
            delay(100);
            break;
        }
        else if(mouse_press(70,525,190,658)==1||mouse_press(70, 210, 190, 340)==1||mouse_press(70, 360, 190, 515)==1)
        {
            mouse_off(&mouse);
            delay(100);
            break;
        }
    }
}
            