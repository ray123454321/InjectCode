//*************************************************************************
//  
//  Copyright (c) all 2014  All rights reserved
//  D a t e  : 2014.9.11
//  ��  �� : 
//  ��  �� : 0.1
//  ��  �� : ���л��������Ϣ����
//  ˵  �� : 
//  ��  ע :
//
//  �޸ļ�¼:
//  ��   ��       �汾    �޸���              �޸�����
// 2014/9/11 0.1      EvilKnight        ����
//  YYYY/MM/DD    X.Y     <���߻��޸�����>    <�޸�����>
//
//*************************************************************************
#include "EnvironmentInformation.h"

typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);

LPFN_ISWOW64PROCESS fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(
                                        GetModuleHandle(TEXT("kernel32")),"IsWow64Process");

/*******************************************************************************
*
*   �� �� �� : GetOSBit
*  �������� : ȡ�ò���ϵͳλ��
*  �����б� : ��
*   ˵      �� : 
*  ���ؽ�� :  ����ɹ������ز���ϵͳλ��, ���򷵻�0
*
*******************************************************************************/
ULONG   GetOSBit(VOID)
{
        SYSTEM_INFO si = {0} ;
        GetNativeSystemInfo(&si) ;
        if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64 ||
                si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64 )
        {
                return 64;
        }
        return 32;
}


/*******************************************************************************
*
*   �� �� �� : GetProcessBit
*  �������� : ȡ��ָ������λ��
*  �����б� : dwPID          --             Ŀ�����ID
*   ˵      �� : 
*  ���ؽ�� :  ����ɹ������ؽ���λ��, ���򷵻�0
*
*******************************************************************************/
ULONG   GetProcessBit(__in CONST DWORD dwPID)
{
        // ���Ե���IsWow64Process
        // ��GetProcessImageFileName
        return 0 ;
}

/*******************************************************************************
*
*   �� �� �� : GetMyselfBit
*  �������� : ȡ�õ�ǰ���̵�λ��
*  �����б� : ��
*   ˵      �� : ��
*  ���ؽ�� :  ���ص�ǰ����λ��
*
*******************************************************************************/
ULONG   GetMyselfBit(VOID)
{
        return sizeof(PVOID) * 8;
}

/*******************************************************************************
*
*   �� �� �� : GetPEFileBit
*  �������� : ȡ�ÿ�ִ���ļ���λ��
*  �����б� : pPEFilePath  --     pe�ļ�·��
*   ˵      �� : ��pe�ļ���ͷ���ڴ棬�ٵ���GetBitByPEHeaderȥ�ж�
*  ���ؽ�� :  ���ص�ǰ����λ��
*
*******************************************************************************/
ULONG   GetPEFileBit(__in_z CONST PTCHAR pPEFilePath)
{
        return 0 ;
}

/*******************************************************************************
*
*   �� �� �� : GetBitByPEHeader
*  �������� :ͨ���ڴ��е�PEͷ��ȡ�ó���λ��
*  �����б� : pPE  --     ָ��洢peͷ���ڴ���ʼ��ַ
*                   uSize  --  ָ���洢peͷ�ڴ������С
*   ˵      �� : ��pe�ļ���ͷ���ڴ棬�ٵ���GetBitByPEHeaderȥ�ж�
*  ���ؽ�� :  ���ص�ǰ����λ��
*
*******************************************************************************/
ULONG   GetBitByPEHeader(__in_bcount(uSize) CONST PVOID pPE,
                         __in CONST ULONG uSize)
{
        // ����ͨ��IMAGE_NT_OPTIONAL_HDR_MAGIC���ж�
        return  0 ;
}
