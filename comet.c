/*comet.c*/
/********************************************************************************/
/*																				*/
/*[システム名]	COMETシミュレータメイン											*/
/*																				*/
/*[機能概要]	仮想メモリ上のオブジェクトプログラムを実行し、					*/
/*				そのトレースリストを標準出力する								*/
/*																				*/
/*[記述形式]	./comet [-r] [-s n] executable									*/
/*																				*/
/*[パラメータ]	executable	(I)	実行ファイル名称、リスト						*/
/*				-r			(I)	オプション指定された場合、						*/
/*								トレース出力しない。							*/
/*				-s			(I)	オプション指定された場合、						*/
/*								nステップまでで命令実行を						*/
/*								打ち切きる。-sオプションを						*/
/*								省略すると、500ステップで						*/
/*				n			(I)	打切りとなる。									*/
/*																				*/
/*[戻り値]		RESULT_OK	正常終了											*/
/*				i_code		異常終了											*/
/*																				*/
/*[特記事項]	なし															*/
/*																				*/
/*[改版履歴]	作成	2021.12.16	yokohamaA	Hanata							*/
/*				改訂															*/
/*																				*/
/********************************************************************************/
#include "comet_define.h"
#include "comet.h"
#include "comet_table.h"
#include <stdio.h>

int main(int argc,char* argv[])
{

/*初期化と宣言*/
	int i_code = RESULT_OK;					//戻り値を確保する場所

	short unsigned *puh_1st_adr = RESET_Z;	//仮想メモリの先頭アドレスを確保する場所


/*構造体変数初期化*/
	//オプション用テーブル
	Toption k_option_ar = {
		RIST_ON,STEP_LIMIT_OFF,STEPNUM_Z,
	};
	//オブジェクト用テーブル
	T_OBJ k_obj_ar ={
		RESET_Z,RESET_Z,RESET_Z,
	};

/*コマンドラインチェック*/
	if (argc <= CAPA_PARAMETER_MIN || argc > CAPA_PARAMETER_MAX){
		i_code = ERROR_COMLINE;
	}

/*パラメータチェック関数*/
	if (i_code == RESULT_OK){
		i_code = st_pchk(&k_option_ar, argc, argv);
	}

/*仮想メモリ確保関数*/
	if (i_code == RESULT_OK){
		puh_1st_adr = cm_tbat();
		if(puh_1st_adr == RESET_Z){
			i_code = ERROR_MEMORY;
		}
	}


/*オブジェクトファイル展開関数*/
	if (i_code == RESULT_OK){
		i_code = object_open(&k_obj_ar, argc, argv, puh_1st_adr);
	}

/*オードモード関数*/
	if (i_code == RESULT_OK){
		i_code = auto_run(k_option_ar, k_obj_ar, puh_1st_adr);
	}

/*結果表示関数*/
	end_output(i_code);
	if (i_code != RESULT_OK){
		return i_code;
	}

	return RESULT_OK;
}