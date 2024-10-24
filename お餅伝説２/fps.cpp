#include "fps.h"

//�O���[�o���ϐ�
FPS fps;

//������
VOID FPSInit(VOID)
{
	//Windows���N�����Ă��猻�݂܂ł̎��Ԃ𓾂�
	fps.FirstTakeTime = GetNowHiPerformanceCount();
	

	//���̒l��������
	fps.NowTakeTime = fps.FirstTakeTime;
	fps.OldTakeTime = fps.FirstTakeTime;
	fps.Deltatime = 0.000001f;
	fps.Average = 60.0f;

	return;
}

VOID FPSCheck(VOID)
{
	//���݂̎���
	fps.NowTakeTime = GetNowHiPerformanceCount();

	//�f���^�^�C�����v�Z
	fps.Deltatime = (fps.NowTakeTime - fps.OldTakeTime) / MicroSecond;

	//���݂̎�����ۑ�
	fps.OldTakeTime = fps.NowTakeTime;

	//���݂�MAX�t���[���ڂȂ�
	if (fps.FrameCount == GameFPS)
	{
		//1�t���[���ځ`MAX�t���[���ڂ܂ł̍��v���Ԃ��v�Z
		float TotalFrameTime = fps.NowTakeTime - fps.FirstTakeTime;

		//���v���Ԃ𗝑z��FPS�l�Ŋ����ĕ��ϒl���v�Z
		float CalcAverage = TotalFrameTime / GameFPS;

		//�P�b������̃t���[�����ɕϊ�
		fps.Average = MicroSecond / CalcAverage;
		
		//1�t���[���ڂ̎������擾
		fps.FirstTakeTime = GetNowHiPerformanceCount();

		//�t���[�������P�ɖ߂�
		fps.FrameCount = 1;

	}
	else
	{
		//�t���[�������J�E���g�A�b�v
		fps.FrameCount;

	}
	return;
}

VOID FPSDraw(VOID)
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "FPS�F%3.1f", fps.Average);
	return;
}

VOID FPSWait(VOID)
{
	int wait = 0;
	wait =
		MicroSecond / GameFPS * fps.FrameCount
		- (fps.NowTakeTime - fps.FirstTakeTime);

	wait /= MillSecond;
	
	if (wait > 0 && wait <= waitTimeMill)
	{
		WaitTimer(wait);
	
	}

	return;

}