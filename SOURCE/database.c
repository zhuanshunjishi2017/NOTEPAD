#include"allfunc.h"
void data_select(char* username)
{
   
    FILE *fp;
    USERS temp;
    int found=0;
    if((fp=fopen("data.dat","rb+"))==NULL)
    {
        printf("error!\n");
        exit(0);
    }
    while(fread(&temp,sizeof(USERS),1,fp))
    {
        if(strcmp(temp.user_name,username)==0)
        {
            found=1;
            break;
        }
        
    }
    fclose(fp);
    if(found)
    {
        FILE *fp1;
        if((fp1=fopen("data1.dat","wb"))==NULL)
        {
            printf("error!\n");
            exit(0);
        }
        fwrite(&temp,sizeof(USERS),1,fp1);
        fclose(fp1);
    }
        
}
void data_reselect()
{
    FILE *fp, *fp1;
    USERS temp, temp1;
    long record_pos = 0;
    int found = 0;

    // 打开临时文件
    if ((fp = fopen("data1.dat", "rb")) == NULL) 
    {
        perror("无法打开临时文件");
        exit(EXIT_FAILURE);
    }
    fseek(fp, -(long)sizeof(USERS), SEEK_END); // 定位到文件末尾前的最后一个结构体
    // 读取临时数据
    if (fread(&temp, sizeof(USERS), 1, fp) != 1) 
    {
        fclose(fp);
        printf("临时文件读取失败\n");
        return;
    }
    fclose(fp);

    // 打开主文件
    if ((fp1 = fopen("data.dat", "rb+")) == NULL) 
    {
        perror("无法打开主文件");
        exit(EXIT_FAILURE);
    }

    // 查找匹配记录
    while ( fread(&temp1, sizeof(USERS), 1, fp1) == 1) 
    {
        if (strcmp(temp1.user_name, temp.user_name) == 0)
         {
            found = 1;
            record_pos = ftell(fp1) - sizeof(USERS);
        }
    }

    // 更新记录
    if (found) 
    {
        fseek(fp1, record_pos, SEEK_SET);
        if (fwrite(&temp, sizeof(USERS), 1, fp1) != 1) 
        {
            printf("记录更新失败\n");
        }
        fflush(fp1);
    } else {
        printf("未找到匹配用户记录\n");
    }

    fclose(fp1);
}
void find_and_print_carplate(const char *username)
{
    FILE *fp;
    USERS temp;
    int found = 0;

    // 打开 data.dat 文件
    if ((fp = fopen("data.dat", "rb")) == NULL) 
    {
        printf("无法打开文件 data.dat\n");
        return;
    }

    // 遍历文件，查找匹配的用户
    while (fread(&temp, sizeof(USERS), 1, fp) == 1) 
    {

        if (strcmp(temp.user_name, username) == 0) 
        {
            found = 1;
            break;
        }
    }
    fclose(fp);

    // 如果找到用户，输出车牌号
    if (found) 
    {
        printf("用户名: %s\n", temp.user_name);
        printf("车牌号: %s\n", temp.carboard);

        // 在图形界面中显示车牌号
        prt_hz16_asc16_size(150, 300, 3, 3, temp.carboard, 0x000000, "HZK\\hzk16");
    } else 
    {
        printf("未找到用户名为 %s 的用户记录！\n", username);
    }
}