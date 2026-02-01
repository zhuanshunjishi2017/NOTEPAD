#include"allfunc.h"
#include<time.h>
void draw_input_carboard()
{
     //第一行
    prt_hz24_asc32(150, 530, "0", 0x000000, "hzk\\hzk24s");//0
    prt_hz24_asc32(200, 530, "1", 0x000000, "hzk\\hzk24s");//1
    prt_hz24_asc32(250, 530, "2", 0x000000, "hzk\\hzk24s");//2
    prt_hz24_asc32(300, 530, "3", 0x000000, "hzk\\hzk24s");//3
    prt_hz24_asc32(350, 530, "4", 0x000000, "hzk\\hzk24s");//4
    prt_hz24_asc32(400, 530, "5", 0x000000, "hzk\\hzk24s");//5
    prt_hz24_asc32(450, 530, "6", 0x000000, "hzk\\hzk24s");//6
    prt_hz24_asc32(500, 530, "7", 0x000000, "hzk\\hzk24s");//7
    prt_hz24_asc32(550, 530, "8", 0x000000, "hzk\\hzk24s");//8
    prt_hz24_asc32(600, 530, "9", 0x000000, "hzk\\hzk24s");//9
    prt_hz24_asc32(650, 530, "A", 0x000000, "hzk\\hzk24s");//A
    prt_hz24_asc32(700, 530, "B", 0x000000, "hzk\\hzk24s");//B
    prt_hz24_asc32(750, 530, "C", 0x000000, "hzk\\hzk24s");//C
    //第二行
    prt_hz24_asc32(150, 580, "D", 0x000000, "hzk\\hzk24s");//D
    prt_hz24_asc32(200, 580, "E", 0x000000, "hzk\\hzk24s");//E
    prt_hz24_asc32(250, 580, "F", 0x000000, "hzk\\hzk24s");//F
    prt_hz24_asc32(300, 580, "G", 0x000000, "hzk\\hzk24s");//G
    prt_hz24_asc32(350, 580, "H", 0x000000, "hzk\\hzk24s");//H
    prt_hz24_asc32(400, 580, "J", 0x000000, "hzk\\hzk24s");//J
    prt_hz24_asc32(450, 580, "K", 0x000000, "hzk\\hzk24s");//K
    prt_hz24_asc32(500, 580, "L", 0x000000, "hzk\\hzk24s");//L
    prt_hz24_asc32(550, 580, "M", 0x000000, "hzk\\hzk24s");//M
    prt_hz24_asc32(600, 580, "N", 0x000000, "hzk\\hzk24s");//N
    prt_hz24_asc32(650, 580, "P", 0x000000, "hzk\\hzk24s");//P
    prt_hz24_asc32(700, 580, "Q", 0x000000, "hzk\\hzk24s");//Q
    prt_hz24_asc32(750, 580, "R", 0x000000, "hzk\\hzk24s");//R
    //第三行
    prt_hz24_asc32(150, 630, "S", 0x000000, "hzk\\hzk24s");//S
    prt_hz24_asc32(200, 630, "T", 0x000000, "hzk\\hzk24s");//T
    prt_hz24_asc32(250, 630, "U", 0x000000, "hzk\\hzk24s");//U
    prt_hz24_asc32(300, 630, "V", 0x000000, "hzk\\hzk24s");//V
    prt_hz24_asc32(350, 630, "W", 0x000000, "hzk\\hzk24s");//W
    prt_hz24_asc32(400, 630, "X", 0x000000, "hzk\\hzk24s");//X
    prt_hz24_asc32(450, 630, "Y", 0x000000, "hzk\\hzk24s");//Y
    prt_hz24_asc32(500, 630, "Z", 0x000000, "hzk\\hzk24s");//Z
    prt_hz24_asc32(550, 630, "港", 0x000000, "hzk\\hzk24s");//港
    prt_hz24_asc32(600, 630, "澳", 0x000000, "hzk\\hzk24s");//澳
    prt_hz24_asc32(650, 630, "学", 0x000000, "hzk\\hzk24s");//学
    prt_hz24_asc32(700, 630, "警", 0x000000, "hzk\\hzk24s");//警
    prt_hz24_asc32(750, 630, "挂", 0x000000, "hzk\\hzk24s");//挂
    //draw_confirmbotton(750,560,"删除");//删除按钮
    //draw_confirmbotton(750,640,"确认");//确认按钮
    puthz_coverd(815, 545, "删除", 2, 32, 30, 0x000000);
    puthz_coverd(815, 630, "确认", 2, 32, 30, 0x000000);
    draw_confirmbotton(840, 710, "隐藏软键盘"); // 返回上一级
}
void softborad(int car_number)
{
    int save_picture25;
    int save_picture26;
    int save_picture27;
    int save_picture28;
    int save_picture29;
    int save_picture30;
    int save_picture31;
    int save_picture32;
    int save_picture33;
    int if_puthz=0;
    int if_puthz1=0;
    typedef struct {
        char carboard[80];
    } CarPlateData;
    char brand[10];
    FILE*fp;
    // 全局或局部声明结构体数据
    CarPlateData plateData;
    
    // 生成车辆品牌
    srand((unsigned int)time(NULL));

    // 读取车牌数据 
    memset(plateData.carboard, 0, sizeof(plateData.carboard)); // 初始化为全 0
    save_picture25 = SaveBMP(110, 468, 1024, 768);
    save_picture26 = SaveBMP(305, 365, 365, 425);
    

    puthz(810,375,"电",32,40,0x000000);
   
   if(car_number==0)
{
    Line1(315, 415, 355, 415, 0x000000);
    rounded_bar(120, 470, 900, 700, 10, 0xBDBD, 0xFFFFFF, 0);
    puthz(300, 480, "请点击对应的车牌归属省份", 32, 40, 0xFF068);
    rounded_bar(125, 520, 895, 695, 5, 0xFFFFFF, 0xFFFFFF, 0);
    //895-125=770  770-170=600（左右各空出85）  600/12=50（每一个省份的宽度)
    //520-695=175  175-25=150（上空出25）150/3=50（每一个省份的高度）
    //第一行
    puthz(150, 530, "京", 32, 40, 0x000000);    
    puthz(200, 530, "津", 32, 40, 0x000000);
    puthz(250, 530, "冀", 32, 40, 0x000000);
    puthz(300, 530, "晋", 32, 40, 0x000000);
    puthz(350, 530, "蒙", 32, 40, 0x000000);
    puthz(400, 530, "辽", 32, 40, 0x000000);
    puthz(450, 530, "吉", 32, 40, 0x000000);
    puthz(500, 530, "黑", 32, 40, 0x000000);
    puthz(550, 530, "沪", 32, 40, 0x000000);
    puthz(600, 530, "苏", 32, 40, 0x000000);
    puthz(650, 530, "浙", 32, 40, 0x000000);
    puthz(700, 530, "皖", 32, 40, 0x000000);
    puthz(750, 530, "闽", 32, 40, 0x000000);
    //第二行
    puthz(150, 580, "赣", 32, 40, 0x000000);
    puthz(200, 580, "鲁", 32, 40, 0x000000);
    puthz(250, 580, "豫", 32, 40, 0x000000);
    puthz(300, 580, "鄂", 32, 40, 0x000000);
    puthz(350, 580, "湘", 32, 40, 0x000000);
    puthz(400, 580, "粤", 32, 40, 0x000000);
    puthz(450, 580, "桂", 32, 40, 0x000000);
    puthz(500, 580, "琼", 32, 40, 0x000000);
    puthz(550, 580, "渝", 32, 40, 0x000000);
    puthz(600, 580, "川", 32, 40, 0x000000);
    puthz(650, 580, "贵", 32, 40, 0x000000);
    puthz(700, 580, "云", 32, 40, 0x000000);
    puthz(750, 580, "藏", 32, 40, 0x000000);
    //第三行
    puthz(150, 630, "陕", 32, 40, 0x000000);
    puthz(200, 630, "甘", 32, 40, 0x000000);
    puthz(250, 630, "青", 32, 40, 0x000000);
    puthz(300, 630, "宁", 32, 40, 0x000000);
    puthz(350, 630, "新", 32, 40, 0x000000);
    puthz(400, 630, "港", 32, 40, 0x000000);
    puthz(450, 630, "澳", 32, 40, 0x000000);
    puthz(500, 630, "台", 32, 40, 0x000000);
    puthz(550, 630, "使", 32, 40, 0x000000);
    puthz(600, 630, "警", 32, 40, 0x000000);
    puthz(650, 630, "学", 32, 40, 0x000000);
    puthz(700, 630, "挂", 32, 40, 0x000000);
    puthz(750, 630, "领", 32, 40, 0x000000);
    
    /*draw_confirmbotton(750,560,"删除");//删除按钮
    draw_confirmbotton(750,640,"确认");//确认按钮*/
    puthz_coverd(815, 545, "删除", 2, 32, 30, 0x000000);
    puthz_coverd(815, 630, "确认", 2, 32, 30, 0x000000);
   
    draw_confirmbotton(840, 710, "隐藏软键盘"); // 返回上一级      

    while(1)
    {
        if(mouse_press(840, 710, 960, 770)==1 && car_number==0)
        {
            mouse_off(&mouse);
            LoadBMP(110, 468, 1024, 768, save_picture25);
            LoadBMP(305, 365, 365, 425, save_picture26);
            //is_query=0;
            break;
        }
        
        if (mouse_press(150, 520, 200, 570) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "京", 24, 40, 0x000000);
            strncpy(plateData.carboard, "京", 2);
        }

        if (mouse_press(200, 520, 250, 570) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "津", 24, 40, 0x000000);
            strncpy(plateData.carboard, "津", 2);
        }

        if (mouse_press(250, 520, 300, 570) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "冀", 24, 40, 0x000000);
            strncpy(plateData.carboard, "冀", 2);
        }

        if (mouse_press(300, 520, 350, 570) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "晋", 24, 40, 0x000000);
            strncpy(plateData.carboard, "晋", 2);
        }

        if (mouse_press(350, 520, 400, 570) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "蒙", 24, 40, 0x000000);
            strncpy(plateData.carboard, "蒙", 2);
        }

        if (mouse_press(400, 520, 450, 570) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "辽", 24, 40, 0x000000);
            strncpy(plateData.carboard, "辽", 2);
        }

        if (mouse_press(450, 520, 500, 570) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "吉", 24, 40, 0x000000);
            strncpy(plateData.carboard, "吉", 2);
        }

        if (mouse_press(500, 520, 550, 570) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "黑", 24, 40, 0x000000);
            strncpy(plateData.carboard, "黑", 2);
        }

        if (mouse_press(550, 520, 600, 570) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "沪", 24, 40, 0x000000);
            strncpy(plateData.carboard, "沪", 2);
        }

        if (mouse_press(600, 520, 650, 570) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "苏", 24, 40, 0x000000);
            strncpy(plateData.carboard, "苏", 2);
        }

        if (mouse_press(650, 520, 700, 570) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "浙", 24, 40, 0x000000);
            strncpy(plateData.carboard, "浙", 2);
        }

        if (mouse_press(700, 520, 750, 570) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "皖", 24, 40, 0x000000);
            strncpy(plateData.carboard, "皖", 2);
        }

        if (mouse_press(750, 520, 800, 570) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "闽", 24, 40, 0x000000);
            strncpy(plateData.carboard, "闽", 2);
        }

        if (mouse_press(150, 580, 200, 630) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "赣", 24, 40, 0x000000);
            strncpy(plateData.carboard, "赣", 2);
        }

        if (mouse_press(200, 580, 250, 630) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "鲁", 24, 40, 0x000000);
            strncpy(plateData.carboard, "鲁", 2);
        }

        if (mouse_press(250, 580, 300, 630) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "豫", 24, 40, 0x000000);
            strncpy(plateData.carboard, "豫", 2);
        }

        if (mouse_press(300, 580, 350, 630) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "鄂", 24, 40, 0x000000);
            strncpy(plateData.carboard, "鄂", 2);
        }

        if (mouse_press(350, 580, 400, 630) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "湘", 24, 40, 0x000000);
            strncpy(plateData.carboard, "湘", 2);
        }

        if (mouse_press(400, 580, 450, 630) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "粤", 24, 40, 0x000000);
            strncpy(plateData.carboard, "粤", 2);
        }

        if (mouse_press(450, 580, 500, 630) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "桂", 24, 40, 0x000000);
            strncpy(plateData.carboard, "桂", 2);
        }

        if (mouse_press(500, 580, 550, 630) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "琼", 24, 40, 0x000000);
            strncpy(plateData.carboard, "琼", 2);
        }

        if (mouse_press(550, 580, 600, 630) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "渝", 24, 40, 0x000000);
            strncpy(plateData.carboard, "渝", 2);
        }

        if (mouse_press(600, 580, 650, 630) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "川", 24, 40, 0x000000);
            strncpy(plateData.carboard, "川", 2);
        }

        if (mouse_press(650, 580, 700, 630) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "贵", 24, 40, 0x000000);
            strncpy(plateData.carboard, "贵", 2);
        }

        if (mouse_press(700, 580, 750, 630) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "云", 24, 40, 0x000000);
            strncpy(plateData.carboard, "云", 2);
        }

        if (mouse_press(750, 580, 800, 630) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "藏", 24, 40, 0x000000);
            strncpy(plateData.carboard, "藏", 2);
        }

        if (mouse_press(150, 630, 200, 680) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "陕", 24, 40, 0x000000);
            strncpy(plateData.carboard, "陕", 2);
        }

        if (mouse_press(200, 630, 250, 680) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "甘", 24, 40, 0x000000);
            strncpy(plateData.carboard, "甘", 2);
        }

        if (mouse_press(250, 630, 300, 680) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "青", 24, 40, 0x000000);
            strncpy(plateData.carboard, "青", 2);
        }

        if (mouse_press(300, 630, 350, 680) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "宁", 24, 40, 0x000000);
            strncpy(plateData.carboard, "宁", 2);
        }

        if (mouse_press(350, 630, 400, 680) == 1 && car_number == 0) {
            car_number = 1;
            LoadBMP(305, 365, 365, 425, save_picture26);
            puthz(320, 380, "新", 24, 40, 0x000000);
            strncpy(plateData.carboard, "新", 2);
        }
        
        if(mouse_press(815, 545, 915, 595)==1&&car_number==1)
        {
            car_number=0;
            mouse_off(&mouse);
            LoadBMP(305, 365, 365, 425, save_picture26);
            Line1(315, 415, 355, 415, 0x000000);
        }
        if(mouse_press(815, 630, 915, 680)==1&&car_number==1)
        {
            car_number=2;
            mouse_off(&mouse);
            LoadBMP(110, 468, 1024, 768, save_picture25);
            break;
        }
        mouse_show(&mouse);
    }
}
   if(car_number==2)
{
    //Line1(315, 415, 355, 415, 0x000000);
    Line1(385,415,425,415,0x000000);
    rounded_bar(120, 470, 900, 700, 10, 0xBDBD, 0xFFFFFF, 0);
    puthz(320, 480, "请点击对应的车牌号码", 32, 40, 0xFF068);
    rounded_bar(125, 520, 895, 695, 5, 0xFFFFFF, 0xFFFFFF, 0);
    //895-125=770  770-170=600（左右各空出85）  600/12=50（每一个省份的宽度)
    //520-695=175  175-25=150（上空出25）150/3=50（每一个省份的高度）
    draw_input_carboard();
    while(1)
    {
        mouse_show(&mouse);
        if(mouse_press(840, 710, 960, 770)==1 && car_number==2)
        {
            mouse_off(&mouse);
            LoadBMP(110, 468, 1024, 768, save_picture25);
            LoadBMP(375, 365, 435, 425, save_picture26);
            car_number=2;
            break;
        }

        if (mouse_press(650, 520, 700, 570) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "A", 0x000000, "hzk\\hzk24s"); // A
            plateData.carboard[2] = 'A';
        }

        if (mouse_press(700, 520, 750, 570) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "B", 0x000000, "hzk\\hzk24s"); // B
            plateData.carboard[2] = 'B';
        }

        if (mouse_press(750, 520, 800, 570) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "C", 0x000000, "hzk\\hzk24s"); // C
            plateData.carboard[2] = 'C';
        }

        if (mouse_press(150, 580, 200, 630) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "D", 0x000000, "hzk\\hzk24s"); // D
            plateData.carboard[2] = 'D';
        }

        if (mouse_press(200, 580, 250, 630) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "E", 0x000000, "hzk\\hzk24s"); // E
            plateData.carboard[2] = 'E';
        }

        if (mouse_press(250, 580, 300, 630) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "F", 0x000000, "hzk\\hzk24s"); // F
            plateData.carboard[2] = 'F';
        }

        if (mouse_press(300, 580, 350, 630) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "G", 0x000000, "hzk\\hzk24s"); // G
            plateData.carboard[2] = 'G';
        }

        if (mouse_press(350, 580, 400, 630) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "H", 0x000000, "hzk\\hzk24s"); // H
            plateData.carboard[2] = 'H';
        }

        if (mouse_press(400, 580, 450, 630) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "J", 0x000000, "hzk\\hzk24s"); // J
            plateData.carboard[2] = 'J';
        }

        if (mouse_press(450, 580, 500, 630) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "K", 0x000000, "hzk\\hzk24s"); // K
            plateData.carboard[2] = 'K';
        }

        if (mouse_press(500, 580, 550, 630) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "L", 0x000000, "hzk\\hzk24s"); // L
            plateData.carboard[2] = 'L';
        }

        if (mouse_press(550, 580, 600, 630) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "M", 0x000000, "hzk\\hzk24s"); // M
            plateData.carboard[2] = 'M';
        }

        if (mouse_press(600, 580, 650, 630) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "N", 0x000000, "hzk\\hzk24s"); // N
            plateData.carboard[2] = 'N';
        }

        if (mouse_press(650, 580, 700, 630) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "P", 0x000000, "hzk\\hzk24s"); // P
            plateData.carboard[2] = 'P';
        }

        if (mouse_press(700, 580, 750, 630) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "Q", 0x000000, "hzk\\hzk24s"); // Q
            plateData.carboard[2] = 'Q';
        }

        if (mouse_press(750, 580, 800, 630) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "R", 0x000000, "hzk\\hzk24s"); // R
            plateData.carboard[2] = 'R';
        }

        if (mouse_press(150, 630, 200, 680) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "S", 0x000000, "hzk\\hzk24s"); // S
            plateData.carboard[2] = 'S';
        }

        if (mouse_press(200, 630, 250, 680) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "T", 0x000000, "hzk\\hzk24s"); // T
            plateData.carboard[2] = 'T';
        }

        if (mouse_press(250, 630, 300, 680) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "U", 0x000000, "hzk\\hzk24s"); // U
            plateData.carboard[2] = 'U';
        }

        if (mouse_press(300, 630, 350, 680) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "V", 0x000000, "hzk\\hzk24s"); // V
            plateData.carboard[2] = 'V';
        }

        if (mouse_press(350, 630, 400, 680) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "W", 0x000000, "hzk\\hzk24s"); // W
            plateData.carboard[2] = 'W';
        }

        if (mouse_press(400, 630, 450, 680) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "X", 0x000000, "hzk\\hzk24s"); // X
            plateData.carboard[2] = 'X';
        }

        if (mouse_press(450, 630, 500, 680) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "Y", 0x000000, "hzk\\hzk24s"); // Y
            plateData.carboard[2] = 'Y';
        }

        if (mouse_press(500, 630, 550, 680) == 1 && car_number == 2) {
            car_number = 3;
            LoadBMP(375, 365, 435, 425, save_picture26);
            prt_hz24_asc32(399, 380, "Z", 0x000000, "hzk\\hzk24s"); // Z
            plateData.carboard[2] = 'Z';
        }
        if(mouse_press(815, 545, 915, 595)==1 && car_number==3)
        {
            car_number=2;
            LoadBMP(375, 365, 435, 425, save_picture26);
            Line1(385,415,425,415,0x000000);
        }
        if(mouse_press(815, 630, 915, 680)==1 && car_number==3)
        {
            car_number=3;
            LoadBMP(110, 468, 1024, 768, save_picture25);
            break;
        }
        mouse_show(&mouse);
    }
} 
 if(car_number==3)
{
    Line1(455,415,495,415,0x000000);
    rounded_bar(120, 470, 900, 700, 10, 0xBDBD, 0xFFFFFF, 0);
    puthz(320, 480, "请点击对应的车牌号码", 32, 40, 0xFF068);
    rounded_bar(125, 520, 895, 695, 5, 0xFFFFFF, 0xFFFFFF, 0);

   draw_input_carboard();

    while(1)
    {
        if(mouse_press(840, 710, 960, 770)==1&&car_number==3)
        {
            mouse_off(&mouse);
            LoadBMP(110, 468, 1024, 768, save_picture25);
            LoadBMP(445, 365, 505, 425, save_picture26);
            car_number=3;
            break;
        }
        if(mouse_press(150, 520, 200, 570)==1&&car_number==3)
        {
            car_number=4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "0", 0x000000, "hzk\\hzk24s");//0 
            plateData.carboard[3] = '0';
        }
        if (mouse_press(200, 520, 250, 570) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "1", 0x000000, "hzk\\hzk24s"); // 1
            plateData.carboard[3] = '1';
        }

        if (mouse_press(250, 520, 300, 570) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "2", 0x000000, "hzk\\hzk24s"); // 2
            plateData.carboard[3] = '2';
        }

        if (mouse_press(300, 520, 350, 570) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "3", 0x000000, "hzk\\hzk24s"); // 3
            plateData.carboard[3] = '3';
        }

        if (mouse_press(350, 520, 400, 570) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "4", 0x000000, "hzk\\hzk24s"); // 4
            plateData.carboard[3] = '4';
        }

        if (mouse_press(400, 520, 450, 570) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "5", 0x000000, "hzk\\hzk24s"); // 5
            plateData.carboard[3] = '5';
        }

        if (mouse_press(450, 520, 500, 570) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "6", 0x000000, "hzk\\hzk24s"); // 6
            plateData.carboard[3] = '6';
        }

        if (mouse_press(500, 520, 550, 570) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "7", 0x000000, "hzk\\hzk24s"); // 7
            plateData.carboard[3] = '7';
        }

        if (mouse_press(550, 520, 600, 570) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "8", 0x000000, "hzk\\hzk24s"); // 8
            plateData.carboard[3] = '8';
        }

        if (mouse_press(600, 520, 650, 570) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "9", 0x000000, "hzk\\hzk24s"); // 9
            plateData.carboard[3] = '9';
        }

        if (mouse_press(650, 520, 700, 570) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "A", 0x000000, "hzk\\hzk24s"); // A
            plateData.carboard[3] = 'A';
        }

        if (mouse_press(700, 520, 750, 570) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "B", 0x000000, "hzk\\hzk24s"); // B
            plateData.carboard[3] = 'B';
        }

        if (mouse_press(750, 520, 800, 570) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "C", 0x000000, "hzk\\hzk24s"); // C
            plateData.carboard[3] = 'C';
        }

        if (mouse_press(150, 580, 200, 630) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "D", 0x000000, "hzk\\hzk24s"); // D
            plateData.carboard[3] = 'D';
        }

        if (mouse_press(200, 580, 250, 630) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "E", 0x000000, "hzk\\hzk24s"); // E
            plateData.carboard[3] = 'E';
        }

        if (mouse_press(250, 580, 300, 630) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "F", 0x000000, "hzk\\hzk24s"); // F
            plateData.carboard[3] = 'F';
        }

        if (mouse_press(300, 580, 350, 630) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "G", 0x000000, "hzk\\hzk24s"); // G
            plateData.carboard[3] = 'G';
        }

        if (mouse_press(350, 580, 400, 630) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "H", 0x000000, "hzk\\hzk24s"); // H
            plateData.carboard[3] = 'H';
        }

        if (mouse_press(400, 580, 450, 630) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "J", 0x000000, "hzk\\hzk24s"); // J
            plateData.carboard[3] = 'J';
        }

        if (mouse_press(450, 580, 500, 630) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "K", 0x000000, "hzk\\hzk24s"); // K
            plateData.carboard[3] = 'K';
        }

        if (mouse_press(500, 580, 550, 630) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "L", 0x000000, "hzk\\hzk24s"); // L
            plateData.carboard[3] = 'L';
        }

        if (mouse_press(550, 580, 600, 630) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "M", 0x000000, "hzk\\hzk24s"); // M
            plateData.carboard[3] = 'M';
        }

        if (mouse_press(600, 580, 650, 630) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "N", 0x000000, "hzk\\hzk24s"); // N
            plateData.carboard[3] = 'N';
        }

        if (mouse_press(650, 580, 700, 630) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "P", 0x000000, "hzk\\hzk24s"); // P
            plateData.carboard[3] = 'P';
        }

        if (mouse_press(700, 580, 750, 630) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "Q", 0x000000, "hzk\\hzk24s"); // Q
            plateData.carboard[3] = 'Q';
        }

        if (mouse_press(750, 580, 800, 630) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "R", 0x000000, "hzk\\hzk24s"); // R
            plateData.carboard[3] = 'R';
        }

        if (mouse_press(150, 630, 200, 680) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "S", 0x000000, "hzk\\hzk24s"); // S
            plateData.carboard[3] = 'S';
        }

        if (mouse_press(200, 630, 250, 680) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "T", 0x000000, "hzk\\hzk24s"); // T
            plateData.carboard[3] = 'T';
        }

        if (mouse_press(250, 630, 300, 680) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "U", 0x000000, "hzk\\hzk24s"); // U
            plateData.carboard[3] = 'U';
        }

        if (mouse_press(300, 630, 350, 680) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "V", 0x000000, "hzk\\hzk24s"); // V
            plateData.carboard[3] = 'V';
        }

        if (mouse_press(350, 630, 400, 680) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "W", 0x000000, "hzk\\hzk24s"); // W
            plateData.carboard[3] = 'W';
        }

        if (mouse_press(400, 630, 450, 680) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "X", 0x000000, "hzk\\hzk24s"); // X
            plateData.carboard[3] = 'X';
        }

        if (mouse_press(450, 630, 500, 680) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "Y", 0x000000, "hzk\\hzk24s"); // Y
            plateData.carboard[3] = 'Y';
        }

        if (mouse_press(500, 630, 550, 680) == 1 && car_number == 3) {
            car_number = 4;
            LoadBMP(445, 365, 505, 425, save_picture26);
            prt_hz24_asc32(469, 380, "Z", 0x000000, "hzk\\hzk24s"); // Z
            plateData.carboard[3] = 'Z';
        }
        if(mouse_press(815, 545, 915, 595)==1&&car_number==4)
        {
            car_number=3;
            LoadBMP(445,365,505,425, save_picture26);
            Line1(455,415,495,415,0x000000);
        }
        if(mouse_press(815, 630, 915, 680)==1&&car_number==4)
        {
            car_number=4;
            LoadBMP(110,468,1024,768, save_picture25);
            break;
        }
        mouse_show(&mouse);
    }
}   
 if(car_number==4)
{
    Line1(525,415,565,415,0x000000);
    rounded_bar(120, 470, 900, 700, 10, 0xBDBD, 0xFFFFFF, 0);
    puthz(320, 480, "请点击对应的车牌号码", 32, 40, 0xFF068);
    rounded_bar(125, 520, 895, 695, 5, 0xFFFFFF, 0xFFFFFF, 0);

    draw_input_carboard();

    while(1)
    {
        mouse_show(&mouse);
        if(mouse_press(840, 710, 960, 770)==1 && car_number==4)
        {
            mouse_off(&mouse);
            LoadBMP(110, 468, 1024, 768, save_picture25);
            LoadBMP(515, 365, 575, 425, save_picture26);
            car_number=4;
            break;
        }
        if(mouse_press(150, 520, 200, 570)==1 && car_number==4)
        {
            car_number=5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "0", 0x000000, "hzk\\hzk24s");//0
            plateData.carboard[4] = '0';
        }
        if (mouse_press(200, 520, 250, 570) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "1", 0x000000, "hzk\\hzk24s"); // 1
            plateData.carboard[4] = '1';
        }

        if (mouse_press(250, 520, 300, 570) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "2", 0x000000, "hzk\\hzk24s"); // 2
            plateData.carboard[4] = '2';
        }

        if (mouse_press(300, 520, 350, 570) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "3", 0x000000, "hzk\\hzk24s"); // 3
            plateData.carboard[4] = '3';
        }

        if (mouse_press(350, 520, 400, 570) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "4", 0x000000, "hzk\\hzk24s"); // 4
            plateData.carboard[4] = '4';
        }

        if (mouse_press(400, 520, 450, 570) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "5", 0x000000, "hzk\\hzk24s"); // 5
            plateData.carboard[4] = '5';
        }

        if (mouse_press(450, 520, 500, 570) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "6", 0x000000, "hzk\\hzk24s"); // 6
            plateData.carboard[4] = '6';
        }

        if (mouse_press(500, 520, 550, 570) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "7", 0x000000, "hzk\\hzk24s"); // 7
            plateData.carboard[4] = '7';
        }

        if (mouse_press(550, 520, 600, 570) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "8", 0x000000, "hzk\\hzk24s"); // 8
            plateData.carboard[4] = '8';
        }

        if (mouse_press(600, 520, 650, 570) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "9", 0x000000, "hzk\\hzk24s"); // 9
            plateData.carboard[4] = '9';
        }

        if (mouse_press(650, 520, 700, 570) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "A", 0x000000, "hzk\\hzk24s"); // A
            plateData.carboard[4] = 'A';
        }

        if (mouse_press(700, 520, 750, 570) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "B", 0x000000, "hzk\\hzk24s"); // B
            plateData.carboard[4] = 'B';
        }

        if (mouse_press(750, 520, 800, 570) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "C", 0x000000, "hzk\\hzk24s"); // C
            plateData.carboard[4] = 'C';
        }

        if (mouse_press(150, 580, 200, 630) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "D", 0x000000, "hzk\\hzk24s"); // D
            plateData.carboard[4] = 'D';
        }

        if (mouse_press(200, 580, 250, 630) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "E", 0x000000, "hzk\\hzk24s"); // E
            plateData.carboard[4] = 'E';
        }

        if (mouse_press(250, 580, 300, 630) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "F", 0x000000, "hzk\\hzk24s"); // F
            plateData.carboard[4] = 'F';
        }

        if (mouse_press(300, 580, 350, 630) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "G", 0x000000, "hzk\\hzk24s"); // G
            plateData.carboard[4] = 'G';
        }

        if (mouse_press(350, 580, 400, 630) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "H", 0x000000, "hzk\\hzk24s"); // H
            plateData.carboard[4] = 'H';
        }

        if (mouse_press(400, 580, 450, 630) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "J", 0x000000, "hzk\\hzk24s"); // J
            plateData.carboard[4] = 'J';
        }

        if (mouse_press(450, 580, 500, 630) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "K", 0x000000, "hzk\\hzk24s"); // K
            plateData.carboard[4] = 'K';
        }

        if (mouse_press(500, 580, 550, 630) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "L", 0x000000, "hzk\\hzk24s"); // L
            plateData.carboard[4] = 'L';
        }

        if (mouse_press(550, 580, 600, 630) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "M", 0x000000, "hzk\\hzk24s"); // M
            plateData.carboard[4] = 'M';
        }

        if (mouse_press(600, 580, 650, 630) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "N", 0x000000, "hzk\\hzk24s"); // N
            plateData.carboard[4] = 'N';
        }

        if (mouse_press(650, 580, 700, 630) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "P", 0x000000, "hzk\\hzk24s"); // P
            plateData.carboard[4] = 'P';
        }

        if (mouse_press(700, 580, 750, 630) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "Q", 0x000000, "hzk\\hzk24s"); // Q
            plateData.carboard[4] = 'Q';
        }

        if (mouse_press(750, 580, 800, 630) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "R", 0x000000, "hzk\\hzk24s"); // R
            plateData.carboard[4] = 'R';
        }

        if (mouse_press(150, 630, 200, 680) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "S", 0x000000, "hzk\\hzk24s"); // S
            plateData.carboard[4] = 'S';
        }

        if (mouse_press(200, 630, 250, 680) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "T", 0x000000, "hzk\\hzk24s"); // T
            plateData.carboard[4] = 'T';
        }

        if (mouse_press(250, 630, 300, 680) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "U", 0x000000, "hzk\\hzk24s"); // U
            plateData.carboard[4] = 'U';
        }

        if (mouse_press(300, 630, 350, 680) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "V", 0x000000, "hzk\\hzk24s"); // V
            plateData.carboard[4] = 'V';
        }

        if (mouse_press(350, 630, 400, 680) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "W", 0x000000, "hzk\\hzk24s"); // W
            plateData.carboard[4] = 'W';
        }

        if (mouse_press(400, 630, 450, 680) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "X", 0x000000, "hzk\\hzk24s"); // X
            plateData.carboard[4] = 'X';
        }

        if (mouse_press(450, 630, 500, 680) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "Y", 0x000000, "hzk\\hzk24s"); // Y
            plateData.carboard[4] = 'Y';
        }

        if (mouse_press(500, 630, 550, 680) == 1 && car_number == 4) {
            car_number = 5;
            LoadBMP(515, 365, 575, 425, save_picture26);
            prt_hz24_asc32(539, 380, "Z", 0x000000, "hzk\\hzk24s"); // Z
            plateData.carboard[4] = 'Z';
        }
        if(mouse_press(815, 545, 915, 595)==1 && car_number==5)
        {
            car_number=4;
            LoadBMP(515,365,575,425, save_picture26);
            Line1(525,415,565,415,0x000000);
        }
        if(mouse_press(815, 630, 915, 680)==1 && car_number==5)
        {
            car_number=5;
            LoadBMP(110,468,1024,768, save_picture25);
            break;
        }
        mouse_show(&mouse);
    }

}  
 if(car_number==5)
{
    Line1(595,415,635,415,0x000000);
    rounded_bar(120, 470, 900, 700, 10, 0xBDBD, 0xFFFFFF, 0);
    puthz(320, 480, "请点击对应的车牌号码", 32, 40, 0xFF068);
    rounded_bar(125, 520, 895, 695, 5, 0xFFFFFF, 0xFFFFFF, 0);

    draw_input_carboard();
    while(1)
    {
        mouse_show(&mouse);
        if(mouse_press(840, 710, 960, 770)==1 && car_number==5)
        {
            mouse_off(&mouse);
            LoadBMP(110, 468, 1024, 768, save_picture25);
            LoadBMP(585, 365, 645, 425, save_picture26);
            car_number=5;
            break;
        }
        if(mouse_press(150, 520, 200, 570)==1 && car_number==5)
        {
            car_number=6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "0", 0x000000, "hzk\\hzk24s");//0
            plateData.carboard[5] = '0';
        }
        if (mouse_press(200, 520, 250, 570) == 1 && car_number == 5) 
        {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "1", 0x000000, "hzk\\hzk24s"); // 1
            plateData.carboard[5] = '1';
        }

        if (mouse_press(250, 520, 300, 570) == 1 && car_number == 5) 
        {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "2", 0x000000, "hzk\\hzk24s"); // 2
            plateData.carboard[5] = '2';
        }

        if (mouse_press(300, 520, 350, 570) == 1 && car_number == 5) 
        {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "3", 0x000000, "hzk\\hzk24s"); // 3
            plateData.carboard[5] = '3';
        }

        if (mouse_press(350, 520, 400, 570) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "4", 0x000000, "hzk\\hzk24s"); // 4
            plateData.carboard[5] = '4';
        }

        if (mouse_press(400, 520, 450, 570) == 1 && car_number == 5) 
        {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "5", 0x000000, "hzk\\hzk24s"); // 5
            plateData.carboard[5] = '5';
        }

        if (mouse_press(450, 520, 500, 570) == 1 && car_number == 5) 
        {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "6", 0x000000, "hzk\\hzk24s"); // 6
            plateData.carboard[5] = '6';
        }

        if (mouse_press(500, 520, 550, 570) == 1 && car_number == 5) 
        {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "7", 0x000000, "hzk\\hzk24s"); // 7
            plateData.carboard[5] = '7';
        }

        if (mouse_press(550, 520, 600, 570) == 1 && car_number == 5) 
        {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "8", 0x000000, "hzk\\hzk24s"); // 8
            plateData.carboard[5] = '8';
        }

        if (mouse_press(600, 520, 650, 570) == 1 && car_number == 5) 
        {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "9", 0x000000, "hzk\\hzk24s"); // 9
            plateData.carboard[5] = '9';
        }

        if (mouse_press(650, 520, 700, 570) == 1 && car_number == 5) 
        {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "A", 0x000000, "hzk\\hzk24s"); // A
            plateData.carboard[5] = 'A';
        }

        if (mouse_press(700, 520, 750, 570) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "B", 0x000000, "hzk\\hzk24s"); // B
            plateData.carboard[5] = 'B';
        }

        if (mouse_press(750, 520, 800, 570) == 1 && car_number == 5) 
        {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "C", 0x000000, "hzk\\hzk24s"); // C
            plateData.carboard[5] = 'C';
        }

        if (mouse_press(150, 580, 200, 630) == 1 && car_number == 5) 
        {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "D", 0x000000, "hzk\\hzk24s"); // D
            plateData.carboard[5] = 'D';
        }

        if (mouse_press(200, 580, 250, 630) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "E", 0x000000, "hzk\\hzk24s"); // E
            plateData.carboard[5] = 'E';
        }

        if (mouse_press(250, 580, 300, 630) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "F", 0x000000, "hzk\\hzk24s"); // F
            plateData.carboard[5] = 'F';
        }

        if (mouse_press(300, 580, 350, 630) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "G", 0x000000, "hzk\\hzk24s"); // G
            plateData.carboard[5] = 'G';
        }

        if (mouse_press(350, 580, 400, 630) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "H", 0x000000, "hzk\\hzk24s"); // H
            plateData.carboard[5] = 'H';
        }

        if (mouse_press(400, 580, 450, 630) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "J", 0x000000, "hzk\\hzk24s"); // J
            plateData.carboard[5] = 'J';
        }

        if (mouse_press(450, 580, 500, 630) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "K", 0x000000, "hzk\\hzk24s"); // K
            plateData.carboard[5] = 'K';
        }

        if (mouse_press(500, 580, 550, 630) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "L", 0x000000, "hzk\\hzk24s"); // L
            plateData.carboard[5] = 'L';
        }

        if (mouse_press(550, 580, 600, 630) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "M", 0x000000, "hzk\\hzk24s"); // M
            plateData.carboard[5] = 'M';
        }

        if (mouse_press(600, 580, 650, 630) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "N", 0x000000, "hzk\\hzk24s"); // N
            plateData.carboard[5] = 'N';
        }

        if (mouse_press(650, 580, 700, 630) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "P", 0x000000, "hzk\\hzk24s"); // P
            plateData.carboard[5] = 'P';
        }

        if (mouse_press(700, 580, 750, 630) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "Q", 0x000000, "hzk\\hzk24s"); // Q
            plateData.carboard[5] = 'Q';
        }

        if (mouse_press(750, 580, 800, 630) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "R", 0x000000, "hzk\\hzk24s"); // R
            plateData.carboard[5] = 'R';
        }

        if (mouse_press(150, 630, 200, 680) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "S", 0x000000, "hzk\\hzk24s"); // S
            plateData.carboard[5] = 'S';
        }

        if (mouse_press(200, 630, 250, 680) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "T", 0x000000, "hzk\\hzk24s"); // T
            plateData.carboard[5] = 'T';
        }

        if (mouse_press(250, 630, 300, 680) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "U", 0x000000, "hzk\\hzk24s"); // U
            plateData.carboard[5] = 'U';
        }

        if (mouse_press(300, 630, 350, 680) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "V", 0x000000, "hzk\\hzk24s"); // V
            plateData.carboard[5] = 'V';
        }

        if (mouse_press(350, 630, 400, 680) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "W", 0x000000, "hzk\\hzk24s"); // W
            plateData.carboard[5] = 'W';
        }

        if (mouse_press(400, 630, 450, 680) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "X", 0x000000, "hzk\\hzk24s"); // X
            plateData.carboard[5] = 'X';
        }

        if (mouse_press(450, 630, 500, 680) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "Y", 0x000000, "hzk\\hzk24s"); // Y
            plateData.carboard[5] = 'Y';
        }

        if (mouse_press(500, 630, 550, 680) == 1 && car_number == 5) {
            car_number = 6;
            LoadBMP(585, 365, 645, 425, save_picture26);
            prt_hz24_asc32(609, 380, "Z", 0x000000, "hzk\\hzk24s"); // Z
            plateData.carboard[5] = 'Z';
        }
        if(mouse_press(815, 545, 915, 595)==1 && car_number==6)
        {
            car_number=5;
            LoadBMP(585,365,645,425, save_picture26);
            Line1(595,415,635,415,0x000000);
        }
        if(mouse_press(815, 630, 915, 680)==1 && car_number==6)
        {
            car_number=6;
            LoadBMP(110,468,1024,768, save_picture25);
            
            break;
        }
        
    }
}    
if(car_number==6)
{
    Line1(665,415,705,415,0x000000);
    rounded_bar(120, 470, 900, 700, 10, 0xBDBD, 0xFFFFFF, 0);
    puthz(320, 480, "请点击对应的车牌号码", 32, 40, 0xFF068);
    rounded_bar(125, 520, 895, 695, 5, 0xFFFFFF, 0xFFFFFF, 0);

   draw_input_carboard();

    while(1)
    {
        mouse_show(&mouse);
        if(mouse_press(840, 710, 960, 770)==1 && car_number==6)
        {
            mouse_off(&mouse);
            LoadBMP(110, 468, 1024, 768, save_picture25);
            LoadBMP(655, 365, 715, 425, save_picture26);
            car_number=6;
            break;
        }
        if(mouse_press(150, 520, 200, 570)==1 && car_number==6)
        {
            car_number=7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "0", 0x000000, "hzk\\hzk24s");//0 
            plateData.carboard[6] = '0';
        }
        if(mouse_press(200, 520, 250, 570)==1 && car_number==6)
        {
            car_number=7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "1", 0x000000, "hzk\\hzk24s");//1
            plateData.carboard[6] = '1';
        }
        if (mouse_press(250, 520, 300, 570) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "2", 0x000000, "hzk\\hzk24s"); // 2
            plateData.carboard[6] = '2';
        }

        if (mouse_press(300, 520, 350, 570) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "3", 0x000000, "hzk\\hzk24s"); // 3
            plateData.carboard[6] = '3';
        }

        if (mouse_press(350, 520, 400, 570) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "4", 0x000000, "hzk\\hzk24s"); // 4
            plateData.carboard[6] = '4';
        }

        if (mouse_press(400, 520, 450, 570) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "5", 0x000000, "hzk\\hzk24s"); // 5
            plateData.carboard[6] = '5';
        }

        if (mouse_press(450, 520, 500, 570) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "6", 0x000000, "hzk\\hzk24s"); // 6
            plateData.carboard[6] = '6';
        }

        if (mouse_press(500, 520, 550, 570) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "7", 0x000000, "hzk\\hzk24s"); // 7
            plateData.carboard[6] = '7';
        }

        if (mouse_press(550, 520, 600, 570) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "8", 0x000000, "hzk\\hzk24s"); // 8
            plateData.carboard[6] = '8';
        }

        if (mouse_press(600, 520, 650, 570) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "9", 0x000000, "hzk\\hzk24s"); // 9
            plateData.carboard[6] = '9';
        }

        if (mouse_press(650, 520, 700, 570) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "A", 0x000000, "hzk\\hzk24s"); // A
            plateData.carboard[6] = 'A';
        }

        if (mouse_press(700, 520, 750, 570) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "B", 0x000000, "hzk\\hzk24s"); // B
            plateData.carboard[6] = 'B';
        }

        if (mouse_press(750, 520, 800, 570) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "C", 0x000000, "hzk\\hzk24s"); // C
            plateData.carboard[6] = 'C';
        }

        if (mouse_press(150, 580, 200, 630) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "D", 0x000000, "hzk\\hzk24s"); // D
            plateData.carboard[6] = 'D';
        }

        if (mouse_press(200, 580, 250, 630) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "E", 0x000000, "hzk\\hzk24s"); // E
            plateData.carboard[6] = 'E';
        }

        if (mouse_press(250, 580, 300, 630) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "F", 0x000000, "hzk\\hzk24s"); // F
            plateData.carboard[6] = 'F';
        }

        if (mouse_press(300, 580, 350, 630) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "G", 0x000000, "hzk\\hzk24s"); // G
            plateData.carboard[6] = 'G';
        }

        if (mouse_press(350, 580, 400, 630) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "H", 0x000000, "hzk\\hzk24s"); // H
            plateData.carboard[6] = 'H';
        }

        if (mouse_press(400, 580, 450, 630) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "J", 0x000000, "hzk\\hzk24s"); // J
            plateData.carboard[6] = 'J';
        }

        if (mouse_press(450, 580, 500, 630) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "K", 0x000000, "hzk\\hzk24s"); // K
            plateData.carboard[6] = 'K';
        }

        if (mouse_press(500, 580, 550, 630) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "L", 0x000000, "hzk\\hzk24s"); // L
            plateData.carboard[6] = 'L';
        }

        if (mouse_press(550, 580, 600, 630) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "M", 0x000000, "hzk\\hzk24s"); // M
            plateData.carboard[6] = 'M';
        }

        if (mouse_press(600, 580, 650, 630) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "N", 0x000000, "hzk\\hzk24s"); // N
            plateData.carboard[6] = 'N';
        }

        if (mouse_press(650, 580, 700, 630) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "P", 0x000000, "hzk\\hzk24s"); // P
            plateData.carboard[6] = 'P';
        }

        if (mouse_press(700, 580, 750, 630) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "Q", 0x000000, "hzk\\hzk24s"); // Q
            plateData.carboard[6] = 'Q';
        }

        if (mouse_press(750, 580, 800, 630) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "R", 0x000000, "hzk\\hzk24s"); // R
            plateData.carboard[6] = 'R';
        }

        if (mouse_press(150, 630, 200, 680) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "S", 0x000000, "hzk\\hzk24s"); // S
            plateData.carboard[6] = 'S';
        }

        if (mouse_press(200, 630, 250, 680) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "T", 0x000000, "hzk\\hzk24s"); // T
            plateData.carboard[6] = 'T';
        }

        if (mouse_press(250, 630, 300, 680) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "U", 0x000000, "hzk\\hzk24s"); // U
            plateData.carboard[6] = 'U';
        }

        if (mouse_press(300, 630, 350, 680) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "V", 0x000000, "hzk\\hzk24s"); // V
            plateData.carboard[6] = 'V';
        }

        if (mouse_press(350, 630, 400, 680) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "W", 0x000000, "hzk\\hzk24s"); // W
            plateData.carboard[6] = 'W';
        }

        if (mouse_press(400, 630, 450, 680) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "X", 0x000000, "hzk\\hzk24s"); // X
            plateData.carboard[6] = 'X';
        }

        if (mouse_press(450, 630, 500, 680) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "Y", 0x000000, "hzk\\hzk24s"); // Y
            plateData.carboard[6] = 'Y';
        }

        if (mouse_press(500, 630, 550, 680) == 1 && car_number == 6) {
            car_number = 7;
            LoadBMP(655, 365, 715, 425, save_picture26);
            prt_hz24_asc32(677, 380, "Z", 0x000000, "hzk\\hzk24s"); // Z
            plateData.carboard[6] = 'Z';
        }
        if(mouse_press(815, 545, 915, 595)==1 && car_number==7)
        {
            car_number=6;
            LoadBMP(655,365,715,425, save_picture26);
            Line1(665,415,705,415,0x000000);
        }
        if(mouse_press(815, 630, 915, 680)==1 && car_number==7)
        {
            car_number=7;
            LoadBMP(110,468,1024,768, save_picture25);
            
            break;
        }
    }
}
 if(car_number==7)
{
    Line1(735,415,775,415,0x000000);
    rounded_bar(120, 470, 900, 700, 10, 0xBDBD, 0xFFFFFF, 0);
    puthz(320, 480, "请点击对应的车牌号码", 32, 40, 0xFF068);
    rounded_bar(125, 520, 895, 695, 5, 0xFFFFFF, 0xFFFFFF, 0);

    draw_input_carboard();
    while(1)
    {
        if(mouse_press(840, 710, 960, 770)==1 && car_number==8)
        {
            mouse_off(&mouse);
            LoadBMP(110, 468, 1024, 768, save_picture25);
            car_number=7;
            fp=fopen("data1.dat","rb+");
            fseek(fp,60,SEEK_SET);
            fwrite(plateData.carboard, sizeof(plateData.carboard), 1, fp);
            if (if_puthz1!=0)
            {
                brand[0]='a'+if_puthz1;//如果是警车，生成10,如果是挂车，生成11
                brand[1]='\0';
            }
            else
            {
                brand[0] = '0'+rand()%6;
                brand[1] = '\0';
            }
            fseek(fp, 140, SEEK_SET);
            fwrite(brand, sizeof(brand), 1, fp);
            fflush(fp);
            fseek(fp,60,SEEK_SET);
            fclose(fp);
            break;
        }
        if(mouse_press(150, 520, 200, 570)==1 && car_number==7)
        {
            car_number=8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "0", 0x000000, "hzk\\hzk24s");//0
            plateData.carboard[7] = '0';
        }
        if (mouse_press(200, 520, 250, 570) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "1", 0x000000, "hzk\\hzk24s"); // 1
            plateData.carboard[7] = '1';
        }

        if (mouse_press(250, 520, 300, 570) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "2", 0x000000, "hzk\\hzk24s"); // 2
            plateData.carboard[7] = '2';
        }

        if (mouse_press(300, 520, 350, 570) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "3", 0x000000, "hzk\\hzk24s"); // 3
            plateData.carboard[7] = '3';
        }

        if (mouse_press(350, 520, 400, 570) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "4", 0x000000, "hzk\\hzk24s"); // 4
            plateData.carboard[7] = '4';
        }

        if (mouse_press(400, 520, 450, 570) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "5", 0x000000, "hzk\\hzk24s"); // 5
            plateData.carboard[7] = '5';
        }

        if (mouse_press(450, 520, 500, 570) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "6", 0x000000, "hzk\\hzk24s"); // 6
            plateData.carboard[7] = '6';
        }

        if (mouse_press(500, 520, 550, 570) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "7", 0x000000, "hzk\\hzk24s"); // 7
            plateData.carboard[7] = '7';
        }

        if (mouse_press(550, 520, 600, 570) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "8", 0x000000, "hzk\\hzk24s"); // 8
            plateData.carboard[7] = '8';
        }

        if (mouse_press(600, 520, 650, 570) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "9", 0x000000, "hzk\\hzk24s"); // 9
            plateData.carboard[7] = '9';
        }

        if (mouse_press(650, 520, 700, 570) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "A", 0x000000, "hzk\\hzk24s"); // A
            plateData.carboard[7] = 'A';
        }

        if (mouse_press(700, 520, 750, 570) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "B", 0x000000, "hzk\\hzk24s"); // B
            plateData.carboard[7] = 'B';
        }

        if (mouse_press(750, 520, 800, 570) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "C", 0x000000, "hzk\\hzk24s"); // C
            plateData.carboard[7] = 'C';
        }

        if (mouse_press(150, 580, 200, 630) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "D", 0x000000, "hzk\\hzk24s"); // D
            plateData.carboard[7] = 'D';
        }

        if (mouse_press(200, 580, 250, 630) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "E", 0x000000, "hzk\\hzk24s"); // E
            plateData.carboard[7] = 'E';
        }

        if (mouse_press(250, 580, 300, 630) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "F", 0x000000, "hzk\\hzk24s"); // F
            plateData.carboard[7] = 'F';
        }

        if (mouse_press(300, 580, 350, 630) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "G", 0x000000, "hzk\\hzk24s"); // G
            plateData.carboard[7] = 'G';
        }

        if (mouse_press(350, 580, 400, 630) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "H", 0x000000, "hzk\\hzk24s"); // H
            plateData.carboard[7] = 'H';
        }

        if (mouse_press(400, 580, 450, 630) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "J", 0x000000, "hzk\\hzk24s"); // J
            plateData.carboard[7] = 'J';
        }

        if (mouse_press(450, 580, 500, 630) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "K", 0x000000, "hzk\\hzk24s"); // K
            plateData.carboard[7] = 'K';
        }

        if (mouse_press(500, 580, 550, 630) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "L", 0x000000, "hzk\\hzk24s"); // L
            plateData.carboard[7] = 'L';
        }

        if (mouse_press(550, 580, 600, 630) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "M", 0x000000, "hzk\\hzk24s"); // M
            plateData.carboard[7] = 'M';
        }

        if (mouse_press(600, 580, 650, 630) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "N", 0x000000, "hzk\\hzk24s"); // N
            plateData.carboard[7] = 'N';
        }

        if (mouse_press(650, 580, 700, 630) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "P", 0x000000, "hzk\\hzk24s"); // P
            plateData.carboard[7] = 'P';
        }

        if (mouse_press(700, 580, 750, 630) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "Q", 0x000000, "hzk\\hzk24s"); // Q
            plateData.carboard[7] = 'Q';
        }

        if (mouse_press(750, 580, 800, 630) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "R", 0x000000, "hzk\\hzk24s"); // R
            plateData.carboard[7] = 'R';
        }

        if (mouse_press(150, 630, 200, 680) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "S", 0x000000, "hzk\\hzk24s"); // S
            plateData.carboard[7] = 'S';
        }

        if (mouse_press(200, 630, 250, 680) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "T", 0x000000, "hzk\\hzk24s"); // T
            plateData.carboard[7] = 'T';
        }

        if (mouse_press(250, 630, 300, 680) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "U", 0x000000, "hzk\\hzk24s"); // U
            plateData.carboard[7] = 'U';
        }

        if (mouse_press(300, 630, 350, 680) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "V", 0x000000, "hzk\\hzk24s"); // V
            plateData.carboard[7] = 'V';
        }

        if (mouse_press(350, 630, 400, 680) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "W", 0x000000, "hzk\\hzk24s"); // W
            plateData.carboard[7] = 'W';
        }

        if (mouse_press(400, 630, 450, 680) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "X", 0x000000, "hzk\\hzk24s"); // X
            plateData.carboard[7] = 'X';
        }

        if (mouse_press(450, 630, 500, 680) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "Y", 0x000000, "hzk\\hzk24s"); // Y
            plateData.carboard[7] = 'Y';
        }

        if (mouse_press(500, 630, 550, 680) == 1 && car_number == 7) {
            car_number = 8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "Z", 0x000000, "hzk\\hzk24s"); // Z
            plateData.carboard[7] = 'Z';
        }
        if(mouse_press(550, 630, 600, 680)==1&&car_number==7)
        {
            car_number=8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "港", 0x000000, "hzk\\hzk24s"); // 港
            strncpy(&plateData.carboard[7], "港", 2);
            plateData.carboard[9] = '\0'; // 确保以 '\0' 结束
            if_puthz=1;
        }
        if(mouse_press(600, 630, 650, 680)==1&&car_number==7)
        {
            car_number=8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "澳", 0x000000, "hzk\\hzk24s"); // 澳
            strncpy(&plateData.carboard[7], "澳", 2);
            plateData.carboard[9] = '\0'; // 确保以 '\0' 结束
            if_puthz=1;
        }
        if(mouse_press(650, 630, 700, 680)==1&&car_number==7)
        {
            car_number=8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "学", 0x000000, "hzk\\hzk24s"); // 学
            strncpy(&plateData.carboard[7], "学", 2);
            plateData.carboard[9] = '\0'; // 确保以 '\0' 结束
            if_puthz=1;
        }
        if(mouse_press(700,630,750,680)==1&&car_number==7)
        {
            car_number=8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "警", 0x000000, "hzk\\hzk24s"); // 警
            strncpy(&plateData.carboard[7], "警", 2);
            plateData.carboard[9] = '\0'; // 确保以 '\0' 结束
            if_puthz=1;
            if_puthz1=1;
        }
        if(mouse_press(750, 630, 800, 680)==1&&car_number==7)
        {
            car_number=8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            prt_hz24_asc32(747, 380, "挂", 0x000000, "hzk\\hzk24s"); // 挂
            strncpy(&plateData.carboard[7], "挂", 2);
            plateData.carboard[9] = '\0'; // 确保以 '\0' 结束
            if_puthz=1;
            if_puthz1=2;
        }

        if(mouse_press(815, 545, 915, 595)==1 && car_number==8)
        {
            car_number=8;
            LoadBMP(725, 365, 785, 425, save_picture26);
            Line1(735,415,775,415,0x000000);
        }
        if(mouse_press(815, 630, 915, 680)==1 && car_number==8)
        {
            car_number=8;
            LoadBMP(110,468,1024,768, save_picture25);
            /*plateData.carboard[8+if_puthz] = '\0'; // 确保以 '\0' 结束
            if(fwrite(plateData.carboard, sizeof(plateData.carboard), 1, fp)==1)
            {
                printf("写入成功\n");
            }
            else
            {
                printf("写入失败\n");
                exit(0);
            }*/
            //fclose(fp);
            if (if_puthz1!=0)
            {
                brand[0]='a'+if_puthz1;//如果是警车，生成10,如果是挂车，生成11
                brand[1]='\0';
            }
            else
            {
                brand[0] = '0'+rand()%6;
                brand[1] = '\0';
            }
            fp=fopen("data1.dat","rb+");
            fseek(fp, 140, SEEK_SET);
            fwrite(brand, sizeof(brand), 1, fp);
            fflush(fp);
            fseek(fp,60,SEEK_SET);
            fclose(fp);
            break;
        }
    
        mouse_show(&mouse);
    }
}
if(car_number==8&&if_puthz==0)
{
    Line1(805,415,845,415,0x000000);
    rounded_bar(120, 470, 900, 700, 10, 0xBDBD, 0xFFFFFF, 0);
    puthz(320, 480, "此处仅电车用户填写", 32, 40, 0xFF068);
    rounded_bar(125, 520, 895, 695, 5, 0xFFFFFF, 0xFFFFFF, 0);
    LoadBMP(795, 365, 855, 425, save_picture26);
    draw_input_carboard();

    while(1)
    {
        if(mouse_press(840, 710, 960, 770)==1 && car_number==8)
        {
            mouse_off(&mouse);
            LoadBMP(110, 468, 1024, 768, save_picture25);
            LoadBMP(795, 365, 855, 425, save_picture26);
            plateData.carboard[8] = '\0'; // 确保以 '\0' 结束
            fp=fopen("data1.dat","rb+");
            fseek(fp,60,SEEK_SET);
            fwrite(plateData.carboard, sizeof(plateData.carboard), 1, fp);
            if (if_puthz1!=0)
            {
                brand[0]='a'+if_puthz1;//如果是警车，生成b,如果是挂车，生成c
                brand[1]='\0';
            }
            else
            {
                brand[0] = '7'+rand()%3;
                brand[1] = '\0';
            }
            fseek(fp, 140, SEEK_SET);
            fwrite(brand, sizeof(brand), 1, fp);
            fflush(fp);
            fseek(fp,60,SEEK_SET);
            fclose(fp);
           
            break;
        }
        if(mouse_press(840, 710, 960, 770)==1 && car_number==9)
        {
            mouse_off(&mouse);
            LoadBMP(110, 468, 1024, 768, save_picture25);
            fp=fopen("data1.dat","rb+");
            fseek(fp,60,SEEK_SET);
            plateData.carboard[9+if_puthz] = '\0'; // 确保以 '\0' 结束
            fwrite(plateData.carboard, sizeof(plateData.carboard), 1, fp);
            fflush(fp);
            if (if_puthz1!=0)
            {
                brand[0]='a'+if_puthz1;//如果是警车，生成b,如果是挂车，生成c
                brand[1]='\0';
            }
            else
            {
                brand[0] = '7'+rand()%3;
                brand[1] = '\0';
            }
            fseek(fp, 140, SEEK_SET);
            fwrite(brand, sizeof(brand), 1, fp);
            fflush(fp);
            fseek(fp,60,SEEK_SET);
            fclose(fp);
            break;
        }
        if(mouse_press(150, 520, 200, 570)==1 && car_number==8)
        {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "0", 0x000000, "hzk\\hzk24s");//0
            plateData.carboard[8] = '0';
        }
        if (mouse_press(200, 520, 250, 570) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "1", 0x000000, "hzk\\hzk24s"); // 1
            plateData.carboard[8] = '1';
        }

        if (mouse_press(250, 520, 300, 570) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "2", 0x000000, "hzk\\hzk24s"); // 2
            plateData.carboard[8] = '2';
        }

        if (mouse_press(300, 520, 350, 570) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "3", 0x000000, "hzk\\hzk24s"); // 3
            plateData.carboard[8] = '3';
        }

        if (mouse_press(350, 520, 400, 570) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "4", 0x000000, "hzk\\hzk24s"); // 4
            plateData.carboard[8] = '4';
        }

        if (mouse_press(400, 520, 450, 570) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "5", 0x000000, "hzk\\hzk24s"); // 5
            plateData.carboard[8] = '5';
        }

        if (mouse_press(450, 520, 500, 570) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "6", 0x000000, "hzk\\hzk24s"); // 6
            plateData.carboard[8] = '6';
        }

        if (mouse_press(500, 520, 550, 570) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "7", 0x000000, "hzk\\hzk24s"); // 7
            plateData.carboard[8] = '7';
        }

        if (mouse_press(550, 520, 600, 570) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "8", 0x000000, "hzk\\hzk24s"); // 8
            plateData.carboard[8] = '8';
        }

        if (mouse_press(600, 520, 650, 570) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "9", 0x000000, "hzk\\hzk24s"); // 9
            plateData.carboard[8] = '9';
        }

        if (mouse_press(650, 520, 700, 570) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "A", 0x000000, "hzk\\hzk24s"); // A
            plateData.carboard[8] = 'A';
        }

        if (mouse_press(700, 520, 750, 570) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "B", 0x000000, "hzk\\hzk24s"); // B
            plateData.carboard[8] = 'B';
        }

        if (mouse_press(750, 520, 800, 570) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "C", 0x000000, "hzk\\hzk24s"); // C
            plateData.carboard[8] = 'C';
        }

        if (mouse_press(150, 580, 200, 630) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "D", 0x000000, "hzk\\hzk24s"); // D
            plateData.carboard[8] = 'D';
        }

        if (mouse_press(200, 580, 250, 630) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "E", 0x000000, "hzk\\hzk24s"); // E
            plateData.carboard[8] = 'E';
        }

        if (mouse_press(250, 580, 300, 630) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "F", 0x000000, "hzk\\hzk24s"); // F
            plateData.carboard[8] = 'F';
        }

        if (mouse_press(300, 580, 350, 630) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "G", 0x000000, "hzk\\hzk24s"); // G
            plateData.carboard[8] = 'G';
        }

        if (mouse_press(350, 580, 400, 630) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "H", 0x000000, "hzk\\hzk24s"); // H
            plateData.carboard[8] = 'H';
        }

        if (mouse_press(400, 580, 450, 630) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "J", 0x000000, "hzk\\hzk24s"); // J
            plateData.carboard[8] = 'J';
        }

        if (mouse_press(450, 580, 500, 630) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "K", 0x000000, "hzk\\hzk24s"); // K
            plateData.carboard[8] = 'K';
        }

        if (mouse_press(500, 580, 550, 630) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "L", 0x000000, "hzk\\hzk24s"); // L
            plateData.carboard[8] = 'L';
        }

        if (mouse_press(550, 580, 600, 630) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "M", 0x000000, "hzk\\hzk24s"); // M
            plateData.carboard[8] = 'M';
        }

        if (mouse_press(600, 580, 650, 630) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "N", 0x000000, "hzk\\hzk24s"); // N
            plateData.carboard[8] = 'N';
        }

        if (mouse_press(650, 580, 700, 630) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "P", 0x000000, "hzk\\hzk24s"); // P
            plateData.carboard[8] = 'P';
        }

        if (mouse_press(700, 580, 750, 630) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "Q", 0x000000, "hzk\\hzk24s"); // Q
            plateData.carboard[8] = 'Q';
        }

        if (mouse_press(750, 580, 800, 630) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "R", 0x000000, "hzk\\hzk24s"); // R
            plateData.carboard[8] = 'R';
        }

        if (mouse_press(150, 630, 200, 680) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "S", 0x000000, "hzk\\hzk24s"); // S
            plateData.carboard[8] = 'S';
        }

        if (mouse_press(200, 630, 250, 680) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "T", 0x000000, "hzk\\hzk24s"); // T
            plateData.carboard[8] = 'T';
        }

        if (mouse_press(250, 630, 300, 680) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "U", 0x000000, "hzk\\hzk24s"); // U
            plateData.carboard[8] = 'U';
        }

        if (mouse_press(300, 630, 350, 680) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "V", 0x000000, "hzk\\hzk24s"); // V
            plateData.carboard[8] = 'V';
        }

        if (mouse_press(350, 630, 400, 680) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "W", 0x000000, "hzk\\hzk24s"); // W
            plateData.carboard[8] = 'W';
        }

        if (mouse_press(400, 630, 450, 680) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "X", 0x000000, "hzk\\hzk24s"); // X
            plateData.carboard[8] = 'X';
        }

        if (mouse_press(450, 630, 500, 680) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "Y", 0x000000, "hzk\\hzk24s"); // Y
            plateData.carboard[8] = 'Y';
        }

        if (mouse_press(500, 630, 550, 680) == 1 && car_number == 8) {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "Z", 0x000000, "hzk\\hzk24s"); // Z
            plateData.carboard[8] = 'Z';
        }
        if(mouse_press(550, 630, 600, 680)==1&&car_number==8)
        {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "港", 0x000000, "hzk\\hzk24s"); // 港
            strncpy(&plateData.carboard[8], "港", 2);
            if_puthz=1;
        }
        if(mouse_press(600, 630, 650, 680)==1&&car_number==8)
        {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "澳", 0x000000, "hzk\\hzk24s"); // 澳
            strncpy(&plateData.carboard[8], "澳", 2);
            if_puthz=1;
        }
        if(mouse_press(650, 630, 700, 680)==1&&car_number==8)
        {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "学", 0x000000, "hzk\\hzk24s"); // 学
            strncpy(&plateData.carboard[8], "学", 2);
            if_puthz=1;
        }
        if(mouse_press(700, 630, 750, 680)==1&&car_number==8)
        {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "警", 0x000000, "hzk\\hzk24s"); // 警
            strncpy(&plateData.carboard[8], "警", 2);
            if_puthz=1;
            if_puthz1=1;
        }
        if(mouse_press(750, 630, 800, 680)==1&&car_number==8)
        {
            car_number = 9;
            LoadBMP(795, 365, 855, 425, save_picture26);
            prt_hz24_asc32(817, 380, "挂", 0x000000, "hzk\\hzk24s"); // 挂
            strncpy(&plateData.carboard[8], "挂", 2);
            if_puthz=1;
            if_puthz1=2;
        }

        if(mouse_press(815, 545, 915, 595)==1 && car_number==9)
        {
            car_number = 8;
            LoadBMP(795, 365, 855, 425, save_picture26);
            Line1(805,415,845,415,0x000000);
            if_puthz1=0;
            if_puthz=0;
        }
        if(mouse_press(815, 630, 915, 680)==1 && car_number==9)
        {
            car_number = 9;
            LoadBMP(110,468,1024,768, save_picture25);
            plateData.carboard[9+if_puthz] = '\0'; // 确保以 '\0' 结束
            fp=fopen("data1.dat","rb+");
            fseek(fp,60,SEEK_SET);
            fwrite(plateData.carboard, sizeof(plateData.carboard), 1, fp);
            if (if_puthz1!=0)
            {
                brand[0]='a'+if_puthz1;//如果是警车，生成b,如果是挂车，生成c
                brand[1]='\0';
            }
            else
            {
                brand[0] = '7'+rand()%3;
                brand[1] = '\0';
            }
            fseek(fp, 140, SEEK_SET);
            fwrite(brand, sizeof(brand), 1, fp);
            fflush(fp);
            fseek(fp,60,SEEK_SET);
            fclose(fp);
            break;
        }
        mouse_show(&mouse);
    }
}
else if(car_number==8&&if_puthz==1)
{
    LoadBMP(110,468,1024,768, save_picture25);
    puthz(320,500,"您已经输入最后一位特征车牌号",32,40,0xFF068);
    puthz(320,550,"请点击确认按钮",32,40,0xFF068);
}
}