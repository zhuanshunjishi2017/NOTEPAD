#include <allfunc.h>


// 绘制平复（中性）表情，32x32大小，整体为橙黄色
void draw_neutral32(int x, int y)
{
    // 绘制脸部
    Circlefill(x+16, y+16, 16, 0xFD00);
    // 绘制眼睛
    Circlefill(x+11, y+12, 3, 0x000000);
    Circlefill(x+21, y+12, 3, 0x000000);
    // 绘制中性直线嘴巴
    Line_Thick(x+10, y+24, x+22, y+24, 1, 0x000000);
}

// 绘制哭脸表情，32x32大小，整体为橙黄色
void draw_cry32(int x, int y)
{
    int j;
    // 绘制脸部
    Circlefill(x+16, y+16, 16, 0xFD00);
    // 绘制眼睛
    Circlefill(x+11, y+12, 3, 0x000000);
    Circlefill(x+21, y+12, 3, 0x000000);
    // 绘制下垂的嘴巴（略呈凹弧）
    Line_Thick(x+10, y+26, x+22, y+26, 1, 0x000000);
    // 拉长眼泪：在左眼和右眼下分别绘制多个小圆
    for(j = 0; j < 4; j++)  // 可根据需要调整循环次数
    {
        Circlefill(x+11, y+16 + j*2, 2, 0xCD5C5C);  // 左眼下的延长眼泪
        Circlefill(x+21, y+16 + j*2, 2, 0xCD5C5C);  // 右眼下的延长眼泪
    }
}

void draw_smiley32(int x, int y)
{
    // 绘制脸部：中心在 (x+16, y+16)，半径为16，橙黄色（假设 0xFD00 为橙黄色）
    Circlefill(x + 16, y + 16, 16, 0xFD00);
    
    // 计算尺寸比例（原 24×24 时，眼睛相对于中心偏移 (-4, -3) 和 (4, -3)，半径 2）
    // 32×32 时，比例因子约 1.33，所以眼睛偏移约为 (-5, -4) 和 (5, -4)，眼睛半径设为 3
    Circlefill(x + 16 - 5, y + 16 - 4, 3, 0x0000);  // 左眼，中心 (11,12)
    Circlefill(x + 16 + 5, y + 16 - 4, 3, 0x0000);  // 右眼，中心 (21,12)
    
    // 绘制笑弧
    // 原 24×24 时，笑弧顶点相对于脸心 (12,12) 为：(-5,3) -> (-2,6) -> (2,6) -> (5,3)；
    // 乘以比例因子 1.33 得到近似新相对坐标：(-7,4) -> (-3,8) -> (3,8) -> (7,4)
    // 加上新脸中心 (16,16) 得到绝对坐标：
    // P1: (16-7, 16+4) = (9,20)
    // P2: (16-3, 16+8) = (13,24)
    // P3: (16+3, 16+8) = (19,24)
    // P4: (16+7, 16+4) = (23,20)
    Line_Thick(x + 9,  y + 20, x + 13, y + 24, 1, 0x0000);
    Line_Thick(x + 13, y + 24, x + 19, y + 24, 1, 0x0000);
    Line_Thick(x + 19, y + 24, x + 23, y + 20, 1, 0x0000);
}

// 新增：绘制 24x24 笑脸函数，整体橙黄色，带黑色眼和笑弧
void draw_smiley24(int x, int y)
{
    // 绘制面部：填充圆，半径为12（直径24）
    // 颜色选用橙黄色（用 0xFD00 表示，5:6:5 模式下 R=31, G≈40, B=0）
    Circlefill(x + 12, y + 12, 12, 0xFD00);
    
    // 绘制左眼：小圆，半径为2，位于面部左上区域
    Circlefill(x + 8, y + 9, 2, 0x0000);
    
    // 绘制右眼
    Circlefill(x + 16, y + 9, 2, 0x0000);
    
    // 绘制笑弧（微笑）
    // 利用3条线段连接近似弧形：从 (x+7, y+15) -> (x+10, y+18) -> (x+14, y+18) -> (x+17, y+15)
    Line_Thick(x + 7,  y + 15, x + 10, y + 18, 1, 0x0000);
    Line_Thick(x + 10, y + 18, x + 14, y + 18, 1, 0x0000);
    Line_Thick(x + 14, y + 18, x + 17, y + 15, 1, 0x0000);
}



/* BC31兼容性改造说明：
   1. 所有变量声明前置
   2. 使用传统for循环语法
   3. 颜色参数改用unsigned short */
