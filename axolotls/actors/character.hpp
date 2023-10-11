//
//  character.hpp
//  axolotls
//
//  Created by kam on 11.10.2023.
//  Copyright © 2023 kam. All rights reserved.
//

#ifndef character_hpp
#define character_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "scene_node.hpp"
#include "types.h"

class Character: public SceneNode {
public:
    explicit        Character(TextureManager& textures);
    virtual void    draw_self(sf::RenderTarget& target, sf::RenderStates states) const;
    
private:
    sf::Sprite      m_sprite;
};

#endif /* character_hpp */
