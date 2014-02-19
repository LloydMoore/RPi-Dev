/*******************************************************************************
* File Name: LMotorPwm.h  
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

#if !defined(CY_PWM_LMotorPwm_H)
#define CY_PWM_LMotorPwm_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 LMotorPwm_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define LMotorPwm_Resolution 16u
#define LMotorPwm_UsingFixedFunction 1u
#define LMotorPwm_DeadBandMode 0u
#define LMotorPwm_KillModeMinTime 0u
#define LMotorPwm_KillMode 1u
#define LMotorPwm_PWMMode 0u
#define LMotorPwm_PWMModeIsCenterAligned 0u
#define LMotorPwm_DeadBandUsed 0u
#define LMotorPwm_DeadBand2_4 0u

#if !defined(LMotorPwm_PWMUDB_genblk8_stsreg__REMOVED)
    #define LMotorPwm_UseStatus 0u
#else
    #define LMotorPwm_UseStatus 0u
#endif /* !defined(LMotorPwm_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(LMotorPwm_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define LMotorPwm_UseControl 1u
#else
    #define LMotorPwm_UseControl 0u
#endif /* !defined(LMotorPwm_PWMUDB_genblk1_ctrlreg__REMOVED) */
#define LMotorPwm_UseOneCompareMode 1u
#define LMotorPwm_MinimumKillTime 1u
#define LMotorPwm_EnableMode 0u

#define LMotorPwm_CompareMode1SW 0u
#define LMotorPwm_CompareMode2SW 0u

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_0 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define LMotorPwm__B_PWM__DISABLED 0
#define LMotorPwm__B_PWM__ASYNCHRONOUS 1
#define LMotorPwm__B_PWM__SINGLECYCLE 2
#define LMotorPwm__B_PWM__LATCHED 3
#define LMotorPwm__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define LMotorPwm__B_PWM__DBMDISABLED 0
#define LMotorPwm__B_PWM__DBM_2_4_CLOCKS 1
#define LMotorPwm__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define LMotorPwm__B_PWM__ONE_OUTPUT 0
#define LMotorPwm__B_PWM__TWO_OUTPUTS 1
#define LMotorPwm__B_PWM__DUAL_EDGE 2
#define LMotorPwm__B_PWM__CENTER_ALIGN 3
#define LMotorPwm__B_PWM__DITHER 5
#define LMotorPwm__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define LMotorPwm__B_PWM__LESS_THAN 1
#define LMotorPwm__B_PWM__LESS_THAN_OR_EQUAL 2
#define LMotorPwm__B_PWM__GREATER_THAN 3
#define LMotorPwm__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define LMotorPwm__B_PWM__EQUAL 0
#define LMotorPwm__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{
    
    uint8 PWMEnableState;
       
    #if(!LMotorPwm_UsingFixedFunction)
        uint16 PWMUdb;               /* PWM Current Counter value  */
        #if(!LMotorPwm_PWMModeIsCenterAligned)
            uint16 PWMPeriod;
        #endif /* (!LMotorPwm_PWMModeIsCenterAligned) */
        #if (LMotorPwm_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (LMotorPwm_UseStatus) */
        
        /* Backup for Deadband parameters */
        #if(LMotorPwm_DeadBandMode == LMotorPwm__B_PWM__DBM_256_CLOCKS || \
            LMotorPwm_DeadBandMode == LMotorPwm__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */
        
        /* Backup Kill Mode Counter*/
        #if(LMotorPwm_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (LMotorPwm_KillModeMinTime) */
       
        /* Backup control register */
        #if(LMotorPwm_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (LMotorPwm_UseControl) */
        
    #endif /* (!LMotorPwm_UsingFixedFunction) */
   
}LMotorPwm_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/
 
void    LMotorPwm_Start(void) ;
void    LMotorPwm_Stop(void) ;

#if (LMotorPwm_UseStatus || LMotorPwm_UsingFixedFunction)
    void  LMotorPwm_SetInterruptMode(uint8 interruptMode) ;
    uint8 LMotorPwm_ReadStatusRegister(void) ;
