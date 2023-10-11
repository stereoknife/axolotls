//
//  scene_node.cpp
//  axolotls
//
//  Created by kam on 11.10.2023.
//  Copyright © 2023 kam. All rights reserved.
//

#include "scene_node.hpp"

SceneNode::SceneNode() :
    m_children{}
{}

////////////////////////////////////////////////////////////
// Child functions
////////////////////////////////////////////////////////////

void SceneNode::attach_child(Ptr child) {
    child->m_parent = this;
    m_children.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detach_child(const SceneNode &node) {
    auto found = std::find_if(m_children.begin(), m_children.end(),
                              [&] (Ptr& p) -> bool { return p.get() == &node; });
    
    assert(found != m_children.end());
    
    Ptr result = std::move(*found);
    result->m_parent = nullptr;
    m_children.erase(found);
    return result;
}

////////////////////////////////////////////////////////////
// Update functions
////////////////////////////////////////////////////////////

void SceneNode::update(sf::Time dt) {
    update_self(dt);
    update_children(dt);
}

void SceneNode::update_self(sf::Time dt) {
    
}

void SceneNode::update_children(sf::Time dt) {
    for (Ptr& child : m_children) {
        child->update(dt);
    }
}

////////////////////////////////////////////////////////////
// Draw functions
////////////////////////////////////////////////////////////

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    
    draw_self(target, states);
    
    for (const Ptr& child : m_children) {
        child->draw(target, states);
    }
}

void SceneNode::draw_self(sf::RenderTarget &target, sf::RenderStates states) const {}

////////////////////////////////////////////////////////////
// Transform functions
////////////////////////////////////////////////////////////
sf::Transform SceneNode::get_world_transform() const {
    sf::Transform transform = sf::Transform::Identity;
    for (const SceneNode* node = this; node != nullptr; node = node->m_parent) {
        transform = node->getTransform() * transform;
    }
    return transform;
}

vec2 SceneNode::get_world_position() const {
    return get_world_transform() * vec2();
}
