#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<math.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
int js = 1;
void chess()//�������
{
	settextstyle(20, 20, "����");
	outtextxy(1024, 50, "��ɫ������");
	outtextxy(1024, 400, "��ɫ���Ӹ���");
	outtextxy(1024, 700, "��ɫ���Ӹ���");
	int arr[40][40] = { 0 };
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			arr[i][j] = 0;

		}
	}///�����ж���λ��Ϊʲô��������
	int a = 0;//a�ж�����״̬
	int g1 = 1, y1 = 1;
	char g0[10],y0[10];//�����ж�
	FILE *fp;
	fopen_s(&fp, "C:\\Users\\Lenovo\\source\\repos\\Project1\\������浵.txt", "a+");//���ļ�
	char s[100] ;
	sprintf_s(s, "%d", js);
	while (1)
	{	MOUSEMSG msg;//�����λ������
		int g = 0, y = 0;//�ۼ����Ӹ���
		
		msg = GetMouseMsg();
		int m, n, p, q;
		p = (msg.x) / 51;
		q = (msg.y - 24) / 51 + 1;
		m = p * 51;
		n = (q - 1) * 51 + 24;
		double l1, l2, l3, l4, l = 25 * 25;
		if (msg.mkLButton == 1)
		{
			if (msg.x > 1024 || msg.x < 30)//��ʾ�����ڽ���������
			{
				HWND hnd = GetHWnd();
				MessageBox(hnd, "���Ѿ�Խ�磬�����µ��", "��ʾ", MB_OK);
			}
			l1 = pow(msg.x - m, 2) + pow(msg.y - n, 2);
			if (l1 <= l && a == 1 && msg.x <= 980 && msg.x >= 30 && arr[p + 4][q + 4] == 0)//��ʮ��λ������/������ɫ�ֻ�/�����̽�������/�жϴ˴�û��zi
			{
				setfillcolor(GREEN);
				fillcircle(m, n, 20.5);
				fprintf_s(fp, "%d\n", js);
				fprintf_s(fp, "%d\n", m);
				fprintf_s(fp, "%d\n", n);
				settextstyle(20, 20, "����");
				outtextxy(1024, 50, "����ɫ������");//������ʾ
				sprintf_s(g0, "%d", g1);
				outtextxy(1024, 450, g0);
				outtextxy(1100, 450, "��");
				g1 = g1 + 1;//���Ӽ���
				arr[p + 4][q + 4] = -1;//��������Ϊ-1
				a = 0;//��ʱ��������ɫ����
				
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 4 - i][q + 4] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 4 - i][q + 4] != -1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 4 + i][q + 4] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 4 + i][q + 4] != -1)
					{
						break;
					}
				}
				if (g >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					goto col;
				}//�ж�������
			col:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 4][q + 4 - i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 4][q + 4 - i] != -1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 4][q + 4 + i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 4][q + 4 + i] != -1)
					{
						break;
					}
				}
				if (g >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					goto leftlean;
				}//�ж�������
			leftlean:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 4 - i][q + 4 - i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 4 - i][q + 4 - i] != -1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 4 + i][q + 4 + i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 4 + i][q + 4 + i] != -1)
					{
						break;
					}
				}
				if (g >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					goto rightlean;
				}//�ж���б����
			rightlean:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 4 - i][q + 4 + i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 4 - i][q + 4 + i] != -1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 4 + i][q + 4 - i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 4 + i][q + 4 - i] != -1)
					{
						break;
					}
				}
				if (g >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					continue;
				}//�ж���б
			}
			else if (l1 <= l && msg.x <= 980 && msg.x >= 30 && arr[p + 4][q + 4] == 0)
			{
				setfillcolor(YELLOW);
				fillcircle(m, n, 20.5);
				fprintf_s(fp, "%d\n", js);
				fprintf_s(fp, "%d\n", m);
				fprintf_s(fp, "%d\n", n);
				settextstyle(20, 20, "����");
				outtextxy(1024, 50, "����ɫ������");
				sprintf_s(y0, "%d", y1);
				outtextxy(1024, 750, y0);
				outtextxy(1100, 750, "��");
				y1 = y1 + 1;//���Ӽ���
				arr[p + 4][q + 4] = 1;
				a = 1;//��ʱ���������
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 4 - i][q + 4] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 4 - i][q + 4] != 1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 4 + i][q + 4] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 4 + i][q + 4] != 1)
					{
						break;
					}
				}
				if (y >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto cola;
				}//�ж�������
			cola:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 4][q + 4 - i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 4][q + 4 - i] != 1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 4][q + 4 + i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 4][q + 4 + i] != 1)
					{
						break;
					}
				}
				if (y >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto leftleana;
				}//�ж�������
			leftleana:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 4 - i][q + 4 - i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 4 - i][q + 4 - i] != 1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 4 + i][q + 4 + i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 4 + i][q + 4 + i] != 1)
					{
						break;
					}
				}
				if (y >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto rightleana;
				}//�ж���б����
			rightleana:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 4 - i][q + 4 + i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 4 - i][q + 4 + i] != 1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 4 + i][q + 4 - i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 4 + i][q + 4 - i] != 1)
					{
						break;
					}
				}
				if (y >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					continue;
				}//�ж���б

			}

			l2 = pow(msg.x - (m + 51), 2) + pow(msg.y - n, 2);
			if (l2 <= l && a == 1 && msg.x <= 980 && msg.x >= 30 && arr[p + 1 + 4][q + 4] == 0)
			{
				setfillcolor(GREEN);
				fillcircle(m + 51, n, 20.5);
				fprintf_s(fp, "%d\n", js);
				fprintf_s(fp, "%d\n", m+51);
				fprintf_s(fp, "%d\n", n);
				settextstyle(20, 20, "����");
				outtextxy(1024, 50, "����ɫ������");
				sprintf_s(g0, "%d", g1);
				outtextxy(1024, 450, g0);
				outtextxy(1100, 450, "��");
				g1 = g1 + 1;//���Ӽ���
				arr[p + 1 + 4][q + 4] = -1;
				a = 0;
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 1 + 4 - i][q + 4] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 1 + 4 - i][q + 4] != -1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 1 + 4 + i][q + 4] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 1 + 4 + i][q + 4] != -1)
					{
						break;
					}
				}
				if (g >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					goto col1;
				}
			col1:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 1 + 4][q + 4 - i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 1 + 4][q + 4 - i] != -1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 1 + 4][q + 4 + i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 1 + 4][q + 4 + i] != -1)
					{
						break;
					}
				}
				if (g >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					goto leftlean1;
				}
			leftlean1:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 1 + 4 - i][q + 4 - i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 1 + 4 - i][q + 4 - i] != -1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 1 + 4 + i][q + 4 + i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 1 + 4 + i][q + 4 + i] != -1)
					{
						break;
					}
				}
				if (g >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					goto rightlean1;
				}
			rightlean1:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 1 + 4 - i][q + 4 + i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 1 + 4 - i][q + 4 + i] != -1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 1 + 4 + i][q + 4 - i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 1 + 4 + i][q + 4 - i] != -1)
					{
						break;
					}
				}
				if (g >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					continue;
				}
			}
			else if (l2 <= l && msg.x <= 980 && msg.x >= 30 && arr[p + 1 + 4][q + 4] == 0)
			{
				setfillcolor(YELLOW);
				fillcircle(m + 51, n, 20.5);
				fprintf_s(fp, "%d\n", js);
				fprintf_s(fp, "%d\n", m+51);
				fprintf_s(fp, "%d\n", n);
				settextstyle(20, 20, "����");
				outtextxy(1024, 50, "����ɫ������");
				sprintf_s(y0, "%d", y1);
				outtextxy(1024, 750, y0);
				outtextxy(1100, 750, "��");
				y1 = y1 + 1;//���Ӽ���
				arr[p + 1 + 4][q + 4] = 1;
				a = 1;
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 1 + 4 - i][q + 4] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 1 + 4 - i][q + 4] != 1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 1 + 4 + i][q + 4] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 1 + 4 + i][q + 4] != 1)
					{
						break;
					}
				}
				if (y >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto colb;
				}//�ж�������
			colb:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 1 + 4][q + 4 - i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 1 + 4][q + 4 - i] != 1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 1 + 4][q + 4 + i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 1 + 4][q + 4 + i] != 1)
					{
						break;
					}
				}
				if (y >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto leftleanb;
				}//�ж�������
			leftleanb:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 1 + 4 - i][q + 4 - i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 1 + 4 - i][q + 4 - i] != 1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 1 + 4 + i][q + 4 + i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 1 + 4 + i][q + 4 + i] != 1)
					{
						break;
					}
				}
				if (y >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto rightleanb;
				}//�ж���б����
			rightleanb:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 1 + 4 - i][q + 4 + i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 1 + 4 - i][q + 4 + i] != 1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 1 + 4 + i][q + 4 - i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 1 + 4 + i][q + 4 - i] != 1)
					{
						break;
					}
				}
				if (y >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					continue;
				}//�ж���б

			}


			l3 = pow(msg.x - (m + 51), 2) + pow(msg.y - (n + 51), 2);
			if (l3 <= l && a == 1 && msg.x <= 980 && msg.x >= 30 && arr[p + 1 + 4][q + 1 + 4] == 0)
			{
				setfillcolor(GREEN);
				fillcircle(m + 51, n + 51, 20.5);
				fprintf_s(fp, "%d\n", js);
				fprintf_s(fp, "%d\n", m+51);
				fprintf_s(fp, "%d\n", n+51);
				settextstyle(20, 20, "����");
				outtextxy(1024, 50, "����ɫ������");
				sprintf_s(g0, "%d", g1);
				outtextxy(1024, 450, g0);
				outtextxy(1100, 450, "��");
				g1 = g1 + 1;//���Ӽ���
				arr[p + 1 + 4][q + 1 + 4] = -1;
				a = 0;
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 1 + 4 - i][q + 1 + 4] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 1 + 4 - i][q + 1 + 4] != -1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 1 + 4 + i][q + 1 + 4] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 1 + 4 + i][q + 1 + 4] != -1)
					{
						break;
					}
				}
				if (g >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					goto col2;
				}
			col2:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 1 + 4][q + 1 + 4 - i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 1 + 4][q + 1 + 4 - i] != -1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 1 + 4][q + 1 + 4 + i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 1 + 4][q + 1 + 4 + i] != -1)
					{
						break;
					}
				}
				if (g >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					goto leftlean2;
				}
			leftlean2:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 1 + 4 - i][q + 1 + 4 - i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 1 + 4 - i][q + 1 + 4 - i] != -1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 1 + 4 + i][q + 1 + 4 + i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 1 + 4 + i][q + 1 + 4 + i] != -1)
					{
						break;
					}
				}
				if (g >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					goto rightlean2;
				}
			rightlean2:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 1 + 4 - i][q + 1 + 4 + i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 1 + 4 - i][q + 1 + 4 + i] != -1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 1 + 4 + i][q + 1 + 4 - i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 1 + 4 + i][q + 1 + 4 - i] != -1)
					{
						break;
					}
				}
				if (g >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					continue;
				}
			}
			else if (l3 <= l && msg.x <= 980 && msg.x >= 30 && arr[p + 1 + 4][q + 1 + 4] == 0)
			{
				setfillcolor(YELLOW);
				fillcircle(m + 51, n + 51, 20.5);
				fprintf_s(fp, "%d\n", js);
				fprintf_s(fp, "%d\n", m+51);
				fprintf_s(fp, "%d\n", n+51);
				settextstyle(20, 20, "����");
				outtextxy(1024, 50, "����ɫ������");
				sprintf_s(y0, "%d", y1);
				outtextxy(1024, 750, y0);
				outtextxy(1100, 750, "��");
				y1 = y1 + 1;//���Ӽ���
				arr[p + 1 + 4][q + 1 + 4] = 1;
				a = 1;
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 1 + 4 - i][q + 1 + 4] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 1 + 4 - i][q + 1 + 4] != 1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 1 + 4 + i][q + 1 + 4] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 1 + 4 + i][q + 1 + 4] != 1)
					{
						break;
					}
				}
				if (y >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto colc;
				}//�ж�������
			colc:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 1 + 4][q + 1 + 4 - i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 1 + 4][q + 1 + 4 - i] != 1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 1 + 4][q + 1 + 4 + i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 1 + 4][q + 1 + 4 + i] != 1)
					{
						break;
					}
				}
				if (y >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto leftleanc;
				}//�ж�������
			leftleanc:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 1 + 4 - i][q + 1 + 4 - i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 1 + 4 - i][q + 1 + 4 - i] != 1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 1 + 4 + i][q + 1 + 4 + i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 1 + 4 + i][q + 1 + 4 + i] != 1)
					{
						break;
					}
				}
				if (y >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto rightleanc;
				}//�ж���б����
			rightleanc:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 1 + 4 - i][q + 1 + 4 + i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 1 + 4 - i][q + 1 + 4 + i] != 1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 1 + 4 + i][q + 1 + 4 - i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 1 + 4 + i][q + 1 + 4 - i] != 1)
					{
						break;
					}
				}
				if (y >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					continue;
				}//�ж���б

			}


			l4 = pow(msg.x - m, 2) + pow(msg.y - (n + 51), 2);
			if (l4 <= l && a == 1 && msg.x <= 980 && msg.x >= 30 && arr[p + 4][q + 1 + 4] == 0)
			{
				setfillcolor(GREEN);
				fillcircle(m, n + 51, 20.5);
				fprintf_s(fp, "%d\n", js);
				fprintf_s(fp, "%d\n", m);
				fprintf_s(fp, "%d\n", n+51);
				settextstyle(20, 20, "����");
				outtextxy(1024, 50, "����ɫ������");
				sprintf_s(g0, "%d", g1);
				outtextxy(1024, 450, g0);
				outtextxy(1100, 450, "��");
				g1 = g1 + 1;//���Ӽ���
				arr[p + 4][q + 1 + 4] = -1;
				a = 0;
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 4 - i][q + 1 + 4] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 4 - i][q + 1 + 4] != -1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 4 + i][q + 1 + 4] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 4 + i][q + 1 + 4] != -1)
					{
						break;
					}
				}
				if (g >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					goto col3;
				}
			col3:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 4][q + 1 + 4 - i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 4][q + 1 + 4 - i] != -1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 4][q + 1 + 4 + i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 4][q + 1 + 4 + i] != -1)
					{
						break;
					}
				}
				if (g >=5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					goto leftlean3;
				}
			leftlean3:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 4 - i][q + 1 + 4 - i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 4 - i][q + 1 + 4 - i] != -1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 4 + i][q + 1 + 4 + i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 4 + i][q + 1 + 4 + i] != -1)
					{
						break;
					}
				}
				if (g >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					goto rightlean3;
				}
			rightlean3:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 4 - i][q + 1 + 4 + i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 4 - i][q + 1 + 4 + i] != -1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 4 + i][q + 1 + 4 - i] == -1)
					{
						g = g + 1;
					}
					if (arr[p + 4 + i][q + 1 + 4 - i] != -1)
					{
						break;
					}
				}
				if (g >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					continue;
				}
			}
			else if (l4 <= l && msg.x <= 980 && msg.x >= 30 && arr[p + 4][q + 1 + 4] == 0)
			{
				setfillcolor(YELLOW);
				fillcircle(m, n + 51, 20.5);
				fprintf_s(fp, "%d\n", js);
				fprintf_s(fp, "%d\n", m);
				fprintf_s(fp, "%d\n", n+51);
				settextstyle(20, 20, "����");
				outtextxy(1024, 50, "����ɫ������");
				sprintf_s(y0, "%d", y1);
				outtextxy(1024, 750, y0);
				outtextxy(1100, 750, "��");
				y1 = y1 + 1;//���Ӽ���
				arr[p + 4][q + 1 + 4] = 1;
				a = 1;
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 4 - i][q +1+ 4] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 4 - i][q +1+ 4] != 1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 4 + i][q +1+ 4] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 4 + i][q +1+ 4] != 1)
					{
						break;
					}
				}
				if (y >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto cold;
				}//�ж�������
			cold:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 4][q +1+ 4 - i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 4][q +1+ 4 - i] != 1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 4][q +1+ 4 + i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 4][q +1+ 4 + i] != 1)
					{
						break;
					}
				}
				if (y >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto leftleand;
				}//�ж�������
			leftleand:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 4 - i][q +1+ 4 - i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 4 - i][q +1+ 4 - i] != 1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 4 + i][q +1+ 4 + i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 4 + i][q +1+ 4 + i] != 1)
					{
						break;
					}
				}
				if (y >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto rightleand;
				}//�ж���б����
			rightleand:
				for (int i = 0; i <= 4; i++)
				{
					if (arr[p + 4 - i][q +1+ 4 + i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 4 - i][q +1+ 4 + i] != 1)
					{
						break;
					}
				}
				for (int i = 1; i <= 4; i++)
				{
					if (arr[p + 4 + i][q +1+ 4 - i] == 1)
					{
						y = y + 1;
					}
					if (arr[p + 4 + i][q +1+ 4 - i] != 1)
					{
						break;
					}
				}
				if (y >= 5)
				{
					HWND hnd = GetHWnd();
					MessageBox(hnd, "��Ϸ��������ɫ����ʤ", "��ʾ", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					continue;
				}//�ж���б

			}

			
		}
	}
}

