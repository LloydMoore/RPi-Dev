/*******************************************************************************
* File Name: PiComs.h
* Version 2.60
*
* Description:
*  Contains the function prototypes, constants and register definition
*  of the SPI Slave Component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIS_PiComs_H)
#define CY_SPIS_PiComs_H

#include "cytypes.h"
#include "CyLib.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component SPI_Slave_v2_60 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define PiComs_DATA_WIDTH                  (8u)
#define PiComs_INTERNAL_TX_INT_ENABLED     (0u)
#define PiComs_INTERNAL_RX_INT_ENABLED     (0u)
#define PiComs_MODE_USE_ZERO               (1u)
#define PiComs_BIDIRECTIONAL_MODE          (0u)
#define PiComs_MODE                        (0u)

#define PiComs_FIFO_SIZE                  (4u)
/* Internal interrupt handling */
#define PiComs_TX_BUFFER_SIZE             (4u)
#define PiComs_RX_BUFFER_SIZE             (4u)
#define PiComs_INTERNAL_TX_INT_ENABLED    (0u)
#define PiComs_INTERNAL_RX_INT_ENABLED    (0u)

#define PiComs_TX_SOFTWARE_BUF_ENABLED    ((0u != PiComs_INTERNAL_TX_INT_ENABLED) && \
                                                     (PiComs_TX_BUFFER_SIZE > PiComs_FIFO_SIZE))

#define PiComs_RX_SOFTWARE_BUF_ENABLED    ((0u != PiComs_INTERNAL_RX_INT_ENABLED) && \
                                                     (PiComs_RX_BUFFER_SIZE > PiComs_FIFO_SIZE))

/* Following definitions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects
*/
#define PiComs_InternalInterruptEnabled (0u)


/***************************************
*        Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
    uint8 cntrPeriod;

    #if(CY_UDB_V0) /* CY_UDB_V0 */

        uint8 saveSrTxIntMask;
        uint8 saveSrRxIntMask;

    #endif /* CY_UDB_V0 */

} PiComs_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  PiComs_Init(void) ;
void  PiComs_Enable(void) ;
void  PiComs_Start(void) ;
void  PiComs_Stop(void) ;
void  PiComs_EnableTxInt(void) ;
void  PiComs_EnableRxInt(void) ;
void  PiComs_DisableTxInt(void) ;
void  PiComs_DisableRxInt(void) ;
void  PiComs_SetTxInterruptMode(uint8 intSrc) ;
void  PiComs_SetRxInterruptMode(uint8 intSrc) ;
uint8 PiComs_ReadTxStatus(void) ;
uint8 PiComs_ReadRxStatus(void) ;
void  PiComs_WriteTxData(uint8 txData);

#if(PiComs_MODE_USE_ZERO != 0u)
    void  PiComs_WriteTxDataZero(uint8 txDataByte) \
                                              ;
#endif /* (PiComs_MODE_USE_ZERO != 0u) */

uint8 PiComs_ReadRxData(void) ;
uint8 PiComs_GetRxBufferSize(void) ;
uint8 PiComs_GetTxBufferSize(void) ;
void  PiComs_ClearRxBuffer(void) ;
void  PiComs_ClearTxBuffer(void) ;

#if (PiComs_BIDIRECTIONAL_MODE != 0u)
    void  PiComs_TxEnable(void) ;
    void  PiComs_TxDisable(void) ;
#endif /* PiComs_BIDIRECTIONAL_MODE != 0u */

void  PiComs_PutArray(const uint8 buffer[], uint8 byteCount) ;
void  PiComs_ClearFIFO(void) ;
void  PiComs_Sleep(void) ;
void  PiComs_Wakeup(void) ;
void  PiComs_SaveConfig(void) ;
void  PiComs_RestoreConfig(void) ;

