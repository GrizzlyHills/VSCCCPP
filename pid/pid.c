#define AA_KPVALUE 150
#define AA_KIVALUE 100
#define AA_KDVALUE 30
typedef struct PID
{
    sint an_Ref;       //角度PID，角度设定值
    sint an_FeedBack;  //角度PID，角度反馈值
    sint an_PreError;  //角度PID，前一次，角度误差,,
    an_Ref - an_FeedBack
    sint an_PreDerror; //角度PID，前一次，角度误差之差，
    d_error - PreDerror;
    sint an_Kp; //角度PID，
    Ka = Kp
    sint an_Ki; //角度PID，
    Kb = Kp * (T / Ti)
                  sint an_Kd; //角度PID，
    sint an_PreU;             //舵机控制输出值}PID;
    PID sPID;                 //申请一个PID类型的变量
    void PIDInit(void)        //PID初始化
    {
        sPID.an_Ref = 0;
        sPID.an_FeedBack = 0;
        sPID.an_PreError = 0;
        sPID.an_PreDerror = 0;
        sPID.an_Kp = AA_KPVALUE;
        sPID.an_Ki = AA_KIVALUE;
        sPID.an_Kd = AA_KDVALUE;
        sPID.an_PreU = 0;
    }
    unsigned int PIDCalc(PID *pp) //返回值赋给舵机
    {
        sint error, d_error, dd_error;
        error = pp->an_Ref - pp->an_FeedBack;
        d_error = error - pp->an_PreError;
        dd_error = d_error - pp->an_PreDerror;
        pp->an_PreError = error;
        pp->an_PreDerror = d_error;
        pp->an_PreU += pp->an_Kp * error + pp->an_Ki * d_error + pp->an_Kd * dd_error;
        return (pp->an_PreU);
    }
    