#include <stdio.h> //4번 큐 입력문제
#include <stdlib.h>
#include<ctype.h>

#define TRUE 1
#define FALSE 0
#define LEN 20


typedef struct
{
	int front; //앞
	int rear; //뒤
	char qarr[LEN]; // 큐데이터 배열

}Queue;


void Init_Queue(Queue* pQ); //큐 초기화 함수
int IsEmpty_Queue(Queue* pQ); //큐가 비어있는지 확인하는 함수
void Enqueue(Queue* pQ, char data); //큐 추가 함수
void Dequeue(Queue* pQ); //큐 삭제, 데이터 반환 함수

int main()
{
	char str[LEN]; //입력 받은 문장 배열
	char *p = &str; //원본을 지키기 위해 원본 문장 가리키는 포인터 변수 생성
	int i, num = 0;

	Queue q; //큐 래퍼런스 생성
	Init_Queue(&q); //큐 초기화

	while (1) {

		for (i = 0; i<20; i++)	str[i] = ""; //입력 문자열 초기화

		printf("문장 입력>>> ");
		gets(str); //입력 받기

		if (isalpha(p[0])) //알파벳이면 큐 삽입 
		{
			for (i = 0; i < strlen(str); i++)
				Enqueue(&q, p[i]);
		}
		else { //숫자이면 큐 가져오기
			if (strlen(str) == 2) {//두자리 숫자이면
				num = p[1] - 48;
				num += (p[0] - 48) * 10; //문자를 정수형으로
			}
			else //한 자리 숫자
				num = p[0] - 48; //문자를 정수형으로
			for (i = 0; i < num; i++)
			Dequeue(&q); //가져오기
		}
	}

}


void Init_Queue(Queue* pQ) //큐 초기화 
{
	int i;

	pQ->front = -1;
	pQ->rear = -1;

	for (i = 0; i<20; i++)
		pQ->qarr[i] = "";
}



int IsEmpty_Queue(Queue* pQ)
{
	if (pQ->rear == 0) //rear이 0이면 비었음
		return TRUE;
	else
		return FALSE;
}

int IsFull(Queue* pQ)
{
	if (pQ->rear == LEN - 1) //맨 뒤를 가리킨다면 꽉 참
		return TRUE;
	else
		return FALSE;
}




void Enqueue(Queue* pQ, char data) //큐 삽입
{
	if (IsFull(pQ)) //꽉 찼으면
	{
		printf("ADDQUEUE(%c) Fail : Queue Full     Queue Size = 20 / 20\n", data);
		return;
	}
	else
	{
		pQ->front = 0;
		pQ->rear++; //rear하나 증가
		pQ->qarr[pQ->rear] = data; //이동한 곳에 데이터 저장
		printf("ADDQUEUE(%c)    Queue Size = %d / 20\n", data, (pQ->rear)+1);
		return;
	}
}


void Dequeue(Queue* pQ) //큐 가져오기
{
	int i, j;
	if (IsEmpty_Queue(pQ)) //큐가 비었는지 확인
	{
		printf("큐가 비어있습니다!\n");
		return;
	}
	else //안 비었다면
	{
			printf("DELETEQUEUE( ) = %c, Queue Size = %d/ 20\n", pQ->qarr[pQ->front], (pQ->rear) - (pQ->front)); //없애기전에 출력
			pQ->qarr[pQ->front] = " "; //공백으로 없애기
			pQ->front++; //front 하나 증가 

			for (j = pQ->front; j <= pQ->rear; j++) 
				pQ->qarr[j - 1] = pQ->qarr[j]; //앞으로 땡겨주기
			
			pQ->front--; 
			pQ->rear--;//front, rear 하나씩 감소
			
		}
		return;
	
}









