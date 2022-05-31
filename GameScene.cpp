#include "GameScene.h"
#include "Player.h"
#include "console.h"
#include "Item.h"
#include "Monster.h"

GameScene::GameScene()
	: player(nullptr)
	, currentObjects{}
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			if (y == MAX_Y - 1)
			{
				map[y][x] = BLOCK_TYPE::FLOOR;
				continue;
			}

			map[y][x] = BLOCK_TYPE::EMPTY;
		}
	}

	POSITION pos = { MAX_X - 2, MAX_Y / 2 - 1 };
	monster = new Monster(pos);
	player = new Player({ PLAYER_X, MAX_Y / 2 });
	currentObjects.push_back(monster);
	currentObjects.push_back(player);
}

void GameScene::Update()
{
	if (isRelease) return;

	if (updateTime % 15 == 0)
	{
		Item* item = new Item({MAX_X, rand() % MAX_Y },
			(ITEM_TYPE)(rand() % (int)ITEM_TYPE::COUNT));
		currentObjects.push_back(item);

		GenerateColumn(currentObjects);
	}

	POSITION pos = { MAX_X - 2, MAX_Y / 2 - 1 };

	map[pos.y + 1][pos.x] = BLOCK_TYPE::MONSTER;

	for (int i = 0; i < currentObjects.size(); i++)
	{
		if (!currentObjects[i])continue;
		if (currentObjects.empty() || i >= currentObjects.size())continue;

		POSITION pos = currentObjects[i]->GetPosition();
		currentObjects[i]->Update(map);

		if (isRelease || currentObjects.empty() || i >= currentObjects.size())
		{
			return;
		}

		if (IN_SCREEN(pos.x, pos.y))
			map[pos.y][pos.x] = BLOCK_TYPE::EMPTY;

		pos = currentObjects[i]->GetPosition();

		if (IN_SCREEN(pos.x, pos.y))
			map[pos.y][pos.x] = currentObjects[i]->GetObjectType();
	}

	DeleteObject();
	Draw();

	updateTime++;
}

void GameScene::ReleaseScene()
{
	isRelease = true;
	int index = 0;

	while (!currentObjects.empty())
	{
		delete currentObjects[0];
		currentObjects[0] = nullptr;
		currentObjects.erase(currentObjects.begin());
	}
}

void GameScene::Draw()
{
	if (isRelease) return;

	gotoxy(OFFSET_X, OFFSET_Y - 3);
	cout << "| HIGHSCORE: " << Player::GetHighScore() << endl;
	gotoxy(OFFSET_X, OFFSET_Y - 2);
	cout << "| SCORE: " << Player::GetScore() << endl;

	gotoxy(OFFSET_X, OFFSET_Y);

	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			switch (map[y][x])
			{
			case BLOCK_TYPE::EMPTY:
				setcolor(WHITE, SKYBLUE);
				if (x % 2 == 0)
				{
					if (y % 2 == 0)
						cout << "* ";
					else
						cout << " *";
				}
				else
					cout << "  ";
				break;

			case BLOCK_TYPE::FLOOR:
				setcolor(BLACK, SKYBLUE);
				cout << "��";
				break;

			default:
				(WHITE, SKYBLUE);
				cout << "  ";
			}
		}
		cout << endl;
		gotoxy(OFFSET_X, OFFSET_Y + y);
	}

	for (int i = 0; i < currentObjects.size(); i++)
	{
		currentObjects[i]->Render(OFFSET_X, OFFSET_Y);
	}
}

void GameScene::DeleteObject()
{
	if (isRelease)return;

	for (int i = 0; i < currentObjects.size(); i++)
	{
		if (isRelease || i < 0)return;

		Object* obj = currentObjects[i];

		if (obj)
		{
			if (!obj->GetIsDead()) continue;

			currentObjects.erase(currentObjects.begin() + i);
			delete obj;
			obj = nullptr;
			i--;
		}
	}
}