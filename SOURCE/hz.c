#include "hz.h"


/*16位点阵汉字输出，x,y表示汉字输出位置，s为汉字串，color表示汉字颜色，
name 为汉字库文件路径，即字体信息*/
void prt_hz16(int x, int y, char *s, unsigned int color, char * name) 
{
	FILE * fp=NULL;
	char buffer[32]={0};                                          //用来读取16汉字的32位字模

	int i=0;
	int j=0;
	unsigned char qh =0;     
    unsigned char wh =0; 	    //汉字区位号
	unsigned long offset=0;     //汉字内码
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //用来屏蔽出每一位的信息

						  0x02,0x01};
	if((fp=fopen(name,"rb"))==NULL)
	{
		printf("Can't open hzk16!");
		getch();
		exit(0);
	}
	while(*s)                                        //若汉字串未读完，则继续

    {
		qh=* s-160;                                       //???????????
        wh=*(s+1) -160;
        offset=(94*(qh-1)+(wh-1))*32L;                     //????��????
        fseek(fp,offset, SEEK_SET);                        //?????????��???????��??
        fread(buffer, 32, 1, fp);                          //??????��??????
        for(i=0;i<16;i++)                                  //?????????????????
			{
				for(j=0;j<16;j++)
				{
					if((mask[j%8] & buffer[i*2+j/8])!=0)
					{
						putpixel(x+j,y+i,color);
					}
				}
			}
			x+=16;                                          //?????????????16
			s+=2;                                           //????????????
    }
    fclose(fp);
}


/*(有延迟)24位点阵汉字输出，x,y表示汉字输出位置，s为汉字串，color表示汉字颜色，
name 为汉字库文件路径，即字体信息*/
void prt_hz24(int x, int y,char * s, unsigned int color, char * name)    
{
	FILE * fp=NULL;
	char buffer[72]={0};                                            //???????24?????72��???
	int i=0;
	int j=0;
	unsigned char qh=0;
	unsigned char wh=0;
	unsigned long offset=0;
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //???????��???��?????
						  0x02,0x01};
	if((fp=fopen(name,"rb"))==NULL)
	{
		printf("Can't open hzk24!");
        getch();
        exit(0);
    }
    while(*s)
    {
        qh=* s-160;
        wh=*(s+1)-160;
        offset=(94*(qh-1)+(wh-1))*72L;             
        fseek(fp,offset, SEEK_SET);
		fread(buffer, 72, 1, fp);
        for(i=0; i<24; i++)                                 //??????????
           for(j=0;j<24;j++)
			{
				if((mask[j%8] & buffer[i*3+j/8])!=0)
				{
					putpixel(x+j,y+i,color);
				}					
			}
        s+=2;
        x+=24;                                         //行输出，间距24
		//delay(50);         //使每个汉字输出过程可见，起到美化效果的作用
    }
    fclose(fp);
}



void prt_asc16( int x,int y,char * s,unsigned int color)		//输出一串英文函数
{

	FILE *  fp=NULL;
	int i=0;
	int j=0;
	unsigned long offset=0;
	char buffer[16]={0};
	if (!(fp=fopen("hzk\\ASC16","rb")))
	{
        printf("asc16 wrong!");		
        exit(1);
	}
	while(*s)
    { 
		offset=*s * 16L;                         	
		fseek(fp,offset,0);
		fread(buffer,16,1,fp);                        
		
		for(i=0;i<16;i++)
			for(j=0;j<8;j++)
				if((buffer[i]>>(7-j))&0x1)
					putpixel(x+j,y+i,color);
		s++;
		x+=10;
   }
	fclose(fp);
}
/*
void prt_asc16_ch( int x,int y,char s,unsigned int color)		//????????????
{

	FILE *  fp=NULL;
	int i=0;
	int j=0;
	unsigned long offset=0;
	char buffer[16]={0};
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //???????��???��?????
						  0x02,0x01};
	if ((fp=fopen("hzk\\ASC16","rb"))==NULL)
	{
                  printf("asc16 wrong!");
				  getch();		
                     exit(1);
	}
	offset=s * 16L;                         	//????��????
	fseek(fp,offset,0);
	fread(buffer,16,1,fp);                        	//??????????	
	for(i=0;i<16;i++)
	{
		for(j=0;j<8;j++)
		{
			if((mask[j] & buffer[i])!=0)    	
			{
				putpixel(x+j,y+i,color);
			}
		}
	}
	fclose(fp);
}
	*/

