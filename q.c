#include <stdio.h> //4�� ť �Է¹���
#include <stdlib.h>
#include<ctype.h>

#define TRUE 1
#define FALSE 0
#define LEN 20


typedef struct
{
	int front; //��
	int rear; //��
	char qarr[LEN]; // ť������ �迭

}Queue;


void Init_Queue(Queue* pQ); //ť �ʱ�ȭ �Լ�
int IsEmpty_Queue(Queue* pQ); //ť�� ����ִ��� Ȯ���ϴ� �Լ�
void Enqueue(Queue* pQ, char data); //ť �߰� �Լ�
void Dequeue(Queue* pQ); //ť ����, ������ ��ȯ �Լ�

int main()
{
	char str[LEN]; //�Է� ���� ���� �迭
	char *p = &str; //������ ��Ű�� ���� ���� ���� ����Ű�� ������ ���� ����
	int i, num = 0;

	Queue q; //ť ���۷��� ����
	Init_Queue(&q); //ť �ʱ�ȭ

	while (1) {

		for (i = 0; i<20; i++)	str[i] = ""; //�Է� ���ڿ� �ʱ�ȭ

		printf("���� �Է�>>> ");
		gets(str); //�Է� �ޱ�

		if (isalpha(p[0])) //���ĺ��̸� ť ���� 
		{
			for (i = 0; i < strlen(str); i++)
				Enqueue(&q, p[i]);
		}
		else { //�����̸� ť ��������
			if (strlen(str) == 2) {//���ڸ� �����̸�
				num = p[1] - 48;
				num += (p[0] - 48) * 10; //���ڸ� ����������
			}
			else //�� �ڸ� ����
				num = p[0] - 48; //���ڸ� ����������
			for (i = 0; i < num; i++)
			Dequeue(&q); //��������
		}
	}

}


void Init_Queue(Queue* pQ) //ť �ʱ�ȭ 
{
	int i;

	pQ->front = -1;
	pQ->rear = -1;

	for (i = 0; i<20; i++)
		pQ->qarr[i] = "";
}



int IsEmpty_Queue(Queue* pQ)
{
	if (pQ->rear == 0) //rear�� 0�̸� �����
		return TRUE;
	else
		return FALSE;
}

int IsFull(Queue* pQ)
{
	if (pQ->rear == LEN - 1) //�� �ڸ� ����Ų�ٸ� �� ��
		return TRUE;
	else
		return FALSE;
}




void Enqueue(Queue* pQ, char data) //ť ����
{
	if (IsFull(pQ)) //�� á����
	{
		printf("ADDQUEUE(%c) Fail : Queue Full     Queue Size = 20 / 20\n", data);
		return;
	}
	else
	{
		pQ->front = 0;
		pQ->rear++; //rear�ϳ� ����
		pQ->qarr[pQ->rear] = data; //�̵��� ���� ������ ����
		printf("ADDQUEUE(%c)    Queue Size = %d / 20\n", data, (pQ->rear)+1);
		return;
	}
}


void Dequeue(Queue* pQ) //ť ��������
{
	int i, j;
	if (IsEmpty_Queue(pQ)) //ť�� ������� Ȯ��
	{
		printf("ť�� ����ֽ��ϴ�!\n");
		return;
	}
	else //�� ����ٸ�
	{
			printf("DELETEQUEUE( ) = %c, Queue Size = %d/ 20\n", pQ->qarr[pQ->front], (pQ->rear) - (pQ->front)); //���ֱ����� ���
			pQ->qarr[pQ->front] = " "; //�������� ���ֱ�
			pQ->front++; //front �ϳ� ���� 

			for (j = pQ->front; j <= pQ->rear; j++) 
				pQ->qarr[j - 1] = pQ->qarr[j]; //������ �����ֱ�
			
			pQ->front--; 
			pQ->rear--;//front, rear �ϳ��� ����
			
		}
		return;
	
}









