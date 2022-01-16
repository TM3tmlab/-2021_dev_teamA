/********************************************************************************/
/*                                                                              */
/*[システム名]    IoT開発演習 有効アドレス解析関数                              */
/*                                                                              */
/*[機能概要]      有効アドレスを解析する                                        */
/*                                                                              */
/*[記述形式]      int ea_check(Ttracetbl *pk_trace,                             */
/*                                  unsigned short *puh_1st_adr)                */
/*                                                                              */
/*[パラメータ]    Ttracetbl *pk_trace (I/O)                                     */
/*                    トレースの際に用いる情報が内包された構造体                */
/*                    命令コード/オペランドコード1/オペランドコード2/           */
/*                    汎用レジスタ番号、またはR1/間接アドレス指定/              */
/*                    インデックスレジスタ番号、又は間接レジスタ番号、又はR2/   */
/*                    有効アドレス/トレースリストフラグを出力する               */
/*                unsigned short *puh_1st_adr (I)                               */
/*                    仮想メモリの先頭アドレス                                  */
/*                                                                              */
/*[戻り値]        EA_OK    正常終了                                             */
/*                EA_EG    異常終了                                             */
/*                                                                              */
/*[特記事項]      なし                                                          */
/*                                                                              */
/*[改版履歴]      作成    2019.08.09  **********                                */
/*                改訂    2019.08.21  **********                                */
/*                        インデックスアドレス指定の修正                        */
/*                改訂    2019.08.22  **********                                */
/*                        シフト命令の修正                                      */
/*                        未実装命令の空白表示を変更                            */
/*                        レジスタが異常な数値だった場合の挙動を修正            */
/*                                                                              */
/*                                                                              */
/********************************************************************************/

#include "ea_check.h"

int ea_check(Ttracetbl *pk_trace, unsigned short *puh_1st_adr)
{
    int i_reg_flag = 0;   //レジスタの値が正しいなら0、正しくないなら1

	/***** エラーチェック *****/
	/*OPcodeの確認及びチェック*/
	pk_trace->uh_opcd = *(puh_1st_adr + pk_trace->uh_pr);
	switch(pk_trace->uh_opcd >> BIT_SHIFT_15_8) {
	case OPCD_LD1:
    	/* FALL THROUGH */
	case OPCD_LD2:
    	/* FALL THROUGH */
	case OPCD_ST:
    	/* FALL THROUGH */
	case OPCD_ADDA:
	    /* FALL THROUGH */
	case OPCD_SLL:
	    /* FALL THROUGH */
	case OPCD_EXIT:
		/* DO NOTHING */
		break;
	default:
        pk_trace->c_trace_flag = BLANK_ALL;
        pk_trace->uh_g = 0;
        pk_trace->uh_i = 0;
        pk_trace->uh_x = 0;
		return EA_NG;
	}

	/*汎用レジスタ番号の代入及びチェック*/
	pk_trace->uh_g = (*(puh_1st_adr + pk_trace->uh_pr) & BIT_MASK_7_4) >> BIT_SHIFT_7_4;
	if(pk_trace->uh_g >= GR_NUM) {
        i_reg_flag = 1;
		pk_trace->uh_ea = 0;
	}

	/*インデックスレジスタ番号の代入及びチェック*/
	pk_trace->uh_x = (*(puh_1st_adr + pk_trace->uh_pr) & BIT_MASK_2_0);
	if(pk_trace->uh_x >= GR_NUM) {
        i_reg_flag = 1;
		pk_trace->uh_ea = 0;
	}

	/***** 有効アドレス解析 *****/
	switch(pk_trace->uh_opcd >> BIT_SHIFT_15_8) {
	case OPCD_LD1:                  /*1語命令*/
					/* FALL THROUGH */
	case OPCD_EXIT:                 /*1語命令*/
		pk_trace->uh_ea = 0;
		pk_trace->uh_opr1 = 0;
		pk_trace->uh_opr2 = 0;
		pk_trace->uh_i = 0;
		pk_trace->c_trace_flag = BLANK_ALL;
        /*i,xが正しいか*/
        if(i_reg_flag == 1) {
            return EA_NG;
        }
		break;
	default:                        /*それ以外*/
		pk_trace->c_trace_flag = BLANK_OPR2;
		pk_trace->uh_opr1 = *(puh_1st_adr + pk_trace->uh_pr + 1);
		pk_trace->uh_opr2 = 0;

        /*i,xが正しいか*/
        if(i_reg_flag == 1) {
            return EA_NG;
        }

		switch(adrmode_check(pk_trace, puh_1st_adr)) {
		case DIR_AM:                /*直接アドレス指定or即値アドレス指定*/
			if((pk_trace->uh_opcd >> BIT_SHIFT_15_8) == OPCD_SLL) {	/*即値アドレス指定*/
				pk_trace->uh_ea = *(puh_1st_adr + pk_trace->uh_pr + 1);
			} else {												/*直接アドレス指定*/
				pk_trace->uh_ea = *(puh_1st_adr + pk_trace->uh_pr + 1);
			}
				break;
		case IND_AM:                /*インデックスアドレス指定*/
			pk_trace->uh_ea = pk_trace->auh_ogr[pk_trace->uh_x] + *(puh_1st_adr + pk_trace->uh_pr + 1);
			break;
		case IDR_AM:                /*間接アドレス指定*/
			pk_trace->uh_ea = pk_trace->auh_ogr[pk_trace->uh_x];
			break;
		default:
			/* DO NOTHING */
			break;
		}
		break;
	}
	
	/*シフト命令なら有効アドレスが最大を超えてもエラーではない*/
	if((pk_trace->uh_opcd >> BIT_SHIFT_15_8) == OPCD_SLL) {
		return RESULT_OK;
	}
	
	/*有効アドレス解析のチェック*/
	if(pk_trace->uh_ea > VM_MAX_SIZE) {
		return EA_NG;
	}

	return RESULT_OK;
}
