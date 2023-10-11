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
    mWindow{sf::VideoMode(800, 600), "SFML window"},
    mIcon{},
    mCharacterTexture{},
    mCharacterSprite{},
    mTextureManager{}
{
    if (!mIcon.loadFromFile(resourcePath() / "icon.png"))
        return EXIT_FAILURE;
    
    mTextureManager.load(0, resourcePath() / "character.png");
    
    mWindow.setIcon(mIcon.getSize().x, mIcon.getSize().y, mIcon.getPixelsPtr());
    mCharacterSprite.setTexture(mTextureManager.get(0));
    mCharacterSprite.setPosition(100.f, 100.f);
    mFdt = sf::seconds(1.f / 60.f);
    mPlayerSpeed = 50.f;
    
    mMovingLeft = false;
    mMovingRight = false;
}

void Game::run() {
    
    sf::Clock clock;
    sf::Time dt = sf::Time::Zero;
    
    // Start the game loop
    while (mWindow.isOpen())
    {
        events();
        
        // Process updates every 1/60 seconds
        dt += clock.restart();
        while (dt > mFdt) {
            dt -= mFdt;
            
            events();
            update(mFdt);
        }

        // Clear screen
        mWindow.clear();

        draw();

        // Update the window
        mWindow.display();
    }
}

void Game::events() {
    // Process events
    for (sf::Event event; mWindow.pollEvent(event);)
    {
        switch (event.type) {
            // Close window: exit
            case sf::Event::Closed:
                mWindow.close();
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
    if (mMovingLeft)
        movement.x -= mPlayerSpeed;
    if (mMovingRight)
        movement.x += mPlayerSpeed;
    
    mCharacterSprite.move(movement * dt.asSeconds());
}

void Game::draw() {
    mWindow.draw(mCharacterSprite);
}

void Game::input(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::A)
        mMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        mMovingRight = isPressed;
}
