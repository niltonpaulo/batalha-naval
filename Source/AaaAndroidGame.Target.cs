using UnrealBuildTool;

public class AaaAndroidGameTarget : TargetRules
{
	public AaaAndroidGameTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
		ExtraModuleNames.Add("AaaAndroidGame");
	}
}
