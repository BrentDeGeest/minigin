#include <SDL.h>
#include "InputManager.h"
#include <backends/imgui_impl_sdl2.h>
#include <iostream>
///////////////////
// slide 13 xinput
///////////////////

bool dae::InputManager::ProcessInput()
{

	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		if (e.type == SDL_KEYDOWN) {
			std::cout << "key pressed!\n";
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			
		}
		// etc...

		ImGui_ImplSDL2_ProcessEvent(&e);
	}

	return true;
}
