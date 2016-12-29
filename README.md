<img src="https://raw.githubusercontent.com/gameplay3d/GamePlay/master/gameplay/res/icon.png" width=100/>

## GamePlay v3.0.0 - Tim's Fork

GamePlay is an open-source, cross-platform native C++ game framework for creating 2D/3D mobile and desktop games.

- [Website](http://www.gameplay3d.io/)
- [Wiki](https://github.com/gameplay3d/GamePlay/wiki)
- [API](http://gameplay3d.github.io/GamePlay/api/index.html)
- [Development Guide](https://github.com/gameplay3d/GamePlay/wiki#wiki-Development_Guide)
- [Community Group](https://groups.google.com/d/forum/gameplay3d-developers)

## Supported Platforms
- [Windows](https://github.com/gameplay3d/GamePlay/wiki/Visual-Studio-Setup) 
- [Linux](https://github.com/gameplay3d/GamePlay/wiki/CMake Setup - Linux)
- [MacOSX](https://github.com/gameplay3d/GamePlay/wiki/Apple-Xcode-Setup)
- [iOS](https://github.com/gameplay3d/GamePlay/wiki/Apple-Xcode-Setup)
- [Android](https://github.com/gameplay3d/GamePlay/wiki/Android-NDK-Setup)

## NOTES

### iOS
When archiving a project we now need to fix the project's build settings so Release includes deps library, same as Debug.
- Linking / Other Linker Flags / Release / Any iOS Simulator SDK
-- -L../../GamePlay/external-deps/lib/ios/x86
- Linking / Other Linker Flags / Release / Any iOS SDK
-- -L../../GamePlay/external-deps/lib/ios/arm

PlatformiOS.mm 	These must be changed based on what interface orientations are supported
				> (NSUInteger) supportedinterfaceorientations
				> (BOOL)shouldAutorotate
				> (NSUInteger)application:(UIApplication *)application


