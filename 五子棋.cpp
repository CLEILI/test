#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<math.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
int js = 1;
void chess()//鼠标落子
{
	settextstyle(20, 20, "楷体");
	outtextxy(1024, 50, "黄色方先手");
	outtextxy(1024, 400, "绿色棋子个数");
	outtextxy(1024, 700, "黄色棋子个数");
	int arr[40][40] = { 0 };
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			arr[i][j] = 0;

		}
	}///数组判定该位置为什么样的棋子
	int a = 0;//a判断棋子状态
	int g1 = 1, y1 = 1;
	char g0[10],y0[10];//个数判断
	FILE *fp;
	fopen_s(&fp, "C:\\Users\\Lenovo\\source\\repos\\Project1\\五子棋存档.txt", "a+");//打开文件
	char s[100] ;
	sprintf_s(s, "%d", js);
	while (1)
	{	MOUSEMSG msg;//鼠标点击位置下棋
		int g = 0, y = 0;//累计棋子个数
		
		msg = GetMouseMsg();
		int m, n, p, q;
		p = (msg.x) / 51;
		q = (msg.y - 24) / 51 + 1;
		m = p * 51;
		n = (q - 1) * 51 + 24;
		double l1, l2, l3, l4, l = 25 * 25;
		if (msg.mkLButton == 1)
		{
			if (msg.x > 1024 || msg.x < 30)//提示不可在界外下棋子
			{
				HWND hnd = GetHWnd();
				MessageBox(hnd, "您已经越界，请重新点击", "提示", MB_OK);
			}
			l1 = pow(msg.x - m, 2) + pow(msg.y - n, 2);
			if (l1 <= l && a == 1 && msg.x <= 980 && msg.x >= 30 && arr[p + 4][q + 4] == 0)//在十字位置下棋/棋子颜色轮换/在棋盘界内下子/判断此处没有zi
			{
				setfillcolor(GREEN);
				fillcircle(m, n, 20.5);
				fprintf_s(fp, "%d\n", js);
				fprintf_s(fp, "%d\n", m);
				fprintf_s(fp, "%d\n", n);
				settextstyle(20, 20, "楷体");
				outtextxy(1024, 50, "到黄色方落子");//落子提示
				sprintf_s(g0, "%d", g1);
				outtextxy(1024, 450, g0);
				outtextxy(1100, 450, "个");
				g1 = g1 + 1;//落子计数
				arr[p + 4][q + 4] = -1;//绿子数组为-1
				a = 0;//此时已下完绿色棋子
				
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
					MessageBox(hnd, "游戏结束，绿色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					goto col;
				}//判断行五子
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
					MessageBox(hnd, "游戏结束，绿色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					goto leftlean;
				}//判断列五子
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
					MessageBox(hnd, "游戏结束，绿色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					goto rightlean;
				}//判断左斜五子
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
					MessageBox(hnd, "游戏结束，绿色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					g = 0;
					continue;
				}//判断右斜
			}
			else if (l1 <= l && msg.x <= 980 && msg.x >= 30 && arr[p + 4][q + 4] == 0)
			{
				setfillcolor(YELLOW);
				fillcircle(m, n, 20.5);
				fprintf_s(fp, "%d\n", js);
				fprintf_s(fp, "%d\n", m);
				fprintf_s(fp, "%d\n", n);
				settextstyle(20, 20, "楷体");
				outtextxy(1024, 50, "到绿色方落子");
				sprintf_s(y0, "%d", y1);
				outtextxy(1024, 750, y0);
				outtextxy(1100, 750, "个");
				y1 = y1 + 1;//落子计数
				arr[p + 4][q + 4] = 1;
				a = 1;//此时已下完黄棋
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
					MessageBox(hnd, "游戏结束，黄色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto cola;
				}//判断行五子
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
					MessageBox(hnd, "游戏结束，黄色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto leftleana;
				}//判断列五子
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
					MessageBox(hnd, "游戏结束，黄色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto rightleana;
				}//判断左斜五子
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
					MessageBox(hnd, "游戏结束，黄色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					continue;
				}//判断右斜

			}

			l2 = pow(msg.x - (m + 51), 2) + pow(msg.y - n, 2);
			if (l2 <= l && a == 1 && msg.x <= 980 && msg.x >= 30 && arr[p + 1 + 4][q + 4] == 0)
			{
				setfillcolor(GREEN);
				fillcircle(m + 51, n, 20.5);
				fprintf_s(fp, "%d\n", js);
				fprintf_s(fp, "%d\n", m+51);
				fprintf_s(fp, "%d\n", n);
				settextstyle(20, 20, "楷体");
				outtextxy(1024, 50, "到黄色方落子");
				sprintf_s(g0, "%d", g1);
				outtextxy(1024, 450, g0);
				outtextxy(1100, 450, "个");
				g1 = g1 + 1;//落子计数
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
					MessageBox(hnd, "游戏结束，绿色方获胜", "提示", MB_OK);
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
					MessageBox(hnd, "游戏结束，绿色方获胜", "提示", MB_OK);
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
					MessageBox(hnd, "游戏结束，绿色方获胜", "提示", MB_OK);
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
					MessageBox(hnd, "游戏结束，绿色方获胜", "提示", MB_OK);
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
				settextstyle(20, 20, "楷体");
				outtextxy(1024, 50, "到绿色方落子");
				sprintf_s(y0, "%d", y1);
				outtextxy(1024, 750, y0);
				outtextxy(1100, 750, "个");
				y1 = y1 + 1;//落子计数
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
					MessageBox(hnd, "游戏结束，黄色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto colb;
				}//判断行五子
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
					MessageBox(hnd, "游戏结束，黄色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto leftleanb;
				}//判断列五子
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
					MessageBox(hnd, "游戏结束，黄色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto rightleanb;
				}//判断左斜五子
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
					MessageBox(hnd, "游戏结束，黄色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					continue;
				}//判断右斜

			}


			l3 = pow(msg.x - (m + 51), 2) + pow(msg.y - (n + 51), 2);
			if (l3 <= l && a == 1 && msg.x <= 980 && msg.x >= 30 && arr[p + 1 + 4][q + 1 + 4] == 0)
			{
				setfillcolor(GREEN);
				fillcircle(m + 51, n + 51, 20.5);
				fprintf_s(fp, "%d\n", js);
				fprintf_s(fp, "%d\n", m+51);
				fprintf_s(fp, "%d\n", n+51);
				settextstyle(20, 20, "楷体");
				outtextxy(1024, 50, "到黄色方落子");
				sprintf_s(g0, "%d", g1);
				outtextxy(1024, 450, g0);
				outtextxy(1100, 450, "个");
				g1 = g1 + 1;//落子计数
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
					MessageBox(hnd, "游戏结束，绿色方获胜", "提示", MB_OK);
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
					MessageBox(hnd, "游戏结束，绿色方获胜", "提示", MB_OK);
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
					MessageBox(hnd, "游戏结束，绿色方获胜", "提示", MB_OK);
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
					MessageBox(hnd, "游戏结束，绿色方获胜", "提示", MB_OK);
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
				settextstyle(20, 20, "楷体");
				outtextxy(1024, 50, "到绿色方落子");
				sprintf_s(y0, "%d", y1);
				outtextxy(1024, 750, y0);
				outtextxy(1100, 750, "个");
				y1 = y1 + 1;//落子计数
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
					MessageBox(hnd, "游戏结束，黄色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto colc;
				}//判断行五子
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
					MessageBox(hnd, "游戏结束，黄色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto leftleanc;
				}//判断列五子
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
					MessageBox(hnd, "游戏结束，黄色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto rightleanc;
				}//判断左斜五子
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
					MessageBox(hnd, "游戏结束，黄色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					continue;
				}//判断右斜

			}


			l4 = pow(msg.x - m, 2) + pow(msg.y - (n + 51), 2);
			if (l4 <= l && a == 1 && msg.x <= 980 && msg.x >= 30 && arr[p + 4][q + 1 + 4] == 0)
			{
				setfillcolor(GREEN);
				fillcircle(m, n + 51, 20.5);
				fprintf_s(fp, "%d\n", js);
				fprintf_s(fp, "%d\n", m);
				fprintf_s(fp, "%d\n", n+51);
				settextstyle(20, 20, "楷体");
				outtextxy(1024, 50, "到黄色方落子");
				sprintf_s(g0, "%d", g1);
				outtextxy(1024, 450, g0);
				outtextxy(1100, 450, "个");
				g1 = g1 + 1;//落子计数
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
					MessageBox(hnd, "游戏结束，绿色方获胜", "提示", MB_OK);
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
					MessageBox(hnd, "游戏结束，绿色方获胜", "提示", MB_OK);
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
					MessageBox(hnd, "游戏结束，绿色方获胜", "提示", MB_OK);
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
					MessageBox(hnd, "游戏结束，绿色方获胜", "提示", MB_OK);
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
				settextstyle(20, 20, "楷体");
				outtextxy(1024, 50, "到绿色方落子");
				sprintf_s(y0, "%d", y1);
				outtextxy(1024, 750, y0);
				outtextxy(1100, 750, "个");
				y1 = y1 + 1;//落子计数
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
					MessageBox(hnd, "游戏结束，黄色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto cold;
				}//判断行五子
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
					MessageBox(hnd, "游戏结束，黄色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto leftleand;
				}//判断列五子
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
					MessageBox(hnd, "游戏结束，黄色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					goto rightleand;
				}//判断左斜五子
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
					MessageBox(hnd, "游戏结束，黄色方获胜", "提示", MB_OK);
					fclose(fp);
					break;
				}
				else
				{
					y = 0;
					continue;
				}//判断右斜

			}

			
		}
	}
}

