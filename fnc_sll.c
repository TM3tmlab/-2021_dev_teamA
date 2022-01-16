/*****************************************************************************************/
/*                                                                                       */
/*[システム名]    論理左シフト関数                                                       */
/*                                                                                       */
/*[機能概要]      命令語SLLを実行する                                                    */
/*                                                                                       */
/*[記述形式]      int fnc_sll(Ttracetbl  *pk_trace, unsigned short *puh_1st_adr )        */
/*                                                                                       */
/*[パラメータ]    Ttracetbl       *pk_trace     (I/O)トレースリスト用構造体              */
/*                unsigned short  *puh_1st_adr  (I)仮想メモリの先頭アドレス              */
/*                                                                                       */
/*[戻り値]        RESULT_OK         正常終了                                             */
/*                                                                                       */
/*[特記事項]      なし                                                                   */
/*                                                                                       */
/*[改版履歴]      作成    2021.12.22  **********                                         */
/*                                                                                       */
/*****************************************************************************************/
#include "fnc_sll.h"
int fnc_sll(Ttracetbl *pk_trace, unsigned short *puh_1st_adr)
{
    (void)puh_1st_adr;              /*SLL関数では先頭アドレスを使用しない*/
    
    /*変数宣言*/
    unsigned short uh_over_flag;    /*オーバーフロー判断用*/
    
    /*計算処理*/
    pk_trace->auh_ogr[pk_trace->uh_g] <<= (pk_trace->uh_ea - 1);
    uh_over_flag = pk_trace->auh_ogr[pk_trace->uh_g] & BIT_MASK_15;
    pk_trace->auh_ogr[pk_trace->uh_g] <<= 1;
    
    /*フラグの初期化*/
    pk_trace->uh_fr = 0x0000;
    
    /*ゼロフラグ判定*/
    if((short)pk_trace->auh_ogr[pk_trace->uh_g] == 0) {
        pk_trace->uh_fr |= FR_ZERO_FRAG;
    }
    
    /*サインフラグ判定*/
    if((short)(pk_trace->auh_ogr[pk_trace->uh_g]) < 0){
		pk_trace->uh_fr |= FR_SIGN_FRAG;
	}
	
	/*オーバーフローフラグ判定*/
	if(uh_over_flag != 0) {
	    pk_trace->uh_fr |= FR_OVER_FRAG;
	}
	
	/*プログラムレジスタ更新*/
	pk_trace->uh_pr += 2;
	
	/*正常終了*/
	return RESULT_OK;
}
