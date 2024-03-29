#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextComponent.h"
#include "Scene.h"

#include "GameObject.h"
#include "TextureComponent.h"
#include "FPSComponent.h"
#include <chrono>

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto go = std::make_shared<dae::GameObject>();
	go->AddComponent<dae::TextureComponent>();
	go->GetComponent<dae::TextureComponent>()->SetTexture("background.tga");
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	go->AddComponent<dae::TextureComponent>();
	go->GetComponent<dae::TextureComponent>()->SetTexture("logo.tga");
	go->SetPosition(216, 180);
	scene.Add(go);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	go = std::make_shared<dae::GameObject>();
	go->AddComponent<dae::TextComponent>();
	auto textComponent = go->GetComponent<dae::TextComponent>();
	textComponent->SetText("Programming 4 Assignment");
	textComponent->SetFont(font);
	go->SetPosition(120, 0);
	scene.Add(go);

	font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 28);
	go = std::make_shared<dae::GameObject>();
	auto fpsTextComponent = go->AddComponent<dae::TextComponent>();
	go->AddComponent<dae::FPSComponent>();
	fpsTextComponent->SetText("0");
	fpsTextComponent->SetFont(font);
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	auto daeImg = go->AddComponent<dae::TextureComponent>();
	daeImg->SetTexture("logo.tga");
	go->SetPosition(400, 300);
	scene.Add(go);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}