/* Communication bootloader APIs */
#if defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_PiComs) || \
                                          (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))
    /* Physical layer functions */
    void    PiComs_CyBtldrCommStart(void) CYSMALL ;
    void    PiComs_CyBtldrCommStop(void) CYSMALL ;
    void    PiComs_CyBtldrCommReset(void) CYSMALL ;
    cystatus PiComs_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;
    cystatus PiComs_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;

    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_PiComs)
        #define CyBtldrCommStart    PiComs_CyBtldrCommStart
        #define CyBtldrCommStop     PiComs_CyBtldrCommStop
        #define CyBtldrCommReset    PiComs_CyBtldrCommReset
        #define CyBtldrCommWrite    PiComs_CyBtldrCommWrite
        #define CyBtldrCommRead     PiComs_CyBtldrCommRead
    #endif  /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_PiComs) */

    /* Byte to Byte time out for detecting end of block data from host */
    #define PiComs_BYTE2BYTE_TIME_OUT (1u)

#endif /* (CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_PiComs) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface)) */


CY_ISR_PROTO(PiComs_TX_ISR);
CY_ISR_PROTO(PiComs_RX_ISR);

/* Macros for getting software status of SPIS Statusi Register */
#define PiComs_GET_STATUS_TX(swTxSts) ( (uint8)(PiComs_TX_STATUS_REG | \
                                                       ((swTxSts) & PiComs_STS_CLR_ON_RD_BYTES_MASK)) )
#define PiComs_GET_STATUS_RX(swRxSts) ( (uint8)(PiComs_RX_STATUS_REG | \
                                                       ((swRxSts) & PiComs_STS_CLR_ON_RD_BYTES_MASK)) )

/* Following definitions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects
*/
#define PiComs_WriteByte      (PiComs_WriteTxData)
#define PiComs_ReadByte       (PiComs_ReadRxData)
#define PiComs_WriteByteZero  (PiComs_WriteTxDataZero)
void  PiComs_SetInterruptMode(uint8 intSrc) ;
uint8 PiComs_ReadStatus(void) ;
void  PiComs_EnableInt(void) ;
void  PiComs_DisableInt(void) ;


/**********************************
*   Variable with external linkage
**********************************/

extern uint8 PiComs_initVar;


/***************************************
*           API Constants
***************************************/

#define PiComs_TX_ISR_NUMBER     ((uint8)PiComs_TxInternalInterrupt__INTC_NUMBER)
#define PiComs_RX_ISR_NUMBER     ((uint8)PiComs_RxInternalInterrupt__INTC_NUMBER)
#define PiComs_TX_ISR_PRIORITY   ((uint8)PiComs_TxInternalInterrupt__INTC_PRIOR_NUM)
#define PiComs_RX_ISR_PRIORITY   ((uint8)PiComs_RxInternalInterrupt__INTC_PRIOR_NUM)


/***************************************
*    Initial Parameter Constants
***************************************/

#define PiComs_INT_ON_SPI_DONE    (uint8)(0u << PiComs_STS_SPI_DONE_SHIFT)
#define PiComs_INT_ON_TX_EMPTY    (uint8)(1u << PiComs_STS_TX_FIFO_EMPTY_SHIFT)
#define PiComs_INT_ON_TX_NOT_FULL (uint8)(0u << PiComs_STS_TX_FIFO_NOT_FULL_SHIFT)
#define PiComs_INT_ON_BYTE_COMP   (uint8)(0u << PiComs_STS_BYTE_COMPLETE_SHIFT)

#define PiComs_TX_INIT_INTERRUPTS_MASK  (PiComs_INT_ON_SPI_DONE | \
                                            PiComs_INT_ON_TX_EMPTY | PiComs_INT_ON_TX_NOT_FULL | \
                                            PiComs_INT_ON_BYTE_COMP)

#define PiComs_INT_ON_RX_EMPTY     (uint8)(0u << PiComs_STS_RX_FIFO_EMPTY_SHIFT)
#define PiComs_INT_ON_RX_NOT_EMPTY (uint8)(1u << PiComs_STS_RX_FIFO_NOT_EMPTY_SHIFT)
#define PiComs_INT_ON_RX_OVER      (uint8)(0u << PiComs_STS_RX_FIFO_OVERRUN_SHIFT)
#define PiComs_INT_ON_RX_FULL      (uint8)(0u << PiComs_STS_RX_FIFO_FULL_SHIFT)

