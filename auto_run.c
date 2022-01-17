/*********************************************************************************************************************************************************************/
/*                                                                                                                                                                   */
/*       [システム名]               オートモード関数                                                                                                                 */
/*       [機能概要]                 オブジェクトコードの展開された仮想メモリから1命令ずつ取り出してexit命令を処理するまで以下を繰り返す。                            */
/*                                  オブジェクトコードを解析する関数、実行する関数、トレースを出力する関数。                                                         */
/*       [起動条件／呼出形式]       #include “auto_run.h”                                                                                                          */
/*                                  int auto_run(Toption k_option, T_OBJ k_obj_ar, unsigned short* puh_1st_adr)                                                      */
/*       [戻り値]                   RESULT_OK                        正常終了                                                                                        */
/*                                  TRACE_END_HC                     異常終了(メモリ未実装未定義命令)                                                                */
/*                                  TRACE_END_SO                     異常終了(ステップ数異常)                                                                        */
/*                                  ERROR_NULL                       異常終了(NULLポイントエラー)                                                                    */
/*       [パラメータ説明]           Toption k_option_ar              (I)オプションの内容が内包された構造体                                                           */
/*                                  T_OBJ   k_obj_ar                 (I)オブジェクトファイルの情報が内包された構造体                                                 */
/*                                  unsigned short *puh_1st_short    (I)仮想メモリの先頭アドレス                                                                     */
/*       [特記事項]                 1.実行中にメモリ未実装アドレスにアクセスするか、未定義の命令を実行しようとした場合は、異常終了(メモリ未実装未定義命令)とする。   */
/*                                  2.指定ステップ数を超えて命令を実行しようとした場合は、異常終了(ステップ数異常)とする。                                           */
/*                                  3.ポインタがNULLだった場合、ERROR_NULLを返す。                                                                                   */
/*       [改版履歴]                 作成   2021.12.20                                                                                                                */
/*                                                                                                                                                                   */
/*********************************************************************************************************************************************************************/


#include "auto_run.h"
#include <stdio.h>

int auto_run(Toption k_option_ar, T_OBJ k_obj_ar, unsigned short* puh_1st_adr)
{
    /*変数宣言*/
    /*トレースリスト用構造体 初期化*/
    Ttracetbl k_trace_ar ={
    	0, 0, 0, 0, "", 0, 0, 0, 0, k_obj_ar.uh_init_pr, {0, 0, 0, 0, VM_MAX_SIZE},
    };

    /*命令解析用構造体 初期化*/
    T_FNC k_fnc_ar[FNC_NUM] = { { OPCD_LD1, "LD", fnc_ld1 },
                                 { OPCD_LD2, "LD", fnc_ld2 },
                                 { OPCD_ST, "ST", fnc_st },
                                 { OPCD_ADDA, "ADDA", fnc_adda },
                                 { OPCD_SLL, "SLL", fnc_sll },
                                 { OPCD_EXIT, "EXIT", fnc_exit } };
    int i;                   //ループカウント用変数1
    int i2;                 //ループカウント用変数2
    int i_return_hc;        //有効アドレス解析関数復帰値
    int (*pi_do_func)();    //実行関数ポインタ
    
    /*ヌルポインタチェック*/
    if(puh_1st_adr == NULL) {
        return ERROR_NULL;
    }
    
    /*処理・トレースループ 最大ステップ数を超えるまで*/
    for(i = 0; i < k_option_ar.i_stepnum; i++) {
        k_trace_ar.uh_adr = k_trace_ar.uh_pr;
        /*プログラムレジスタのチェック*/
        if(k_trace_ar.uh_pr > VM_MAX_SIZE){
             return TRACE_END_HC;
        }
        i_return_hc = ea_check(&k_trace_ar, puh_1st_adr);
             
        /*戻り値のヌルチェック*/
        if(i_return_hc == ERROR_NULL) {
            return ERROR_NULL;
        }
        
        /*関数ポインタで命令関数呼び出し＆エモニック代入*/
        for(i2 = 0; i2 < FNC_NUM; i2++) {
            if(k_fnc_ar[i2].uh_opcd == (k_trace_ar.uh_opcd >> BIT_SHIFT_15_8)) {
                 strcpy(k_trace_ar.ac_mne, k_fnc_ar[i2].ac_mne);
                 pi_do_func = k_fnc_ar[i2].func;
                 break;
            }
            strcpy(k_trace_ar.ac_mne, "   ");
        }
        
        /*有効アドレス解析関数が正常終了なら命令関数系呼び出し*/
        if(i_return_hc == RESULT_OK) {
            i_return_hc = (*pi_do_func)(&k_trace_ar, puh_1st_adr);
        }
        
        /*戻り値のヌルチェック*/
        if(i_return_hc == ERROR_NULL) {
            return ERROR_NULL;
        }
        
        /*-rオプションがなければトレース結果出力関数呼び出し*/
        if(k_option_ar.i_rist == 0) {
             trace_output(k_trace_ar, i);
        }
        
        /*HADRDWARE CHECKEDではないか*/
        if(i_return_hc == 1) {
            return TRACE_END_HC;
        }
        
        /*EXITだったら正常終了*/
        if(strcmp(k_trace_ar.ac_mne, "EXIT") == 0) {
            return RESULT_OK;
        }
    }
    
    return TRACE_END_SO;
}                                    