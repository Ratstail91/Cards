/* Copyright: (c) Kayne Ruse 2014
 * 
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 * 
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 * 
 * 3. This notice may not be removed or altered from any source
 * distribution.
*/
#include "poker_scene.hpp"

//-------------------------
//Public access members
//-------------------------

PokerScene::PokerScene() {
	//
}

PokerScene::~PokerScene() {
	//
}

//-------------------------
//Frame loop
//-------------------------

void PokerScene::FrameStart() {
	//
}

void PokerScene::Update(double delta) {
	//
}

void PokerScene::FrameEnd() {
	//
}

void PokerScene::Render(SDL_Surface* const screen) {
	//
}

//-------------------------
//Event handlers
//-------------------------

void PokerScene::MouseMotion(SDL_MouseMotionEvent const& motion) {
	//
}

void PokerScene::MouseButtonDown(SDL_MouseButtonEvent const& button) {
	//
}

void PokerScene::MouseButtonUp(SDL_MouseButtonEvent const& button) {
	//
}

void PokerScene::KeyDown(SDL_KeyboardEvent const& key) {
	switch(key.keysym.sym) {
		case SDLK_ESCAPE:
			QuitEvent();
			break;
	}
}

void PokerScene::KeyUp(SDL_KeyboardEvent const& key) {
	//
}
