/********************************************************************************/
/*                                                                              */
/*[システム名]    IoT開発演習  トレース結果出力関数                             */
/*                                                                              */
/*[機能概要]      トレース結果を表示する。                                      */
/*                                                                              */
/*[特記事項]      なし                                                          */
/*                                                                              */
/*[改版履歴]      作成    2021.12.27  **********                                */
/*                                                                              */
/********************************************************************************/

#ifndef TRACE_OUTPUT_H
#define TRACE_OUTPUT_H

/***** インクルード宣言 *****/
#include <stdio.h>
#include "comet_define.h"
#include "comet_table.h"

/**定数宣言*/
#define NUM_TITLE_DISPLAY (20) /*タイトル表示するステップ数*/
#define NONE_OPR1 (1)		   /*OPR1を空白で表示する*/
#define NONE_OPR2 (2)		   /*OPR2を空白で表示する*/
#define NONE_OPR_EA (4)		   /*EAを空白で表示する*/

/***** プロトタイプ宣言 *****/
int trace_output(Ttracetbl k_trece, int i_stepnum);

#endif /*TRACE_OUTPUT_H*/
