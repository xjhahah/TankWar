//̹�˴�ս
//0����ʾ����               ���
//1���߿�                  ���
//2��ָ��λ����ʾ�Լ���̹��         ���
//3������̹�����ŷ����������       ���
	 //getasynkeustae            ���
	 //Sleep(����)                ���   
	 //������˸                    ���
	 //����˸                      ���
	 //SetConsoleCursorPosition   ���   
//4��ָ��λ����ʾ�з�̹��           ���
//5���з�̹���Լ�������             ���
		//�����                  ���
		//�ٶȿ���                ���
		//��̹��λ�����           ���


//6������̹�ˣ����ո�����ӵ�       
	  //���ո�� �����ӵ�          ���
	  //�����ӵ�����               ���
	  //ɾ��                      ���
	  //���ӵ��ŵ�������           ���
	  //�ӵ�������                 ���
	  //�ӵ�ײ����ʧ               ���
	  //�ӵ�̹���غ�bug            ���
//7���з�̹���Զ����ӵ�
//8�������Լ���boss
//9�������ϰ���
//10���ӵ���ײ   �����ж� 
//11����ȫ������
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>

#define BACK_WIDE   22
#define BACK_HIGHT  22

//����ö��
enum { enum_east, enum_south, enum_west, enum_north };

//��ʾ��ʾ����
void StartIU();
//���������ʼ��Ϸ
void StartGame();
//���������ʼ��Ϸ
void ClearIU();

//��ʾ�߿�
void ShowBackGroud();
//����̹�˷���
void ControlDis();
//���ѷ�̹���µ�λ�������ڱ�����
void SetOurNewPos();
//���ü�ס�µ�λ��
void RememOurOldPos();
//��վɵ�����λ��
void ClearOurOldPos();
//�з���̹���Զ�������
void DiTankeRun();
//�з�̹������仯
void SetDiNewPos();
//�з�̹���������õ�������
void SetDiNewPosToBack();
//��յз�̹��ԭ����λ��
void ClearDiOldPos();
//��ס�з�̹���µ�����
void RemeDiNewPos();
//�����ӵ�����
void CreateDanList(struct Node* *pHead, struct Node* *pEnd, int x, int y, int dis);
//�������
void ClearList(struct Node* *pHead, struct Node* *pEnd);
//���ӵ��ŵ�������
void SetDanToBack(struct Node *pHead);
//�ӵ�������
void DanRun();
//�ӵ�����仯
void DanPosChange(struct Node *pHead);
//�ӵ��ɵ�λ�����
void ClearDanOldPos(struct Node *pHead);
//ɾ�������ڵ�
struct Node* ClearOutDan(struct Node* *pHead, struct Node* *pEnd, struct Node *pTemp);
