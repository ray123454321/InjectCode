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
//  YYYY/MM/DD    X.Y     <���߻��޸�����>    <�޸�����>
//
//*************************************************************************

#ifndef PROCESSINFORMATION__H
#define PROCESSINFORMATION__H

#include <windows.h>

// ͨ��������ȡ�ý����б�
ULONG
GetProcessListByProcessName(
                                  __in_z CONST PTCHAR pProcessName,
                                   __in_bcount(uSize) CONST PDWORD pArrayPID,
                                    __in CONST ULONG uSize) ;

#endif

