/*******************************************************************************
* File Name: RMotorPwm.h  
* Version 3.0
*
* Description:
*  Contains the prototypes and constants for the functions available to the 
*  PWM user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PWM_RMotorPwm_H)
#define CY_PWM_RMotorPwm_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 RMotorPwm_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define RMotorPwm_Resolution 16u
#define RMotorPwm_UsingFixedFunction 1u
#define RMotorPwm_DeadBandMode 0u
#define RMotorPwm_KillModeMinTime 0u
#define RMotorPwm_KillMode 1u
#define RMotorPwm_PWMMode 0u
#define RMotorPwm_PWMModeIsCenterAligned 0u
#define RMotorPwm_DeadBandUsed 0u
#define RMotorPwm_DeadBand2_4 0u

#if !defined(RMotorPwm_PWMUDB_genblk8_stsreg__REMOVED)
    #define RMotorPwm_UseStatus 0u
#else
    #define RMotorPwm_UseStatus 0u
#endif /* !defined(RMotorPwm_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(RMotorPwm_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define RMotorPwm_UseControl 1u
#else
    #define RMotorPwm_UseControl 0u
#endif /* !defined(RMotorPwm_PWMUDB_genblk1_ctrlreg__REMOVED) */
#define RMotorPwm_UseOneCompareMode 1u
#define RMotorPwm_MinimumKillTime 1u
#define RMotorPwm_EnableMode 0u

#define RMotorPwm_CompareMode1SW 0u
#define RMotorPwm_CompareMode2SW 0u

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_0 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define RMotorPwm__B_PWM__DISABLED 0
#define RMotorPwm__B_PWM__ASYNCHRONOUS 1
#define RMotorPwm__B_PWM__SINGLECYCLE 2
#define RMotorPwm__B_PWM__LATCHED 3
#define RMotorPwm__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define RMotorPwm__B_PWM__DBMDISABLED 0
#define RMotorPwm__B_PWM__DBM_2_4_CLOCKS 1
#define RMotorPwm__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define RMotorPwm__B_PWM__ONE_OUTPUT 0
#define RMotorPwm__B_PWM__TWO_OUTPUTS 1
#define RMotorPwm__B_PWM__DUAL_EDGE 2
#define RMotorPwm__B_PWM__CENTER_ALIGN 3
#define RMotorPwm__B_PWM__DITHER 5
#define RMotorPwm__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define RMotorPwm__B_PWM__LESS_THAN 1
#define RMotorPwm__B_PWM__LESS_THAN_OR_EQUAL 2
#define RMotorPwm__B_PWM__GREATER_THAN 3
#define RMotorPwm__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define RMotorPwm__B_PWM__EQUAL 0
#define RMotorPwm__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{
    
    uint8 PWMEnableState;
       
    #if(!RMotorPwm_UsingFixedFunction)
        uint16 PWMUdb;               /* PWM Current Counter value  */
        #if(!RMotorPwm_PWMModeIsCenterAligned)
            uint16 PWMPeriod;
        #endif /* (!RMotorPwm_PWMModeIsCenterAligned) */
        #if (RMotorPwm_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (RMotorPwm_UseStatus) */
        
        /* Backup for Deadband parameters */
        #if(RMotorPwm_DeadBandMode == RMotorPwm__B_PWM__DBM_256_CLOCKS || \
            RMotorPwm_DeadBandMode == RMotorPwm__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */
        
        /* Backup Kill Mode Counter*/
        #if(RMotorPwm_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (RMotorPwm_KillModeMinTime) */
       
        /* Backup control register */
        #if(RMotorPwm_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (RMotorPwm_UseControl) */
        
    #endif /* (!RMotorPwm_UsingFixedFunction) */
   
}RMotorPwm_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/
 
void    RMotorPwm_Start(void) ;
void    RMotorPwm_Stop(void) ;

#if (RMotorPwm_UseStatus || RMotorPwm_UsingFixedFunction)
    void  RMotorPwm_SetInterruptMode(uint8 interruptMode) ;
    uint8 RMotorPwm_ReadStatusRegister(void) ;
