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

class Game {
public:
                        Game();
    void                run();
    
private:
    void                events();
    void                update(sf::Time dt);
    void                draw();
    void                input(sf::Keyboard::Key key, bool isPressed);
    
    sf::RenderWindow    mWindow;
    sf::Image           mIcon;
    sf::Time            mFdt;
    TextureManager      mTextureManager;
    
    // WIP stuff that is here for now
    sf::Sprite          mCharacterSprite;
    sf::Texture         mCharacterTexture;
    f32                 mPlayerSpeed;
    bool                mMovingLeft;
    bool                mMovingRight;
};

#endif /* game_hpp */
