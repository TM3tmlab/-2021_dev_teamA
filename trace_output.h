/********************************************************************************/
/*                                                                              */
/*[�����ƥ�̾]    IoT��ȯ�齬  �ȥ졼����̽��ϴؿ�                             */
/*                                                                              */
/*[��ǽ����]      �ȥ졼����̤�ɽ�����롣                                      */
/*                                                                              */
/*[�õ�����]      �ʤ�                                                          */
/*                                                                              */
/*[��������]      ����    2021.12.27  **********                                */
/*                                                                              */
/********************************************************************************/

#ifndef TRACE_OUTPUT_H
#define TRACE_OUTPUT_H

/***** ���󥯥롼����� *****/
#include <stdio.h>
#include "comet_define.h"
#include "comet_table.h"

/**������*/
#define NUM_TITLE_DISPLAY (20) /*�����ȥ�ɽ�����륹�ƥå׿�*/
#define NONE_OPR1 (1)		   /*OPR1������ɽ������*/
#define NONE_OPR2 (2)		   /*OPR2������ɽ������*/
#define NONE_OPR_EA (4)		   /*EA������ɽ������*/

/***** �ץ�ȥ�������� *****/
int trace_output(Ttracetbl k_trece, int i_stepnum);

#endif /*TRACE_OUTPUT_H*/
