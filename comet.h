/*comet.h*/
/********************************************************************************/
/*																				*/
/*[システム名]	COMETシミュレータメイン用ヘッダーファイル						*/
/*																				*/
/*[機能概要]	COMETシミュレータメイン用のヘッダーファイル						*/
/*																				*/
/*[特記事項]	なし															*/
/*																				*/
/*[改版履歴]	作成	2021.12.16	yokohamaA	Hanata							*/
/*																				*/
/********************************************************************************/
#ifndef _INCLUDE_COMET_
#define _INCLUDE_COMET_

/*インクルード宣言*/
#include "comet_define.h"
#include "comet_table.h"
#include "st_pchk.h"
#include "cm_tbat.h"
#include "object_open.h"
#include "auto_run.h"
#include "end_output.h"

/*定義*/
#define CAPA_PARAMETER_MIN	(1)			//コマンドライン引数容量最小
#define CAPA_PARAMETER_MAX	(5)			//コマンドライン引数容量最大

#endif									/*_INCLUDE_COMET_*/