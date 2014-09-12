//*************************************************************************
//  
//  Copyright (c) all 2014  All rights reserved
//  D a t e  : 2014.9.11
//  ��  �� : 
//  ��  �� : 0.1
//  ��  �� : ȡ����صĽ�����Ϣ
//  ˵  �� : 
//  ��  ע :
//
//  �޸ļ�¼:
//  ��   ��       �汾    �޸���              �޸�����
// 2014/9/11 0.1      EvilKnight        ����
// 2014/9/11 0.1      EvilKnight        ʵ��GetProcessListByProcessName
//  YYYY/MM/DD    X.Y     <���߻��޸�����>    <�޸�����>
//
//*************************************************************************
#include "ProcessInformation.h"
#include "ErrorInformation.h"
#include <tlhelp32.h>
#include <Windows.h>
#include <tchar.h>

/*******************************************************************************
*
*   �� �� �� : GetProcessListByProcessName
*  �������� : ͨ��������ȡ�ý����б�
*  �����б� : pProcessName     --      ָ�����ҵĽ�����
*                   pArrayPID            --       ����������ָ������ͬ�Ľ���PID
*                   uSize                    --       pArrayPID�����С����byte,���ǿ��Դ����pid
*   ˵      �� :  ���pArrayPIDû��ָ���Ļ���������Ȼ���Թ���������ڳ�������ͨ������
*                    �ڴ汣�淵�ؽ���Ļ��������ȵ���һ�����������ȡ���������Ա�����ҪӦ
*                    ��С���ڴ�
*  ���ؽ�� :  ������ָ����������ͬ�Ľ�����
*
*******************************************************************************/
ULONG GetProcessListByProcessName(
                            __in_z CONST PTCHAR pProcessName,
                            __in_bcount(uSize) CONST PDWORD pArrayPID,
                            __in CONST ULONG uSize)
{
        ULONG uProcessCount(0) ;
        HANDLE hProcessSnap = INVALID_HANDLE_VALUE ;
        PROCESSENTRY32 pe32;

        if (NULL == pProcessName)
        {
                OutputDebugString(TEXT("GetProcessListByProcessName pProcessName can't NULL!\r\n")) ;
                return 0 ;
        }

        __try
        {
                hProcessSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
                if (INVALID_HANDLE_VALUE == hProcessSnap)
                {
                        OutputErrorInformation(TEXT("GetProcessListByProcessName"),
                                                                TEXT("CreateToolhelp32Snapshot")) ;
                        __leave ;
                }

                pe32.dwSize = sizeof(PROCESSENTRY32) ;

                if( !Process32First( hProcessSnap, &pe32 ))
                {
                        OutputErrorInformation(TEXT("GetProcessListByProcessName"),
                                                                TEXT("Process32First")) ;
                        __leave ;
                }

                do 
                {
                        // ����ǱȽ�MAX_PATH���ַ���
                        if (0 == _tcsnicmp(pe32.szExeFile, pProcessName, MAX_PATH))
                        {
                                if (NULL != pArrayPID && uProcessCount < uSize)
                                {
                                        pArrayPID[uProcessCount] = pe32.th32ProcessID ;
                                }
                                uProcessCount++ ;
                        }

                } while (Process32Next( hProcessSnap, &pe32 ));
        }

        __finally
        {
                if (INVALID_HANDLE_VALUE != hProcessSnap)
                {
                        CloseHandle(hProcessSnap) ;
                        hProcessSnap = INVALID_HANDLE_VALUE ;
                }
        }
        return uProcessCount ;
}