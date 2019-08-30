#pragma once



class tile
{
private:
	int num;

public:
	tile();
	int get_type() { return num; }
	void set_num(int x) { num = x; }

};