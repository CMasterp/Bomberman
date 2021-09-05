/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** XRay
*/

#include "XRay.hpp"
#include "Exception/Exception.hpp"

XRay::XRay(void)
        : _window(1920, 1080, "Bomberman")
{
    // Set icon for window
    Raylib::Window::setWindowIcon(Raylib::Image("resources/assets/head.png"));

    // Set in fullscreen mode
    Raylib::Window::toggleFullscreen();

    // Set resources
    setResources();

    // Set Audio
    Raylib::Audio::initAudioDevice();
    setAudioResources();

    // Scenes
    _scenesFunc.push_back(&XRay::displayMenuScene);
    _scenesFunc.push_back(&XRay::displayGameModeScene);
    _scenesFunc.push_back(&XRay::displayHowToPlayScene);
    _scenesFunc.push_back(&XRay::displaySettingsScene);
    _scenesFunc.push_back(&XRay::displayPlayerChoiceScene);
    _scenesFunc.push_back(&XRay::displayMapChoiceScene);
    _scenesFunc.push_back(&XRay::displayLoadGameScene);
    _scenesFunc.push_back(&XRay::displayInGameScene);
    _scenesFunc.push_back(&XRay::displayVictoryScene);
    _scenesFunc.push_back(&XRay::displayDefeatScene);
    _scenesFunc.push_back(&XRay::quitGame);

    // Scenes Back
    _scenesBack.insert(std::pair<Scene, void (XRay::*)()>(Scene::HELP, &XRay::displayMenuScene));
    _scenesBack.insert(std::pair<Scene, void (XRay::*)()>(Scene::SETTINGS, &XRay::displayMenuScene));
    _scenesBack.insert(std::pair<Scene, void (XRay::*)()>(Scene::GAME_MODE, &XRay::displayMenuScene));
    _scenesBack.insert(std::pair<Scene, void (XRay::*)()>(Scene::PLAYER_CHOICE, &XRay::displayGameModeScene));
    _scenesBack.insert(std::pair<Scene, void (XRay::*)()>(Scene::LOAD_GAME, &XRay::displayGameModeScene));
    _scenesBack.insert(std::pair<Scene, void (XRay::*)()>(Scene::MAP_CHOICE, &XRay::displayPlayerChoiceScene));

    // Scenes Back Backup
    _scenesBackBackup.insert(std::pair<Scene, void (XRay::*)()>(Scene::HELP, &XRay::displayMenuScene));
    _scenesBackBackup.insert(std::pair<Scene, void (XRay::*)()>(Scene::SETTINGS, &XRay::displayMenuScene));
    _scenesBackBackup.insert(std::pair<Scene, void (XRay::*)()>(Scene::GAME_MODE, &XRay::displayMenuScene));
    _scenesBackBackup.insert(std::pair<Scene, void (XRay::*)()>(Scene::PLAYER_CHOICE, &XRay::displayGameModeScene));
    _scenesBackBackup.insert(std::pair<Scene, void (XRay::*)()>(Scene::LOAD_GAME, &XRay::displayGameModeScene));
    _scenesBackBackup.insert(std::pair<Scene, void (XRay::*)()>(Scene::MAP_CHOICE, &XRay::displayPlayerChoiceScene));

    // Display Intro (studio and introduction cinematic)
    _intro = std::make_pair(true, std::vector<void (XRay::*)()>{&XRay::displayStudio, &XRay::displayTeamPresentation});

    //Transition Manager
    _transitionManager.insert(std::pair<Scene, std::pair<bool, bool>>(Scene::HELP, std::pair<bool, bool>(false, false)));
    _transitionManager.insert(std::pair<Scene, std::pair<bool, bool>>(Scene::SETTINGS, std::pair<bool, bool>(false, false)));
    _transitionManager.insert(std::pair<Scene, std::pair<bool, bool>>(Scene::GAME_MODE, std::pair<bool, bool>(false, false)));
    _transitionManager.insert(std::pair<Scene, std::pair<bool, bool>>(Scene::PLAYER_CHOICE, std::pair<bool, bool>(false, false)));
    _transitionManager.insert(std::pair<Scene, std::pair<bool, bool>>(Scene::LOAD_GAME, std::pair<bool, bool>(false, false)));
    _transitionManager.insert(std::pair<Scene, std::pair<bool, bool>>(Scene::MAP_CHOICE, std::pair<bool, bool>(false, false)));

    masterVolume = 50;
    musicVolume = 100;
    sfxVolume = 100;
    Raylib::Audio::setMasterVolume(masterVolume / 100);
    changeMusicVolume();
    changeSfxVolume();
}

