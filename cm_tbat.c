/*cm_tabat.c*/
/********************************************************************************/
/*																				*/
/*[システム名]	仮想メモリ確保関数												*/
/*																				*/
/*[機能概要]	OSの管理するメモリ領域から、									*/
/*				共有メモリの領域を仮想メモリとして割り当てる。					*/
/*																				*/
/*[記述形式]	unsigned short* cm_tabat()										*/
/*																				*/
/*[パラメータ]	なし															*/
/*																				*/
/*[戻り値]		puhtad		仮想メモリの先頭アドレス							*/
/*																				*/
/*[特記事項]	なし															*/
/*																				*/
/*[改版履歴]	作成	2021.12.zz	yokohamaA	Hanata							*/
/*				改訂															*/
/*																				*/
/********************************************************************************/
#include "cm_tbat.h"

short unsigned *cm_tbat()
{
    key_t ikey;           /* "key_t" is  typedef. see includes above.*/
    int id;
	short unsigned *puhtad;

    ikey  = (key_t) getuid();   /* getuid --> see system-call manual */

                                /* shared memory getting (system-call) */
    id = shmget( ikey, TSIZE, IPC_CREAT | 0666 );
    if ( id == -1 )
    {
        perror ( "shmget" );
        return 0;
    }
                                /* shared memory attachment (system-call) */
    puhtad = shmat( id, 0, 0 );
    if ( puhtad == (void *)-1 )
    {
        perror ( "shmat" );
        return 0;
    }

    return puhtad;
}