void Read_Asc16(char key,unsigned char *buffer)
{
    unsigned long offset=0;
	FILE*fp=NULL;
	if ((fp=fopen("hzk\\ASC16","rb"))==NULL)
	{
                  printf("asc16 wrong!");
				  getch();		
                     exit(1);
	}
	offset=key* 16L;
	fseek(fp,offset,0);
	fread(buffer,16,1,fp);              	
	fclose(fp);
}

void Put_Asc16(int x,int y,char key,unsigned int color)
{
    int i=0;
	int j=0;
    unsigned char buffer[16];
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04, 
						  0x02,0x01};
    Read_Asc16(key,buffer);
    for(i=0;i<16;i++)
        for(j=0;j<8;j++)
            if((mask[j] & buffer[i])!=0)
                putpixel(x+i,y+j,color);
}

/*??????????????*/
void Put_Asc16_Size(int x,int y,int xsize,int ysize,char key,unsigned int color)
{
	int i=0;
	int j=0;
	int m=0;
	int n=0;
	unsigned char buffer[16]={0};
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //???????��???��?????
						  0x02,0x01};
	Read_Asc16(key,buffer);
	for(i=0;i<16;i++)
		for(j=0;j<8;j++)
	        for(m=1;m<=ysize;m++)
				for(n=1;n<=xsize;n++)
					if((mask[j] & buffer[i])!=0)
				        putpixel(x+j*xsize+n,y+m+i*ysize,color);
}

/*?????????????????????*/
void put_asc16_size(int x,int y,int xsize,int ysize,char *s,unsigned int color )
{
    int i=0;
    for(i=0;s[i]!=0;i++)
    {
		Put_Asc16_Size(x+i*xsize*8,y,xsize,ysize,s[i],color);
    }
}

/*????????????*/
void put_asc16_number_size(int x,int y,int xsize,int ysize,int n,unsigned int color )
{
	char *s=0;
	int i=0;
	itoa(n,s,10);
    for(i=0;s[i]!=0;i++)
    {
		Put_Asc16_Size(x+i*xsize*8,y,xsize,ysize,s[i],color);
    }
}

/*????????????,l????????*/
void put_asc16_number_size_coverd(int x,int y,int xsize,int ysize,int l,int n,unsigned int color )
{
	char *s=0;
	int i=0;
	itoa(n,s,10);
	for(i=0;i<l;i++)
	{
		setcolor(getpixel(x+i,y-1));
		line(x+i,y,x+i,y+16*ysize);
	}
    for(i=0;s[i]!=0;i++)
    {
		Put_Asc16_Size(x+i*xsize*8,y,xsize,ysize,s[i],color);
    }
}

void prt_hz16_size(int x, int y, int xsize,int ysize,char *s, unsigned int color, char * name)  
{
	FILE * fp;
	char buffer[32];                                          //???????16?????32��???
	int i=0;
	int j=0;
	int m=0;
	int n=0;
	unsigned char qh=0;          	//??????????��???????
	unsigned char wh=0;    
	unsigned long offset=0;                                     //???��????
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //???????��???��?????
						  0x02,0x01};
	if((fp=fopen(name,"rb"))==NULL)
	{
		printf("Can't open hzk16!");
		getch();
		exit(0);
	}
	while(*s!=0)                                         //???????��?????????
    {
		qh=* s-160;                                       //?????????��??
        wh=*(s+1) -160;
        offset=(94L*(qh-1)+(wh-1))*32;                     //???????????
        fseek(fp,offset, 0);                        //?????????��???????��??
        fread(buffer, 32, 1, fp);                          //??????��??????
        for(i=0;i<16;i++)                                  //?????????????????
		{
			for(j=0;j<16;j++)
			{
				if((mask[j%8] & buffer[i*2+j/8])!=0)
				{
					for(m=0;m<xsize;m++)
					{
						for(n=0;n<ysize;n++)
					    {
							putpixel(x+j*xsize+m,y+i*ysize+n,color);
        				}
					}
				}
			}
		}
	    x+=16*xsize;                                          //?????????????16*xsize
		s+=2;                                           //????????????
    }
    fclose(fp);
}


