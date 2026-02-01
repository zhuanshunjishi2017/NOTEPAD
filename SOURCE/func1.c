#include"allfunc.h"

// �������״̬ö��
typedef enum 
{
    STATE_INIT,
    STATE_UNPROCESSED_QUERY,
    STATE_PROCESSED_PAYMENT,
    STATE_PAID_FEEDBACK
} AppState;

// ��װ����ָ�����
void restoreMainUI(int savepicture1, int savepicyure2, int savepicture3) 
{
    LoadBMP(70, 210, 190, 340, savepicture1);
    LoadBMP(70, 360, 190, 515, savepicyure2);
    LoadBMP(70, 525, 190, 658, savepicture3);
    puthz(72, 280, "δ����", 32, 30, 0x000000);
    puthz(72, 400, "�Ѵ���", 32, 30, 0x000000);
    puthz(72, 440, "δ�ɿ�", 32, 30, 0x000000);
    puthz(72, 560, "�ѽɿ�", 32, 30, 0x000000);
}

// ��װΥ����Ϣ��ʾ����
void showViolationInfo(USERS temp) 
{
    char* location_output[12] = {0};
    char* violation_output[12][4] = {0};
    char fine_str[10];
    char fine_str1[10];
    int i;

    sprintf(fine_str, "%d", temp.fine[0]);
    sprintf(fine_str1, "%d", temp.fine[1]);

    puthz(350, 250, temp.fine_time, 32, 30, 0x0010DD);
    prt_hz16_asc16_size(290, 450, 2, 2, fine_str1, 0x0010DD, "HZK\\hzk16");

    for (i = 0; fine_str[i] != '\0'; i++) 
    {
        char digit[2];
        digit[0] = fine_str[i];
        digit[1] = '\0';
        prt_hz16_asc16_size(700 + i * 20, 450, 2, 2, digit, 0x0010DD, "HZK\\hzk16");
    }

    if (temp.location >= 0 && temp.location < 12 && temp.violation >= 0 && temp.violation < 4) 
    {
        location_input(location_output, temp.location);
        violation_input(violation_output, temp.location, temp.violation);

        if (location_output[temp.location] != NULL) 
        {
            puthz(700, 250, location_output[temp.location], 32, 30, 0x0010DD);
            free(location_output[temp.location]);
        }

        if (violation_output[temp.location][temp.violation] != NULL) 
        {
            puthz(350, 350, violation_output[temp.location][temp.violation], 32, 30, 0x0010DD);
            free(violation_output[temp.location][temp.violation]);
        }
    } 
    else 
    {
        puthz(190, 200, "��Υ�¼�¼", 32, 30, 0x000000);
        puthz(190, 250, "�����ط��ù������������Ӵ", 24, 25, 0x000000);
    }
}
void showViolationInfo1(USERS temp) 
{
    char* location_output[12] = {0};
    

    puthz(350, 350, temp.fine_time, 32, 30, 0x0010DD);

    if (temp.location >= 0 && temp.location < 12 && temp.violation >= 0 && temp.violation < 4) 
    {
        location_input(location_output, temp.location);
        

        if (location_output[temp.location]!= NULL) 
        {
            puthz(700, 350, location_output[temp.location], 32, 30, 0x0010DD);
            free(location_output[temp.location]);
        }
    }
}

// ��װ֧����ά�봦������
void handlePaymentQRCode(int *is_show, int savepicture2_1, const char *bmp_path) 
{
    mouse_off(&mouse);
    delay(200);
    LoadBMP(560, 270, 940, 650, savepicture2_1);
    Readbmp64k(560, 270, bmp_path);
    draw_botton(400, 560, 535, 610, 0xFFFFFF, 0x00FF);
    puthz(400, 570, "���Ѹ���", 32, 35, 0x000000);
    *is_show = 1;
}

