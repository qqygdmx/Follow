#ifndef __HAL_MUSIC_H__ 
#define __HAL_MUSIC_H__ 


//���������������ֵ��λ��Hz��
#define L1 262 // c 
#define L2 294 // d 
#define L3 330 // e 
#define L4 349 // f 
#define L5 392 // g 
#define L6 440 // a1 
#define L7 494 // b1

//����������������ֵ��λ��Hz��
#define M1 523 // c1 
#define M2 587 // d1 
#define M3 659 // e1 
#define M4 698 // f1 
#define M5 784 // g1 
#define M6 880 // a2 
#define M7 988 // b2 

//���������������ֵ��λ��Hz��
#define H1 1047 // c2 
#define H2 1175 // d2 
#define H3 1319 // e2 
#define H4 1397 // f2 
#define H5 1568 // g2 
#define H6 1760 // a3 
#define H7 1976 // b3 

//����ʱֵ��λ�����������ٶȣ���ֵ��λ��ms��
#define T 3600
//���������ṹ
typedef struct 
{ 
	short mName; //������ȡֵL1~L7,M1~M7,H1~H7�ֱ��ʾ���� ���� ������1234567��ȡֵ0��ʾ��ֹ��
	short mTime; //ʱֵ��ȡֵT T/2 T/4 T/8 T/16 T/32�ֱ��ʾȫ���� �������� �ķ����� �˷�����...,ȡֵ0��ʾ�������

}tNote;

//��������
extern void musicPlay(void); 
#endif // __MUSIC_H__ 
  
