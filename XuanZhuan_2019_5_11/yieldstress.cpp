#include "yieldstress.h"

struct STAGE StageRefValue[StageNum];
struct STAGE StageRefValue2[StageNum];

struct TotalProcessState total_process_state;
struct TotalProcessState total_process_state2;
struct STANDorTESToil_PARAMETER stageparameter;
struct STAGEENDTEMPERATURE CurrentStageSequence={0,0,0,0,0};      //当前属于12或9中某个阶段的数值；
struct STAGEENDTEMPERATURE TargetStage={0,0,0,0,0};
//struct YieldStressValue_ApparentViscosity_TESTing OilYSAVParm={QDateTime::fromString(QString(20000101), "yyyyMMdd"),0,0,0,0,0,0,0,0,0,0};

void YIELDSTRESS::stage_init(struct STAGE stageInfo[5])
{
    stageInfo[0] = { 0,  QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"),
                        QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"), 2*60,
                        INITTEMPERATURE, (total_process_state.TargetStage.TargetTemperature - 10), 0, 1, 0, 0, 0, 0};
    stageInfo[1] = { 1,  QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"),
                        QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"), 2*60,
                        (total_process_state.TargetStage.TargetTemperature - 10), (total_process_state.TargetStage.TargetTemperature - 5), 0, 1, 0, 0, 0, 0};
    stageInfo[2] = { 2,  QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"),
                        QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"), 60,
                        (total_process_state.TargetStage.TargetTemperature - 5), total_process_state.TargetStage.TargetTemperature, 0, 1, 0, 0, 0, 0};
    stageInfo[3] = { 3,  QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"),
                        QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"), 6*60*60,
                        total_process_state.TargetStage.TargetTemperature, total_process_state.TargetStage.TargetTemperature, 0, 0.2, 0, 0, 0, 0};
    stageInfo[4] = { 4,  QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"),
                        QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"), 20*60,
                        total_process_state.TargetStage.TargetTemperature, INITTEMPERATURE, 0, 1, 0, 0, 0, 0};
}

void YIELDSTRESS::totalProcessStateInit(struct TotalProcessState* totalProcessState)
{
    // IsFirstStarting 默认置1
    totalProcessState->IsFirstStarting = 1;
    totalProcessState->RestartSequenceNum = 0;
    totalProcessState->ProcedureStartTime = QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss");
    totalProcessState->TestingStartTime = 0;
    totalProcessState->CurrentTime = QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss");
    // 当前温度默认0
    totalProcessState->CurrentTemperature = 0;
    totalProcessState->CurrentStageSequence = { 0, 0, 0, 0, 0};
    totalProcessState->CurrentStageDoingTime = 0;
    totalProcessState->CurrentPressure = 0;
    totalProcessState->TargetStage = { 0, 0, 0, 0, 0};
    totalProcessState->IsFinished = 0;
    totalProcessState->StandardOilPoleParameter[0] = { "", "", 0, 0, 0, 0,
                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    totalProcessState->StandardOilPoleParameter[1] = { "", "", 0, 0, 0, 0,
                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    totalProcessState->StandardOilPoleParameter[2] = { "", "", 0, 0, 0, 0,
                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    totalProcessState->StandardOilPoleParameter[3] = { "", "", 0, 0, 0, 0,
                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    totalProcessState->StandardOilPoleParameter[4] = { "", "", 0, 0, 0, 0,
                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    totalProcessState->StandardOilPoleParameter[5] = { "", "", 0, 0, 0, 0,
                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    totalProcessState->StandardOilPoleParameter[6] = { "", "", 0, 0, 0, 0,
                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    totalProcessState->StandardOilPoleParameter[7] = { "", "", 0, 0, 0, 0,
                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    totalProcessState->StandardOilPoleParameter[8] = { "", "", 0, 0, 0, 0,
                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    totalProcessState->TestOilPoleParameter[0] = { "", "", 0, 0, 0, 0,
                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    totalProcessState->TestOilPoleParameter[1] = { "", "", 0, 0, 0, 0,
                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    totalProcessState->TestOilPoleParameter[2] = { "", "", 0, 0, 0, 0,
                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    totalProcessState->TestOilPoleParameter[3] = { "", "", 0, 0, 0, 0,
                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    totalProcessState->TestOilPoleParameter[4] = { "", "", 0, 0, 0, 0,
                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    totalProcessState->TestOilPoleParameter[5] = { "", "", 0, 0, 0, 0,
                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    totalProcessState->TestOilPoleParameter[6] = { "", "", 0, 0, 0, 0,
                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    totalProcessState->TestOilPoleParameter[7] = { "", "", 0, 0, 0, 0,
                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    totalProcessState->TestOilPoleParameter[8] = { "", "", 0, 0, 0, 0,
                                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    totalProcessState->GeneralStage = 0;
    totalProcessState->GeneralInstrumentState = 0;
}

void YIELDSTRESS::stageInitDebug(struct STAGE stageInfo[5])
{
    // debug中 时间缩短比例 所有时间都乘以scale60 部分时间还要再乘以scale6 比如36小时
    int scale60 = 60;
    int scale6 = 6;

    // 恒温状态
    stageInfo[0] = { 0,  QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"),
                        QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"), 60,
                        INITTEMPERATURE, 140, 0, 1, 0, 0, 0, 0};
    stageInfo[1] = { 1,  QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"),
                        QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"), 60,
                        140, 145, 0, 1, 0, 0, 0, 0};
    stageInfo[2] = { 2,  QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"),
                        QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"), 60,
                        145, 150, 0, 1, 0, 0, 0, 0};
    stageInfo[3] = { 3,  QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"),
                        QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"), 30*60/scale6,
                        150, 150, 0, 0.2, 0, 0, 0, 0};
    stageInfo[4] = { 4,  QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"),
                        QDateTime::fromString(QString(QDATETIMEINITVALUE), "yyyyMMddHHmmss"), 20*60/scale6,
                        150, INITTEMPERATURE, 0, 1, 0, 0, 0, 0};
}