#endif /* (RMotorPwm_UseStatus || RMotorPwm_UsingFixedFunction) */

#define RMotorPwm_GetInterruptSource() RMotorPwm_ReadStatusRegister()

#if (RMotorPwm_UseControl)
    uint8 RMotorPwm_ReadControlRegister(void) ; 
    void  RMotorPwm_WriteControlRegister(uint8 control) ;
#endif /* (RMotorPwm_UseControl) */

#if (RMotorPwm_UseOneCompareMode)
   #if (RMotorPwm_CompareMode1SW)
       void    RMotorPwm_SetCompareMode(uint8 comparemode) ;
   #endif /* (RMotorPwm_CompareMode1SW) */
#else
    #if (RMotorPwm_CompareMode1SW)
        void    RMotorPwm_SetCompareMode1(uint8 comparemode) ;
    #endif /* (RMotorPwm_CompareMode1SW) */
    #if (RMotorPwm_CompareMode2SW)
        void    RMotorPwm_SetCompareMode2(uint8 comparemode) ;
    #endif /* (RMotorPwm_CompareMode2SW) */
#endif /* (RMotorPwm_UseOneCompareMode) */

#if (!RMotorPwm_UsingFixedFunction)
    uint16   RMotorPwm_ReadCounter(void) ;
    uint16 RMotorPwm_ReadCapture(void) ;
    
	#if (RMotorPwm_UseStatus)
	        void RMotorPwm_ClearFIFO(void) ;
	#endif /* (RMotorPwm_UseStatus) */

    void    RMotorPwm_WriteCounter(uint16 counter) ;
#endif /* (!RMotorPwm_UsingFixedFunction) */

void    RMotorPwm_WritePeriod(uint16 period) ;
uint16 RMotorPwm_ReadPeriod(void) ;

#if (RMotorPwm_UseOneCompareMode)
    void    RMotorPwm_WriteCompare(uint16 compare) ;
    uint16 RMotorPwm_ReadCompare(void) ; 
#else
    void    RMotorPwm_WriteCompare1(uint16 compare) ;
    uint16 RMotorPwm_ReadCompare1(void) ; 
    void    RMotorPwm_WriteCompare2(uint16 compare) ;
    uint16 RMotorPwm_ReadCompare2(void) ; 
#endif /* (RMotorPwm_UseOneCompareMode) */


#if (RMotorPwm_DeadBandUsed)
    void    RMotorPwm_WriteDeadTime(uint8 deadtime) ;
    uint8   RMotorPwm_ReadDeadTime(void) ;
#endif /* (RMotorPwm_DeadBandUsed) */

#if ( RMotorPwm_KillModeMinTime)
    void RMotorPwm_WriteKillTime(uint8 killtime) ;
    uint8 RMotorPwm_ReadKillTime(void) ; 
#endif /* ( RMotorPwm_KillModeMinTime) */

void RMotorPwm_Init(void) ;
void RMotorPwm_Enable(void) ;
void RMotorPwm_Sleep(void) ;
void RMotorPwm_Wakeup(void) ;
void RMotorPwm_SaveConfig(void) ;
void RMotorPwm_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define RMotorPwm_INIT_PERIOD_VALUE        65535u
#define RMotorPwm_INIT_COMPARE_VALUE1      0u
#define RMotorPwm_INIT_COMPARE_VALUE2      63u
#define RMotorPwm_INIT_INTERRUPTS_MODE     (uint8)(((uint8)(0u << RMotorPwm_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                  (uint8)((uint8)(0u << RMotorPwm_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                  (uint8)((uint8)(0u << RMotorPwm_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                  (uint8)((uint8)(0u << RMotorPwm_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define RMotorPwm_DEFAULT_COMPARE2_MODE    (uint8)((uint8)1u << RMotorPwm_CTRL_CMPMODE2_SHIFT)
#define RMotorPwm_DEFAULT_COMPARE1_MODE    (uint8)((uint8)1u << RMotorPwm_CTRL_CMPMODE1_SHIFT)
#define RMotorPwm_INIT_DEAD_TIME           1u