void DrawRMB32(int x0, int y0, int color)
{
    int y, i, d, x;        /* 循环变量前置声明 */
    int ypos;              /* 坐标计算中间量 */
    unsigned page_offset;  /* 显存分页偏移量 */

    

    /* 绘制垂直主干（居中） */
    for (y = 0; y < 32; y++) {
        /* 显存分页计算（BC31专用内存模型） */
        page_offset = ((unsigned)(y0 + y) << 10) + x0 + 16;
        _AX = FP_SEG((void far*)page_offset);
        _DX = FP_OFF((void far*)page_offset);
        asm mov dx,ax  /* 显存分页操作 */
        asm mov ax,0x4F05
        asm xor bx,bx
        asm int 0x10

        Putpixel64k(x0 + 16, y0 + y, color);
    }

    /* 绘制三层水平横杆 */
    for (i = 0; i < 3; i++) {
        ypos = 8 + i*8;

        /* 主横杆绘制 */
        for (x = 8; x < 25; x++) {
            Putpixel64k(x0 + x, y0 + ypos, color);
        }

        /* 顶部装饰斜线 */
        if (i == 0) {
            for (d = 0; d < 5; d++) {
                Putpixel64k(x0 + 16-d, y0 + ypos-d, color);
                Putpixel64k(x0 + 16+d, y0 + ypos-d, color);
            }
        }

        /* 底部装饰斜线 */
        if (i == 2) {
            for (d = 0; d < 5; d++) {
                Putpixel64k(x0 + 16-d, y0 + ypos+d, color);
                Putpixel64k(x0 + 16+d, y0 + ypos+d, color);
            }
        }
    }

    /* 强化中间交叉区域 */
    for (y = 14; y < 19; y++) {
        for (x = 14; x < 19; x++) {
            Putpixel64k(x0 + x, y0 + y, color);
        }
    }
}//画出对勾
/* 新增的勾选标记绘制函数 */
void DrawCheckmark(int x, int y, int size, int color)
{
    /* 参数说明：
       x,y    - 中心点坐标
       size   - 标记尺寸（正方形边长）
       color  - 绘制颜色 */

    /* 默认尺寸处理 */
    /* 计算相对偏移量 */
    int offset = size/2;            // 半径
    int line_width = size/15 + 1;    // 动态线宽（最小1像素）
    /* 勾型路径坐标计算 */
    // 起始点：左上方1/4处
    int start_x = x - offset*3/4;
    int start_y = y - offset/4;
    // 中间转折点：中心偏右下方
    int mid_x = x - offset/5;
    int mid_y = y + offset/6;  
    // 结束点：右下方1/4处
    int end_x = x + offset*3/4;
    int end_y = y - offset*3/4;
	/* 默认尺寸处理 */
	if(size <= 0) size = 30;  
	/* 绘制三段式勾型 */
    Line_Thick(start_x, start_y, mid_x, mid_y, line_width, color);  // 左上到中间
    Line_Thick(mid_x, mid_y, end_x, end_y, line_width, color);      // 中间到右下
    
}

//抗锯齿优化
void DrawCheckmarkAA(int x, int y, int size, int color)
{
    // 使用两次不同透明度的绘制增强视觉效果
    DrawCheckmark(x, y, size, color & 0xFFE0); // 降低红色分量
    DrawCheckmark(x+1, y+1, size-2, color);    // 偏移绘制
}
//多分辨率适配
void AutoScaleCheckmark(int x, int y, int color)
{
    // 根据当前分辨率自动缩放
    int cur_mode = GetSVGA();
    int scale_factor = (cur_mode == 0x117) ? 2 : 1;
    DrawCheckmark(x, y, 30*scale_factor, color);
}


/*//画扫描线(左上角坐标，线长，线厚，颜色)
void draw_scanline(int x,int y,int l,int n,int color)
{
    register int i; // 使用寄存器变量加速循环
    for(i=0;i<n;i++)
    {
        Line1(x,y+i,x+l,y+i,color);
        color=color-10; // 保持颜色渐变效果
    }
}*/

