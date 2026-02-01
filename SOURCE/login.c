#include <allfunc.h>
#include <stdio.h>

//新用户注册
void rigister_login(int *func)
{
	int save_picture;
	struct USER temp={0};//存储信息的用户结构体 
	char judge[10]="\0";//用于判断的密码
    mouse_off(&mouse);
    draw_login_visiter_rigister();
	save_picture=SaveBMP(430,635,630,660);

	

    while(1)
    {
        mouse_show(&mouse);
		// 处理点击事件
		if(mouse_press(460, 240, 700, 290)==1)   //输入账号//200, 200, 800, 550
		{
			mouse_off(&mouse);
			bar1(460, 240, 700, 290,0xffff);
			strcpy(temp.name,"\0");
			Getinfo(470,250,temp.name,10,460, 240, 700, 290);
			mouse_on(mouse);
		}
		else if(mouse_press(460, 340, 700, 390)==1)    //输入密码
		{
			mouse_off(&mouse);
			bar1(460, 340, 700, 390,0xffff);
			strcpy(temp.code,"\0");
			Getcode(470,355,temp.code,10,460, 340, 700, 390);
			mouse_on(mouse);
		}
		else if(mouse_press(460, 440, 700, 490)==1)     //重新输入密码
		{
			mouse_off(&mouse);
			bar1(460, 440, 700, 490,0xffff);
			strcpy(judge,"\0");
			Getcode(470,450,judge,10,460, 440, 700, 490);
			mouse_on(mouse);
		}
		if(mouse_press(330,560,430,620)==1)     //点击确认键
		{
			if(strcmp(temp.name,"\0")!=0)//用户名不为空 
			{
				if(strcmp(temp.code,"\0")!=0)//密码不为空 
				{
					if(!strcmp(temp.code,judge))//两次密码相同 
			        {
				      if(save_user(temp)==0)
                      {
						prt_hz24(430,635,"注册成功！",0,"HZK\\Hzk24h");
						delay(1500);	
						*func=2;
						mouse_off(&mouse);
				        break;
                      }
                      else
                      {
                        prt_hz24(430,635,"用户名已被注册！",10,"HZK\\Hzk24h");
                        delay(1500);
				        LoadBMP(430,635,630,660,save_picture);
                      }
			        }
			        else
			        {
				      prt_hz24(430,635,"两次密码不相同！",0,"HZK\\Hzk24h");
				      delay(1500);
				      LoadBMP(430,635,630,660,save_picture);
			        }  
				}
				else
				{
					prt_hz24(430,635,"密码为空！",0,"HZK\\Hzk24h");
				    delay(1500);
				   LoadBMP(430,635,630,660,save_picture);
				}	
			}
			else
			{
				prt_hz24(570,575,"用户名为空！",0,"HZK\\Hzk24h");
				delay(1500);
				bar1(570,575,800,600,0xffff);
			}	
		}
		 if(mouse_press(300,560,450,620)==1)
            {
                puthz(450, 650, "注册成功", 24, 30, 0x000000);
				
                delay(500);
                *func=0;
				mouse_off(&mouse);
                break;
            }
        else if(mouse_press(580,560,680,620)==1)
            {
                *func=2;
				mouse_off(&mouse);
                break;
            }
    }
}