/********************************
*         Registers
******************************** */

#if (RMotorPwm_UsingFixedFunction)
   #define RMotorPwm_PERIOD_LSB          (*(reg16 *) RMotorPwm_PWMHW__PER0)
   #define RMotorPwm_PERIOD_LSB_PTR      ( (reg16 *) RMotorPwm_PWMHW__PER0)
   #define RMotorPwm_COMPARE1_LSB        (*(reg16 *) RMotorPwm_PWMHW__CNT_CMP0)
   #define RMotorPwm_COMPARE1_LSB_PTR    ( (reg16 *) RMotorPwm_PWMHW__CNT_CMP0)
   #define RMotorPwm_COMPARE2_LSB        0x00u
   #define RMotorPwm_COMPARE2_LSB_PTR    0x00u
   #define RMotorPwm_COUNTER_LSB         (*(reg16 *) RMotorPwm_PWMHW__CNT_CMP0)
   #define RMotorPwm_COUNTER_LSB_PTR     ( (reg16 *) RMotorPwm_PWMHW__CNT_CMP0)
   #define RMotorPwm_CAPTURE_LSB         (*(reg16 *) RMotorPwm_PWMHW__CAP0)
   #define RMotorPwm_CAPTURE_LSB_PTR     ( (reg16 *) RMotorPwm_PWMHW__CAP0)
   #define RMotorPwm_RT1                 (*(reg8 *)  RMotorPwm_PWMHW__RT1)
   #define RMotorPwm_RT1_PTR             ( (reg8 *)  RMotorPwm_PWMHW__RT1)
      
