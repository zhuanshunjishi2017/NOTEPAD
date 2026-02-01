#include <allfunc.h>

// 登录界面函数
void welcome(int *page)
{
    
    int pre1 = 0, pre2 = 0;
    bar1(0, 0, 1024, 768, 0xFFFFFF); // (0,0)到(1024,768)的白色背景
    // 设置字体（如果需要的话）
    // setFont("your-font.ttf", 24); // 示例字体设置
    mouse_off(&mouse);
    Readbmp64k(0, 0, "bmp\\ckshust1.bmp");

    // 标题
    puthz(300, 300, "违停管理系统登录", 48, 50, 0x000000);
   // 按钮
    draw_botton(300,450,400,510,0xFFFFFF,0x000000);
    puthz_coverd(290,465,"访客登录",4 ,32,30,0x000000);
    draw_botton(580,450,730,510,0xFFFFFF,0x000000);
    puthz_coverd(580,465,"管理员登录",5 ,32,30,0x000000);
    //draw_main_toolbotton(600, 0x00BD2E, "注册", " "); // 注册
    //draw_main_toolbotton(800, 0x00BD2E, "管理员登录", " "); // 管理员登录
    
    // 底部提示
    puthz(330, 600, "请填写用户名和密码以登录", 24, 30, 0x000000);

    
    
    while (1) 
    {
        // 检测悬停状态
        int hover_visitor= (mouse.x >= 300 && mouse.x <= 400 && mouse.y >= 450 && mouse.y <= 510);
        int hover_admin= (mouse.x >= 580 && mouse.x <= 730 && mouse.y >= 450 && mouse.y <= 510);
        mouse_show(&mouse);
       
        // 更新访客按钮
        if (hover_visitor != pre1) 
        {
            mouse_off(&mouse); // 关闭鼠标
            bar1(300, 450, 400, 510, 0xFFFFFF); // 恢复背景
            draw_botton(300, 450, 400, 510, hover_visitor ? 0xDDDDDD : 0xFFFFFF, 0x000000);
            puthz_coverd(290, 465, "访客登录", 4, 32, 30, hover_visitor ? 0xFF0000 : 0x000000);
            pre1 = hover_visitor;
            mouse_on(mouse); // 重绘鼠标
        }

        // 更新管理员按钮
        if (hover_admin != pre2) 
        {
            mouse_off(&mouse); // 关闭鼠标
            bar1(580, 450, 730, 510, 0xFFFFFF);
            draw_botton(580, 450, 730, 510, hover_admin ? 0xDDDDDD : 0xFFFFFF, 0x000000);
            puthz_coverd(580, 465, "管理员登录", 5, 32, 30, hover_admin ? 0xFF0000 : 0x000000);
            pre2 = hover_admin;
            mouse_on(mouse);
        }

        // 处理点击事件
        if (mouse_press(300, 450, 400, 510) == 1) 
        {
            *page = 2;
            mouse_off(&mouse);
            break;
        } 
        else if (mouse_press(580, 450, 730, 510) == 1) 
        {
            *page = 1;
            mouse_off(&mouse);
            break;
        }
    }
}
void draw_login_admin(void) 
{
    mouse_off(&mouse);
    // 背景
    bar1(0, 0, 1024, 768, 0xFFFFFF); // (0,0)到(1024,768)的白色背景
    Readbmp64k(0, 0, "bmp\\ckshust1.bmp");
    // 标题
    puthz(300, 200, "违章管理系统登录", 48, 50, 0x000000);
    // 登录框
    rounded_bar(200, 350, 800, 550, 10, 0xBDBD, 0xFFFFFF, 0);//(200,350)到(800,550)的圆角矩形
    puthz(250, 380, "用户名", 32, 36, 0x000000);//(250,380)的用户名
    puthz(250, 450, "密码", 32, 40, 0x000000);//(400,210)的密码
    // 输入框
    rounded_bar(460, 370, 700, 420, 5, 0xFFFFFF, 0xFFFFFF, 0);//(460,370)到(700,420)的圆角矩形
    rounded_bar(460, 445, 700, 495, 5, 0xFFFFFF, 0xFFFFFF, 0);//(460,445)到(700,495)的圆角矩形
    // 按钮
    draw_botton(300,560,450,620,0xFFFFFF,0x000000);
    puthz_coverd(290,575,"管理员登录",5 ,32,30,0x000000);
    draw_botton(580,560,680,620,0xFFFFFF,0x000000);
    puthz_coverd(590,575,"返回",2 ,32,30,0x000000);
    // 底部提示
    puthz(330, 650, "请填写用户名和密码以登录", 24, 30, 0x000000);
}

void draw_login_visiter(void)
    {   
        Readbmp64k(0, 0, "bmp\\ckshust1.bmp");
        mouse_off(&mouse);
        // 标题
        puthz(220, 220, "违章管理系统访客查询登录", 48, 50, 0x000000);
        // 登录框
        rounded_bar(200, 350, 800, 550, 10, 0xBDBD, 0xFFFFFF, 0);//(200,350)到(800,550)的圆角矩形
        puthz(250, 380, "用户名", 32, 36, 0x000000);//(250,380)的用户名
        puthz(250, 450, "密码", 32, 40, 0x000000);//(400,210)的密码
        // 输入框
        rounded_bar(460, 370, 700, 420, 5, 0xFFFFFF, 0xFFFFFF, 0);//(460,370)到(700,420)的圆角矩形
        rounded_bar(460, 445, 700, 495, 5, 0xFFFFFF, 0xFFFFFF, 0);//(460,445)到(700,495)的圆角矩形
        draw_botton(250,560,350,620,0xFFFFFF,0x000000);
        puthz_coverd(240,575,"访客登录",4 ,32,30,0x000000);
        draw_botton(440,560,560,620,0xFFFFFF,0x000000);
        puthz_coverd(440,575,"用户注册",4 ,32,30,0x000000);
        draw_botton(660,560,760,620,0xFFFFFF,0x000000);
        puthz_coverd(680,575,"返回",2 ,32,30,0x000000);
        puthz(330, 650, "请填写用户名和密码以登录", 24, 30, 0x000000);
            
    }

