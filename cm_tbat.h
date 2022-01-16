/*cm_tabat.h*/
/********************************************************************************/
/*																				*/
/*[システム名]	仮想メモリ確保関数用ヘッダーファイル							*/
/*																				*/
/*[機能概要]	仮想メモリ確保関数用のヘッダーファイル							*/
/*																				*/
/*[特記事項]	なし															*/
/*																				*/
/*[改版履歴]	作成	2021.12.zz	yokohamaA	Hanata							*/
/*																				*/
/********************************************************************************/
#ifndef _INCLUDE_TABAT_
#define _INCLUDE_TABAT_

/*インクルード宣言*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h> 

/*定義*/
#define TSIZE				68608

/*プロトタイプ宣言*/
//仮想メモリ確保関数
short unsigned* cm_tbat();

void *shmat();

#endif									/*_INCLUDE_TABAT_*/