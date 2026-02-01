#include"allfunc.h"     
#include<stdio.h>
//注：本软件为管理模拟软件，故一切测试数据已经预存                                                                                                                                                                                                                                                                                                                                                            #include<allfunc.h>
//违停信息模拟预存
void showTransferAnimation1(void) 
{
    /* 圆环参数 */
    int centerX = 512;  /* 圆心x坐标 */
    int centerY = 300;  /* 圆心y坐标 */
    int radius = 80;    /* 圆半径 */
    int barWidth = 10;  /* 竖条宽度 */
    int barHeight = 20; /* 竖条高度 */
    int i, angle, x, y;
    
    /* 文字参数 */
    int textX = 350;    /* 文字起始x坐标 */
    int textY = 500;    /* 文字y坐标 */
    
    /* 清空区域 */
    bar1(50, 120, 974, 600, 0xFFFFFF);
    
    /* 绘制圆环 */
    angle = 0;
    while(angle < 360) {
        x = centerX + radius * cos(angle * 3.14159 / 180);
        y = centerY + radius * sin(angle * 3.14159 / 180);
        bar1(x, y, x+1, y+1, 0x000000);
        angle += 5;
    }
    
    /* 竖条动画 */
    i = 0;
    while(i < 12) 
    {
        angle = i * 30;
        x = centerX + radius * cos(angle * 3.14159 / 180) - barWidth/2;
        y = centerY + radius * sin(angle * 3.14159 / 180) - barHeight/2;
        bar1(x, y, x+barWidth, y+barHeight, 0x000000);
        delay(100);
        i++;
    }
    
    /* 逐个显示文字 */
    puthz(textX, textY, "正", 32, 40, 0x000000);
    delay(200);
    puthz(textX+32, textY, "在", 32, 40, 0x000000);
    delay(200);
    puthz(textX+64, textY, "传", 32, 40, 0x000000);
    delay(200);
    puthz(textX+96, textY, "输", 32, 40, 0x000000);
    delay(200);
    puthz(textX+128, textY, "提", 32, 40, 0x000000);
    delay(200);
    puthz(textX+160, textY, "醒", 32, 40, 0x000000);
    delay(200);
    puthz(textX+192, textY, "信", 32, 40, 0x000000);
    delay(200);
    puthz(textX+224, textY, "息", 32, 40, 0x000000);
    delay(200);
    puthz(textX+256, textY, "到", 32, 40, 0x000000);
    delay(200);
    puthz(textX+288, textY, "用", 32, 40, 0x000000);
    delay(200);
    puthz(textX+320, textY, "户", 32, 40, 0x000000);
    delay(200);
    puthz(textX+352, textY, "端", 32, 40, 0x000000);
    delay(1000);
}
void showLoadingAnimation(void) 
{
    int centerX = 915;   /* 圆心x坐标(830+1000)/2 */
    int centerY = 200;   /* 圆心y坐标(50+350)/2 */
    int radius = 80;     /* 圆半径 */
    int barWidth = 10;   /* 竖条宽度 */
    int barHeight = 20;  /* 竖条高度 */
    int barCount = 12;   /* 竖条数量 */
    int i, angle, x, y;
    int prevAngle, prevX, prevY;
    
    /* 清空加载区域 */
    bar1(830, 50, 1000, 350, 0xFFFFFF);
    
    /* 绘制圆形边框 */
    for(angle = 0; angle < 360; angle++)
     {
        x = centerX + radius * cos(angle * 3.14159 / 180);
        y = centerY + radius * sin(angle * 3.14159 / 180);
        bar1(x, y, x+1, y+1, 0x000000);
    }
    
    /* 动画循环 */
    for(i = 0; i < barCount; i++) 
    {
        /* 清除上一帧 */
        if(i > 0) {
            prevAngle = (i-1) * 360/barCount;
            prevX = centerX + radius * cos(prevAngle * 3.14159 / 180) - barWidth/2;
            prevY = centerY + radius * sin(prevAngle * 3.14159 / 180) - barHeight/2;
            bar1(prevX, prevY, prevX+barWidth, prevY+barHeight, 0xFFFFFF);
        }
        
        /* 绘制当前竖条 */
        angle = i * 360/barCount;
        x = centerX + radius * cos(angle * 3.14159 / 180) - barWidth/2;
        y = centerY + radius * sin(angle * 3.14159 / 180) - barHeight/2;
        bar1(x, y, x+barWidth, y+barHeight, 0x000000);
        
        delay(200); /* 控制动画速度 */
    }
}
//信息传输动画
void showTransferAnimation(void) 
{
    /* 圆环参数 */
    int centerX = 512;  /* 圆心x坐标 */
    int centerY = 300;  /* 圆心y坐标 */
    int radius = 80;    /* 圆半径 */
    int barWidth = 10;  /* 竖条宽度 */
    int barHeight = 20; /* 竖条高度 */
    int i, angle, x, y;
    
    /* 文字参数 */
    int textX = 350;    /* 文字起始x坐标 */
    int textY = 500;    /* 文字y坐标 */
    
    /* 清空区域 */
    bar1(100, 150, 924, 600, 0xFFFFFF);
    
    /* 绘制圆环 */
    angle = 0;
    while(angle < 360) {
        x = centerX + radius * cos(angle * 3.14159 / 180);
        y = centerY + radius * sin(angle * 3.14159 / 180);
        bar1(x, y, x+1, y+1, 0x000000);
        angle += 5;
    }
    
    /* 竖条动画 */
    i = 0;
    while(i < 12) 
    {
        angle = i * 30;
        x = centerX + radius * cos(angle * 3.14159 / 180) - barWidth/2;
        y = centerY + radius * sin(angle * 3.14159 / 180) - barHeight/2;
        bar1(x, y, x+barWidth, y+barHeight, 0x000000);
        delay(100);
        i++;
    }
    
    /* 逐个显示文字 */
    puthz(textX, textY, "正", 32, 40, 0x000000);
    delay(200);
    puthz(textX+32, textY, "在", 32, 40, 0x000000);
    delay(200);
    puthz(textX+64, textY, "传", 32, 40, 0x000000);
    delay(200);
    puthz(textX+96, textY, "输", 32, 40, 0x000000);
    delay(200);
    puthz(textX+128, textY, "提", 32, 40, 0x000000);
    delay(200);
    puthz(textX+160, textY, "醒", 32, 40, 0x000000);
    delay(200);
    puthz(textX+192, textY, "信", 32, 40, 0x000000);
    delay(200);
    puthz(textX+224, textY, "息", 32, 40, 0x000000);
    delay(200);
    puthz(textX+256, textY, "到", 32, 40, 0x000000);
    delay(200);
    puthz(textX+288, textY, "用", 32, 40, 0x000000);
    delay(200);
    puthz(textX+320, textY, "户", 32, 40, 0x000000);
    delay(200);
    puthz(textX+352, textY, "端", 32, 40, 0x000000);
    delay(1000);
}
//车牌打印函数
void printPlates(int baseX, int baseY, char plates[8][10]) 
{
    int row, col;
    int x = baseX;
    int y = baseY;
    
    for(row = 0; row < 8; row++) 
    {
        // 跳过空车牌
        if(plates[row][0] == '\0') continue;
        
        // 打印当前车牌的所有字符
        for(col = 0; col < 10 && plates[row][col] != '\0'; col++)
        {
            // 处理中文字符(GBK双字节)
            if((unsigned char)plates[row][col] >= 0xA0) 
            {
                char temp[3];
                temp[0] = plates[row][col];
                temp[1] = plates[row][col+1];
                temp[2] = '\0';
                puthz(x, y, temp, 32, 30, 0x000000);
                col++; // 跳过下一个字节
                x += 32;
            }
            else  // 处理英文/数字(单字节)
            {
                Put_Asc16_Size(x, y, 3, 3, plates[row][col], 0x000000);
                x += 30;
            }
        }
        
        // 换行处理
        x = baseX;
        y += 50;  // 行间距50像素
    }
}

