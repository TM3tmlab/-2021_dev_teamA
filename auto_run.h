/********************************************************************************/
/*                                                                              */
/*[�����ƥ�̾]    IoT��ȯ�齬 �����ȥ⡼�ɴؿ��ѥإå����ե�����                */
/*                                                                              */
/*[��ǽ����]      �����ȥ⡼�ɴؿ��ѤΥإå����ե�����                          */
/*                                                                              */
/*[�õ�����]      �ʤ�                                                          */
/*                                                                              */
/*[��������]      ����    2021.12.20  **********                                */
/*                                                                              */
/********************************************************************************/ 

#ifndef AUTO_RUN_H
#define AUTO_RUN_H

/***** ���󥯥롼����� *****/
#include <string.h>
#include "comet_define.h"
#include "comet_table.h"
#include "ea_check.h"
#include "fnc_ld1.h"
#include "fnc_ld2.h"
#include "fnc_st.h"
#include "fnc_adda.h"
#include "fnc_sll.h"
#include "fnc_exit.h"
#include "trace_output.h"

/***** �ץ�ȥ�������� *****/
/*�����ȥ⡼�ɴؿ�*/
int auto_run(Toption k_option_ar, T_OBJ k_obj_ar, unsigned short *puh_1st_adr);

#endif      /*AUTO_RUN_H*/
