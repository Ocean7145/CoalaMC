

#include "pch.h"
#include <CoalaMOD.h>

#pragma comment (lib, "CoalaMOD.lib")


// RlocateBlock은 건물이 플레이어를 바라보도록 하는 함수이다. 좌표와 블록이름, dir과 gap을 전달받는다.

void RlocateBlock(BlockID Block, int x1, int y1, int z1, double dir, int gap)
{
	if (((dir >= 45) && (dir < 135) == 1) || ((dir >= 225) && (dir < 315) == 1) == 1)
	{
		if ((dir >= 45) && (dir < 135) == 1)
		{
			locateBlock(Block, x1 - gap, y1, z1 - gap);
		}
		else
		{
			locateBlock(Block, x1 - gap, y1, z1 + gap);
		}
	}
	else
	{

		if ((dir >= 0) && (dir < 45) == 1)
		{
			locateBlock(Block, x1 - (2 * gap), y1, z1);
		}
		else if ((dir >= 315) && (dir < 360) == 1)
		{
			locateBlock(Block, x1 - (2 * gap), y1, z1);
		}
		else
		{
			locateBlock(Block, x1, y1, z1);
		}


	}


}

int main()
{

	int px, py, pz; // 위치정보 없는 플레이어의 위치

	int dx, dy, dz; // 위치정보 있는 플레이어의 위치

	int num1, num2; // 루프용 변수.

	double dir = getPlayerDirection();

	getPlayerLocation(&px, &py, &pz);

	BlockID lp = createBlock(BLOCK_LAPIS_LAZULI);
	WoodID bi = createWood(WOOD_BIRCH);
	BlockID qu = createBlock(BLOCK_NETHER_QUARTZ);
	WoolID lb = createWool(COLOR_LIGHT_BLUE);
	WoolID cy = createWool(COLOR_CYAN);
	WoolID lg = createWool(COLOR_LIGHT_GRAY);
	WoolID pn = createWool(COLOR_PINK);
	ConcreteID br = createConcrete(COLOR_BROWN, false);
	ConcreteID rd = createConcrete(COLOR_RED, true);
	ConcreteID og = createConcrete(COLOR_ORANGE, true);
	TerracottaID wt = createTerracotta(TERRACOTTA, COLOR_WHITE);
	TerracottaID pr = createTerracotta(TERRACOTTA, COLOR_PURPLE);
	TerracottaID pt = createTerracotta(TERRACOTTA, COLOR_PINK);
	TerracottaID mg = createTerracotta(TERRACOTTA, COLOR_MAGENTA);




	/* 아래의 코드는 플레이어의 각도에 따라 dx와 dz를 결정하는 코드이다.
	건축물이 평면 픽셀아트이므로 플레이어의 각도를 곧이곧대로 따라가다간 이미지가 깨져버린다.
	비단 이미지 뿐만이 아닌 건축물도 플레이어의 각도를 따라가게 하면 모양새가 이상해지므로
	'플레이어의 앞쪽 시야에는 보이되, 플레이어의 시야를 그대로 따라가지는 않게' 한다. */


	if ((dir >= 0) && (dir < 45) == 1)
	{
		dz = pz + 200;
		dx = px;
	}
	else if ((dir >= 45) && (dir < 135) == 1)

	{
		dz = pz;
		dx = px - 200;
	}

	else if ((dir >= 135) && (dir < 225) == 1)
	{
		dz = pz - 200;
		dx = px;
	}
	else if ((dir >= 225) && (dir < 315) == 1)
	{
		dz = pz;
		dx = px + 200;
	}
	else if ((dir >= 315) && (dir <= 360) == 1)
	{
		dz = pz + 200;
		dx = px;
	}





	dy = py + 30; // 그냥 쓰기 쉬우라고 통일했다. 별 의미는 없다. 

	// lb: 푸른양모 cy: 청록양모 lp: 라피스 lg: 밝은회색양모 bi: 자작나무원목 qu: 석영


	// y축 최소는 dy - 13, 최대는 dy + 31.
	// x축 최소는 dx, 최대는 dx+81.

	num1 = 0; //x축
	num2 = -14; //y축

	while (num2 <= 31)
	{
		while (num1 <= 82)
		{
			RlocateBlock(qu, dx + num1, dy + num2, dz, dir, num1);
			num1++;
		}
		num1 = 0;
		num2++;
	}
	// 뒷배경용 석영블록 배치 코드



	RlocateBlock(lb, dx + 1, dy, dz, dir, 1);
	RlocateBlock(lp, dx + 2, dy, dz, dir, 2);
	RlocateBlock(lp, dx + 3, dy, dz, dir, 3);
	RlocateBlock(lp, dx + 4, dy, dz, dir, 4);
	RlocateBlock(lp, dx + 5, dy, dz, dir, 5);
	RlocateBlock(lp, dx + 6, dy, dz, dir, 6);
	RlocateBlock(lp, dx + 7, dy, dz, dir, 7);
	RlocateBlock(cy, dx + 8, dy, dz, dir, 8);
	RlocateBlock(qu, dx + 9, dy, dz, dir, 9);
	RlocateBlock(qu, dx + 10, dy, dz, dir, 10);
	RlocateBlock(qu, dx + 11, dy, dz, dir, 11);
	RlocateBlock(qu, dx + 12, dy, dz, dir, 12);
	RlocateBlock(qu, dx + 13, dy, dz, dir, 13);
	RlocateBlock(lg, dx + 14, dy, dz, dir, 14);
	RlocateBlock(cy, dx + 15, dy, dz, dir, 15);
	RlocateBlock(lp, dx + 16, dy, dz, dir, 16);
	RlocateBlock(lp, dx + 17, dy, dz, dir, 17);
	RlocateBlock(lp, dx + 18, dy, dz, dir, 18);
	RlocateBlock(lb, dx + 19, dy, dz, dir, 19);




	RlocateBlock(lb, dx + 1, dy + 1, dz, dir, 1);
	RlocateBlock(lp, dx + 2, dy + 1, dz, dir, 2);
	RlocateBlock(lp, dx + 3, dy + 1, dz, dir, 3);
	RlocateBlock(lp, dx + 4, dy + 1, dz, dir, 4);
	RlocateBlock(lp, dx + 5, dy + 1, dz, dir, 5);
	RlocateBlock(lp, dx + 6, dy + 1, dz, dir, 6);
	RlocateBlock(lp, dx + 7, dy + 1, dz, dir, 7);
	RlocateBlock(lb, dx + 8, dy + 1, dz, dir, 8);
	RlocateBlock(lb, dx + 17, dy + 1, dz, dir, 17);
	RlocateBlock(lp, dx + 18, dy + 1, dz, dir, 18);
	RlocateBlock(lp, dx + 19, dy + 1, dz, dir, 19);
	RlocateBlock(lb, dx + 20, dy + 1, dz, dir, 20);



	RlocateBlock(lb, dx + 1, dy + 2, dz, dir, 1);
	RlocateBlock(lp, dx + 2, dy + 2, dz, dir, 2);
	RlocateBlock(lp, dx + 3, dy + 2, dz, dir, 3);
	RlocateBlock(lp, dx + 4, dy + 2, dz, dir, 4);
	RlocateBlock(lp, dx + 5, dy + 2, dz, dir, 5);
	RlocateBlock(lp, dx + 6, dy + 2, dz, dir, 6);
	RlocateBlock(lp, dx + 7, dy + 2, dz, dir, 7);
	RlocateBlock(lb, dx + 8, dy + 2, dz, dir, 8);
	RlocateBlock(lb, dx + 19, dy + 2, dz, dir, 19);
	RlocateBlock(lp, dx + 20, dy + 2, dz, dir, 20);
	RlocateBlock(lb, dx + 21, dy + 2, dz, dir, 21);


	RlocateBlock(lb, dx + 1, dy + 3, dz, dir, 1);
	RlocateBlock(lp, dx + 2, dy + 3, dz, dir, 2);
	RlocateBlock(lp, dx + 3, dy + 3, dz, dir, 3);
	RlocateBlock(lp, dx + 4, dy + 3, dz, dir, 4);
	RlocateBlock(lp, dx + 5, dy + 3, dz, dir, 5);
	RlocateBlock(lp, dx + 6, dy + 3, dz, dir, 6);
	RlocateBlock(lp, dx + 7, dy + 3, dz, dir, 7);
	RlocateBlock(lb, dx + 8, dy + 3, dz, dir, 8);
	RlocateBlock(bi, dx + 20, dy + 3, dz, dir, 20);
	RlocateBlock(cy, dx + 21, dy + 3, dz, dir, 21);
	RlocateBlock(lb, dx + 22, dy + 3, dz, dir, 22);


	RlocateBlock(lb, dx + 1, dy + 4, dz, dir, 1);
	RlocateBlock(lp, dx + 2, dy + 4, dz, dir, 2);
	RlocateBlock(lp, dx + 3, dy + 4, dz, dir, 3);
	RlocateBlock(lp, dx + 4, dy + 4, dz, dir, 4);
	RlocateBlock(lp, dx + 5, dy + 4, dz, dir, 5);
	RlocateBlock(lp, dx + 6, dy + 4, dz, dir, 6);
	RlocateBlock(lp, dx + 7, dy + 4, dz, dir, 7);
	RlocateBlock(lp, dx + 8, dy + 4, dz, dir, 8);



	RlocateBlock(bi, dx + 1, dy + 5, dz, dir, 1);
	RlocateBlock(lp, dx + 2, dy + 5, dz, dir, 2);
	RlocateBlock(lp, dx + 3, dy + 5, dz, dir, 3);
	RlocateBlock(lp, dx + 4, dy + 5, dz, dir, 4);
	RlocateBlock(lp, dx + 5, dy + 5, dz, dir, 5);
	RlocateBlock(lp, dx + 6, dy + 5, dz, dir, 6);
	RlocateBlock(lp, dx + 7, dy + 5, dz, dir, 7);
	RlocateBlock(lp, dx + 8, dy + 5, dz, dir, 8);
	RlocateBlock(cy, dx + 9, dy + 5, dz, dir, 9);




	RlocateBlock(cy, dx + 2, dy + 6, dz, dir, 2);
	RlocateBlock(lp, dx + 3, dy + 6, dz, dir, 3);
	RlocateBlock(lp, dx + 4, dy + 6, dz, dir, 4);
	RlocateBlock(lp, dx + 5, dy + 6, dz, dir, 5);
	RlocateBlock(lp, dx + 6, dy + 6, dz, dir, 6);
	RlocateBlock(lp, dx + 7, dy + 6, dz, dir, 7);
	RlocateBlock(lp, dx + 8, dy + 6, dz, dir, 8);
	RlocateBlock(lp, dx + 9, dy + 6, dz, dir, 9);
	RlocateBlock(cy, dx + 10, dy + 6, dz, dir, 10);


	RlocateBlock(bi, dx + 2, dy + 7, dz, dir, 2);
	RlocateBlock(lp, dx + 3, dy + 7, dz, dir, 3);
	RlocateBlock(lp, dx + 4, dy + 7, dz, dir, 4);
	RlocateBlock(lp, dx + 5, dy + 7, dz, dir, 5);
	RlocateBlock(lp, dx + 6, dy + 7, dz, dir, 6);
	RlocateBlock(lp, dx + 7, dy + 7, dz, dir, 7);
	RlocateBlock(lp, dx + 8, dy + 7, dz, dir, 8);
	RlocateBlock(lp, dx + 9, dy + 7, dz, dir, 9);
	RlocateBlock(lp, dx + 10, dy + 7, dz, dir, 10);
	RlocateBlock(lb, dx + 11, dy + 7, dz, dir, 11);




	RlocateBlock(cy, dx + 3, dy + 8, dz, dir, 3);
	RlocateBlock(lp, dx + 4, dy + 8, dz, dir, 4);
	RlocateBlock(lp, dx + 5, dy + 8, dz, dir, 5);
	RlocateBlock(lp, dx + 6, dy + 8, dz, dir, 6);
	RlocateBlock(lp, dx + 7, dy + 8, dz, dir, 7);
	RlocateBlock(lp, dx + 8, dy + 8, dz, dir, 8);
	RlocateBlock(lp, dx + 9, dy + 8, dz, dir, 9);
	RlocateBlock(lp, dx + 10, dy + 8, dz, dir, 10);
	RlocateBlock(lp, dx + 11, dy + 8, dz, dir, 11);
	RlocateBlock(cy, dx + 12, dy + 8, dz, dir, 12);
	RlocateBlock(bi, dx + 13, dy + 8, dz, dir, 13);

	RlocateBlock(bi, dx + 3, dy + 9, dz, dir, 3);
	RlocateBlock(lp, dx + 4, dy + 9, dz, dir, 4);
	RlocateBlock(lp, dx + 5, dy + 9, dz, dir, 5);
	RlocateBlock(lp, dx + 6, dy + 9, dz, dir, 6);
	RlocateBlock(lp, dx + 7, dy + 9, dz, dir, 7);
	RlocateBlock(lp, dx + 8, dy + 9, dz, dir, 8);
	RlocateBlock(lp, dx + 9, dy + 9, dz, dir, 9);
	RlocateBlock(lp, dx + 10, dy + 9, dz, dir, 10);
	RlocateBlock(lp, dx + 11, dy + 9, dz, dir, 11);
	RlocateBlock(lp, dx + 12, dy + 9, dz, dir, 12);
	RlocateBlock(lp, dx + 13, dy + 9, dz, dir, 13);
	RlocateBlock(cy, dx + 14, dy + 9, dz, dir, 14);
	RlocateBlock(cy, dx + 15, dy + 9, dz, dir, 15);
	RlocateBlock(cy, dx + 16, dy + 9, dz, dir, 16);
	RlocateBlock(lb, dx + 17, dy + 9, dz, dir, 17);



	RlocateBlock(lb, dx + 4, dy + 10, dz, dir, 4);
	RlocateBlock(lp, dx + 5, dy + 10, dz, dir, 5);
	RlocateBlock(lp, dx + 6, dy + 10, dz, dir, 6);
	RlocateBlock(lp, dx + 7, dy + 10, dz, dir, 7);
	RlocateBlock(lp, dx + 8, dy + 10, dz, dir, 8);
	RlocateBlock(lp, dx + 9, dy + 10, dz, dir, 9);
	RlocateBlock(lp, dx + 10, dy + 10, dz, dir, 10);
	RlocateBlock(lp, dx + 11, dy + 10, dz, dir, 11);
	RlocateBlock(lp, dx + 12, dy + 10, dz, dir, 12);
	RlocateBlock(lp, dx + 13, dy + 10, dz, dir, 13);
	RlocateBlock(lp, dx + 14, dy + 10, dz, dir, 14);
	RlocateBlock(lp, dx + 15, dy + 10, dz, dir, 15);
	RlocateBlock(lp, dx + 16, dy + 10, dz, dir, 16);
	RlocateBlock(lp, dx + 17, dy + 10, dz, dir, 17);
	RlocateBlock(lp, dx + 18, dy + 10, dz, dir, 18);
	RlocateBlock(lb, dx + 19, dy + 10, dz, dir, 19);



	RlocateBlock(cy, dx + 5, dy + 11, dz, dir, 5);
	RlocateBlock(lp, dx + 6, dy + 11, dz, dir, 6);
	RlocateBlock(lp, dx + 7, dy + 11, dz, dir, 7);
	RlocateBlock(lp, dx + 8, dy + 11, dz, dir, 8);
	RlocateBlock(lp, dx + 9, dy + 11, dz, dir, 9);
	RlocateBlock(lp, dx + 10, dy + 11, dz, dir, 10);
	RlocateBlock(lp, dx + 11, dy + 11, dz, dir, 11);
	RlocateBlock(lp, dx + 12, dy + 11, dz, dir, 12);
	RlocateBlock(lp, dx + 13, dy + 11, dz, dir, 13);
	RlocateBlock(lp, dx + 14, dy + 11, dz, dir, 14);
	RlocateBlock(lp, dx + 15, dy + 11, dz, dir, 15);
	RlocateBlock(lp, dx + 16, dy + 11, dz, dir, 16);
	RlocateBlock(lp, dx + 17, dy + 11, dz, dir, 17);
	RlocateBlock(lp, dx + 18, dy + 11, dz, dir, 18);
	RlocateBlock(lp, dx + 19, dy + 11, dz, dir, 19);
	RlocateBlock(cy, dx + 20, dy + 11, dz, dir, 20);


	RlocateBlock(lb, dx + 6, dy + 12, dz, dir, 6);
	RlocateBlock(lp, dx + 7, dy + 12, dz, dir, 7);
	RlocateBlock(lp, dx + 8, dy + 12, dz, dir, 8);
	RlocateBlock(lp, dx + 9, dy + 12, dz, dir, 9);
	RlocateBlock(lp, dx + 10, dy + 12, dz, dir, 10);
	RlocateBlock(lp, dx + 11, dy + 12, dz, dir, 11);
	RlocateBlock(lp, dx + 12, dy + 12, dz, dir, 12);
	RlocateBlock(lp, dx + 13, dy + 12, dz, dir, 13);
	RlocateBlock(lp, dx + 14, dy + 12, dz, dir, 14);
	RlocateBlock(lp, dx + 15, dy + 12, dz, dir, 15);
	RlocateBlock(lp, dx + 16, dy + 12, dz, dir, 16);
	RlocateBlock(lp, dx + 17, dy + 12, dz, dir, 17);
	RlocateBlock(lp, dx + 18, dy + 12, dz, dir, 18);
	RlocateBlock(lp, dx + 19, dy + 12, dz, dir, 19);
	RlocateBlock(lp, dx + 20, dy + 12, dz, dir, 20);
	RlocateBlock(lb, dx + 21, dy + 12, dz, dir, 21);



	RlocateBlock(lb, dx + 7, dy + 13, dz, dir, 7);
	RlocateBlock(lp, dx + 8, dy + 13, dz, dir, 8);
	RlocateBlock(lp, dx + 9, dy + 13, dz, dir, 9);
	RlocateBlock(lp, dx + 10, dy + 13, dz, dir, 10);
	RlocateBlock(lp, dx + 11, dy + 13, dz, dir, 11);
	RlocateBlock(lp, dx + 12, dy + 13, dz, dir, 12);
	RlocateBlock(lp, dx + 13, dy + 13, dz, dir, 13);
	RlocateBlock(lp, dx + 14, dy + 13, dz, dir, 14);
	RlocateBlock(lp, dx + 15, dy + 13, dz, dir, 15);
	RlocateBlock(lp, dx + 16, dy + 13, dz, dir, 16);
	RlocateBlock(lp, dx + 17, dy + 13, dz, dir, 17);
	RlocateBlock(lp, dx + 18, dy + 13, dz, dir, 18);
	RlocateBlock(lp, dx + 19, dy + 13, dz, dir, 19);
	RlocateBlock(lp, dx + 20, dy + 13, dz, dir, 20);
	RlocateBlock(lp, dx + 21, dy + 13, dz, dir, 21);




	RlocateBlock(cy, dx + 8, dy + 14, dz, dir, 8);
	RlocateBlock(lp, dx + 9, dy + 14, dz, dir, 9);
	RlocateBlock(lp, dx + 10, dy + 14, dz, dir, 10);
	RlocateBlock(lp, dx + 11, dy + 14, dz, dir, 11);
	RlocateBlock(lp, dx + 12, dy + 14, dz, dir, 12);
	RlocateBlock(lp, dx + 13, dy + 14, dz, dir, 13);
	RlocateBlock(lp, dx + 14, dy + 14, dz, dir, 14);
	RlocateBlock(lp, dx + 15, dy + 14, dz, dir, 15);
	RlocateBlock(lp, dx + 16, dy + 14, dz, dir, 16);
	RlocateBlock(lp, dx + 17, dy + 14, dz, dir, 17);
	RlocateBlock(lp, dx + 18, dy + 14, dz, dir, 18);
	RlocateBlock(lp, dx + 19, dy + 14, dz, dir, 19);
	RlocateBlock(lp, dx + 20, dy + 14, dz, dir, 20);
	RlocateBlock(cy, dx + 21, dy + 14, dz, dir, 21);



	RlocateBlock(lb, dx + 9, dy + 15, dz, dir, 9);
	RlocateBlock(lp, dx + 10, dy + 15, dz, dir, 10);
	RlocateBlock(lp, dx + 11, dy + 15, dz, dir, 11);
	RlocateBlock(lp, dx + 12, dy + 15, dz, dir, 12);
	RlocateBlock(lp, dx + 13, dy + 15, dz, dir, 13);
	RlocateBlock(lp, dx + 14, dy + 15, dz, dir, 14);
	RlocateBlock(lp, dx + 15, dy + 15, dz, dir, 15);
	RlocateBlock(lp, dx + 16, dy + 15, dz, dir, 16);
	RlocateBlock(lp, dx + 17, dy + 15, dz, dir, 17);
	RlocateBlock(lp, dx + 18, dy + 15, dz, dir, 18);
	RlocateBlock(lp, dx + 19, dy + 15, dz, dir, 19);
	RlocateBlock(lp, dx + 20, dy + 15, dz, dir, 20);
	RlocateBlock(cy, dx + 21, dy + 15, dz, dir, 21);



	RlocateBlock(lb, dx + 10, dy + 16, dz, dir, 10);
	RlocateBlock(lb, dx + 11, dy + 16, dz, dir, 11);
	RlocateBlock(lp, dx + 12, dy + 16, dz, dir, 12);
	RlocateBlock(lp, dx + 13, dy + 16, dz, dir, 13);
	RlocateBlock(lp, dx + 14, dy + 16, dz, dir, 14);
	RlocateBlock(lp, dx + 15, dy + 16, dz, dir, 15);
	RlocateBlock(lp, dx + 16, dy + 16, dz, dir, 16);
	RlocateBlock(lp, dx + 17, dy + 16, dz, dir, 17);
	RlocateBlock(lp, dx + 18, dy + 16, dz, dir, 18);
	RlocateBlock(lp, dx + 19, dy + 16, dz, dir, 19);
	RlocateBlock(lp, dx + 20, dy + 16, dz, dir, 20);



	RlocateBlock(lb, dx + 12, dy + 17, dz, dir, 12);
	RlocateBlock(cy, dx + 13, dy + 17, dz, dir, 13);
	RlocateBlock(lp, dx + 14, dy + 17, dz, dir, 14);
	RlocateBlock(lp, dx + 15, dy + 17, dz, dir, 15);
	RlocateBlock(lp, dx + 16, dy + 17, dz, dir, 16);
	RlocateBlock(lp, dx + 17, dy + 17, dz, dir, 17);
	RlocateBlock(lp, dx + 18, dy + 17, dz, dir, 18);
	RlocateBlock(cy, dx + 19, dy + 17, dz, dir, 19);
	RlocateBlock(lg, dx + 20, dy + 17, dz, dir, 20);



	RlocateBlock(bi, dx + 14, dy + 18, dz, dir, 14);
	RlocateBlock(lb, dx + 15, dy + 18, dz, dir, 15);
	RlocateBlock(lb, dx + 16, dy + 18, dz, dir, 16);
	RlocateBlock(lb, dx + 17, dy + 18, dz, dir, 17);
	RlocateBlock(lb, dx + 18, dy + 18, dz, dir, 18);

	// C 기준점 위로는 다 했음.

	RlocateBlock(lg, dx + 1, dy - 1, dz, dir, 1);
	RlocateBlock(lp, dx + 2, dy - 1, dz, dir, 2);
	RlocateBlock(lp, dx + 3, dy - 1, dz, dir, 3);
	RlocateBlock(lp, dx + 4, dy - 1, dz, dir, 4);
	RlocateBlock(lp, dx + 5, dy - 1, dz, dir, 5);
	RlocateBlock(lp, dx + 6, dy - 1, dz, dir, 6);
	RlocateBlock(lp, dx + 7, dy - 1, dz, dir, 7);
	RlocateBlock(lp, dx + 8, dy - 1, dz, dir, 8);
	RlocateBlock(cy, dx + 9, dy - 1, dz, dir, 9);
	RlocateBlock(lb, dx + 10, dy - 1, dz, dir, 10);
	RlocateBlock(cy, dx + 11, dy - 1, dz, dir, 11);
	RlocateBlock(lp, dx + 12, dy - 1, dz, dir, 12);
	RlocateBlock(lp, dx + 13, dy - 1, dz, dir, 13);
	RlocateBlock(lp, dx + 14, dy - 1, dz, dir, 14);
	RlocateBlock(lp, dx + 15, dy - 1, dz, dir, 15);
	RlocateBlock(lp, dx + 16, dy - 1, dz, dir, 16);
	RlocateBlock(lp, dx + 17, dy - 1, dz, dir, 17);
	RlocateBlock(cy, dx + 18, dy - 1, dz, dir, 18);




	RlocateBlock(cy, dx + 2, dy - 2, dz, dir, 2);
	RlocateBlock(lp, dx + 3, dy - 2, dz, dir, 3);
	RlocateBlock(lp, dx + 4, dy - 2, dz, dir, 4);
	RlocateBlock(lp, dx + 5, dy - 2, dz, dir, 5);
	RlocateBlock(lp, dx + 6, dy - 2, dz, dir, 6);
	RlocateBlock(lp, dx + 7, dy - 2, dz, dir, 7);
	RlocateBlock(lp, dx + 8, dy - 2, dz, dir, 8);
	RlocateBlock(lp, dx + 9, dy - 2, dz, dir, 9);
	RlocateBlock(lp, dx + 10, dy - 2, dz, dir, 10);
	RlocateBlock(lp, dx + 11, dy - 2, dz, dir, 11);
	RlocateBlock(lp, dx + 12, dy - 2, dz, dir, 12);
	RlocateBlock(lp, dx + 13, dy - 2, dz, dir, 13);
	RlocateBlock(lp, dx + 14, dy - 2, dz, dir, 14);
	RlocateBlock(lp, dx + 15, dy - 2, dz, dir, 15);
	RlocateBlock(lp, dx + 16, dy - 2, dz, dir, 16);
	RlocateBlock(lb, dx + 17, dy - 2, dz, dir, 17);



	RlocateBlock(cy, dx + 2, dy - 3, dz, dir, 2);
	RlocateBlock(lp, dx + 3, dy - 3, dz, dir, 3);
	RlocateBlock(lp, dx + 4, dy - 3, dz, dir, 4);
	RlocateBlock(lp, dx + 5, dy - 3, dz, dir, 5);
	RlocateBlock(lp, dx + 6, dy - 3, dz, dir, 6);
	RlocateBlock(lp, dx + 7, dy - 3, dz, dir, 7);
	RlocateBlock(lp, dx + 8, dy - 3, dz, dir, 8);
	RlocateBlock(lp, dx + 9, dy - 3, dz, dir, 9);
	RlocateBlock(lp, dx + 10, dy - 3, dz, dir, 10);
	RlocateBlock(lp, dx + 11, dy - 3, dz, dir, 11);
	RlocateBlock(lp, dx + 12, dy - 3, dz, dir, 12);
	RlocateBlock(lp, dx + 13, dy - 3, dz, dir, 13);
	RlocateBlock(lp, dx + 14, dy - 3, dz, dir, 14);
	RlocateBlock(lp, dx + 15, dy - 3, dz, dir, 15);
	RlocateBlock(lb, dx + 16, dy - 3, dz, dir, 16);


	RlocateBlock(lb, dx + 2, dy - 4, dz, dir, 2);
	RlocateBlock(lp, dx + 3, dy - 4, dz, dir, 3);
	RlocateBlock(lp, dx + 4, dy - 4, dz, dir, 4);
	RlocateBlock(lp, dx + 5, dy - 4, dz, dir, 5);
	RlocateBlock(lp, dx + 6, dy - 4, dz, dir, 6);
	RlocateBlock(lp, dx + 7, dy - 4, dz, dir, 7);
	RlocateBlock(lp, dx + 8, dy - 4, dz, dir, 8);
	RlocateBlock(lp, dx + 9, dy - 4, dz, dir, 9);
	RlocateBlock(lp, dx + 10, dy - 4, dz, dir, 10);
	RlocateBlock(lp, dx + 11, dy - 4, dz, dir, 11);
	RlocateBlock(lp, dx + 12, dy - 4, dz, dir, 12);
	RlocateBlock(lp, dx + 13, dy - 4, dz, dir, 13);
	RlocateBlock(cy, dx + 14, dy - 4, dz, dir, 14);


	RlocateBlock(lb, dx + 4, dy - 5, dz, dir, 4);
	RlocateBlock(lp, dx + 5, dy - 5, dz, dir, 5);
	RlocateBlock(lp, dx + 6, dy - 5, dz, dir, 6);
	RlocateBlock(lp, dx + 7, dy - 5, dz, dir, 7);
	RlocateBlock(lp, dx + 8, dy - 5, dz, dir, 8);
	RlocateBlock(lp, dx + 9, dy - 5, dz, dir, 9);
	RlocateBlock(lp, dx + 10, dy - 5, dz, dir, 10);
	RlocateBlock(cy, dx + 11, dy - 5, dz, dir, 11);
	RlocateBlock(lb, dx + 12, dy - 5, dz, dir, 12);




	RlocateBlock(lb, dx + 5, dy - 6, dz, dir, 5);
	RlocateBlock(lb, dx + 6, dy - 6, dz, dir, 6);
	RlocateBlock(lb, dx + 7, dy - 6, dz, dir, 7);
	RlocateBlock(lb, dx + 8, dy - 6, dz, dir, 8);
	RlocateBlock(lb, dx + 9, dy - 6, dz, dir, 9);
	RlocateBlock(bi, dx + 10, dy - 6, dz, dir, 10);


	// 글자 C는 끝.


	RlocateBlock(lp, dx + 25, dy, dz, dir, 25);
	RlocateBlock(lp, dx + 26, dy, dz, dir, 26);
	RlocateBlock(lp, dx + 27, dy, dz, dir, 27);
	RlocateBlock(lp, dx + 28, dy, dz, dir, 28);
	RlocateBlock(lp, dx + 29, dy, dz, dir, 29);
	RlocateBlock(lp, dx + 30, dy, dz, dir, 30);
	RlocateBlock(lp, dx + 31, dy, dz, dir, 31);
	RlocateBlock(lp, dx + 32, dy, dz, dir, 32);
	RlocateBlock(lp, dx + 33, dy, dz, dir, 33);
	RlocateBlock(lp, dx + 34, dy, dz, dir, 34);
	RlocateBlock(cy, dx + 35, dy, dz, dir, 35);
	RlocateBlock(lb, dx + 36, dy, dz, dir, 36);
	RlocateBlock(lp, dx + 37, dy, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy, dz, dir, 40);
	RlocateBlock(lb, dx + 41, dy, dz, dir, 41);



	RlocateBlock(lb, dx + 25, dy + 1, dz, dir, 25);
	RlocateBlock(lp, dx + 26, dy + 1, dz, dir, 26);
	RlocateBlock(lp, dx + 27, dy + 1, dz, dir, 27);
	RlocateBlock(lp, dx + 28, dy + 1, dz, dir, 28);
	RlocateBlock(lp, dx + 29, dy + 1, dz, dir, 29);
	RlocateBlock(lp, dx + 30, dy + 1, dz, dir, 30);
	RlocateBlock(lp, dx + 31, dy + 1, dz, dir, 31);
	RlocateBlock(lp, dx + 32, dy + 1, dz, dir, 32);
	RlocateBlock(lp, dx + 33, dy + 1, dz, dir, 33);
	RlocateBlock(lp, dx + 34, dy + 1, dz, dir, 34);
	RlocateBlock(lp, dx + 35, dy + 1, dz, dir, 35);
	RlocateBlock(lp, dx + 36, dy + 1, dz, dir, 36);
	RlocateBlock(lp, dx + 37, dy + 1, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy + 1, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy + 1, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy + 1, dz, dir, 40);
	RlocateBlock(lb, dx + 41, dy + 1, dz, dir, 41);


	RlocateBlock(bi, dx + 25, dy + 2, dz, dir, 25);
	RlocateBlock(lp, dx + 26, dy + 2, dz, dir, 26);
	RlocateBlock(lp, dx + 27, dy + 2, dz, dir, 27);
	RlocateBlock(lp, dx + 28, dy + 2, dz, dir, 28);
	RlocateBlock(lp, dx + 29, dy + 2, dz, dir, 29);
	RlocateBlock(lp, dx + 30, dy + 2, dz, dir, 30);
	RlocateBlock(lp, dx + 31, dy + 2, dz, dir, 31);
	RlocateBlock(lp, dx + 32, dy + 2, dz, dir, 32);
	RlocateBlock(lp, dx + 33, dy + 2, dz, dir, 33);
	RlocateBlock(lp, dx + 34, dy + 2, dz, dir, 34);
	RlocateBlock(lp, dx + 35, dy + 2, dz, dir, 35);
	RlocateBlock(lp, dx + 36, dy + 2, dz, dir, 36);
	RlocateBlock(lp, dx + 37, dy + 2, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy + 2, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy + 2, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy + 2, dz, dir, 40);
	RlocateBlock(cy, dx + 41, dy + 2, dz, dir, 41);



	RlocateBlock(cy, dx + 26, dy + 3, dz, dir, 26);
	RlocateBlock(lp, dx + 27, dy + 3, dz, dir, 27);
	RlocateBlock(lp, dx + 28, dy + 3, dz, dir, 28);
	RlocateBlock(lp, dx + 29, dy + 3, dz, dir, 29);
	RlocateBlock(lp, dx + 30, dy + 3, dz, dir, 30);
	RlocateBlock(lp, dx + 31, dy + 3, dz, dir, 31);
	RlocateBlock(lp, dx + 32, dy + 3, dz, dir, 32);
	RlocateBlock(lp, dx + 33, dy + 3, dz, dir, 33);
	RlocateBlock(lp, dx + 34, dy + 3, dz, dir, 34);
	RlocateBlock(lp, dx + 35, dy + 3, dz, dir, 35);
	RlocateBlock(lp, dx + 36, dy + 3, dz, dir, 36);
	RlocateBlock(lp, dx + 37, dy + 3, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy + 3, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy + 3, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy + 3, dz, dir, 40);
	RlocateBlock(lp, dx + 41, dy + 3, dz, dir, 41);
	RlocateBlock(lb, dx + 42, dy + 3, dz, dir, 42);



	RlocateBlock(bi, dx + 26, dy + 4, dz, dir, 26);
	RlocateBlock(lp, dx + 27, dy + 4, dz, dir, 27);
	RlocateBlock(lp, dx + 28, dy + 4, dz, dir, 28);
	RlocateBlock(lp, dx + 29, dy + 4, dz, dir, 29);
	RlocateBlock(lp, dx + 30, dy + 4, dz, dir, 30);
	RlocateBlock(lp, dx + 31, dy + 4, dz, dir, 31);
	RlocateBlock(lp, dx + 32, dy + 4, dz, dir, 32);
	RlocateBlock(lp, dx + 33, dy + 4, dz, dir, 33);
	RlocateBlock(lp, dx + 34, dy + 4, dz, dir, 34);
	RlocateBlock(lp, dx + 35, dy + 4, dz, dir, 35);
	RlocateBlock(lp, dx + 36, dy + 4, dz, dir, 36);
	RlocateBlock(lp, dx + 37, dy + 4, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy + 4, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy + 4, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy + 4, dz, dir, 40);
	RlocateBlock(lp, dx + 41, dy + 4, dz, dir, 41);
	RlocateBlock(lp, dx + 42, dy + 4, dz, dir, 42);
	RlocateBlock(cy, dx + 43, dy + 4, dz, dir, 43);
	RlocateBlock(bi, dx + 44, dy + 4, dz, dir, 44);




	RlocateBlock(lb, dx + 27, dy + 5, dz, dir, 27);
	RlocateBlock(lp, dx + 28, dy + 5, dz, dir, 28);
	RlocateBlock(lp, dx + 29, dy + 5, dz, dir, 29);
	RlocateBlock(lp, dx + 30, dy + 5, dz, dir, 30);
	RlocateBlock(lp, dx + 31, dy + 5, dz, dir, 31);
	RlocateBlock(lp, dx + 32, dy + 5, dz, dir, 32);
	RlocateBlock(qu, dx + 33, dy + 5, dz, dir, 33);
	RlocateBlock(lb, dx + 34, dy + 5, dz, dir, 34);
	RlocateBlock(lp, dx + 35, dy + 5, dz, dir, 35);
	RlocateBlock(lp, dx + 36, dy + 5, dz, dir, 36);
	RlocateBlock(lp, dx + 37, dy + 5, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy + 5, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy + 5, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy + 5, dz, dir, 40);
	RlocateBlock(lp, dx + 41, dy + 5, dz, dir, 41);
	RlocateBlock(lp, dx + 42, dy + 5, dz, dir, 42);
	RlocateBlock(lp, dx + 43, dy + 5, dz, dir, 43);
	RlocateBlock(cy, dx + 44, dy + 5, dz, dir, 44);


	RlocateBlock(lp, dx + 28, dy + 6, dz, dir, 28);
	RlocateBlock(lp, dx + 29, dy + 6, dz, dir, 29);
	RlocateBlock(lp, dx + 30, dy + 6, dz, dir, 30);
	RlocateBlock(lp, dx + 31, dy + 6, dz, dir, 31);
	RlocateBlock(lp, dx + 32, dy + 6, dz, dir, 32);
	RlocateBlock(lb, dx + 33, dy + 6, dz, dir, 33);
	RlocateBlock(qu, dx + 34, dy + 6, dz, dir, 34);
	RlocateBlock(bi, dx + 35, dy + 6, dz, dir, 35);
	RlocateBlock(lb, dx + 36, dy + 6, dz, dir, 36);
	RlocateBlock(lp, dx + 37, dy + 6, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy + 6, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy + 6, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy + 6, dz, dir, 40);
	RlocateBlock(lp, dx + 41, dy + 6, dz, dir, 41);
	RlocateBlock(lp, dx + 42, dy + 6, dz, dir, 42);
	RlocateBlock(lp, dx + 43, dy + 6, dz, dir, 43);
	RlocateBlock(lp, dx + 44, dy + 6, dz, dir, 44);
	RlocateBlock(lp, dx + 45, dy + 6, dz, dir, 45);



	RlocateBlock(cy, dx + 28, dy + 7, dz, dir, 28);
	RlocateBlock(lp, dx + 29, dy + 7, dz, dir, 29);
	RlocateBlock(lp, dx + 30, dy + 7, dz, dir, 30);
	RlocateBlock(lp, dx + 31, dy + 7, dz, dir, 31);
	RlocateBlock(lp, dx + 32, dy + 7, dz, dir, 32);
	RlocateBlock(lp, dx + 33, dy + 7, dz, dir, 33);
	RlocateBlock(qu, dx + 34, dy + 7, dz, dir, 34);
	RlocateBlock(qu, dx + 35, dy + 7, dz, dir, 35);
	RlocateBlock(qu, dx + 36, dy + 7, dz, dir, 36);
	RlocateBlock(lb, dx + 37, dy + 7, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy + 7, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy + 7, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy + 7, dz, dir, 40);
	RlocateBlock(lp, dx + 41, dy + 7, dz, dir, 41);
	RlocateBlock(lp, dx + 42, dy + 7, dz, dir, 42);
	RlocateBlock(lp, dx + 43, dy + 7, dz, dir, 43);
	RlocateBlock(lp, dx + 44, dy + 7, dz, dir, 44);
	RlocateBlock(lp, dx + 45, dy + 7, dz, dir, 45);
	RlocateBlock(cy, dx + 46, dy + 7, dz, dir, 46);
	RlocateBlock(lb, dx + 47, dy + 7, dz, dir, 47);




	RlocateBlock(lp, dx + 29, dy + 8, dz, dir, 29);
	RlocateBlock(lp, dx + 30, dy + 8, dz, dir, 30);
	RlocateBlock(lp, dx + 31, dy + 8, dz, dir, 31);
	RlocateBlock(lp, dx + 32, dy + 8, dz, dir, 32);
	RlocateBlock(lp, dx + 33, dy + 8, dz, dir, 33);
	RlocateBlock(lb, dx + 34, dy + 8, dz, dir, 34);
	RlocateBlock(qu, dx + 35, dy + 8, dz, dir, 35);
	RlocateBlock(qu, dx + 36, dy + 8, dz, dir, 36);
	RlocateBlock(qu, dx + 37, dy + 8, dz, dir, 37);
	RlocateBlock(cy, dx + 38, dy + 8, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy + 8, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy + 8, dz, dir, 40);
	RlocateBlock(lp, dx + 41, dy + 8, dz, dir, 41);
	RlocateBlock(lp, dx + 42, dy + 8, dz, dir, 42);
	RlocateBlock(lp, dx + 43, dy + 8, dz, dir, 43);
	RlocateBlock(lp, dx + 44, dy + 8, dz, dir, 44);
	RlocateBlock(lp, dx + 45, dy + 8, dz, dir, 45);
	RlocateBlock(lp, dx + 46, dy + 8, dz, dir, 46);
	RlocateBlock(lp, dx + 47, dy + 8, dz, dir, 47);
	RlocateBlock(bi, dx + 48, dy + 8, dz, dir, 48);


	RlocateBlock(lb, dx + 29, dy + 9, dz, dir, 29);
	RlocateBlock(lp, dx + 30, dy + 9, dz, dir, 30);
	RlocateBlock(lp, dx + 31, dy + 9, dz, dir, 31);
	RlocateBlock(lp, dx + 32, dy + 9, dz, dir, 32);
	RlocateBlock(lp, dx + 33, dy + 9, dz, dir, 33);
	RlocateBlock(lp, dx + 34, dy + 9, dz, dir, 34);
	RlocateBlock(lb, dx + 35, dy + 9, dz, dir, 35);
	RlocateBlock(qu, dx + 36, dy + 9, dz, dir, 36);
	RlocateBlock(qu, dx + 37, dy + 9, dz, dir, 37);
	RlocateBlock(cy, dx + 38, dy + 9, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy + 9, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy + 9, dz, dir, 40);
	RlocateBlock(lp, dx + 41, dy + 9, dz, dir, 41);
	RlocateBlock(lp, dx + 42, dy + 9, dz, dir, 42);
	RlocateBlock(lp, dx + 43, dy + 9, dz, dir, 43);
	RlocateBlock(lp, dx + 44, dy + 9, dz, dir, 44);
	RlocateBlock(lp, dx + 45, dy + 9, dz, dir, 45);
	RlocateBlock(lp, dx + 46, dy + 9, dz, dir, 46);
	RlocateBlock(lp, dx + 47, dy + 9, dz, dir, 47);
	RlocateBlock(lp, dx + 48, dy + 9, dz, dir, 48);


	RlocateBlock(cy, dx + 30, dy + 10, dz, dir, 30);
	RlocateBlock(lp, dx + 31, dy + 10, dz, dir, 31);
	RlocateBlock(lp, dx + 32, dy + 10, dz, dir, 32);
	RlocateBlock(lp, dx + 33, dy + 10, dz, dir, 33);
	RlocateBlock(lp, dx + 34, dy + 10, dz, dir, 34);
	RlocateBlock(lp, dx + 35, dy + 10, dz, dir, 35);
	RlocateBlock(bi, dx + 36, dy + 10, dz, dir, 36);
	RlocateBlock(qu, dx + 37, dy + 10, dz, dir, 37);
	RlocateBlock(lb, dx + 38, dy + 10, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy + 10, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy + 10, dz, dir, 40);
	RlocateBlock(lp, dx + 41, dy + 10, dz, dir, 41);
	RlocateBlock(cy, dx + 42, dy + 10, dz, dir, 42);
	RlocateBlock(lb, dx + 43, dy + 10, dz, dir, 43);
	RlocateBlock(cy, dx + 44, dy + 10, dz, dir, 44);
	RlocateBlock(lp, dx + 45, dy + 10, dz, dir, 45);
	RlocateBlock(lp, dx + 46, dy + 10, dz, dir, 46);
	RlocateBlock(lp, dx + 47, dy + 10, dz, dir, 47);
	RlocateBlock(lp, dx + 48, dy + 10, dz, dir, 48);
	RlocateBlock(lp, dx + 49, dy + 10, dz, dir, 49);
	RlocateBlock(lp, dx + 50, dy + 10, dz, dir, 50);
	RlocateBlock(cy, dx + 51, dy + 10, dz, dir, 51);





	RlocateBlock(lb, dx + 31, dy + 11, dz, dir, 31);
	RlocateBlock(lp, dx + 32, dy + 11, dz, dir, 32);
	RlocateBlock(lp, dx + 33, dy + 11, dz, dir, 33);
	RlocateBlock(lp, dx + 34, dy + 11, dz, dir, 34);
	RlocateBlock(lp, dx + 35, dy + 11, dz, dir, 35);
	RlocateBlock(lp, dx + 36, dy + 11, dz, dir, 36);
	RlocateBlock(lb, dx + 37, dy + 11, dz, dir, 37);
	RlocateBlock(qu, dx + 38, dy + 11, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy + 11, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy + 11, dz, dir, 40);
	RlocateBlock(lp, dx + 41, dy + 11, dz, dir, 41);
	RlocateBlock(lp, dx + 42, dy + 11, dz, dir, 42);
	RlocateBlock(qu, dx + 43, dy + 11, dz, dir, 43);
	RlocateBlock(qu, dx + 44, dy + 11, dz, dir, 44);
	RlocateBlock(qu, dx + 45, dy + 11, dz, dir, 45);
	RlocateBlock(qu, dx + 46, dy + 11, dz, dir, 46);
	RlocateBlock(bi, dx + 47, dy + 11, dz, dir, 47);
	RlocateBlock(lb, dx + 48, dy + 11, dz, dir, 48);
	RlocateBlock(lp, dx + 49, dy + 11, dz, dir, 49);
	RlocateBlock(lp, dx + 50, dy + 11, dz, dir, 50);
	RlocateBlock(lp, dx + 51, dy + 11, dz, dir, 51);
	RlocateBlock(lb, dx + 52, dy + 11, dz, dir, 52); //  여기가 u 기준점. 제일 튀어나온 곳




	RlocateBlock(cy, dx + 32, dy + 12, dz, dir, 32);
	RlocateBlock(lp, dx + 33, dy + 12, dz, dir, 33);
	RlocateBlock(lp, dx + 34, dy + 12, dz, dir, 34);
	RlocateBlock(lp, dx + 35, dy + 12, dz, dir, 35);
	RlocateBlock(lp, dx + 36, dy + 12, dz, dir, 36);
	RlocateBlock(lp, dx + 37, dy + 12, dz, dir, 37);
	RlocateBlock(lb, dx + 38, dy + 12, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy + 12, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy + 12, dz, dir, 40);
	RlocateBlock(lp, dx + 41, dy + 12, dz, dir, 41);
	RlocateBlock(lp, dx + 42, dy + 12, dz, dir, 42);
	RlocateBlock(qu, dx + 43, dy + 12, dz, dir, 43);
	RlocateBlock(qu, dx + 44, dy + 12, dz, dir, 44);
	RlocateBlock(qu, dx + 45, dy + 12, dz, dir, 45);
	RlocateBlock(qu, dx + 46, dy + 12, dz, dir, 46);
	RlocateBlock(qu, dx + 47, dy + 12, dz, dir, 47);
	RlocateBlock(qu, dx + 48, dy + 12, dz, dir, 48);
	RlocateBlock(qu, dx + 49, dy + 12, dz, dir, 49);
	RlocateBlock(lg, dx + 50, dy + 12, dz, dir, 50);
	RlocateBlock(lb, dx + 51, dy + 12, dz, dir, 51);




	RlocateBlock(bi, dx + 32, dy + 13, dz, dir, 32);
	RlocateBlock(lp, dx + 33, dy + 13, dz, dir, 33);
	RlocateBlock(lp, dx + 34, dy + 13, dz, dir, 34);
	RlocateBlock(lp, dx + 35, dy + 13, dz, dir, 35);
	RlocateBlock(lp, dx + 36, dy + 13, dz, dir, 36);
	RlocateBlock(lp, dx + 37, dy + 13, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy + 13, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy + 13, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy + 13, dz, dir, 40);
	RlocateBlock(lp, dx + 41, dy + 13, dz, dir, 41);
	RlocateBlock(lp, dx + 42, dy + 13, dz, dir, 42);
	RlocateBlock(bi, dx + 43, dy + 13, dz, dir, 43);



	RlocateBlock(bi, dx + 33, dy + 14, dz, dir, 33);
	RlocateBlock(lp, dx + 34, dy + 14, dz, dir, 34);
	RlocateBlock(lp, dx + 35, dy + 14, dz, dir, 35);
	RlocateBlock(lp, dx + 36, dy + 14, dz, dir, 36);
	RlocateBlock(lp, dx + 37, dy + 14, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy + 14, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy + 14, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy + 14, dz, dir, 40);
	RlocateBlock(lp, dx + 41, dy + 14, dz, dir, 41);
	RlocateBlock(lp, dx + 42, dy + 14, dz, dir, 42);
	RlocateBlock(qu, dx + 43, dy + 14, dz, dir, 43);





	RlocateBlock(lb, dx + 34, dy + 15, dz, dir, 34);
	RlocateBlock(lp, dx + 35, dy + 15, dz, dir, 35);
	RlocateBlock(lp, dx + 36, dy + 15, dz, dir, 36);
	RlocateBlock(lp, dx + 37, dy + 15, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy + 15, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy + 15, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy + 15, dz, dir, 40);
	RlocateBlock(lp, dx + 41, dy + 15, dz, dir, 41);
	RlocateBlock(lp, dx + 42, dy + 15, dz, dir, 42);
	RlocateBlock(bi, dx + 43, dy + 15, dz, dir, 43);




	RlocateBlock(lb, dx + 35, dy + 16, dz, dir, 35);
	RlocateBlock(lp, dx + 36, dy + 16, dz, dir, 36);
	RlocateBlock(lp, dx + 37, dy + 16, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy + 16, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy + 16, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy + 16, dz, dir, 40);
	RlocateBlock(lp, dx + 41, dy + 16, dz, dir, 41);
	RlocateBlock(lp, dx + 42, dy + 16, dz, dir, 42);
	RlocateBlock(bi, dx + 43, dy + 16, dz, dir, 43);


	RlocateBlock(lb, dx + 36, dy + 17, dz, dir, 36);
	RlocateBlock(lp, dx + 37, dy + 17, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy + 17, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy + 17, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy + 17, dz, dir, 40);
	RlocateBlock(lp, dx + 41, dy + 17, dz, dir, 41);
	RlocateBlock(lp, dx + 42, dy + 17, dz, dir, 42);


	RlocateBlock(lb, dx + 37, dy + 18, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy + 18, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy + 18, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy + 18, dz, dir, 40);
	RlocateBlock(lp, dx + 41, dy + 18, dz, dir, 41);
	RlocateBlock(lb, dx + 42, dy + 18, dz, dir, 42);




	RlocateBlock(bi, dx + 39, dy + 19, dz, dir, 39);
	RlocateBlock(lb, dx + 40, dy + 19, dz, dir, 40);
	RlocateBlock(lb, dx + 41, dy + 19, dz, dir, 41);


	// A 기준점 위로 끝.



	RlocateBlock(lb, dx + 23, dy - 1, dz, dir, 23);
	RlocateBlock(lp, dx + 24, dy - 1, dz, dir, 24);
	RlocateBlock(lp, dx + 25, dy - 1, dz, dir, 25);
	RlocateBlock(lp, dx + 26, dy - 1, dz, dir, 26);
	RlocateBlock(lp, dx + 27, dy - 1, dz, dir, 27);
	RlocateBlock(lp, dx + 28, dy - 1, dz, dir, 28);
	RlocateBlock(lp, dx + 29, dy - 1, dz, dir, 29);
	RlocateBlock(lp, dx + 30, dy - 1, dz, dir, 30);
	RlocateBlock(lp, dx + 31, dy - 1, dz, dir, 31);
	RlocateBlock(lp, dx + 32, dy - 1, dz, dir, 32);
	RlocateBlock(lb, dx + 33, dy - 1, dz, dir, 33);
	RlocateBlock(bi, dx + 34, dy - 1, dz, dir, 34);
	RlocateBlock(qu, dx + 35, dy - 1, dz, dir, 35);
	RlocateBlock(qu, dx + 36, dy - 1, dz, dir, 36);
	RlocateBlock(lp, dx + 37, dy - 1, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy - 1, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy - 1, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy - 1, dz, dir, 40);

	RlocateBlock(lb, dx + 21, dy - 2, dz, dir, 21);
	RlocateBlock(cy, dx + 22, dy - 2, dz, dir, 22);
	RlocateBlock(lp, dx + 23, dy - 2, dz, dir, 23);
	RlocateBlock(lp, dx + 24, dy - 2, dz, dir, 24);
	RlocateBlock(lp, dx + 25, dy - 2, dz, dir, 25);
	RlocateBlock(lp, dx + 26, dy - 2, dz, dir, 26);
	RlocateBlock(lp, dx + 27, dy - 2, dz, dir, 27);
	RlocateBlock(lp, dx + 28, dy - 2, dz, dir, 28);
	RlocateBlock(lp, dx + 29, dy - 2, dz, dir, 29);
	RlocateBlock(lp, dx + 30, dy - 2, dz, dir, 30);
	RlocateBlock(lb, dx + 31, dy - 2, dz, dir, 31);
	RlocateBlock(qu, dx + 32, dy - 2, dz, dir, 32);
	RlocateBlock(qu, dx + 33, dy - 2, dz, dir, 33);
	RlocateBlock(qu, dx + 34, dy - 2, dz, dir, 34);
	RlocateBlock(qu, dx + 35, dy - 2, dz, dir, 35);
	RlocateBlock(qu, dx + 36, dy - 2, dz, dir, 36);
	RlocateBlock(cy, dx + 37, dy - 2, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy - 2, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy - 2, dz, dir, 39);
	RlocateBlock(cy, dx + 40, dy - 2, dz, dir, 40);




	RlocateBlock(bi, dx + 19, dy - 3, dz, dir, 19);
	RlocateBlock(cy, dx + 20, dy - 3, dz, dir, 20);
	RlocateBlock(lp, dx + 21, dy - 3, dz, dir, 21);
	RlocateBlock(lp, dx + 22, dy - 3, dz, dir, 22);
	RlocateBlock(lp, dx + 23, dy - 3, dz, dir, 23);
	RlocateBlock(lp, dx + 24, dy - 3, dz, dir, 24);
	RlocateBlock(lp, dx + 25, dy - 3, dz, dir, 25);
	RlocateBlock(lp, dx + 26, dy - 3, dz, dir, 26);
	RlocateBlock(lp, dx + 27, dy - 3, dz, dir, 27);
	RlocateBlock(lp, dx + 28, dy - 3, dz, dir, 28);
	RlocateBlock(cy, dx + 29, dy - 3, dz, dir, 29);
	RlocateBlock(qu, dx + 30, dy - 3, dz, dir, 30);
	RlocateBlock(qu, dx + 31, dy - 3, dz, dir, 31);
	RlocateBlock(qu, dx + 32, dy - 3, dz, dir, 32);
	RlocateBlock(qu, dx + 33, dy - 3, dz, dir, 33);
	RlocateBlock(qu, dx + 34, dy - 3, dz, dir, 34);
	RlocateBlock(qu, dx + 35, dy - 3, dz, dir, 35);
	RlocateBlock(qu, dx + 36, dy - 3, dz, dir, 36);
	RlocateBlock(lb, dx + 37, dy - 3, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy - 3, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy - 3, dz, dir, 39);
	RlocateBlock(lp, dx + 40, dy - 3, dz, dir, 40);



	RlocateBlock(lb, dx + 18, dy - 4, dz, dir, 18);
	RlocateBlock(lp, dx + 19, dy - 4, dz, dir, 19);
	RlocateBlock(lp, dx + 20, dy - 4, dz, dir, 20);
	RlocateBlock(lp, dx + 21, dy - 4, dz, dir, 21);
	RlocateBlock(lp, dx + 22, dy - 4, dz, dir, 22);
	RlocateBlock(lp, dx + 23, dy - 4, dz, dir, 23);
	RlocateBlock(lp, dx + 24, dy - 4, dz, dir, 24);
	RlocateBlock(lp, dx + 25, dy - 4, dz, dir, 25);
	RlocateBlock(lp, dx + 26, dy - 4, dz, dir, 26);
	RlocateBlock(lp, dx + 27, dy - 4, dz, dir, 27);
	RlocateBlock(lb, dx + 28, dy - 4, dz, dir, 28);
	RlocateBlock(qu, dx + 29, dy - 4, dz, dir, 29);
	RlocateBlock(qu, dx + 30, dy - 4, dz, dir, 30);
	RlocateBlock(qu, dx + 31, dy - 4, dz, dir, 31);
	RlocateBlock(qu, dx + 32, dy - 4, dz, dir, 32);
	RlocateBlock(qu, dx + 33, dy - 4, dz, dir, 33);
	RlocateBlock(qu, dx + 34, dy - 4, dz, dir, 34);
	RlocateBlock(qu, dx + 35, dy - 4, dz, dir, 35);
	RlocateBlock(qu, dx + 36, dy - 4, dz, dir, 36);
	RlocateBlock(lb, dx + 37, dy - 4, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy - 4, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy - 4, dz, dir, 39);
	RlocateBlock(cy, dx + 40, dy - 4, dz, dir, 40);



	RlocateBlock(bi, dx + 17, dy - 5, dz, dir, 17);
	RlocateBlock(lp, dx + 18, dy - 5, dz, dir, 18);
	RlocateBlock(lp, dx + 19, dy - 5, dz, dir, 19);
	RlocateBlock(lp, dx + 20, dy - 5, dz, dir, 20);
	RlocateBlock(lp, dx + 21, dy - 5, dz, dir, 21);
	RlocateBlock(lp, dx + 22, dy - 5, dz, dir, 22);
	RlocateBlock(lp, dx + 23, dy - 5, dz, dir, 23);
	RlocateBlock(lp, dx + 24, dy - 5, dz, dir, 24);
	RlocateBlock(lp, dx + 25, dy - 5, dz, dir, 25);
	RlocateBlock(lp, dx + 26, dy - 5, dz, dir, 26);
	RlocateBlock(lp, dx + 27, dy - 5, dz, dir, 27);
	RlocateBlock(lg, dx + 28, dy - 5, dz, dir, 28);
	RlocateBlock(qu, dx + 29, dy - 5, dz, dir, 29);
	RlocateBlock(qu, dx + 30, dy - 5, dz, dir, 30);
	RlocateBlock(qu, dx + 31, dy - 5, dz, dir, 31);
	RlocateBlock(qu, dx + 32, dy - 5, dz, dir, 32);
	RlocateBlock(qu, dx + 33, dy - 5, dz, dir, 33);
	RlocateBlock(qu, dx + 34, dy - 5, dz, dir, 34);
	RlocateBlock(qu, dx + 35, dy - 5, dz, dir, 35);
	RlocateBlock(qu, dx + 36, dy - 5, dz, dir, 36);
	RlocateBlock(cy, dx + 37, dy - 5, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy - 5, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy - 5, dz, dir, 39);
	RlocateBlock(cy, dx + 40, dy - 5, dz, dir, 40);




	RlocateBlock(cy, dx + 17, dy - 6, dz, dir, 17);
	RlocateBlock(lp, dx + 18, dy - 6, dz, dir, 18);
	RlocateBlock(cy, dx + 19, dy - 6, dz, dir, 19);
	RlocateBlock(lb, dx + 20, dy - 6, dz, dir, 20);
	RlocateBlock(lb, dx + 21, dy - 6, dz, dir, 21);
	RlocateBlock(lp, dx + 22, dy - 6, dz, dir, 22);
	RlocateBlock(lp, dx + 23, dy - 6, dz, dir, 23);
	RlocateBlock(lp, dx + 24, dy - 6, dz, dir, 24);
	RlocateBlock(lp, dx + 25, dy - 6, dz, dir, 25);
	RlocateBlock(lp, dx + 26, dy - 6, dz, dir, 26);
	RlocateBlock(cy, dx + 27, dy - 6, dz, dir, 27);
	RlocateBlock(qu, dx + 28, dy - 6, dz, dir, 28);
	RlocateBlock(qu, dx + 29, dy - 6, dz, dir, 29);
	RlocateBlock(qu, dx + 30, dy - 6, dz, dir, 30);
	RlocateBlock(qu, dx + 31, dy - 6, dz, dir, 31);
	RlocateBlock(qu, dx + 32, dy - 6, dz, dir, 32);
	RlocateBlock(qu, dx + 33, dy - 6, dz, dir, 33);
	RlocateBlock(qu, dx + 34, dy - 6, dz, dir, 34);
	RlocateBlock(qu, dx + 35, dy - 6, dz, dir, 35);
	RlocateBlock(qu, dx + 36, dy - 6, dz, dir, 36);
	RlocateBlock(cy, dx + 37, dy - 6, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy - 6, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy - 6, dz, dir, 39);
	RlocateBlock(lb, dx + 40, dy - 6, dz, dir, 40);



	RlocateBlock(bi, dx + 18, dy - 7, dz, dir, 18);
	RlocateBlock(qu, dx + 19, dy - 7, dz, dir, 19);
	RlocateBlock(qu, dx + 20, dy - 7, dz, dir, 20);
	RlocateBlock(lb, dx + 21, dy - 7, dz, dir, 21);
	RlocateBlock(lp, dx + 22, dy - 7, dz, dir, 22);
	RlocateBlock(lp, dx + 23, dy - 7, dz, dir, 23);
	RlocateBlock(lp, dx + 24, dy - 7, dz, dir, 24);
	RlocateBlock(lp, dx + 25, dy - 7, dz, dir, 25);
	RlocateBlock(lp, dx + 26, dy - 7, dz, dir, 26);
	RlocateBlock(bi, dx + 27, dy - 7, dz, dir, 27);
	RlocateBlock(qu, dx + 28, dy - 7, dz, dir, 28);
	RlocateBlock(qu, dx + 29, dy - 7, dz, dir, 29);
	RlocateBlock(qu, dx + 30, dy - 7, dz, dir, 30);
	RlocateBlock(qu, dx + 31, dy - 7, dz, dir, 31);
	RlocateBlock(qu, dx + 32, dy - 7, dz, dir, 32);
	RlocateBlock(qu, dx + 33, dy - 7, dz, dir, 33);
	RlocateBlock(qu, dx + 34, dy - 7, dz, dir, 34);
	RlocateBlock(qu, dx + 35, dy - 7, dz, dir, 35);
	RlocateBlock(qu, dx + 36, dy - 7, dz, dir, 36);
	RlocateBlock(lb, dx + 37, dy - 7, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy - 7, dz, dir, 38);
	RlocateBlock(lp, dx + 39, dy - 7, dz, dir, 39);
	RlocateBlock(bi, dx + 40, dy - 7, dz, dir, 40);



	RlocateBlock(cy, dx + 21, dy - 8, dz, dir, 21);
	RlocateBlock(lp, dx + 22, dy - 8, dz, dir, 22);
	RlocateBlock(lp, dx + 23, dy - 8, dz, dir, 23);
	RlocateBlock(lp, dx + 24, dy - 8, dz, dir, 24);
	RlocateBlock(lp, dx + 25, dy - 8, dz, dir, 25);
	RlocateBlock(lb, dx + 26, dy - 8, dz, dir, 26);
	RlocateBlock(qu, dx + 27, dy - 8, dz, dir, 27);
	RlocateBlock(qu, dx + 28, dy - 8, dz, dir, 28);
	RlocateBlock(qu, dx + 29, dy - 8, dz, dir, 29);
	RlocateBlock(qu, dx + 30, dy - 8, dz, dir, 30);
	RlocateBlock(qu, dx + 31, dy - 8, dz, dir, 31);
	RlocateBlock(qu, dx + 32, dy - 8, dz, dir, 32);
	RlocateBlock(qu, dx + 33, dy - 8, dz, dir, 33);
	RlocateBlock(qu, dx + 34, dy - 8, dz, dir, 34);
	RlocateBlock(qu, dx + 35, dy - 8, dz, dir, 35);
	RlocateBlock(qu, dx + 36, dy - 8, dz, dir, 36);
	RlocateBlock(lb, dx + 37, dy - 8, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy - 8, dz, dir, 38);
	RlocateBlock(cy, dx + 39, dy - 8, dz, dir, 39);



	RlocateBlock(lp, dx + 21, dy - 9, dz, dir, 21);
	RlocateBlock(lp, dx + 22, dy - 9, dz, dir, 22);
	RlocateBlock(lp, dx + 23, dy - 9, dz, dir, 23);
	RlocateBlock(lp, dx + 24, dy - 9, dz, dir, 24);
	RlocateBlock(cy, dx + 25, dy - 9, dz, dir, 25);
	RlocateBlock(qu, dx + 26, dy - 9, dz, dir, 26);
	RlocateBlock(qu, dx + 27, dy - 9, dz, dir, 27);
	RlocateBlock(qu, dx + 28, dy - 9, dz, dir, 28);
	RlocateBlock(qu, dx + 29, dy - 9, dz, dir, 29);
	RlocateBlock(qu, dx + 30, dy - 9, dz, dir, 30);
	RlocateBlock(qu, dx + 31, dy - 9, dz, dir, 31);
	RlocateBlock(qu, dx + 32, dy - 9, dz, dir, 32);
	RlocateBlock(qu, dx + 33, dy - 9, dz, dir, 33);
	RlocateBlock(qu, dx + 34, dy - 9, dz, dir, 34);
	RlocateBlock(qu, dx + 35, dy - 9, dz, dir, 35);
	RlocateBlock(qu, dx + 36, dy - 9, dz, dir, 36);
	RlocateBlock(lb, dx + 37, dy - 9, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy - 9, dz, dir, 38);
	RlocateBlock(lb, dx + 39, dy - 9, dz, dir, 39);




	RlocateBlock(cy, dx + 21, dy - 10, dz, dir, 21);
	RlocateBlock(lp, dx + 22, dy - 10, dz, dir, 22);
	RlocateBlock(lp, dx + 23, dy - 10, dz, dir, 23);
	RlocateBlock(lp, dx + 24, dy - 10, dz, dir, 24);
	RlocateBlock(lb, dx + 25, dy - 10, dz, dir, 25);
	RlocateBlock(qu, dx + 26, dy - 10, dz, dir, 26);
	RlocateBlock(qu, dx + 27, dy - 10, dz, dir, 27);
	RlocateBlock(qu, dx + 28, dy - 10, dz, dir, 28);
	RlocateBlock(qu, dx + 29, dy - 10, dz, dir, 29);
	RlocateBlock(qu, dx + 30, dy - 10, dz, dir, 30);
	RlocateBlock(qu, dx + 31, dy - 10, dz, dir, 31);
	RlocateBlock(qu, dx + 32, dy - 10, dz, dir, 32);
	RlocateBlock(qu, dx + 33, dy - 10, dz, dir, 33);
	RlocateBlock(qu, dx + 34, dy - 10, dz, dir, 34);
	RlocateBlock(qu, dx + 35, dy - 10, dz, dir, 35);
	RlocateBlock(qu, dx + 36, dy - 10, dz, dir, 36);
	RlocateBlock(bi, dx + 37, dy - 10, dz, dir, 37);
	RlocateBlock(lp, dx + 38, dy - 10, dz, dir, 38);
	RlocateBlock(lb, dx + 39, dy - 10, dz, dir, 39);



	RlocateBlock(lb, dx + 22, dy - 11, dz, dir, 22);
	RlocateBlock(cy, dx + 23, dy - 11, dz, dir, 23);
	RlocateBlock(lb, dx + 24, dy - 11, dz, dir, 24);
	RlocateBlock(qu, dx + 25, dy - 11, dz, dir, 25);
	RlocateBlock(qu, dx + 26, dy - 11, dz, dir, 26);
	RlocateBlock(qu, dx + 27, dy - 11, dz, dir, 27);
	RlocateBlock(qu, dx + 28, dy - 11, dz, dir, 28);
	RlocateBlock(qu, dx + 29, dy - 11, dz, dir, 29);
	RlocateBlock(qu, dx + 30, dy - 11, dz, dir, 30);
	RlocateBlock(qu, dx + 31, dy - 11, dz, dir, 31);
	RlocateBlock(qu, dx + 32, dy - 11, dz, dir, 32);
	RlocateBlock(qu, dx + 33, dy - 11, dz, dir, 33);
	RlocateBlock(qu, dx + 34, dy - 11, dz, dir, 34);
	RlocateBlock(qu, dx + 35, dy - 11, dz, dir, 35);
	RlocateBlock(qu, dx + 36, dy - 11, dz, dir, 36);
	RlocateBlock(qu, dx + 37, dy - 11, dz, dir, 37);
	RlocateBlock(cy, dx + 38, dy - 11, dz, dir, 38);
	RlocateBlock(bi, dx + 39, dy - 11, dz, dir, 39);


	RlocateBlock(cy, dx + 38, dy - 12, dz, dir, 38);
	RlocateBlock(bi, dx + 39, dy - 12, dz, dir, 39);


	RlocateBlock(lg, dx + 38, dy - 13, dz, dir, 38);


	// A는 다 끝남.



	RlocateBlock(bi, dx + 53, dy + 11, dz, dir, 53);
	RlocateBlock(lp, dx + 54, dy + 11, dz, dir, 54);
	RlocateBlock(lp, dx + 55, dy + 11, dz, dir, 55);
	RlocateBlock(lp, dx + 56, dy + 11, dz, dir, 56);
	RlocateBlock(lp, dx + 57, dy + 11, dz, dir, 57);
	RlocateBlock(lp, dx + 58, dy + 11, dz, dir, 58);
	RlocateBlock(qu, dx + 59, dy + 11, dz, dir, 59);
	RlocateBlock(qu, dx + 60, dy + 11, dz, dir, 60);
	RlocateBlock(qu, dx + 61, dy + 11, dz, dir, 61);
	RlocateBlock(qu, dx + 62, dy + 11, dz, dir, 62);
	RlocateBlock(lg, dx + 63, dy + 11, dz, dir, 63);
	RlocateBlock(lp, dx + 64, dy + 11, dz, dir, 64);
	RlocateBlock(lp, dx + 65, dy + 11, dz, dir, 65);
	RlocateBlock(lp, dx + 66, dy + 11, dz, dir, 66);
	RlocateBlock(lp, dx + 67, dy + 11, dz, dir, 67);
	RlocateBlock(lp, dx + 68, dy + 11, dz, dir, 68);
	RlocateBlock(lp, dx + 69, dy + 11, dz, dir, 69);
	RlocateBlock(lp, dx + 70, dy + 11, dz, dir, 70);
	RlocateBlock(lb, dx + 71, dy + 11, dz, dir, 71);
	RlocateBlock(qu, dx + 72, dy + 11, dz, dir, 72);
	RlocateBlock(qu, dx + 73, dy + 11, dz, dir, 73);
	RlocateBlock(qu, dx + 74, dy + 11, dz, dir, 74);
	RlocateBlock(qu, dx + 75, dy + 11, dz, dir, 75);
	RlocateBlock(qu, dx + 76, dy + 11, dz, dir, 76);
	RlocateBlock(qu, dx + 77, dy + 11, dz, dir, 77);
	RlocateBlock(qu, dx + 78, dy + 11, dz, dir, 78);
	RlocateBlock(lg, dx + 79, dy + 11, dz, dir, 79);
	RlocateBlock(lb, dx + 80, dy + 11, dz, dir, 80);  // 여기가 U의 기준점




	RlocateBlock(cy, dx + 54, dy + 12, dz, dir, 54);
	RlocateBlock(lp, dx + 55, dy + 12, dz, dir, 55);
	RlocateBlock(lp, dx + 56, dy + 12, dz, dir, 56);
	RlocateBlock(lp, dx + 57, dy + 12, dz, dir, 57);
	RlocateBlock(lp, dx + 58, dy + 12, dz, dir, 58);
	RlocateBlock(lb, dx + 59, dy + 12, dz, dir, 59);
	RlocateBlock(qu, dx + 60, dy + 12, dz, dir, 60);
	RlocateBlock(qu, dx + 61, dy + 12, dz, dir, 61);
	RlocateBlock(qu, dx + 62, dy + 12, dz, dir, 62);
	RlocateBlock(qu, dx + 63, dy + 12, dz, dir, 63);
	RlocateBlock(lb, dx + 64, dy + 12, dz, dir, 64);
	RlocateBlock(lp, dx + 65, dy + 12, dz, dir, 65);
	RlocateBlock(lp, dx + 66, dy + 12, dz, dir, 66);
	RlocateBlock(lp, dx + 67, dy + 12, dz, dir, 67);
	RlocateBlock(lp, dx + 68, dy + 12, dz, dir, 68);
	RlocateBlock(lp, dx + 69, dy + 12, dz, dir, 69);
	RlocateBlock(lp, dx + 70, dy + 12, dz, dir, 70);
	RlocateBlock(cy, dx + 71, dy + 12, dz, dir, 71);



	RlocateBlock(lb, dx + 54, dy + 13, dz, dir, 54);
	RlocateBlock(lp, dx + 55, dy + 13, dz, dir, 55);
	RlocateBlock(lp, dx + 56, dy + 13, dz, dir, 56);
	RlocateBlock(lp, dx + 57, dy + 13, dz, dir, 57);
	RlocateBlock(lp, dx + 58, dy + 13, dz, dir, 58);
	RlocateBlock(lb, dx + 59, dy + 13, dz, dir, 59);
	RlocateBlock(qu, dx + 60, dy + 13, dz, dir, 60);
	RlocateBlock(qu, dx + 61, dy + 13, dz, dir, 61);
	RlocateBlock(qu, dx + 62, dy + 13, dz, dir, 62);
	RlocateBlock(qu, dx + 63, dy + 13, dz, dir, 63);
	RlocateBlock(qu, dx + 64, dy + 13, dz, dir, 64);
	RlocateBlock(lb, dx + 65, dy + 13, dz, dir, 65);
	RlocateBlock(lp, dx + 66, dy + 13, dz, dir, 66);
	RlocateBlock(lp, dx + 67, dy + 13, dz, dir, 67);
	RlocateBlock(lp, dx + 68, dy + 13, dz, dir, 68);
	RlocateBlock(lp, dx + 69, dy + 13, dz, dir, 69);
	RlocateBlock(lp, dx + 70, dy + 13, dz, dir, 70);
	RlocateBlock(cy, dx + 71, dy + 13, dz, dir, 71);
	RlocateBlock(qu, dx + 72, dy + 13, dz, dir, 72);
	RlocateBlock(qu, dx + 73, dy + 13, dz, dir, 73);
	RlocateBlock(qu, dx + 74, dy + 13, dz, dir, 74);
	RlocateBlock(qu, dx + 75, dy + 13, dz, dir, 75);
	RlocateBlock(qu, dx + 76, dy + 13, dz, dir, 76);
	RlocateBlock(qu, dx + 77, dy + 13, dz, dir, 77);
	RlocateBlock(qu, dx + 78, dy + 13, dz, dir, 78);
	RlocateBlock(qu, dx + 79, dy + 13, dz, dir, 79);
	RlocateBlock(qu, dx + 80, dy + 13, dz, dir, 80);
	RlocateBlock(qu, dx + 81, dy + 13, dz, dir, 81);



	RlocateBlock(lp, dx + 55, dy + 14, dz, dir, 55);
	RlocateBlock(lp, dx + 56, dy + 14, dz, dir, 56);
	RlocateBlock(lp, dx + 57, dy + 14, dz, dir, 57);
	RlocateBlock(lp, dx + 58, dy + 14, dz, dir, 58);
	RlocateBlock(cy, dx + 59, dy + 14, dz, dir, 59);
	RlocateBlock(qu, dx + 60, dy + 14, dz, dir, 60);
	RlocateBlock(qu, dx + 61, dy + 14, dz, dir, 61);
	RlocateBlock(qu, dx + 62, dy + 14, dz, dir, 62);
	RlocateBlock(qu, dx + 63, dy + 14, dz, dir, 63);
	RlocateBlock(br, dx + 64, dy + 14, dz, dir, 64);
	RlocateBlock(mg, dx + 65, dy + 14, dz, dir, 65);
	RlocateBlock(pt, dx + 66, dy + 14, dz, dir, 66);
	RlocateBlock(pr, dx + 67, dy + 14, dz, dir, 67);
	RlocateBlock(pt, dx + 68, dy + 14, dz, dir, 68);
	RlocateBlock(mg, dx + 69, dy + 14, dz, dir, 69);
	RlocateBlock(pr, dx + 70, dy + 14, dz, dir, 70);
	RlocateBlock(pt, dx + 71, dy + 14, dz, dir, 71);
	RlocateBlock(br, dx + 72, dy + 14, dz, dir, 72);
	RlocateBlock(og, dx + 73, dy + 14, dz, dir, 73);
	RlocateBlock(br, dx + 74, dy + 14, dz, dir, 74);
	RlocateBlock(br, dx + 75, dy + 14, dz, dir, 75);
	RlocateBlock(og, dx + 76, dy + 14, dz, dir, 76);
	RlocateBlock(br, dx + 77, dy + 14, dz, dir, 77);
	RlocateBlock(br, dx + 78, dy + 14, dz, dir, 78);
	RlocateBlock(og, dx + 79, dy + 14, dz, dir, 79);
	RlocateBlock(og, dx + 80, dy + 14, dz, dir, 80);
	RlocateBlock(pn, dx + 81, dy + 14, dz, dir, 81);



	RlocateBlock(lb, dx + 55, dy + 15, dz, dir, 55);
	RlocateBlock(lp, dx + 56, dy + 15, dz, dir, 56);
	RlocateBlock(lp, dx + 57, dy + 15, dz, dir, 57);
	RlocateBlock(lp, dx + 58, dy + 15, dz, dir, 58);
	RlocateBlock(lp, dx + 59, dy + 15, dz, dir, 59);
	RlocateBlock(qu, dx + 60, dy + 15, dz, dir, 60);
	RlocateBlock(qu, dx + 61, dy + 15, dz, dir, 61);
	RlocateBlock(qu, dx + 62, dy + 15, dz, dir, 62);
	RlocateBlock(qu, dx + 63, dy + 15, dz, dir, 63);
	RlocateBlock(rd, dx + 64, dy + 15, dz, dir, 64);
	RlocateBlock(og, dx + 65, dy + 15, dz, dir, 65);
	RlocateBlock(br, dx + 66, dy + 15, dz, dir, 66);
	RlocateBlock(pr, dx + 67, dy + 15, dz, dir, 67);
	RlocateBlock(pr, dx + 68, dy + 15, dz, dir, 68);
	RlocateBlock(pr, dx + 69, dy + 15, dz, dir, 69);
	RlocateBlock(pr, dx + 70, dy + 15, dz, dir, 70);
	RlocateBlock(pr, dx + 71, dy + 15, dz, dir, 71);
	RlocateBlock(pr, dx + 72, dy + 15, dz, dir, 72);
	RlocateBlock(pn, dx + 73, dy + 15, dz, dir, 73);
	RlocateBlock(pn, dx + 74, dy + 15, dz, dir, 74);
	RlocateBlock(pn, dx + 75, dy + 15, dz, dir, 75);
	RlocateBlock(pn, dx + 76, dy + 15, dz, dir, 76);
	RlocateBlock(pn, dx + 77, dy + 15, dz, dir, 77);
	RlocateBlock(pn, dx + 78, dy + 15, dz, dir, 78);
	RlocateBlock(pn, dx + 79, dy + 15, dz, dir, 79);
	RlocateBlock(og, dx + 80, dy + 15, dz, dir, 80);
	RlocateBlock(pt, dx + 81, dy + 15, dz, dir, 81);








	RlocateBlock(lp, dx + 56, dy + 16, dz, dir, 56);
	RlocateBlock(lp, dx + 57, dy + 16, dz, dir, 57);
	RlocateBlock(lp, dx + 58, dy + 16, dz, dir, 58);
	RlocateBlock(lp, dx + 59, dy + 16, dz, dir, 59);
	RlocateBlock(lb, dx + 60, dy + 16, dz, dir, 60);
	RlocateBlock(qu, dx + 61, dy + 16, dz, dir, 61);
	RlocateBlock(qu, dx + 62, dy + 16, dz, dir, 62);
	RlocateBlock(qu, dx + 63, dy + 16, dz, dir, 63);
	RlocateBlock(rd, dx + 64, dy + 16, dz, dir, 64);
	RlocateBlock(wt, dx + 65, dy + 16, dz, dir, 65);
	RlocateBlock(qu, dx + 66, dy + 16, dz, dir, 66);
	RlocateBlock(lb, dx + 67, dy + 16, dz, dir, 67);
	RlocateBlock(lp, dx + 68, dy + 16, dz, dir, 68);
	RlocateBlock(lp, dx + 69, dy + 16, dz, dir, 69);
	RlocateBlock(lp, dx + 70, dy + 16, dz, dir, 70);
	RlocateBlock(lp, dx + 71, dy + 16, dz, dir, 71);
	RlocateBlock(lp, dx + 72, dy + 16, dz, dir, 72);
	RlocateBlock(qu, dx + 73, dy + 16, dz, dir, 73);
	RlocateBlock(qu, dx + 74, dy + 16, dz, dir, 74);
	RlocateBlock(qu, dx + 75, dy + 16, dz, dir, 75);
	RlocateBlock(qu, dx + 76, dy + 16, dz, dir, 76);
	RlocateBlock(qu, dx + 77, dy + 16, dz, dir, 77);
	RlocateBlock(qu, dx + 78, dy + 16, dz, dir, 78);
	RlocateBlock(qu, dx + 79, dy + 16, dz, dir, 79);
	RlocateBlock(wt, dx + 80, dy + 16, dz, dir, 80);
	RlocateBlock(pt, dx + 81, dy + 16, dz, dir, 81);





	RlocateBlock(cy, dx + 56, dy + 17, dz, dir, 56);
	RlocateBlock(lp, dx + 57, dy + 17, dz, dir, 57);
	RlocateBlock(lp, dx + 58, dy + 17, dz, dir, 58);
	RlocateBlock(lp, dx + 59, dy + 17, dz, dir, 59);
	RlocateBlock(lb, dx + 60, dy + 17, dz, dir, 60);
	RlocateBlock(qu, dx + 61, dy + 17, dz, dir, 61);
	RlocateBlock(qu, dx + 62, dy + 17, dz, dir, 62);
	RlocateBlock(qu, dx + 63, dy + 17, dz, dir, 63);
	RlocateBlock(rd, dx + 64, dy + 17, dz, dir, 64);
	RlocateBlock(wt, dx + 65, dy + 17, dz, dir, 65);
	RlocateBlock(qu, dx + 66, dy + 17, dz, dir, 66);
	RlocateBlock(qu, dx + 67, dy + 17, dz, dir, 67);
	RlocateBlock(lp, dx + 68, dy + 17, dz, dir, 68);
	RlocateBlock(lp, dx + 69, dy + 17, dz, dir, 69);
	RlocateBlock(lp, dx + 70, dy + 17, dz, dir, 70);
	RlocateBlock(lp, dx + 71, dy + 17, dz, dir, 71);
	RlocateBlock(lp, dx + 72, dy + 17, dz, dir, 72);
	RlocateBlock(lb, dx + 73, dy + 17, dz, dir, 73);
	RlocateBlock(qu, dx + 74, dy + 17, dz, dir, 74);
	RlocateBlock(qu, dx + 75, dy + 17, dz, dir, 75);
	RlocateBlock(qu, dx + 76, dy + 17, dz, dir, 76);
	RlocateBlock(qu, dx + 77, dy + 17, dz, dir, 77);
	RlocateBlock(qu, dx + 78, dy + 17, dz, dir, 78);
	RlocateBlock(qu, dx + 79, dy + 17, dz, dir, 79);
	RlocateBlock(wt, dx + 80, dy + 17, dz, dir, 80);
	RlocateBlock(pt, dx + 81, dy + 17, dz, dir, 81);





	RlocateBlock(bi, dx + 56, dy + 18, dz, dir, 56);
	RlocateBlock(lp, dx + 57, dy + 18, dz, dir, 57);
	RlocateBlock(lp, dx + 58, dy + 18, dz, dir, 58);
	RlocateBlock(lp, dx + 59, dy + 18, dz, dir, 59);
	RlocateBlock(cy, dx + 60, dy + 18, dz, dir, 60);
	RlocateBlock(qu, dx + 61, dy + 18, dz, dir, 61);
	RlocateBlock(qu, dx + 62, dy + 18, dz, dir, 62);
	RlocateBlock(qu, dx + 63, dy + 18, dz, dir, 63);
	RlocateBlock(rd, dx + 64, dy + 18, dz, dir, 64);
	RlocateBlock(wt, dx + 65, dy + 18, dz, dir, 65);
	RlocateBlock(qu, dx + 66, dy + 18, dz, dir, 66);
	RlocateBlock(qu, dx + 67, dy + 18, dz, dir, 67);
	RlocateBlock(lb, dx + 68, dy + 18, dz, dir, 68);
	RlocateBlock(lp, dx + 69, dy + 18, dz, dir, 69);
	RlocateBlock(lp, dx + 70, dy + 18, dz, dir, 70);
	RlocateBlock(lp, dx + 71, dy + 18, dz, dir, 71);
	RlocateBlock(lp, dx + 72, dy + 18, dz, dir, 72);
	RlocateBlock(lp, dx + 73, dy + 18, dz, dir, 73);
	RlocateBlock(lb, dx + 74, dy + 18, dz, dir, 74);
	RlocateBlock(qu, dx + 75, dy + 18, dz, dir, 75);
	RlocateBlock(qu, dx + 76, dy + 18, dz, dir, 76);
	RlocateBlock(qu, dx + 77, dy + 18, dz, dir, 77);
	RlocateBlock(qu, dx + 78, dy + 18, dz, dir, 78);
	RlocateBlock(qu, dx + 79, dy + 18, dz, dir, 79);
	RlocateBlock(wt, dx + 80, dy + 18, dz, dir, 80);
	RlocateBlock(pt, dx + 81, dy + 18, dz, dir, 81);





	RlocateBlock(lb, dx + 57, dy + 19, dz, dir, 57);
	RlocateBlock(lp, dx + 58, dy + 19, dz, dir, 58);
	RlocateBlock(lp, dx + 59, dy + 19, dz, dir, 59);
	RlocateBlock(lb, dx + 60, dy + 19, dz, dir, 60);
	RlocateBlock(qu, dx + 61, dy + 19, dz, dir, 61);
	RlocateBlock(qu, dx + 62, dy + 19, dz, dir, 62);
	RlocateBlock(qu, dx + 63, dy + 19, dz, dir, 63);
	RlocateBlock(rd, dx + 64, dy + 19, dz, dir, 64);
	RlocateBlock(wt, dx + 65, dy + 19, dz, dir, 65);
	RlocateBlock(qu, dx + 66, dy + 19, dz, dir, 66);
	RlocateBlock(qu, dx + 67, dy + 19, dz, dir, 67);
	RlocateBlock(qu, dx + 68, dy + 19, dz, dir, 68);
	RlocateBlock(cy, dx + 69, dy + 19, dz, dir, 69);
	RlocateBlock(lp, dx + 70, dy + 19, dz, dir, 70);
	RlocateBlock(lp, dx + 71, dy + 19, dz, dir, 71);
	RlocateBlock(lp, dx + 72, dy + 19, dz, dir, 72);
	RlocateBlock(lp, dx + 73, dy + 19, dz, dir, 73);
	RlocateBlock(lp, dx + 74, dy + 19, dz, dir, 74);
	RlocateBlock(lg, dx + 75, dy + 19, dz, dir, 75);
	RlocateBlock(qu, dx + 76, dy + 19, dz, dir, 76);
	RlocateBlock(qu, dx + 77, dy + 19, dz, dir, 77);
	RlocateBlock(qu, dx + 78, dy + 19, dz, dir, 78);
	RlocateBlock(qu, dx + 79, dy + 19, dz, dir, 79);
	RlocateBlock(wt, dx + 80, dy + 19, dz, dir, 80);
	RlocateBlock(pt, dx + 81, dy + 19, dz, dir, 81);




	RlocateBlock(lg, dx + 58, dy + 20, dz, dir, 58);
	RlocateBlock(bi, dx + 59, dy + 20, dz, dir, 59);
	RlocateBlock(qu, dx + 60, dy + 20, dz, dir, 60);
	RlocateBlock(qu, dx + 61, dy + 20, dz, dir, 61);
	RlocateBlock(qu, dx + 62, dy + 20, dz, dir, 62);
	RlocateBlock(qu, dx + 63, dy + 20, dz, dir, 63);
	RlocateBlock(rd, dx + 64, dy + 20, dz, dir, 64);
	RlocateBlock(wt, dx + 65, dy + 20, dz, dir, 65);
	RlocateBlock(qu, dx + 66, dy + 20, dz, dir, 66);
	RlocateBlock(qu, dx + 67, dy + 20, dz, dir, 67);
	RlocateBlock(qu, dx + 68, dy + 20, dz, dir, 68);
	RlocateBlock(lb, dx + 69, dy + 20, dz, dir, 69);
	RlocateBlock(lp, dx + 70, dy + 20, dz, dir, 70);
	RlocateBlock(lp, dx + 71, dy + 20, dz, dir, 71);
	RlocateBlock(lp, dx + 72, dy + 20, dz, dir, 72);
	RlocateBlock(lp, dx + 73, dy + 20, dz, dir, 73);
	RlocateBlock(lp, dx + 74, dy + 20, dz, dir, 74);
	RlocateBlock(cy, dx + 75, dy + 20, dz, dir, 75);
	RlocateBlock(qu, dx + 76, dy + 20, dz, dir, 76);
	RlocateBlock(qu, dx + 77, dy + 20, dz, dir, 77);
	RlocateBlock(qu, dx + 78, dy + 20, dz, dir, 78);
	RlocateBlock(qu, dx + 79, dy + 20, dz, dir, 79);
	RlocateBlock(wt, dx + 80, dy + 20, dz, dir, 80);
	RlocateBlock(pt, dx + 81, dy + 20, dz, dir, 81);




	RlocateBlock(rd, dx + 64, dy + 21, dz, dir, 64);
	RlocateBlock(wt, dx + 65, dy + 21, dz, dir, 65);
	RlocateBlock(qu, dx + 66, dy + 21, dz, dir, 66);
	RlocateBlock(qu, dx + 67, dy + 21, dz, dir, 67);
	RlocateBlock(qu, dx + 68, dy + 21, dz, dir, 68);
	RlocateBlock(qu, dx + 69, dy + 21, dz, dir, 69);
	RlocateBlock(cy, dx + 70, dy + 21, dz, dir, 70);
	RlocateBlock(lp, dx + 71, dy + 21, dz, dir, 71);
	RlocateBlock(lp, dx + 72, dy + 21, dz, dir, 72);
	RlocateBlock(lp, dx + 73, dy + 21, dz, dir, 73);
	RlocateBlock(lp, dx + 74, dy + 21, dz, dir, 74);
	RlocateBlock(cy, dx + 75, dy + 21, dz, dir, 75);
	RlocateBlock(qu, dx + 76, dy + 21, dz, dir, 76);
	RlocateBlock(qu, dx + 77, dy + 21, dz, dir, 77);
	RlocateBlock(qu, dx + 78, dy + 21, dz, dir, 78);
	RlocateBlock(qu, dx + 79, dy + 21, dz, dir, 79);
	RlocateBlock(wt, dx + 80, dy + 21, dz, dir, 80);
	RlocateBlock(pt, dx + 81, dy + 21, dz, dir, 81);




	RlocateBlock(rd, dx + 64, dy + 22, dz, dir, 64);
	RlocateBlock(wt, dx + 65, dy + 22, dz, dir, 65);
	RlocateBlock(qu, dx + 66, dy + 22, dz, dir, 66);
	RlocateBlock(qu, dx + 67, dy + 22, dz, dir, 67);
	RlocateBlock(qu, dx + 68, dy + 22, dz, dir, 68);
	RlocateBlock(qu, dx + 69, dy + 22, dz, dir, 69);
	RlocateBlock(lb, dx + 70, dy + 22, dz, dir, 70);
	RlocateBlock(lp, dx + 71, dy + 22, dz, dir, 71);
	RlocateBlock(lp, dx + 72, dy + 22, dz, dir, 72);
	RlocateBlock(lp, dx + 73, dy + 22, dz, dir, 73);
	RlocateBlock(cy, dx + 74, dy + 22, dz, dir, 74);
	RlocateBlock(qu, dx + 75, dy + 22, dz, dir, 75);
	RlocateBlock(qu, dx + 76, dy + 22, dz, dir, 76);
	RlocateBlock(qu, dx + 77, dy + 22, dz, dir, 77);
	RlocateBlock(qu, dx + 78, dy + 22, dz, dir, 78);
	RlocateBlock(qu, dx + 79, dy + 22, dz, dir, 79);
	RlocateBlock(wt, dx + 80, dy + 22, dz, dir, 80);
	RlocateBlock(pt, dx + 81, dy + 22, dz, dir, 81);




	RlocateBlock(rd, dx + 64, dy + 23, dz, dir, 64);
	RlocateBlock(wt, dx + 65, dy + 23, dz, dir, 65);
	RlocateBlock(qu, dx + 66, dy + 23, dz, dir, 66);
	RlocateBlock(qu, dx + 67, dy + 23, dz, dir, 67);
	RlocateBlock(qu, dx + 68, dy + 23, dz, dir, 68);
	RlocateBlock(qu, dx + 69, dy + 23, dz, dir, 69);
	RlocateBlock(qu, dx + 70, dy + 23, dz, dir, 70);
	RlocateBlock(cy, dx + 71, dy + 23, dz, dir, 71);
	RlocateBlock(lp, dx + 72, dy + 23, dz, dir, 72);
	RlocateBlock(lb, dx + 73, dy + 23, dz, dir, 73);
	RlocateBlock(qu, dx + 74, dy + 23, dz, dir, 74);
	RlocateBlock(qu, dx + 75, dy + 23, dz, dir, 75);
	RlocateBlock(qu, dx + 76, dy + 23, dz, dir, 76);
	RlocateBlock(qu, dx + 77, dy + 23, dz, dir, 77);
	RlocateBlock(qu, dx + 78, dy + 23, dz, dir, 78);
	RlocateBlock(qu, dx + 79, dy + 23, dz, dir, 79);
	RlocateBlock(wt, dx + 80, dy + 23, dz, dir, 80);
	RlocateBlock(pt, dx + 81, dy + 23, dz, dir, 81);


	RlocateBlock(rd, dx + 64, dy + 24, dz, dir, 64);
	RlocateBlock(wt, dx + 65, dy + 24, dz, dir, 65);
	RlocateBlock(qu, dx + 66, dy + 24, dz, dir, 66);
	RlocateBlock(qu, dx + 67, dy + 24, dz, dir, 67);
	RlocateBlock(qu, dx + 68, dy + 24, dz, dir, 68);
	RlocateBlock(qu, dx + 69, dy + 24, dz, dir, 69);
	RlocateBlock(qu, dx + 70, dy + 24, dz, dir, 70);
	RlocateBlock(qu, dx + 71, dy + 24, dz, dir, 71);
	RlocateBlock(qu, dx + 72, dy + 24, dz, dir, 72);
	RlocateBlock(qu, dx + 73, dy + 24, dz, dir, 73);
	RlocateBlock(qu, dx + 74, dy + 24, dz, dir, 74);
	RlocateBlock(qu, dx + 75, dy + 24, dz, dir, 75);
	RlocateBlock(qu, dx + 76, dy + 24, dz, dir, 76);
	RlocateBlock(qu, dx + 77, dy + 24, dz, dir, 77);
	RlocateBlock(qu, dx + 78, dy + 24, dz, dir, 78);
	RlocateBlock(qu, dx + 79, dy + 24, dz, dir, 79);
	RlocateBlock(wt, dx + 80, dy + 24, dz, dir, 80);
	RlocateBlock(pt, dx + 81, dy + 24, dz, dir, 81); //2



	RlocateBlock(rd, dx + 64, dy + 25, dz, dir, 64);
	RlocateBlock(wt, dx + 65, dy + 25, dz, dir, 65);
	RlocateBlock(qu, dx + 66, dy + 25, dz, dir, 66);
	RlocateBlock(qu, dx + 67, dy + 25, dz, dir, 67);
	RlocateBlock(qu, dx + 68, dy + 25, dz, dir, 68);
	RlocateBlock(qu, dx + 69, dy + 25, dz, dir, 69);
	RlocateBlock(qu, dx + 70, dy + 25, dz, dir, 70);
	RlocateBlock(qu, dx + 71, dy + 25, dz, dir, 71);
	RlocateBlock(qu, dx + 72, dy + 25, dz, dir, 72);
	RlocateBlock(qu, dx + 73, dy + 25, dz, dir, 73);
	RlocateBlock(qu, dx + 74, dy + 25, dz, dir, 74);
	RlocateBlock(qu, dx + 75, dy + 25, dz, dir, 75);
	RlocateBlock(qu, dx + 76, dy + 25, dz, dir, 76);
	RlocateBlock(qu, dx + 77, dy + 25, dz, dir, 77);
	RlocateBlock(qu, dx + 78, dy + 25, dz, dir, 78);
	RlocateBlock(qu, dx + 79, dy + 25, dz, dir, 79);
	RlocateBlock(wt, dx + 80, dy + 25, dz, dir, 80);
	RlocateBlock(pt, dx + 81, dy + 25, dz, dir, 81); //3


	RlocateBlock(rd, dx + 64, dy + 26, dz, dir, 64);
	RlocateBlock(wt, dx + 65, dy + 26, dz, dir, 65);
	RlocateBlock(qu, dx + 66, dy + 26, dz, dir, 66);
	RlocateBlock(qu, dx + 67, dy + 26, dz, dir, 67);
	RlocateBlock(qu, dx + 68, dy + 26, dz, dir, 68);
	RlocateBlock(qu, dx + 69, dy + 26, dz, dir, 69);
	RlocateBlock(qu, dx + 70, dy + 26, dz, dir, 70);
	RlocateBlock(qu, dx + 71, dy + 26, dz, dir, 71);
	RlocateBlock(qu, dx + 72, dy + 26, dz, dir, 72);
	RlocateBlock(qu, dx + 73, dy + 26, dz, dir, 73);
	RlocateBlock(qu, dx + 74, dy + 26, dz, dir, 74);
	RlocateBlock(qu, dx + 75, dy + 26, dz, dir, 75);
	RlocateBlock(qu, dx + 76, dy + 26, dz, dir, 76);
	RlocateBlock(qu, dx + 77, dy + 26, dz, dir, 77);
	RlocateBlock(qu, dx + 78, dy + 26, dz, dir, 78);
	RlocateBlock(qu, dx + 79, dy + 26, dz, dir, 79);
	RlocateBlock(wt, dx + 80, dy + 26, dz, dir, 80);
	RlocateBlock(pt, dx + 81, dy + 26, dz, dir, 81); //4



	RlocateBlock(rd, dx + 64, dy + 27, dz, dir, 64);
	RlocateBlock(wt, dx + 65, dy + 27, dz, dir, 65);
	RlocateBlock(qu, dx + 66, dy + 27, dz, dir, 66);
	RlocateBlock(qu, dx + 67, dy + 27, dz, dir, 67);
	RlocateBlock(qu, dx + 68, dy + 27, dz, dir, 68);
	RlocateBlock(qu, dx + 69, dy + 27, dz, dir, 69);
	RlocateBlock(qu, dx + 70, dy + 27, dz, dir, 70);
	RlocateBlock(qu, dx + 71, dy + 27, dz, dir, 71);
	RlocateBlock(qu, dx + 72, dy + 27, dz, dir, 72);
	RlocateBlock(qu, dx + 73, dy + 27, dz, dir, 73);
	RlocateBlock(qu, dx + 74, dy + 27, dz, dir, 74);
	RlocateBlock(qu, dx + 75, dy + 27, dz, dir, 75);
	RlocateBlock(qu, dx + 76, dy + 27, dz, dir, 76);
	RlocateBlock(qu, dx + 77, dy + 27, dz, dir, 77);
	RlocateBlock(qu, dx + 78, dy + 27, dz, dir, 78);
	RlocateBlock(qu, dx + 79, dy + 27, dz, dir, 79);
	RlocateBlock(wt, dx + 80, dy + 27, dz, dir, 80);
	RlocateBlock(pt, dx + 81, dy + 27, dz, dir, 81); //5


	RlocateBlock(rd, dx + 64, dy + 28, dz, dir, 64);
	RlocateBlock(wt, dx + 65, dy + 28, dz, dir, 65);
	RlocateBlock(qu, dx + 66, dy + 28, dz, dir, 66);
	RlocateBlock(qu, dx + 67, dy + 28, dz, dir, 67);
	RlocateBlock(qu, dx + 68, dy + 28, dz, dir, 68);
	RlocateBlock(qu, dx + 69, dy + 28, dz, dir, 69);
	RlocateBlock(qu, dx + 70, dy + 28, dz, dir, 70);
	RlocateBlock(qu, dx + 71, dy + 28, dz, dir, 71);
	RlocateBlock(qu, dx + 72, dy + 28, dz, dir, 72);
	RlocateBlock(qu, dx + 73, dy + 28, dz, dir, 73);
	RlocateBlock(qu, dx + 74, dy + 28, dz, dir, 74);
	RlocateBlock(qu, dx + 75, dy + 28, dz, dir, 75);
	RlocateBlock(qu, dx + 76, dy + 28, dz, dir, 76);
	RlocateBlock(qu, dx + 77, dy + 28, dz, dir, 77);
	RlocateBlock(qu, dx + 78, dy + 28, dz, dir, 78);
	RlocateBlock(qu, dx + 79, dy + 28, dz, dir, 79);
	RlocateBlock(wt, dx + 80, dy + 28, dz, dir, 80);
	RlocateBlock(pt, dx + 81, dy + 28, dz, dir, 81); //6


	RlocateBlock(rd, dx + 64, dy + 29, dz, dir, 64);
	RlocateBlock(wt, dx + 65, dy + 29, dz, dir, 65);
	RlocateBlock(qu, dx + 66, dy + 29, dz, dir, 66);
	RlocateBlock(qu, dx + 67, dy + 29, dz, dir, 67);
	RlocateBlock(qu, dx + 68, dy + 29, dz, dir, 68);
	RlocateBlock(qu, dx + 69, dy + 29, dz, dir, 69);
	RlocateBlock(qu, dx + 70, dy + 29, dz, dir, 70);
	RlocateBlock(qu, dx + 71, dy + 29, dz, dir, 71);
	RlocateBlock(qu, dx + 72, dy + 29, dz, dir, 72);
	RlocateBlock(qu, dx + 73, dy + 29, dz, dir, 73);
	RlocateBlock(qu, dx + 74, dy + 29, dz, dir, 74);
	RlocateBlock(qu, dx + 75, dy + 29, dz, dir, 75);
	RlocateBlock(qu, dx + 76, dy + 29, dz, dir, 76);
	RlocateBlock(qu, dx + 77, dy + 29, dz, dir, 77);
	RlocateBlock(qu, dx + 78, dy + 29, dz, dir, 78);
	RlocateBlock(qu, dx + 79, dy + 29, dz, dir, 79);
	RlocateBlock(pn, dx + 80, dy + 29, dz, dir, 80);
	RlocateBlock(pt, dx + 81, dy + 29, dz, dir, 81); //7





	RlocateBlock(rd, dx + 64, dy + 30, dz, dir, 64);
	RlocateBlock(rd, dx + 65, dy + 30, dz, dir, 65);
	RlocateBlock(rd, dx + 66, dy + 30, dz, dir, 66);
	RlocateBlock(rd, dx + 67, dy + 30, dz, dir, 67);
	RlocateBlock(rd, dx + 68, dy + 30, dz, dir, 68);
	RlocateBlock(rd, dx + 69, dy + 30, dz, dir, 69);
	RlocateBlock(rd, dx + 70, dy + 30, dz, dir, 70);
	RlocateBlock(rd, dx + 71, dy + 30, dz, dir, 71);
	RlocateBlock(rd, dx + 72, dy + 30, dz, dir, 72);
	RlocateBlock(rd, dx + 73, dy + 30, dz, dir, 73);
	RlocateBlock(rd, dx + 74, dy + 30, dz, dir, 74);
	RlocateBlock(rd, dx + 75, dy + 30, dz, dir, 75);
	RlocateBlock(rd, dx + 76, dy + 30, dz, dir, 76);
	RlocateBlock(rd, dx + 77, dy + 30, dz, dir, 77);
	RlocateBlock(rd, dx + 78, dy + 30, dz, dir, 78);
	RlocateBlock(rd, dx + 79, dy + 30, dz, dir, 79);
	RlocateBlock(rd, dx + 80, dy + 30, dz, dir, 80);
	RlocateBlock(pt, dx + 81, dy + 30, dz, dir, 81);





	RlocateBlock(bi, dx + 64, dy + 31, dz, dir, 64);
	RlocateBlock(bi, dx + 65, dy + 31, dz, dir, 65);
	RlocateBlock(bi, dx + 66, dy + 31, dz, dir, 66);
	RlocateBlock(bi, dx + 67, dy + 31, dz, dir, 67);
	RlocateBlock(bi, dx + 68, dy + 31, dz, dir, 68);
	RlocateBlock(bi, dx + 69, dy + 31, dz, dir, 69);
	RlocateBlock(bi, dx + 70, dy + 31, dz, dir, 70);
	RlocateBlock(bi, dx + 71, dy + 31, dz, dir, 71);
	RlocateBlock(bi, dx + 72, dy + 31, dz, dir, 72);
	RlocateBlock(bi, dx + 73, dy + 31, dz, dir, 73);
	RlocateBlock(bi, dx + 74, dy + 31, dz, dir, 74);
	RlocateBlock(bi, dx + 75, dy + 31, dz, dir, 75);
	RlocateBlock(bi, dx + 76, dy + 31, dz, dir, 76);
	RlocateBlock(bi, dx + 77, dy + 31, dz, dir, 77);
	RlocateBlock(bi, dx + 78, dy + 31, dz, dir, 78);
	RlocateBlock(bi, dx + 79, dy + 31, dz, dir, 79);
	RlocateBlock(bi, dx + 80, dy + 31, dz, dir, 80);
	RlocateBlock(bi, dx + 81, dy + 31, dz, dir, 81);  // U자 기준선 위로는 끝.



	RlocateBlock(bi, dx + 52, dy + 10, dz, dir, 52);
	RlocateBlock(lb, dx + 53, dy + 10, dz, dir, 53);
	RlocateBlock(lp, dx + 54, dy + 10, dz, dir, 54);
	RlocateBlock(lp, dx + 55, dy + 10, dz, dir, 55);
	RlocateBlock(lp, dx + 56, dy + 10, dz, dir, 56);
	RlocateBlock(lp, dx + 57, dy + 10, dz, dir, 57);
	RlocateBlock(cy, dx + 58, dy + 10, dz, dir, 58);
	RlocateBlock(qu, dx + 59, dy + 10, dz, dir, 59);
	RlocateBlock(qu, dx + 60, dy + 10, dz, dir, 60);
	RlocateBlock(qu, dx + 61, dy + 10, dz, dir, 61);
	RlocateBlock(lb, dx + 62, dy + 10, dz, dir, 62);
	RlocateBlock(lp, dx + 63, dy + 10, dz, dir, 63);
	RlocateBlock(lp, dx + 64, dy + 10, dz, dir, 64);
	RlocateBlock(lp, dx + 65, dy + 10, dz, dir, 65);
	RlocateBlock(lp, dx + 66, dy + 10, dz, dir, 66);
	RlocateBlock(lp, dx + 67, dy + 10, dz, dir, 67);
	RlocateBlock(lp, dx + 68, dy + 10, dz, dir, 68);
	RlocateBlock(lp, dx + 69, dy + 10, dz, dir, 69);
	RlocateBlock(lp, dx + 70, dy + 10, dz, dir, 70);
	RlocateBlock(lb, dx + 71, dy + 10, dz, dir, 71);
	RlocateBlock(qu, dx + 72, dy + 10, dz, dir, 72);
	RlocateBlock(qu, dx + 73, dy + 10, dz, dir, 73);
	RlocateBlock(qu, dx + 74, dy + 10, dz, dir, 74);
	RlocateBlock(qu, dx + 75, dy + 10, dz, dir, 75);
	RlocateBlock(qu, dx + 76, dy + 10, dz, dir, 76);
	RlocateBlock(qu, dx + 77, dy + 10, dz, dir, 77);
	RlocateBlock(cy, dx + 78, dy + 10, dz, dir, 78);
	RlocateBlock(lb, dx + 79, dy + 10, dz, dir, 79);
	RlocateBlock(bi, dx + 80, dy + 10, dz, dir, 80);




	RlocateBlock(cy, dx + 53, dy + 9, dz, dir, 53);
	RlocateBlock(lp, dx + 54, dy + 9, dz, dir, 54);
	RlocateBlock(lp, dx + 55, dy + 9, dz, dir, 55);
	RlocateBlock(lp, dx + 56, dy + 9, dz, dir, 56);
	RlocateBlock(lp, dx + 57, dy + 9, dz, dir, 57);
	RlocateBlock(lb, dx + 58, dy + 9, dz, dir, 58);
	RlocateBlock(qu, dx + 59, dy + 9, dz, dir, 59);
	RlocateBlock(qu, dx + 60, dy + 9, dz, dir, 60);
	RlocateBlock(lg, dx + 61, dy + 9, dz, dir, 61);
	RlocateBlock(lp, dx + 62, dy + 9, dz, dir, 62);
	RlocateBlock(lp, dx + 63, dy + 9, dz, dir, 63);
	RlocateBlock(lp, dx + 64, dy + 9, dz, dir, 64);
	RlocateBlock(lp, dx + 65, dy + 9, dz, dir, 65);
	RlocateBlock(lp, dx + 66, dy + 9, dz, dir, 66);
	RlocateBlock(lp, dx + 67, dy + 9, dz, dir, 67);
	RlocateBlock(lp, dx + 68, dy + 9, dz, dir, 68);
	RlocateBlock(lp, dx + 69, dy + 9, dz, dir, 69);
	RlocateBlock(lp, dx + 70, dy + 9, dz, dir, 70);
	RlocateBlock(bi, dx + 71, dy + 9, dz, dir, 71);
	RlocateBlock(qu, dx + 72, dy + 9, dz, dir, 72);
	RlocateBlock(qu, dx + 73, dy + 9, dz, dir, 73);
	RlocateBlock(qu, dx + 74, dy + 9, dz, dir, 74);
	RlocateBlock(qu, dx + 75, dy + 9, dz, dir, 75);
	RlocateBlock(lb, dx + 76, dy + 9, dz, dir, 76);
	RlocateBlock(lp, dx + 77, dy + 9, dz, dir, 77);
	RlocateBlock(lp, dx + 78, dy + 9, dz, dir, 78);
	RlocateBlock(cy, dx + 79, dy + 9, dz, dir, 79);



	RlocateBlock(bi, dx + 52, dy + 8, dz, dir, 52);
	RlocateBlock(lp, dx + 53, dy + 8, dz, dir, 53);
	RlocateBlock(lp, dx + 54, dy + 8, dz, dir, 54);
	RlocateBlock(lp, dx + 55, dy + 8, dz, dir, 55);
	RlocateBlock(lp, dx + 56, dy + 8, dz, dir, 56);
	RlocateBlock(lp, dx + 57, dy + 8, dz, dir, 57);
	RlocateBlock(qu, dx + 58, dy + 8, dz, dir, 58);
	RlocateBlock(qu, dx + 59, dy + 8, dz, dir, 59);
	RlocateBlock(bi, dx + 60, dy + 8, dz, dir, 60);
	RlocateBlock(cy, dx + 61, dy + 8, dz, dir, 61);
	RlocateBlock(lp, dx + 62, dy + 8, dz, dir, 62);
	RlocateBlock(lp, dx + 63, dy + 8, dz, dir, 63);
	RlocateBlock(lp, dx + 64, dy + 8, dz, dir, 64);
	RlocateBlock(lb, dx + 65, dy + 8, dz, dir, 65);
	RlocateBlock(lp, dx + 66, dy + 8, dz, dir, 66);
	RlocateBlock(lp, dx + 67, dy + 8, dz, dir, 67);
	RlocateBlock(lp, dx + 68, dy + 8, dz, dir, 68);
	RlocateBlock(lp, dx + 69, dy + 8, dz, dir, 69);
	RlocateBlock(lp, dx + 70, dy + 8, dz, dir, 70);
	RlocateBlock(bi, dx + 71, dy + 8, dz, dir, 71);
	RlocateBlock(qu, dx + 72, dy + 8, dz, dir, 72);
	RlocateBlock(qu, dx + 73, dy + 8, dz, dir, 73);
	RlocateBlock(lb, dx + 74, dy + 8, dz, dir, 74);
	RlocateBlock(lp, dx + 75, dy + 8, dz, dir, 75);
	RlocateBlock(lp, dx + 76, dy + 8, dz, dir, 76);
	RlocateBlock(lp, dx + 77, dy + 8, dz, dir, 77);
	RlocateBlock(lp, dx + 78, dy + 8, dz, dir, 78);


	RlocateBlock(lb, dx + 52, dy + 7, dz, dir, 52);
	RlocateBlock(lp, dx + 53, dy + 7, dz, dir, 53);
	RlocateBlock(lp, dx + 54, dy + 7, dz, dir, 54);
	RlocateBlock(lp, dx + 55, dy + 7, dz, dir, 55);
	RlocateBlock(lp, dx + 56, dy + 7, dz, dir, 56);
	RlocateBlock(lp, dx + 57, dy + 7, dz, dir, 57);
	RlocateBlock(qu, dx + 58, dy + 7, dz, dir, 58);
	RlocateBlock(bi, dx + 59, dy + 7, dz, dir, 59);
	RlocateBlock(lp, dx + 60, dy + 7, dz, dir, 60);
	RlocateBlock(lp, dx + 61, dy + 7, dz, dir, 61);
	RlocateBlock(lp, dx + 62, dy + 7, dz, dir, 62);
	RlocateBlock(lp, dx + 63, dy + 7, dz, dir, 63);
	RlocateBlock(cy, dx + 64, dy + 7, dz, dir, 64);
	RlocateBlock(qu, dx + 65, dy + 7, dz, dir, 65);
	RlocateBlock(cy, dx + 66, dy + 7, dz, dir, 66);
	RlocateBlock(lp, dx + 67, dy + 7, dz, dir, 67);
	RlocateBlock(lp, dx + 68, dy + 7, dz, dir, 68);
	RlocateBlock(lp, dx + 69, dy + 7, dz, dir, 69);
	RlocateBlock(lp, dx + 70, dy + 7, dz, dir, 70);
	RlocateBlock(cy, dx + 71, dy + 7, dz, dir, 71);
	RlocateBlock(cy, dx + 72, dy + 7, dz, dir, 72);
	RlocateBlock(lp, dx + 73, dy + 7, dz, dir, 73);
	RlocateBlock(lp, dx + 74, dy + 7, dz, dir, 74);
	RlocateBlock(lp, dx + 75, dy + 7, dz, dir, 75);
	RlocateBlock(lp, dx + 76, dy + 7, dz, dir, 76);
	RlocateBlock(cy, dx + 77, dy + 7, dz, dir, 77);
	RlocateBlock(bi, dx + 78, dy + 7, dz, dir, 78);



	RlocateBlock(lb, dx + 52, dy + 6, dz, dir, 52);
	RlocateBlock(lp, dx + 53, dy + 6, dz, dir, 53);
	RlocateBlock(lp, dx + 54, dy + 6, dz, dir, 54);
	RlocateBlock(lp, dx + 55, dy + 6, dz, dir, 55);
	RlocateBlock(lp, dx + 56, dy + 6, dz, dir, 56);
	RlocateBlock(lp, dx + 57, dy + 6, dz, dir, 57);
	RlocateBlock(lb, dx + 58, dy + 6, dz, dir, 58);
	RlocateBlock(lp, dx + 59, dy + 6, dz, dir, 59);
	RlocateBlock(lp, dx + 60, dy + 6, dz, dir, 60);
	RlocateBlock(lp, dx + 61, dy + 6, dz, dir, 61);
	RlocateBlock(lp, dx + 62, dy + 6, dz, dir, 62);
	RlocateBlock(lp, dx + 63, dy + 6, dz, dir, 63);
	RlocateBlock(bi, dx + 64, dy + 6, dz, dir, 64);
	RlocateBlock(qu, dx + 65, dy + 6, dz, dir, 65);
	RlocateBlock(cy, dx + 66, dy + 6, dz, dir, 66);
	RlocateBlock(lb, dx + 67, dy + 6, dz, dir, 67);
	RlocateBlock(lp, dx + 68, dy + 6, dz, dir, 68);
	RlocateBlock(lp, dx + 69, dy + 6, dz, dir, 69);
	RlocateBlock(lp, dx + 70, dy + 6, dz, dir, 70);
	RlocateBlock(lp, dx + 71, dy + 6, dz, dir, 71);
	RlocateBlock(lp, dx + 72, dy + 6, dz, dir, 72);
	RlocateBlock(lp, dx + 73, dy + 6, dz, dir, 73);
	RlocateBlock(lp, dx + 74, dy + 6, dz, dir, 74);
	RlocateBlock(lp, dx + 75, dy + 6, dz, dir, 75);
	RlocateBlock(lp, dx + 76, dy + 6, dz, dir, 76);
	RlocateBlock(cy, dx + 77, dy + 6, dz, dir, 77);
	RlocateBlock(bi, dx + 78, dy + 6, dz, dir, 78);



	RlocateBlock(lb, dx + 52, dy + 5, dz, dir, 52);
	RlocateBlock(lp, dx + 53, dy + 5, dz, dir, 53);
	RlocateBlock(lp, dx + 54, dy + 5, dz, dir, 54);
	RlocateBlock(lp, dx + 55, dy + 5, dz, dir, 55);
	RlocateBlock(lp, dx + 56, dy + 5, dz, dir, 56);
	RlocateBlock(lp, dx + 57, dy + 5, dz, dir, 57);
	RlocateBlock(lp, dx + 58, dy + 5, dz, dir, 58);
	RlocateBlock(lp, dx + 59, dy + 5, dz, dir, 59);
	RlocateBlock(lp, dx + 60, dy + 5, dz, dir, 60);
	RlocateBlock(lp, dx + 61, dy + 5, dz, dir, 61);
	RlocateBlock(lp, dx + 62, dy + 5, dz, dir, 62);
	RlocateBlock(lb, dx + 63, dy + 5, dz, dir, 63);
	RlocateBlock(qu, dx + 64, dy + 5, dz, dir, 64);
	RlocateBlock(qu, dx + 65, dy + 5, dz, dir, 65);
	RlocateBlock(qu, dx + 66, dy + 5, dz, dir, 66);
	RlocateBlock(cy, dx + 67, dy + 5, dz, dir, 67);
	RlocateBlock(lp, dx + 68, dy + 5, dz, dir, 68);
	RlocateBlock(lp, dx + 69, dy + 5, dz, dir, 69);
	RlocateBlock(lp, dx + 70, dy + 5, dz, dir, 70);
	RlocateBlock(lp, dx + 71, dy + 5, dz, dir, 71);
	RlocateBlock(lp, dx + 72, dy + 5, dz, dir, 72);
	RlocateBlock(lp, dx + 73, dy + 5, dz, dir, 73);
	RlocateBlock(lp, dx + 74, dy + 5, dz, dir, 74);
	RlocateBlock(lp, dx + 75, dy + 5, dz, dir, 75);
	RlocateBlock(lb, dx + 76, dy + 5, dz, dir, 76);



	RlocateBlock(lb, dx + 52, dy + 4, dz, dir, 52);
	RlocateBlock(lp, dx + 53, dy + 4, dz, dir, 53);
	RlocateBlock(lp, dx + 54, dy + 4, dz, dir, 54);
	RlocateBlock(lp, dx + 55, dy + 4, dz, dir, 55);
	RlocateBlock(lp, dx + 56, dy + 4, dz, dir, 56);
	RlocateBlock(lp, dx + 57, dy + 4, dz, dir, 57);
	RlocateBlock(lp, dx + 58, dy + 4, dz, dir, 58);
	RlocateBlock(lp, dx + 59, dy + 4, dz, dir, 59);
	RlocateBlock(lp, dx + 60, dy + 4, dz, dir, 60);
	RlocateBlock(lp, dx + 61, dy + 4, dz, dir, 61);
	RlocateBlock(lb, dx + 62, dy + 4, dz, dir, 62);
	RlocateBlock(qu, dx + 63, dy + 4, dz, dir, 63);
	RlocateBlock(qu, dx + 64, dy + 4, dz, dir, 64);
	RlocateBlock(qu, dx + 65, dy + 4, dz, dir, 65);
	RlocateBlock(qu, dx + 66, dy + 4, dz, dir, 66);
	RlocateBlock(lg, dx + 67, dy + 4, dz, dir, 67);
	RlocateBlock(lp, dx + 68, dy + 4, dz, dir, 68);
	RlocateBlock(lp, dx + 69, dy + 4, dz, dir, 69);
	RlocateBlock(lp, dx + 70, dy + 4, dz, dir, 70);
	RlocateBlock(lp, dx + 71, dy + 4, dz, dir, 71);
	RlocateBlock(lp, dx + 72, dy + 4, dz, dir, 72);
	RlocateBlock(lp, dx + 73, dy + 4, dz, dir, 73);
	RlocateBlock(lb, dx + 74, dy + 4, dz, dir, 74);
	RlocateBlock(lb, dx + 75, dy + 4, dz, dir, 75);



	RlocateBlock(lb, dx + 52, dy + 3, dz, dir, 52);
	RlocateBlock(lp, dx + 53, dy + 3, dz, dir, 53);
	RlocateBlock(lp, dx + 54, dy + 3, dz, dir, 54);
	RlocateBlock(lp, dx + 55, dy + 3, dz, dir, 55);
	RlocateBlock(lp, dx + 56, dy + 3, dz, dir, 56);
	RlocateBlock(lp, dx + 57, dy + 3, dz, dir, 57);
	RlocateBlock(lp, dx + 58, dy + 3, dz, dir, 58);
	RlocateBlock(lp, dx + 59, dy + 3, dz, dir, 59);
	RlocateBlock(lp, dx + 60, dy + 3, dz, dir, 60);
	RlocateBlock(lb, dx + 61, dy + 3, dz, dir, 61);
	RlocateBlock(qu, dx + 62, dy + 3, dz, dir, 62);
	RlocateBlock(qu, dx + 63, dy + 3, dz, dir, 63);
	RlocateBlock(qu, dx + 64, dy + 3, dz, dir, 64);
	RlocateBlock(qu, dx + 65, dy + 3, dz, dir, 65);
	RlocateBlock(qu, dx + 66, dy + 3, dz, dir, 66);
	RlocateBlock(qu, dx + 67, dy + 3, dz, dir, 67);
	RlocateBlock(bi, dx + 68, dy + 3, dz, dir, 68);
	RlocateBlock(lp, dx + 69, dy + 3, dz, dir, 69);
	RlocateBlock(lp, dx + 70, dy + 3, dz, dir, 70);
	RlocateBlock(lp, dx + 71, dy + 3, dz, dir, 71);
	RlocateBlock(lp, dx + 72, dy + 3, dz, dir, 72);
	RlocateBlock(cy, dx + 73, dy + 3, dz, dir, 73);




	RlocateBlock(lp, dx + 53, dy + 2, dz, dir, 53);
	RlocateBlock(lp, dx + 54, dy + 2, dz, dir, 54);
	RlocateBlock(lp, dx + 55, dy + 2, dz, dir, 55);
	RlocateBlock(lp, dx + 56, dy + 2, dz, dir, 56);
	RlocateBlock(lp, dx + 57, dy + 2, dz, dir, 57);
	RlocateBlock(lp, dx + 58, dy + 2, dz, dir, 58);
	RlocateBlock(lb, dx + 59, dy + 2, dz, dir, 59);
	RlocateBlock(qu, dx + 60, dy + 2, dz, dir, 60);
	RlocateBlock(qu, dx + 61, dy + 2, dz, dir, 61);
	RlocateBlock(qu, dx + 62, dy + 2, dz, dir, 62);
	RlocateBlock(qu, dx + 63, dy + 2, dz, dir, 63);
	RlocateBlock(qu, dx + 64, dy + 2, dz, dir, 64);
	RlocateBlock(qu, dx + 65, dy + 2, dz, dir, 65);
	RlocateBlock(qu, dx + 66, dy + 2, dz, dir, 66);
	RlocateBlock(qu, dx + 67, dy + 2, dz, dir, 67);
	RlocateBlock(qu, dx + 68, dy + 2, dz, dir, 68);
	RlocateBlock(lb, dx + 69, dy + 2, dz, dir, 69);
	RlocateBlock(lb, dx + 70, dy + 2, dz, dir, 70);
	RlocateBlock(lb, dx + 71, dy + 2, dz, dir, 71);
	RlocateBlock(bi, dx + 72, dy + 2, dz, dir, 72);



	RlocateBlock(lb, dx + 53, dy + 2, dz, dir, 53);
	RlocateBlock(cy, dx + 54, dy + 2, dz, dir, 54);
	RlocateBlock(lp, dx + 55, dy + 2, dz, dir, 55);
	RlocateBlock(lp, dx + 56, dy + 2, dz, dir, 56);
	RlocateBlock(lp, dx + 57, dy + 2, dz, dir, 57);
	RlocateBlock(cy, dx + 58, dy + 2, dz, dir, 58);  // U자 끝.


}