void foundboard()
{
	initgraph(1300, 966);
	IMAGE img;
	loadimage(&img, "D:/ͼƬ/����������.jpg");
	putimage(0, 0, &img);//����һ������ͼƬ�����Ͻ�����51��24,ÿ����51*51

}
void time()
{
	int a = 0;
	char s[100];
	while (1)
	{
		sprintf_s(s, "%d", a);
		settextstyle(20, 20, "����");
		outtextxy(1024, 50, s);
		outtextxy(1100, 50, "��");
		Sleep(1000);
		a = a + 1;
	}

}
void read()
{
	int m, n,j,k,a = 0, q;
	int arr[30][30];
	FILE *fp;
	fopen_s(&fp, "C:\\Users\\Lenovo\\source\\repos\\Project1\\������浵.txt", "r+");
	char s[10];
	
	InputBox(s, 8, "��������Ҫ��ȡ�ĶԾ����", "�浵","1",0,0,false);
	int p = atoi(s);
	foundboard();
	while (feof(fp)==0)
	{
		fscanf_s(fp, "%d", &q);
		fscanf_s(fp, "%d", &m);
		fscanf_s(fp, "%d", &n);
		j = m / 51;
		k = (n - 24) / 51 + 1;
		if (p == q)
		{
			if (a == 0&&arr[j][k]!=1)
			{
				setfillcolor(YELLOW);
				fillcircle(m, n, 20.5);
				arr[j][k] = 1;
				a = 1;
				Sleep(500);
				continue;
			}
			if (a == 1&&arr[j][k] != 1)
			{
				setfillcolor(GREEN);
				fillcircle(m, n, 20.5);
				arr[j][k] = 1;
				a = 0;
				Sleep(500);
				continue;
			}
		}
	}
	fclose(fp);
}
void foundstart()
{
	A:initgraph(1024, 1024);
	IMAGE img;
	loadimage(&img, "D:/ͼƬ/��ʼ����.jpg");
	putimage(0, 0,1024,966,&img,0,0);
	settextstyle(60, 30, "����");
	outtextxy(400, 470, "��ʼ��Ϸ");
	outtextxy(400, 600, "��ȡ�浵");
	while (1)
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		if (m.mkLButton == 1)
		{
			if (m.x > 400 && m.x < 630 && m.y>470 && m.y < 540)

			{
				break;

			}
			if (m.x > 400 && m.x < 630 && m.y>600 && m.y < 670)
			{
				read();
				goto A;

			}
		}
	}

}
void music()
{
	mciSendString("open D:\\����\\ddz.mp3 alias ddz", 0, 0, 0);
	mciSendString("play ddz repeat", 0, 0, 0);
}
void clear()
{
	FILE *fp;
	fopen_s(&fp, "C:\\Users\\Lenovo\\source\\repos\\Project1\\������浵.txt", "w");
	fclose(fp);
}
int main()
{

	clear();
	A:foundstart();
	foundboard();
	music();
	chess(); 
	js = js + 1;
	goto A;
	return 0;
}
