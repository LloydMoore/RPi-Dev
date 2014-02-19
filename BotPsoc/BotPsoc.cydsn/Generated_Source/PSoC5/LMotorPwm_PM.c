/*******************************************************************************
* File Name: LMotorPwm_PM.c
* Version 3.0
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#include "cytypes.h"
#include "LMotorPwm.h"

static LMotorPwm_backupStruct LMotorPwm_backup;


/*******************************************************************************
* Function Name: LMotorPwm_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  LMotorPwm_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void LMotorPwm_SaveConfig(void) 
{
    
    #if(!LMotorPwm_UsingFixedFunction)
        #if(!LMotorPwm_PWMModeIsCenterAligned)
            LMotorPwm_backup.PWMPeriod = LMotorPwm_ReadPeriod();
        #endif /* (!LMotorPwm_PWMModeIsCenterAligned) */
        LMotorPwm_backup.PWMUdb = LMotorPwm_ReadCounter();
        #if (LMotorPwm_UseStatus)
            LMotorPwm_backup.InterruptMaskValue = LMotorPwm_STATUS_MASK;
        #endif /* (LMotorPwm_UseStatus) */
        
        #if(LMotorPwm_DeadBandMode == LMotorPwm__B_PWM__DBM_256_CLOCKS || \
            LMotorPwm_DeadBandMode == LMotorPwm__B_PWM__DBM_2_4_CLOCKS)
            LMotorPwm_backup.PWMdeadBandValue = LMotorPwm_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */
        
        #if(LMotorPwm_KillModeMinTime)
             LMotorPwm_backup.PWMKillCounterPeriod = LMotorPwm_ReadKillTime();
        #endif /* (LMotorPwm_KillModeMinTime) */
        
        #if(LMotorPwm_UseControl)
            LMotorPwm_backup.PWMControlRegister = LMotorPwm_ReadControlRegister();
        #endif /* (LMotorPwm_UseControl) */
    #endif  /* (!LMotorPwm_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: LMotorPwm_RestoreConfig
********************************************************************************
* 
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  LMotorPwm_backup:  Variables of this global structure are used to  
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void LMotorPwm_RestoreConfig(void) 
{
        #if(!LMotorPwm_UsingFixedFunction)
            #if(!LMotorPwm_PWMModeIsCenterAligned)
                LMotorPwm_WritePeriod(LMotorPwm_backup.PWMPeriod);
            #endif /* (!LMotorPwm_PWMModeIsCenterAligned) */
            LMotorPwm_WriteCounter(LMotorPwm_backup.PWMUdb);
            #if (LMotorPwm_UseStatus)
                LMotorPwm_STATUS_MASK = LMotorPwm_backup.InterruptMaskValue;
            #endif /* (LMotorPwm_UseStatus) */
            
            #if(LMotorPwm_DeadBandMode == LMotorPwm__B_PWM__DBM_256_CLOCKS || \
                LMotorPwm_DeadBandMode == LMotorPwm__B_PWM__DBM_2_4_CLOCKS)
                LMotorPwm_WriteDeadTime(LMotorPwm_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
            #if(LMotorPwm_KillModeMinTime)
                LMotorPwm_WriteKillTime(LMotorPwm_backup.PWMKillCounterPeriod);
            #endif /* (LMotorPwm_KillModeMinTime) */
            
            #if(LMotorPwm_UseControl)
                LMotorPwm_WriteControlRegister(LMotorPwm_backup.PWMControlRegister); 
            #endif /* (LMotorPwm_UseControl) */
        #endif  /* (!LMotorPwm_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: LMotorPwm_Sleep
********************************************************************************
* 
* Summary:
*  Disables block's operation and saves the user configuration. Should be called 
*  just prior to entering sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  LMotorPwm_backup.PWMEnableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void LMotorPwm_Sleep(void) 
{
    #if(LMotorPwm_UseControl)
        if(LMotorPwm_CTRL_ENABLE == (LMotorPwm_CONTROL & LMotorPwm_CTRL_ENABLE))
        {
            /*Component is enabled */
            LMotorPwm_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            LMotorPwm_backup.PWMEnableState = 0u;
        }
    #endif /* (LMotorPwm_UseControl) */

    /* Stop component */
    LMotorPwm_Stop();
    
    /* Save registers configuration */
    LMotorPwm_SaveConfig();
}


/*******************************************************************************
* Function Name: LMotorPwm_Wakeup
********************************************************************************
* 
* Summary:
*  Restores and enables the user configuration. Should be called just after 
*  awaking from sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  LMotorPwm_backup.pwmEnable:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void LMotorPwm_Wakeup(void) 
{
     /* Restore registers values */
    LMotorPwm_RestoreConfig();
    
    if(LMotorPwm_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        LMotorPwm_Enable();
    } /* Do nothing if component's block was disabled before */
    
}


/* [] END OF FILE */