#endif /* (LMotorPwm_UseStatus || LMotorPwm_UsingFixedFunction) */

#define LMotorPwm_GetInterruptSource() LMotorPwm_ReadStatusRegister()

#if (LMotorPwm_UseControl)
    uint8 LMotorPwm_ReadControlRegister(void) ; 
    void  LMotorPwm_WriteControlRegister(uint8 control) ;
#endif /* (LMotorPwm_UseControl) */

#if (LMotorPwm_UseOneCompareMode)
   #if (LMotorPwm_CompareMode1SW)
       void    LMotorPwm_SetCompareMode(uint8 comparemode) ;
   #endif /* (LMotorPwm_CompareMode1SW) */
#else
    #if (LMotorPwm_CompareMode1SW)
        void    LMotorPwm_SetCompareMode1(uint8 comparemode) ;
    #endif /* (LMotorPwm_CompareMode1SW) */
    #if (LMotorPwm_CompareMode2SW)
        void    LMotorPwm_SetCompareMode2(uint8 comparemode) ;
    #endif /* (LMotorPwm_CompareMode2SW) */
#endif /* (LMotorPwm_UseOneCompareMode) */

#if (!LMotorPwm_UsingFixedFunction)
    uint16   LMotorPwm_ReadCounter(void) ;
    uint16 LMotorPwm_ReadCapture(void) ;
    
	#if (LMotorPwm_UseStatus)
	        void LMotorPwm_ClearFIFO(void) ;
	#endif /* (LMotorPwm_UseStatus) */

    void    LMotorPwm_WriteCounter(uint16 counter) ;
#endif /* (!LMotorPwm_UsingFixedFunction) */

void    LMotorPwm_WritePeriod(uint16 period) ;
uint16 LMotorPwm_ReadPeriod(void) ;

#if (LMotorPwm_UseOneCompareMode)
    void    LMotorPwm_WriteCompare(uint16 compare) ;
    uint16 LMotorPwm_ReadCompare(void) ; 
#else
    void    LMotorPwm_WriteCompare1(uint16 compare) ;
    uint16 LMotorPwm_ReadCompare1(void) ; 
    void    LMotorPwm_WriteCompare2(uint16 compare) ;
    uint16 LMotorPwm_ReadCompare2(void) ; 
#endif /* (LMotorPwm_UseOneCompareMode) */


#if (LMotorPwm_DeadBandUsed)
    void    LMotorPwm_WriteDeadTime(uint8 deadtime) ;
    uint8   LMotorPwm_ReadDeadTime(void) ;
#endif /* (LMotorPwm_DeadBandUsed) */

#if ( LMotorPwm_KillModeMinTime)
    void LMotorPwm_WriteKillTime(uint8 killtime) ;
    uint8 LMotorPwm_ReadKillTime(void) ; 
#endif /* ( LMotorPwm_KillModeMinTime) */

void LMotorPwm_Init(void) ;
void LMotorPwm_Enable(void) ;
void LMotorPwm_Sleep(void) ;
void LMotorPwm_Wakeup(void) ;
void LMotorPwm_SaveConfig(void) ;
void LMotorPwm_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define LMotorPwm_INIT_PERIOD_VALUE        65535u
#define LMotorPwm_INIT_COMPARE_VALUE1      0u
#define LMotorPwm_INIT_COMPARE_VALUE2      63u
#define LMotorPwm_INIT_INTERRUPTS_MODE     (uint8)(((uint8)(0u << LMotorPwm_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                  (uint8)((uint8)(0u << LMotorPwm_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                  (uint8)((uint8)(0u << LMotorPwm_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                  (uint8)((uint8)(0u << LMotorPwm_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define LMotorPwm_DEFAULT_COMPARE2_MODE    (uint8)((uint8)1u << LMotorPwm_CTRL_CMPMODE2_SHIFT)
#define LMotorPwm_DEFAULT_COMPARE1_MODE    (uint8)((uint8)1u << LMotorPwm_CTRL_CMPMODE1_SHIFT)
#define LMotorPwm_INIT_DEAD_TIME           1u