/*输出既有16*16汉字又有16*16asc字符的字符串函数，x,y表示汉字输出位置，xsize,ysize为放大倍数，s为混合字符串，
color表示字符颜色，name 为汉字库文件路径，即字体信息*/
void show_text_16(int x, int y, char *s, unsigned int color, char * name)
{
	FILE * fp1=NULL;
	FILE * fp2=NULL;
	char buffer1[16]={0};                                     
	char buffer2[32]={0};                                          
	int i=0;
	int j=0;                                                  
    unsigned char wh=0;
	unsigned char qh=0;                                     
	unsigned long offset=0;                             
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,  
						  0x02,0x01};
	if ((fp1=fopen("hzk\\ASC16","rb"))==NULL)
	{
        closegraph();
		printf("asc16 wrong!");		
        getch();            
		exit(1);
	}
	if((fp2=fopen(name,"rb"))==NULL)
	{
		closegraph();
		printf("Can't open hzk16!");
		getch();
		exit(0);
	}
 
	while(*s)
    {
        if((*s&0x80)==0)//若该字符字节最高位为0，表明该字节ASCII码，输出字符
		{
			offset=*s * 16L;                         	
	        fseek(fp1,offset,0);
	        fread(buffer1,16,1,fp1); 
		    for(i=0;i<16;i++) 
				for(j=0;j<8;j++)
					if(mask[j]&buffer1[i])
						putpixel(x+j,y+2+i,color); 
						//y+2*ysize是为了平衡汉字与英文字符的高度

			x+=8; 
			s++;
		}		
		else if(*s&0x80) //若该字符字节最高位为1，表明该字节为汉字内码一部分，输出汉字  
		{
			qh=* s-160;                                     
    	    wh=*(s+1) -160;
     	    offset=(94L*(qh-1)+(wh-1))*32;
   	   	    fseek(fp2,offset, 0);    
  	        fread(buffer2, 32, 1, fp2);
  	        for(i=0;i<16;i++) 
				for(j=0;j<16;j++)
					if((mask[j%8] & buffer2[i*2+j/8])!=0)
						putpixel(x+j,y+i,color);

			x+=16;
			s+=2;
        }
	}
    fclose(fp1);
	fclose(fp2);
}	


/*输出既有24*24汉字又有32*32 asc字符的字符串函数，x,y表示汉字输出位置，s为混合字符串，
color表示字符颜色，name 为汉字库文件路径，即字体信息*/
void prt_hz24_asc32(int x, int y,char *s, unsigned int color, char * name)
{
	FILE * fp1=NULL;
	FILE * fp2=NULL;
	char buffer1[16]={0}; 
	char buffer2[72]={0}; 
	int i=0;
	int j=0;
	int m=0;
	int n=0;              
	unsigned char qh=0;
    unsigned char wh=0;                                    //????????????��??
	unsigned long offset=0;                               //???��????
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //???????��??????��?????
						  0x02,0x01};
	if ((fp1=fopen("hzk\\ASC16","rb"))==NULL)
	{
        closegraph();
		printf("asc16 wrong!");		
        getch();            
		exit(1);
	}
	if((fp2=fopen(name,"rb"))==NULL)
	{
		closegraph();
		printf("Can't open hzk24!");
		getch();
		exit(0);
	}
	while(*s!=0)                                         //??????????��?????????
    {
        if((*s&0x80)==0)                               //?????????????��?0???????????ASCII????????
		{
			offset=*s * 16L;                         	//????��????
	        fseek(fp1,offset,0);
	        fread(buffer1,16,1,fp1);                //??????????
		    for(i=0;i<16;i++)                              //?????????????32*32???
			{
				for(j=0;j<8;j++)
				{
					if(mask[j]&buffer1[i])
					{
						for(m=0;m<2;m++)
						{
							for(n=0;n<2;n++)
						    {
	                            putpixel(x+j*2+m,y-2+i*2+n,color); //y-2??????????????????????
							}
						}
					}
				}
			}
			x+=8*2;           //?????????????16
			s++;		                //???????????
		}		
		else if((*s&0x80)!=0)                                     //?????????????��?1?????????????????????????????????  
		{
			qh=* s-160;                                       //?????????��??
    	    wh=*(s+1) -160;
     	    offset=(94L*(qh-1)+(wh-1))*72;  //???????????
   	   	    fseek(fp2,offset, 0);                        //?????????��???????��??
  	        fread(buffer2, 72, 1, fp2);                  //??????��??????
  	        for(i=0;i<24;i++)                               //?????????????????????
			{
				for(j=0;j<24;j++)
				{
					if((mask[j%8] & buffer2[i*3+j/8])!=0)
					{
						putpixel(x+j,y+i,color);
					}					
				}
			}
			x+=24;              //?????????????24
			s+=2;   			             //???????????
        }
	}
    fclose(fp1);
	fclose(fp2);
}	
