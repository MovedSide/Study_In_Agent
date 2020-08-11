#include "gamepanel.h"


gamepanel::gamepanel()
{

	set_edge();
	set_alltile();
	print_game();
}

void gamepanel::set_edge()
{
	for (int i = 0; i < HEIGHT; i++)	
	{
		for (int j = 0; j < WEIGHT; j++)
		{
			if (j == 0 || j == WEIGHT-1 || i == 0 || i == HEIGHT-1 || j==19)
				game_panel[i][j] = 1;
			else
				game_panel[i][j] = 0;
			panel_cpy[i][j] = -1;
		}
	}
}
void gamepanel::copy_panel()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WEIGHT; j++)
		{
			panel_cpy[i][j] = game_panel[i][j];
		}
	}
}
void gamepanel::set_alltile()
{
	find_break();
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			set_tile(i, j);
	}
}
void gamepanel::find_break()
{
	int k = canbreak();
	if (k == 0)
		return;
	if (k == 1 || k == 2 || k == 3)
	{
		make_tile(k - 1, 0);
		make_tile(k - 1, 1);
		make_tile(k - 1, 2);
		find_break();
	}
	if (k == 4 || k == 5 || k == 6)
	{
		make_tile(0, k - 4);
		make_tile(1, k - 4);
		make_tile(2, k - 4);
		find_break();
	}

}
void gamepanel::set_tile(int x,int y)
{
	int type = tiles[x][y].get_type();
	for (int i = x * 6 + 1; i <= (x + 1) * 6; i++)
	{
		for (int j = y * 6 + 1; j <= (y + 1) * 6; j++)
		{
			game_panel[i][j] = 10 + type;
		}
	}
}
void gamepanel::set_Color(unsigned short text, unsigned short back)
{	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back<<4));
}
int gamepanel::canbreak()
{
	for (int i=0; i < 3; i++)
	{
		if (tiles[i][0].get_type() == tiles[i][1].get_type() && tiles[i][1].get_type() == tiles[i][2].get_type())
		{
			printf("+++++++++++++++++++\n");
			return i + 1;
		}
	}
	for (int i=0; i < 3; i++)
	{
		if (tiles[0][i].get_type() == tiles[1][i].get_type() && tiles[1][i].get_type() == tiles[2][i].get_type())
		{
			printf("-------------------\n");
			return i + 4;
		}
	}
	return 0;
}
void gamepanel::make_tile(int x, int y)
{
	tiles[x][y].set_num(rand() % 4);
}
void gamepanel::print_game()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WEIGHT; j++)
		{
			if (panel_cpy[i][j] == game_panel[i][j]) continue; // 이전 판과 같으면 다시 그릴 필요가 없다
			if (game_panel[i][j] == 1)
			{
				set_Color(15, 0);
				printf("■");
			}
			else if(game_panel[i][j] == 0)
				printf("  ");
			else
			{
				set_Color(15, game_panel[i][j] - 9);
				printf("★");
			}
		}
		printf("\n");
	}
	copy_panel();
}