/********************************
*         Registers
******************************** */

#if (LMotorPwm_UsingFixedFunction)
   #define LMotorPwm_PERIOD_LSB          (*(reg16 *) LMotorPwm_PWMHW__PER0)
   #define LMotorPwm_PERIOD_LSB_PTR      ( (reg16 *) LMotorPwm_PWMHW__PER0)
   #define LMotorPwm_COMPARE1_LSB        (*(reg16 *) LMotorPwm_PWMHW__CNT_CMP0)
   #define LMotorPwm_COMPARE1_LSB_PTR    ( (reg16 *) LMotorPwm_PWMHW__CNT_CMP0)
   #define LMotorPwm_COMPARE2_LSB        0x00u
   #define LMotorPwm_COMPARE2_LSB_PTR    0x00u
   #define LMotorPwm_COUNTER_LSB         (*(reg16 *) LMotorPwm_PWMHW__CNT_CMP0)
   #define LMotorPwm_COUNTER_LSB_PTR     ( (reg16 *) LMotorPwm_PWMHW__CNT_CMP0)
   #define LMotorPwm_CAPTURE_LSB         (*(reg16 *) LMotorPwm_PWMHW__CAP0)
   #define LMotorPwm_CAPTURE_LSB_PTR     ( (reg16 *) LMotorPwm_PWMHW__CAP0)
   #define LMotorPwm_RT1                 (*(reg8 *)  LMotorPwm_PWMHW__RT1)
   #define LMotorPwm_RT1_PTR             ( (reg8 *)  LMotorPwm_PWMHW__RT1)
      
