#ifndef YIELDSTRESS_H
#define YIELDSTRESS_H

#include<QDateTime>


//表格有5个温度调整段
#define StageNum 5


struct STAGE{           //对应某个阶段的起止时间，时长，起止温度等；起始时间为相对值0；最后两个成员为动态变化值
    int StageSquence;
    QDateTime StartTime;
    QDateTime EndTime;
//    QDateTime Duration;
    int Duration;       // 时长改为int型 单位为秒
    float StartTemptre;
    float EndTemptre;        //也作为作样设定目标温度
    float asymptote;          //渐近控温;
    float allowError;       // 允许温差
    float RepeatabilityErr;  //同一仪器不同时间段重复允许误差r%
    float ReproducibilityErr; //不同仪器同一实验的允许偏差R%
    bool Isdoing;        			 //该过程进行中为1，0为未开始
    bool Isdone;          			 //该阶段=1为已完成 0为未完成
};

extern struct STAGE StageRefValue[StageNum];     //将表格中的数据，初始化到结构体数组中
extern struct STAGE StageRefValue2[StageNum];


//一个杆的屈服应力与表观粘度测试结果
struct YieldStressValue_ApparentViscosity_TESTing{
    //QDateTime Duration;   //记录旋转时间
    int YieldStressDuration;       // 改为int记录旋转时间 精确到毫秒
    float YieldStressTurns;      //记录旋转圈数
    float YieldStressRotationSpeed;   //记录转速；
    float YieldStressValue;   //测量参数：屈服应力

    float ApparentViscosity;   //测量参数：表观粘度
    float ApparentViscosityDuration;   //表观粘度，测量参数：表观粘度
    float ApparentViscosityTurns;      //记录旋转圈数
    float ApparentViscosityRotationSpeed;  //记录转速；
    float ApparentViscosityValue;      //测量参数：表观粘度
    float Gr;//  相关系数，根据实际情况添加
    float Sr;
};

struct STAGEENDTEMPERATURE{
    float TemperatureSetting;     //阶段的目标温度,作样设定的目标温度；
    int  TableId;      //作样属于表格1or表格2；   可通过二维数组找到对应阶段的参数值；
    int StageSequence;      //作样属于哪个阶段结束的目标温度，该温度达到后，恒温作样；
    bool TargetTemOk;        //  目标温度是否达到=1为达到
    float TargetTemperature;  // 该过程是否为目标温度，如是，则不再降温，而是恒温稳定
};
struct STANDorTESToil_PARAMETER{
    // 两个QString 可以放在 struct TotalProcessState 里面
    QString EngineOilSample;          //机油样本名称
    QString TestEngineer;             //测试人,标油对应Administrators
    //QDateTime TestDateTime;                //测试时间
    // 测试时间用秒来记录
    int TestDateTime;
    int PoleSequence;             //温箱中9个杆的第几个
    float TemperatureSetting;     //作样设定的目标温度；
    float TemperatureActual;        //测试实际温度   标油；
    struct YieldStressValue_ApparentViscosity_TESTing OilYSAVParm;   //一行测试油品记录条目结果
      //根据情况添加....
};

extern struct STANDorTESToil_PARAMETER stageparameter;
//仪器运行的总体状态,定时更新，每分钟存入文件，作样恢复读入
struct TotalProcessState{
    int IsFirstStarting;       //程序运行会若干天，作样过程中，可能会系统和程序死机导致程序重启，程序重启时，读入上次存储的存储状态；首次读入时置1，重启继续时置0；
    int RestartSequenceNum;       //表示是一个完整作样的第几次重启，第一次置0，重启一次就累加1；
    QDateTime ProcedureStartTime;    //总程序启动时间，还没开始作样；
    //QDateTime TestingStartTime;      //程序启动后，开始作样第一次运行时的时间，作样过程中，程序重启继续上一次未完成的作样，该值不更新；
    // 用int代替
    int TestingStartTime;
    QDateTime CurrentTime;           //当前时间；
    float CurrentTemperature;   //当前温度；
    float CurrentPressure;
    struct STAGEENDTEMPERATURE CurrentStageSequence;      //当前属于12或9中某个阶段的数值；
    //QDateTime CurrentStageDoingTime;     //该阶段内已经持续的时间；
    // 用int 代替
    int CurrentStageDoingTime;
    //     StageDebugPIDSetting; //类似与之前的DebugPIDSetting，设置不断    变化的目标温度，记录当前温度，PID系数等；
    struct STAGEENDTEMPERATURE TargetStage; //目标阶段，12或9中某个阶段的数值，内含目标设定温度
    bool IsFinished;           //该作样是否正常结束，正常结束=1，未结束=0；与IsFirstStarting配合；
    struct STANDorTESToil_PARAMETER StandardOilPoleParameter[9];   //标油9个杆均需先验测定
    struct STANDorTESToil_PARAMETER TestOilPoleParameter[9];  //当前测试9根棒，分别测试的参数；
    int GeneralStage;
    int GeneralInstrumentState;    //0b 0000 0000 0000 0000;      //改状态初始值置零
};
extern struct TotalProcessState total_process_state;
extern struct TotalProcessState total_process_state2;
//标油测试参数，仅只针对-20°C

