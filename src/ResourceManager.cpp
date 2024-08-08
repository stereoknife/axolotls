//
// Created by kam on 6.8.2024.
//

#include <cassert>
#include "ResourceManager.h"

template <typename Resource, typename Identifier>
auto ResourceManager<Resource, Identifier>::load(Identifier id, const std::string& filename) -> void {
    std::unique_ptr<Resource> texture = std::make_unique<Resource>();
    if (!texture->loadFromFile(filename)) {
        throw std::runtime_error("TextureHolder::load - Failed to load " + filename);
    }

    auto inserted = m_resource_map.insert({id, std::move(texture)});
    assert(inserted.second);
}

template <typename Resource, typename Identifier>
template <typename Parameter>
auto ResourceManager<Resource, Identifier>::load(Identifier id, const std::string& filename, const Parameter& parameter) -> void {
    std::unique_ptr<Resource> texture = std::make_unique<Resource>();
    if (!texture->loadFromFile(filename, parameter)) {
        throw std::runtime_error("TextureHolder::load - Failed to load " + filename);
    }

    auto inserted = m_resource_map.insert({id, std::move(texture)});
    assert(inserted.second);
}

template <typename Resource, typename Identifier>
auto ResourceManager<Resource, Identifier>::get(Identifier id) -> Resource& {
    auto found = m_resource_map.find(id);
    assert(found != m_resource_map.end());
    return *found->second;
}

template <typename Resource, typename Identifier>
auto ResourceManager<Resource, Identifier>::get(Identifier id) const -> const Resource& {
    auto found = m_resource_map.find(id);
    assert(found != m_resource_map.end());
    return *found->second;
}