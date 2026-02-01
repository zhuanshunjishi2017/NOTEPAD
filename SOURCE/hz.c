#include "hz.h"

/*16λ�����������x,y��ʾ�������λ�ã�sΪ���ִ���color��ʾ������ɫ��
name Ϊ���ֿ��ļ�·������������Ϣ*/
void prt_hz16(int x, int y, char *s, unsigned int color, char * name) 
{
	FILE * fp=NULL;
	char buffer[32]={0};                                          //������ȡ16���ֵ�32λ��ģ
	int i=0;
	int j=0;
	unsigned char qh =0;     
    unsigned char wh =0; 	     //������λ��
	unsigned long offset=0;     //��������
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ�ÿһλ����Ϣ
						  0x02,0x01};
	if((fp=fopen(name,"rb"))==NULL)
	{
		printf("Can't open hzk16!");
		getch();
		exit(0);
	}
	while(*s)                                         //�����ִ�δ���꣬�����
    {
		qh=* s-160;                                       //�õ���������
        wh=*(s+1) -160;
        offset=(94*(qh-1)+(wh-1))*32L;                     //����λ����
        fseek(fp,offset, SEEK_SET);                        //���ֿ��ļ��в�������λ��
        fread(buffer, 32, 1, fp);                          //��ȡ��Ӧλ�õ���ģ
        for(i=0;i<16;i++)                                  //��ָ�������һ������
			{
				for(j=0;j<16;j++)
				{
					if((mask[j%8] & buffer[i*2+j/8])!=0)
					{
						putpixel(x+j,y+i,color);
					}
				}
			}
			x+=16;                                          //������������Ϊ16
			s+=2;                                           //��ȡ��һ������
    }
    fclose(fp);
}


/*(���ӳ�)24λ�����������x,y��ʾ�������λ�ã�sΪ���ִ���color��ʾ������ɫ��
name Ϊ���ֿ��ļ�·������������Ϣ*/
void prt_hz24(int x, int y,char * s, unsigned int color, char * name)    
{
	FILE * fp=NULL;
	char buffer[72]={0};                                            //������ȡ24���ֵ�72λ��ģ
	int i=0;
	int j=0;
	unsigned char qh=0;
	unsigned char wh=0;
	unsigned long offset=0;
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ�ÿһλ����Ϣ
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
        for(i=0; i<24; i++)                                 //���һ������
           for(j=0;j<24;j++)
			{
				if((mask[j%8] & buffer[i*3+j/8])!=0)
				{
					putpixel(x+j,y+i,color);
				}					
			}
        s+=2;
        x+=24;                                         //����������24
		delay(50);                                   //ʹÿ������������̿ɼ���������Ч��������
    }
    fclose(fp);
}




/*x,y��ʾ�������λ�ã�sΪ���ִ���color��ʾ������ɫ��
name Ϊ���ֿ��ļ�·������������Ϣ*/
void prt_hz24d(int x, int y,char * s, unsigned int color, char * name)    
{
	FILE * fp=NULL;
	char buffer[72]={0};                                             //������ȡ24���ֵ�72λ��ģ
	int i=0;
	int j=0;
	unsigned char qh=0;
	unsigned char wh=0;
	unsigned long offset=0;
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ�ÿһλ����Ϣ
						  0x02,0x01};
	if((fp=fopen(name,"rb"))==NULL)
	{
		printf("Can't open hzk24d!");
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
        for(i=0; i<24; i++)                                 //���һ������
           for(j=0;j<24;j++)
			{
				if((mask[j%8] & buffer[i*3+j/8])!=0)
				{
					putpixel(x+j,y+i,color);
				}					
			}
           s+=2;
           x+=24;                                         //����������24
    }
    fclose(fp);
}