//初始化是，对结构体空间整体初始化0；
                  //   abcd efgh ijkl mnop
//A：阶段性过程（以下功能注释移到代码之中）：
// 16位的标志位和int比较 默认在16位前面补上16个0
#define INIT_Stage            0x0000 //初始状态

#define S1_Stage1_RISE_TEM      0x8000  //0:00~0:20 阶段 升温 0b1000 0000 0000 0000
#define S2_Stage1_HOLD_TEM      0xc000  //0:20~2:20 阶段保持 0b1100 0000 0000 0000
#define S3_Stage1_KEEP_TEM      0xe000  //2:20~2:40 阶段持续 0b1110 0000 0000 0000
#define S4_Stage1_REACTION_TEM      0xf000  //   阶段反应

#define FINISHED        0xffff

#define StageTargetEnd 0x0002    //温度达标后，开始恒温过程，与之前stage搭配 0b 0000 0000 0000 0010;

// 过程被中止
#define STOP_RUNNING    0xfff4

//是否还有其他阶段，若有不从字段？若无，出现其它阶段，均报错处理

//B:设备工作状态设备，设备状态B与阶段过程A配合；
#define IncubatorgWireHeatingAlcoholNoFlowing 0x8000    //温箱加热管加热，酒精不循环，对应清洗，及80°C的升温及恒温情况 0b 1000 0000 0000 0000;
#define IncubatorgIdleAlcoholFlowing          0x2000   //温箱加热管与二级板均空闲，酒精循环,给恒温箱降温到常温，持续时间10分钟？为一个阶段内的过度过程，降温一段时间后二级板制冷  0b0010 0000 0000 0000;
#define IncubatorErjbCoolingAlcoholFlowing    0x7000    //温箱二级板制冷,酒精可开始加热控温，酒精循环 0b0111 0000 0000 0000
#define IncubatorErjbCoolingAlcoholFlowingDj  0x7800    //温箱二级板制冷,酒精可开始加热控温，酒精循环，进入测旋转时间状态0b 0111 1000 0000 0000



//G：o p

//过程定义：
//示例1 if(timers.erjibanflag==0&&timers.cleanflag==0)
         //if(JiujUnCycleErjbIdle&QingxiUnstart==GeneralStage&（JiujCycleErjHtClStateMap|QingxiStateMap)
//示例2 if(timers.erjibanflag==2&&timers.erjibanqingxiflag==true&&  debugPIDsetting.temp_erjiban_current-qingxiwendu>-1&&timers.cleanflag==0&&timers.orderflag==0)
//   	    if(JiujUnCycleErjbHeating&QingxiIsDoing==G


//阶段的定义  0b abcd efgh igkl mnop...，分别对应12或9中的某个特定的阶段；

class YIELDSTRESS {
public:
    // QDateTime 统一的初始值     2019-01-01 00:00:01
    #define QDATETIMEINITVALUE  "20190101000001"
    // 初始温度 大于室温 小于50度 默认40度
    #define INITTEMPERATURE     25
    void stage_init(struct STAGE stageInfo[6]);
    // 仪器运行总状态 struct TotalProcessState 初始化
    void totalProcessStateInit(struct TotalProcessState*);

    void stageInitDebug(struct STAGE stageInfo[6]);
};



#endif // YIELDSTRESS_H
