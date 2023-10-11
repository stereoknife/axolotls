//
//  scene_node.hpp
//  axolotls
//
//  Created by kam on 11.10.2023.
//  Copyright © 2023 kam. All rights reserved.
//

#ifndef scene_node_hpp
#define scene_node_hpp

#include <stdio.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "types.h"

// Virtual functions aren't abstract bc this way there's no need to create an empty
// derivative class to represent a scene.

class SceneNode :
    public sf::Transformable,
    public sf::Drawable,
    private sf::NonCopyable
{
public:
    using Ptr = std::unique_ptr<SceneNode>;
    
                        SceneNode();
    
    void                attach_child(Ptr child);
    Ptr                 detach_child(const SceneNode& node);
    
    void                update(sf::Time dt);
    
    sf::Transform       get_world_transform() const;
    vec2                get_world_position() const;
    
private:
            void        update_children(sf::Time dt);
    virtual void        update_self(sf::Time dt);
    
    virtual void        draw(sf::RenderTarget& target, sf::RenderStates states) const final;
    virtual void        draw_self(sf::RenderTarget& target, sf::RenderStates states) const;
    
    std::vector<Ptr>    m_children;
    SceneNode*          m_parent;
};

#endif /* scene_node_hpp */