void prt_asc16( int x,int y,char * s,unsigned int color)		//���һ��Ӣ�ĺ���
{

	FILE *  fp=NULL;
	int i=0;
	int j=0;
	unsigned long offset=0;
	char buffer[16]={0};
	if ((fp=fopen("hzk\\ASC16","rb"))==NULL)
	{
                  printf("asc16 wrong!");		
                     exit(1);
	}
	while(*s)
        { 
	offset=*s * 16L;                         	//����λ����
	fseek(fp,offset,0);
	fread(buffer,16,1,fp);                        	//������ģ��Ϣ
	
	for(i=0;i<16;i++)
	{
		for(j=0;j<8;j++)
		{
			if((buffer[i]>>(7-j))&0x1)    	//Ϊ1��λ��ʾ
			{
				putpixel(x+j,y+i,color);
			}
		}
	}
    s++;
    x+=10;
   }
	fclose(fp);
}

void prt_asc16_ch( int x,int y,char s,unsigned int color)		//���һ��Ӣ�ĺ���
{

	FILE *  fp=NULL;
	int i=0;
	int j=0;
	unsigned long offset=0;
	char buffer[16]={0};
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ�ÿһλ����Ϣ
						  0x02,0x01};
	if ((fp=fopen("hzk\\ASC16","rb"))==NULL)
	{
                  printf("asc16 wrong!");
				  getch();		
                     exit(1);
	}
	offset=s * 16L;                         	//����λ����
	fseek(fp,offset,0);
	fread(buffer,16,1,fp);                        	//������ģ��Ϣ	
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
	offset=key* 16L;                         	//����λ����
	fseek(fp,offset,0);
	fread(buffer,16,1,fp);                    //������ģ��Ϣ	
	fclose(fp);
}

void Put_Asc16(int x,int y,char key,unsigned int color)
{
    int i=0;
	int j=0;
    unsigned char buffer[16];
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ�ÿһλ����Ϣ
						  0x02,0x01};
    Read_Asc16(key,buffer);
    for(i=0;i<16;i++)
        for(j=0;j<8;j++)
            if((mask[j] & buffer[i])!=0)
                putpixel(x+i,y+j,color);
}

/*��ʾ�Ŵ���Ӣ���ַ�*/
void Put_Asc16_Size(int x,int y,int xsize,int ysize,char key,unsigned int color)
{
	int i=0;
	int j=0;
	int m=0;
	int n=0;
	unsigned char buffer[16]={0};
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ�ÿһλ����Ϣ
						  0x02,0x01};
	Read_Asc16(key,buffer);
	for(i=0;i<16;i++)
		for(j=0;j<8;j++)
	        for(m=1;m<=ysize;m++)
				for(n=1;n<=xsize;n++)
					if((mask[j] & buffer[i])!=0)
				        putpixel(x+j*xsize+n,y+m+i*ysize,color);
}

/*��ʾ�Ŵ���Ӣ�ĺ������ַ���*/
void put_asc16_size(int x,int y,int xsize,int ysize,char *s,unsigned int color )
{
    int i=0;
    for(i=0;s[i]!=0;i++)
    {
		Put_Asc16_Size(x+i*xsize*8,y,xsize,ysize,s[i],color);
    }
}

/*��ʾ�Ŵ�������*/
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

/*��ʾ�Ŵ�������,lΪ���ǳ���*/
void put_asc16_number_size_coverd(int x,int y,int xsize,int ysize,int l,int n,unsigned int color )
{
	char *s=0;
	int i=0;
	itoa(n,s,10);
	for(i=0;i<l;i++)
	{
		Line_Thick(x+i,y,x+i,y+16*ysize,1,Getpixel64k(x+i,y-1));
	}
    for(i=0;s[i]!=0;i++)
    {
		Put_Asc16_Size(x+i*xsize*8,y,xsize,ysize,s[i],color);
    }
}