#define PiComs_RX_INIT_INTERRUPTS_MASK (PiComs_INT_ON_RX_EMPTY | \
                                            PiComs_INT_ON_RX_NOT_EMPTY | PiComs_INT_ON_RX_OVER | \
                                            PiComs_INT_ON_RX_FULL)

#define PiComs_BITCTR_INIT           (PiComs_DATA_WIDTH - 1u)

#define PiComs__MODE_00 0
#define PiComs__MODE_01 1
#define PiComs__MODE_10 2
#define PiComs__MODE_11 3


#define PiComs_TX_BUFFER_SIZE         (4u)
#define PiComs_RX_BUFFER_SIZE         (4u)

/* Following definitions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects
*/
#define PiComs_INIT_INTERRUPTS_MASK  (PiComs_INT_ON_SPI_DONE | PiComs_INT_ON_TX_EMPTY | \
                                            PiComs_INT_ON_TX_NOT_FULL | PiComs_INT_ON_RX_EMPTY | \
                                            PiComs_INT_ON_RX_NOT_EMPTY | PiComs_INT_ON_RX_OVER | \
                                            PiComs_INT_ON_BYTE_COMP)


/***************************************
*             Registers
***************************************/

#if(CY_UDB_V0)

    #define PiComs_TXDATA_ZERO_REG           (* (reg8  *) \
            PiComs_BSPIS_es2_SPISlave_sR8_DpMISO_u0__A0_REG)

    #define PiComs_TXDATA_ZERO_PTR           (  (reg8  *) \
            PiComs_BSPIS_es2_SPISlave_sR8_DpMISO_u0__A0_REG)

    #define PiComs_RXDATA_ZERO_REG           (* (reg8  *) \
            PiComs_BSPIS_es2_SPISlave_sR8_DpMOSI_u0__A0_REG)

    #define PiComs_RXDATA_ZERO_PTR           (  (reg8  *) \
            PiComs_BSPIS_es2_SPISlave_sR8_DpMOSI_u0__A0_REG)

    #define PiComs_TXDATA_REG                (* (reg8  *) \
            PiComs_BSPIS_es2_SPISlave_sR8_DpMISO_u0__F0_REG)

    #define PiComs_TXDATA_PTR                (  (reg8  *) \
            PiComs_BSPIS_es2_SPISlave_sR8_DpMISO_u0__F0_REG)

    #define PiComs_RXDATA_REG                (* (reg8  *) \
            PiComs_BSPIS_es2_SPISlave_sR8_DpMOSI_u0__F0_REG)

    #define PiComs_RXDATA_PTR                (  (reg8  *) \
            PiComs_BSPIS_es2_SPISlave_sR8_DpMOSI_u0__F0_REG)

    #define PiComs_TX_AUX_CONTROL_DP0_REG       (* (reg8 *) \
            PiComs_BSPIS_es2_SPISlave_sR8_DpMISO_u0__DP_AUX_CTL_REG)
    #define PiComs_TX_AUX_CONTROL_DP0_PTR       (  (reg8 *) \
            PiComs_BSPIS_es2_SPISlave_sR8_DpMISO_u0__DP_AUX_CTL_REG)

    #if(PiComs_DATA_WIDTH > 8u)

        #define PiComs_TX_AUX_CONTROL_DP1_REG   (* (reg8 *) \
                PiComs_BSPIS_es2_SPISlave_sR8_DpMISO_u1__DP_AUX_CTL_REG)
        #define PiComs_TX_AUX_CONTROL_DP1_PTR   (  (reg8 *) \
                PiComs_BSPIS_es2_SPISlave_sR8_DpMISO_u1__DP_AUX_CTL_REG)

    #endif /* PiComs_DATA_WIDTH > 8u */

