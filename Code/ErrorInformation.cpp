//*************************************************************************
//  
//  Copyright (c) all 2014  All rights reserved
//  D a t e  : 2014.9.11
//  ��  �� : 
//  ��  �� : 0.1
//  ��  �� : ������Ϣ��غ���
//  ˵  �� : 
//  ��  ע :
//
//  �޸ļ�¼:
//  ��   ��       �汾    �޸���              �޸�����
// 2014/9/11 0.1      EvilKnight        ����
//  YYYY/MM/DD    X.Y     <���߻��޸�����>    <�޸�����>
//
//*************************************************************************

#include "ErrorInformation.h"
#include <tchar.h>
#include <assert.h>

/*******************************************************************************
*
*   �� �� �� :     OutputErrorInformation
*  �������� :     ���������Ϣ
*  �����б� :     pFunctionName          --             Ŀ�����ID
*                      pTipsInformation      --             ָ��Ҫע���dll
*   ˵      �� :     ��ЩҪ�жϺ����Ƿ�ɹ�ִ�еģ��������Ļ�������������������
*                      ����Ϣ
*  ���ؽ�� :     ����ɹ�������TRUE��ʧ�ܷ���FALSE
*
*******************************************************************************/
VOID OutputErrorInformation(__in_z CONST PTCHAR pFunctionName,
                                                __in_z CONST PTCHAR pTipsInformation)
{
        TCHAR szBuffer[MAX_PATH] = {0} ;

        assert(NULL != pFunctionName) ;
        assert(NULL != pTipsInformation) ;

        _stprintf_s(szBuffer, sizeof(szBuffer), TEXT("%s::%s ErrorCode:%p\r\n"), 
                                pFunctionName, pTipsInformation, GetLastError()) ;
        OutputDebugString(szBuffer) ;
}