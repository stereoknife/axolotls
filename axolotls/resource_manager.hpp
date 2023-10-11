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
    std::unordered_map<Identifier, Ptr> m_resource_map;
};


// Impl

template <typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::load(Identifier id, const std::string& filename) {
    auto resource = std::make_unique<Resource>();
    
    if (!resource->loadFromFile(filename))
        throw std::runtime_error("ResourceManager::load - Failed to load " + filename);
    
    auto inserted = m_resource_map.insert({id, std::move(resource)});
    assert(inserted.second);
}

template <typename Resource, typename Identifier>
template <typename Param>
void ResourceManager<Resource, Identifier>::load(Identifier id, const std::string& filename, const Param& secondParam) {
    auto resource = std::make_unique<Resource>();
    
    if (!resource->loadFromFile(filename, secondParam))
        throw std::runtime_error("ResourceManager::load - Failed to load " + filename);
    
    auto inserted = m_resource_map.insert({id, std::move(resource)});
    assert(inserted.second);
}

template <typename Resource, typename Identifier>
Resource& ResourceManager<Resource, Identifier>::get(Identifier id) {
    auto found = m_resource_map.find(id);
    assert(found != m_resource_map.end());
    return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceManager<Resource, Identifier>::get(Identifier id) const {
    auto found = m_resource_map.find(id);
    assert(found != m_resource_map.end());
    return *found->second;
}

#endif /* resource_manager_hpp */
