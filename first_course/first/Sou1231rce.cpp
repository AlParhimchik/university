#include <SFML/Graphics.hpp>

using namespace sf;

float offsetX = 0, offsetY = 0;

const int H = 17;
const int W = 150;


String TileMap[H] = {       //�� ������ �������� ���������� ������������ ��������, ��� ������� ������ ����� 
	"0PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP0",
	"0kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk0",
	"0k      w                                                             k              w                                                 w            k0",
	"0kkkkk              w                                  w            kkkkk  w                         w        w            w                        k0",
	"0kk                                    w                          kkk   k               kkkkkkkk                                     kkkkkkk        k0",
	"0kkkkkkk        kkkk                            kkkkkkkkk                           w               kkkkkkk                rr                       k0",
	"0k    k                             kkkkkkk                        kk           kkk            w                  w        rr                       k0",
	"0k    kkkkkk                      kk                            kkk           kk                                            rrrr                    k0",
	"0k                           k                              kkkk   k        kk     w         kkkk     w                                       kkkkkkk0",
	"0kkk      w                  kk                                     kkkk                                                                   kkkk     k0",
	"0k k           kk    kkkkk  kkkk                                                                                                            k       k0",
	"0k kkkk             kk                 t0                               rrr          w                        r                        r kkk        k0",
	"0k              w                 k    00              t0             rrrrrr                    rrr          rrr         rr           rrr           k0",
	"0k                               kkk   00              00         rrrr     rr                 rrrrrr        rrrrr r      rr                         k0",
	"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP1PPPPP",
	"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
	"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP1PPPP",
};

class PLAYER {

public:

	float dx, dy;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;


	PLAYER(Texture &image)   //�������� �������� � ������ �� ������������
	{
		sprite.setTexture(image);  //�������� � ������ ������
		rect = FloatRect(80, 190, 16, 16);  //��������� ���������� x, y, ������ � ������ 

		dx = dy = 0.1;
		currentFrame = 0;   //������� ����
	}

	void update(float time)  //�������, ������� ��������������� "����" � ����, ��������� ������������ �������, �� �������� ��� ������� �������
	{
		rect.left += dx * time;
		Collision(0);

		if (!onGround) dy = dy + 0.0005*time;
		rect.top += dy*time;
		onGround = false;
		Collision(1);

		currentFrame += time * 0.005;  //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������
		if (currentFrame > 3) currentFrame -= 3;  //���� ��������� ������ ����, ���������� �������� �� ��������� 

		if (dx>0) sprite.setTextureRect(IntRect(100 + 28 * int(currentFrame), 144, 16, 16));  //���������� �� ����������� � ������, ��� ������ ������� ��� �����
		if (dx<0) sprite.setTextureRect(IntRect(100 + 28 * int(currentFrame) + 16, 144, -16, 16));  //���������� �� ����������� � �����, ��� ������ ������� ��� �����

		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);  //����� ������� ���������
		dx = 0;
	}

	void Collision(int num)   //������� ������������ ��������� � ������ 
	{
		for (int i = rect.top / 16; i<(rect.top + rect.height) / 16; i++) //���������� �� ���� �����
			for (int j = rect.left / 16; j<(rect.left + rect.width) / 16; j++) //��������� �� ���� ����� �� 16, ��� ����� �������� ����� ���������, � ������� �������� �������������. (�� ������ ������� 16*16, ������� ����� ������������ ������ �� ���������� ���������). � <(rect.left+rect.width)/16 - ������� ����������� ��������� �� ����. �� ���� ���������� ������ ������� ��������, ������� ������������� � ����������. ����� ������� ���� � ����� ����� ������� �� ����, ������� �� �� ������ �������� (���������������� � ������), �� ������� �������� (���������������� � ������)
			{
				if ((TileMap[i][j] == 'P') || (TileMap[i][j] == 'k') || (TileMap[i][j] == '0') || (TileMap[i][j] == 'r') || (TileMap[i][j] == 't')) //// ������ ��������� ��������� �� ������� ������� �� ���� ���������
				{
					if (dy>0 && num == 1)
					{
						rect.top = i * 16 - rect.height;  dy = 0;   onGround = true;
					}
					if (dy<0 && num == 1)
					{
						rect.top = i * 16 + 16;   dy = 0;
					}
					if (dx>0 && num == 0)
					{
						rect.left = j * 16 - rect.width;
					}
					if (dx<0 && num == 0)
					{
						rect.left = j * 16 + 16;
					}
				}

				if (TileMap[i][j] == 'w') { TileMap[i][j] = ' '; }  //�������� �����, ��� ������ ����� ��� ���������� 
			}
	}
};