#else /* CY_UDB_V0 */
    #if(CY_PSOC3 || CY_PSOC5)
        #define PiComs_TXDATA_ZERO_REG          (* (reg8  *) \
                PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__A0_REG)

        #define PiComs_TXDATA_ZERO_PTR           (  (reg8  *) \
                PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__A0_REG)

        #define PiComs_RXDATA_ZERO_REG           (* (reg8  *) \
                PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__A0_REG)

        #define PiComs_RXDATA_ZERO_PTR           (  (reg8  *) \
                PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__A0_REG)

        #define PiComs_TXDATA_REG                (* (reg8  *) \
                PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__F0_REG)

        #define PiComs_TXDATA_PTR                (  (reg8  *) \
                PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__F0_REG)

        #define PiComs_RXDATA_REG                (* (reg8  *) \
                PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__F1_REG)

        #define PiComs_RXDATA_PTR                (  (reg8  *) \
                PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__F1_REG)
    #else
        #if(PiComs_DATA_WIDTH <= 8u) /* 8bit - SPIS */
            #define PiComs_TXDATA_ZERO_REG           (* (reg8 *) \
                    PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__A0_REG)

            #define PiComs_TXDATA_ZERO_PTR           (  (reg8  *) \
                    PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__A0_REG)

            #define PiComs_RXDATA_ZERO_REG           (* (reg8  *) \
                    PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__A0_REG)

            #define PiComs_RXDATA_ZERO_PTR           (  (reg8 *) \
                    PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__A0_REG)

            #define PiComs_TXDATA_REG                (* (reg8  *) \
                    PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__F0_REG)

            #define PiComs_TXDATA_PTR                (  (reg8  *) \
                    PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__F0_REG)

            #define PiComs_RXDATA_REG                (* (reg8  *) \
                    PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__F1_REG)

            #define PiComs_RXDATA_PTR                (  (reg8  *) \
                    PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__F1_REG)
        #else /* 16bit - SPIS */
            #define PiComs_TXDATA_ZERO_REG           (* (reg16  *) \
                    PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__16BIT_A0_REG)

            #define PiComs_TXDATA_ZERO_PTR           (  (reg16  *) \
                    PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__16BIT_A0_REG)

            #define PiComs_RXDATA_ZERO_REG           (* (reg16  *) \
                    PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__16BIT_A0_REG)

            #define PiComs_RXDATA_ZERO_PTR           (  (reg16  *) \
                    PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__16BIT_A0_REG)

            #define PiComs_TXDATA_REG                (* (reg16  *) \
                    PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__16BIT_F0_REG)

            #define PiComs_TXDATA_PTR                (  (reg16  *) \
                    PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__16BIT_F0_REG)

            #define PiComs_RXDATA_REG                (* (reg16  *) \
                    PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__16BIT_F1_REG)

            #define PiComs_RXDATA_PTR                (  (reg16 *) \
                    PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__16BIT_F1_REG)
        #endif /* (PiComs_DATA_WIDTH <= 8u) */
    #endif     /* (CY_PSOC3 || CY_PSOC5) */

    #define PiComs_TX_AUX_CONTROL_DP0_REG       (* (reg8 *) \
            PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__DP_AUX_CTL_REG)
    #define PiComs_TX_AUX_CONTROL_DP0_PTR       (  (reg8 *) \
            PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__DP_AUX_CTL_REG)

    #define PiComs_RX_AUX_CONTROL_DP0_REG       (* (reg8 *) \
            PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__DP_AUX_CTL_REG)
    #define PiComs_RX_AUX_CONTROL_DP0_PTR       (  (reg8 *) \
            PiComs_BSPIS_es3_SPISlave_sR8_Dp_u0__DP_AUX_CTL_REG)

    #if(PiComs_DATA_WIDTH > 8u)

        #define PiComs_TX_AUX_CONTROL_DP1_REG   (* (reg8 *) \
                PiComs_BSPIS_es3_SPISlave_sR8_Dp_u1__DP_AUX_CTL_REG)
        #define PiComs_TX_AUX_CONTROL_DP1_PTR   (  (reg8 *) \
                PiComs_BSPIS_es3_SPISlave_sR8_Dp_u1__DP_AUX_CTL_REG)

        #define PiComs_RX_AUX_CONTROL_DP1_REG   (* (reg8 *) \
                PiComs_BSPIS_es3_SPISlave_sR8_Dp_u1__DP_AUX_CTL_REG)
        #define PiComs_RX_AUX_CONTROL_DP1_PTR   (  (reg8 *) \
                PiComs_BSPIS_es3_SPISlave_sR8_Dp_u1__DP_AUX_CTL_REG)

    #endif /* PiComs_DATA_WIDTH > 8u */

