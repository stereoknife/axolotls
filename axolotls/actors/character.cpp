//
//  character.cpp
//  axolotls
//
//  Created by kam on 11.10.2023.
//  Copyright © 2023 kam. All rights reserved.
//

#include "character.hpp"

Character::Character(TextureManager& textures) :
    m_sprite{textures.get(0)}
{
    sf::FloatRect bounds = m_sprite.getLocalBounds();
    m_sprite.setOrigin(bounds.width / 2.f, bounds.height);
}

void Character::draw_self(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(m_sprite, states);
}
