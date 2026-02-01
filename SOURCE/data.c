#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void location_input(char* location_output[], int location_num)
{
    char* location[12] = 
    {
        "华科附小", "图书馆", "机械楼", "管理学院", "体育馆", 
        "南二门", "计算机学院", "船海学院", "中操场", "东二区宿舍", 
        "青年园", "学术交流中心"
    };

    // 为 location_output[location_num] 分配内存
    location_output[location_num] = malloc(strlen(location[location_num]) + 1);
    if (location_output[location_num] == NULL)
    {
        printf("内存分配失败！\n");
        return;
    }

    // 复制字符串
    strcpy(location_output[location_num], location[location_num]);
}
void violation_input(char* violation_output[12][4], int location, int violation)
{
    // 违停行为预存
    char* locations[12][4] = 
    {
        {"未按规定停车，堵塞消防通道", "车辆占用人行道", "车辆停在禁停区域", "车辆停在校园出入口"},
        {"车辆停在图书馆入口", "未按规定停车", "占用残疾人停车位", "车辆停在绿化带内"},
        {"车辆停在机械楼出入口", "未按规定停车", "车辆停在消防栓前", "车辆停在应急通道"},
        {"车辆停在管理学院入口", "未按规定停车", "占用教职工停车位", "车辆停在绿化带内"},
        {"车辆停在体育馆入口", "未按规定停车", "车辆停在应急通道", "车辆停在观众通道"},
        {"车辆停在南二门出入口", "未按规定停车", "车辆停在人行道上", "车辆停在禁停区域"},
        {"占用实验室设备装卸区", "停在学院正门台阶前", "占用新能源车充电位", "挤占教授专用停车区"},
        {"停放在试验池通道", "在学院交叉路口违停", "占用访客车位", "在消防栓前违规停车"},
        {"停放在运动场应急通道", "占用跑道周边缓冲区", "在观众席出入口停车", "挤占操场外围非机动车道"},
        {"堵塞宿舍楼消防通道", "占用垃圾清运专用车位", "在宿舍自行车棚前停车", "夜间违停于临时禁停区"},
        {"驶入园区绿地停车", "占用林间步行道", "在湖边观景平台违停", "停放在园内狭窄路段"},
        {"在会议车辆入口处停车", "停放在中心景观绿化带","堵塞交流人员进出通道","未按规定停车"}
    };

    // 为 violation_output[location][violation] 分配内存
    violation_output[location][violation] = malloc(strlen(locations[location][violation]) + 1);
    if (violation_output[location][violation] == NULL)
    {
        printf("内存分配失败！\n");
        return;
    }

    // 复制字符串
    strcpy(violation_output[location][violation], locations[location][violation]);
}