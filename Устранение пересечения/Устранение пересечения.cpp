#include <iostream>
#include <memory>

class node
{
public:
    int m_value;
    std::shared_ptr<node> parent;
    std::weak_ptr<node> weak_parent;

    node(int value) : m_value{ value } {};
    ~node() { std::cout << "destructor called\n"; }
};

int main()
{
    {
        auto node1 = std::make_shared<node>(1);
        auto node2 = std::make_shared<node>(2);

        node1->parent = node2;
        node2->weak_parent = node1;

        node1->parent.reset();
        node2->weak_parent.reset();
    }

    return 0;
}
