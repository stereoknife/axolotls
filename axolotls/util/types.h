//
//  types.h
//  axolotls
//
//  Created by kam on 17.9.2023.
//  Copyright © 2023 kam. All rights reserved.
//

#ifndef types_h
#define types_h

#include <stdint.h>
#include "resource_manager.hpp"

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using s8 = int8_t;
using s16 = int16_t;
using s32 = int32_t;
using s64 = int64_t;

using f32 = float;
using f64 = double;

using vec2 = sf::Vector2f;
using vec3 = sf::Vector3f;

using TextureManager = ResourceManager<sf::Texture, u32>;
using ImageManager = ResourceManager<sf::Image, u32>;

#endif /* types_h */
