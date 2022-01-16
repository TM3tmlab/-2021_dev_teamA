/********************************************************************************/
/*                                                                              */
/*[システム名]    IoT開発演習 オートモード関数用ヘッダーファイル                */
/*                                                                              */
/*[機能概要]      オートモード関数用のヘッダーファイル                          */
/*                                                                              */
/*[特記事項]      なし                                                          */
/*                                                                              */
/*[改版履歴]      作成    2021.12.20  **********                                */
/*                                                                              */
/********************************************************************************/ 

#ifndef AUTO_RUN_H
#define AUTO_RUN_H

/***** インクルード宣言 *****/
#include <string.h>
#include "comet_define.h"
#include "comet_table.h"
#include "ea_check.h"
#include "fnc_ld1.h"
#include "fnc_ld2.h"
#include "fnc_st.h"
#include "fnc_adda.h"
#include "fnc_sll.h"
#include "fnc_exit.h"
#include "trace_output.h"

/***** プロトタイプ宣言 *****/
/*オートモード関数*/
int auto_run(Toption k_option_ar, T_OBJ k_obj_ar, unsigned short *puh_1st_adr);

#endif      /*AUTO_RUN_H*/