//管理人员登录
void staff_login(int *func)
{
	int pre3 = 0, pre4 = 0;
	char name[10]="\0";
	char code[10]="\0";
	int save_picture;

	save_picture=SaveBMP(430,635,630,660);
    mouse_off(&mouse);
    draw_login_admin();
    mouse_on(mouse);
    while(1)
    {
         // 检测悬停状态
        int hover_visitor = (mouse.x >= 300 && mouse.x <= 450 && mouse.y >= 560 && mouse.y <= 620);
        int hover_admin = (mouse.x >= 580 && mouse.x <= 680 && mouse.y >= 560 && mouse.y <= 620);

        mouse_show(&mouse);
       
        // 更新管理员按钮
		if (hover_visitor != pre3) 
        {
            mouse_off(&mouse); // 关闭鼠标
			bar1(300, 560, 450, 620, 0xFFFFFF); // 恢复背景
            draw_botton(300, 560, 450, 620, hover_visitor ? 0xDDDDDD : 0xFFFFFF, 0x000000);
            puthz_coverd(290, 575, "管理员登录", 5, 32, 30, hover_visitor ? 0xFF0000 : 0x000000);
            pre3 = hover_visitor;
            mouse_on(mouse); // 重绘鼠标

        }
        if (hover_admin != pre4)
        {
            mouse_off(&mouse); // 关闭鼠标
			bar1(580, 560, 680, 620, 0xFFFFFF);
            draw_botton(580, 560, 680, 620, hover_admin ? 0xDDDDDD : 0xFFFFFF, 0x000000);
            puthz_coverd(590, 575, "返回", 2, 32, 30, hover_admin ? 0xFF0000 : 0x000000);
            pre4 = hover_admin;
            mouse_on(mouse);
        }
		if(mouse_press(460, 370, 700, 420)==1)
		{
			mouse_off(&mouse);
			strcpy(name,"\0");
			bar1(460, 370, 700, 420,0xffff);
			Getinfo(502,398,name,9,460, 370, 700, 420);//得到账号 
			mouse_on(mouse);
		}
		else if(mouse_press(460, 445, 700, 495)==1)//点击密码框 
		{
			mouse_off(&mouse);
			strcpy(code,"\0");
			bar1(460, 445, 700, 495,0xffff);
			Getcode(502,468,code,9,460, 445, 700, 495);//得到密码 
			mouse_on(mouse);
		}
		else if(mouse_press(300,560,450,620)==1)//点击登录
		{
			if(strcmp("1",name)==0&&strcmp("1",code)==0)
			{
				*func=5;
				mouse_off(&mouse);
				break;
			}
			else
			{
				prt_hz24(430,635,"信息不符合！",0,"HZK\\Hzk24h");
				delay(1500);
				LoadBMP(430,635,630,660,save_picture);
			}
		}
		else if(mouse_press(580,560,680,620)==1)
        {
            *func=0;
			mouse_off(&mouse);
            break;
        }
		
    }
}

