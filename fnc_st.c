/*****************************************************************************************/
/*                                                                                       */
/*[システム名]    ストア関数                                                             */
/*                                                                                       */
/*[機能概要]      Rを有効アドレスが示す番地に設定する関数                                */
/*                                                                                       */
/*[記述形式]      int fnc_st(Ttracetbl  *pk_trace, unsigned short *puh_1st_adr )         */
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
#include "fnc_st.h"
int fnc_st(Ttracetbl *pk_trace, unsigned short *puh_1st_adr)
{
	/*ヌルポインタチェック*/
    if(puh_1st_adr == NULL) {
        return ERROR_NULL;
    }
	
    /*ストア処理*/
    pk_trace->uh_ea = pk_trace->auh_ogr[pk_trace->uh_g];

    /*プログラムレジスタ更新*/
	pk_trace->uh_pr += 2;

	/*正常終了*/
	return RESULT_OK;
}
