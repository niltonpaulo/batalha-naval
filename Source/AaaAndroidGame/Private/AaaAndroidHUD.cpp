#include "AaaAndroidHUD.h"

#include "Blueprint/UserWidget.h"

void AAaaAndroidHUD::BeginPlay()
{
	Super::BeginPlay();

	if (MobileHUDWidgetClass)
	{
		MobileHUDWidget = CreateWidget<UUserWidget>(GetWorld(), MobileHUDWidgetClass);
		if (MobileHUDWidget)
		{
			MobileHUDWidget->AddToViewport();
		}
	}
}
