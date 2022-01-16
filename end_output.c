/*end_output.c*/
/********************************************************************/
/*																	*/
/*[システム名]	終了結果表示関数									*/
/*																	*/
/*[機能概要]	エラーコードからエラーコード内容を表示。			*/
/*				i_code が下記のエラー一覧のコードと一致した場合、	*/
/*				表示内容を表示し、END_OK を返す。					*/
/*				エラーコード「上記以外」が入ったとき、				*/
/*				表示内容を表示し、END_NGを返す。					*/
/*																	*/
/*[記述形式]	int end_output(int i_code)							*/
/*																	*/
/*[パラメータ]	i_code	(I)		エラーコード						*/
/*																	*/
/*[戻り値]		RESULT_OK	正常終了								*/
/*				END_NG		異常終了								*/
/*																	*/
/*[特記事項]	エラーコード「上記以外」が入ったとき、				*/
/*				表示内容を表示し、END_NGを返す。					*/
/*																	*/
/*[改版履歴]	作成	2021.12.22	********						*/
/*				改訂												*/
/*																	*/
/********************************************************************/
#include "end_output.h"

int end_output(int i_code){
	int i_loop = RESET_Z;
	int i_error[ERROR_NUM] = {RESULT_OK,ERROR_NULL,ERROR_COMLINE,ERROR_OPTION,ERROR_OPTION_N,ERROR_OPTION_S,ERROR_FILE,ERROR_MEMORY,ERROR_OPEN,ERROR_GET,ERROR_OVER};
	char s_coment[ERROR_NUM][SIZE] = {"TRACEE NTD",
									"ファイルが存在しませんでした",
									"実行時の入力に誤りがあります。\n入力例は以下の通り\n./comet [-r] [-s n] 実行可能ファイル",
									"実行時の入力に誤りがあります。\n入力例は以下の通り\n./comet [-r] [-s n] 実行可能ファイル",
									"実行時の入力に誤りがあります。\n入力例は以下の通り\n./comet [-r] [-s n] 実行可能ファイル",
									"ステップ数は2,147,483,648未満で指定してください",
									"実行時の入力に誤りがあります。\n入力例は以下の通り\n./comet [-r] [-s n] 実行可能ファイル",
									"仮想メモリの確保に失敗しました",
									"ファイルを開くのに失敗しました",
									"ファイルサイズの取得に失敗しました",
									"オブジェクトコードのサイズがオーバーしています"};

	for (i_loop = RESET_Z; i_loop <= ERROR_NUM; i_loop++){
		if (i_code == i_error[i_loop]){
			printf("%s\n", s_coment[i_loop]);
			break;
		}
		if (i_loop == ERROR_NUM){
			printf("予期せぬエラーが発生しました\n");
			return END_ERROR;
		}
	}

	return RESULT_OK;
}