//扫描操作(坐标，线厚，颜色，速度延迟)
/*void start_scan(int x1,int y1,int x2,int y2,int n,int color,int speeddelay)
{
    register int i; // 使用寄存器变量加速循环
    int temp=color;
    void *buffer=NULL;
    
    /* 精确计算缓冲区大小 */
    /*int width = x2 - x1 + 1;
    int height = n + 3;  // 包含安全余量
    size_t buffer_size = width * height * sizeof(unsigned int);
    
    /* 预计算固定值 */
    /*int scan_length = x2 - x1;
    int total_lines = y2 - y1 - n - 1;
    
    buffer=(unsigned int*)malloc(buffer_size);
    if(!buffer) return; // 添加内存分配检查
    
    /* 删除无效颜色判断 */
    /*Get_image(x1,y1-1,x2,y1+n+1,buffer);
    draw_scanline(x1,y1,scan_length,n,color);
    
    for(i=1;i<total_lines;i++)
    {
        Put_image(x1,y1+i-2,x2+2,y1+i+n,buffer);       // 优化图像恢复范围
        Get_image(x1,y1+i-1,x2+2,y1+i+n+1,buffer);     // 优化图像保存范围
        draw_scanline(x1,y1+i,scan_length,n,color--);// 修正线长计算错误
        
        /* 延迟移至循环末尾减少误差 */
       /* delay(speeddelay);
    }
    
    /* 优化最终图像恢复 */
    /*Put_image(x1,y1+total_lines-1,x2+2,y1+total_lines+n,buffer);
    free(buffer);
}
*/

//画扫描线(左上角坐标，线长，线厚，颜色)
void draw_scanline(int x,int y,int l,int n,int color)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        Line1(x,y+i,x+l,y+i,color);
        color=color-3;
    }
}

//扫描操作(坐标，线厚，颜色，速度延迟)
void start_scan(int x1,int y1,int x2,int y2,int n,int color,int speeddelay)
{
    int i=0;
    int temp=color;
    void *buffer=NULL;
    buffer=(unsigned int*)malloc(29000);
    if(temp-20==color)
    {
        color=temp;
    }
    Get_image(x1,y1-1,x2,y1+n+1,buffer);
    draw_scanline(x1,y1,x2-x1,n,color);
    for(i=1;i<y2-y1-n-1;i++)
    {
        Put_image(x1,y1+(i-1)-1,x2,y1+(i-1)+n+1,buffer);
        Get_image(x1,y1+i-1,x2,y1+i+n+1,buffer);
        draw_scanline(x1,y1+i,x2-x1-1,n,color--);
        delay(speeddelay);
    }
    Put_image(x1,y1+y2-y1-n-3,x2,y1+y2-y1-n-1+n,buffer);
    free(buffer);
    buffer=NULL;
}

//画出圆角矩形按钮(color1背景色，color2边框色,state是1为激活，0为普通)
void rounded_bar(int x1, int y1, int x2, int y2, int r ,int color1, int color2,int state)
{
	if(state==1)
	{
		color1=0xFFAAAA;
		color2=0x00FF00;
	}

	Circlefill(x1+r,y1+r,r+1,color2);
	Circlefill(x2-r,y1+r,r+1,color2);
	Circlefill(x1+r,y2-r,r+1,color2);
	Circlefill(x2-r,y2-r,r+1,color2);
	Line_Thick(x1,y1+r+1,x1,y2-r-1,1,color2 );
	Line_Thick(x2,y1+r+1,x2,y2-r-1,1,color2 );
	Line_Thick(x1+r+1,y1,x2-r-1,y1,1,color2 );
	Line_Thick(x1+r+1,y2,x2-r-1,y2,1,color2 );

	Circlefill(x1+r,y1+r,r,color1);
	Circlefill(x2-r,y1+r,r,color1);
	Circlefill(x1+r,y2-r,r,color1);
	Circlefill(x2-r,y2-r,r,color1);
	bar1(x1+r,y1,x2-r,y2,color1);
	bar1(x1,y1+r,x2,y2-r,color1);
}


//画出按键
void draw_botton(int x1 ,int y1,int x2,int y2,int Cowercolor,int Bordercolor)
{
	Cirbar(x1,y1,x2,y2, Bordercolor);
	Cirbar(x1,y1+2,x2,y2-2, Cowercolor);
}


//画出普通输入栏
void draw_commoninput(int x1,int y1,char *s)
{
	Line_Thick(x1, y1, x1 + 380, y1, 1, 0xBD32 );
	prt_hz16_size(x1 + 16, y1 - 46, 2, 2, s, 0xBD32, "HZK\\HZK16s");
}

//画出确认按钮
void draw_confirmbotton(int x1,int y1,char *s)
{
	draw_botton(x1, y1, x1+150, y1+55, 0xFFFFFF, 0x00FF);
	puthz(x1+12,y1+15,s, 24,25, 0x000000);
}


