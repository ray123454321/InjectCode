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

#ifndef ENVIRONMENTINFORMATION__H
#define ENVIRONMENTINFORMATION__H

#include <Windows.h>

// ȡ�ò���ϵͳλ��
ULONG   GetOSBit(VOID) ;

// ȡ��ָ������λ����32λ����64λ���������ȡ��������ֵ������0
ULONG   GetProcessBit(__in CONST DWORD dwPID) ;

// ȡ�õ�ǰ���̵�λ��
ULONG   GetMyselfBit(VOID) ;

// ȡ�ÿ�ִ���ļ���λ��
ULONG   GetPEFileBit(__in_z CONST PTCHAR pPEFilePath) ;

// ͨ���ڴ��е�PEͷ��ȡ�ó���λ��
ULONG   GetBitByPEHeader(__in_bcount(uSize) CONST PVOID pPE,
                                                __in CONST ULONG uSize) ;

#endif