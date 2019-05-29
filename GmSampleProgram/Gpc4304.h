//===========================================================================
//
//  GPIB-HG(PCI/C-PCI)-[GPC/GPF-4301]/GPIB-EX(PCI/C-PCI)-[GPC-4304]
//
//  OS       : Windows XP, Windows 2000, Windows NT4.0
//                         Windows Millennium Edition, Windows 98, Windows 95
//
//  MODULE   : GPC4304.H
//
//  PURPOSE  : Application include header file-English comments 
//
//  Copyright 2000, 2002 Interface Corporation. All rights reserved.
//===========================================================================

#ifndef	_GPC4304_H
#define _GPC4304_H

#ifdef __cplusplus      // Assume C declarations for C++ 
extern "C" {
#endif                  // __cplusplus

#define LPSRQCALLBACK	VOID WINAPI
typedef void (WINAPI *PLPSRQCALLBACK)(int nBoardNo, DWORD dwUser);

#define _GPC4304_DLL_IMPORT_ WINAPI

int _GPC4304_DLL_IMPORT_ PciGpibExInitBoard(int nBoardNo, HWND hWnd);
int _GPC4304_DLL_IMPORT_ PciGpibExFinishBoard(int nBoardNo);
int _GPC4304_DLL_IMPORT_ PciGpibExGetInfo(int nBoardNo, int nPrmNo, ULONG *ulpGetPrm);
int _GPC4304_DLL_IMPORT_ PciGpibExSetConfig(int nBoardNo, char *szPrm);
int _GPC4304_DLL_IMPORT_ PciGpibExGetConfig(int nBoardNo, int nPrmNo, ULONG *ulpGetPrm);
int _GPC4304_DLL_IMPORT_ PciGpibExSetSignal(int nBoardNo, UINT uSignal, BOOL bDetect);
int _GPC4304_DLL_IMPORT_ PciGpibExWaitSignal(int nBoardNo, UINT *upStatus);
int _GPC4304_DLL_IMPORT_ PciGpibExGetStatus(int nBoardNo, UINT *upStatus);
int _GPC4304_DLL_IMPORT_ PciGpibExClrStatus(int nBoardNo, UINT uClrStat);
int _GPC4304_DLL_IMPORT_ PciGpibExGetBusLine(int nBoardNo, UINT *upGetBusLine, int nSelFlag);
int _GPC4304_DLL_IMPORT_ PciGpibExSetBusLine(int nBoardNo, UINT uSetBusLine, int nSelFlag);
int _GPC4304_DLL_IMPORT_ PciGpibExWaitTimer(DWORD dwTimer);
int _GPC4304_DLL_IMPORT_ PciGpibExStartTimer(void);
int _GPC4304_DLL_IMPORT_ PciGpibExClearTimer(void);
int _GPC4304_DLL_IMPORT_ PciGpibExReadTimer(DWORD *dwpTimerVal);
int _GPC4304_DLL_IMPORT_ PciGpibExStopTimer(void);

int _GPC4304_DLL_IMPORT_ PciGpibExSetIfc(int nBoardNo, int nTime);
int _GPC4304_DLL_IMPORT_ PciGpibExSetRen(int nBoardNo);
int _GPC4304_DLL_IMPORT_ PciGpibExResetRen(int nBoardNo);
int _GPC4304_DLL_IMPORT_ PciGpibExSetRemote(int nBoardNo, int *npAdrsTbl);
int _GPC4304_DLL_IMPORT_ PciGpibExExecTrigger(int nBoardNo, int *npAdrsTbl);
int _GPC4304_DLL_IMPORT_ PciGpibExExecDevClear(int nBoardNo);
int _GPC4304_DLL_IMPORT_ PciGpibExExecSdc(int nBoardNo, int *npAdrsTbl);
int _GPC4304_DLL_IMPORT_ PciGpibExSetLocal(int nBoardNo, int *npAdrsTbl);
int _GPC4304_DLL_IMPORT_ PciGpibExSetLlo(int nBoardNo);
int _GPC4304_DLL_IMPORT_ PciGpibExSetRwls(int nBoardNo, int *npAdrsTbl);
int _GPC4304_DLL_IMPORT_ PciGpibExExecPassCtrl(int nBoardNo, int *npAdrsTbl);
int _GPC4304_DLL_IMPORT_ PciGpibExExecFindListener(int nBoardNo, int *npAdrsTbl, int *npStatTbl, int *npFindCnt);
int _GPC4304_DLL_IMPORT_ PciGpibExExecDevReset(int nBoardNo, int *npAdrsTbl);
int _GPC4304_DLL_IMPORT_ PciGpibExReSysCtrl(int nBoardNo, int nMode);
int _GPC4304_DLL_IMPORT_ PciGpibExGoStandby(int nBoardNo, int nMode);
int _GPC4304_DLL_IMPORT_ PciGpibExGoActCtrller(int nBoardNo, int nMode);
int _GPC4304_DLL_IMPORT_ PciGpibExExecSpoll(int nBoardNo, int *npAdrsTbl, int *npStbTbl, int *npStbAdrs);
int _GPC4304_DLL_IMPORT_ PciGpibExCheckSrq(int nBoardNo);
int _GPC4304_DLL_IMPORT_ PciGpibExClearSrq(int nBoardNo);
int _GPC4304_DLL_IMPORT_ PciGpibExEnableSrq(int nBoardNo);
int _GPC4304_DLL_IMPORT_ PciGpibExDisableSrq(int nBoardNo);
int _GPC4304_DLL_IMPORT_ PciGpibExExecPpoll(int nBoardNo, int *npPst);
int _GPC4304_DLL_IMPORT_ PciGpibExCfgPpoll(int nBoardNo, int *npAdrsTbl, int nPpe);
int _GPC4304_DLL_IMPORT_ PciGpibExUnCfgPpoll(int nBoardNo, int *npAdrsTbl);
int _GPC4304_DLL_IMPORT_ PciGpibExWriteBusCmd(int nBoardNo, int *npCmdTbl);

int _GPC4304_DLL_IMPORT_ PciGpibExMastSendData(int nBoardNo, int *npAdrsTbl, DWORD  dwLength,  void *pvBuffer, UINT uMsg);
int _GPC4304_DLL_IMPORT_ PciGpibExMastRecvData(int nBoardNo, int *npAdrsTbl, DWORD *dwpLength, void *pvBuffer, UINT uMsg);
int _GPC4304_DLL_IMPORT_ PciGpibExMastSendFile(int nBoardNo, int *npAdrsTbl, char *pszFname);
int _GPC4304_DLL_IMPORT_ PciGpibExMastRecvFile(int nBoardNo, int *npAdrsTbl, DWORD *dwpLength, char *pszFname);

int _GPC4304_DLL_IMPORT_ PciGpibExSlavSendData(int nBoardNo, DWORD  dwLength,  void *pvBuffer, UINT uMsg);
int _GPC4304_DLL_IMPORT_ PciGpibExSlavRecvData(int nBoardNo, DWORD *dwpLength, void *pvBuffer, UINT uMsg);
int _GPC4304_DLL_IMPORT_ PciGpibExSlavSendFile(int nBoardNo, char *pzsFname);
int _GPC4304_DLL_IMPORT_ PciGpibExSlavRecvFile(int nBoardNo, DWORD *dwpLength, char *pszFname);
int _GPC4304_DLL_IMPORT_ PciGpibExSlavCheckStb(int nBoardNo);
int _GPC4304_DLL_IMPORT_ PciGpibExSlavSetSrq(int nBoardNo, int nStb);
int _GPC4304_DLL_IMPORT_ PciGpibExSlavSetIst(int nBoardNo, int nMode);
int _GPC4304_DLL_IMPORT_ PciGpibExSlavSetPp2(int nBoardNo, int nMode);

int _GPC4304_DLL_IMPORT_ PciGpibExSetSrqEvent(int nBoardNo, PLPSRQCALLBACK lpOnSrqProc, DWORD dwUser);
int _GPC4304_DLL_IMPORT_ PciGpibExSetSrqEventEx(int nBoardNo, PLPSRQCALLBACK lpOnSrqProc, HANDLE hUserEvent, HWND hUserWnd, UINT uUserMsg, DWORD dwUser);
int _GPC4304_DLL_IMPORT_ PciGpibExWaitSrqEvent(int nBoardNo, ULONG ulTimeOut);
int _GPC4304_DLL_IMPORT_ PciGpibExKillSrqEvent(int nBoardNo);

// Special API - Windows XP/2000/NT4.0/Me/98/95 - These APIs are not available for the GPC-4301.
int _GPC4304_DLL_IMPORT_ PciGpibExMastSendDataSpe(int nBoardNo, int *npAdrsTbl, DWORD  dwLength,  void *pvBuffer, UINT uMsg, int n);
int _GPC4304_DLL_IMPORT_ PciGpibExMastRecvDataSpe(int nBoardNo, int *npAdrsTbl, DWORD *dwpLength, void *pvBuffer, UINT uMsg, int n);

#define GPIB_SUCCESS_NOT_FOUND_LISTENER     11    // No Listener is found.
#define GPIB_SUCCESS_OK_SEND_STB            7     // The device has already sent a status byte.
#define GPIB_SUCCESS_NOT_EXEC_SPOLL         6     // The Controller-in-charge has not done serial polling yet.
#define GPIB_SUCCESS_NOT_ACTIVE_SRQ         5     // The SRQ line is deasserted.
#define GPIB_SUCCESS_ACTIVE_SRQ             4     // The SRQ line is asserted.
#define GPIB_SUCCESS_OK_EOI_DETECT          2     // The read operation was successfully completed with detecting the EOI assertion.
#define GPIB_SUCCESS_OK_RECV_DATA_CNT       1     // The read operation was terminated when count of data byte received reaches the specified number. At this point, delimiter characters have not been detected.
#define GPIB_SUCCESS_OK_DELIM_DETECT        0     // The read operation was successfully completed with detecting the specified delimiter.
#define GPIB_SUCCESS                        0     // The process was successfully completed.
#define GPIB_ERROR_ILLEGAL_BOARDNO          -1    // The specified board number is invalid.
#define GPIB_ERROR_ILLEGAL_INP_PARAM        -2    // The given parameter is invalid.
#define GPIB_ERROR_ILLEGAL_PARAM_NO         -3    // The specified parameter number is out of the range.
#define GPIB_ERROR_NOT_USE_SLAVE            -4    // The interface is not the Controller-in-charge.
#define GPIB_ERROR_NOT_USE_NONE_CIC         -4    // The interface is not a Listener or Talker.
#define GPIB_ERROR_NOT_USE_MASTER           -5    // This function API is not available for the interface that is the Master mode.
#define GPIB_ERROR_NOT_USE_CIC              -5    // This function API is not available for the interface that is the Controller-in-charge.
#define GPIB_ERROR_NOT_BOTH_USE             -6    // The interface cannot be specified both the Controller-in-charge and a Listener or a Talker at the same time.
#define GPIB_ERROR_WRITE_BUS_COMMAND        -7    // Failed to send a GPIB command.
#define GPIB_ERROR_NO_SET_SIGNAL            -8    // No event mask is given. Specify one or more events to be detected.
#define GPIB_ERROR_NO_ACTIVE_SRQ            -9    // The Controller-in-charge cannot determine a device that requests service at the serial polling.
#define GPIB_ERROR_STB_RECV_TMO             -10   // The timeout interval is elapsed before the Controller-in-charge receives a status byte completely.
#define GPIB_ERROR_DATA_RECV                -12   // Failed to read an operation. Asynchronous transfer is in progress on the GPIB.
#define GPIB_ERROR_DATA_SEND                -13   // Failed to write an operation. Asynchronous transfer is in progress on the GPIB.
#define GPIB_ERROR_TRANS_TMO                -14   // The timeout interval is elapsed before the read operation is completed.
#define GPIB_ERROR_WAIT_SIGNAL_TMO          -15   // The timeout interval is elapsed before expected GPIB events occur.
#define GPIB_ERROR_IFC_TRANS_EXIT           -16   // The I/O operation is aborted by the IFC signal assertion.
#define GPIB_ERROR_NOT_CACS                 -19   // The interface can not become Active-Controller.
#define GPIB_ERROR_NOW_BUS_OCCUPATION       -20   // Asynchronous transfer is in progress on the GPIB.
#define GPIB_ERROR_NO_SET                   -22   // The device driver cannot change configuration parameters.
#define GPIB_ERROR_NOT_START_TIMER          -24   // The timer cannot start.
#define GPIB_ERROR_EXIST_START_TIMER        -25   // The timer is running.
#define GPIB_ERROR_NOT_TICK_TIMER           -26   // The timer is not running.
#define GPIB_ERROR_FILE_ACCESS              -30   // Access to the file is denied. Failed to open the file.
#define GPIB_ERROR_SET_CALLBACK_EVENT       -40   // Failed to register the callback routine.
#define GPIB_ERROR_KILL_CALLBACK_EVENT      -41   // Failed to remove the callback routine.
#define GPIB_ERROR_WAIT_OBJECT_SIGNAL       -42   // The event object is enabled.
#define GPIB_ERROR_WAIT_OBJECT_TMO          -43   // The timeout interval is elapsed before the event object is signaled.
#define GPIB_ERROR_WAIT_OBJECT_FAILED       -44   // An error occurred before the event object is signaled. 
#define GPIB_ERROR_NOT_SET_CALLBACK_EVENT   -45   // No event is registered.
#define GPIB_ERROR_NOT_SYS_CONTROLLER       -50   // The interface is not System Controller.
#define GPIB_ERROR_NOT_CREATE_EVENT         -992  // Failed to create the event.
#define GPIB_ERROR_NOT_CREATE_THREAD        -993  // Failed to create the thread.
#define GPIB_ERROR_NOT_INIT_CALL            -994  // The function API is not available before the board is initialized properly.
#define GPIB_ERROR_BOARD_CLOSE              -995  // Failed to close the board.
#define GPIB_ERROR_NOT_ALLOC_PAGE           -996  // The driver software cannot allocate enough memory.
#define GPIB_ERROR_NOT_USE_TIMER            -997  // The timer is not successfully configured.
#define GPIB_ERROR_NOT_USE_RESOURCE         -998  // Hardware resources such as IRQ level may conflict with the system or other devices.
#define GPIB_ERROR_NOT_BOARD                -999  // The board is not correctly installed or the I/O port address conflicts with the system or other devices.
#define GPIB_ERROR_NOT_SUPPORT              -2000 // This API is not supported.

#ifdef __cplusplus
}                       // End of extern "C" {
#endif                  // __cplusplus

#endif
