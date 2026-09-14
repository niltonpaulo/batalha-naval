#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AaaAndroidHUD.generated.h"

class UUserWidget;

UCLASS()
class AAaaAndroidHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category=UI)
	TSubclassOf<UUserWidget> MobileHUDWidgetClass;

private:
	UPROPERTY()
	TObjectPtr<UUserWidget> MobileHUDWidget;
};
