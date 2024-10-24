#pragma once

#include "DXlib.h"
//�}�N����`
#define GameFPS    60   //�ݒ肷��FPS

#define MicroSecond       1000000.0f       //1�}�C�N���b�v
#define MillSecond        1000.0f          //1�~���b
#define waitTimeMill       3000			   //�ő�҂����ԁi�~���j

typedef struct _FPS
{
	LONGLONG FirstTakeTime = 0;	           //�f���^�^�C���i�o�ߎ��ԁj		
	LONGLONG NowTakeTime= 0;	           //���݂̌v������
	LONGLONG OldTakeTime = 0;	           //�ȑO�̌v������
	
	float Deltatime = 0.000001f;			//�f���^�^�C���i�o�ߎ��ԁj
	int FrameCount = 1;						//���݂̃t���[�����i1�t���[���ځ`MAX�t���[���߂܂Łj
	float Average = 0.0f;					//����FPS�l

}FPS;

//�O���O���[�o���ϐ�
extern FPS fps;

//�O���v���g�^�C�v�錾
extern  VOID FPSInit(VOID);					//FPS�����l			
extern  VOID FPSCheck(VOID);				//FPS�v��				
extern  VOID FPSDraw(VOID);					//FPS�`��			
extern  VOID FPSWait(VOID);					//FPS�ҋ@			
