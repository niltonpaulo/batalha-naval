using UnrealBuildTool;

public class AaaAndroidGame : ModuleRules
{
	public AaaAndroidGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore"
		});
	}
}