#else
   #if (LMotorPwm_Resolution == 8u) /* 8bit - PWM */
	   
	   #if(LMotorPwm_PWMModeIsCenterAligned)
	       #define LMotorPwm_PERIOD_LSB      (*(reg8 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
	       #define LMotorPwm_PERIOD_LSB_PTR   ((reg8 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
	   #else
	       #define LMotorPwm_PERIOD_LSB      (*(reg8 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__F0_REG)
	       #define LMotorPwm_PERIOD_LSB_PTR   ((reg8 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__F0_REG)
	   #endif /* (LMotorPwm_PWMModeIsCenterAligned) */
	   
	   #define LMotorPwm_COMPARE1_LSB    (*(reg8 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__D0_REG)
	   #define LMotorPwm_COMPARE1_LSB_PTR ((reg8 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__D0_REG)
	   #define LMotorPwm_COMPARE2_LSB    (*(reg8 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
	   #define LMotorPwm_COMPARE2_LSB_PTR ((reg8 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
	   #define LMotorPwm_COUNTERCAP_LSB   (*(reg8 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__A1_REG)
	   #define LMotorPwm_COUNTERCAP_LSB_PTR ((reg8 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__A1_REG)
	   #define LMotorPwm_COUNTER_LSB     (*(reg8 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__A0_REG)
	   #define LMotorPwm_COUNTER_LSB_PTR  ((reg8 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__A0_REG)
	   #define LMotorPwm_CAPTURE_LSB     (*(reg8 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__F1_REG)
	   #define LMotorPwm_CAPTURE_LSB_PTR  ((reg8 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__F1_REG)
   
   #else
   		#if(CY_PSOC3) /* 8-bit address space */	
			#if(LMotorPwm_PWMModeIsCenterAligned)
		       #define LMotorPwm_PERIOD_LSB      (*(reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
		       #define LMotorPwm_PERIOD_LSB_PTR   ((reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
		    #else
		       #define LMotorPwm_PERIOD_LSB      (*(reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__F0_REG)
		       #define LMotorPwm_PERIOD_LSB_PTR   ((reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__F0_REG)
		    #endif /* (LMotorPwm_PWMModeIsCenterAligned) */
		   
		    #define LMotorPwm_COMPARE1_LSB    (*(reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__D0_REG)
		    #define LMotorPwm_COMPARE1_LSB_PTR ((reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__D0_REG)
		    #define LMotorPwm_COMPARE2_LSB    (*(reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
		    #define LMotorPwm_COMPARE2_LSB_PTR ((reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
		    #define LMotorPwm_COUNTERCAP_LSB   (*(reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__A1_REG)
		    #define LMotorPwm_COUNTERCAP_LSB_PTR ((reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__A1_REG)
		    #define LMotorPwm_COUNTER_LSB     (*(reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__A0_REG)
		    #define LMotorPwm_COUNTER_LSB_PTR  ((reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__A0_REG)
		    #define LMotorPwm_CAPTURE_LSB     (*(reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__F1_REG)
		    #define LMotorPwm_CAPTURE_LSB_PTR  ((reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__F1_REG)
		#else
			#if(LMotorPwm_PWMModeIsCenterAligned)
		       #define LMotorPwm_PERIOD_LSB      (*(reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
		       #define LMotorPwm_PERIOD_LSB_PTR   ((reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
		    #else
		       #define LMotorPwm_PERIOD_LSB      (*(reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
		       #define LMotorPwm_PERIOD_LSB_PTR   ((reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
		    #endif /* (LMotorPwm_PWMModeIsCenterAligned) */
		   
		    #define LMotorPwm_COMPARE1_LSB    (*(reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
		    #define LMotorPwm_COMPARE1_LSB_PTR ((reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
		    #define LMotorPwm_COMPARE2_LSB    (*(reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
		    #define LMotorPwm_COMPARE2_LSB_PTR ((reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
		    #define LMotorPwm_COUNTERCAP_LSB   (*(reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
		    #define LMotorPwm_COUNTERCAP_LSB_PTR ((reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
		    #define LMotorPwm_COUNTER_LSB     (*(reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
		    #define LMotorPwm_COUNTER_LSB_PTR  ((reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
		    #define LMotorPwm_CAPTURE_LSB     (*(reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
		    #define LMotorPwm_CAPTURE_LSB_PTR  ((reg16 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
		#endif
		
	   #define LMotorPwm_AUX_CONTROLDP1    (*(reg8 *) LMotorPwm_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)
       #define LMotorPwm_AUX_CONTROLDP1_PTR  ((reg8 *) LMotorPwm_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (LMotorPwm_Resolution == 8) */
   
   #define LMotorPwm_AUX_CONTROLDP0      (*(reg8 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)
   #define LMotorPwm_AUX_CONTROLDP0_PTR  ((reg8 *) LMotorPwm_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (LMotorPwm_UsingFixedFunction) */
   
#if(LMotorPwm_KillModeMinTime )
    #define LMotorPwm_KILLMODEMINTIME      (*(reg8 *) LMotorPwm_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define LMotorPwm_KILLMODEMINTIME_PTR   ((reg8 *) LMotorPwm_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (LMotorPwm_KillModeMinTime ) */