XRay::~XRay(void)
{
}

void XRay::setResources(void)
{
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::ADD, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/add.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::REMOVE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/remove.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::PREVIOUS, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/previous.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::NEXT, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/next.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::CONTROLS, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/controls.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::GAMEPAD, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/gamepad.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::HUMAN, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/human.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::AI, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/ai.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::HEAD, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/head.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::LOADGAME, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/loadGame.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::LOADGAME_BG, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/loadGameBG.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::LOADGAME_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/loadGameHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::NEWGAME, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/newGame.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::NEWGAME_BG, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/newGameBG.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::NEWGAME_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/newGameHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::LOADSCENE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/loadScene.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BRANCH, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/branch.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BACK, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/back.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BACK_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/backHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::HELP, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/help.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::HELP_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/helpHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SETTINGS, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/settings.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SETTINGS_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/settingsHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::INDIE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/indie.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::STUDIO, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/studio.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BOMBER_TEAM, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/bomberTeam.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::MENU_TITLE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/title.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BOMBER_THINKING, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/bomberThinking.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::PLAY, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/play.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::PLAY_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/playHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::QUIT, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/quit.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::QUIT_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/quitHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SKIP, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/skip.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SKIP_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/skipHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::PARALLAX, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/parallax.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BG, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/bg.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::p1, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/j1.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::p2, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/j2.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::p3, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/j3.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::p4, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/j4.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::P1, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/p1.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::P2, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/p2.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::P3, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/p3.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::P4, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/p4.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::MOUSEYELLOW, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/mouseYellow.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::KEYBOARDYELLOW, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/keyboardYellow.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::PLAYSTATIONYELLOW, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/playstationYellow.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::XBOXYELLOW, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/xboxYellow.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::MOUSEBLUE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/mouseBlue.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::KEYBOARDBLUE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/keyboardBlue.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::PLAYSTATIONBLUE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/playstationBlue.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::XBOXBLUE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/xboxBlue.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::NEXTSCENE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/nextScene.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::NEXT_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/nextHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::MAPCHOICEBG, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/mapChoiceBack.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SIZE_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/sizeHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SETS_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/setHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::DURATION_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/durationHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::AI_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/iaHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SIZE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/size.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SETS, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/sets.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::DURATION, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/duration.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::IA, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/ia.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::MOUSEPANEL, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/mousePanel.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::KEYBOARDPANEL, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/keyboardPanel.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::PLAYSTATIONPANEL, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/playstationPanel.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::XBOXPANEL, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/xboxPanel.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::PAUSE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/pause.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::DEPAUSE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/depause.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::PAUSEBACK, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/pauseBg.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::RESUME, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/resume.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::RESTART, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/restart.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SAVE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/save.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SETTING, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/setting.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::HOME, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/home.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::RESUMEHOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/resumeHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::RESTARTHOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/restartHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SAVEHOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/saveHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SETTINGSHOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/settingHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::HOMEHOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/homeHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SAVED, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/saved.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BACKUPBAR, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/backup.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::VICTORYBG, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/victoryBg.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::DEFEATBG, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/defeatBg.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::NEXTLEVEL, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/nextlevel.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::NEXTLEVELHOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/nextlevelHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::RANKING, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/ranking.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::ON, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/ON.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::OFF, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/OFF.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SETTING_BG, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/backSetting.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::VOLUME_UP, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/volumeUp.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::VOLUME_DOWN, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/volumeDown.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::LOADINGFRAMEO, std::make_shared<Raylib::Texture>(Raylib::Image("resources/cinematic/loading/frame0.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::S7X7S, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/7x7.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::S9X9S, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/9x9.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::S11X11S, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/11x11.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::S13X13S, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/13x13.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::S15X15S, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/15x15.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::S17X17S, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/17x17.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::S19X19S, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/19x19.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::MIN1MIN, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/min1min.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::MIN2MIN, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/min2min.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::MIN3MIN, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/min3min.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::MIN4MIN, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/min4min.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::MIN5MIN, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/min5min.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SET1SET, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/set1set.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SET2SET, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/set2set.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SET3SET, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/set3set.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SET4SET, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/set4set.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SET5SET, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/set5set.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::EASY, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/easy.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::MEDIUM, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/medium.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::DIFFICULT, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/hard.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::TEXT_FULLSCREEN, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/textFullscreen.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::TEXT_GENERAL, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/textGeneral.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::TEXT_MUSIC, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/textMusic.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::TEXT_SFX, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/textSfx.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::TEXT_VOLUME, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/textVolume.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::TEXT_MODS, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/textMods.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::CLOCKBAR, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/clockbar.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::YELLOWBOMBERMAN, std::make_shared<Raylib::Texture>(Raylib::Image("resources/players/bioYellow.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::REDBOMBERMAN, std::make_shared<Raylib::Texture>(Raylib::Image("resources/players/bioRed.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BLUEBOMBERMAN, std::make_shared<Raylib::Texture>(Raylib::Image("resources/players/bioBlue.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::GREENBOMBERMAN, std::make_shared<Raylib::Texture>(Raylib::Image("resources/players/bioGreen.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::HOWTO_BG, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/howToBack.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::MOUSERADAR, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/mouseRadar.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::BACKUPERROR, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/backupBarRed.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::PRINCE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/prince.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::LUCAS, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/lucas.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::JONATHAN, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/jonathan.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::NICO, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/nico.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::MEHDI, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/mehdi.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::CHARLES, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/charles.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::TEAMTITLE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/teamAndTitle.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::SKATE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/3D/Items/skate.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::FIRE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/3D/Items/fire.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::IBOMB, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/3D/Items/bomb.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(Resources::AIPANEL, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/aiPanel.png"))));
}

void XRay::setAudioResources(void)
{
    // Music
    _musics.insert(std::pair<MusicResources, std::shared_ptr<Raylib::Music>>(MusicResources::MSC_BOMBERMAN, std::make_shared<Raylib::Music>(*(new Raylib::Music("resources/music/Bomberman.mp3")))));
    _musics.insert(std::pair<MusicResources, std::shared_ptr<Raylib::Music>>(MusicResources::MSC_GAME, std::make_shared<Raylib::Music>(*(new Raylib::Music("resources/music/bmgame.ogg")))));

    // Sound
    _sfx.insert(std::pair<SfxResources, std::shared_ptr<Raylib::Sound>>(SfxResources::SFX_OPENNING, std::make_shared<Raylib::Sound>(*(new Raylib::Sound("resources/music/opening.mp3")))));
    _sfx.insert(std::pair<SfxResources, std::shared_ptr<Raylib::Sound>>(SfxResources::SFX_KLICK, std::make_shared<Raylib::Sound>(*(new Raylib::Sound("resources/Sound/Klick.wav")))));
    _sfx.insert(std::pair<SfxResources, std::shared_ptr<Raylib::Sound>>(SfxResources::SFX_ENTER, std::make_shared<Raylib::Sound>(*(new Raylib::Sound("resources/Sound/Enter.wav")))));
    _sfx.insert(std::pair<SfxResources, std::shared_ptr<Raylib::Sound>>(SfxResources::SFX_SETTING, std::make_shared<Raylib::Sound>(*(new Raylib::Sound("resources/Sound/Settings.wav")))));
    _sfx.insert(std::pair<SfxResources, std::shared_ptr<Raylib::Sound>>(SfxResources::SFX_HOME, std::make_shared<Raylib::Sound>(*(new Raylib::Sound("resources/Sound/Home.wav")))));
    _sfx.insert(std::pair<SfxResources, std::shared_ptr<Raylib::Sound>>(SfxResources::SFX_NOCK, std::make_shared<Raylib::Sound>(*(new Raylib::Sound("resources/Sound/Nock.wav")))));
    _sfx.insert(std::pair<SfxResources, std::shared_ptr<Raylib::Sound>>(SfxResources::SFX_TURN_OFF, std::make_shared<Raylib::Sound>(*(new Raylib::Sound("resources/Sound/TurnOff.wav")))));
    _sfx.insert(std::pair<SfxResources, std::shared_ptr<Raylib::Sound>>(SfxResources::SFX_TURN_ON, std::make_shared<Raylib::Sound>(*(new Raylib::Sound("resources/Sound/TurnOn.wav")))));
    _sfx.insert(std::pair<SfxResources, std::shared_ptr<Raylib::Sound>>(SfxResources::SFX_JIG, std::make_shared<Raylib::Sound>(*(new Raylib::Sound("resources/Sound/Jig0.wav")))));
    _sfx.insert(std::pair<SfxResources, std::shared_ptr<Raylib::Sound>>(SfxResources::SFX_JIG1, std::make_shared<Raylib::Sound>(*(new Raylib::Sound("resources/Sound/Jig1.wav")))));
    _sfx.insert(std::pair<SfxResources, std::shared_ptr<Raylib::Sound>>(SfxResources::SFX_BING, std::make_shared<Raylib::Sound>(*(new Raylib::Sound("resources/Sound/Bing.wav")))));
    _sfx.insert(std::pair<SfxResources, std::shared_ptr<Raylib::Sound>>(SfxResources::SFX_WEEE, std::make_shared<Raylib::Sound>(*(new Raylib::Sound("resources/Sound/wee.wav")))));
    _sfx.insert(std::pair<SfxResources, std::shared_ptr<Raylib::Sound>>(SfxResources::SFX_BOOM, std::make_shared<Raylib::Sound>(*(new Raylib::Sound("resources/Sound/boom.wav")))));
    _sfx.insert(std::pair<SfxResources, std::shared_ptr<Raylib::Sound>>(SfxResources::SFX_TUDUM, std::make_shared<Raylib::Sound>(*(new Raylib::Sound("resources/Sound/tudum.wav")))));
    _sfx.insert(std::pair<SfxResources, std::shared_ptr<Raylib::Sound>>(SfxResources::SFX_DEFEAT, std::make_shared<Raylib::Sound>(*(new Raylib::Sound("resources/Sound/bmlose.ogg")))));
    _sfx.insert(std::pair<SfxResources, std::shared_ptr<Raylib::Sound>>(SfxResources::SFX_COUNTDOWN, std::make_shared<Raylib::Sound>(*(new Raylib::Sound("resources/Sound/countdown.wav")))));
}

void XRay::quitGame(void)
{
    // Set scene
    _scene = END_GAME;
}

void XRay::displayStudio(void)
{
    // Draw
    for (int f = 0, x = 0, y = 0; x < 480; f += 1) {
        x = -100 + f;
        y = 1500 - f;
        beginDrawing();
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
        _resources.at(INDIE)->drawTexture(x, 440);
        _resources.at(STUDIO)->drawTexture(y, 440);
        endDrawing();
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    // Intro is done, so update its status flag
    _intro.first = false;
    displayCinematic(Cinematic::INTRO);
}

void XRay::displayTeamPresentation(void)
{
    // Draw
    for (int f = 0, x = 0; x < 480; f += 1) {
        x = -100 + f;
        beginDrawing();
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
        _resources.at(PRINCE)->drawTexture(x, CFunctions::generatePairOfRandomIntegers(1, 780).second);
        _resources.at(LUCAS)->drawTexture(CFunctions::generatePairOfRandomIntegers(1080, 1080).first, CFunctions::generatePairOfRandomIntegers(1980, 1080).second);
        _resources.at(JONATHAN)->drawTexture(CFunctions::generatePairOfRandomIntegers(780, 1080).first, x);
        _resources.at(NICO)->drawTexture(x, CFunctions::generatePairOfRandomIntegers(1980, 580).second);
        _resources.at(MEHDI)->drawTexture(CFunctions::generatePairOfRandomIntegers(1980, 1080).first, CFunctions::generatePairOfRandomIntegers(1980, 1080).second);
        _resources.at(CHARLES)->drawTexture(CFunctions::generatePairOfRandomIntegers(500, 500).first, CFunctions::generatePairOfRandomIntegers(500, 500).second);
        endDrawing();
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    beginDrawing();
    _resources.at(TEAMTITLE)->drawTexture(0, 0);
    endDrawing();

    std::this_thread::sleep_for(std::chrono::milliseconds(4000));

    // Intro is done, so update its status flag
    _intro.first = false;
    displayCinematic(Cinematic::INTRO);
}

void XRay::playMusic(MusicResources music) {
    if (!_musics.at(music)->isPlaying()) {
        std::thread tMusic(&XRay::playAndUpdateMusic, this, music);
        tMusic.detach();
    }
}

// Don't call this function only use it with playMusic(MusicResources music)
void XRay::playAndUpdateMusic(MusicResources music) {
    Clock clock;
    _musics.at(music)->playMusic();
    while (_musics.at(music)->isPlaying()) {
        if (clock.doesTimeElapsed(0.01))
            _musics.at(music)->update();
    }
}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTrydisplayStudio() {
    try
    {   XRay test;
        test.displayStudio();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrydisplayTeamPresentation() {
    try
    {   XRay test;
        test.displayTeamPresentation();
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTryplayMusic() {
    try
    {   XRay test;
        MusicResources music;
        test.playMusic(music);
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTryplayAndUpdateMusic() {
    try
    {   XRay test;
        MusicResources music;
        test.playAndUpdateMusic(music);
    }
    catch (Engine::Exception& ex)
    {
        std::cout << ex.what() << ex.getInfo() << std::endl;
        std::cout << "Function: " << ex.getFunction() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
