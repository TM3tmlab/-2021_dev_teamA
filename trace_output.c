/***************************************************************************************************/
/*                                                                                                 */
/*[システム名]           IoT開発演習  トレース結果出力関数                                         */
/*                                                                                                 */
/*[機能概要]             トレース結果を表示する。                                                  */
/*                                                                                                 */
/*[起動条件／呼出形式]   #include ”trace_output.h”                                               */
/*                       int trace_output (Ttracetbl  k_trace, int i_stepnum)                      */
/*                                                                                                 */
/*[戻り値]               RESULT_OK       正常終了                                                  */
/*                       ERROR_NULL      異常終了(NULLポイントエラー)                              */
/*                                                                                                 */
/*[パラメータ説明]       Ttracetbl          k_trace          (I)トレースリスト用構造体             */
/*                       int                i_stepnum        (I)現在ステップ                       */
/*[特記事項]             空白はタイトルの列に合わせて表示する。                                    */
/*                       トレースリストフォーマット通りにトレースリスト用テーブルを表示すること。  */
/*                       数値は16進数で表記すること。                                              */
/*                       ・ポインタがNULLだった場合、ERROR_NULLを返す。                            */
/*                                                                                                 */
/*[改版履歴]             作成    2021.12.27  **********                                            */
/*                                                                                                 */
/***************************************************************************************************/
#include "trace_output.h"
int trace_output (Ttracetbl k_trace, int i_stepnum)
{
	
    /*タイトル表示判定*/
    if ((i_stepnum % NUM_TITLE_DISPLAY) == 0) {
    	printf("ADR  OPCD OPR1 OPR2 MNE  G I X EA   PR   GR0  GR1  GR2  GR3  GR4  MR FR\n");
    }

    /*ADRを表示*/
    printf("%04x", k_trace.uh_adr);

    /*OPCDを表示*/
    printf(" %04x", k_trace.uh_opcd);

    /*OPR1を表示*/
    if ((k_trace.c_trace_flag & NONE_OPR1) == 0) {
          printf(" %04x", k_trace.uh_opr1);
    } 
    else {
         printf("     ");
    }

    /*OPR2を表示*/
	if((k_trace.c_trace_flag & NONE_OPR2) == 0) {
		printf(" %04x", k_trace.uh_opr2);
	}
	else{
		printf("     ");
	}

    /*MNEを表示*/
	printf(" %-4s", k_trace.ac_mne);
    
	/*Gを表示*/
	printf(" %01x", k_trace.uh_g);
	
    /*Iを表示*/
	printf(" %01x", k_trace.uh_i);
    
	/*Xを表示*/
	printf(" %01x", k_trace.uh_x);
	
    /*EAを表示*/
	if((k_trace.c_trace_flag & NONE_OPR_EA) == 0) {
		printf(" %04x", k_trace.uh_ea);
	}
	else{
		printf("     ");
	}
			
    /*PRを表示*/
	printf(" %04x", k_trace.uh_pr);
	
    /*GR0を表示*/
	printf(" %04x", k_trace.auh_ogr[0]);
	
    /*GR1を表示*/
	printf(" %04x", k_trace.auh_ogr[1]);
	
    /*GR2を表示*/
	printf(" %04x", k_trace.auh_ogr[2]);
	
    /*GR3を表示*/
	printf(" %04x", k_trace.auh_ogr[3]);
	
    /*GR4を表示*/
	printf(" %04x", k_trace.auh_ogr[4]);
	
    /*MRを表示*/
	printf(" %02x", k_trace.uh_mr);
	
    /*FRを表示*/
	printf(" %02x\n", k_trace.uh_fr);

    return RESULT_OK;
}

