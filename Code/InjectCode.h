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
//  YYYY/MM/DD    X.Y     <���߻��޸�����>    <�޸�����>
//
//*************************************************************************
#ifndef INJECTCODE__H
#define INJECTCODE__H

#include <Windows.h>

// ��dllע�뵽ָ������
BOOL Inject(__in CONST DWORD dwPID,
                        __in_z CONST PTCHAR pDllPath) ;

// ��dllע�뵽ָ���������Ľ�����
BOOL Inject(__in_z CONST PTCHAR pProcessName,
                        __in_z CONST PTCHAR pDllPath) ;

#endif