#else
   #if (RMotorPwm_Resolution == 8u) /* 8bit - PWM */
	   
	   #if(RMotorPwm_PWMModeIsCenterAligned)
	       #define RMotorPwm_PERIOD_LSB      (*(reg8 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
	       #define RMotorPwm_PERIOD_LSB_PTR   ((reg8 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
	   #else
	       #define RMotorPwm_PERIOD_LSB      (*(reg8 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__F0_REG)
	       #define RMotorPwm_PERIOD_LSB_PTR   ((reg8 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__F0_REG)
	   #endif /* (RMotorPwm_PWMModeIsCenterAligned) */
	   
	   #define RMotorPwm_COMPARE1_LSB    (*(reg8 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__D0_REG)
	   #define RMotorPwm_COMPARE1_LSB_PTR ((reg8 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__D0_REG)
	   #define RMotorPwm_COMPARE2_LSB    (*(reg8 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
	   #define RMotorPwm_COMPARE2_LSB_PTR ((reg8 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
	   #define RMotorPwm_COUNTERCAP_LSB   (*(reg8 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__A1_REG)
	   #define RMotorPwm_COUNTERCAP_LSB_PTR ((reg8 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__A1_REG)
	   #define RMotorPwm_COUNTER_LSB     (*(reg8 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__A0_REG)
	   #define RMotorPwm_COUNTER_LSB_PTR  ((reg8 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__A0_REG)
	   #define RMotorPwm_CAPTURE_LSB     (*(reg8 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__F1_REG)
	   #define RMotorPwm_CAPTURE_LSB_PTR  ((reg8 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__F1_REG)
   
   #else
   		#if(CY_PSOC3) /* 8-bit address space */	
			#if(RMotorPwm_PWMModeIsCenterAligned)
		       #define RMotorPwm_PERIOD_LSB      (*(reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
		       #define RMotorPwm_PERIOD_LSB_PTR   ((reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
		    #else
		       #define RMotorPwm_PERIOD_LSB      (*(reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__F0_REG)
		       #define RMotorPwm_PERIOD_LSB_PTR   ((reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__F0_REG)
		    #endif /* (RMotorPwm_PWMModeIsCenterAligned) */
		   
		    #define RMotorPwm_COMPARE1_LSB    (*(reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__D0_REG)
		    #define RMotorPwm_COMPARE1_LSB_PTR ((reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__D0_REG)
		    #define RMotorPwm_COMPARE2_LSB    (*(reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
		    #define RMotorPwm_COMPARE2_LSB_PTR ((reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
		    #define RMotorPwm_COUNTERCAP_LSB   (*(reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__A1_REG)
		    #define RMotorPwm_COUNTERCAP_LSB_PTR ((reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__A1_REG)
		    #define RMotorPwm_COUNTER_LSB     (*(reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__A0_REG)
		    #define RMotorPwm_COUNTER_LSB_PTR  ((reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__A0_REG)
		    #define RMotorPwm_CAPTURE_LSB     (*(reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__F1_REG)
		    #define RMotorPwm_CAPTURE_LSB_PTR  ((reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__F1_REG)
		#else
			#if(RMotorPwm_PWMModeIsCenterAligned)
		       #define RMotorPwm_PERIOD_LSB      (*(reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
		       #define RMotorPwm_PERIOD_LSB_PTR   ((reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
		    #else
		       #define RMotorPwm_PERIOD_LSB      (*(reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
		       #define RMotorPwm_PERIOD_LSB_PTR   ((reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
		    #endif /* (RMotorPwm_PWMModeIsCenterAligned) */
		   
		    #define RMotorPwm_COMPARE1_LSB    (*(reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
		    #define RMotorPwm_COMPARE1_LSB_PTR ((reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
		    #define RMotorPwm_COMPARE2_LSB    (*(reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
		    #define RMotorPwm_COMPARE2_LSB_PTR ((reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
		    #define RMotorPwm_COUNTERCAP_LSB   (*(reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
		    #define RMotorPwm_COUNTERCAP_LSB_PTR ((reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
		    #define RMotorPwm_COUNTER_LSB     (*(reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
		    #define RMotorPwm_COUNTER_LSB_PTR  ((reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
		    #define RMotorPwm_CAPTURE_LSB     (*(reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
		    #define RMotorPwm_CAPTURE_LSB_PTR  ((reg16 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
		#endif
		
	   #define RMotorPwm_AUX_CONTROLDP1    (*(reg8 *) RMotorPwm_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)
       #define RMotorPwm_AUX_CONTROLDP1_PTR  ((reg8 *) RMotorPwm_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (RMotorPwm_Resolution == 8) */
   
   #define RMotorPwm_AUX_CONTROLDP0      (*(reg8 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)
   #define RMotorPwm_AUX_CONTROLDP0_PTR  ((reg8 *) RMotorPwm_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (RMotorPwm_UsingFixedFunction) */
   
#if(RMotorPwm_KillModeMinTime )
    #define RMotorPwm_KILLMODEMINTIME      (*(reg8 *) RMotorPwm_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define RMotorPwm_KILLMODEMINTIME_PTR   ((reg8 *) RMotorPwm_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (RMotorPwm_KillModeMinTime ) */

