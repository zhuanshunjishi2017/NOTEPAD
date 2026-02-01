#include <allfunc.h>

void putasc(int x, int y, char *s, int flag, int part, int color)
{
    FILE *asc_p = NULL;
    unsigned char mat[16];
    unsigned long offset;
    unsigned char mask[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
    int i, j, pos;
    int y0 = y;
    int x0 = x;

    asc_p = fopen("HZK\\ASC16", "rb");
    if (asc_p == NULL)
    {
        closegraph();
        printf("cant open ASC16");
        getch();
        exit(1);
    }

    while (*s != '\0')
    {
        while (x < 1024 - 8 && *s != '\0') // 修改循环条件，固定字符宽度8像素
        {
            y = y0;
            offset = (s[0] - 32) * 16L;
            fseek(asc_p, offset, SEEK_SET);
            fread(mat, 16, 1, asc_p);

            for (i = 0; i < 16; i++)
            {
                pos = i; // 每行一个字节
                for (j = 0; j < 8; j++)
                {
                    if ((mask[j % 8] & mat[pos + j / 8]) != 0) // 修正NULL比较为0
                    {
                        putpixel(x + j, y, color);
                    }
                }
                y++;
            }

            x += part; // part控制字符间距
            s += 1;   // ASCII字符占1字节
        }
        x = x0;
        y0 += flag + 10; // flag应为字符高度（16），行间距+10
    }

    fclose(asc_p); // 关闭文件指针
}

void puthz(int x, int y,char *s,int flag,int part,int color)
{
	FILE *hzk_p=NULL;                                       //定义汉字库文件指针
	unsigned char quma,weima;                 //定义汉字的区码和位码
	unsigned long offset;                          //定义汉字在字库中的偏移量
	unsigned char mask[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};  //功能数组，用于显示汉字点阵中的亮点
	int i,j,pos;


	switch(flag)    //不同的flag对应不同的汉字库，实现了汉字的大小可根据需要改变
	{
		case 16 :
				  {
					 char mat[32];   //16*16的汉字需要32个字节的数组来存储
					int y0=y;
					int x0=x;
					 hzk_p = fopen("HZK\\HZ16","rb");            //使用相对路径
					 if(hzk_p==NULL)
					 {
						closegraph();
						printf("cant open HZ16");
						 getch();
						 exit(1);

					}
					while(*s!=NULL)
					{
						while (x<1024-flag && (*s!=NULL))
						{
							y=y0;
							quma=s[0]-0xa0;                      //求出区码
							weima=s[1]-0xa0;                     //求出位码
							offset=(94*(quma-1)+(weima-1))*32L;   //求出要显示的汉字在字库文件中的偏移
							fseek(hzk_p,offset,SEEK_SET);         //重定位文件指针
							fread (mat,32,1,hzk_p);            //读出该汉字的具体点阵数据,1为要读入的项数

							for(i=0;i<16;i++)
							{
								pos=2*i;       //16*16矩阵中有每一行有两外字节
								for(j=0;j<16;j++)    //一行一行地扫描，将位上为了1的点显示出来
								{
									if((mask[j%8]&mat[pos+j/8])!=NULL)   //j%8只能在0—8之间循环，j/8在0，1之间循环
									{
										putpixel(x+j,y,color);

									}

								}
								y++;


							}
							/*====================================================
								以上是一个汉字显示完
							====================================================*/
							x+=part;        //给x 一个偏移量part
							s+=2;           //汉字里存放的是内码，2个字节，所以要加2

						}
						x=x0;y0+=flag+10; //一行汉字显示完后,重新从左侧开始输出汉字，给y一个偏移量
					}

					break;

				 }


		case 24 :
				  {
					char mat[72];   //24*24矩阵要72个字节来存储
					 int y0=y;
					 int x0=x;
					hzk_p = fopen("HZK\\Hzk24k","rb");
					if (hzk_p==NULL)
					{
						closegraph();
						printf("cant open HZ24");
						getch();
						exit(1);

					}
					while(*s!=NULL)
					{
						while(x<1024-flag && (*s!=NULL))
						{
							y=y0;
							quma=s[0]-0xa0;                      //求出区码
							weima=s[1]-0xa0;                     //求出位码
							offset=(94*(quma-1)+(weima-1))*72L;
							fseek(hzk_p,offset,SEEK_SET);
							fread (mat,72,1,hzk_p);
							for (i=0;i<24;i++)
							{
								pos=3*i;   //矩阵中每一行有三个字节
								for (j=0;j<24;j++)   // 每一行有24位
								{
									if ((mask[j%8]&mat[pos+j/8])!=NULL)
										putpixel(x+j,y,color);

								}
								y++;

							}
							x+=part;
							s+=2;
						}
						x=x0;y0+=flag+10;
					}
						break;
				}

		case 32 :
				  {
					 char mat[128];   //32*32的汉字需要128个字节的数组来存储
					int y0=y;
					int x0=x;
					 hzk_p = fopen("HZK\\HZK32S","rb");
					 if(hzk_p==NULL)
					 {
						closegraph();
						printf("cant open HZ32");
						 getch();
						 exit(1);

					}
					while(*s!=NULL)
					{
						while (x<1024-flag && (*s!=NULL))
						{
							y=y0;
							quma=s[0]-0xa0;                      //求出区码
							weima=s[1]-0xa0;                     //求出位码
							offset=(94*(quma-1)+(weima-1))*128L;
							fseek(hzk_p,offset,SEEK_SET);
							fread (mat,128,1,hzk_p);
							for(i=0;i<32;i++)
							{
								pos=4*i;       //32*32矩阵中有每一行有两外字节
								for(j=0;j<32;j++)
								{
									if((mask[j%8]&mat[pos+j/8])!=NULL)
									{
										putpixel(x+j,y,color);

									}

								}
								y++;


							}
								//以上是一个汉字显示完
							x+=part;    //给x 一个偏移量part
							s+=2;          //汉字里存放的是内码，2个字节，所以要加2

						}
						x=x0;y0+=flag+10;   //一行汉字显示完后，给y一个偏移量
					}
						break;

				 }


		case 48:
				  {
					char mat[288];   //48*48的汉字需要288个字节的数组来存储
					int y0=y;
					int x0=x;
					 hzk_p = fopen("HZK\\Hzk48k","rb");
					 if(hzk_p==NULL)
					 {
						closegraph();
						printf("cant open HZ48");
						 getch();
						 exit(1);

					}
					while(*s!=NULL)
					{
						while (x<1024-flag && (*s!=NULL))
						{
							y=y0;
							quma=s[0]-0xa0;                      //求出区码
							weima=s[1]-0xa0;                     //求出位码
							offset=(94*(quma-1)+(weima-1))*288L;   //求出要显示的汉字在字库文件中的偏移
							fseek(hzk_p,offset,SEEK_SET);         //重定位文件指针
							fread (mat,288,1,hzk_p);            //读出该汉字的具体点阵数据,1为要读入的项数

							for(i=0;i<48;i++)
							{
								pos=6*i;
								for(j=0;j<48;j++)    //一行一行地扫描，将位上为了1的点显示出来
								{
									if((mask[j%8]&mat[pos+j/8])!=NULL)   //j%8只能在0—8之间循环，j/8在0，1之间循环
									{
										putpixel(x+j,y,color);

									}

								}
								y++;
							}
								//以上是一个汉字显示完
							x+=part;    //给x 一个偏移量part
							s+=2;          //汉字里存放的是内码，2个字节，所以要加2

						}
						x=x0;y0+=flag+10;   //一行汉字显示完后，给y一个偏移量
					}
						break;

				}

		default:
				  break;

	}

	fclose(hzk_p);
}

void puthz_coverd(int x, int y,char *s,int n,int flag,int part,int color)
{
	int i=0;
	for(i=0;i<part*n;i++)
	{
		Line_Thick(x+i,y,x+i,y+flag+1,1,Getpixel64k(x+i,y-1));
	}
	puthz( x,  y, s, flag, part, color);

}
void puthz_coverd2(int x, int y,char *s,int n,int flag,int part,int color,int backcolor)
{
	int i=0;
	for(i=0;i<part*n;i++)
	{
		Line_Thick(x+i,y,x+i,y+flag+1,1,backcolor);
	}
	puthz( x,  y, s, flag, part, color);

}