//画出勾选按钮(x,y为中心坐标，state是1为激活，0为普通,2为存在,-1为限制,3为起点,4为终点)
void draw_checkbutton(int x,int y,int state)
{
	bar1(x-16,y-16,x+16,y+16,0x000000);
	if(state==0)
	{
		bar1(x-15,y-15,x+15,y+15,0xFFFFFF);	
	}
	if(state==2)
	{
		bar1(x-15,y-15,x+15,y+15,0xFFAA);
	}
	if(state==1)
	{
		bar1(x-15,y-15,x+15,y+15,0xBBBB);
    	Line_Thick(x - 14, y - 2, x - 9, y - 2, 2, 0xFF0000);
		Line_Thick(x - 9, y - 2, x, y + 8, 2, 0xFF0000);
		Line_Thick(x + 12, y - 12, x, y + 8, 2, 0xFF0000);
	}
	if(state==-1)
	{
		bar1(x-15,y-15,x+15,y+15,0xFF19);
		Circlefill(x,y,13,0xFFAAAA);
		Circlefill(x,y,11,0xFF19);
		Line_Thick(x-14,y+11,x+11,y-14,1,0xFFFFFF);
		Line_Thick(x-11,y+14,x+14,y-11,1,0xFFFFFF);
		Line_Thick(x-14,y+14,x+14,y-14,2,0x000000);
	}
	if(state==3)
	{
		bar1(x-15,y-15,x+15,y+15,0xBDBD);
		puthz(x-1,y-1,"起",16,16,0xBB23);
		bar1(x-12,y+13,x-1,y+14,0x000000);
		bar1(x-7,y-12,x-6,y+13,0x000000);
		bar1(x-6,y-11,x+9,y-1,0xBBBF);
	}
	if(state==4)
	{
		bar1(x-15,y-15,x+15,y+15,0x7397F0);
		puthz(x-1,y-1,"终",16,16,0xBB23);
		bar1(x-12,y+13,x-1,y+14,0x000000);
		bar1(x-7,y-12,x-6,y+13,0x000000);
		bar1(x-6,y-11,x+9,y-1,0xFFAAAA);
	}
}


//画出彩线
void Line_Thick_color(int x1, int y1, int x2, int y2, int radius,unsigned int color)
{
	int	dx, dy;			/*直线x、y坐标差值*/
	int dx2, dy2;		/*加快运算速度的中间值*/
	int xinc, yinc;		/*判断x、y增加方向的符号值*/
	int d, dxy;			/*决策变量*/
	
	/*计算坐标差值和中间变量*/
	dx = abs(x2 - x1);
	dx2 = dx << 1;
	dy = abs(y2 - y1);
	dy2 = dy << 1;
	
	/*判断直线x坐标增加方向*/
	if (x2 > x1)
	{
		xinc = 1;
	}
	
	/*如果是竖直线*/
	else if (x2 == x1)
	{
		/*y坐标排序*/
		if (y1 > y2)
		{
			dx = y1;
			y1 = y2;
			y2 = dx;
		}
		
		/*画竖直线*/
		for (dx = y1; dx <= y2; dx++)
		{
			Circlefill(x1, dx, radius, color);
			color+=1;
		}
		
		return;
	}
	
	else
	{
		xinc = -1;
	}
	
	/*判断直线y坐标增加方向*/
	if (y2 > y1)
	{
		yinc = 1;
	}
	
	/*如果是水平线*/
	else if (y2 == y1)
	{
		Line3(x1, y1, x2, y1,radius, color);	
		color+=1;
		return;
	}
	
	else
	{
		yinc = -1;
	}
	
	/*******************************
	以下运用Bresenham算法生成直线。
	该算法是得到公认的成熟的快速算法。
	具体细节略去。
	*******************************/
	Circlefill(x1, y1, radius, color);
	color+=1;
	if (dx >= dy)
	{
		d = dy2 - dx;
		dxy = dy2 - dx2;
		
		while (dx--)
		{
			if (d <= 0)
			{
				d += dy2;
			}
			
			else
			{
				d += dxy;
				y1 += yinc;
			}
			
			x1 += xinc;
			Circlefill(x1, y1, radius, color);
			color+=1;
		}
	}
	
	else
	{
		d = dx2 - dy;
		dxy = dx2 - dy2;
		
		while (dy--)
		{
			if (d <= 0)
			{
				d += dx2;
			}
			
			else
			{
				d += dxy;
				x1 += xinc;
			}
			
			y1 += yinc;
			Circlefill(x1, y1, radius, color);
			color+=1;
		}
	}
}