#if(RMotorPwm_DeadBandMode == RMotorPwm__B_PWM__DBM_256_CLOCKS)
    #define RMotorPwm_DEADBAND_COUNT      (*(reg8 *) RMotorPwm_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define RMotorPwm_DEADBAND_COUNT_PTR  ((reg8 *) RMotorPwm_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define RMotorPwm_DEADBAND_LSB_PTR    ((reg8 *) RMotorPwm_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define RMotorPwm_DEADBAND_LSB        (*(reg8 *) RMotorPwm_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(RMotorPwm_DeadBandMode == RMotorPwm__B_PWM__DBM_2_4_CLOCKS)
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (RMotorPwm_UsingFixedFunction)
        #define RMotorPwm_DEADBAND_COUNT        (*(reg8 *) RMotorPwm_PWMHW__CFG0) 
        #define RMotorPwm_DEADBAND_COUNT_PTR     ((reg8 *) RMotorPwm_PWMHW__CFG0)
        #define RMotorPwm_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << RMotorPwm_DEADBAND_COUNT_SHIFT)
        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define RMotorPwm_DEADBAND_COUNT_SHIFT   0x06u  
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define RMotorPwm_DEADBAND_COUNT        (*(reg8 *) RMotorPwm_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define RMotorPwm_DEADBAND_COUNT_PTR     ((reg8 *) RMotorPwm_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define RMotorPwm_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << RMotorPwm_DEADBAND_COUNT_SHIFT) 
        /* As defined by the verilog implementation of the Control Register */
        #define RMotorPwm_DEADBAND_COUNT_SHIFT   0x00u 
    #endif /* (RMotorPwm_UsingFixedFunction) */
#endif /* (RMotorPwm_DeadBandMode == RMotorPwm__B_PWM__DBM_256_CLOCKS) */



#if (RMotorPwm_UsingFixedFunction)
    #define RMotorPwm_STATUS                (*(reg8 *) RMotorPwm_PWMHW__SR0)
    #define RMotorPwm_STATUS_PTR            ((reg8 *) RMotorPwm_PWMHW__SR0)
    #define RMotorPwm_STATUS_MASK           (*(reg8 *) RMotorPwm_PWMHW__SR0)
    #define RMotorPwm_STATUS_MASK_PTR       ((reg8 *) RMotorPwm_PWMHW__SR0)
    #define RMotorPwm_CONTROL               (*(reg8 *) RMotorPwm_PWMHW__CFG0)
    #define RMotorPwm_CONTROL_PTR           ((reg8 *) RMotorPwm_PWMHW__CFG0)    
    #define RMotorPwm_CONTROL2              (*(reg8 *) RMotorPwm_PWMHW__CFG1)    
    #define RMotorPwm_CONTROL3              (*(reg8 *) RMotorPwm_PWMHW__CFG2)
    #define RMotorPwm_GLOBAL_ENABLE         (*(reg8 *) RMotorPwm_PWMHW__PM_ACT_CFG)
    #define RMotorPwm_GLOBAL_ENABLE_PTR       ( (reg8 *) RMotorPwm_PWMHW__PM_ACT_CFG)
    #define RMotorPwm_GLOBAL_STBY_ENABLE      (*(reg8 *) RMotorPwm_PWMHW__PM_STBY_CFG)
    #define RMotorPwm_GLOBAL_STBY_ENABLE_PTR  ( (reg8 *) RMotorPwm_PWMHW__PM_STBY_CFG)
  
  
    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define RMotorPwm_BLOCK_EN_MASK          RMotorPwm_PWMHW__PM_ACT_MSK
    #define RMotorPwm_BLOCK_STBY_EN_MASK     RMotorPwm_PWMHW__PM_STBY_MSK 
    /* Control Register definitions */
    #define RMotorPwm_CTRL_ENABLE_SHIFT      0x00u
    
    #define RMotorPwm_CTRL_CMPMODE1_SHIFT    0x04u  /* As defined by Register map as MODE_CFG bits in CFG2*/
    
    #define RMotorPwm_CTRL_DEAD_TIME_SHIFT   0x06u   /* As defined by Register map */

    /* Fixed Function Block Only CFG register bit definitions */
    #define RMotorPwm_CFG0_MODE              0x02u   /*  Set to compare mode */
    
    /* #define RMotorPwm_CFG0_ENABLE            0x01u */  /* Enable the block to run */
    #define RMotorPwm_CFG0_DB                0x20u   /* As defined by Register map as DB bit in CFG0 */

    /* Control Register Bit Masks */
    #define RMotorPwm_CTRL_ENABLE            (uint8)((uint8)0x01u << RMotorPwm_CTRL_ENABLE_SHIFT)
    #define RMotorPwm_CTRL_RESET             (uint8)((uint8)0x01u << RMotorPwm_CTRL_RESET_SHIFT)
    #define RMotorPwm_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << RMotorPwm_CTRL_CMPMODE2_SHIFT)
    #define RMotorPwm_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << RMotorPwm_CTRL_CMPMODE1_SHIFT)
    
    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define RMotorPwm_CTRL2_IRQ_SEL_SHIFT    0x00u       
    #define RMotorPwm_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << RMotorPwm_CTRL2_IRQ_SEL_SHIFT)  
    
    /* Status Register Bit Locations */
    #define RMotorPwm_STATUS_TC_SHIFT            0x07u   /* As defined by Register map as TC in SR0 */
    #define RMotorPwm_STATUS_CMP1_SHIFT          0x06u   /* As defined by the Register map as CAP_CMP in SR0 */
    
    /* Status Register Interrupt Enable Bit Locations */
    #define RMotorPwm_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)    
    #define RMotorPwm_STATUS_TC_INT_EN_MASK_SHIFT            (RMotorPwm_STATUS_TC_SHIFT - 4u)
    #define RMotorPwm_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)  
    #define RMotorPwm_STATUS_CMP1_INT_EN_MASK_SHIFT          (RMotorPwm_STATUS_CMP1_SHIFT - 4u)
    
    /* Status Register Bit Masks */
    #define RMotorPwm_STATUS_TC              (uint8)((uint8)0x01u << RMotorPwm_STATUS_TC_SHIFT)
    #define RMotorPwm_STATUS_CMP1            (uint8)((uint8)0x01u << RMotorPwm_STATUS_CMP1_SHIFT)
    
    /* Status Register Interrupt Bit Masks */
    #define RMotorPwm_STATUS_TC_INT_EN_MASK              (uint8)((uint8)RMotorPwm_STATUS_TC >> 4u)
    #define RMotorPwm_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)RMotorPwm_STATUS_CMP1 >> 4u)
    
    /*RT1 Synch Constants */
    #define RMotorPwm_RT1_SHIFT             0x04u
    #define RMotorPwm_RT1_MASK              (uint8)((uint8)0x03u << RMotorPwm_RT1_SHIFT)/* Sync TC and CMP bit masks */
    #define RMotorPwm_SYNC                  (uint8)((uint8)0x03u << RMotorPwm_RT1_SHIFT)
    #define RMotorPwm_SYNCDSI_SHIFT         0x00u
    #define RMotorPwm_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << RMotorPwm_SYNCDSI_SHIFT) /* Sync all DSI inputs */
    #define RMotorPwm_SYNCDSI_EN            (uint8)((uint8)0x0Fu << RMotorPwm_SYNCDSI_SHIFT) /* Sync all DSI inputs */
    

#else
    #define RMotorPwm_STATUS                (*(reg8 *) RMotorPwm_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define RMotorPwm_STATUS_PTR            ((reg8 *) RMotorPwm_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define RMotorPwm_STATUS_MASK           (*(reg8 *) RMotorPwm_PWMUDB_genblk8_stsreg__MASK_REG)
    #define RMotorPwm_STATUS_MASK_PTR       ((reg8 *) RMotorPwm_PWMUDB_genblk8_stsreg__MASK_REG)
    #define RMotorPwm_STATUS_AUX_CTRL       (*(reg8 *) RMotorPwm_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define RMotorPwm_CONTROL               (*(reg8 *) RMotorPwm_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define RMotorPwm_CONTROL_PTR           ((reg8 *) RMotorPwm_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    
    
    /***********************************
    *          Constants
    ***********************************/

    /* Control Register definitions */
    #define RMotorPwm_CTRL_ENABLE_SHIFT      0x07u
    #define RMotorPwm_CTRL_RESET_SHIFT       0x06u
    #define RMotorPwm_CTRL_CMPMODE2_SHIFT    0x03u
    #define RMotorPwm_CTRL_CMPMODE1_SHIFT    0x00u
    #define RMotorPwm_CTRL_DEAD_TIME_SHIFT   0x00u   /* No Shift Needed for UDB block */
    /* Control Register Bit Masks */
    #define RMotorPwm_CTRL_ENABLE            (uint8)((uint8)0x01u << RMotorPwm_CTRL_ENABLE_SHIFT)
    #define RMotorPwm_CTRL_RESET             (uint8)((uint8)0x01u << RMotorPwm_CTRL_RESET_SHIFT)
    #define RMotorPwm_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << RMotorPwm_CTRL_CMPMODE2_SHIFT)
    #define RMotorPwm_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << RMotorPwm_CTRL_CMPMODE1_SHIFT) 
    
    /* Status Register Bit Locations */
    #define RMotorPwm_STATUS_KILL_SHIFT          0x05u
    #define RMotorPwm_STATUS_FIFONEMPTY_SHIFT    0x04u
    #define RMotorPwm_STATUS_FIFOFULL_SHIFT      0x03u  
    #define RMotorPwm_STATUS_TC_SHIFT            0x02u
    #define RMotorPwm_STATUS_CMP2_SHIFT          0x01u
    #define RMotorPwm_STATUS_CMP1_SHIFT          0x00u
    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define RMotorPwm_STATUS_KILL_INT_EN_MASK_SHIFT          RMotorPwm_STATUS_KILL_SHIFT          
    #define RMotorPwm_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    RMotorPwm_STATUS_FIFONEMPTY_SHIFT    
    #define RMotorPwm_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      RMotorPwm_STATUS_FIFOFULL_SHIFT        
    #define RMotorPwm_STATUS_TC_INT_EN_MASK_SHIFT            RMotorPwm_STATUS_TC_SHIFT            
    #define RMotorPwm_STATUS_CMP2_INT_EN_MASK_SHIFT          RMotorPwm_STATUS_CMP2_SHIFT          
    #define RMotorPwm_STATUS_CMP1_INT_EN_MASK_SHIFT          RMotorPwm_STATUS_CMP1_SHIFT   
    /* Status Register Bit Masks */
    #define RMotorPwm_STATUS_KILL            (uint8)((uint8)0x00u << RMotorPwm_STATUS_KILL_SHIFT )
    #define RMotorPwm_STATUS_FIFOFULL        (uint8)((uint8)0x01u << RMotorPwm_STATUS_FIFOFULL_SHIFT)
    #define RMotorPwm_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << RMotorPwm_STATUS_FIFONEMPTY_SHIFT)
    #define RMotorPwm_STATUS_TC              (uint8)((uint8)0x01u << RMotorPwm_STATUS_TC_SHIFT)
    #define RMotorPwm_STATUS_CMP2            (uint8)((uint8)0x01u << RMotorPwm_STATUS_CMP2_SHIFT) 
    #define RMotorPwm_STATUS_CMP1            (uint8)((uint8)0x01u << RMotorPwm_STATUS_CMP1_SHIFT)
    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define RMotorPwm_STATUS_KILL_INT_EN_MASK            RMotorPwm_STATUS_KILL
    #define RMotorPwm_STATUS_FIFOFULL_INT_EN_MASK        RMotorPwm_STATUS_FIFOFULL
    #define RMotorPwm_STATUS_FIFONEMPTY_INT_EN_MASK      RMotorPwm_STATUS_FIFONEMPTY
    #define RMotorPwm_STATUS_TC_INT_EN_MASK              RMotorPwm_STATUS_TC
    #define RMotorPwm_STATUS_CMP2_INT_EN_MASK            RMotorPwm_STATUS_CMP2
    #define RMotorPwm_STATUS_CMP1_INT_EN_MASK            RMotorPwm_STATUS_CMP1
                                                          
    /* Datapath Auxillary Control Register definitions */
    #define RMotorPwm_AUX_CTRL_FIFO0_CLR     0x01u
    #define RMotorPwm_AUX_CTRL_FIFO1_CLR     0x02u
    #define RMotorPwm_AUX_CTRL_FIFO0_LVL     0x04u
    #define RMotorPwm_AUX_CTRL_FIFO1_LVL     0x08u
    #define RMotorPwm_STATUS_ACTL_INT_EN_MASK  0x10u /* As defined for the ACTL Register */
#endif /* RMotorPwm_UsingFixedFunction */

#endif  /* CY_PWM_RMotorPwm_H */


/* [] END OF FILE */