#endif /* CY_UDB_V0 */

#define PiComs_COUNTER_PERIOD_REG    (* (reg8 *) \
        PiComs_BSPIS_es3_SPISlave_BitCounter__PERIOD_REG)
#define PiComs_COUNTER_PERIOD_PTR    (  (reg8 *) \
        PiComs_BSPIS_es3_SPISlave_BitCounter__PERIOD_REG)

#define PiComs_TX_STATUS_MASK_REG    (* (reg8 *) \
        PiComs_BSPIS_es3_SPISlave_TxStsReg__MASK_REG)
#define PiComs_TX_STATUS_MASK_PTR    (  (reg8 *) \
        PiComs_BSPIS_es3_SPISlave_TxStsReg__MASK_REG)

#define PiComs_RX_STATUS_MASK_REG    (* (reg8 *) \
        PiComs_BSPIS_es3_SPISlave_RxStsReg__MASK_REG)
#define PiComs_RX_STATUS_MASK_PTR    (  (reg8 *) \
        PiComs_BSPIS_es3_SPISlave_RxStsReg__MASK_REG)

#define PiComs_ONE_REG               (* (reg8 *) \
        PiComs_BSPIS_es3_SPISlave_dpCounter_u0__D1_REG)
#define PiComs_ONE_PTR               (  (reg8 *) \
        PiComs_BSPIS_es3_SPISlave_dpCounter_u0__D1_REG)

#define PiComs_TX_STATUS_REG         (* (reg8 *) \
        PiComs_BSPIS_es3_SPISlave_TxStsReg__STATUS_REG)
#define PiComs_TX_STATUS_PTR         (  (reg8 *) \
        PiComs_BSPIS_es3_SPISlave_TxStsReg__STATUS_REG)

#define PiComs_RX_STATUS_REG         (* (reg8 *) \
        PiComs_BSPIS_es3_SPISlave_RxStsReg__STATUS_REG)
#define PiComs_RX_STATUS_PTR         (  (reg8 *) \
        PiComs_BSPIS_es3_SPISlave_RxStsReg__STATUS_REG)

#define PiComs_COUNTER_CONTROL_REG   (* (reg8 *) \
        PiComs_BSPIS_es3_SPISlave_BitCounter__CONTROL_AUX_CTL_REG)
#define PiComs_COUNTER_CONTROL_PTR   (  (reg8 *) \
        PiComs_BSPIS_es3_SPISlave_BitCounter__CONTROL_AUX_CTL_REG)

#define PiComs_TX_STATUS_ACTL_REG    (* (reg8 *) \
        PiComs_BSPIS_es3_SPISlave_TxStsReg__STATUS_AUX_CTL_REG)
#define PiComs_TX_STATUS_ACTL_PTR    (  (reg8 *) \
        PiComs_TX_BSPIS_es3_SPISlave_TxStsReg__STATUS_AUX_CTL_REG)

#define PiComs_RX_STATUS_ACTL_REG    (* (reg8 *) \
        PiComs_BSPIS_es3_SPISlave_RxStsReg__STATUS_AUX_CTL_REG)
#define PiComs_RX_STATUS_ACTL_PTR    (  (reg8 *) \
        PiComs_RX_BSPIS_es3_SPISlave_RxStsReg__STATUS_AUX_CTL_REG)

#if(PiComs_BIDIRECTIONAL_MODE)

    #define PiComs_CONTROL_REG       (* (reg8 *) \
   PiComs_BSPIS_es3_SPISlave_SyncCtl_CtrlReg__CONTROL_REG)
    #define PiComs_CONTROL_PTR       (  (reg8 *) \
   PiComs_BSPIS_es3_SPISlave_SyncCtl_CtrlReg__CONTROL_REG)

