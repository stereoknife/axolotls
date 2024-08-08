//
//  Game.hpp
//  sa2k
//
//  Created by kam on 6.8.2024.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Game {
public:
         Game();
    auto run()                  -> void;

private:
    auto process_events()       -> void;
    auto update(sf::Time dt)    -> void;
    auto draw()                 -> void;

private:
    sf::RenderWindow    m_window;
};

#endif /* Game_hpp */
