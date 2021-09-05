/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Modeler.cpp
*/

#include "Modeler.hpp"
#include "Exception/Exception.hpp"

Modeler::Modeler(const std::string &obj_path, const std::string &texture_path, const Animator &animation_path)
        : _model(LoadModel(obj_path.c_str())),
          _isAnimated(isThereAnimationsPath(animation_path)),
          _currentAnimation(WALK),
          _frame(0),
          _model_path(obj_path),
          _texture_path(texture_path),
          _animator(animation_path)
{
    int fake_counter = 0;

    if (_isAnimated)
    {
        _animations.push_back(LoadModelAnimations(animation_path.WALK.c_str(), &fake_counter)[0]);
        _animations.push_back(LoadModelAnimations(animation_path.BOMB.c_str(), &fake_counter)[0]);
        _animations.push_back(LoadModelAnimations(animation_path.EMOTE.c_str(), &fake_counter)[0]);
    }

    SetMaterialTexture(&_model.materials[0], MAP_DIFFUSE, LoadTexture(texture_path.c_str()));
}

Modeler::Modeler()
        : _model(LoadModel("resources/players/3D/Bombermans/white_tpose.glb")),
          _isAnimated(true),
          _currentAnimation(WALK),
          _frame(0),
          _model_path("resources/players/3D/Bombermans/white_tpose.glb"),
          _texture_path("resources/players/3D/Bombermans/texture.png"),
          _animator({
                            "resources/players/3D/Bombermans/animations/white_walking.glb",
                            "resources/players/3D/Bombermans/animations/white_bomb.glb",
                            "resources/players/3D/Bombermans/animations/white_emote.glb"
                    }
          )
{

    int fake_counter = 0;

    _animations.push_back(LoadModelAnimations("resources/players/3D/Bombermans/animations/white_walking.glb", &fake_counter)[0]);
    _animations.push_back(LoadModelAnimations("resources/players/3D/Bombermans/animations/white_bomb.glb", &fake_counter)[0]);
    _animations.push_back(LoadModelAnimations("resources/players/3D/Bombermans/animations/white_emote.glb", &fake_counter)[0]);

    SetMaterialTexture(&_model.materials[0], MAP_DIFFUSE, LoadTexture("resources/players/3D/Bombermans/texture.png"));
}

/*Modeler::Modeler(const Modeler &model)
: _model(LoadModel(model.getObjPath()),
_isAnimated(isThereAnimationsPath(model.getTexturePath())),
_currentAnimation(WALK),
_frame(0),
_model_path(model.getObjPath()),
_texture_path(model.getTexturePath()),
_animations(model.getAnimationPath())
{

}*/

Modeler& Modeler::operator=(Modeler model)
{
    int fake_counter = 0;

    _model = model.getModel();
    _isAnimated = isThereAnimationsPath(model.getAnimationPath());
    _texture_path = model.getTexturePath();
    _animator = model.getAnimationPath();

    _animations.clear();
    _animations.push_back(LoadModelAnimations(_animator.WALK.c_str(), &fake_counter)[0]);
    _animations.push_back(LoadModelAnimations(_animator.BOMB.c_str(), &fake_counter)[0]);
    _animations.push_back(LoadModelAnimations(_animator.EMOTE.c_str(), &fake_counter)[0]);

    SetMaterialTexture(&_model.materials[0], MAP_DIFFUSE, LoadTexture(_texture_path.c_str()));

    return *this;
}

Modeler::~Modeler()
{

}

Animator Modeler::getAnimationPath()
{
    return _animator;
}

std::string Modeler::getObjPath()
{
    return _model_path;
}

std::string Modeler::getTexturePath()
{
    return _texture_path;
}


bool Modeler::isThereAnimationsPath(const Animator &animation_path) const
{
    if (animation_path.EMOTE == "null" || animation_path.BOMB == "null" || animation_path.WALK == "null")
        return false;
    return true;
}

void Modeler::update()
{
    if (!_isAnimated)
        return;
    if (clock.doesTimeElapsed(FRAMETIME)) {
        _frame++;
        if (_frame >= _animations[_currentAnimation].frameCount)
            _frame = 0;
        UpdateModelAnimation(_model, _animations[_currentAnimation], _frame);
    }
}

void Modeler::makeWalk()
{
    _currentAnimation = WALK;
}

void Modeler::makeBomb()
{
    _currentAnimation = BOMB;
}

void Modeler::makeEmote()
{
    _currentAnimation = EMOTE;
}

Model &Modeler::getModel()
{
    return _model;
}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTrygetAnimationPath() {
    try
    {   Modeler test;
        test.getAnimationPath();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrygetObjPath() {
    try
    {   Modeler test;
        test.getObjPath();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrygetTexturePath() {
    try
    {   Modeler test;
        test.getTexturePath();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

// isThereAnimationsPath is a private functions - testing using asserts

void assertIsThereAnimationsPath() {
    Animator animation_path;
    assert(1+1==1);
    assert((animation_path.EMOTE == "null" || animation_path.BOMB == "null" || animation_path.WALK == "null"));
}

int catchThrowTryupdate() {
    try
    {   Modeler test;
        test.update();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrymakeWalk() {
    try
    {   Modeler test;
        test.makeWalk();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrymakeBomb() {
    try
    {   Modeler test;
        test.makeBomb();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrymakeEmote() {
    try
    {   Modeler test;
        test.makeEmote();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

