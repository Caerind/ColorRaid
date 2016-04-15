#include "KeyBinding.hpp"
#include <iostream>

namespace lp
{

KeyBinding::KeyBinding(ActionMapPtr map)
{
    if (map == nullptr)
    {
        mActionMap = std::make_shared<thor::ActionMap<std::string>>();
    }
    else
    {
        mActionMap = map;
    }
}

KeyBinding::~KeyBinding()
{
}

void KeyBinding::setAction(std::string const& id, sf::Keyboard::Key key, thor::Action::ActionType type)
{
    mKeys[id].first = key;
    mKeys[id].second = type;
    (*mActionMap)[id] = getActionFromId(id);
}

void KeyBinding::setKey(std::string const& id, sf::Keyboard::Key key)
{
    mKeys[id].first = key;
    (*mActionMap)[id] = getActionFromId(id);
}

void KeyBinding::setType(std::string const& id, thor::Action::ActionType type)
{
    mKeys[id].second = type;
    (*mActionMap)[id] = getActionFromId(id);
}

sf::Keyboard::Key KeyBinding::getKey(std::string const& id)
{
    if (mKeys.find(id) == mKeys.end())
    {
        std::cerr << "KeyBinding : id (" << id << ") not recognized. " << std::endl;
        return sf::Keyboard::Unknown;
    }
    return mKeys.at(id).first;
}

thor::Action::ActionType KeyBinding::getType(std::string const& id)
{
    if (mKeys.find(id) == mKeys.end())
    {
        std::cerr << "KeyBinding : id (" << id << ") not recognized. " << std::endl;
        return thor::Action::PressOnce;
    }
    return mKeys.at(id).second;
}

thor::Action KeyBinding::getActionFromId(std::string const& id)
{
    assert(mKeys.find(id) != mKeys.end());
    sf::Keyboard::Key k = getKey(id);
    thor::Action::ActionType t = getType(id);
    return thor::Action(k,t);
}

ActionMapPtr KeyBinding::getMap()
{
    return mActionMap;
}

bool KeyBinding::load(std::string const& filename)
{
    pugi::xml_document doc;
    if (!doc.load_file(filename.c_str()))
    {
        return false;
    }
    pugi::xml_node keys = doc.child("KeyBinding");
    if (keys)
    {
        for (pugi::xml_node key = keys.child("Key"); key; key = key.next_sibling("Key"))
        {
            std::string id = key.attribute("id").value();
            std::string k = key.attribute("key").value();
            std::size_t t = key.attribute("type").as_uint();

            mKeys[id].first = thor::toKeyboardKey(k);
            mKeys[id].second = static_cast<thor::Action::ActionType>(t);
        }

        for (auto itr = mKeys.begin(); itr != mKeys.end(); itr++)
        {
            (*mActionMap)[itr->first] = getActionFromId(itr->first);
        }

        return true;
    }

    return false;
}

void KeyBinding::save(std::string const& filename)
{
    pugi::xml_document doc;
    doc.load_file(filename.c_str());
    if (doc.child("KeyBinding"))
    {
        doc.remove_child("KeyBinding");
    }
    pugi::xml_node keys = doc.append_child("KeyBinding");

    for (auto itr = mKeys.begin(); itr != mKeys.end(); itr++)
    {
        pugi::xml_node a = keys.append_child("Key");
        a.append_attribute("id") = itr->first.c_str();
        a.append_attribute("key") = thor::toString(itr->second.first).c_str();
        a.append_attribute("type") = itr->second.second;
    }

    doc.save_file(filename.c_str());
}

} // namespace lp
