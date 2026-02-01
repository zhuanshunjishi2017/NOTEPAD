#include"allfunc.h"


void user_function(int *page)
{
    int save_picture16; // 保存原界面
    int is_query_open = 0; // 标志变量，记录是否处于查询界面
    int is_query_open1 = 0;
    int pre1 = 0;//给处罚申诉设置悬停效果
    //int i;
    //char*carboard1[8];
    FILE*fp;
    char username[10];
    long current_pos = 0;
    USERS temp ;
    data_reselect();
    //读取临时文件中的数据

    if((fp=fopen("data1.dat","rb+"))==NULL)
    {
        printf("error!\n");
        exit(0);
    }
    Readbmp64k(0, 0, "bmp\\user1.bmp");
    bar1(30, 120, 500, 710, 0xd4a6f8); // (0,0)到(1024,768)的白色背景 
    puthz(35, 50, "用户", 32, 30, 0x000000); // 用户名
     fseek(fp,0,SEEK_SET);
        fread(username,sizeof(username)-1,1,fp);
        username[sizeof(username)-1]='\0';
        if(username[0] == '\0')
        {
            put_asc16_size(120,50,2,2,"error",0x000000);
        }    
        else
        {
            put_asc16_size(120, 50, 2, 2, username, 0x000000); // 后续将用户名导入
        }
    
    find_and_print_carplate(username);
    puthz(250, 50, "您好", 32, 30, 0x000000); // 问候语
    puthz(35, 150, "车辆信息", 48, 45, 0x000000);
    puthz(35, 250, "车牌号", 32, 30, 0x000000);
    puthz(35, 350, "车辆类型", 32, 30, 0x000000);

    bar1(500, 120, 740, 390, 0x00CC33); // (0,0)到(1024,768)的白色背景
    puthz(500, 150, "用户查询区", 48, 45, 0x000000);

    draw_botton(540, 240, 700, 300, 0xFFFFFF, 0x000000);
    puthz_coverd(530, 255, "查询违章情况", 6, 32, 30, 0x000000);//点击一次弹出界面，再次点击返回原界面
    draw_botton(540, 310, 700, 370, 0xFFFFFF, 0x000000);
    puthz_coverd(530, 325, "查看违章照片", 6, 32, 30, 0x000000);//点击一次弹出界面，再次点击返回原界面  

    bar1(500, 390, 740, 670, 9159e4); // (0,0)到(1024,768)的白色背景
    puthz(500, 410, "用户处理区", 48, 45, 0x000000);
    
    draw_botton(540, 510, 700, 570, 0xFFFFFF, 0x000000);
    puthz_coverd(530, 525, "安全知识学习", 6, 32, 30, 0x000000);
    draw_botton(540, 590, 700, 650, 0xFFFFFF, 0x000000);
    puthz_coverd(560, 605, "违章处理", 4, 32, 30, 0x000000);

    puthz(770, 250, "如对处罚结果有疑问",24, 25, 0x000000);
    puthz(740, 283, "请点击下方按钮进行申诉",24, 25, 0x000000);//提示词

    draw_botton(800, 370, 960, 430, 0xFFFFFF, 0x000000);
    puthz_coverd(820, 385, "处罚申诉", 4, 32, 30, 0x000000);//出发申诉按钮，有悬停效果

    puthz(755, 490, "如需了解更多安全知识",24, 25, 0x000000);
    puthz(740, 523, "请点击左侧按钮进行学习",24, 25, 0x000000);//提示词
    
       
        memset(&temp, 0, sizeof(USERS)); // 清空 temp 结构体
        // 读取违章记录
        fseek(fp, 0, SEEK_SET); // 定位到文件开始
        while (fread(&temp, sizeof(USERS), 1, fp) == 1)
        {
            if (strcmp(temp.user_name, username) == 0)
            {
                current_pos = ftell(fp) - sizeof(USERS); // 获取当前记录的偏移量
                                
            }
        }
        fseek(fp, current_pos, SEEK_SET); // 定位到当前记录的位置
        fread(&temp, sizeof(USERS), 1, fp); // 读取当前记录
        fclose(fp);     
        put_car_picture(temp);
        
    draw_confirmbotton(830, 650, "查看历史违章"); // 返回上一级
    draw_confirmbotton(830, 710, "返回主界面"); // 返回主界面

    while (1)
    {
        int hover_visitor = (mouse.x >= 800 && mouse.x <= 960 && mouse.y >= 370 && mouse.y <= 415);
        mouse_show(&mouse);
        
        if(hover_visitor != pre1)//处罚申诉按钮的悬停效果
        {
           mouse_off(&mouse); // 关闭鼠标
            // 恢复背景
            bar1(800, 370, 960, 430, 0xFFFFFF);
            draw_botton(800, 370, 960, 430, hover_visitor ? 0xDDDDDD : 0xFFFFFF, 0x000000);
            puthz_coverd(820, 385, "处罚申诉", 4, 32, 30, hover_visitor ? 0xFF0000 : 0x000000);
            pre1 = hover_visitor;
            mouse_on(mouse);
        }
        if (mouse_press(540, 240, 700, 300) == 1)
        {
            if (!is_query_open)
            {
               
                is_query_open=watch_func1(temp);
                
            }
            else
            {
                
                is_query_open = 0; // 标记为查询界面已关闭
                break;
            }
        }
        if(mouse_press(540, 310, 700, 370)==1)
        {
            if(!is_query_open1)
            {
                
                is_query_open1=watch_func2(temp);
                    
            }
            else
            {
                is_query_open1 = 0; // 标记为查询界面已关闭
                break;
            }

            
            
            
        }
        
        if(mouse_press(830, 650, 950, 710)==1)
        {
            if(temp.if_fine==1||temp.if_fine==2)
            {
                *page=15;
                break;
            }
            else if(temp.if_fine==0)
            {
                puthz(765, 580, "您没有违章记录", 32, 30, 0xFF068);
                delay(500);
                LoadBMP(765, 580, 1000, 630, save_picture16);
            }
        }
        if(mouse_press(830, 710, 950, 770)==1)
        {
            data_reselect();
            *page=0;
            break;
        }
       if (mouse_press(800, 370, 960, 430) == 1)
        {
            int if_fine = -1;
            fp= fopen("data1.dat", "rb+");
            // 保存原界面
            save_picture16=SaveBMP(765, 580, 1000, 630);
            // 定位到 if_fine 的位置
            if (fseek(fp, 36+current_pos, SEEK_SET) != 0)
            {
                printf("文件指针定位失败！\n");
                return;
            }

            // 读取 if_fine 的值
            if (fread(&if_fine, sizeof(int), 1, fp) != 1)
            {
                printf("读取 if_fine 失败！\n");
                return;
            }
           

            // 根据 if_fine 的值决定是否跳转页面
            if (if_fine == 1)
            {
                *page = 27;  // 跳转到页面 27
                break;
            }
            else
            {
                // 清除提示区域背景
               
                puthz(765, 580, "您没有违章记录", 32, 30, 0xFF068);
                delay(500);
                LoadBMP(765, 580, 1000, 630, save_picture16);

            }
        }
        if(mouse_press(540, 510, 700, 570)==1)
        {
            *page=28;
            break;
        }
        if(mouse_press(540, 590, 700, 650)==1)
        {
            int if_fine = -1;
            int if_against=-1;
            int save_picture17;
            save_picture16=SaveBMP(765, 580, 1000, 630);
            save_picture17=SaveBMP(765, 580, 1000, 630);
            fp= fopen("data1.dat", "rb+");
            // 定位到 if_fine 的位置
            if (fseek(fp, 36+current_pos, SEEK_SET) != 0)
            {
                printf("文件指针定位失败！\n");
                return 0;
            }

            // 读取 if_fine 的值
            if (fread(&if_fine, sizeof(int), 1, fp) != 1)
            {
                printf("读取 if_fine 失败！\n");
                return 0;
            }
             if(fread(&if_against, sizeof(int), 1, fp) != 1)
            {
                printf("读取 if_against 失败！\n");
                return;
            }

            // 根据 if_fine 的值决定是否跳转页面
            if (if_fine == 1&&if_against==0)
            {
                
                *page = 29;  // 跳转到页面 27
                fclose(fp);
                break;
            }
            else if(if_fine==1&&if_against==1)
            {
                puthz(765, 580, "您已申请申诉", 32, 30, 0xFF068);

                delay(500);
                LoadBMP(765, 580, 1000, 630, save_picture16);// 清除提示区域背景
            }
            else
            {
                puthz(765, 580, "您没有违章记录", 32, 30, 0xFF068);
                delay(500);
                LoadBMP(765, 580, 1000, 630, save_picture16);// 清除提示区域背景
            }
        }
    }
}

