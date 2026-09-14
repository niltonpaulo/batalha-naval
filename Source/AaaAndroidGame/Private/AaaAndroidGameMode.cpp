#include "AaaAndroidGameMode.h"

#include "AaaAndroidCharacter.h"
#include "AaaAndroidHUD.h"
#include "AaaAndroidPlayerStart.h"

AAaaAndroidGameMode::AAaaAndroidGameMode()
{
	DefaultPawnClass = AAaaAndroidCharacter::StaticClass();
	HUDClass = AAaaAndroidHUD::StaticClass();
	PlayerStartClass = AAaaAndroidPlayerStart::StaticClass();
}
