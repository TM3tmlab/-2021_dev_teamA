/*st_pchk.h*/
/********************************************************************************/
/*																				*/
/*[システム名]	起動パラメータ解読処理用ヘッダーファイル						*/
/*																				*/
/*[機能概要]	起動パラメータ解読処理用のヘッダーファイル						*/
/*																				*/
/*[特記事項]	なし															*/
/*																				*/
/*[改版履歴]	作成	2021.12.16	yokohamaA	Hanata							*/
/*																				*/
/********************************************************************************/
#ifndef _INCLUDE_ST_
#define _INCLUDE_ST_

/*インクルード宣言*/
#include	<stdlib.h>
#include	<string.h>
#include	"comet_table.h"
#include	"comet_define.h"

/*定義*/
#define RIST_ON			(0)			//リスト表示初期値(表示する)
#define STEP_LIMIT_OFF	(0)			//ステップ数指定(指定なし)
#define STEPNUM_Z		(500)		//ステップ数指定(指定なし)
#define RIST_OFF		(1)			//リスト表示を行わない
#define STEP_LIMIT_ON	(1)			//ステップ数指定
#define STEPNUM_MAX		(2147483647)//最大ステップ数
#define CAPA_COMLINE	(3)			//コマンドライン引数の容量
#define OPTION_R		("-r")		//オプションR
#define OPTION_S		("-s")		//オプションS

/*プロトタイプ宣言*/
//起動パラメータ解読処理
int st_pchk(Toption* k_option_ar,int i_comline,char s_comline[]);

#endif									/*_INCLUDE_ST_*/