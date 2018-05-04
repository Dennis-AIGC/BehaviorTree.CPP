#ifndef DECORATOR_SUBTREE_NODE_H
#define DECORATOR_SUBTREE_NODE_H

#include "behavior_tree_core/decorator_node.h"

namespace BT
{
class DecoratorSubtreeNode : public DecoratorNode
{
  public:
    // Constructor
    DecoratorSubtreeNode(std::string name) : DecoratorNode(name)
    {
    }

    virtual ~DecoratorSubtreeNode() = default;

  private:
    virtual BT::NodeStatus tick()
    {
        NodeStatus prev_status = status();
        if ( prev_status== BT::IDLE || prev_status == BT::HALTED)
        {
            setStatus(BT::RUNNING);
        }
        auto status = child_node_->executeTick();
        setStatus(status);
        return status;
    }
};

}

#endif   // DECORATOR_SUBTREE_NODE_H
