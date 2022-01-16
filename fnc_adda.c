/*****************************************************************************************/
/*                                                                                       */
/*[システム名]    算術加算関数                                                           */
/*                                                                                       */
/*[機能概要]      命令語ADDAを実行する。                                                 */
/*                                                                                       */
/*[記述形式]      int fnc_adda(Ttracetbl *pk_trace, unsigned short *puh_1st_adr )        */
/*                                                                                       */
/*[パラメータ]    Ttracetbl       *pk_trace     (I/O)トレースリスト用構造体              */
/*                unsigned short  *puh_1st_adr  (I)仮想メモリの先頭アドレス              */
/*                                                                                       */
/*[戻り値]        RESULT_OK         正常終了                                             */
/*                ERROR_NULL        異常終了(NULLポイントエラー)                         */
/*                                                                                       */
/*[特記事項]      なし                                                                   */
/*                                                                                       */
/*[改版履歴]      作成    2021.12.22  **********                                         */
/*                                                                                       */
/*****************************************************************************************/
#include "fnc_adda.h"
int fnc_adda(Ttracetbl* pk_trace, unsigned short *puh_1st_adr)
{
    /*変数宣言*/
    int i_sum;            //合計変数
    
    /*ヌルポインタチェック*/
    if(puh_1st_adr == NULL) {
        return ERROR_NULL;
    }
	
	/*計算処理*/
	i_sum = (int)((short)*(puh_1st_adr + pk_trace->uh_ea) + (short)pk_trace->auh_ogr[pk_trace->uh_g]);
	
	/*計算結果をデスティネーションへ代入*/
	pk_trace->auh_ogr[pk_trace->uh_x] = (unsigned short)i_sum;
	
	/*フラグの初期化*/
	pk_trace->uh_fr = 0x0000;
	
	/*ゼロフラグ判定*/
	if((short)(pk_trace->auh_ogr[pk_trace->uh_g] == 0)) {
		pk_trace->uh_fr |= FR_ZERO_FRAG;
	}
	
	/*サインフラグ判定*/
	if((short)((pk_trace->auh_ogr[pk_trace->uh_g]) & 0x10) == 0x10){
		pk_trace->uh_fr |= FR_SIGN_FRAG;
	}
		
	/*オーバーフローフラグ判定*/
	if(i_sum < SHORT_MIN || i_sum > SHORT_MAX) {
		pk_trace->uh_fr |= FR_OVER_FRAG;
	}
	
	/*プログラムレジスタ更新*/
	pk_trace->uh_pr += 2;
		
    /*正常終了*/
	return RESULT_OK;

}