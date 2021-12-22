#include <SFML/Graphics.hpp>
#include <iostream> 

using namespace sf;

int main() {

	RenderWindow window(sf::VideoMode(1640, 1480), "MyTragicGame");

	Texture herotexture;
	herotexture.loadFromFile("images/myhero.png");

	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(0, 0, 32, 32));
	herosprite.setPosition(250, 250);

	float CurrentFrame = 0;//������ ������� ����
	Clock clock;

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		///////////////////////////////////////////���������� ���������� � ���������////////////////////////////////////////////////////////////////////////
		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) { //���� ������ ������� ������� ����� ��� ���� ����� �
			CurrentFrame += 0.008 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 10) CurrentFrame -= 10; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
			herosprite.setTextureRect(IntRect(32 * (1 + int(CurrentFrame)), 64, -32, 32)); //���������� �� ����������� �.
			herosprite.move(-0.08 * time, 0);//���������� ���� �������� ��������� �����
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
			CurrentFrame += 0.008 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 10) CurrentFrame -= 10; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
			herosprite.setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32)); //���������� �� ����������� �.

			herosprite.move(0.08 * time, 0);//���������� ���� �������� ��������� ������
		}

		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
			CurrentFrame += 0.008 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 10) CurrentFrame -= 10; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
			herosprite.setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32)); //���������� �� ����������� �.
			herosprite.move(0, -0.08 * time);//���������� ���� �������� ��������� �����
		}

		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
			CurrentFrame += 0.008 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 10) CurrentFrame -= 10; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
			herosprite.setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32)); //���������� �� ����������� �.
			herosprite.move(0, 0.08 * time);//���������� ���� �������� ��������� ����
		}



		window.clear();
		window.draw(herosprite);
		window.display();
	}

	return 0;
}