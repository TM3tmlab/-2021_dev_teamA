/*****************************************************************************************/
/*                                                                                       */
/*[システム名]    エグジット関数                                                         */
/*                                                                                       */
/*[機能概要]      exit命令を実行する関数                                                 */
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
#include "fnc_exit.h"
int fnc_exit(Ttracetbl *pk_trace, unsigned short *puh_1st_adr)
{
    /*ヌルポインタチェック*/
    if(puh_1st_adr == NULL) {
        return ERROR_NULL;
    }
	
    /*プログラムレジスタ更新*/
	pk_trace->uh_pr += 2;

	/*正常終了*/
	return RESULT_OK;
}
