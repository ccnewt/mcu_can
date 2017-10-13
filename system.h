#ifndef SYSTEM_H
#define	SYSTEM_H
/******************************************************************************/
/* System Level #define Macros                                                */
/******************************************************************************/

/* TODO Define system operating frequency */

/* Microcontroller MIPs (FCY) */
#define SYS_FREQ        120000000L
#define FCY             SYS_FREQ/2

typedef struct tagSYSTEMREQ {
  unsigned FAULT_REQ:1;
  unsigned QUICK_SET:1;
  unsigned WARN_REQ:1;
  unsigned FSM_REQ:1;
  unsigned HMI2MCU_UPD_REQ:1;
  unsigned MCU2HMI_UPDREQ:1;
  unsigned CAN_CMD:1;  //CAN命令请求处理位
} SYSREQBITS;

typedef struct tagCAN_CAM_INFO
{
    unsigned CMD_Operate:1; //????
    unsigned CMD_Read_Out1:1; //????1-5
    unsigned CMD_Read_OUt2:1;
    unsigned CMD_Read_OUt3:1;
    unsigned CMD_Read_OUt4:1;
    unsigned CMD_Read_OUt5:1;
    unsigned CMD_Set_Value1:1; //????1-5
    unsigned CMD_Set_Value2:1;
    unsigned CMD_Set_Value3:1;
    unsigned CMD_Set_Value4:1;
    unsigned CMD_Set_Value5:1;
} CAN_CMD_INFO;

extern SYSREQBITS  __attribute__((near)) SYSREQBits;
extern CAN_CMD_INFO __attribute__((near)) CAN_CMD_Infobits;
/******************************************************************************/
/* System Function Prototypes                                                 */
/******************************************************************************/

/* Custom oscillator configuration funtions, reset source evaluation
functions, and other non-peripheral microcontroller initialization functions
go here. */

void ConfigureOscillator(void); /* Handles clock switching/osc initialization */

#endif