void safe_learning(int *page)
{
    
    int is_query_open = 0; 
    // 标志变量，记录是否处于查询界面
    int save_picture16; // 保存原界面
    int save_picture17;

    Readbmp64k(0, 0, "bmp\\user1.bmp");   
    
    puthz(350, 50, "安全知识学习", 48, 50, 0x000000);
    puthz(250, 150, "华中科技大学机动车管理条例", 32, 40, 0x000000);
   
    rounded_bar(50, 200, 974, 750, 10, 0xBDBD, 0xFFFFFF, 0);
    bar1(60, 210, 964, 660, 0xFFFFFF);

    draw_confirmbotton(250, 680, "返回上一级"); // 返回上一级
    draw_confirmbotton(610, 680, "返回主界面"); // 返回主界面
    
    puthz(80, 250,"第一条",32,30,0x000000);
    puthz(110, 300,"校园主干道两侧、教学核心区、楼宇出入口、车辆和人员密集区通道等区域严",24,25,0x000000);
    puthz(75, 330,"禁停放机动车，已施划停车位的除外。车辆在停车位停放应遵守规范，停车入位，",24,25,0x000000);
    puthz(75, 360,"不得跨压停车线。",24,25,0x000000);
    puthz(80, 400,"第二条",32,30,0x000000);
    puthz(110, 440,"校园内机动车辆行驶应遵守交通规则，不得超速行驶，不得逆行，不得占用人",24,25,0x000000);
    puthz(75, 470,"行道行驶，不得在校园内鸣喇叭。",24,25,0x000000);
    puthz(80, 510,"第三条",32,30,0x000000);
    puthz(110, 550,"在校园内停放机动车，应依照物价部门核定的收费标准缴纳停放费用。",24,25,0x000000);

    bar2(258,626,288,656,0x000000);
    puthz(300,630,"我已知晓并同意以上条例且愿意遵循以上条例",24,25,0x000000);

    /*prt_hz24_asc32(25, 150,"校园主干道两侧、教学核心区、楼宇出入口、车辆和人员密集区通道等区域严禁停放机动车,已施划停车位的除外。车辆在停车位停放应遵守规范,停车入位,不得跨压停车线。", 0x000000, "HZK\\HZK24s");
    prt_hz24_asc32(25, 250,"校园内机动车辆行驶应遵守交通规则,不得超速行驶,不得逆行,不得占用人行道行驶,不得在校园内鸣喇叭。", 0x000000, "HZK\\HZK24s");
    prt_hz24_asc32(25, 350,"在校园内停放机动车,应依照物价部门核定的收费标准缴纳停放费用。", 0x000000, "HZK\\HZK24s");
    */
    
    while (1)
    {
        mouse_show(&mouse);
        
        if (mouse_press(250, 680, 370, 740) == 1)
        {
            if(is_query_open!=1)
            {
                mouse_off(&mouse);
                save_picture17 = SaveBMP(258, 586, 800, 650);//保存原界面,长为290，宽为220
                //Readbmp64k(450, 350, "bmp\\warning.bmp");效果不好，改为下面的
                puthz(300, 600, "请用户确认同意校园车辆安全管理条例", 24, 25, 0xFF068);
                delay(1000);
                LoadBMP(258, 586, 800, 650, save_picture17);
            }
            else
            {
                *page = 26;
                break;
            }
        }
        if (mouse_press(610, 680, 730, 740) == 1)
        {
            *page = 20;
            break;
        }
        if(mouse_press(258,626,288,656)==1)
        {
            if (!is_query_open)
            {
               mouse_off(&mouse);
               save_picture16 = SaveBMP(258, 626, 288, 656);
               delay(200);
               DrawCheckmark(272,645,30,0xFF068);
               is_query_open = 1;
            
            }
            else
            {
                delay(200);
                mouse_off(&mouse);
                LoadBMP(258, 626, 288, 656, save_picture16);
                is_query_open = 0;
            }
            
        }
    }
}
void fun_against(int *page)
{
    int save_picture18; // 保存原界面
    int save_picture19;
    int save_picture20;
    int save_picture21;
    int save_picture22;
    int save_picture23;
    int save_picture24;
    int is_query_open = 0; // 标志变量，记录是否处于查询界面
    int is_query_open1 = 0;
    int false_query_open1 = 0;
    int false_query_open2 = 0;
    int false_query_open3 = 0;
    int textbox_open = 0;
    FILE*fp;
    int if_fine;
    long current_pos;
    
    if((fp=fopen("data1.dat","rb+"))==NULL)
    {
        printf("error!\n");
        exit(0);
    }
    fseek(fp, 0, SEEK_END);
    current_pos = ftell(fp)-(long)sizeof(USERS);
    mouse_off(&mouse);
    Readbmp64k(0, 0, "bmp\\user1.bmp");
    mouse_show(&mouse);
    fseek(fp, 24+current_pos, SEEK_SET);
    //申诉功能区
    fclose(fp);
    puthz(400, 50, "处罚申诉", 48, 50, 0x000000);
    puthz(50, 150, "请选择您的申诉内容", 32, 35, 0x000000);
    rounded_bar(50, 200, 974, 750, 10, 0xBDBD, 0xFFFFFF, 0);
    bar1(60, 210, 964, 660, 0xFFFFFF);
    
    bar2(150, 270, 190, 310, 0x000000);//选择栏
    puthz(220, 265, "错误判罚", 48, 50, 0x000000);
    bar2(600, 270, 640, 310, 0x000000);
    puthz(670, 265, "处罚过重", 48, 50, 0x000000);
    puthz(80, 350, "请填写您的申诉理由", 32, 35, 0x000000);
    rounded_bar(140, 400, 904, 600, 10, 0xFFFFFF, 0xFFFFFF, 0);
    save_picture20 = SaveBMP(140, 400, 904, 600);

    draw_confirmbotton(150, 680, "返回上一级"); // 返回上一级
    draw_confirmbotton(420, 680, "提交申诉"); // 提交申诉
    draw_confirmbotton(720, 680, "返回主界面"); // 返回主界面
    //要加上反馈输入等功能
    save_picture18 = SaveBMP(150, 270, 190, 310);
    save_picture19 = SaveBMP(600, 270, 640, 310);
    while (1)
    {
        mouse_show(&mouse);
        if(mouse_press(150, 680, 270, 740)==1)
        {
            *page=26;
            break;
        }
        if(mouse_press(420, 680, 540, 740)==1)
        {
            if_fine=1;
            fp=fopen("data1.dat","rb+");
            puthz(450, 620, "申诉成功", 24, 30, 0xFF068);
            fseek(fp, 38+current_pos, SEEK_SET);
            fwrite(&if_fine, 2, 1, fp);
            fseek(fp, 0, SEEK_SET);
            data_reselect();
            fclose(fp);
            delay(500);
            *page=26;
            break;
        }
        if(mouse_press(720, 680, 840, 740)==1)
        {
            *page=0;
            break;
        }
        if (mouse_press(150, 270, 190, 310) == 1)
        {
           
            if (!is_query_open)
            {
                mouse_off(&mouse);
                // 保存原界面
                LoadBMP(600, 270, 640, 310, save_picture19);
                delay(200);
                DrawCheckmark(169,294,40,0xFF068);
                textbox_open=1;//错误判罚
                is_query_open = 1; // 标记为查询界面已打开
                is_query_open1=0;//点击错误判罚时，处罚过重的状态关闭
            }
            else
            {
                // 返回原界面
                delay(200);
                mouse_off(&mouse);
                // 返回原界面
                LoadBMP(140, 400, 904, 600, save_picture20);
                LoadBMP(150, 270, 190, 310, save_picture18);
                LoadBMP(600, 270, 640, 310, save_picture19);
                is_query_open = 0; // 标记为查询界面已关闭
                textbox_open=0;
            }
            if(is_query_open1==0&&is_query_open==1)
            {
                LoadBMP(140, 400, 904, 600, save_picture20);
                //此时是点击错误处罚的状态，下面写出错误处罚的反应代码
                bar2(160, 430, 190, 460, 0x000000);
                puthz(220, 425,"车辆正常停放但被误罚", 32, 35, 0x000000);
                bar2(160, 480, 190, 510, 0x000000);
                puthz(220, 479,"车辆违停类型发生误判", 32, 35, 0x000000);
                bar2(160, 540, 190, 570, 0x000000);
                puthz(220, 543,"其他原因，等待管理员复核", 32, 35, 0x000000);
                
            }
        }
        if (mouse_press(600, 270, 640, 310) == 1)
        {
           
            if (!is_query_open1)
            {
                mouse_off(&mouse);
                // 保存原界面
                
                delay(200);
                DrawCheckmark(619,294,40,0xFF068);
                is_query_open1 = 1; // 标记为查询界面已打开
                is_query_open=0;//点击处罚过重的状态，错误判罚的状态关闭
                LoadBMP(150, 270, 190, 310, save_picture18);
                textbox_open=2;//处罚过重

            }
            else
            {
                delay(200);
                mouse_off(&mouse);
                // 返回原界面
                LoadBMP(600, 270, 640, 310, save_picture19);
                LoadBMP(140, 400, 904, 600, save_picture20);
                is_query_open1 = 0; // 标记为查询界面已关闭
                textbox_open=0;
            }
            
            if(is_query_open1==1&&is_query_open==0)
            {
                //此时是点击处罚过重的状态，下面写出处罚过重的反应代码
                LoadBMP(140, 400, 904, 600, save_picture20);
                bar2(160, 430, 190, 460, 0x000000);
                puthz(220, 425,"处罚金额过高", 32, 35, 0x000000);
                bar2(160, 480, 190, 510, 0x000000);
                puthz(220, 479,"处罚扣分过多", 32, 35, 0x000000);
                bar2(160, 540, 190, 570, 0x000000);
                puthz(220, 543,"其他原因，等待管理员复核", 32, 35, 0x000000);
            }
        }  
        if(mouse_press(160, 430, 190, 460)==1)
        {
            if(!false_query_open1)
            {
                mouse_off(&mouse);
                save_picture21 = SaveBMP(160, 430, 190, 460);
                DrawCheckmark(176,448,30,0xFF068);
                if(textbox_open==1)//对应错误判罚中的车辆正常停放但被误罚
                {
                    fp=fopen("data1.dat","rb+");
                    fseek(fp, 24+current_pos, SEEK_SET);
                    if_fine=1;
                    fwrite(&if_fine, 2, 1, fp);
                    fseek(fp, -2, SEEK_CUR);
                    fclose(fp);
                }
                else if(textbox_open==2)//对应处罚过重中的处罚金额过高
                {
                    if_fine=1;
                    fp=fopen("data1.dat","rb+");
                    fseek(fp, 24+current_pos, SEEK_SET);
                    fseek(fp, 6, SEEK_CUR);
                    fwrite(&if_fine, 2, 1, fp);
                    fseek(fp, -8, SEEK_CUR);
                    fclose(fp);
                }
                delay(200);
                mouse_show(&mouse);
                false_query_open1= 1 ;
            }
            else
            {
                mouse_off(&mouse);
                LoadBMP(160, 430, 190, 460, save_picture21);
                delay(200);
                /*if(textbox_open==1)
                {
                    fseek(fp, 2, SEEK_CUR);
                    fwrite("0", 2, 1, fp);
                    fseek(fp, -4, SEEK_CUR);
                }
                else if(textbox_open==2)
                {
                    fseek(fp, 6, SEEK_CUR);
                    fwrite("0", 2, 1, fp);
                    fseek(fp, -8, SEEK_CUR);
                }*/
                mouse_show(&mouse);
                false_query_open1 = 0;
            }
        } 
        if(mouse_press(160, 480, 190, 510)==1)
        {
            if(!false_query_open2)
            {
                mouse_off(&mouse);
                save_picture22 = SaveBMP(160, 480, 190, 510);
                DrawCheckmark(176,498,30,0xFF068);
                if(textbox_open==1)//对应错误判罚中的车辆车辆违停类型发生误判
                {
                    if_fine=1;
                    fp=fopen("data1.dat","rb+");
                    fseek(fp, 24+current_pos, SEEK_SET);
                    fseek(fp, 2, SEEK_CUR);
                  fwrite(&if_fine, 2, 1, fp);
                    fseek(fp, -4, SEEK_CUR);
                    fclose(fp);
                }
                else if(textbox_open==2)//对应处罚过重中的处罚扣分过多
                {
                    if_fine=1;
                    fp=fopen("data1.dat","rb+");
                    fseek(fp, 24+current_pos, SEEK_SET);
                    fseek(fp, 8, SEEK_CUR);
                    fwrite(&if_fine, 2, 1, fp);
                    fseek(fp, -10, SEEK_CUR);
                    fclose(fp);
                }
                delay(200);
                mouse_show(&mouse);
                false_query_open2= 1 ;
            }
            else
            {
                mouse_off(&mouse);
                LoadBMP(160, 480, 190, 510, save_picture22);
                delay(200);
                /*if(textbox_open==1)
                {
                    fseek(fp, 2, SEEK_CUR);
                    fwrite("0", 2, 1, fp);
                    fseek(fp, -4, SEEK_CUR);
                }
                else if(textbox_open==2)
                {
                    fseek(fp, 8, SEEK_CUR);
                    fwrite("0", 2, 1, fp);
                    fseek(fp, -10, SEEK_CUR);
                }*/
                mouse_show(&mouse);
                false_query_open2 = 0;
            }
        }
        if(mouse_press(160, 540, 190, 570)==1)
        {
            if(!false_query_open3)
            {
                mouse_off(&mouse);
                save_picture23 = SaveBMP(160, 540, 190, 570);
                DrawCheckmark(176,558,30,0xFF068);
                delay(200);
                mouse_show(&mouse);
                if(textbox_open==1)//对应错误判罚中的其他原因，等待管理员复核
                {
                    if_fine=1;
                    fp=fopen("data1.dat","rb+");
                    fseek(fp, 24+current_pos, SEEK_SET);
                    fseek(fp, 4, SEEK_CUR);
                    fwrite(&if_fine, 2, 1, fp);
                    fseek(fp, -6, SEEK_CUR);
                    fclose(fp);
                }
                else if(textbox_open==2)//对应处罚过重中的其他原因，等待管理员复核
                {
                    if_fine=1;
                    fp=fopen("data1.dat","rb+");
                    fseek(fp, 24+current_pos, SEEK_SET);
                    fseek(fp, 10, SEEK_CUR);
                   fwrite(&if_fine, 2, 1, fp);
                    fseek(fp, -12, SEEK_CUR);
                    fclose(fp);
                }
                false_query_open3= 1 ;
            }
            else
            {
                mouse_off(&mouse);
                LoadBMP(160, 540, 190, 570, save_picture23);
                delay(200);
                /*if(textbox_open==1)
                {
                    fseek(fp, 4, SEEK_CUR);
                    fwrite("0", 2, 1, fp);
                    fseek(fp, -6, SEEK_CUR);
                }
                else if(textbox_open==2)
                {
                    fseek(fp, 10, SEEK_CUR);
                    fwrite("0", 2, 1, fp);
                    fseek(fp, -12, SEEK_CUR);
                }*/
                mouse_show(&mouse);
                false_query_open3 = 0;
            }
        } 
    }
}
