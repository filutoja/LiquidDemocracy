#include "node.h"

#include <algorithm>

Node::Node(const std::string& name) : name(name){}

void Node::AddChild(const std::shared_ptr<Node>& child) {
    children.push_back(child);
}

void Node::RemoveChild(const std::string& name) {
    auto child_to_remove = std::find_if(children.begin(), children.end(), [&name](auto child){
        return child->name == name;
    });
    if(child_to_remove != children.end()) {
        children.erase(child_to_remove);
    }
}

void Node::SetParent(const std::shared_ptr<Node>& new_parent) {
   parent = new_parent;
}

std::weak_ptr<Node> Node::GetParent() const {
    return parent;
}

unsigned Node::CountAllChildren() const {
    unsigned res = parent.lock() ? 1 : 0;
    for(const auto& child : children) {
        res += child->CountAllChildren();
    }
    return res;
}
