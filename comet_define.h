/*comet_define.h*/
/********************************************************************************/
/*																				*/
/*[システム名]	IoT開発演習 COMET共通#defineマクロ								*/
/*																				*/
/*[機能概要]	COMETプログラム共通#defineヘッダファイル						*/
/*																				*/
/*[特記事項]	なし															*/
/*                                                                              */
/*[改版履歴]	作成	2021.12.22	YokohamaA									*/
/*																				*/
/********************************************************************************/
#ifndef COMET_DEFINE_H
#define COMET_DEFINE_H

/*インクルード文*/
#include<stdio.h>

/***** 共通定数 *****/
#define RESET_Z			(0)			/*初期値*/
#define VM_MAX_SIZE		(0x7FFF)	/*仮想メモリ最大サイズ*/
#define GR_NUM			(5)			/*汎用レジスタ個数*/
#define MNE_LEN			(5)			/*ニモニック文字数*/
#define FNC_NUM			(6)			/*命令語個数*/

/*命令語解析ビット操作用*/
#define BIT_MASK_15_8	(0xFF00)	/*OPcode部抽出用*/
#define BIT_SHIFT_15_8	(8)			/*OPcode部シフト計算用*/
#define BIT_MASK_7_4	(0x00F0)	/*R、R1部抽出用*/
#define BIT_SHIFT_7_4	(4)			/*R、R1部シフト計算用*/
#define BIT_MASK_3		(0x0008)	/*I部抽出用*/
#define BIT_SHIFT_3		(3)			/*I部シフト計算用*/
#define BIT_MASK_2_0	(0x0007)	/*XR、IR、R2部抽出用*/

/*シフト命令オーバーフロー判定用*/
#define BIT_MASK_15		(0x8000)	/*SLL命令用*/

/*フラグレジスタビット操作用*/
#define FR_ZERO_FRAG	(0x0001)	/*ゼロフラグ*/
#define FR_SIGN_FRAG	(0x0002)	/*サインフラグ*/
#define FR_OVER_FRAG	(0x0004)	/*オーバーフローフラグ*/

/*フラグレジスタオーバーフロー範囲用*/
#define SHORT_MIN		(-32768)
#define SHORT_MAX		(32767)
#define U_SHORT_MIN		(0)
#define U_SHORT_MAX		(65535)

/*空白表示ビット操作用*/
#define BLANK_ALL		(0x07)		/*OPR1,OPR2,EA全て空白表示*/
#define BLANK_OPR2		(0x02)		/*OPR2のみ空白表示*/

/*OPcode参照用*/
#define OPCD_LD1		(0x14)		/*LD(1語)のOPcode*/
#define OPCD_LD2		(0x10)		/*LD(2語)のOPcode*/
#define OPCD_ST			(0x11)		/*STのOPcode*/
#define OPCD_ADDA		(0x20)		/*ADDAのOPcode*/
#define OPCD_SLL		(0x52)		/*SLLのOPcode*/
#define OPCD_EXIT		(0xa0)		/*EXITのOPcode*/


/***** 復帰値 *****/
/****共通****/
#define RESULT_OK		(0)			/*正常*/
#define ERROR_NULL		(1)		/*異常:ポインタがNULL*/

/*main内エラーコード*/
#define ERROR_MEMORY	(7)		/*メモリ確保エラー*/

/*check_param*/
#define ERROR_COMLINE	(20)		//コマンドラインの数に異常発生
#define ERROR_OPTION_N	(21)		//-sが指定されていてnの値が指定されていない場合
#define ERROR_OPTION_S	(22)		//(nの値が0以下または2^31-1よりも大きい場合
#define ERROR_OPTION	(23)		//指定されていないオプションを指定された場合
#define ERROR_FILE		(24)		//実行可能ファイルが指定されていない
#define ERROR_FILE_OPEN	(25)		//ファイルが開けない

/*object_open*/
#define ERROR_OPEN		(41)		//異常終了(展開失敗)
#define ERROR_GET		(42)		//異常終了(ファイルサイズ取得失敗)
#define ERROR_OVER		(43)		//異常終了(仮想メモリよりもオブジェクトコードのサイズが大きい)
#define ERROR_READ		(44)		//異常終了(読み込み失敗)

/*auto_run*/
#define TRACE_END_HC	(31)		/*異常：メモリ未実装/未定義命令*/
#define TRACE_END_SO	(32)		/*異常：ステップ数オーバー*/
#define TRACE_END_NE	(33)		/*異常：EXITなし*/

/*ea_check*/
#define EA_NG			(60)			/*異常：メモリ未実装/未定義命令*/

/*adrmode_check*/
#define DIR_AM			(0)			/*正常：直接アドレス指定*/
#define IND_AM			(1)			/*正常：インデックスアドレス指定*/
#define IDR_AM			(2)			/*正常：間接アドレス指定*/
#define ERROR_IDR		(90)		/*異常:間接アドレス指定の異常*/

/*end_output*/
#define ERROR_NUM		(99)
#define END_NG			(1)			/*異常*/

#endif  /*COMET_DEFINE_H*/