#endif /* PiComs_BIDIRECTIONAL_MODE */

/* Obsolete register names. Not to be used in new designs */
#define PiComs_TXDATA_ZERO               (PiComs_TXDATA_ZERO_REG)
#define PiComs_TXDATA                    (PiComs_TXDATA_REG)
#define PiComs_RXDATA                    (PiComs_RXDATA_REG)
#define PiComs_MISO_AUX_CONTROLDP0       (PiComs_MISO_AUX_CTRL_DP0_REG)
#define PiComs_MOSI_AUX_CONTROLDP0       (PiComs_MOSI_AUX_CTRL_DP0_REG)
#define PiComs_TXBUFFERREAD              (PiComs_txBufferRead)
#define PiComs_TXBUFFERWRITE             (PiComs_txBufferWrite)
#define PiComs_RXBUFFERREAD              (PiComs_rxBufferRead)
#define PiComs_RXBUFFERWRITE             (PiComs_rxBufferWrite)

#if(PiComs_DATA_WIDTH > 8u)

    #define PiComs_MISO_AUX_CONTROLDP1   (PiComs_MISO_AUX_CTRL_DP1_REG)
    #define PiComs_MOSI_AUX_CONTROLDP1   (PiComs_MOSI_AUX_CTRL_DP0_REG)

#endif /* PiComs_DATA_WIDTH > 8u */

#define PiComs_COUNTER_PERIOD            (PiComs_COUNTER_PERIOD_REG)
#define PiComs_COUNTER_CONTROL           (PiComs_COUNTER_CONTROL_REG)
#define PiComs_ONE                       (PiComs_ONE_REG)
#define PiComs_STATUS                    (PiComs_TX_STATUS_REG)
#define PiComs_STATUS_MASK               (PiComs_TX_STATUS_MASK_REG)
#define PiComs_STATUS_ACTL               (PiComs_TX_STATUS_ACTL_REG)


/***************************************
*       Register Constants
***************************************/

/* Status Register Definitions */
#define PiComs_STS_SPI_DONE_SHIFT             (0x00u)
#define PiComs_STS_TX_FIFO_NOT_FULL_SHIFT     (0x01u)
#define PiComs_STS_TX_FIFO_EMPTY_SHIFT        (0x02u)
#define PiComs_STS_RX_FIFO_NOT_EMPTY_SHIFT    (0x03u)
#define PiComs_STS_RX_FIFO_EMPTY_SHIFT        (0x04u)
#define PiComs_STS_RX_FIFO_OVERRUN_SHIFT      (0x05u)
#define PiComs_STS_RX_FIFO_FULL_SHIFT         (0x06u)
#define PiComs_STS_BYTE_COMPLETE_SHIFT        (0x06u)

#define PiComs_STS_SPI_DONE                   ((uint8)(0x01u << PiComs_STS_SPI_DONE_SHIFT))
#define PiComs_STS_TX_FIFO_EMPTY              ((uint8)(0x01u << PiComs_STS_TX_FIFO_EMPTY_SHIFT))
#define PiComs_STS_TX_FIFO_NOT_FULL           ((uint8)(0x01u << PiComs_STS_TX_FIFO_NOT_FULL_SHIFT))
#define PiComs_STS_RX_FIFO_EMPTY              ((uint8)(0x01u << PiComs_STS_RX_FIFO_EMPTY_SHIFT))
#define PiComs_STS_RX_FIFO_NOT_EMPTY          ((uint8)(0x01u << PiComs_STS_RX_FIFO_NOT_EMPTY_SHIFT))
#define PiComs_STS_RX_FIFO_OVERRUN            ((uint8)(0x01u << PiComs_STS_RX_FIFO_OVERRUN_SHIFT))
#define PiComs_STS_RX_FIFO_FULL               ((uint8)(0x01u << PiComs_STS_RX_FIFO_FULL_SHIFT))
#define PiComs_STS_BYTE_COMPLETE              ((uint8)(0x01u << PiComs_STS_BYTE_COMPLETE_SHIFT))

#define PiComs_STS_CLR_ON_RD_BYTES_MASK       (0x61u)

