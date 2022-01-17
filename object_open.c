/*object_open.c*/
/*サンプルを元に作成*/
/********************************************************************************/
/*																				*/
/*[システム名]	オブジェクトファイル展開関数									*/
/*																				*/
/*[機能概要]	取得した仮想メモリの先頭アドレスをオブジェクト					*/
/*				展開先アドレスと実行開始アドレスに								*/
/*				加算したそれぞれのアドレスを取得する							*/
/*																				*/
/*[記述形式]	void object_open(struct T_OBJ* pk_obj_ar, 						*/
/*				struct Toption* pkoption unsiged short *puh_1st_adr)			*/
/*																				*/
/*[パラメータ]	T_OBJ* pk_obj_ar	(O)	オブジェクトファイルの情報				*/
/*												が内包された構造体				*/
/*										実行可能ファイル						*/
/*				unsigned short* puh_1st_adr	(O)									*/
/*										仮想メモリの先頭アドレス				*/
/*				Toption* pk_option	(I)	実行可能ファイル名のポインタ			*/
/*																				*/
/*[戻り値]		RESULT_OK			正常終了									*/
/*				ERROR_NULL			異常終了(ポインタがNULL)					*/
/*				ERROR_OPEN			異常終了(展開失敗)							*/
/*				ERROR_GET			異常終了(ファイルサイズ取得失敗)			*/
/*				ERROR_OVER			異常終了									*/
/*				(仮想メモリよりもオブジェクトコードのサイズが大きい)			*/
/*				ERROR_VMEM			異常終了(仮想メモリ確保失敗)				*/
/*				ERROR_READ			異常終了(読み込み失敗)						*/
/*																				*/
/*[特記事項]	なし															*/
/*																				*/
/*[改版履歴]	作成	2021.12.zz	yokohamaA	Hanata							*/
/*																				*/
/********************************************************************************/

#include "object_open.h"
#include <stdio.h>

int object_open(T_OBJ* k_obj_ar, int argc, char* argv[], unsigned short *puh_1st_adr){

	FILE* fpobj;
	struct stat statBuf;
	const char* pfilename;
	unsigned short s[16];
	
/*引数チェック*/
	if (argv[argc - 1] == NULL || puh_1st_adr == NULL){
		return ERROR_NULL;
	}

	pfilename = argv[argc - 1];

/*サイズ取得*/
	if (stat(pfilename, &statBuf) == -1){
		return ERROR_GET;
	}

/*サイズチェック*/
	if(statBuf.st_size > VMEM_MAX){
		return ERROR_OVER;
	}

/*読み込み(ヘッダ部)*/
	int read_num;

/*ファイルオープン*/
	if((fpobj = fopen(pfilename,"r")) == NULL){
		return ERROR_OPEN;
	}
	
/*ヘッダ読み込み*/
	read_num = fread(s, sizeof(char), OBJ_SIZE, fpobj);
	if (read_num != OBJ_SIZE){
		return ERROR_READ;
	}
	k_obj_ar->uh_obj_open = s[0];
	k_obj_ar->uh_init_pr = s[1];
	k_obj_ar->i_code_size = RESET_Z;
	
/*読み込み(オブジェクト部)*/
	//オブジェクトサイズ計算
	if (k_obj_ar->i_code_size == 0){
		k_obj_ar->i_code_size = statBuf.st_size - OBJ_SIZE;
	}
	
	//仮想メモリサイズとの比較
	if ((k_obj_ar->i_code_size + k_obj_ar->uh_obj_open) > VMEM_MAX){
		return ERROR_OVER;
	}
	
	
	//オブジェクト読み込み
	read_num = fread((puh_1st_adr + k_obj_ar->uh_obj_open), sizeof(char), k_obj_ar->i_code_size, fpobj);
	if (read_num != k_obj_ar->i_code_size){
		return ERROR_READ;
	}
	
	fclose(fpobj);
	
	return RESULT_OK;
}