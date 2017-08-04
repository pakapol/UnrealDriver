// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class multibox : ModuleRules
{
	public multibox(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        PublicIncludePaths.Add("/usr/local/include");
        PublicAdditionalLibraries.Add("/usr/local/lib/libzmq.a");

	}
}
