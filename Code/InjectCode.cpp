//*************************************************************************
//  
//  Copyright (c) all 2014  All rights reserved
//  D a t e  : 2014.9.11
//  ��  �� : 
//  ��  �� : 0.1
//  ��  �� : ��ָ����dllע�뵽Ŀ�����
//  ˵  �� : 
//  ��  ע :
//
//  �޸ļ�¼:
//  ��   ��       �汾    �޸���              �޸�����
// 2014/9/11 0.1      EvilKnight        ����
// 2014/9/12 0.1      EvilKnight        ʵ��Inject by ProcessName����
//  YYYY/MM/DD    X.Y     <���߻��޸�����>    <�޸�����>
//
//*************************************************************************
#include "InjectCode.h"
#include "EnvironmentInformation.h"
#include "ErrorInformation.h"
#include "ProcessInformation.h"


/*******************************************************************************
*
*   �� �� �� : Inject
*  �������� : ��dllע�뵽ָ������
*  �����б� : dwPID          --             Ŀ�����ID
*                   pDllPath      --             ָ��Ҫע���dll
*   ˵      �� : 
*  ���ؽ�� :  ����ɹ�������TRUE��ʧ�ܷ���FALSE
*
*******************************************************************************/
BOOL Inject(__in CONST DWORD dwPID, 
                        __in_z CONST PTCHAR pDllPath)
{
        // ����Ҫ�ж�ϵͳ�����������Ŀ������Լ�dll��λ��
        // �ж������λ����Ҫע���dll�Ƿ���Ŀ�����һ��

        // ��Ŀ�����

        // ��Ŀ����������ڴ�

        // д��dll·��

        // ����Զ���߳�
        // �ȴ��߳̽���

        // �ͷ��ڴ�

        // �رս��̾��
  
        return TRUE ;
}

// ��dllע�뵽ָ���������Ľ�����

/*******************************************************************************
*
*   �� �� �� : Inject
*  �������� : ��dllע�뵽ָ���������Ľ�����
*  �����б� : pProcessName     --             Ŀ�������
*                   pDllPath              --             ָ��Ҫע���dll
*   ˵      �� : ע��ʧ�ܣ�����ע����һ��
*  ���ؽ�� :  ���ȫ���ɹ�������TRUE����ʧ�ܷ���FALSE
*
*******************************************************************************/
BOOL Inject(__in_z CONST PTCHAR pProcessName,
            __in_z CONST PTCHAR pDllPath)
{
        ULONG uProcessCount(0) ;
        ULONG  uMemoryLength(0) ;
        BOOL bState(FALSE) ;
        PDWORD pArrayPID(NULL) ;
        const ULONG uFree(5) ;         // ������һЩ�ռ䣬��ֹ������ȡ�ý���id��ʱ��
                                                        // ͻȻ������һЩ���̣�����̫���ڼ��˵��������
                                                        // �Ͳ�������

        if (NULL == pProcessName)
        {
                OutputDebugString(TEXT("Inject:: pProcessName can't NULL! \r\n")) ;
                return FALSE ;
        }

        __try
        {
                uProcessCount = GetProcessListByProcessName(pProcessName, NULL, 0) ;
                // ���һ����ͬ�Ķ�û�У�ֱ���˳��ɣ�
                if (0 == uProcessCount)
                {
                        __leave ;
                }
                
                uMemoryLength = uProcessCount + uFree ;
                pArrayPID = new DWORD[uMemoryLength] ;
                uProcessCount = GetProcessListByProcessName(pProcessName, pArrayPID, uMemoryLength) ;

                // ���ĵ������ж��˰ɣ�Ҫ��Ȼ������ô��������ô���أ����һ���ͬ���ĳ���
                if (uProcessCount > uMemoryLength)
                {
                        __leave ;
                }

                bState = TRUE ;
                // ���ε���Inject��Ŀ�����ע��dll
                for (ULONG uIndex(0); uIndex < uProcessCount; ++ uIndex)
                {
                        // �����һ��ע��ʧ�ܣ��򷵻�״̬Ϊʧ��
                        if (! Inject(pArrayPID[uIndex], pDllPath))
                        {
                                bState = FALSE ;
                        }
                }
        }

        __finally
        {
                if (NULL != pArrayPID)
                {
                        delete [] pArrayPID ;
                        pArrayPID = NULL ;
                }
        }
        
        return bState ;
}
