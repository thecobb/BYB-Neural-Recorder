#include "Game.h"
#include "MainView.h"
#include "widgets/TextureGL.h"
#include <SDL.h>
#include <iostream>

namespace BackyardBrains {

Game::Game() : _fileRec(_manager) {
	std::cout << "Loading Resources...\n";
	loadResources();
	std::cout << "Creating Window...\n";

	addWindow(new MainView(_manager, _fileRec));
	createWindow(800,600);
	setWindowTitle("BYB Spike Recorder");

	std::cout << "Starting GUI...\n";

}

Game::~Game() {
	
}


void Game::loadResources() {
	Widgets::TextureGL::load("data/pause.png");
	Widgets::TextureGL::load("data/pausehigh.png");
	Widgets::TextureGL::load("data/play.png");
	Widgets::TextureGL::load("data/playhigh.png");

	Widgets::TextureGL::load("data/forward.png");
	Widgets::TextureGL::load("data/forwardhigh.png");
	Widgets::TextureGL::load("data/backward.png");
	Widgets::TextureGL::load("data/backwardhigh.png");

	Widgets::TextureGL::load("data/config.png");
	Widgets::TextureGL::load("data/confighigh.png");
	Widgets::TextureGL::load("data/thresh.png");
	Widgets::TextureGL::load("data/threshhigh.png");
	Widgets::TextureGL::load("data/rec.png");
	Widgets::TextureGL::load("data/rechigh.png");
	Widgets::TextureGL::load("data/file.png");
	Widgets::TextureGL::load("data/filehigh.png");
	Widgets::TextureGL::load("data/analysis.png");
	Widgets::TextureGL::load("data/analysishigh.png");

	Widgets::TextureGL::load("data/save.png");
	Widgets::TextureGL::load("data/savehigh.png");

	Widgets::TextureGL::load("data/pin.png");
	Widgets::TextureGL::load("data/threshpin.png");
	Widgets::TextureGL::load("data/dropdown.png");

	Widgets::TextureGL::load("data/ckboxon.png");
	Widgets::TextureGL::load("data/ckboxoff.png");
}

void Game::advance() {
	static uint32_t t = 0; // TODO make this cleaner
	uint32_t newt = SDL_GetTicks();
	_manager.advance((newt-t)*_manager.sampleRate()/1000);
	_fileRec.advance();

	t = newt;
}



} // namespace BackyardBrains