void draw_login_visiter_chepai(int *page)
{
    int pre1=0;
    int save_picture1;
    int car_number=0;
    int is_query=0;
    char carboard1[80];
    FILE*  fp;
    
   
   
    Readbmp64k(0, 0, "bmp\\ckshust1.bmp");
    mouse_off(&mouse);
    // 标题
    puthz(220, 220, "违章管理系统访客车牌绑定", 48, 50, 0x000000);
    rounded_bar(120, 350, 900, 450, 10, 0xBDBD, 0xFFFFFF, 0);//(200,350)到(800,550)的圆角矩形
    puthz( 160, 380, "车牌号", 32, 36, 0x000000);
    rounded_bar(310, 370, 360, 420, 5, 0xFFFFFF, 0xFFFFFF, 0);
    rounded_bar(380, 370, 430, 420, 5, 0xFFFFFF, 0xFFFFFF, 0);
    rounded_bar(450, 370, 500, 420, 5, 0xFFFFFF, 0xFFFFFF, 0);
    rounded_bar(520, 370, 570, 420, 5, 0xFFFFFF, 0xFFFFFF, 0);
    rounded_bar(590, 370, 640, 420, 5, 0xFFFFFF, 0xFFFFFF, 0);
    rounded_bar(660, 370, 710, 420, 5, 0xFFFFFF, 0xFFFFFF, 0);
    rounded_bar(730, 370, 780, 420, 5, 0xFFFFFF, 0xFFFFFF, 0);
    rounded_bar(800, 370, 850, 420, 5, 0xFFFFFF, 0xFFFFFF, 0);
    
    puthz(315, 470, "请点击第一个输入框输入车牌号", 24, 30, 0xFF068);
    draw_botton(450,500,580,560,0xFFFFFF,0x000000);
    puthz_coverd(450,515,"车牌绑定",4 ,32,30,0x000000);//(250,560)到(350,620)的按钮
    save_picture1 = SaveBMP(110, 468, 915, 705);
    
    while (1)
    {
        int hover_visitor = (mouse.x >= 450 && mouse.x <= 580 && mouse.y >= 500 && mouse.y <= 560); 
        mouse_show(&mouse);
        if (hover_visitor != pre1&&is_query==0) 
        {
            mouse_off(&mouse); // 关闭鼠标
            bar1(450, 500, 580, 560, 0xFFFFFF); // 恢复背景
            draw_botton(450, 500, 580, 560, hover_visitor ? 0xDDDDDD : 0xFFFFFF, 0x000000);
            puthz_coverd(450, 515, "车牌绑定", 4, 32, 30, hover_visitor ? 0xFF0000 : 0x000000);
            pre1 = hover_visitor;
            mouse_on(mouse); // 重绘鼠标
        }
        if(mouse_press(450,500,580,560)==1&&is_query==0)
         {
            fp = fopen("data1.dat", "rb+");    
            fseek(fp, 60, SEEK_SET);
                fread(carboard1, 80, 1, fp);
                fclose(fp);
                if(carboard1[2] == '\0')
                {
                    puthz(450, 650, "车牌号不能为空", 24, 30, 0xFF068);
                    delay(500);
                }
                else
                {
                    puthz(450, 650, "绑定成功", 24, 30, 0x000000);
                    delay(500);
                    mouse_off(&mouse);
                    *page=26;
                    break;
                }
         }
        if(mouse_press(310, 370,360,420)==1)
        {
            if(is_query==0)
            {
                mouse_off(&mouse);
                car_number=0;
                softborad(car_number);
                mouse_on(mouse);
                is_query=1; 
            }
            if(is_query==1)
            {
                mouse_off(&mouse);
                car_number=0;
                LoadBMP(110, 468, 915, 705, save_picture1);
                mouse_on(mouse);
                is_query=0;
            }
        }

    }  
}
void draw_login_visiter_rigister(void)
{
    Readbmp64k(0, 0, "bmp\\ckshust1.bmp");
    mouse_off(&mouse);
    puthz(380, 120, "用户注册", 48, 50, 0x000000);
    rounded_bar(200, 200, 800, 550, 10, 0xBDBD, 0xFFFFFF, 0);
    //注册
    puthz(250, 250, "新用户名", 32, 36, 0x000000);//(250,380)的用户名
    puthz(250, 350, "请输入密码", 32, 40, 0x000000);//(400,210)的密码
    puthz(250, 450, "确认密码", 32, 40, 0x000000);//(400,210)的密码
    // 输入框
    rounded_bar(460, 240, 700, 290, 5, 0xFFFFFF, 0xFFFFFF, 0);//(460,370)到(700,420)的圆角矩形
    rounded_bar(460, 340, 700, 390, 5, 0xFFFFFF, 0xFFFFFF, 0);//(460,445)到(700,495)的圆角矩形
    rounded_bar(460, 440, 700, 490, 5, 0xFFFFFF, 0xFFFFFF, 0);
    mouse_off(&mouse);
    draw_botton(330,560,430,620,0xFFFFFF,0x000000);
    puthz_coverd(340,575,"注册",2 ,32,30,0x000000);
    draw_botton(580,560,680,620,0xFFFFFF,0x000000);
    puthz_coverd(590,575,"返回",2 ,32,30,0x000000);
}