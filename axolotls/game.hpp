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
#include "types.h"
#include "resource_manager.hpp"
#include "character.hpp"

class Game {
public:
                        Game();
    void                run();
    
private:
    void                init();
    
    void                update(sf::Time dt);
    void                draw();
    
    void                events();
    void                input(sf::Keyboard::Key key, bool isPressed);
    
    sf::RenderWindow    m_window;
    sf::Time            m_fdt;
    TextureManager      m_texture_manager;
    ImageManager        m_image_manager;
    
    // WIP stuff that is here for now
    SceneNode           m_scene;
    f32                 m_player_speed;
    bool                m_moving_left;
    bool                m_moving_right;
};

#endif /* game_hpp */
