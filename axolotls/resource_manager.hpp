//
//  resource_manager.hpp
//  axolotls
//
//  Created by kam on 11.10.2023.
//  Copyright © 2023 kam. All rights reserved.
//

#ifndef resource_manager_hpp
#define resource_manager_hpp

#include <stdio.h>
#include <unordered_map>
#include <SFML/Graphics.hpp>

template <typename Resource, typename Identifier>
class ResourceManager {
public:
    void                load(Identifier id, const std::string& filename);
    
    template <typename Param>
    void                load(Identifier id, const std::string& filename, const Param& secondParam);
    
    Resource&           get(Identifier id);
    const Resource&     get(Identifier id) const;
    
private:
    using Ptr = std::unique_ptr<Resource>;
    std::unordered_map<Identifier, Ptr> mTextureMap;
};


// Impl

template <typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::load(Identifier id, const std::string& filename) {
    auto texture = std::make_unique<sf::Texture>();
    
    if (!texture->loadFromFile(filename))
        throw std::runtime_error("ResourceManager::load - Failed to load " + filename);
    
    auto inserted = mTextureMap.insert({id, std::move(texture)});
    assert(inserted.second);
}

template <typename Resource, typename Identifier>
template <typename Param>
void ResourceManager<Resource, Identifier>::load(Identifier id, const std::string& filename, const Param& secondParam) {
    auto texture = std::make_unique<sf::Texture>();
    
    if (!texture->loadFromFile(filename, secondParam))
        throw std::runtime_error("ResourceManager::load - Failed to load " + filename);
    
    auto inserted = mTextureMap.insert({id, std::move(texture)});
    assert(inserted.second);
}

template <typename Resource, typename Identifier>
Resource& ResourceManager<Resource, Identifier>::get(Identifier id) {
    auto found = mTextureMap.find(id);
    assert(found != mTextureMap.end());
    return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceManager<Resource, Identifier>::get(Identifier id) const {
    auto found = mTextureMap.find(id);
    assert(found != mTextureMap.end());
    return *found->second;
}

#endif /* resource_manager_hpp */
