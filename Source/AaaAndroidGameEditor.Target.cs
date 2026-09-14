using UnrealBuildTool;

public class AaaAndroidGameEditorTarget : TargetRules
{
	public AaaAndroidGameEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
		ExtraModuleNames.Add("AaaAndroidGame");
	}
}
