/********************************************************************************************************************************************************************/
/*                                                                                                                                                                   */
/*       [システム名]               アドレッシングモード解析関数                                                                                                     */
/*       [機能概要]                 命令のアドレッシングモードを解析する関数。                                                                                       */
/*       [起動条件／呼出形式]       #include “adomode_check.h”                                                                                                     */
/*                                  int adrmode_check(Ttracetbl* pk_trace,unsigned short* puh_1st_adr)                                                               */  
/*                                                                                                                                                                   */
/*                                                                                                                                                                   */
/*       [戻り値]                   DAI_AM			    直接アドレス指定                                                                                             */
/*                                  IND_AM				インデックスアドレス指定                                                                                     */
/*                                  IDR_AM				間接アドレス指定                                                                                             */
/*                                  EROOR_NULL			異常終了(ＮULLポインタエラー)                                                                                */
/*                                                                                                                                                                   */
/*       [パラメータ説明]           Ttracetbl*               pk_trace          (I)オプションの内容が内包された構造体                                                 */
/*                                  unsigned short*          puh_1st_adr       (I)オブジェクトファイルの情報が内包された構造体                                       */
/*                                                                                                                                                                   */
/*       [特記事項]                                                                                                                                                  */
/*                                                                                                                                                                   */
/*       [改版履歴]                 作成   2021.1.13                                                                                                                 */
/*                                                                                                                                                                   */
/*********************************************************************************************************************************************************************/

#include"adrmode_check.h"
#define IDR_ON 1
#define IDR_OFF 0

int adrmode_check(Ttracetbl* pk_trace, unsigned short *puh_1st_adr)
{
	if (puh_1st_adr == NULL) {
	
		return ERROR_NULL;
	}
	pk_trace->uh_i = (*(puh_1st_adr + pk_trace->uh_pr) & 0x0008) >> 3;  //間接アドレス指定3bit目
	pk_trace->uh_x =(*(puh_1st_adr + pk_trace->uh_pr) & 0x0007); //インデックスアドレス指定または、R２0-2bit目
	switch (pk_trace->uh_i) {
	case (IDR_ON):
	
		return IDR_AM; 
	
	case (IDR_OFF):
		if (pk_trace->uh_x == 0){
			return DIR_AM;
		}
		return IND_AM;
	default:
		return ERROR_IDR;
	}
}