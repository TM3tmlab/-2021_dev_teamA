/*object_open.h*/
/********************************************************************/
/*																	*/
/*[システム名]	オブジェクトファイル展開関数用ヘッダーファイル		*/
/*																	*/
/*[機能概要]	オブジェクトファイル展開関数用のヘッダーファイル	*/
/*																	*/
/*[特記事項]	なし												*/
/*																	*/
/*[改版履歴]	作成	2021.12.zz	yokohamaA	Hanata				*/
/*																	*/
/********************************************************************/
#ifndef _INCLUDE_OBJ_
#define _INCLUDE_OBJ_

/*インクルード宣言*/
#include "comet_table.h"
#include "comet_define.h"
#include <stdio.h>
#include <sys/stat.h>

#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>

/*定義*/
#define OBJ_SIZE		(32)		//オブジェクトのヘッダ長
#define OBJ_MIN			(2)			//オブジェクト最小サイズ
#define VMEM_MAX		(0x7FFF)	//仮想メモリの最大サイズ

/*戻り値*/

/*プロトタイプ宣言*/
int object_open(T_OBJ* k_obj_ar, int argc, char* argv[], unsigned short* puh_1st_adr);

#endif									/*_INCLUDE_OBJ_*/