//
// Created by kam on 6.8.2024.
//

#ifndef AXOLOTLS_RESOURCEMANAGER_H
#define AXOLOTLS_RESOURCEMANAGER_H

#include <unordered_map>
#include <SFML/Graphics.hpp>

template <typename Resource, typename Identifier>
class ResourceManager {
public:
    auto load(Identifier id, const std::string& filename) -> void;

    template <typename Parameter>
    auto load(Identifier id, const std::string& filename, const Parameter& parameter) -> void;

    auto get(Identifier id) -> Resource&;
    auto get(Identifier id) const -> const Resource&;

private:
    std::unordered_map<Identifier, std::unique_ptr<Resource>> m_resource_map;
};


#endif //AXOLOTLS_RESOURCEMANAGER_H