/*x,y��ʾ�������λ�ã�xsize,ysizeΪ�Ŵ�����sΪ���ִ���color��ʾ������ɫ��name Ϊ���ֿ��ļ�·������������Ϣ*/
void prt_hz16_size(int x, int y, int xsize,int ysize,char *s, unsigned int color, char * name)  
{
	FILE * fp;
	char buffer[32];                                          //������ȡ16���ֵ�32λ��ģ
	int i=0;
	int j=0;
	int m=0;
	int n=0;
	unsigned char qh=0;          	//�������㺺��λ�ź�����
	unsigned char wh=0;    
	unsigned long offset=0;                                     //��¼λ����
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ�ÿһλ����Ϣ
						  0x02,0x01};
	if((fp=fopen(name,"rb"))==NULL)
	{
		printf("Can't open hzk16!");
		getch();
		exit(0);
	}
	while(*s!=0)                                         //�����ִ�δ���꣬�����
    {
		qh=* s-160;                                       //�������ź�λ��
        wh=*(s+1) -160;
        offset=(94L*(qh-1)+(wh-1))*32;                     //���㺺�ֵĵ�ַ��
        fseek(fp,offset, 0);                        //���ֿ��ļ��в�������λ��
        fread(buffer, 32, 1, fp);                          //��ȡ��Ӧλ�õ���ģ
        for(i=0;i<16;i++)                                  //��ָ�������һ������
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
	    x+=16*xsize;                                          //������������Ϊ16*xsize
		s+=2;                                           //��ȡ��һ������
    }
    fclose(fp);
}

