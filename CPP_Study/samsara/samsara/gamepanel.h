#pragma once
#include"tile.h"
#include<stdio.h>
#include<Windows.h>
class gamepanel
{
private:
	static const int HEIGHT = 20;
	static const int WEIGHT = 40;
	tile tiles[3][3];
	int game_panel[HEIGHT][WEIGHT];
	int panel_cpy[HEIGHT][WEIGHT];

public:
	gamepanel();
	void set_edge();
	void copy_panel();
	void set_alltile();
	void set_tile(int x,int y);
	void set_Color(unsigned short text, unsigned short back);
	int canbreak();
	void find_break();
	void make_tile(int x,int y);
	void print_game();


};