//
//  game.hpp
//  axolotls
//
//  Created by kam on 17.9.2023.
//  Copyright © 2023 kam. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Game {
public:
                        Game();
    void                run();
    
private:
    void                input();
    void                update();
    void                draw();
    
    sf::RenderWindow    window;
    sf::Image           icon;
    
    sf::Time            fdt;
};

#endif /* game_hpp */
