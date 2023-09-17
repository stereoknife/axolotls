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
    window{sf::VideoMode(800, 600), "SFML window"},
    icon{}
{
    if (!icon.loadFromFile(resourcePath() / "icon.png"))
    {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    fdt = sf::seconds(1.f / 60.f);
}

void Game::run() {
    
    sf::Clock clock;
    sf::Time dt = sf::Time::Zero;
    
    // Start the game loop
    while (window.isOpen())
    {
        input();
        
        // Process updates every 1/60 seconds
        dt += clock.restart();
        while (dt > fdt) {
            dt -= fdt;
            
            input();
            update();
        }

        // Clear screen
        window.clear();

        draw();

        // Update the window
        window.display();
    }
}

void Game::input() {
    // Process events
    for (sf::Event event; window.pollEvent(event);)
    {
        // Close window: exit
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }

        // Escape pressed: exit
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            window.close();
        }
    }
}

void Game::update() {
    
}

void Game::draw() {
    
}
