//
// Created by VerOchka on 30.10.2023.
//

#include "System.hpp"

namespace Data {
    size_t System::serialize(std::ostream &os) const {
        const auto pos = os.tellp();
        const auto len = (_name.size()
                + _image.size()
                + _races.size()*sizeof(Race)
                + _actions.size()*sizeof(Action));

//        os.write(reinterpret_cast<const char*>(&len), sizeof(len));
//        os.write(reinterpret_cast<const char*>(&_name), _name.size());
//        os.write(reinterpret_cast<const char*>(&_image), _image.size());

        return 0;
    }

    size_t System::deserialize(std::istream &is) {
        return 0;
    }

    size_t System::serialized_size() const noexcept {
        return 0;
    }

    void System::setName(const std::u16string &name) {
        _name = name;
    }

    void System::setImage(const std::u16string &image) {
        _image = image;
    }

    void System::setRaces(const std::vector<Race> &races) {
        _races = races;
    }

    void System::addAction(const Action &action) {
        _actions.push_back(action);
    }

    void System::addClass(CharacterClass &characterClass) {
        _classes.push_back(characterClass);
    }

    void System::addClass(Skill &skill) {
        _skills.push_back(skill);
    }
}