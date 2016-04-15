#ifndef LP_KEYBINDING_HPP
#define LP_KEYBINDING_HPP

#include <cassert>
#include <string>
#include <fstream>
#include <Thor/Input.hpp>
#include "ActionTarget.hpp"
#include "pugixml.hpp"

namespace lp
{

class KeyBinding
{
    public:
        KeyBinding(ActionMapPtr map = nullptr);
        ~KeyBinding();

        void setAction(std::string const& id, sf::Keyboard::Key key, thor::Action::ActionType type);
        void setKey(std::string const& id, sf::Keyboard::Key key);
        void setType(std::string const& id, thor::Action::ActionType type);
        sf::Keyboard::Key getKey(std::string const& id);
        thor::Action::ActionType getType(std::string const& id);

        thor::Action getActionFromId(std::string const& id);

        ActionMapPtr getMap();

        bool load(std::string const& filename);
        void save(std::string const& filename);

    protected:
        ActionMapPtr mActionMap;
        std::map<std::string,std::pair<sf::Keyboard::Key,thor::Action::ActionType>> mKeys;
};

} // namespace lp

#endif // LP_KEYBINDING_HPP