/*�������16*16��������16*16asc�ַ����ַ���������x,y��ʾ�������λ�ã�xsize,ysizeΪ�Ŵ�����sΪ����ַ�����
color��ʾ�ַ���ɫ��name Ϊ���ֿ��ļ�·������������Ϣ*/
void prt_hz16_asc16_size(int x, int y, int xsize,int ysize,char *s, unsigned int color, char * name)
{
	FILE * fp1=NULL;
	FILE * fp2=NULL;
	char buffer1[16]={0};                                          //������ȡ16ascll�ַ���16λ��ģ
	char buffer2[32]={0};                                          //������ȡ16���ֵ�32λ��ģ
	int i=0;
	int j=0;
	int m=0;
	int n=0;                                                             //ѭ������
	unsigned char qh=0;
    unsigned char wh=0;                                    //�������㺺����λ��
	unsigned long offset=0;                               //��¼λ����
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ���ģÿһλ����Ϣ
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
 
	while(*s!=0)                                         //������ַ���δ���꣬�����
    {
        if((*s&0x80)==0)                               //�����ַ��ֽ����λΪ0���������ֽ�ASCII�룬����ַ�
		{
			offset=*s * 16L;                         	//����λ����
	        fseek(fp1,offset,0);
	        fread(buffer1,16,1,fp1);                //������ģ��Ϣ
		    for(i=0;i<16;i++)                         //��ָ�������һ���Ŵ����ַ�
			{
				for(j=0;j<8;j++)
				{
					if(mask[j]&buffer1[i])
					{
						for(m=0;m<xsize;m++)
						{
							for(n=0;n<ysize;n++)
						    {
	                            putpixel(x+j*xsize+m,y+2*ysize+i*ysize+n,color); //y+2*ysize��Ϊ��ƽ�⺺����Ӣ���ַ��ĸ߶�
							}
						}
					}
				}
			}
			x+=8*xsize;           //������������Ϊ8*xsize
			s++;		                //��ȡ��һ���ַ�
		}		
		else if((*s&0x80)!=0)                                     //�����ַ��ֽ����λΪ1���������ֽ�Ϊ��������һ���֣��������  
		{
			qh=* s-160;                                       //�������ź�λ��
    	    wh=*(s+1) -160;
     	    offset=(94L*(qh-1)+(wh-1))*32;  //���㺺�ֵĵ�ַ��
   	   	    fseek(fp2,offset, 0);                        //���ֿ��ļ��в�������λ��
  	        fread(buffer2, 32, 1, fp2);                  //��ȡ��Ӧλ�õ���ģ
  	        for(i=0;i<16;i++)                               //��ָ�������һ���Ŵ��ĺ���
			{
				for(j=0;j<16;j++)
				{
					if((mask[j%8] & buffer2[i*2+j/8])!=0)
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
			x+=16*xsize;              //������������Ϊ16*xsize
			s+=2;   			             //��ȡ��һ���ַ�
        }
	}
    fclose(fp1);
	fclose(fp2);
}	

/*�������24*24��������32*32 asc�ַ����ַ���������x,y��ʾ�������λ�ã�sΪ����ַ�����
color��ʾ�ַ���ɫ��name Ϊ���ֿ��ļ�·������������Ϣ*/
void prt_hz24_asc32(int x, int y,char *s, unsigned int color, char * name)
{
	FILE * fp1=NULL;
	FILE * fp2=NULL;
	char buffer1[16]={0};                                          //������ȡ12ascll�ַ���12λ��ģ
	char buffer2[72]={0};                                          //������ȡ24���ֵ�72λ��ģ
	int i=0;
	int j=0;
	int m=0;
	int n=0;                                                             //ѭ������
	unsigned char qh=0;
    unsigned char wh=0;                                    //�������㺺����λ��
	unsigned long offset=0;                               //��¼λ����
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ���ģÿһλ����Ϣ
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
	while(*s!=0)                                         //������ַ���δ���꣬�����
    {
        if((*s&0x80)==0)                               //�����ַ��ֽ����λΪ0���������ֽ�ASCII�룬����ַ�
		{
			offset=*s * 16L;                         	//����λ����
	        fseek(fp1,offset,0);
	        fread(buffer1,16,1,fp1);                //������ģ��Ϣ
		    for(i=0;i<16;i++)                              //��ָ�������һ��32*32�ַ�
			{
				for(j=0;j<8;j++)
				{
					if(mask[j]&buffer1[i])
					{
						for(m=0;m<2;m++)
						{
							for(n=0;n<2;n++)
						    {
	                            putpixel(x+j*2+m,y-2+i*2+n,color); //y-2��Ϊ��ƽ�⺺����Ӣ���ַ��ĸ߶�
							}
						}
					}
				}
			}
			x+=8*2;           //������������Ϊ16
			s++;		                //��ȡ��һ���ַ�
		}		
		else if((*s&0x80)!=0)                                     //�����ַ��ֽ����λΪ1���������ֽ�Ϊ��������һ���֣��������  
		{
			qh=* s-160;                                       //�������ź�λ��
    	    wh=*(s+1) -160;
     	    offset=(94L*(qh-1)+(wh-1))*72;  //���㺺�ֵĵ�ַ��
   	   	    fseek(fp2,offset, 0);                        //���ֿ��ļ��в�������λ��
  	        fread(buffer2, 72, 1, fp2);                  //��ȡ��Ӧλ�õ���ģ
  	        for(i=0;i<24;i++)                               //��ָ�������һ���Ŵ��ĺ���
			{
				for(j=0;j<24;j++)
				{
					if((mask[j%8] & buffer2[i*3+j/8])!=0)
					{
						putpixel(x+j,y+i,color);
					}					
				}
			}
			x+=24;              //������������Ϊ24
			s+=2;   			             //��ȡ��һ���ַ�
        }
	}
    fclose(fp1);
	fclose(fp2);
}	
	
/*��������12*24����ҷ��ţ�����*/
void RMB(int x,int y,int xsize,int ysize,unsigned color)
{
	int i=0;
	int j=0;
	int m=0;
	int n=0;  //ѭ������
	int RMB[24][12]={
	    {0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,0,0,0,1,1,1,1},
		{0,1,1,0,0,0,0,0,0,1,1,0},
		{0,1,1,0,0,0,0,0,0,1,0,0},
		{0,0,1,1,0,0,0,0,1,1,0,0},
		{0,0,0,1,0,0,0,0,1,0,0,0},
	    {0,0,0,1,1,0,0,1,1,0,0,0},
		{0,0,0,0,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
	    {1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
	    {0,0,0,1,1,1,1,1,1,0,0,0}}; //���������ͼ�������
		
	for(i=0;i<24;i++)
	{
		for(j=0;j<12;j++)
		{
			if(RMB[i][j]!=0)
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



