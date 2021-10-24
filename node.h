#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include <memory>

class Node {
public:
    Node(const std::string& tmp_name);

    void AddChild(const std::shared_ptr<Node>& child);
    void RemoveChild(const std::string& name);
    void SetParent(const std::shared_ptr<Node>& new_parent);
    std::weak_ptr<Node> GetParent() const;
    unsigned CountAllChildren() const;

private:
    std::string name {};
    std::weak_ptr<Node> parent {};
    std::vector<std::shared_ptr<Node>> children {};
};

using NodePtr = std::shared_ptr<Node>;


#endif // NODE_H