void draw_map_clear(void)
//单纯的绘制地图的必要元素
{
    mouse_off(&mouse);
    bar1(0, 0, 1024, 768, 0xFFFFFF); 
    Readbmp64k(0, 0, "bmp\\map4.bmp");
    draw_main_toolbotton(0, 0xBD32, "监控信息", "展示");
    draw_main_toolbotton(264, 0xBD32, "实时违章", "处理");
    draw_main_toolbotton(528, 0xBD32, "处罚申诉", "处理");
}
void draw_the_map(void)
{
    mouse_off(&mouse);
    bar1(0, 0, 1024, 768, 0xFFFFFF); 
    Readbmp64k(0, 0, "bmp\\map4.bmp");
    draw_main_toolbotton(0, 0xBD32, "监控信息", "展示");
    draw_main_toolbotton(264, 0xBD32, "实时违章", "处理");
    draw_main_toolbotton(528, 0xBD32, "处罚申诉", "处理");
    bar1(353, 131, 377, 155, 0xFF068); // 华科附小
    bar1(185, 335, 209, 359, 0xFF068); // 图书馆
    bar1(505, 293, 529, 317, 0xFF068); // 机械楼
    bar1(535, 65, 559, 89, 0xFF068);   // 管理学院
    bar1(490, 450, 514, 474, 0xFF068); // 体育馆
    bar1(37, 500, 61, 524, 0xFF068);   // 南二门
    bar1(171, 487, 195, 511, 0xFF068); // 计算机学院
    bar1(320, 425, 344, 449, 0xFF068); // 船海学院
    bar1(627, 465, 651, 489, 0xFF068); // 中操场
    bar1(654, 153, 678, 177, 0xFF068); // 东二区宿舍
    bar1(62, 245, 86, 269, 0xFF068);   // 青年园
    bar1(115, 105, 139, 129, 0xFF068); // 学术交流中心
    bar1(710, 243, 734, 267, 0xFF068); // 博士生宿舍

}
//管理员端主界面
void draw_map(int *page)
{
    draw_map_clear();
    Readbmp64k(800,0,"bmp\\AIA.bmp");
    puthz(800, 270, "尊敬的管理员", 32, 30, 0x000000);
    puthz(800, 320, "欢迎使用", 48, 50, 0x000000);
    puthz(800, 400, "违停管理系统", 32, 30, 0x000000);
    puthz(830, 540, "请点击左侧按钮进行操作", 32, 30, 0x000000);
    draw_confirmbotton(830, 680, "返回主界面"); // 返回主界面
    while (1)
    {
        mouse_show(&mouse);  
        if(mouse_press(0,590,264,750)==1)
        {
            *page=6;
            break;
        }
        if(mouse_press(264,590,518,750)==1)
        {
            *page=7;
            break;
        }
        if(mouse_press(528,590,792,750)==1)
        {
            *page=8;
            break;
        }
        if (mouse_press(830, 680, 1024, 740) == 1) 
        {
            *page=0;  
            break;
        }   
    }
}
//监控信息查询
void watcher(int *page) { 
    char* locations[] = {
       "华科附小", "图书馆", "机械楼", "管理学院", "体育馆",
       "南二门", "计算机学院", "船海学院", "中操场", "东二区宿舍",
       "青年园", "学术交流中心", "博士生宿舍"
    };
    int i=0;
    int x_start = 100;  // 起始X坐标
    int y_start = 600;  // 起始Y坐标
    int x_offset = 120; // 每个条目的水平间距
    int y_offset = 40;  // 每个条目的垂直间距
    int font_size = 16; // 汉字大小：16x16
    int color = 0xFF068;  // 字体颜色
    int part = 16;  // 每个汉字的宽度
    int selected = 0;
    char locationName[50], brand[50], function[100];    
    int max_width = 600; // 最大宽度
    
    int x = x_start, y = y_start;
    // 关闭鼠标，防止绘制时出现错误
    mouse_off(&mouse);
    bar1(0,0,1024,768,0xFFFFFF);
    Readbmp64k(0, 0, "bmp\\map4.bmp");
    // 绘制监控界面
    prt_hz24_asc32(50, 710, "监控地点信息", 0x000000, "HZK\\HZK24s"); // 标题
    //绘制功能按钮
    rounded_bar(830, 50, 1000, 350, 20, 0xFFFFFF, 0x000000, 0);
    puthz(840,70,"设备状况",24,25,0x000000);
    bar1(830, 500,1000,560,0x32CD32);
    puthz(840,520,"检查设备状态",24,25,0xFFFFFFF);
    bar1(830, 600, 1000, 660, 0x32CD32); 
    puthz(840, 620, "返回上一页", 24, 25, 0xFFFFFF);
    // 绘制所有监控地点
    bar1(353, 131, 377, 155, 0xFF068); // 华科附小
    bar1(185, 335, 209, 359, 0xFF068); // 图书馆
    bar1(505, 293, 529, 317, 0xFF068); // 机械楼
    bar1(535, 65, 559, 89, 0xFF068);   // 管理学院
    bar1(490, 450, 514, 474, 0xFF068); // 体育馆
    bar1(37, 500, 61, 524, 0xFF068);   // 南二门
    bar1(171, 487, 195, 511, 0xFF068); // 计算机学院
    bar1(320, 425, 344, 449, 0xFF068); // 船海学院
    bar1(627, 465, 651, 489, 0xFF068); // 中操场
    bar1(654, 153, 678, 177, 0xFF068); // 东二区宿舍
    bar1(62, 245, 86, 269, 0xFF068);   // 青年园
    bar1(115, 105, 139, 129, 0xFF068); // 学术交流中心
    bar1(710, 243, 734, 267, 0xFF068); // 博士生宿舍
    // 遍历所有位置名称
    for (i = 0; i < sizeof(locations) / sizeof(locations[0]); i++) 
    {
        // 显示汉字
        puthz(x, y, (char*)locations[i], font_size, part, color);
        // 更新横坐标，如果超出最大宽度，则换行
        x += x_offset;
        if (x + x_offset > x_start + max_width) 
        {
            x = x_start; // 重置为起始X坐标
            y += y_offset; // 换行，增加垂直偏移
        }
    }
    {
        int x_start = 90;  // 表格起始X坐标
        int y_start =  580;  // 表格起始Y坐标
        int cell_width = 120;  // 每个单元格的宽度
        int cell_height = 40;  // 每个单元格的高度
        int rows = 3;  // 表格的行数
        int cols = 5;  // 表格的列数
        int font_size = 16;  // 字体大小
        int color = 0x000000;  // 字体颜色

        int i, j, index = 0;

        // 绘制表格
        for (i = 0; i < rows; i++) 
        {
            for (j = 0; j < cols; j++)
            {
                int x = x_start + j * cell_width;
                int y = y_start + i * cell_height;

                // 绘制单元格边框
                bar1(x, y, x + cell_width, y + 1, color); // 上边框
                bar1(x, y, x + 1, y + cell_height, color); // 左边框
                bar1(x + cell_width - 1, y, x + cell_width, y + cell_height, color); // 右边框
                bar1(x, y + cell_height - 1, x + cell_width, y + cell_height, color); // 下边框

            }
        }
    }
    while (1) 
    {
        mouse_show(&mouse);
        // 监控地点点击检测
        if (mouse_press(830, 600, 1024, 660) == 1) 
        {
            *page = 5;  // 返回主界面
            mouse_off(&mouse);
            break;
        }
        if(mouse_press(830, 500,1000,560)==1)
        {
           mouse_off(&mouse);
            rounded_bar(830, 50, 1000, 350, 20, 0xFFFFFF, 0x000000, 0); 
            showLoadingAnimation();
            rounded_bar(830, 50, 1000, 350, 20, 0xFFFFFF, 0x000000, 0); 
            puthz(840,160,"设备正常",24,25,0x000000);
            bar1(830, 500,1000,560,0x32CD32);
            puthz(840,520,"管理员已知晓",24,25,0xFFFFFFF);
            delay(500);
            //puthz(840,70,"设备状况",24,25,0x000000);
            bar1(830, 500,1000,560,0x32CD32);
            puthz(840,520,"检查设备状态",24,25,0xFFFFFFF);
            rounded_bar(830, 50, 1000, 350, 20, 0xFFFFFF, 0x000000, 0);   
            puthz(840,70,"设备状况",24,25,0x000000);
        }
        //具体监控信息查看
        if (mouse_press(353, 131, 377, 155) == 1) 
        {
           
            strcpy(locationName, "华科附小");
            strcpy(brand, "海康威视");
            strcpy(function, "高清视频传输");
            mouse_off(&mouse);
            bar1(353, 131, 377, 155, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(185, 335, 209, 359) == 1) 
        {
            strcpy(locationName, "图书馆");
            strcpy(brand, "大华");
            strcpy(function, "高清视频监控");
            mouse_off(&mouse);
            bar1(185, 335, 209, 359, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(505, 293, 529, 317) == 1) 
        {
            strcpy(locationName, "机械楼");
            strcpy(brand, "海康威视");
            strcpy(function, "高清视频监控");
            mouse_off(&mouse);
            bar1(505, 293, 529, 317, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(535, 65, 559, 89) == 1) 
        {
            strcpy(locationName, "管理学院");
            strcpy(brand, "大华");
            strcpy(function, "高清视频监控");
            mouse_off(&mouse);
            bar1(535, 65, 559, 89, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(490, 450, 514, 474) == 1) 
        {
            strcpy(locationName, "体育馆");
            strcpy(brand, "海康威视");
            strcpy(function, "高清视频传输");
            mouse_off(&mouse);
            bar1(490, 450, 514, 474, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(37, 500, 61, 524) == 1) 
        {
            strcpy(locationName, "南二门");
            strcpy(brand, "海康威视");
            strcpy(function, "智能识别监控");
            mouse_off(&mouse);
            bar1(37, 500, 61, 524, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(171, 487, 195, 511) == 1) 
        {
            strcpy(locationName, "计算机学院");
            strcpy(brand, "海康威视");
            strcpy(function, "远程视频监控");
            bar1(171, 487, 195, 511, 0xFF068);
            mouse_off(&mouse);
            selected = 1;
        } 
        else if (mouse_press(320, 425, 344, 449) == 1) 
        {
            strcpy(locationName, "船海学院");
            strcpy(brand, "海康威视");
            strcpy(function, "车牌识别监控");
            mouse_off(&mouse);
            bar1(320, 425, 344, 449, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(627, 465, 651, 489) == 1) 
        {
            strcpy(locationName, "中操场");
            strcpy(brand, "大华");
            strcpy(function, "全景监控");
            mouse_off(&mouse);
            bar1(627, 465, 651, 489, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(654, 153, 678, 177) == 1) 
        {
            strcpy(locationName, "东二区宿舍");
            strcpy(brand, "海康威视");
            strcpy(function, "宿舍停车区监控");
            mouse_off(&mouse);
            bar1(654, 153, 678, 177, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(62, 245, 86, 269) == 1) 
        {
            strcpy(locationName, "青年园");
            strcpy(brand, "海康威视");
            strcpy(function, "人工智能巡检监控");
            mouse_off(&mouse);
            bar1(62, 245, 86, 269, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(115, 105, 139, 129) == 1) 
        {
            strcpy(locationName, "学术交流中心");
            strcpy(brand, "大华");
            strcpy(function, "大门智能监控");
            mouse_off(&mouse);
            bar1(115, 105, 139, 129, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(710, 243, 734, 267) == 1) 
        {
            strcpy(locationName, "博士生宿舍");
            strcpy(brand, "海康威视");
            strcpy(function, "门禁停车区域监控");
            bar1(710, 243, 734, 267, 0xFF068);
            mouse_off(&mouse);
            selected = 1;
        }
        // 如果选中了某个监控点，显示详细信息窗口
        if (selected) 
        {
            mouse_off(&mouse);
            bar1(312, 200, 792, 500, 0xFFFFFF); // 绘制信息窗口背景
            bar1(312, 200, 792, 230, 0x000000); // 标题栏
            puthz(345, 200, "监控详情", 24, 25, 0xFFFFFF); // 标题
            puthz(322, 260, "地点：", 24, 25, 0x000000);
            puthz(402, 260, locationName, 24, 25, 0x000000);
            puthz(322, 300, "品牌：", 24, 25, 0x000000);
            puthz(402, 300, brand, 24, 25, 0x000000);
            puthz(322, 340, "功能：", 24, 25, 0x000000);
            puthz(402, 340, function, 24, 25, 0x000000);
            //居中返回按钮
            bar1(450, 400, 650, 450, 0x32CD32);  // 绿色按钮
            puthz(520, 415, "返回", 24, 25, 0xFFFFFF);  // 按钮文字（白色）
            //等待用户操作
            while (1) {
                mouse_show(&mouse);
                //点击返回按钮，刷新界面
                if (mouse_press(450, 400, 650, 450) == 1) {
                    mouse_off(&mouse);
                    watcher(page); // 重新绘制界面   
                    return;
                }
            }
          }          
       }
    }





//管理员端初始生成所用端口
void handle(int *page) 
{
    //初始化定义
    char *locations[20][4] = {
        {"未按规定停车，堵塞消防通道", "车辆占用人行道", "车辆停在禁停区域", "车辆停在校园出入口"},
        {"车辆停在图书馆入口", "未按规定停车", "占用残疾人停车位", "车辆停在绿化带内"},
        {"车辆停在机械楼出入口", "未按规定停车", "车辆停在消防栓前", "车辆停在应急通道"},
        {"车辆停在管理学院入口", "未按规定停车", "占用教职工停车位", "车辆停在绿化带内"},
        {"车辆停在体育馆入口", "未按规定停车", "车辆停在应急通道", "车辆停在观众通道"},
        {"车辆停在南二门出入口", "未按规定停车", "车辆停在人行道上", "车辆停在禁停区域"},
        {"占用实验室设备装卸区", "停在学院正门台阶前", "占用新能源车充电位", "挤占教授专用停车区"},
        {"停放在试验池通道", "在学院交叉路口违停", "占用访客车位", "在消防栓前违规停车"},
        {"停放在运动场应急通道", "占用跑道周边缓冲区", "在观众席出入口停车", "挤占操场外围非机动车道"},
        {"堵塞宿舍楼消防通道", "占用垃圾清运专用车位", "在宿舍自行车棚前停车", "夜间违停于临时禁停区"},
        {"驶入园区绿地停车", "占用林间步行道", "在湖边观景平台违停", "停放在园内狭窄路段"},
        {"在会议车辆入口处停车", "停放在中心景观绿化带","堵塞交流人员进出通道","未按规定停车"}
    };
    char* location[] = {
        "华科附小", "图书馆", "机械楼", "管理学院", "体育馆", 
        "南二门", "计算机学院", "船海学院", "中操场", "东二区宿舍", 
        "青年园", "学术交流中心"
    };
    static time_t lastViolationTime = 0;
    static int violationInterval = 0;//随机事件生成时间控制器
    USERS s = {0};
    USERS temp;
    long current_pos = 0;
    int locations_coords[12][4] = 
    {
        {353, 131, 377, 155}, {185, 335, 209, 359}, {505, 293, 529, 317}, {535, 65, 559, 89},
        {490, 450, 514, 474}, {37, 500, 61, 524}, {171, 487, 195, 511}, {320, 425, 344, 449},
        {627, 465, 651, 489}, {654, 153, 678, 177}, {62, 245, 86, 269}, {115, 105, 139, 129}
    };
    int locationIdx = -1, violationIdx = 0;
    int violationHandled = 0;
    int clicked = 0;
    int i = 0;
    int record_count = 0;
    long file_size;
    FILE* fp = NULL;
    int found_count = 0;
    mouse_off(&mouse);
    //文件操作
    fp = fopen("data.dat", "rb+");
    if (fp == NULL) 
    {
        fp = fopen("data.dat", "wb+");
        if (fp == NULL) 
        {
            perror("文件创建失败");
            exit(EXIT_FAILURE);
        }
    }
    fseek(fp, 0, SEEK_END);
    record_count = ftell(fp) / sizeof(USERS);
     fseek(fp, 0, SEEK_SET); // 重置文件指针到开头
    {
        int j;
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
            if (temp.if_fine == 0||temp.if_fine==2)
             {  // 查找 if_fine == 0 和 if_fine == 2的记录
                s= temp;  // 将符合条件的记录赋值给 s
                found_count++;
                break;
            }
        }
    }
    fclose(fp);
    srand((unsigned int)time(NULL));//随机数处理
    //界面绘制
    mouse_off(&mouse);
    bar1(0, 0, 1024, 768, 0xFFFFFF);
    Readbmp64k(0, 0, "bmp\\map4.bmp");
    for (i = 0; i < 12; i++) 
    {
        bar1(locations_coords[i][0], locations_coords[i][1], 
             locations_coords[i][2], locations_coords[i][3], 0xFF068);
    }
    draw_main_toolbotton(0, 0xBD32, "历史违章", "查询");
    draw_main_toolbotton(264, 0xBD32, "实时违章", "处理");
    draw_main_toolbotton(528, 0xBD32, "扣分准则", "查看");
    bar1(830, 600, 1000, 660, 0x32CD32);
    puthz(840, 620, "返回主界面", 24, 25, 0xFFFFFF);
    //初始化时间控制器
    if (violationInterval == 0) 
    {
        violationInterval = 20 + rand() % 6; // 随机10-15秒
        lastViolationTime = time(NULL);
    }
    draw_confirmbotton(830, 710, "返回主界面"); // 返回主界面
    while (1) 
    {
        mouse_show(&mouse);
        if(mouse_press(830,710,1000,760)==1)
        {
            *page=0;  // 返回主界面
            mouse_off(&mouse);
            break;
        }
        //时间控制并且事件写入
        
        if (violationHandled == 0 && record_count < 100) 
        {
            time_t currentTime = time(NULL);
            if (difftime(currentTime, lastViolationTime) >= violationInterval) 
            {
                locationIdx = rand() % 12;
                violationIdx = rand() % 4;
                if(s.brand[0]=='\0')
                {
                    s.brand[0]='1'+rand()%5;
                    s.brand[1]='\0';
                }
                s.location = locationIdx;
                s.violation = violationIdx;
                s.if_against = 0;
                //if (plate_count > 0) {
                    //int plate_idx = rand() % plate_count;
                    //strcpy(s[record_count].carboard[0], plates[plate_idx]);
                //}
                 // 将文件指针重新定位到该记录的起始位置
                 fp= fopen("data.dat", "rb+");
                fseek(fp, current_pos, SEEK_SET);
                
                if (fwrite(&s, sizeof(USERS), 1, fp) != 1) 
                {
                    perror("写入失败");
                    fclose(fp);
                    exit(0);
                }
                fflush(fp); // 刷新文件缓冲区
                fclose(fp);
                violationHandled = 1;
                clicked = 0;
                bar1(locations_coords[locationIdx][0], locations_coords[locationIdx][1],
                     locations_coords[locationIdx][2], locations_coords[locationIdx][3], 0xFF0000);
                
                // 重置计时器
                violationInterval = 30 + rand() % 6;
                lastViolationTime = currentTime;
            }
        }
        
        //确保点击地图按钮后才能进一步操作
        if (mouse_press(locations_coords[locationIdx][0], locations_coords[locationIdx][1],
                       locations_coords[locationIdx][2], locations_coords[locationIdx][3]) == 1)
        {
            clicked = 1;
            mouse_off(&mouse);
            bar1(locations_coords[locationIdx][0], locations_coords[locationIdx][1],
                 locations_coords[locationIdx][2], locations_coords[locationIdx][3], 0x00CC33);
            bar1(800, 400, 1020, 500, 0xFFFFFF);
            puthz(810, 420, location[locationIdx], 24, 35, 0x000000);
            puthz(810, 450, locations[locationIdx][violationIdx], 24, 25, 0x000000);
            mouse_show(&mouse);
        }
        if (clicked == 1) 
        {
            if (mouse_press(264, 590, 518, 750) == 1) 
            {
                *page = 10;
                break;
            }
            if (mouse_press(840, 628, 950, 700) == 1) 
            {
                mouse_off(&mouse);
                bar1(800, 400, 1020, 500, 0xFFFFFF);
                bar1(locations_coords[locationIdx][0], locations_coords[locationIdx][1],
                     locations_coords[locationIdx][2], locations_coords[locationIdx][3], 0xFF068);
                violationHandled = 0;
                clicked = 0;
            }
        }
        //其他按钮
        if (mouse_press(0, 590, 264, 750) == 1) 
        {
            *page = 12;
            break;
        }
        if (mouse_press(518, 590, 782, 750) == 1) 
        {
            *page = 13;
            break;
        }
        if (mouse_press(830, 600, 1000, 660) == 1)
         {
            *page = 5;

            break;
        }
    }
}



//管理员端处理
void deal_window(int *page) 
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
        {"车辆停在管理学院入口", "未按规定停车", "占用教职工停车位", "车辆停在绿化带内"},
        {"车辆停在体育馆入口", "未按规定停车", "车辆停在应急通道", "车辆停在观众通道"},
        {"车辆停在南二门出入口", "未按规定停车", "车辆停在人行道上", "车辆停在禁停区域"},
        {"占用实验室设备装卸区", "停在学院正门台阶前", "占用新能源车充电位", "挤占教授专用停车区"},
        {"停放在试验池通道", "在学院交叉路口违停", "占用访客车位", "在消防栓前违规停车"},
        {"停放在运动场应急通道", "占用跑道周边缓冲区", "在观众席出入口停车", "挤占操场外围非机动车道"},
        {"堵塞宿舍楼消防通道", "占用垃圾清运专用车位", "在宿舍自行车棚前停车", "夜间违停于临时禁停区"},
        {"驶入园区绿地停车", "占用林间步行道", "在湖边观景平台违停", "停放在园内狭窄路段"},
        {"在会议车辆入口处停车", "停放在中心景观绿化带","堵塞交流人员进出通道","未按规定停车"}
    };
    USERS v = {0};
    FILE *fp = NULL;
    int record_count = 0;
    long file_size;
    int click = -1;
    int i;
    USERS temp;
    long current_pos = 0;
    int found_count = 0;
   
    //初始化文件指针和记录数
    fp = fopen("data.dat", "rb+");
    if (fp == NULL) 
    {
        fp = fopen("data.dat", "wb+");
        if (fp == NULL) 
        {
            mouse_off(&mouse);
            bar1(0, 0, 1024, 768, 0xFFFFFF);
            puthz(400, 300, "无法创建数据文件", 32, 40, 0xFF0000);
            puthz(400, 350, "按任意键返回", 32, 40, 0xFF0000);
            mouse_show(&mouse);
            while(!mouse_press(0, 0, 1024, 768));
            *page = 7;
            return;
        }
    }
    //正确获取文件大小
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    record_count = file_size / sizeof(USERS);
    fseek(fp, 0, SEEK_SET);
  
    //仅在记录数>0时分配内存
   {
        int j;
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
            if (temp.if_fine == 0||temp.if_fine==2)
             {  // 查找 if_fine == 0 或if_fine==2的记录
                v= temp;  // 将符合条件的记录赋值给 s
                found_count++;
                break;
            }
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
    if(v.if_fine==0)
    {
        // 如果找到符合条件的记录，继续处理
        // 计算当前记录的偏移量
        //初始化界面
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
            char temp[10];
            // 定位到车牌数据开始处，并读取 80 字节车牌数据（8个车牌，每个10字节）
            fseek(fp, current_pos, SEEK_SET);  // 定位到指定记录
            fseek(fp,60, SEEK_CUR);  // 跳过前60字节,输出车牌号
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
                        char temp[3];
                        temp[0] = plateBuf[offset+col];
                        temp[1] = plateBuf[offset+col+1];
                        temp[2] = '\0';
                        puthz(x, y, temp, 32, 30, 0x000000);
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
        fclose(fp);
        //puthz(300, 180, v[current_index].carboard, 32, 40, 0x000000);
        puthz(150, 230, "违停地点", 32, 40, 0x000000);
        puthz(330, 230, location[v.location], 32, 40, 0x000000);
        puthz(150, 280, "违停行为", 32, 40, 0x000000);
        puthz(330, 280, locations[v.location][v.violation], 32, 40, 0x000000);
        //行为对应照片打印
        //第一类：消防相关违规
        if  ((v.location == 0 && v.violation == 0) ||  // 堵塞消防通道
        (v.location == 2 && v.violation == 2) ||  // 消防栓前
        (v.location == 4 && v.violation == 2) ||  // 应急通道
        (v.location == 9 && v.violation == 0) ||  // 宿舍消防通道
        (v.location == 11 && v.violation == 0)){  // 宿舍消防通道
        Readbmp64k(300, 350, "bmp\\3.bmp");
        }
        // 第二类：出入口违规
        if((v.location == 0 && v.violation == 3) ||  // 校园出入口
        (v.location == 1 && v.violation == 0) ||  // 图书馆入口
        (v.location == 2 && v.violation == 0) ||  // 机械楼出入口
        (v.location == 3 && v.violation == 0) ||  // 管理学院入口
        (v.location == 4 && v.violation == 0) ||  // 体育馆入口
        (v.location == 5 && v.violation == 0)) { // 南二门出入口
        Readbmp64k(300, 350, "bmp\\5.bmp");
        } 
        
        // 第三类：特殊车位占用//(v[current_index].location == 11 && v[current_index]v.violation == 1))
        if ((v.location == 1 && v.violation == 2) ||  // 残疾人车位
        (v.location == 3 && v.violation == 2) ||  // 教职工车位
        (v.location == 6 && v.violation == 2) ||  // 新能源充电位
        (v.location == 7 && v.violation == 2) ||  // 访客车位
        (v.location == 9 && v.violation == 1) )  // 垃圾清运车位
        {// 垃圾清运车位
        Readbmp64k(300, 350, "bmp\\1.bmp");
        }
        // 第四类：绿化/人行道违规 (click=4)
        if ((v.location == 0 && v.violation == 1) ||  // 占用人行道
        (v.location == 1 && v.violation == 3) ||  // 绿化带内
        (v.location == 3 && v.violation == 3) ||  // 绿化带内
        (v.location == 5 && v.violation == 2) ||  // 人行道上
        (v.location == 10 && v.violation == 1)) {  // 景观绿化带
        Readbmp64k(300, 350, "bmp\\6.bmp");
        }
    // 第五类：特殊区域违规 (click=5)
        if((v.location == 6 && v.violation == 1) ||  // 学院台阶前
        (v.location == 7 && v.violation == 1) ||  // 交叉路口
        (v.location == 8 && v.violation == 1) ||  // 跑道缓冲区
        (v.location == 9 && v.violation == 3) ||  // 夜间违停
        (v.location == 11 && v.violation == 3)) {  // 夜间违停
        Readbmp64k(300, 350, "bmp\\2.bmp");
        }
        
        // 第六类：其他违规 (click=6)
        else{
            Readbmp64k(300, 350, "bmp\\4.bmp");
        }
        

        // 扣分选项按钮
        bar1(220, 520, 350, 560, 0xFFD700);
        puthz(230, 520, "扣二分", 32, 40, 0x000000);
        bar1(420, 520, 550, 560, 0xFFD700);
        puthz(430, 520, "扣五分", 32, 40, 0x000000);
        bar1(620, 520, 750, 560, 0xFFD700);
        puthz(630, 520, "扣十分", 32, 40, 0x000000);
        draw_botton(600, 405, 700, 455, 0xFFFFFF, 0x000000);
        puthz_coverd(590, 415, "误判认定", 2, 32, 30, 0x000000);
        // 操作按钮
        draw_botton(250, 635, 350, 695, 0xFFFFFF, 0x000000);
        puthz_coverd(230, 652, "返回上页", 4, 32, 30, 0x000000);
        draw_botton(440, 635, 560, 695, 0xFFFFFF, 0x000000);
        puthz_coverd(430, 652, "提交处理", 4, 32, 30, 0x000000);
        draw_botton(660, 635, 760, 695, 0xFFFFFF, 0x000000);
        puthz_coverd(650, 652, "规则查看", 2, 32, 30, 0x000000);
    }
    
    // 主循环
    while (1) 
    {
        mouse_show(&mouse);
        if(v.if_fine==2)
        {
            *page=14;
            break;
        }
        
        if (record_count == 0) 
        {
            bar1(400, 300, 624, 350, 0xFFFFFF);
            draw_botton(660, 635, 760, 695, 0xFFFFFF, 0x000000);
            puthz(400, 300, "无违章记录可处理", 32, 40, 0xFF0000);
        }
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
            puthz(230, 520, "扣二分", 32, 40, 0x000000);
            click=2;
        }
        if(mouse_press(420, 520, 550, 560)==1)
        {
            bar1(420, 520, 550, 560, 0x32CD32);
            puthz(430, 520, "扣五分", 32, 40, 0x000000);
            click=5;
        }
        if(mouse_press(620, 520, 750, 560)==1)
        {
            bar1(620, 520, 750, 560, 0x32CD32);
            puthz(630, 520, "扣十分", 32, 40, 0x000000);
            click=10;
        }
        
        if (mouse_press(440, 635, 560, 695) == 1 && click != -1) 
        {    
            // 更新当前记录的处罚信息
            v.if_fine = 1;
            v.fine[0] = click * 10;  // 罚款金额
            v.fine[1] = click;      // 扣分值
            if (click == 0) 
            {
                v.if_fine = 0;  // 如果选择误判认定，则清除处罚标记
            }

            // 将最新的处罚记录追加到文件末尾
            fp= fopen("data.dat", "rb+");
            if (fp== NULL) 
            {
                perror("无法打开文件进行追加写入");
                fclose(fp);
                exit(0);
            }
            strcpy(v.fine_time,"四月二十六");
            fseek(fp, current_pos, SEEK_SET);  // 定位到当前记录
            if (fwrite(&v, sizeof(USERS), 1, fp) != 1)
             {
                perror("写入失败");
                fclose(fp);
                exit(0);
            }
            //fflush(fp); // 刷新文件缓冲区
            // 跳转到历史记录页面
            showTransferAnimation1();
            *page=7;
            
           fclose(fp);
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
        if(*page==7)
        {
           
            break;
        }
        if(*page==11)
        {
            break;
        }
    }
}




void charge_deal(int *page) 
{
    //初始化定义
    char* location[] = 
    {
        "华科附小", "图书馆", "机械楼", "管理学院", "体育馆", 
        "南二门", "计算机学院", "船海学院", "中操场", "东二区宿舍", 
        "青年园", "学术交流中心"
    };
    //违停行为预存
    char *locations[20][4] = 
    {
            {"未按规定停车，堵塞消防通道", "车辆占用人行道", "车辆停在禁停区域", "车辆停在校园出入口"},
            {"车辆停在图书馆入口", "未按规定停车", "占用残疾人停车位", "车辆停在绿化带内"},
            {"车辆停在机械楼出入口", "未按规定停车", "车辆停在消防栓前", "车辆停在应急通道"},
            {"车辆停在管理学院入口", "未按规定停车", "占用教职工停车位", "车辆停在绿化带内"},
            {"车辆停在体育馆入口", "未按规定停车", "车辆停在应急通道", "车辆停在观众通道"},
            {"车辆停在南二门出入口", "未按规定停车", "车辆停在人行道上", "车辆停在禁停区域"},
            {"占用实验室设备装卸区", "停在学院正门台阶前", "占用新能源车充电位", "挤占教授专用停车区"},
            {"停放在试验池通道", "在学院交叉路口违停", "占用访客车位", "在消防栓前违规停车"},
            {"停放在运动场应急通道", "占用跑道周边缓冲区", "在观众席出入口停车", "挤占操场外围非机动车道"},
            {"堵塞宿舍楼消防通道", "占用垃圾清运专用车位", "在宿舍自行车棚前停车", "夜间违停于临时禁停区"},
            {"驶入园区绿地停车", "占用林间步行道", "在湖边观景平台违停", "停放在园内狭窄路段"},
            {"在会议车辆入口处停车", "停放在中心景观绿化带","堵塞交流人员进出通道","未按规定停车"}
        };
    //申诉理由预存
    char *charges[6]=
    {
            "车辆正常停放但被误罚",
            "车辆违停类型发生误判",
            "其他原因，等待管理员复核",
            "车辆正常停放但被误罚",
            "车辆违停类型发生误判",
            "其他原因，等待管理员复核",
        };
    FILE *fp = NULL;
    int deside=-1;
    USERS records = {0};
    int record_count = 0;
    int i;
    int j;
    int y_offset = 330; // 初始Y坐标
    long current_pos = 0;
    int found_count = 0;
    USERS temp;
    int is_query1=0;
    int is_query2=0;
    //文件操作以及记录数量读取
    fp = fopen("data.dat", "rb+");
    if (fp == NULL) 
    {
        perror("文件打开失败");
        return;
    }
    fseek(fp, 0, SEEK_END);
    record_count = ftell(fp) / sizeof(USERS);
    fseek(fp, 0, SEEK_SET); // 将文件指针重新定位到开头
    //读取记录
    {
        int j;
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
            if (temp.if_against == 1)
             {  // 查找 if_against == 1 的记录
                records = temp;  // 将符合条件的记录赋值给 s
                found_count++;
                break;
            }
        }
    }
    fclose(fp);
    if (found_count == 0) 
    {
        bar1(400, 300, 624, 350, 0xFFFFFF);
        puthz(400, 300, "无处罚反馈可处理", 32, 40, 0xFF0000);
        fclose(fp);
        *page=5;
       
        return;
        
    }

    else
    {
        
        mouse_off(&mouse);
        bar1(0, 0, 1024, 768, 0xFFFFFF);
        Readbmp64k(0, 0, "bmp\\user1.bmp");
        rounded_bar(50, 120, 974, 600, 10, 0xBDBD, 0xFFFFFF, 0);
        bar1(60, 130, 964, 580, 0xFFFFFF);
        puthz(400, 50, "申诉处理", 48, 50, 0x000000);
        puthz(150, 180, "申诉车牌", 32, 40, 0x000000);
    // printPlates(330, 180, records[count].carboard); 
        //puthz(300, 180, records[count].plate, 32, 40, 0x000000);
        prt_hz16_asc16_size(330, 180, 3, 3, records.carboard, 0x000000,"HZK\\hzk16");
        puthz(150, 230, "记录地点", 32, 40, 0x000000);
        puthz(330, 230, location[records.location], 32, 40, 0x000000);
        puthz(150, 280, "记录行为", 32, 40, 0x000000);
        puthz(330, 280, locations[records.location][records.violation], 32, 40, 0x000000);
        puthz(150, 330, "申诉理由", 32, 40, 0x000000);
        for (j = 2; j < 8; j++) 
        {
            if (records.fine[j] == 1) 
            {
                puthz(300, y_offset, charges[j-2], 32, 30, 0x000000);
                y_offset += 50; // 每个理由下移50像素
            }
        }
    }
    draw_botton(250, 635, 350, 695, 0xFFFFFF, 0x000000);
    puthz_coverd(225, 652, "提交处理", 4, 32, 30, 0x000000);
    draw_botton(660, 635, 760, 695, 0xFFFFFF, 0x000000);
    puthz_coverd(639, 652, "返回主界面", 2, 32, 30, 0x000000);
    draw_botton(150, 550, 350, 610, 0xFFFFFF, 0xFF0000);
    puthz_coverd(180, 567, "撤销处罚", 4, 32, 30, 0x000000);
    draw_botton(650, 550, 850, 610, 0xFFFFFF, 0x00FF00);
    puthz_coverd(680, 567, "维持判定", 4, 32, 30, 0x000000);
    while (1) 
    {
        mouse_show(&mouse);
        if(mouse_press(150,550,350,610)==1)
        {
            if(is_query1==0)
            {
                deside=1;
                mouse_off(&mouse);
                delay(200);
                puthz_coverd(180, 567, "撤销处罚", 4, 32, 30,0xFF068);
                is_query1=1;
            }
            else
            {
                deside=-1;
                mouse_off(&mouse);
                delay(200);
                puthz_coverd(180, 567, "撤销处罚", 4, 32, 30,0xFF068);
                is_query1=0;
            }
        }//撤销
        if(mouse_press(650,550,850,610)==1)
        {
            if(is_query2==0)
            {
                deside=0;
                mouse_off(&mouse);
                delay(200);
                draw_botton(650, 550, 850, 610, 0xFF068, 0xFF33CC);
                puthz_coverd(680, 567, "维持判定", 4, 32, 30, 0x000000);
                mouse_show(&mouse);
            }
            else
            {
                deside=-1;
                mouse_off(&mouse);
                delay(200);
                draw_botton(650, 550, 850, 610, 0xFFFFFF, 0x00FF00);
                puthz_coverd(680, 567, "维持判定", 4, 32, 30, 0x000000);
                mouse_show(&mouse); 
                is_query2=0;
            }
        }//维持原判
        if(mouse_press(250, 635, 350, 695)==1&&deside!=-1)
        {
            if (deside==1)
            {
                records.if_fine = 0;
                records.if_against = 0;
                //写回文件
                fp= fopen("data.dat", "rb+");
                fseek(fp, current_pos, SEEK_SET);
                if (fwrite(&records, sizeof(USERS), 1, fp) != 1) 
                {
                    perror("写入失败");
                }
                puthz_coverd(430, 700, "已撤销", 2, 32, 30, 0xFF0000);
                delay(1000);
                
                *page=5;
                fclose(fp);
                break;
            }
            if (deside==0)
            {
                records.if_against = 0;
                //写回文件
                fp= fopen("data.dat", "rb+");
                fseek(fp, current_pos, SEEK_SET);
                if (fwrite(&records, sizeof(USERS), 1, fp) != 1) 
                {
                    perror("写入失败");
                }
                puthz_coverd(430, 700, "维持原判", 2, 32, 30, 0x00FF00);
                delay(1000);
                *page=5;
                fclose(fp);
                break;
            }  
        }
        if (mouse_press(660, 635, 760, 695) == 1) 
        {  // 返回主界面按钮
            *page = 7;
            break;
        }
    }
}

void rules(int *page) 
{
    mouse_off(&mouse);
    Readbmp64k(0, 0, "bmp\\user1.bmp");
    puthz(350,50,"华中科技大学",48,50,0x9932CC);
    puthz(270,120,"机动车违停处罚条例",48,50,0x000000);
    rounded_bar(50, 200, 974, 750, 10, 0xBDBD, 0xFFFFFF, 0);
    bar1(60, 210, 964, 660, 0xFFFFFF);
    puthz(65, 220, "（一）轻微违规", 32, 30, 0x000000);
    puthz(110, 270, "在非指定临时停车区域短暂停车（五分钟内），未影响交通秩序和他人通行。", 24, 25, 0x000000);
    puthz(80, 300, "停车时车身部分超出停车位边界，但未妨碍其他车辆和行人正常通行，每次扣二", 24, 25, 0x000000);
    puthz(80, 330, "分，罚款二十元", 24, 25, 0x000000);
    puthz(65, 370, "（二）一般违规", 32, 30, 0x000000);
    puthz(110, 420, "在禁止停车标志、标线处停车，但未造成交通拥堵。用消防通道、应急通道停", 24, 25, 0x000000);
    puthz(80, 450, "车，但未引发紧急情况。每次扣五分，罚款三十元", 24, 25, 0x000000);
    puthz(65, 490, "（三）严重违规", 32, 30, 0x000000);
    puthz(110, 530, "在消防通道、应急通道长时间停车，导致紧急救援车辆无法通行。因违停造成", 24, 25, 0x000000);
    puthz(80, 570, "校园内交通严重拥堵，影响范围较大且持续时间较长（超过三十分钟）。违法者", 24, 25, 0x000000);
    puthz(80, 600, "每次扣十分，罚款五十元", 24, 25, 0x000000);
    // 绘制返回按钮（白色背景 + 居中底部）
    draw_botton(300,660,450,730,0xFFFFFF,0x000000);
    puthz_coverd(293,670,"返回上一页",5 ,32,30,0x000000);
    draw_botton(580,660,730,730,0xFFFFFF,0x000000);
    puthz_coverd(593,670,"返回主界面",2 ,32,30,0x000000);
    // 处理鼠标点击事件
    while (1) {
        mouse_show(&mouse);
        if (mouse_press(300,660,450,730) == 1) 
        {
            *page = 10;  // 返回违章处理界面
            break;
        }
        if (mouse_press(580,660,730,730) == 1) 
        {
            *page = 7;  // 返回管理员界面
            break;
        }
    }
}

void history(int *page) 
{
    char* location[] = 
    {
        "华科附小", "图书馆", "机械楼", "管理学院", "体育馆", 
        "南二门", "计算机学院", "船海学院", "中操场", "东二区宿舍", 
        "青年园", "学术交流中心"
    };
    //违停行为预存
    char *locations[20][4] = 
    {
            {"未按规定停车，堵塞消防通道", "车辆占用人行道", "车辆停在禁停区域", "车辆停在校园出入口"},
            {"车辆停在图书馆入口", "未按规定停车", "占用残疾人停车位", "车辆停在绿化带内"},
            {"车辆停在机械楼出入口", "未按规定停车", "车辆停在消防栓前", "车辆停在应急通道"},
            {"车辆停在管理学院入口", "未按规定停车", "占用教职工停车位", "车辆停在绿化带内"},
            {"车辆停在体育馆入口", "未按规定停车", "车辆停在应急通道", "车辆停在观众通道"},
            {"车辆停在南二门出入口", "未按规定停车", "车辆停在人行道上", "车辆停在禁停区域"},
            {"占用实验室设备装卸区", "停在学院正门台阶前", "占用新能源车充电位", "挤占教授专用停车区"},
            {"停放在试验池通道", "在学院交叉路口违停", "占用访客车位", "在消防栓前违规停车"},
            {"停放在运动场应急通道", "占用跑道周边缓冲区", "在观众席出入口停车", "挤占操场外围非机动车道"},
            {"堵塞宿舍楼消防通道", "占用垃圾清运专用车位", "在宿舍自行车棚前停车", "夜间违停于临时禁停区"},
            {"驶入园区绿地停车", "占用林间步行道", "在湖边观景平台违停", "停放在园内狭窄路段"},
            {"在会议车辆入口处停车", "停放在中心景观绿化带","堵塞交流人员进出通道","未按规定停车"}
        };
    FILE *fp = NULL;
    USERS records[20];
    int total = 0;
    int current_index = 0;
    int need_refresh = 1;
    // 读取所有记录
    fp = fopen("data.dat", "rb");
    if (fp) {
        while (total < 100 && fread(&records[total], sizeof(USERS), 1, fp) == 1) {
            total++;
        }
        fclose(fp);
    }
    // 初始化界面
    mouse_off(&mouse);
    bar1(0, 0, 1024, 768, 0xFFFFFF);
    mouse_off(&mouse);
    Readbmp64k(0, 0, "bmp\\user1.bmp");
    rounded_bar(100, 150, 924, 600, 20, 0xFFFFFF, 0x000000, 0);
    // 绘制操作按钮
    puthz(50, 50, "历史违章页", 48, 50, 0x000000);
    rounded_bar(100, 150, 924, 600, 20, 0xFFFFFF, 0x000000, 0);
    draw_botton(250,620,350,680,0xFFFFFF,0x000000);
    puthz_coverd(240,635,"下一页",4,32,30,0x000000);
    draw_botton(440,620,560,680,0xFFFFFF,0x000000);
    puthz_coverd(440,635,"返回上页",4,32,30,0x000000);
    draw_botton(660,620,790,680,0xFFFFFF,0x000000);
    puthz_coverd(640,635,"返回主界面",2,32,30,0x000000);

    // 查找第一个符合条件的记录
    while (current_index < total && records[current_index].if_fine != 1) {
        current_index++;
    }

    // 主循环
    while (1) {
        mouse_show(&mouse);
        if (need_refresh) {
            mouse_off(&mouse);
                rounded_bar(100, 150, 924, 600, 20, 0xFFFFFF, 0x000000, 0);
            if (current_index >= total) {
                puthz(330, 300, "已是最后一个记录", 32, 40, 0x000000);
                delay(500);
                *page=7;
                break;
            } else
             {
                puthz(150, 180, "车牌号码", 32, 40, 0x000000);
                prt_hz16_asc16_size(330, 180, 2, 2, records[current_index].carboard, 0x000000,"HZK\\hzk16");
                puthz(150, 230, "违章地点", 32, 40, 0x000000);
                puthz(330, 230, location[records[current_index].location], 32, 40, 0x000000);
                puthz(150, 280, "违章类型", 32, 40, 0x000000);
                puthz(330, 280, locations[records[current_index].location][records[current_index].violation], 32, 40, 0x000000);
                puthz(150, 330, "处罚扣分", 32, 40, 0x000000);
                put_asc16_number_size_coverd(330, 330, 2, 2, 1, records[current_index].fine[1], 0x000000);
                puthz(500, 330, "处罚金额", 32, 40, 0x000000);
                put_asc16_number_size_coverd(650, 330, 2, 2, 1, records[current_index].fine[0], 0x000000);
                draw_botton(600, 405, 700, 455, 0xFFFFFF, 0x000000);
                puthz_coverd(590, 415, "已判定", 2, 32, 30, 0x000000);
                if  ((records[current_index].location == 0 && records[current_index].violation == 0) ||  // 堵塞消防通道
				                (records[current_index].location == 2 && records[current_index].violation == 2) ||  // 消防栓前
				                (records[current_index].location == 4 && records[current_index].violation == 2) ||  // 应急通道
				                (records[current_index].location == 9 && records[current_index].violation == 0) ||  // 宿舍消防通道
				                (records[current_index].location == 11 && records[current_index].violation == 0)){  // 宿舍消防通道
				                Readbmp64k(300, 400, "bmp\\3.bmp");
				                }
				                // 第二类：出入口违规
				                if((records[current_index].location == 0 && records[current_index].violation == 3) ||  // 校园出入口
				                (records[current_index].location == 1 && records[current_index].violation == 0) ||  // 图书馆入口
				                (records[current_index].location == 2 && records[current_index].violation == 0) ||  // 机械楼出入口
				                (records[current_index].location == 3 && records[current_index].violation == 0) ||  // 管理学院入口
				                (records[current_index].location == 4 && records[current_index].violation == 0) ||  // 体育馆入口
				                (records[current_index].location == 5 && records[current_index].violation == 0)) { // 南二门出入口
				            
				                Readbmp64k(300, 400, "bmp\\5.bmp");
				                } 
				                // 第三类：特殊车位占用
				                if ((records[current_index].location == 1 && records[current_index].violation == 2) ||  // 残疾人车位
				                (records[current_index].location == 3 && records[current_index].violation == 2) ||  // 教职工车位
				                (records[current_index].location == 6 && records[current_index].violation == 2) ||  // 新能源充电位
				                (records[current_index].location == 7 && records[current_index].violation == 2) ||  // 访客车位
				                (records[current_index].location == 9 && records[current_index].violation == 1) )  // 垃圾清运车位
				                {
				                Readbmp64k(300, 400, "bmp\\1.bmp");
				                }
				                // 第四类：绿化/人行道违规
				                if ((records[current_index].location == 0 && records[current_index].violation == 1) ||  // 占用人行道
				                (records[current_index].location == 1 && records[current_index].violation == 3) ||  // 绿化带内
				                (records[current_index].location == 3 && records[current_index].violation == 3) ||  // 绿化带内
				                (records[current_index].location == 5 && records[current_index].violation == 2) ||  // 人行道上
				                (records[current_index].location == 10 && records[current_index].violation == 1)) {  // 景观绿化带
				                Readbmp64k(300, 400, "bmp\\6.bmp");
				                }
				                // 第五类：特殊区域违规
				                if((records[current_index].location == 6 && records[current_index].violation == 1) ||  // 学院台阶前
				                (records[current_index].location == 7 && records[current_index].violation == 1) ||  // 交叉路口
				                (records[current_index].location == 8 && records[current_index].violation == 1) ||  // 跑道缓冲区
				                (records[current_index].location == 9 && records[current_index].violation == 3) ||  // 夜间违停
				                (records[current_index].location == 11 && records[current_index].violation == 3)) {  // 夜间违停
				                Readbmp64k(300, 400, "bmp\\2.bmp");
				                }
				                // 第六类：其他违规
				                else{
				                    Readbmp64k(300, 400, "bmp\\4.bmp");
				                }
				            }
				            
				            mouse_show(&mouse);
				            need_refresh = 0;
				        }
				
				        if (mouse_press(250,620,350,680) == 1) 
                        {
				            current_index++;
				            while (current_index < total && records[current_index].if_fine != 1) 
                            {
				                current_index++;
				            }
				            need_refresh = 1;
				            while(mouse_press(250,620,350,680) == 1);
				        }
				        
				        if (mouse_press(440,620,560,680) == 1) 
                        {
				            *page = 7;
				            break;
				        }
				        
				        if (mouse_press(660,620,790,680) == 1) 
                        {
				            *page = 5;
				            break;
				        }
				        
				        if (mouse_press(830,600,1000,660) == 1) 
                        {
				            *page = 5;
				            break;
				        }
				
				    }
				}
    
void rules1(int *page)
{
     mouse_off(&mouse);
     Readbmp64k(0, 0, "bmp\\user1.bmp");
     puthz(350,50,"华中科技大学",48,50,0x9932CC);
     puthz(270,120,"机动车违停处罚条例",48,50,0x000000);
     rounded_bar(50, 200, 974, 750, 10, 0xBDBD, 0xFFFFFF, 0);
     bar1(60, 210, 964, 660, 0xFFFFFF);
     puthz(65, 220, "（一）轻微违规", 32, 30, 0x000000);
     puthz(110, 270, "在非指定临时停车区域短暂停车（五分钟内），未影响交通秩序和他人通行。", 24, 25, 0x000000);
     puthz(80, 300, "停车时车身部分超出停车位边界，但未妨碍其他车辆和行人正常通行，每次扣二", 24, 25, 0x000000);
     puthz(80, 330, "分，罚款二十元", 24, 25, 0x000000);
     puthz(65, 370, "（二）一般违规", 32, 30, 0x000000);
     puthz(110, 420, "在禁止停车标志、标线处停车，但未造成交通拥堵。用消防通道、应急通道停", 24, 25, 0x000000);
     puthz(80, 450, "车，但未引发紧急情况。每次扣五分，罚款三十元", 24, 25, 0x000000);
     puthz(65, 490, "（三）严重违规", 32, 30, 0x000000);
     puthz(110, 530, "在消防通道、应急通道长时间停车，导致紧急救援车辆无法通行。因违停造成", 24, 25, 0x000000);
     puthz(80, 570, "校园内交通严重拥堵，影响范围较大且持续时间较长（超过三十分钟）。违法者", 24, 25, 0x000000);
     puthz(80, 600, "每次扣十分，罚款五十元", 24, 25, 0x000000);
     // 绘制返回按钮（白色背景 + 居中底部）
     draw_botton(300,660,450,730,0xFFFFFF,0x000000);
     puthz_coverd(293,670,"返回上一页",5 ,32,30,0x000000);
     draw_botton(580,660,730,730,0xFFFFFF,0x000000);
     puthz_coverd(593,670,"返回主界面",2 ,32,30,0x000000);
     // 处理鼠标点击事件
     while (1) {
         mouse_show(&mouse);
         if (mouse_press(300,660,450,730) == 1)
          {
             *page = 7;  // 返回上一页
             break;
         }
         if (mouse_press(580,660,730,730) == 1)
          {
             *page = 7;  // 返回管理员界面
 
             break;
         }
     }
 }