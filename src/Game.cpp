//
//  Game.cpp
//  sa2k
//
//  Created by kam on 6.8.2024.
//

#include <imgui-SFML.h>
#include <imgui.h>
#include "Game.hpp"

Game::Game()
    : m_window {{ 1920u, 1080u }, "SA2K" }
{
}

auto Game::run() -> void {
    if (!ImGui::SFML::Init(m_window))
        return;

    sf::Clock clock;
    sf::Time time_since_last_update;
    sf::Time time_per_frame = sf::seconds(1.f / 60.f);
    while (m_window.isOpen()) {
        process_events();
        time_since_last_update += clock.restart();
        while (time_since_last_update > time_per_frame) {
            time_since_last_update -= time_per_frame;
            process_events();
            update(time_per_frame);
        }
        draw();
    }

    ImGui::SFML::Shutdown();
}

auto Game::process_events() -> void {
    for (auto event = sf::Event{}; m_window.pollEvent(event);)
    {
        ImGui::SFML::ProcessEvent(m_window, event);

        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
    }
}

auto Game::update(sf::Time dt) -> void {
    ImGui::SFML::Update(m_window, dt);
}

auto Game::draw() -> void {
    ImGui::Begin("Hello, world!");
    ImGui::Button("Look at this pretty button");
    ImGui::End();

    m_window.clear();
    ImGui::SFML::Render(m_window);
    m_window.display();
}
