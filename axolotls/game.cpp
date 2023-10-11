//
//  game.cpp
//  axolotls
//
//  Created by kam on 17.9.2023.
//  Copyright © 2023 kam. All rights reserved.
//

#include "game.hpp"
#include "ResourcePath.hpp"

Game::Game() :
    m_window{sf::VideoMode(800, 600), "SFML window"},
    m_scene{},
    m_texture_manager{},
    m_image_manager{}
{
    m_image_manager.load(0, resourcePath() / "icon.png");
    sf::Image icon = m_image_manager.get(0);
    m_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    m_fdt = sf::seconds(1.f / 60.f);
    m_player_speed = 50.f;
    
    m_moving_left = false;
    m_moving_right = false;
}

void Game::run() {
    
    sf::Clock clock;
    sf::Time dt = sf::Time::Zero;
    
    // Start the game loop
    while (m_window.isOpen())
    {
        events();
        
        // Process updates every 1/60 seconds
        dt += clock.restart();
        while (dt > m_fdt) {
            dt -= m_fdt;
            
            events();
            update(m_fdt);
        }

        // Clear screen
        m_window.clear();

        draw();

        // Update the window
        m_window.display();
    }
}

void Game::init() {
    m_texture_manager.load(0, resourcePath() / "character.png");
    
    auto character = std::make_unique<Character>(m_texture_manager);
    character->setPosition(100, 100);
    m_scene.attach_child(std::move(character));
}

void Game::events() {
    // Process events
    for (sf::Event event; m_window.pollEvent(event);)
    {
        switch (event.type) {
            // Close window: exit
            case sf::Event::Closed:
                m_window.close();
                break;
                
            case sf::Event::KeyPressed:
                input(event.key.code, true);
                break;
                
            case sf::Event::KeyReleased:
                input(event.key.code, false);
                break;
                
            default:
                break;
        }
    }
}

void Game::update(sf::Time dt) {
    sf::Vector2f movement(0.f, 0.f);
    if (m_moving_left)
        movement.x -= m_player_speed;
    if (m_moving_right)
        movement.x += m_player_speed;
    
    //m_character_sprite.move(movement * dt.asSeconds());
}

void Game::draw() {
    m_window.draw(m_scene);
}

void Game::input(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::A)
        m_moving_left = isPressed;
    else if (key == sf::Keyboard::D)
        m_moving_right = isPressed;
}