//用户使用账号登录
void user_login(int *func,int *unum)
{
    FILE *fp;
	char name[10]="\0";
	char code[10]="\0";
    int i=-5;
	int pre1 = 0, pre2 = 0,pre3=0;
	int save_picture;
	USERS user={0};
    UserList UL={0};
	InitUList(&UL);
	ReadAllUser(&UL);

    mouse_off(&mouse);
    draw_login_visiter();
	if((fp=fopen("data.dat","rb+"))==NULL)
	{
		printf("error!\n");
		exit(0);
	}
	save_picture=SaveBMP(430,635,630,660);
    mouse_on(mouse);
	fseek(fp,0,SEEK_END);

    while(1)
    {
       	int hover_visitor = (mouse.x >= 250 && mouse.x <= 350 && mouse.y >= 560 && mouse.y <= 620);
        int hover_admin = (mouse.x >= 440 && mouse.x <= 560 && mouse.y >= 560 && mouse.y <= 620);
        int hover_return = (mouse.x >= 660 && mouse.x <= 760 && mouse.y >= 560 && mouse.y <= 620);
        mouse_show(&mouse);
        
        if (hover_visitor != pre1) 
            {
                mouse_off(&mouse); // 关闭鼠标
				bar1(250, 560, 350, 620, 0xFFFFFF); // 恢复背景
                draw_botton(250, 560, 350, 620, hover_visitor ? 0xDDDDDD : 0xFFFFFF, 0x000000);
                puthz_coverd(240, 575, "访客登录", 4, 32, 30, hover_visitor ? 0xFF0000 : 0x000000);
                pre1 = hover_visitor;
                mouse_on(mouse); // 重绘鼠标
            }
            if (hover_admin != pre2)
            {
                mouse_off(&mouse); // 关闭鼠标
				bar1(440, 560, 560, 620, 0xFFFFFF);
                draw_botton(440, 560, 560, 620, hover_admin ? 0xDDDDDD : 0xFFFFFF, 0x000000);
                puthz_coverd(440, 575, "用户注册", 4, 32, 30, hover_admin ? 0xFF0000 : 0x000000);
                pre2 = hover_admin;
                mouse_on(mouse);
            }
            if (hover_return != pre3)
            {
                mouse_off(&mouse); // 关闭鼠标
				bar1(660, 560, 760, 620, 0xFFFFFF);
                draw_botton(660, 560, 760, 620, hover_return ? 0xDDDDDD : 0xFFFFFF, 0x000000);
                puthz_coverd(680, 575, "返回", 2, 32, 30, hover_return ? 0xFF0000 : 0x000000);
                pre3 = hover_return;
                mouse_on(mouse);
			}
		if(mouse_press(460, 370, 700, 420)==1)//点击账号框 
		{
			mouse_off(&mouse);
			strcpy(name,"\0");
			bar1(460, 370, 700, 420,0xffff);
			Getinfo(470,385,name,10,460, 370, 700, 420);//得到账号 
			mouse_on(mouse);
		}
        else if(mouse_press(460, 445, 700, 495)==1)//点击密码框 
		{
			mouse_off(&mouse);
			strcpy(code,"\0");
			bar1(460, 445, 700, 495,0xffff);
			Getcode(470,460,code,10,460, 445, 700, 495);//得到密码 
			mouse_on(mouse);
		}
        if(mouse_press(250,560,350,620)==1)//点击登录
        {
            i=Check_info(UL,name,code);
            if(i>=0)
			{
				FILE *fp_data, *fp_temp;
				USERS temp,temp1;
    			int found = 0;
				int current_pos[5];
				int j;
				// 打开主数据文件 data.dat
				if ((fp_data = fopen("data.dat", "rb+")) == NULL) 
				{
					perror("无法打开文件 data.dat");
					exit(EXIT_FAILURE);
				}
				
				// 遍历 data.dat 文件，查找是否存在同名用户
				while (fread(&temp, sizeof(USERS), 1, fp_data) == 1) 
				{
					if (strcmp(temp.user_name, name) == 0&&found<=5) 
					{
						found++;
						current_pos[found-1] = ftell(fp_data) - sizeof(USERS); // 记录当前文件指针位置
					}
				}
				if (found > 0) 
				{
					// 如果找到用户，将其所有违章数据写入临时文件 data1.dat
					if ((fp_temp = fopen("data1.dat", "wb")) == NULL) 
					{
						perror("无法打开文件 data1.dat");
						fclose(fp_data);
						exit(EXIT_FAILURE);
					}
					for ( j = 0; j < found; j++) 
					{
						fseek(fp_data, current_pos[j], SEEK_SET); // 定位到当前记录
						fread(&temp, sizeof(USERS), 1, fp_data);
						fwrite(&temp, sizeof(USERS), 1, fp_temp);
					}
					 printf("用户 %s 的所有违章数据已提取到 data1.dat 文件中，共 %d 条记录。\n", name, found);
					*func = 26; // 进入用户主界面
					fclose(fp_data);
					fclose(fp_temp);
					DestroyUList(&UL);
					mouse_off(&mouse);
					break;
				}
				else
				{
					*unum=i;
					DestroyUList(&UL);
					strcpy(user.user_name,name);
					strcpy(user.pass_word,code);
					user.if_fine=0;
					user.fine[0]=0;
					user.if_against=0;
					fseek(fp,0,SEEK_END);
					fwrite(&user,sizeof(USERS),1,fp);
					fclose(fp);
					*func=3;      //进入主界面
					data_select(name);
					mouse_off(&mouse);
					break;
				}
			}
			if(i==-2)//密码输入错误 
			{
				prt_hz24(430,635,"密码错误！",0,"HZK\\Hzk24h");
			    delay(1500);
				LoadBMP(430,635,630,660,save_picture);
			}
			if(i==-3)//用户不存在 
			{
				prt_hz24(430,635,"用户不存在！",0,"HZK\\Hzk24h");
			    delay(1500);
				LoadBMP(430,635,630,660,save_picture);
			} 
        }
        else if(mouse_press(660,560,760,620)==1)
        {
            *func=0;
			fclose(fp);
			mouse_off(&mouse);
            break;
        }
        
		else if(mouse_press(440,560,560,620)==1)
		{
			*func=4;
			fclose(fp);
			mouse_off(&mouse);
			DestroyUList(&UL);
			break;
		}
    }

}