/* StatusI Register Interrupt Enable Control Bits */
/* As defined by the Register map for the AUX Control Register */
#define PiComs_INT_ENABLE                     (0x10u)
#define PiComs_TX_FIFO_CLR    (0x01u) /* F0 - TX FIFO */
#define PiComs_RX_FIFO_CLR    (0x02u) /* F1 - RX FIFO */
#define PiComs_FIFO_CLR       (PiComs_TX_FIFO_CLR | PiComs_RX_FIFO_CLR)

/* Bit Counter (7-bit) Control Register Bit Definitions */
/* As defined by the Register map for the AUX Control Register */
#define PiComs_CNTR_ENABLE                    (0x20u)

/* Bi-Directional mode control bit */
#define PiComs_CTRL_TX_SIGNAL_EN              (0x01u)

/* Datapath Auxillary Control Register definitions */
#define PiComs_AUX_CTRL_FIFO0_CLR             (0x00u)
#define PiComs_AUX_CTRL_FIFO1_CLR             (0x00u)
#define PiComs_AUX_CTRL_FIFO0_LVL             (0x00u)
#define PiComs_AUX_CTRL_FIFO1_LVL             (0x00u)
#define PiComs_STATUS_ACTL_INT_EN_MASK        (0x10u)

/* Component disabled */
#define PiComs_DISABLED   (0u)

/* Obosolete Status Register Definitions *DO NOT USE IN NEW DESIGNS* */
#define PiComs_STS_TX_BUF_NOT_FULL_SHIFT      (0x01u)
#define PiComs_STS_TX_BUF_FULL_SHIFT          (0x02u)
#define PiComs_STS_RX_BUF_NOT_EMPTY_SHIFT     (0x03u)
#define PiComs_STS_RX_BUF_EMPTY_SHIFT         (0x04u)
#define PiComs_STS_RX_BUF_OVERRUN_SHIFT       (0x05u)

#define PiComs_STS_TX_BUF_NOT_FULL            ((uint8)(0x01u << PiComs_STS_TX_BUF_NOT_FULL_SHIFT))
#define PiComs_STS_TX_BUF_FULL                ((uint8)(0x01u << PiComs_STS_TX_BUF_FULL_SHIFT))
#define PiComs_STS_RX_BUF_NOT_EMPTY           ((uint8)(0x01u << PiComs_STS_RX_BUF_NOT_EMPTY_SHIFT))
#define PiComs_STS_RX_BUF_EMPTY               ((uint8)(0x01u << PiComs_STS_RX_BUF_EMPTY_SHIFT))
#define PiComs_STS_RX_BUF_OVERRUN             ((uint8)(0x01u << PiComs_STS_RX_BUF_OVERRUN_SHIFT))

/* Following definitions are for version Compatibility.
*  They are obsolete in SPIS v2_60.
*  Please do not use it in new projects
*/
#define PiComs_DataWidth                  (PiComs_DATA_WIDTH)
#define PiComs_InternalClockUsed          (PiComs_INTERNAL_CLOCK)
#define PiComs_InternalTxInterruptEnabled (PiComs_INTERNAL_TX_INT_ENABLED)
#define PiComs_InternalRxInterruptEnabled (PiComs_INTERNAL_RX_INT_ENABLED)
#define PiComs_ModeUseZero                (PiComs_MODE_USE_ZERO)
#define PiComs_BidirectionalMode          (PiComs_BIDIRECTIONAL_MODE)
#define PiComs_Mode                       (PiComs_MODE)
#define PiComs_DATAWIDHT                  (PiComs_DATA_WIDTH)
#define PiComs_InternalInterruptEnabled   (0u)

#define PiComs_TXBUFFERSIZE   (PiComs_TX_BUFFER_SIZE)
#define PiComs_RXBUFFERSIZE   (PiComs_RX_BUFFER_SIZE)

#define PiComs_TXBUFFER       PiComs_txBuffer
#define PiComs_RXBUFFER       PiComs_rxBuffer


#endif  /* CY_SPIS_PiComs_H */


/* [] END OF FILE */
