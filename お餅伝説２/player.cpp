#include "player.h"
#include "DxLib.h"
#include "collision.h"



float px, py;
float vx, vy;
float animeTimer;
int animNowType;
int animNowIndex;

int animDirectionOffset;

int animNowPattern;

bool charaMove = false;

sHitRect playerHit;
sHitRect playerFootCollider;
sHitRect playerHeadCollider;

const int animPatternNum = 3;			// �A�j���[�V�����̃p�^�[����
const int animDown = 0;			// ������
const int animLeft = 1;			// ������
const int animRight = 2;			// �E����
const int animUp = 3;			// �����
const int animTypeNum = 4;			// �A�j���[�V�����̎��
const int animSizeX = 32;
const int animSizeY = 32;

const int hitSizeX = 40;
const int hitSizeY = 60;

const float animationFPS = 6.0f;		// �b�� 6�R�}�̃A�j���[�V����
const float moveSpeed = 200.0f;		// �ړ����x (�����Ŏw�肵���l���̃s�N�Z��/�b�i��) 
const int animetion = 11;
bool charaPrev;


int drawOffsetX;
int drawOffsetY;
int charaimg[animPatternNum * animTypeNum];

float time = 0.f;

void PlayerInit(int displaywidth, int displayhight)
{
	px = float(displaywidth / 2);
	py = float(displayhight / 2);
	vx = 0.0f;
	vy = 0.0f;
	animeTimer = 0.0f;
	animNowType = animDown;
	animNowPattern = 0;
	animNowIndex = 0;
	animDirectionOffset = 0;

	//initRect(playerHit,hitSizeX,hitSize)
	LoadDivGraph("chara/pipo-charachip003b.png", animPatternNum * animTypeNum, animPatternNum, animTypeNum, animSizeX, animSizeY, charaimg);
	drawOffsetX = (hitSizeX - animSizeX) / 2;
	drawOffsetY = (hitSizeY - animSizeY);

}

void Playerappdate()
{
	time += 1.0f / 60.f;						//60FPS�͂P�b�Ԃ����炻���time�Ɏ��Ԃ����Ă���

	//0,1,2
	//3,4,5
	//6,7,8
	//9,10,11


	if (time > 1.0f) {							//0,1,2,3-3=0,1,2,,	1�b�ȏ�ɂȂ�Ȃ��悤�ɂ���
		time -= 1.0f;							//�P�b�ȏ�ɂȂ��1�b�}�C�i�X������
		animNowIndex += 1;						//�P�b�ɂȂ�Ɣz��̗v�f�����P���₵�Ă���
		if (animNowIndex >= animPatternNum)		//animNowIndex���A�j���[�V�����̉��v�f���ɂȂ��
		{
			animNowIndex -= animPatternNum;		//�RanimPatternNum��animIndex�Ƀ}�C�i�X������0�`�ɂ��Ă���
		}
	}


	if (CheckHitKey(KEY_INPUT_A))
	{
		px--;
		charaMove = true;
		animDirectionOffset = 3;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		px++;
		charaMove = true;
		animDirectionOffset = 6;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		py++;
		charaMove = true;
		animDirectionOffset = 0;
	}
	if (CheckHitKey(KEY_INPUT_W))
	{
		py--;
		charaMove = true;
		animDirectionOffset = 9;
	}
	if (CheckHitKey(KEY_INPUT_W) == 0 && CheckHitKey(KEY_INPUT_S) == 0 && CheckHitKey(KEY_INPUT_D) == 0 && CheckHitKey(KEY_INPUT_A) == 0)
	{
		charaMove = false;
	}

}

void PlayerDraw() 
 {

	 DrawGraph(static_cast<int>(px) + drawOffsetX, static_cast<int>(py) + drawOffsetY, charaimg[animDirectionOffset + animNowIndex], TRUE);


 }

 void PlayerFinalize()
 {
	 if (charaimg[0] != -1)
	 {
		 for (int i = 0; i < animPatternNum * animTypeNum; i++)
		 {
			 DeleteGraph(charaimg[i]);
		 }
	 }
 }
