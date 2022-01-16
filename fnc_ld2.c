/*****************************************************************************************/
/*                                                                                       */
/*[�����ƥ�̾]    ����2��ؿ�                                                          */
/*                                                                                       */
/*[��ǽ����]      OPCode��OP��0x10ͭ�����ɥ쥹����Ȥ�Ҥ����ꤹ��ؿ�                   */
/*                                                                                       */
/*[���ҷ���]      int fnc_ld2(Ttracetbl  *pk_trace, unsigned short *puh_1st_adr )        */
/*                                                                                       */
/*[�ѥ�᡼��]    Ttracetbl       *pk_trace     (I/O)�ȥ졼���ꥹ���ѹ�¤��              */
/*                unsigned short  *puh_1st_adr  (I)���ۥ������Ƭ���ɥ쥹              */
/*                                                                                       */
/*[�����]        RESULT_OK         ���ｪλ                                             */
/*                                                                                       */
/*[�õ�����]      �ʤ�                                                                   */
/*                                                                                       */
/*[��������]      ����    2021.12.21  **********                                         */
/*                                                                                       */
/*****************************************************************************************/
#include "fnc_ld2.h"

int fnc_ld2(Ttracetbl *pk_trace, unsigned short *puh_1st_adr)
{
	/*�̥�ݥ��󥿥����å�*/
    if(puh_1st_adr == NULL) {
        return ERROR_NULL;
    }
	
	/*���ɽ���*/
	pk_trace->auh_ogr[pk_trace->uh_g] = *(puh_1st_adr + pk_trace->uh_ea);

	/*�ե饰�ν����*/
	pk_trace->uh_fr = 0x0000;
	
	/*����ե饰Ƚ��*/

	if((short)pk_trace->auh_ogr[pk_trace->uh_g] == 0) {
		pk_trace->uh_fr |= FR_ZERO_FRAG;
	}
	
	/*������ե饰Ƚ��*/
	if((short)(pk_trace->auh_ogr[pk_trace->uh_g]) < 0) {
		pk_trace->uh_fr |= FR_SIGN_FRAG;
	}

	/*�ץ����쥸��������*/
	pk_trace->uh_pr += 2;
	
	/*���ｪλ*/
	return RESULT_OK;
}