void foundboard()
{
	initgraph(1300, 966);
	IMAGE img;
	loadimage(&img, "D:/图片/五子棋盘新.jpg");
	putimage(0, 0, &img);//加载一个棋盘图片，左上角像素51，24,每个格51*51

}
void time()
{
	int a = 0;
	char s[100];
	while (1)
	{
		sprintf_s(s, "%d", a);
		settextstyle(20, 20, "楷体");
		outtextxy(1024, 50, s);
		outtextxy(1100, 50, "秒");
		Sleep(1000);
		a = a + 1;
	}

}
void read()
{
	int m, n,j,k,a = 0, q;
	int arr[30][30];
	FILE *fp;
	fopen_s(&fp, "C:\\Users\\Lenovo\\source\\repos\\Project1\\五子棋存档.txt", "r+");
	char s[10];
	
	InputBox(s, 8, "请输入想要读取的对局序号", "存档","1",0,0,false);
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
	loadimage(&img, "D:/图片/初始界面.jpg");
	putimage(0, 0,1024,966,&img,0,0);
	settextstyle(60, 30, "黑体");
	outtextxy(400, 470, "开始游戏");
	outtextxy(400, 600, "读取存档");
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
	mciSendString("open D:\\音乐\\ddz.mp3 alias ddz", 0, 0, 0);
	mciSendString("play ddz repeat", 0, 0, 0);
}
void clear()
{
	FILE *fp;
	fopen_s(&fp, "C:\\Users\\Lenovo\\source\\repos\\Project1\\五子棋存档.txt", "w");
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
