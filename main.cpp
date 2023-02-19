#include <SFML/Graphics.hpp>
#include "settings.h"
#include "Roadobj.h"
#include "Player.h"
#include "vrag.h"
#include "Textobj.h"
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, Style::Close | Style::Titlebar);
	window.setPosition(Vector2i{ (1920 - (int)WINDOW_WIDTH) / 2,0 });
	window.setFramerateLimit(FPS);

	Roadobj Doroga, Doroga2;
	roadObjInit(Doroga, RoadStartPos, Road_File_Name, 150.f);
	roadObjInit(Doroga2, RoadStartPos2, Road_File_Name, 150.f);
	Roadobj Trava, Trava2;
	roadObjInit(Trava, GrassStartPos, Grass_File_Name, 0.f);
	roadObjInit(Trava2, GrassStartPos2, Grass_File_Name, 0.f);
	Roadobj Pesok, Pesok2;
	roadObjInit(Pesok, PesokStartPos, Pesok_File_Name, 135.f);
	roadObjInit(Pesok2, PesokStartPos2, Pesok_File_Name, 135.f);
	Player Machina;
	playerInit(Machina, MachinaStartPos, Machina_File_Name);
	Vrag Vrag, Vrag2, Vrag3, Vrag4;
	vragInit(Vrag, VragStartPos, Vrag_File_Name);
	vragInit(Vrag2, VragStartPos2, Vrag_File_Name2);
	vragInit(Vrag3, VragStartPos3, Vrag_File_Name3);
	vragInit(Vrag4, VragStartPos4, Vrag_File_Name4);
	TextObj scoreText;
	textInit (scoreText, Doroga.score);
	

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		roadObjUpdate(Trava);
		roadObjUpdate(Trava2);
		roadObjUpdate(Pesok);
		roadObjUpdate(Pesok2);
		roadObjUpdate(Doroga);
		roadObjUpdate(Doroga2);
		playerUpdate(Machina);
		vragUpdate(Vrag);
		vragUpdate(Vrag2);
		vragUpdate(Vrag3);
		vragUpdate(Vrag4);
		textUpdate(scoreText, Doroga.score);
		if (Machina.sprite.getGlobalBounds().intersects(Vrag.sprite.getGlobalBounds())) {
			SpriteSpeedY = 0.f;
			Vrag.sprite.move(0, 1000);
			Doroga.score = 0;
		}
		if (Machina.sprite.getGlobalBounds().intersects(Vrag2.sprite.getGlobalBounds())) {
			SpriteSpeedY = 0.f;
			Vrag2.sprite.move(0, 1000);
			Doroga.score = 0;
		}
		if (Machina.sprite.getGlobalBounds().intersects(Vrag3.sprite.getGlobalBounds())) {
			SpriteSpeedY = 0.f;
			Vrag3.sprite.move(0, 1000);
			Doroga.score = 0;
		}
		if (Machina.sprite.getGlobalBounds().intersects(Vrag4.sprite.getGlobalBounds())) {
			SpriteSpeedY = 0.f;
			Vrag4.sprite.move(0, 1000);
			Doroga.score = 0;
		}
		float time[]{ 0,0,0,0,0 };
		int  indexTime = rand() % 5;
		if(Machina.sprite.getPosition().x >= 110.f && Machina.sprite.getPosition().x <= 410.f){
			if (time[indexTime] <= 0) {
				Doroga.score += 0.07;
			}
		}
		if (Machina.sprite.getPosition().x < 110.f || Machina.sprite.getPosition().x > 410.f) {
			if (time[indexTime] <= 0) {
				Doroga.score += 0.02;
			}
		}
		if (Doroga.score >= 1000) {
			window.close();
		}
		RoadObjDraw(window, Trava);
		RoadObjDraw(window, Pesok);
		RoadObjDraw(window, Doroga);
		RoadObjDraw(window, Trava2);
		RoadObjDraw(window, Pesok2);
		RoadObjDraw(window, Doroga2);
		playerDraw(window, Machina);
		vragDraw(window, Vrag);
		vragDraw(window, Vrag2);
		vragDraw(window, Vrag4);
		vragDraw(window, Vrag3);
		textDraw(window, scoreText);

		window.display();
	}

	return 0;
}