#if(LMotorPwm_DeadBandMode == LMotorPwm__B_PWM__DBM_256_CLOCKS)
    #define LMotorPwm_DEADBAND_COUNT      (*(reg8 *) LMotorPwm_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define LMotorPwm_DEADBAND_COUNT_PTR  ((reg8 *) LMotorPwm_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define LMotorPwm_DEADBAND_LSB_PTR    ((reg8 *) LMotorPwm_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define LMotorPwm_DEADBAND_LSB        (*(reg8 *) LMotorPwm_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(LMotorPwm_DeadBandMode == LMotorPwm__B_PWM__DBM_2_4_CLOCKS)
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (LMotorPwm_UsingFixedFunction)
        #define LMotorPwm_DEADBAND_COUNT        (*(reg8 *) LMotorPwm_PWMHW__CFG0) 
        #define LMotorPwm_DEADBAND_COUNT_PTR     ((reg8 *) LMotorPwm_PWMHW__CFG0)
        #define LMotorPwm_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << LMotorPwm_DEADBAND_COUNT_SHIFT)
        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define LMotorPwm_DEADBAND_COUNT_SHIFT   0x06u  
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define LMotorPwm_DEADBAND_COUNT        (*(reg8 *) LMotorPwm_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define LMotorPwm_DEADBAND_COUNT_PTR     ((reg8 *) LMotorPwm_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define LMotorPwm_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << LMotorPwm_DEADBAND_COUNT_SHIFT) 
        /* As defined by the verilog implementation of the Control Register */
        #define LMotorPwm_DEADBAND_COUNT_SHIFT   0x00u 
    #endif /* (LMotorPwm_UsingFixedFunction) */
#endif /* (LMotorPwm_DeadBandMode == LMotorPwm__B_PWM__DBM_256_CLOCKS) */



#if (LMotorPwm_UsingFixedFunction)
    #define LMotorPwm_STATUS                (*(reg8 *) LMotorPwm_PWMHW__SR0)
    #define LMotorPwm_STATUS_PTR            ((reg8 *) LMotorPwm_PWMHW__SR0)
    #define LMotorPwm_STATUS_MASK           (*(reg8 *) LMotorPwm_PWMHW__SR0)
    #define LMotorPwm_STATUS_MASK_PTR       ((reg8 *) LMotorPwm_PWMHW__SR0)
    #define LMotorPwm_CONTROL               (*(reg8 *) LMotorPwm_PWMHW__CFG0)
    #define LMotorPwm_CONTROL_PTR           ((reg8 *) LMotorPwm_PWMHW__CFG0)    
    #define LMotorPwm_CONTROL2              (*(reg8 *) LMotorPwm_PWMHW__CFG1)    
    #define LMotorPwm_CONTROL3              (*(reg8 *) LMotorPwm_PWMHW__CFG2)
    #define LMotorPwm_GLOBAL_ENABLE         (*(reg8 *) LMotorPwm_PWMHW__PM_ACT_CFG)
    #define LMotorPwm_GLOBAL_ENABLE_PTR       ( (reg8 *) LMotorPwm_PWMHW__PM_ACT_CFG)
    #define LMotorPwm_GLOBAL_STBY_ENABLE      (*(reg8 *) LMotorPwm_PWMHW__PM_STBY_CFG)
    #define LMotorPwm_GLOBAL_STBY_ENABLE_PTR  ( (reg8 *) LMotorPwm_PWMHW__PM_STBY_CFG)
  
  
    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define LMotorPwm_BLOCK_EN_MASK          LMotorPwm_PWMHW__PM_ACT_MSK
    #define LMotorPwm_BLOCK_STBY_EN_MASK     LMotorPwm_PWMHW__PM_STBY_MSK 
    /* Control Register definitions */
    #define LMotorPwm_CTRL_ENABLE_SHIFT      0x00u
    
    #define LMotorPwm_CTRL_CMPMODE1_SHIFT    0x04u  /* As defined by Register map as MODE_CFG bits in CFG2*/
    
    #define LMotorPwm_CTRL_DEAD_TIME_SHIFT   0x06u   /* As defined by Register map */

    /* Fixed Function Block Only CFG register bit definitions */
    #define LMotorPwm_CFG0_MODE              0x02u   /*  Set to compare mode */
    
    /* #define LMotorPwm_CFG0_ENABLE            0x01u */  /* Enable the block to run */
    #define LMotorPwm_CFG0_DB                0x20u   /* As defined by Register map as DB bit in CFG0 */

    /* Control Register Bit Masks */
    #define LMotorPwm_CTRL_ENABLE            (uint8)((uint8)0x01u << LMotorPwm_CTRL_ENABLE_SHIFT)
    #define LMotorPwm_CTRL_RESET             (uint8)((uint8)0x01u << LMotorPwm_CTRL_RESET_SHIFT)
    #define LMotorPwm_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << LMotorPwm_CTRL_CMPMODE2_SHIFT)
    #define LMotorPwm_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << LMotorPwm_CTRL_CMPMODE1_SHIFT)
    
    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define LMotorPwm_CTRL2_IRQ_SEL_SHIFT    0x00u       
    #define LMotorPwm_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << LMotorPwm_CTRL2_IRQ_SEL_SHIFT)  
    
    /* Status Register Bit Locations */
    #define LMotorPwm_STATUS_TC_SHIFT            0x07u   /* As defined by Register map as TC in SR0 */
    #define LMotorPwm_STATUS_CMP1_SHIFT          0x06u   /* As defined by the Register map as CAP_CMP in SR0 */
    
    /* Status Register Interrupt Enable Bit Locations */
    #define LMotorPwm_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)    
    #define LMotorPwm_STATUS_TC_INT_EN_MASK_SHIFT            (LMotorPwm_STATUS_TC_SHIFT - 4u)
    #define LMotorPwm_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)  
    #define LMotorPwm_STATUS_CMP1_INT_EN_MASK_SHIFT          (LMotorPwm_STATUS_CMP1_SHIFT - 4u)
    
    /* Status Register Bit Masks */
    #define LMotorPwm_STATUS_TC              (uint8)((uint8)0x01u << LMotorPwm_STATUS_TC_SHIFT)
    #define LMotorPwm_STATUS_CMP1            (uint8)((uint8)0x01u << LMotorPwm_STATUS_CMP1_SHIFT)
    
    /* Status Register Interrupt Bit Masks */
    #define LMotorPwm_STATUS_TC_INT_EN_MASK              (uint8)((uint8)LMotorPwm_STATUS_TC >> 4u)
    #define LMotorPwm_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)LMotorPwm_STATUS_CMP1 >> 4u)
    
    /*RT1 Synch Constants */
    #define LMotorPwm_RT1_SHIFT             0x04u
    #define LMotorPwm_RT1_MASK              (uint8)((uint8)0x03u << LMotorPwm_RT1_SHIFT)/* Sync TC and CMP bit masks */
    #define LMotorPwm_SYNC                  (uint8)((uint8)0x03u << LMotorPwm_RT1_SHIFT)
    #define LMotorPwm_SYNCDSI_SHIFT         0x00u
    #define LMotorPwm_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << LMotorPwm_SYNCDSI_SHIFT) /* Sync all DSI inputs */
    #define LMotorPwm_SYNCDSI_EN            (uint8)((uint8)0x0Fu << LMotorPwm_SYNCDSI_SHIFT) /* Sync all DSI inputs */
    

#else
    #define LMotorPwm_STATUS                (*(reg8 *) LMotorPwm_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define LMotorPwm_STATUS_PTR            ((reg8 *) LMotorPwm_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define LMotorPwm_STATUS_MASK           (*(reg8 *) LMotorPwm_PWMUDB_genblk8_stsreg__MASK_REG)
    #define LMotorPwm_STATUS_MASK_PTR       ((reg8 *) LMotorPwm_PWMUDB_genblk8_stsreg__MASK_REG)
    #define LMotorPwm_STATUS_AUX_CTRL       (*(reg8 *) LMotorPwm_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define LMotorPwm_CONTROL               (*(reg8 *) LMotorPwm_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define LMotorPwm_CONTROL_PTR           ((reg8 *) LMotorPwm_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    
    
    /***********************************
    *          Constants
    ***********************************/

    /* Control Register definitions */
    #define LMotorPwm_CTRL_ENABLE_SHIFT      0x07u
    #define LMotorPwm_CTRL_RESET_SHIFT       0x06u
    #define LMotorPwm_CTRL_CMPMODE2_SHIFT    0x03u
    #define LMotorPwm_CTRL_CMPMODE1_SHIFT    0x00u
    #define LMotorPwm_CTRL_DEAD_TIME_SHIFT   0x00u   /* No Shift Needed for UDB block */
    /* Control Register Bit Masks */
    #define LMotorPwm_CTRL_ENABLE            (uint8)((uint8)0x01u << LMotorPwm_CTRL_ENABLE_SHIFT)
    #define LMotorPwm_CTRL_RESET             (uint8)((uint8)0x01u << LMotorPwm_CTRL_RESET_SHIFT)
    #define LMotorPwm_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << LMotorPwm_CTRL_CMPMODE2_SHIFT)
    #define LMotorPwm_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << LMotorPwm_CTRL_CMPMODE1_SHIFT) 
    
    /* Status Register Bit Locations */
    #define LMotorPwm_STATUS_KILL_SHIFT          0x05u
    #define LMotorPwm_STATUS_FIFONEMPTY_SHIFT    0x04u
    #define LMotorPwm_STATUS_FIFOFULL_SHIFT      0x03u  
    #define LMotorPwm_STATUS_TC_SHIFT            0x02u
    #define LMotorPwm_STATUS_CMP2_SHIFT          0x01u
    #define LMotorPwm_STATUS_CMP1_SHIFT          0x00u
    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define LMotorPwm_STATUS_KILL_INT_EN_MASK_SHIFT          LMotorPwm_STATUS_KILL_SHIFT          
    #define LMotorPwm_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    LMotorPwm_STATUS_FIFONEMPTY_SHIFT    
    #define LMotorPwm_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      LMotorPwm_STATUS_FIFOFULL_SHIFT        
    #define LMotorPwm_STATUS_TC_INT_EN_MASK_SHIFT            LMotorPwm_STATUS_TC_SHIFT            
    #define LMotorPwm_STATUS_CMP2_INT_EN_MASK_SHIFT          LMotorPwm_STATUS_CMP2_SHIFT          
    #define LMotorPwm_STATUS_CMP1_INT_EN_MASK_SHIFT          LMotorPwm_STATUS_CMP1_SHIFT   
    /* Status Register Bit Masks */
    #define LMotorPwm_STATUS_KILL            (uint8)((uint8)0x00u << LMotorPwm_STATUS_KILL_SHIFT )
    #define LMotorPwm_STATUS_FIFOFULL        (uint8)((uint8)0x01u << LMotorPwm_STATUS_FIFOFULL_SHIFT)
    #define LMotorPwm_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << LMotorPwm_STATUS_FIFONEMPTY_SHIFT)
    #define LMotorPwm_STATUS_TC              (uint8)((uint8)0x01u << LMotorPwm_STATUS_TC_SHIFT)
    #define LMotorPwm_STATUS_CMP2            (uint8)((uint8)0x01u << LMotorPwm_STATUS_CMP2_SHIFT) 
    #define LMotorPwm_STATUS_CMP1            (uint8)((uint8)0x01u << LMotorPwm_STATUS_CMP1_SHIFT)
    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define LMotorPwm_STATUS_KILL_INT_EN_MASK            LMotorPwm_STATUS_KILL
    #define LMotorPwm_STATUS_FIFOFULL_INT_EN_MASK        LMotorPwm_STATUS_FIFOFULL
    #define LMotorPwm_STATUS_FIFONEMPTY_INT_EN_MASK      LMotorPwm_STATUS_FIFONEMPTY
    #define LMotorPwm_STATUS_TC_INT_EN_MASK              LMotorPwm_STATUS_TC
    #define LMotorPwm_STATUS_CMP2_INT_EN_MASK            LMotorPwm_STATUS_CMP2
    #define LMotorPwm_STATUS_CMP1_INT_EN_MASK            LMotorPwm_STATUS_CMP1
                                                          
    /* Datapath Auxillary Control Register definitions */
    #define LMotorPwm_AUX_CTRL_FIFO0_CLR     0x01u
    #define LMotorPwm_AUX_CTRL_FIFO1_CLR     0x02u
    #define LMotorPwm_AUX_CTRL_FIFO0_LVL     0x04u
    #define LMotorPwm_AUX_CTRL_FIFO1_LVL     0x08u
    #define LMotorPwm_STATUS_ACTL_INT_EN_MASK  0x10u /* As defined for the ACTL Register */
#endif /* LMotorPwm_UsingFixedFunction */

#endif  /* CY_PWM_LMotorPwm_H */


/* [] END OF FILE */
