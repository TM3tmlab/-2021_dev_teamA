/*end_output.h*/
/********************************************************************/
/*																	*/
/*[システム名]	終了結果表示関数用ヘッダーファイル					*/
/*																	*/
/*[機能概要]	終了結果表示関数用のヘッダーファイル				*/
/*																	*/
/*[特記事項]	なし												*/
/*																	*/
/*[改版履歴]	作成	2021.12.22	*******							*/
/*																	*/
/********************************************************************/
#ifndef _INCLUDE_END_
#define _INCLUDE_END_

/*インクルード宣言*/
#include <stdio.h>
#include "comet_define.h"

/*定義*/
#define SIZE		128		//s_comentの容量
#define RESULT_NUM	12		//エラーコードの個数(正常終了も含む)

/*戻り値*/

#define END_ERROR	-60		//異常終了(エラーコード「上記以外」が入ったとき、表示内容を表示し、END_NGを返す。)

/*プロトタイプ宣言*/
int end_output(int i_code);

#endif						/*_INCLUDE_END_*/