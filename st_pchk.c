/*st_pchk.c*/
/********************************************************************************/
/*																				*/
/*[システム名]	起動パラメータ解読処理											*/
/*																				*/
/*[機能概要]	COMETシミュレータシステムのオプション機能と						*/
/*				パラメータが一致するかチェックをし、各オプション				*/
/*				の値の返しと実行可能ファイル名のポインタを取得する。			*/
/*																				*/
/*[記述形式]	void st_pchk(struct Toption* pk_option,							*/
/*											int i_comline,char* s_comline[])	*/ 
/*																				*/
/*[パラメータ]	char argv	(I)		argv[]アドレスコマンドライン引数			*/
/*				int argc	(I)		コマンドライン引数の数						*/
/*			Toption* pk_option	(O)	実行可能ファイル名ののポインタ				*/
/*							オプションの比較を行った結果を代入する。			*/
/*							初期値は0											*/
/*							RIST_ON(-rの初期化)									*/
/*							STEP_LIMIT_OFF(-sの初期化)							*/
/*							STEPNUM_Z(nの初期化)								*/
/*							比較で一致した１を代入する							*/
/*							RIST_OFF(-rが指定された場合)						*/
/*							STEP_LIMIT_ON(-sが指定された場合)					*/
/*																				*/
/*[戻り値]		RESULT_OK			正常終了									*/
/*				ERROR_OPTION		異常終了(特記事項参照)						*/
/*				ERROR_NULL			異常終了(argcがNULLだった場合)				*/
/*				ERROR_OPTION_S		異常終了									*/
/*						(nの値が0以下または2^31-1よりも大きい場合)				*/
/*				ERROR_OPTION_N		異常終了									*/
/*					(-sが指定されていてnの値が指定されていない場合)				*/
/*				ERROR_FILE			異常終了(実行可能ファイルが指定されていない)*/
/*				ERROR_FILE_OPEN		異常終了(ファイルが開けない)				*/
/*				ERROR_COMLINE		異常終了									*/
/*						(コマンドライン引数が0以下または5以上の場合)			*/
/*																				*/
/*[特記事項]	[-r][-s n]以外のオプションを指定された場合、					*/
/*				ERROR_OPTIONを返す。											*/
/*				2^31-1=2,147,483,647											*/
/*																				*/
/*[改版履歴]	作成	2021.12.16	yokohamaA	Hanata							*/
/*																				*/
/********************************************************************************/
#include "st_pchk.h"

int st_pchk(Toption* k_option, int i_comline,char s_comline[])
{
/*初期化と宣言*/
	int i_loop = RESET_Z;						//ループに使用する
	
	k_option->i_rist = RIST_ON;					//-rリセット
	k_option->i_step = STEP_LIMIT_OFF;			//-sリセット
	k_option->i_stepnum = STEPNUM_Z;			//nリセット
	
/*NULLチェック*/
	while (i_loop <= i_comline){
		if (&s_comline[i_loop] == NULL){
			return ERROR_NULL;
		}
		i_loop++;
	}
	i_loop = RESET_Z;							//初期化

/*パラメータチェック*/
	if (i_comline <= RESET_Z || i_comline >= CAPA_COMLINE){
		return ERROR_COMLINE;
	}
	
/*オプションチェック*/
	while (i_loop <= i_comline){
		//-rオプション指定
		if (&s_comline[i_loop] == OPTION_R){
			k_option->i_rist = RIST_OFF;
			i_loop++;
		}
		//-sオプション指定
		else if (&s_comline[i_loop] == OPTION_S){
			k_option->i_step = STEP_LIMIT_ON;
			i_loop++;
			//次の引数の数よりも大きいまたは'-'付きのオプションであるかチェック
			if (i_loop > i_comline || strncmp(&s_comline[i_loop],"-",1) == 0){
				return ERROR_OPTION_N;
			} else {
				k_option->i_stepnum = atoi(&s_comline[i_loop]);
				if (k_option->i_stepnum < RESET_Z || k_option->i_stepnum > STEPNUM_MAX){
					return ERROR_OPTION_S;
				}
			}
			i_loop++;
		}
		//[-r][-s n]以外のオプションを指定された場合
		else{
			return ERROR_OPTION;
		}
	}
	
	return RESULT_OK;
}