class ENEMY
{
public:
	float dx, dy;
	FloatRect rect;
	Sprite sprite;
	float currentFrame;
	bool life;

	void set(Texture &image, int x, int y)
	{
		sprite.setTexture(image);
		rect = FloatRect(x, y, 16, 16);

		dx = 0.05;
		currentFrame = 0;
		life = true;
	}

	void update(float time)
	{
		rect.left += dx * time;
		Collision();

		currentFrame += time * 0.005;
		if (currentFrame > 2) currentFrame -= 2;
		sprite.setTextureRect(IntRect(18 * int(currentFrame), 0, 16, 16));
		if (!life) sprite.setTextureRect(IntRect(58, 0, 16, 16));

		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
	}

	void Collision()
	{
		for (int i = rect.top / 16; i<(rect.top + rect.height) / 16; i++)
			for (int j = rect.left / 16; j<(rect.left + rect.width) / 16; j++)
				if ((TileMap[i][j] == 'P') || (TileMap[i][j] == '0'))
				{
					if (dx>0)
					{
						rect.left = j * 16 - rect.width; dx *= -1;
					}
					else if (dx<0)
					{
						rect.left = j * 16 + 16;  dx *= -1;
					}
				}
	}
};

int main()
{
	RenderWindow window(VideoMode(450, 250), "Kyrsovaia!"); //����� ���� ����

	Texture tileSet;
	tileSet.loadFromFile("Mario_Tileset.png");

	PLAYER Mario(tileSet);
	ENEMY  enemy;
	enemy.set(tileSet, 48 * 16, 13 * 16);

	Sprite tile(tileSet);  //������� ������ Sprite, ������ ������ ��������� ��� ��������� ����� 

	Clock clock;    //���������� �������

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();  //��������� ����� � �������������
		clock.restart();   //������������� ����� 

		time = time / 500;  //�������� ����

		if (time > 20) time = 20;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))    Mario.dx = -0.1;  //���� �������� �����, �� ��������� ���������� �� ��� � �� -0.1
		if (Keyboard::isKeyPressed(Keyboard::Right))    Mario.dx = 0.1;
		if (Keyboard::isKeyPressed(Keyboard::Up))	if (Mario.onGround) { Mario.dy = -0.27; Mario.onGround = false; } //��� ������� ������� ����� ����� ����������� "����������", ������� �������� ������ ����

		Mario.update(time);
		enemy.update(time);


		if (Mario.rect.intersects(enemy.rect))  //������� �������������� � ������
		{
			if (enemy.life) {
				if (Mario.dy>0) { enemy.dx = 0; Mario.dy = -0.2; enemy.life = false; }
				else Mario.sprite.setColor(Color::Blue);
			}
		}

		if (Mario.rect.left>200) offsetX = Mario.rect.left - 200;

		window.clear(Color(255, 255, 255));

		for (int i = 0; i<H; i++)
			for (int j = 0; j<W; j++)
			{
				if (TileMap[i][j] == 'P')  tile.setTextureRect(IntRect(143 - 16 * 3, 112, 16, 16)); //���������� �� ������������ �������� ������������ ��������
				if (TileMap[i][j] == 'k')  tile.setTextureRect(IntRect(143, 112, 16, 16));
				if (TileMap[i][j] == 'c')  tile.setTextureRect(IntRect(143 - 16, 112, 16, 16));
				if (TileMap[i][j] == 't')  tile.setTextureRect(IntRect(0, 47, 32, 95 - 47));
				if (TileMap[i][j] == 'g')  tile.setTextureRect(IntRect(0, 16 * 9 - 5, 3 * 16, 16 * 2 + 5));
				if (TileMap[i][j] == 'G')  tile.setTextureRect(IntRect(145, 222, 222 - 145, 255 - 222));
				if (TileMap[i][j] == 'd')  tile.setTextureRect(IntRect(0, 106, 74, 127 - 106));
				if (TileMap[i][j] == 'w')  tile.setTextureRect(IntRect(99, 224, 140 - 99, 255 - 224));
				if (TileMap[i][j] == 'r')  tile.setTextureRect(IntRect(143 - 32, 112, 16, 16));
				if ((TileMap[i][j] == ' ') || (TileMap[i][j] == '0')) continue;

				tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);  //����������� ����������, ��������� � �����, �.�. ������ ������� �� ��� �������
				window.draw(tile);  //����� ��������� �� �����
			};

		window.draw(Mario.sprite);
		window.draw(enemy.sprite);
		window.display();
	}
	return 0;
}
