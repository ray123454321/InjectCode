//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               ���汣��         ����BUG
//*************************************************************************
//  
//  Copyright (c) all 2014  All rights reserved
//  D a t e  : 2014.9.11
//  ��  �� : 
//  ��  �� : 0.1
//  ��  �� : �����Ϊ�˷�����Գ����õ�
//  ˵  �� : 
//  ��  ע :
//
//  �޸ļ�¼:
//  ��   ��       �汾    �޸���              �޸�����
//  2014/9/11 0.1    EvilKnight        ����
//  YYYY/MM/DD    X.Y     <���߻��޸�����>    <�޸�����>
//
//*************************************************************************
#ifdef _EXE
#pragma comment( linker, "/subsystem:console /entry:mainCRTStartup" )

/*
#pragma comment( linker, "/subsystem:windows /entry:WinMainCRTStartup" )
#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )
#pragma comment( linker, "/subsystem:console /entry:mainCRTStartup" )
#pragma comment( linker, "/subsystem:console /entry:WinMainCRTStartup" )
*/

#include "InjectCode.h"
#include "ProcessInformation.h"
#include "EnvironmentInformation.h"
#include <stdio.h>
#include <Windows.h>

int main(void)
{
        ULONG uOSBit = GetOSBit() ;

        if (Inject(TEXT("svchost.exe"), TEXT("d:\\hook.dll")))
        {
                printf ("Inject Success! \r\n") ;
        }
        return 0 ;
}

#endif