void deal_warning(int *page) 
{
    int savepicture1, savepicyure2, savepicture2_1, savepicture3 ;
    FILE *fp;
    USERS temp;
    int if_fine = -1;
    static int current_rating = 0;
    int if_deal = 0, text2 = 0, if_pay = 0;
    long current_pos = 0;
    AppState state = STATE_INIT;
    int is_query_show1_1 = 0;
    int is_query_show1_2 = 0;
    int i;
    char fine_str[10];

    if ((fp = fopen("data1.dat", "rb+")) == NULL) 
    {
        printf("error!\n");
        exit(0);
    }
    fseek(fp, 0, SEEK_END);
    current_pos = ftell(fp) - (long)sizeof(USERS);
    fseek(fp, current_pos, SEEK_SET);
    fread(&temp, sizeof(USERS), 1, fp);
    fclose(fp);

    mouse_off(&mouse);
    Readbmp64k(0, 0, "bmp\\user1.bmp");
    rounded_bar(50, 200, 974, 750, 10, 0xBDBD, 0xFFFFFF, 0);
    bar1(60, 210, 964, 660, 0xFFFFFF);
    puthz(400, 50, "Υ�´���", 48, 50, 0x000000);
    draw_confirmbotton(420, 680, "�ύ����");

    savepicture1 = SaveBMP(70, 210, 190, 340);
    savepicyure2 = SaveBMP(70, 360, 190, 515);
    savepicture3 = SaveBMP(70, 525, 190, 658);
    
    savepicture2_1 = SaveBMP(560, 270, 700, 550);

    Line3(200, 210, 200, 660, 3, 0x000000);
    puthz(72, 280, "δ����", 32, 30, 0x000000);
    puthz(72, 400, "�Ѵ���", 32, 30, 0x000000);
    puthz(72, 440, "δ�ɿ�", 32, 30, 0x000000);
    puthz(72, 560, "�ѽɿ�", 32, 30, 0x000000);
    Line3(60, 350, 190, 350, 5, 0xBD32);
    Line3(60, 520, 190, 520, 5, 0xBD32);
    Circlefill(165, 265, 10, 0xFF000);

    while (1) 
    {
        mouse_show(&mouse);

        switch (state) 
        {
            case STATE_INIT:
                if (mouse_press(70, 210, 190, 350) == 1) 
                {
                    mouse_off(&mouse);
                    delay(200);
                    restoreMainUI(savepicture1, savepicyure2, savepicture3);
                    puthz(72, 280, "δ����", 32, 30, 0x0010DD);
                    Line3(75, 320, 170, 320, 1, 0x0010DD);
                    // ��ʾΥ����Ϣ
                    puthz(220, 250, "Υ��ʱ��", 32, 30, 0x000000);
                    puthz(570, 250, "Υ�µص�", 32, 30, 0x000000);
                    puthz(220, 350, "Υ����Ϊ", 32, 30, 0x000000);
                    puthz(570, 450, "������", 32, 30, 0x000000);
                    puthz(220, 450, "�۷�", 32, 30, 0x000000);
                    puthz(215, 550, "����Կ۷ִ��������ʣ������·��鿴����ϸ��ť�鿴����ϸ��", 24, 25, 0xFF068);
                    draw_confirmbotton(280, 590, "�ύ����");
                    draw_confirmbotton(650, 590, "�鿴����ϸ��");
                    showViolationInfo(temp);
                    state = STATE_UNPROCESSED_QUERY;
                }
                break;
            case STATE_UNPROCESSED_QUERY:
                if (mouse_press(70, 210, 190, 350) == 1) 
                {
                    mouse_off(&mouse);
                    delay(200);
                    restoreMainUI(savepicture1,  savepicyure2, savepicture3);
                    bar1(205, 212, 960, 658, 0xFFFFFF);
                    state = STATE_INIT;
                } else if (mouse_press(280, 590, 400, 650) == 1) 
                {
                    puthz(350, 500, "�����ɹ�����ǰ���ɿ�ҳ��", 32, 30, 0xFF068);
                    if_deal = 1;
                    delay(2000);
                    Circlefill(165, 385, 10, 0xFF000);
                } else if (mouse_press(650, 590, 800, 650) == 1) 
                {
                    *page = 30;
                    bar1(345, 545, 750, 585, 0xFFFFFF);
                    puthz(380, 500, "����ǰ������ϸ��ҳ��", 32, 30, 0xFF068);
                    delay(2000);
                    return;
                }
                break;
            case STATE_PROCESSED_PAYMENT:
                if (mouse_press(70, 360, 190, 515) == 1) 
                {
                    mouse_off(&mouse);
                    delay(200);
                    restoreMainUI(savepicture1,savepicyure2, savepicture3);
                    bar1(205, 212, 960, 658, 0xFFFFFF);
                    state = STATE_INIT;
                } else if (mouse_press(250, 520, 345, 570) == 1) 
                {
                    if (!is_query_show1_1) 
                    {
                        handlePaymentQRCode(&is_query_show1_1, savepicture2_1, "bmp\\zfb.bmp");
                    } 
                    else 
                    {
                        mouse_off(&mouse);
                        delay(200);
                        LoadBMP(560, 270, 940, 650, savepicture2_1);
                        is_query_show1_1 = 0;
                    }
                } else if (mouse_press(400, 560, 535, 610) == 1 && is_query_show1_1) 
                {
                    delay(200);
                    mouse_off(&mouse);
                    start_scan(670, 380, 830, 545, 15, 0xFFE4E1, 5);
                    puthz(400, 610, "����ɹ�", 32, 35, 0xFF068);
                    Circlefill(165, 545, 10, 0xFF000);
                    if_pay = 1;
                    state = STATE_PAID_FEEDBACK;
                } else if (mouse_press(250, 600, 345, 650) == 1) 
                {
                    if (!is_query_show1_2) 
                    {
                        handlePaymentQRCode(&is_query_show1_2, savepicture2_1, "bmp\\wx.bmp");
                        is_query_show1_1 = 0;
                    } else 
                    {
                        mouse_off(&mouse);
                        delay(200);
                        LoadBMP(560, 270, 940, 650, savepicture2_1);
                        is_query_show1_2 = 0;
                    }
                } 
                // ����΢��֧�� �����Ѹ�� ��ť�����߼�
                else if (mouse_press(400, 560, 535, 610) == 1 && is_query_show1_2) 
                {
                    delay(200);
                    mouse_off(&mouse);
                    start_scan(670, 380, 830, 545, 15, 0xFFE4E1, 5);
                    puthz(400, 610, "����ɹ�", 32, 35, 0xFF068);
                    Circlefill(165, 545, 10, 0xFF000);
                    if_pay = 1;
                    state = STATE_PAID_FEEDBACK;
                }
                break;
            case STATE_PAID_FEEDBACK:
                if (mouse_press(70, 525, 190, 658) == 1) 
                {
                    if (if_pay != 1) 
                    {
                        int save_picture20 = SaveBMP(70, 675, 300, 768);
                        puthz(73, 680, "������ɸ���", 32, 30, 0xFF068);
                        delay(1000);
                        LoadBMP(70, 675, 300, 768, save_picture20);
                    } 
                    else 
                    {
                        // ��ʾ��������
                        mouse_off(&mouse);
                        delay(200);
                        restoreMainUI(savepicture1,savepicyure2, savepicture3);
                        bar1(205, 212, 960, 658, 0xFFFFFF);
                        puthz(72, 560, "�ѽɿ�", 32, 30, 0x0010DD);
                        Line3(75, 600, 170, 600, 1, 0x0010DD);
                        puthz(220, 250, "�Ѵ���Υ��", 32, 30, 0x000000);
                        puthz(220, 350, "Υ��ʱ��", 32, 30, 0x000000);
                        puthz(570, 350, "Υ�µص�", 32, 30, 0x000000);
                        showViolationInfo1(temp);
                        puthz(220, 450, "�˴�Υ�´�����������̶�", 32, 30, 0x000000);
                        puthz(340, 560, "������", 32, 30, 0xFF068);
                        puthz(510, 560, "����", 32, 30, 0x0010DD);
                        puthz(660, 560, "�ǳ�����", 32, 30, 0x000000);
                        for (i = 0; i < 10; i++) 
                        {
                            int boxX1 = 350 + i * (40 + 5);
                            int boxY1 = 520;
                            int boxX2 = boxX1 + 40;
                            int boxY2 = boxY1 + 40;
                            bar2(boxX1, boxY1, boxX2, boxY2, 0x000000);
                        }
                        *page=deal_func1();
                        break;
                    }
                }
                else if ((mouse_press(420, 680, 540, 740) == 1) || text2 == 1) 
                {
                    puthz(270, 650, "�����ɹ����Զ�ǰ����ȫѧϰҳ��", 24, 30, 0xFF068);
                    delay(2000);
                    if_fine = 2;
                    if ((fp = fopen("data1.dat", "rb+")) == NULL) 
                    {
                        printf("error!\n");
                        exit(0);
                    }
                    fseek(fp, 36 + current_pos, SEEK_SET);
                    fwrite(&if_fine, sizeof(int), 1, fp);
                    fclose(fp);
                    *page = 31;
                    return;
                }
                break;
        }

        if (if_deal == 1 && mouse_press(70, 360, 190, 515) == 1) 
        {
            mouse_off(&mouse);
            delay(200);
            restoreMainUI(savepicture1,savepicyure2, savepicture3);
            bar1(205, 212, 960, 658, 0xFFFFFF);
            puthz(72, 400, "�Ѵ���", 32, 30, 0x0010DD);
            Line3(75, 440, 170, 440, 1, 0x0010DD);
            puthz(72, 440, "δ�ɿ�", 32, 30, 0x0010DD);
            Line3(75, 480, 170, 480, 1, 0x0010DD);
            puthz(220, 220, "���пƼ���ѧУ԰Υͣ����ϵͳ", 48, 50, 0x000000);
            puthz(450, 270, "�������", 48, 50, 0x000000);
            puthz(210, 330, "�𾴵��û������ã�", 32, 30, 0x000000);
            puthz(210, 370, "��������ɷ��", 32, 30, 0xFF068);
            RMB(220, 420, 2, 2, 0xFF068);
            sprintf(fine_str, "%d", temp.fine[0]);
            for (i = 0; fine_str[i] != '\0'; i++) {
                char digit[2];
                digit[0] = fine_str[i];
                digit[1] = '\0';
                prt_hz16_asc16_size(285 + i * 30, 410, 3, 3, digit, 0xFF06F, "HZK\\hzk16");
            }
            puthz(210, 470, "��ѡ�񸶿ʽ", 24, 25, 0x0010DD);
            draw_botton(250, 520, 345, 570, 0xFFFFFF, 0x00FF);
            puthz(245, 530, "֧����", 32, 35, 0x000000);
            draw_botton(250, 600, 345, 650, 0xFFFFFF, 0x00FF);
            puthz(255, 610, "΢��", 32, 35, 0x000000);
            savepicture2_1 = SaveBMP(560, 270, 940, 650);
            state = STATE_PROCESSED_PAYMENT;
        }
        if(*page==27)
        {
            break;
        }
    }
}
void punish(int *page)
{
    mouse_off(&mouse);
    Readbmp64k(0, 0, "bmp\\user1.bmp");
    puthz(350,50,"���пƼ���ѧ",48,50,0x9932CC);
    puthz(270,120,"������Υͣ��������",48,50,0x000000);
    rounded_bar(50, 200, 974, 750, 10, 0xBDBD, 0xFFFFFF, 0);
    bar1(60, 210, 964, 660, 0xFFFFFF);
    draw_confirmbotton(420, 680, "������һ��"); // ������һ��
    /*��һ����΢Υ��
    �ڷ�ָ����ʱͣ���������ͣ����������ڣ���δӰ�콻ͨ���������ͨ�С�ͣ��ʱ�������ֳ���ͣ��λ�߽磬��δ����������������������ͨ��,ÿ�ο۶���,����20Ԫ
    (����һ��Υ��
    �ڽ�ֹͣ����־�����ߴ�ͣ������δ��ɽ�ͨӵ�¡�������ͨ����Ӧ��ͨ��ͣ������δ�������������ÿ�ο���֣�����30Ԫ
    ����������Υ��
    ������ͨ����Ӧ��ͨ����ʱ��ͣ�������½�����Ԯ�����޷�ͨ�С���Υͣ���У԰�ڽ�ͨ����ӵ�£�Ӱ�췶Χ�ϴ��ҳ���ʱ��ϳ���������ʮ���ӣ�������Υ�棺ÿ�ο�ʮ�֣�����50Ԫ*/
    puthz(65, 220, "��һ����΢Υ��", 32, 30, 0x000000);
    puthz(110, 270, "�ڷ�ָ����ʱͣ���������ͣ����������ڣ���δӰ�콻ͨ���������ͨ�С�", 24, 25, 0x000000);
    puthz(80, 300, "ͣ��ʱ�������ֳ���ͣ��λ�߽磬��δ����������������������ͨ�У�ÿ�ο۶�", 24, 25, 0x000000);
    puthz(80, 330, "�֣������ʮԪ", 24, 25, 0x000000);
    puthz(65, 370, "������һ��Υ��", 32, 30, 0x000000);
    puthz(110, 420, "�ڽ�ֹͣ����־�����ߴ�ͣ������δ��ɽ�ͨӵ�¡�������ͨ����Ӧ��ͨ��ͣ", 24, 25, 0x000000);
    puthz(80, 450, "������δ�������������ÿ�ο���֣�������ʮԪ", 24, 25, 0x000000);
    puthz(65, 490, "����������Υ��", 32, 30, 0x000000);
    puthz(110, 530, "������ͨ����Ӧ��ͨ����ʱ��ͣ�������½�����Ԯ�����޷�ͨ�С���Υͣ���", 24, 25, 0x000000);
    puthz(80, 570, "У԰�ڽ�ͨ����ӵ�£�Ӱ�췶Χ�ϴ��ҳ���ʱ��ϳ���������ʮ���ӣ���Υ����", 24, 25, 0x000000);
    puthz(80, 600, "ÿ�ο�ʮ�֣�������ʮԪ", 24, 25, 0x000000);
    while(1)
    {
        mouse_show(&mouse);
        if(mouse_press(420, 680, 540, 740)==1)
        {
            *page=29;
            break;
        }
    }
}
void safe_learning_deal(int *page)
{
    int is_query_open = 0; 
    // ��־��������¼�Ƿ��ڲ�ѯ����
    int save_picture16; // ����ԭ����
    int save_picture17;

    Readbmp64k(0, 0, "bmp\\user1.bmp");   
    
    puthz(350, 50, "��ȫ֪ʶѧϰ", 48, 50, 0x000000);
    puthz(250, 150, "���пƼ���ѧ��������������", 32, 40, 0x000000);
   
    rounded_bar(50, 200, 974, 750, 10, 0xBDBD, 0xFFFFFF, 0);
    bar1(60, 210, 964, 660, 0xFFFFFF);

    draw_confirmbotton(430, 680, "ȷ�ϲ��˳�"); // ������һ��
    
    puthz(80, 250,"��һ��",32,30,0x000000);
    puthz(110, 300,"У԰���ɵ����ࡢ��ѧ��������¥�����ڡ���������Ա�ܼ���ͨ����������",24,25,0x000000);
    puthz(75, 330,"��ͣ�Ż���������ʩ��ͣ��λ�ĳ��⡣������ͣ��λͣ��Ӧ���ع淶��ͣ����λ��",24,25,0x000000);
    puthz(75, 360,"���ÿ�ѹͣ���ߡ�",24,25,0x000000);
    puthz(80, 400,"�ڶ���",32,30,0x000000);
    puthz(110, 440,"У԰�ڻ���������ʻӦ���ؽ�ͨ���򣬲��ó�����ʻ���������У�����ռ����",24,25,0x000000);
    puthz(75, 470,"�е���ʻ��������У԰�������ȡ�",24,25,0x000000);
    puthz(80, 510,"������",32,30,0x000000);
    puthz(110, 550,"��У԰��ͣ�Ż�������Ӧ������۲��ź˶����շѱ�׼����ͣ�ŷ��á�",24,25,0x000000);

    bar2(258,626,288,656,0x000000);
    puthz(300,630,"����֪����ͬ������������Ը����ѭ��������",24,25,0x000000);

    /*prt_hz24_asc32(25, 150,"У԰���ɵ����ࡢ��ѧ��������¥�����ڡ���������Ա�ܼ���ͨ���������Ͻ�ͣ�Ż�����,��ʩ��ͣ��λ�ĳ��⡣������ͣ��λͣ��Ӧ���ع淶,ͣ����λ,���ÿ�ѹͣ���ߡ�", 0x000000, "HZK\\HZK24s");
    prt_hz24_asc32(25, 250,"У԰�ڻ���������ʻӦ���ؽ�ͨ����,���ó�����ʻ,��������,����ռ�����е���ʻ,������У԰�������ȡ�", 0x000000, "HZK\\HZK24s");
    prt_hz24_asc32(25, 350,"��У԰��ͣ�Ż�����,Ӧ������۲��ź˶����շѱ�׼����ͣ�ŷ��á�", 0x000000, "HZK\\HZK24s");
    */
    
    while (1)
    {
        mouse_show(&mouse);
        
        if (mouse_press(430, 680, 550, 740) == 1)
        {
            if(is_query_open!=1)
            {
                mouse_off(&mouse);
                save_picture17 = SaveBMP(258, 586, 800, 650);//����ԭ����,��Ϊ290����Ϊ220
                //Readbmp64k(450, 350, "bmp\\warning.bmp");Ч�����ã���Ϊ�����
                puthz(300, 600, "���û�ȷ��ͬ��У԰������ȫ��������", 24, 25, 0xFF068);
                delay(1000);
                LoadBMP(258, 586, 800, 650, save_picture17);
            }
            else
            {
                *page = 26;
                break;
            }
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
void search_history(int *page)
{
    
    char* location[] = 
    {
        "���Ƹ�С", "ͼ���", "��е¥", "����ѧԺ", "������", 
        "�϶���", "�����ѧԺ", "����ѧԺ", "�вٳ�", "����������", 
        "����԰", "ѧ����������"
    };
    //Υͣ��ΪԤ��
    char *locations[20][4] = 
    {
            {"δ���涨ͣ������������ͨ��", "����ռ�����е�", "����ͣ�ڽ�ͣ����", "����ͣ��У԰�����"},
            {"����ͣ��ͼ������", "δ���涨ͣ��", "ռ�òм���ͣ��λ", "����ͣ���̻�����"},
            {"����ͣ�ڻ�е¥�����", "δ���涨ͣ��", "����ͣ������˨ǰ", "����ͣ��Ӧ��ͨ��"},
            {"����ͣ�ڹ���ѧԺ���", "δ���涨ͣ��", "ռ��taffͣ��λ", "����ͣ���̻�����"},
            {"����ͣ�����������", "δ���涨ͣ��", "����ͣ��Ӧ��ͨ��", "����ͣ�ڹ���ͨ��"},
            {"����ͣ���϶��ų����", "δ���涨ͣ��", "����ͣ�����е���", "����ͣ�ڽ�ͣ����"},
            {"ռ��ʵ�����豸װж��", "ͣ��ѧԺ����̨��ǰ", "ռ������Դ�����λ", "��ռ����ר��ͣ����"},
            {"ͣ���������ͨ��", "��ѧԺ����·��Υͣ", "ռ�÷ÿͳ�λ", "������˨ǰΥ��ͣ��"},
            {"ͣ�����˶���Ӧ��ͨ��", "ռ���ܵ��ܱ߻�����", "�ڹ���ϯ�����ͣ��", "��ռ�ٳ���Χ�ǻ�������"},
            {"��������¥����ͨ��", "ռ����������ר�ó�λ", "���������г���ǰͣ��", "ҹ��Υͣ����ʱ��ͣ��"},
            {"ʻ��԰���̵�ͣ��", "ռ���ּ䲽�е�", "�ں��߹۾�ƽ̨Υͣ", "ͣ����԰����խ·��"},
            {"�ڻ��鳵����ڴ�ͣ��", "ͣ�������ľ����̻���","����������Ա����ͨ��","δ���涨ͣ��"}
        };
        FILE *fp = NULL;
        USERS records[20];
        int total = 0;
        int current_index = 0;
        int need_refresh = 1;
        // ��ȡ���м�¼
        fp = fopen("data1.dat", "rb+");
        if (fp) 
        {
            while (total < 20 && fread(&records[total], sizeof(USERS), 1, fp) == 1) 
            {
                total++;
            }
            fclose(fp);
        }
        // ��ʼ������
        mouse_off(&mouse);
        bar1(0, 0, 1024, 768, 0xFFFFFF);
        mouse_off(&mouse);
        Readbmp64k(0, 0, "bmp\\user1.bmp");
        rounded_bar(100, 150, 924, 600, 20, 0xFFFFFF, 0x000000, 0);
        // ���Ʋ�����ť
        puthz(50, 50, "��ʷΥ��ҳ", 48, 50, 0x000000);
        rounded_bar(100, 150, 924, 600, 20, 0xFFFFFF, 0x000000, 0);
        draw_botton(250,620,350,680,0xFFFFFF,0x000000);
        puthz_coverd(240,635,"��һҳ",4,32,30,0x000000);
        draw_botton(440,620,560,680,0xFFFFFF,0x000000);
        puthz_coverd(440,635,"������ҳ",4,32,30,0x000000);
        draw_botton(660,620,790,680,0xFFFFFF,0x000000);
        puthz_coverd(640,635,"����������",2,32,30,0x000000);

      
        // ��ѭ��
        while (1) 
        {
            mouse_show(&mouse);
            if (need_refresh) 
            {
                mouse_off(&mouse);
                    rounded_bar(100, 150, 924, 600, 20, 0xFFFFFF, 0x000000, 0);
                if (current_index >= total) 
                {
                    puthz(330, 300, "�������һ����¼", 32, 40, 0x000000);
                    delay(500);
                    *page=26;
                    break;
                } 
                else
                {
                    puthz(150, 180, "���ƺ���", 32, 40, 0x000000);
                    prt_hz16_asc16_size(330, 180, 2, 2, records[current_index].carboard, 0x000000,"HZK\\hzk16");
                    puthz(150, 230, "Υ�µص�", 32, 40, 0x000000);
                    puthz(330, 230, location[records[current_index].location], 32, 40, 0x000000);
                    puthz(150, 280, "Υ������", 32, 40, 0x000000);
                    puthz(330, 280, locations[records[current_index].location][records[current_index].violation], 32, 40, 0x000000);
                    puthz(150, 330, "�����۷�", 32, 40, 0x000000);
                    put_asc16_number_size_coverd(330, 330, 2, 2, 1, records[current_index].fine[1], 0x000000);
                    puthz(500, 330, "�������", 32, 40, 0x000000);
                    put_asc16_number_size_coverd(650, 330, 2, 2, 1, records[current_index].fine[0], 0x000000);
                    draw_botton(600, 405, 700, 455, 0xFFFFFF, 0x000000);
                    puthz_coverd(590, 415, "���ж�", 2, 32, 30, 0x000000);
                    if  ((records[current_index].location == 0 && records[current_index].violation == 0) ||  // ��������ͨ��
				                (records[current_index].location == 2 && records[current_index].violation == 2) ||  // ����˨ǰ
				                (records[current_index].location == 4 && records[current_index].violation == 2) ||  // Ӧ��ͨ��
				                (records[current_index].location == 9 && records[current_index].violation == 0) ||  // ��������ͨ��
				                (records[current_index].location == 11 && records[current_index].violation == 0))
                                {  // ��������ͨ��
				                Readbmp64k(300, 400, "bmp\\3.bmp");
				                }
				                // �ڶ��ࣺ�����Υ��
				                if((records[current_index].location == 0 && records[current_index].violation == 3) ||  // У԰�����
				                (records[current_index].location == 1 && records[current_index].violation == 0) ||  // ͼ������
				                (records[current_index].location == 2 && records[current_index].violation == 0) ||  // ��е¥�����
				                (records[current_index].location == 3 && records[current_index].violation == 0) ||  // ����ѧԺ���
				                (records[current_index].location == 4 && records[current_index].violation == 0) ||  // ���������
				                (records[current_index].location == 5 && records[current_index].violation == 0)) { // �϶��ų����
				            
				                Readbmp64k(300, 400, "bmp\\5.bmp");
				                } 
				                // �����ࣺ���⳵λռ��
				                if ((records[current_index].location == 1 && records[current_index].violation == 2) ||  // �м��˳�λ
				                (records[current_index].location == 3 && records[current_index].violation == 2) ||  // taffͣ��λ
				                (records[current_index].location == 6 && records[current_index].violation == 2) ||  // ����Դ���λ
				                (records[current_index].location == 7 && records[current_index].violation == 2) ||  // �ÿͳ�λ
				                (records[current_index].location == 9 && records[current_index].violation == 1) )  // �������˳�λ
				                {
				                Readbmp64k(300, 400, "bmp\\1.bmp");
				                }
				                // �����ࣺ�̻�/���е�Υ��
				                if ((records[current_index].location == 0 && records[current_index].violation == 1) ||  // ռ�����е�
				                (records[current_index].location == 1 && records[current_index].violation == 3) ||  // �̻�����
				                (records[current_index].location == 3 && records[current_index].violation == 3) ||  // �̻�����
				                (records[current_index].location == 5 && records[current_index].violation == 2) ||  // ���е���
				                (records[current_index].location == 10 && records[current_index].violation == 1)) {  // �����̻���
				                Readbmp64k(300, 400, "bmp\\6.bmp");
				                }
				                // �����ࣺ��������Υ��
				                if((records[current_index].location == 6 && records[current_index].violation == 1) ||  // ѧԺ̨��ǰ
				                (records[current_index].location == 7 && records[current_index].violation == 1) ||  // ����·��
				                (records[current_index].location == 8 && records[current_index].violation == 1) ||  // �ܵ�������
				                (records[current_index].location == 9 && records[current_index].violation == 3) ||  // ҹ��Υͣ
				                (records[current_index].location == 11 && records[current_index].violation == 3)) {  // ҹ��Υͣ
				                Readbmp64k(300, 400, "bmp\\2.bmp");
				                }
				                // �����ࣺ����Υ��
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
				            need_refresh = 1;
				            while(mouse_press(250,620,350,680) == 1);
				        }
				        
				        if (mouse_press(440,620,560,680) == 1) 
                        {
				            *page = 26;
				            break;
				        }
				        
				        if (mouse_press(660,620,790,680) == 1) 
                        {
				            *page = 26;
				            break;
				        }
				        
				        if (mouse_press(830,600,1000,660) == 1) 
                        {
				            *page = 26;
				            break;
				        }
				
				    }
				
}